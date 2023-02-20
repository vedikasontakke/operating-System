#!/bin/bash


is_prime()
{
    local n=$1
    
    if [ $n -le 1 ]
    then
    echo "$n is not prime"
    elif [ $n -eq 2 ]
    then
    echo "$n is prime"
    else
      for((i=2 ; i<n ; i++))
      do
         if [ $(($n%$i)) -eq 0 ]
         then
         echo "$n is not primE"
         return 0
         fi
      done
    echo "$n is primE"
    fi
}

read -p "enter no : " num
echo "$num"

is_prime $num