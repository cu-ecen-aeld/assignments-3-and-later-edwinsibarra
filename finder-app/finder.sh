#!/bin/sh

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Error: Two arguments required: <filesdir> <searchstr>"
    exit 1
fi

filesdir=$1
searchstr=$2

# Check if the first argument is a directory
if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a directory"
    exit 1
fi

# Initialize counters
file_count=0
match_count=0

# Iterate over all files in the directory and subdirectories
while IFS= read -r -d '' file; do
    file_count=$((file_count + 1))
    # Count matching lines in the current file
    matches=$(grep -c "$searchstr" "$file")
    match_count=$((match_count + matches))
done < <(find "$filesdir" -type f -print0)

# Print the result
echo "The number of files are $file_count and the number of matching lines are $match_count"
