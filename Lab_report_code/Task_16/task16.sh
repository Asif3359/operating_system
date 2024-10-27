#! /bin/bash

# Generate a random number between 1 and 100
target=$(( RANDOM % 100 + 1 ))
guess=0
attempts=0

echo "Welcome to Guess the Number!"
echo "I'm thinking of a number between 1 and 100."

# Loop until the user guesses the correct number
while [ $guess -ne $target ]; do
    read -p "Enter your guess: " guess
    attempts=$(( attempts + 1 ))

    if [ $guess -lt $target ]; then
        echo "Too low! Try again."
    elif [ $guess -gt $target ]; then
        echo "Too high! Try again."
    else
        echo "Congratulations! You've guessed the number $target in $attempts attempts."
    fi
done
