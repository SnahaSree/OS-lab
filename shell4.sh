#reverse string
#!/bin/bash
read -p "Enter a string" s
rev=""
l=${#s}
for((i=l-1;i>=0;i--))
do
rev=$rev${s:$i:1}
done
echo "REVERSE STRING: $rev"
