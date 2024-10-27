#! /bin/bash

echo "Enter the first number:"
read num1

echo "Enter an operator (+, -, *, /):"
read operator

echo "Enter the second number:"
read num2

case $operator in
    "+")
        result=$(echo "$num1 + $num2" | bc)
        ;;
    "-")
        result=$(echo "$num1 - $num2" | bc)
        ;;
    "*")
        result=$(echo "$num1 * $num2" | bc)
        ;;
    "/")
        if [ "$num2" -eq 0 ]; then
            echo "Error: Division by zero is not allowed."
            exit 1
        fi
        result=$(echo "scale=2; $num1 / $num2" | bc)
        ;;
    *)
        echo "Invalid operator. Please use +, -, *, or /."
        exit 1
        ;;
esac
echo "Result: $result"
