#!/bin/bash

echo "Compiling functions.cpp..."
g++ -c functions.cpp -o functions.o

if [ $? -eq 0 ]; then
    echo "functions.cpp compiled successfully."
else
    echo "Error: functions.cpp compilation failed."
    exit 1
fi

echo "Compiling main.cpp..."
g++ -c main.cpp -o main.o

if [ $? -eq 0 ]; then
    echo "main.cpp compiled successfully."
else
    echo "Error: main.cpp compilation failed."
    exit 1
fi

echo "Linking object files..."
g++ functions.o main.o -o play

if [ $? -eq 0 ]; then
    echo "Linking successful. Binary created: play"
else
    echo "Error: Linking failed."
    exit 1
fi

# Clean up object files
rm -f functions.o main.o

echo "Compilation process completed."
