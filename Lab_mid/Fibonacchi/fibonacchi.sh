#! /bin/bash

read -p "Enter the number of tearms : " num_term

a=0
b=1

echo "Fibonacchi sequence up to $num_term terms:"

for ((i=0 ; i<num_term; i++))
do
	echo -n  "$a "
	fn=$((a+b))
	a=$b
	b=$fn
done
echo 
