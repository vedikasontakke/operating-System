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

