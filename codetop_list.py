import math
import time
import requests
import pandas as pd
from tqdm import tqdm
from bs4 import BeautifulSoup
from requests.adapters import HTTPAdapter
from urllib3.util.retry import Retry

API_BASE = "https://codetop.cc/api/questions/"
# 你可以在这里修改 query params（search / ordering / page_size 等）
DEFAULT_PARAMS = {
    "page": 1,
    "search": "",
    "ordering": "-frequency",
}

HEADERS = {
    "User-Agent": "Mozilla/5.0 (compatible; CodetopScraper/1.0)"
}

# ---- helpers ----
def make_session_with_retries(total_retries=5, backoff_factor=0.3, status_forcelist=(429, 500, 502, 503, 504)):
    s = requests.Session()
    retries = Retry(total=total_retries,
                    backoff_factor=backoff_factor,
                    status_forcelist=status_forcelist,
                    allowed_methods=["GET", "POST"])
    s.mount("https://", HTTPAdapter(max_retries=retries))
    s.mount("http://", HTTPAdapter(max_retries=retries))
    return s

def strip_html(html_text):
    if not html_text:
        return ""
    return BeautifulSoup(html_text, "html.parser").get_text(separator=" ", strip=True)

# ---- main ----
def fetch_all_questions(api_base=API_BASE, params=DEFAULT_PARAMS, delay=0.15, save_csv="codetop_questions.csv"):
    session = make_session_with_retries()
    session.headers.update(HEADERS)

    # fetch first page to learn count and page_size
    params = params.copy()
    params["page"] = 1
    r = session.get(api_base, params=params, timeout=20)
    r.raise_for_status()
    j = r.json()

    # flexible keys: sometimes the list might be 'list' or 'results'
    items_key = "list" if "list" in j else ("results" if "results" in j else None)
    if items_key is None:
        raise RuntimeError("响应里找不到 'list' 或 'results' 字段，请打印返回 JSON 检查结构：\n", j)

    total_count = j.get("count", None)  # 如果没有 count，也能继续按页抓直到没数据
    first_items = j.get(items_key, [])
    page_size = len(first_items)
    if page_size == 0:
        return pd.DataFrame()  # 没数据

    if total_count is not None:
        total_pages = (total_count + page_size - 1) // page_size  # 向上取整
    else:
        # 若没有 count，就保守循环直到某页返回空
        total_pages = None

    all_rows = []

    # 如果知道总页数就用 tqdm，否则先用一个大上限并在碰到空页时停止
    if total_pages is not None:
        page_iter = range(1, total_pages + 1)
    else:
        page_iter = range(1, 10000)  # 任意很大的上限，遇空页退出

    for page in tqdm(page_iter, desc="抓取页"):
        params["page"] = page
        resp = session.get(api_base, params=params, timeout=20)
        resp.raise_for_status()
        data = resp.json()
        items = data.get(items_key, [])
        if not items:
            # 没数据 -> 结束（仅在未知 total_count 的情况下）
            if total_pages is None:
                break
            else:
                continue

        for it in items:
            # 展开你关心的字段（根据你给的示例 JSON）
            le = it.get("leetcode") or {}
            row = {
                "id": it.get("id"),
                "value": it.get("value"),
                "time": it.get("time"),
                "status": it.get("status"),
                "note_status": it.get("note_status"),
                "rate": it.get("rate"),
                # leetcode 次级字段
                "leetcode_id": le.get("id"),
                "frontend_question_id": le.get("frontend_question_id"),
                "question_id": le.get("question_id"),
                "title": le.get("title"),
                "level": le.get("level"),
                "slug_title": le.get("slug_title"),
                # 原始 html 内容（如果需要可以去标签）
                "content_html": le.get("content"),
                "content_text": strip_html(le.get("content", "")),
                "comment_count": it.get("comment_count"),
            }
            all_rows.append(row)

        time.sleep(delay)  # 礼貌等待，防止触发防爬或限流

    df = pd.DataFrame(all_rows)

    # 自动把 time 转为 pandas datetime（如果存在）
    if "time" in df.columns:
        df["time"] = pd.to_datetime(df["time"], errors="coerce")

    # 保留 question_id(题号), title(题目), level(难度), value(频度)
    df = df[["question_id", "title", "level", "value"]]

    # 添加标题行
    df.columns = ["题号", "题目", "难度", "频度"]

    # 保存到 CSV（可改为 to_excel / to_parquet）
    df.to_csv(save_csv, index=False, encoding="utf-8-sig")
    print(f"已保存 {len(df)} 条记录到 {save_csv}")
    return df

if __name__ == "__main__":
    df_all = fetch_all_questions()
    print(df_all.head())
    print(df_all.shape)
