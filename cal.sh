#!/bin/bash
echo "Enter two numbers:"
read a
read b
echo "Enter operation (+, -, *, /):"
read op

case $op in
  +) echo "$a + $b = $((a + b))" ;;
  -) echo "$a - $b = $((a - b))" ;;
  \*) echo "$a * $b = $((a * b))" ;;
  /) echo "$a / $b = $((a / b))" ;;
  *) echo "Invalid operation" ;;
esac
