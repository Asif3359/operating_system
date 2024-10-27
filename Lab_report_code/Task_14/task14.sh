#! /bin/bash

echo "Enter first number:"
read num1

echo "Enter second number:"
read num2

echo "$num1 == $num2 : $((num1 == num2))"
echo "$num1 != $num2 : $((num1 != num2))"
echo "$num1 > $num2 : $((num1 > num2))"
echo "$num1 < $num2 : $((num1 < num2))"
echo "$num1 >= $num2 : $((num1 >= num2))"
echo "$num1 <= $num2 : $((num1 <= num2))"
