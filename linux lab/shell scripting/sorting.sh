echo "enter the elements of the array : "
read -a myarray

len=${#myarray[@]}

for(( i=0; i<len; i++ ))
do
  for(( j=0; j<len-i-1; j++ ))
  do
    if (( ${myarray[j]} > ${myarray[j+1]} ))
    then
      temp=${myarray[j]}
      myarray[j]=${myarray[j+1]}
      myarray[j+1]=$temp
    fi
  done
done

echo ${myarray[@]}