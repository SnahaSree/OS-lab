#larger among 3
read -p "Enter 3 numbers:" a b c
if ((a>=b && a>=c)); then
echo "$a is larger"
elif ((b>=a && b>=c)); then 
echo "$b is larger"
else
echo "$c is lager"
fi
