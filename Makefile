CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -g
TARGET = leetcode

# 自动检测所有.cc文件
SRCS = $(wildcard *.cc)
BINS = $(SRCS:.cc=)

all: $(BINS)

# $@表示目标文件，$<表示第一个依赖文件
# %.cc表示所有以.cc结尾的源文件

%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "Running $@:"
	@./$@
	@rm -f $@

clean:
	rm -f $(BINS)