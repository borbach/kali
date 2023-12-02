#!/bin/bash

# Check if the number of arguments is correct
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 directory1 directory2"
    exit 1
fi

directory1="$1"
directory2="$2"

# Check if the directories exist
if [ ! -d "$directory1" ] || [ ! -d "$directory2" ]; then
    echo "Error: Both directories must exist."
    exit 1
fi

# Find all text files in the first directory and its subdirectories
text_files1=$(find "$directory1" -type f -name "*.sh" -o -name "*.cpp" -o -name "*.py")

# Iterate through text files in the first directory
for file1 in $text_files1; do
    # Extract the relative path of the file
    relative_path=$(realpath --relative-to="$directory1" "$file1")
    file2="$directory2/$relative_path"

    # Check if the file exists in the second directory
    if [ -e "$file2" ]; then
        # Compare the contents of the text files
	if cmp -s "$file1" "$file2" ; then
#            echo "File '$relative_path' exists in both directories and has the same content."
             echo "."
        else
            echo "File '$relative_path' exists in both directories but has different content."
        fi
    else
        echo "File '$relative_path' does not exist in the second directory."
    fi
done

