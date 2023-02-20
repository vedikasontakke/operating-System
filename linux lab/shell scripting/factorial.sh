function factorial {
  if (( $1 == 1 ))
  then
    echo 1
  else
    local prev=$(factorial $(( $1 - 1 )))
    echo $(( $1 * $prev ))
  fi
}

echo "Enter a number:"
read num

fact=$(factorial $num)

echo "Factorial of $num is: $fact"

################################################################################################

echo "Enter a number:"
read num

fact=1
for ((i=1;i<=num;i++))
do
  fact=$((fact * i))
done

echo "Factorial of $num is: $fact"

###############################################################

string=$1
substring=$2

if [[ -z $string || -z $substring ]]; then
  echo "Usage: $0 <string> <substring>"
  exit 1
fi

count=$(grep -o $substring <<< $string | wc -l)

echo "The substring '$substring' occurs $count times in the string '$string'."