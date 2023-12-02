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

# Iterate through files in the first directory
for file1 in "$directory1"/*; do
    # Extract the file name from the path
    filename=$(basename "$file1")
    file2="$directory2/$filename"

    # Check if the file exists in the second directory
    if [ -e "$file2" ]; then
        # Compare the contents of the files
        if cmp -s "$file1" "$file2"; then
            echo "File '$filename' exists in both directories and has the same content."
        else
            echo "File '$filename' exists in both directories but has different content."
        fi
    else
        echo "File '$filename' does not exist in the second directory."
    fi
done

