#! /bin/bash

echo "Enter course names:"
read course1 course2 course3

echo "Enter marks for $course1:"
read s1 s2 s3 s4

echo "Enter marks for $course2:"
read s5 s6 s7 s8

echo "Enter marks for $course3:"
read s9 s10 s11 s12

echo "Average for $course1: $(( (s1 + s2 + s3 + s4) / 4 ))"
echo "Average for $course2: $(( (s5 + s6 + s7 + s8) / 4 ))"
echo "Average for $course3: $(( (s9 + s10 + s11 + s12) / 4 ))"

echo "Marks for 2nd to 4th students in $course3: $s10, $s11, $s12"
