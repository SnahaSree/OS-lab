#create a file
#!/bin/bash
read -p "Enter filename to create: " fname
touch "$fname"
echo "File '$fname' created."
#delete a file
#!/bin/bash
read -p "Enter filename to delete: " fname
rm "$fname"
echo "File '$fname' deleted."
#copy a file
#!/bin/bash
read -p "Enter source file: " src
read -p "Enter destination file: " dest
cp "$src" "$dest"
echo "File copied from '$src' to '$dest'."
#rename a file
#!/bin/bash
read -p "Enter current filename: " old
read -p "Enter new filename: " new
mv "$old" "$new"
echo "File renamed to '$new'."
#move a fle
#!/bin/bash
read -p "Enter file to move: " file
read -p "Enter target folder: " folder
mv "$file" "$folder"
echo "File moved to '$folder'."

