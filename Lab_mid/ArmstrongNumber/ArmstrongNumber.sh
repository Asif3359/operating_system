#! /bin/bash
echo "Armstrong number"
read -p "Enter a number : " num
temp=$num
sum=0
n=0

while [ $temp -gt 0 ]; do
	temp=$((temp/10))
	n=$((n+1))
done

temp=$num

while [ $temp -gt 0 ]; do
	digit=$((temp%10))
	sum=$((sum + digit**n))
	temp=$((temp/10))
done

if [ $num -eq $sum ]; then
	echo "$num is an Armstrong number."
else
	echo "$num is not  an Armstrong number."
fi
