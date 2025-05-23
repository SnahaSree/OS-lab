#count file in directory
#!/bin/bash
count=$(ls -1 | wc -l)
echo "Total files: $count"
