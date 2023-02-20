echo -n "enter a long - string in upper case :"
read string

#length
length=${#string}
echo "lenght of string is $length"

#concat
echo -n "enter 2 strings for concaenation in lowercase : "
read s1
read s2

echo -n "$s1 $s2 "
echo "$s1" + "$s2"

#lowercase
lowercase_string=$(echo "$string" | tr '[:upper:]' '[:lower:]')
echo "lowercase is : $lowercase_string"

#uppercase
uppercase_string=$(echo "$s1" | tr '[:lower:]' '[:upper:]')
echo "lowercase is : $lowercase_string"

#slicing
echo "string after slicing is ${string:2:5}"