#!/bin/bash

# Kiểm tra số lượng tham số
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

filesdir=$1
searchstr=$2

# Kiểm tra xem filesdir có phải là một thư mục không
if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a directory."
    exit 1
fi

# Đếm số lượng file và số dòng khớp
file_count=$(find "$filesdir" -type f | wc -l)
matching_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

# In kết quả
echo "The number of files are $file_count and the number of matching lines are $matching_lines."
