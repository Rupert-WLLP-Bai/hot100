#!/bin/bash

# Counter for files
count=1

# Get all .cc files in the current directory
for file in *.cc; do
    # Check if file exists (to handle the case when no .cc files are found)
    [ -e "$file" ] || continue
    
    # Format the number with leading zeros to make it 4 digits
    formatted_num=$(printf "%04d" $count)
    
    # Rename the file
    mv "$file" "${formatted_num}.cc"
    
    # Increment the counter
    ((count++))
done

echo "Renamed $(($count - 1)) .cc files with 4-digit prefixes"