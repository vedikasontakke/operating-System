# Hello World Program in Bash Shell

#!/bin/bash

#!/bin/bash

is_prime()
{
    local n=$1
    
    if [ $n -le 1 ]
    then
    return 1
    elif [ $n -eq 2 ]
    then
    return 0
    else
      for((i=2 ; i<n ; i++))
      do
         if [ $(($n%$i)) -eq 0 ]
         then
         return 1
         fi
      done
    return 0
    fi
}

print_prime()
{
    s=$1
    e=$2
    
    while [ $s -le $e ]
    do
        if is_prime $s;
        then
          echo "$s"
        fi
        ((s++))
    done
}

read -p "enter start index : " start
read -p "enter end index : " end
echo "prime numbers are : "
print_prime $start $end
