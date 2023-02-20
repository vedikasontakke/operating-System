

read -p "enter a number : " num
 
    duplicate=$num
    reverse=0
    rem=0
    
    while [ $num -ne 0 ]
    do
    rem=$(($num%10))
    reverse=$(($reverse*10+$rem))
    num=$(($num/10))
    done
    
    if [ $reverse -eq $duplicate ]
    then
    echo "number is palindrome"
    else
    echo "number is not palindrome $reverse"
    fi