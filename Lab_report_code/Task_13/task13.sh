#! /bin/bash

echo "Enter your name:"
read name

echo "Enter your age:"
read age

if [ "$age" -lt 18 ]; then
   echo "You are a minor, $name."
elif [ "$age" -lt 65 ]; then
   echo "You are an adult, $name."
else
   echo "You are a senior, $name."
fi
