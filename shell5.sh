#string is palindrome or not
#!/bin/bash 
read -p "Enter a string :" s
rev=$(echo "$s" | rev)
if [ "$s"=="$rev" ]; then
echo "$s is a palindrome"
else
echo "$s is not a palindrome"
fi
