#!/bin/bash

# Get user input for the string and substring
read -p "Enter a string: " str
read -p "Enter a sub-string: " sub

# Count the number of occurrences of the sub-string in the string
count=$(echo "$str" | grep -o "$sub" | wc -l)

# Print the result
echo "The sub-string '$sub' occurs $count times in the string '$str'."



#------------------------------------------------------------------#


string=$1
substring=$2

if [[ -z $string || -z $substring ]]; then
  echo "Usage: $0 <string> <substring>"
  exit 1
fi

count=$(grep -o $substring <<< $string | wc -l)

echo "The substring '$substring' occurs $count times in the string '$string'."