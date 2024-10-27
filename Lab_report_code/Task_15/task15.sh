#! /bin/bash

sum=0 

for i in {1..10}
do
	echo " Enter the number $i : "
	read n1
	sum=$((sum+n1))
done

echo "Total sum : $sum"
