#!/bin/bash

# Kiểm tra xem có đủ tham số không
if [ "$#" -ne 2 ]; then
    echo "Error: You must specify a file path and a string to write."
    exit 1
fi

writefile=$1
writestr=$2

# Tạo thư mục nếu nó không tồn tại
mkdir -p "$(dirname "$writefile")"

# Ghi nội dung vào tệp
echo "$writestr" > "$writefile"

# Kiểm tra xem tệp có được tạo thành công không
if [ $? -ne 0 ]; then
    echo "Error: Could not create the file."
    exit 1
fi

echo "File created successfully: $writefile"
