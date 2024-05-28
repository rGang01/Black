# #!/bin/bash 
# echo "Enter a String"
# read input
# reverse=""


# len=${#input}
# for (( i=$len-1; i>=0; i-- ))
# do 
# 	reverse="$reverse${input:$i:1}"
# done
# if [ $input == $reverse ]
# then
#     echo "$input is palindrome"
# else
#     echo "$input is not palindrome"
# fi


# bubblesort

# #!/bin/bash
# arr=(10 8 20 100 12)
# echo "Array in original array is-"
# echo ${arr[*]}


# for((i=0; i<5; i++))
# do
# for((j=0; j<5-i-1; j++))
# do
# if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
# then
# temp=${arr[j]}
# arr[$j]=${arr[$((j+1))]}
# arr[$((j+1))]=$temp
# fi
# done
# done


# echo "Array in sorted order: "
# echo ${arr[*]}




# substring

# #!/bin/bash
# find_substring() {
# string="$1"
# substring="$2"
# length=${#substring}


# for (( i=0; i<${#string}; i++ ))
# do
# if [[ ${string:$i:$length} == "$substring" ]]
# then
# echo "Substring found at position $i"
# fi
# done
# }


# echo "Enter the string: "
# read string
# echo "Enter the substring to search for: "
# read substring


# find_substring "$string" "$substring"

#!/bin/bash

# Function to check if a number is palindrome
# is_palindrome() {
#     local num=$1
#     local reverse=0
#     local original=$num

#     while [ $num -gt 0 ]; do
#         remainder=$((num % 10))
#         reverse=$((reverse * 10 + remainder))
#         num=$((num / 10))
#     done

#     if [ $original -eq $reverse ]; then
#         echo "$original is a palindrome."
#     else
#         echo "$original is not a palindrome."
#     fi
# }

# # Function to check if a number is prime
# is_prime() {
#     local num=$1
#     local flag=0

#     if [ $num -lt 2 ]; then
#         echo "$num is not a prime number."
#         return
#     fi

#     for ((i = 2; i <= num / 2; i++)); do
#         if [ $((num % i)) -eq 0 ]; then
#             flag=1
#             break
#         fi
#     done

#     if [ $flag -eq 0 ]; then
#         echo "$num is a prime number."
#     else
#         echo "$num is not a prime number."
#     fi
# }

# # Function to generate Fibonacci series
# fibonacci_series() {
#     local n=$1
#     local a=0
#     local b=1
#     local i=0

#     echo "Fibonacci series up to $n terms:"
#     while [ $i -lt $n ]; do
#         echo -n "$a "
#         fn=$((a + b))
#         a=$b
#         b=$fn
#         i=$((i + 1))
#     done
#     echo
# }

# # Main program
# read -p "Enter a number: " number

# is_palindrome $number
# is_prime $number

# read -p "Enter the number of terms for Fibonacci series: " n
# fibonacci_series $n


#!/bin/bash

# String handling functions

# string="Hello, World!"

# # Length of the string
# length=${#string}
# echo "Length of the string: $length"

# # Extract substring
# substring=${string:7:5}
# echo "Substring: $substring"

# # Concatenate strings
# new_string="$string How are you?"
# echo "Concatenated string: $new_string"

# # Convert to uppercase
# uppercase=$(echo "$string" | tr '[:lower:]' '[:upper:]')
# echo "Uppercase: $uppercase"

# # Convert to lowercase
# lowercase=$(echo "$string" | tr '[:upper:]' '[:lower:]')
# echo "Lowercase: $lowercase"

# # Replace substring
# replaced_string=${string/Hello/Hi}
# echo "Replaced string: $replaced_string"






//Directory path file
# #!/bin/bash

# # Prompt the user to enter the directory
# echo "Enter the directory path:"
# read dir

# # Check if the directory exists
# if [ ! -d "$dir" ]; then
#     echo "The specified directory does not exist."
#     exit 1
# fi

# # Initialize variables to store the smallest file name and its length
# smallest_file=""
# smallest_length=0

# # Loop through all files in the directory
# for file in "$dir"/*
# do
#     # Check if it is a regular file
#     if [ -f "$file" ]; then
#         # Get the base name of the file (excluding the directory path)
#         base_name=$(basename "$file")
#         # Get the length of the file name
#         name_length=${#base_name}
        
#         # Update the smallest file name and its length if needed
#         if [ -z "$smallest_file" ] || [ "$name_length" -lt "$smallest_length" ]; then
#             smallest_file="$base_name"
#             smallest_length="$name_length"
#         fi
#     fi
# done

# # Check if a smallest file was found and print the result
# if [ -n "$smallest_file" ]; then
#     echo "The file with the smallest name is: $smallest_file"
# else
#     echo "No files found in the specified directory."
# fi





# //File make

# #!/bin/bash

# # Create a file
# touch myfile.txt
# echo "Created file: myfile.txt"

# # Create a hard link to the file
# ln myfile.txt myfile_hardlink.txt
# echo "Created hard link: myfile_hardlink.txt"

# # Create a soft link to the file
# ln -s myfile.txt myfile_symlink.txt
# echo "Created soft link: myfile_symlink.txt"

# # Append names of hidden files to hidden_files.txt
# echo "Appending names of hidden files to hidden_files.txt"
# for file in .*
# do
#     if [ -f "$file" ]; then
#         echo "$file" >> hidden_files.txt
#     fi
# done

# # Convert filenames from uppercase to lowercase
# echo "Converting filenames from uppercase to lowercase"
# for file in *
# do
#     # Check if the filename contains uppercase letters
#     if [[ "$file" =~ [A-Z] ]]; then
#         # Convert the filename to lowercase
#         lowercase_file=$(echo "$file" | tr 'A-Z' 'a-z')
#         # Rename the file
#         mv "$file" "$lowercase_file



# // Even odd no txt

# 1)Create input.txt with some numbers (one per line):


# echo -e "1\n2\n3\n4\n5\n6\n7\n8\n9\n10" > input.txt


# 2)Create the shell script classify_numbers.sh:


# #!/bin/bash

# # Check if input.txt exists
# if [ ! -f "input.txt" ]; then
#     echo "input.txt not found!"
#     exit 1
# fi

# # Clear the content of even.txt and odd.txt if they exist
# > even.txt
# > odd.txt

# # Read numbers from input.txt
# while read -r number; do
#     if [ $((number % 2)) -eq 0 ]; then
#         echo "$number" >> even.txt
#     else
#         echo "$number" >> odd.txt
#     fi
# done < input.txt

# echo "Even numbers are stored in even.txt"
# echo "Odd numbers are stored in odd.txt"






# //Linux Commands

# 1.	Change the password to a password you would like to use for the remainder of the semester.
# Command : passwd


# 2.	Display the date
# Command : date

# 3.	Count the number of lines in the /etc/passwd file
# Command : wc -l etc/passwd

# 4.	Find out who else is on the system
 
# Command : who

 
# 5.	Direct the output of the man pages for the date command to a file name mydate
# Command : man date > mydate.txt


# 6.	Create a subdirectory ‘mydir’
# Command : mkdir mydir


# 7.	Move the file mydate into new subdirectory
# Command : mv mydate.txt mydir


# 8.	Go to mydir and copy the file mydate to a new file called outdate
# Command : cp mydate outdate


# 9.	List the contents of the mydir
# Command : ls
 
 


# 10.	Do a long listing on the file ourdate and note the permissions.
# Command :ls -l outdate


# 11.	Display the name of the current directory starting from root directory
# Command : pwd


# 12.	Move the files in the directory mydir into the home directory
# Command : mv mydir/* .

# 13.	Display the first 5 lines of mydate
# Command : head -5 mydate


# 14.	Display the last 8 lines of the mydate
# Command : head -8 mydate

 
# 15.	Remove the directory mydir
# Command : rmdir mydir


# 16.	Redirect the out of the long listing of files to a file named list
# Command : ls -l > list.txt


# 17.	Select any 5 capitals of states in India and enter them in file named capitals1. Choose more capitals and enter them in a file named capitals2. Choose 5 more capitals and enter them in a file named capitals3. Concatenate all three files into file named capitals.
# Command : cat > capitals1
# cat > capitals2 cat > capitals3
# cat capitals1 capitals2 capitals3 > capitals



# 18.	Concatenate file capitals2 at the end of the file capitals.
# Command : cat capitals2 >> capitals

 
# 19.	Give read and write permission to all users for the capitals file.
# Command : chmod 666 capitals


# 20.	Give read permission to the owner of the file for capitals file.
# Command : chmod 466 capitals


# 21.	Create alias to concatenate the 3 files and redirect them to capitals and run it again.
# Command : alias concat=‘cat capitals1 capitals2 capitals3 > capitals’



# 22.	Find out the number of times ‘the’ appears in the mydate file.
# Command : grep -c “the” mydate


# 23.	Find out the line numbers on which the string ‘date’ appears in the file mydate.
# Command : grep -n “date” mydate

 
# 24.	Print all lines of mydate except those which have ‘i’ in them.
# Command : grep -v “i” mydate.txt

# 25.	
# List the words of 4 letters from the mydate Command : egrep -w “.{4}” mydate


# 26.	List 5 states in the northeast India in file my states. List their corresponding capitals in mycapitals file. Use paste command to combine the files.
# Command : cat > mystates
# cat > mycapitals
# paste mystates my capitals
# =

# 27.	Use the cut command to print 1 and 3 column of the /etc/passwd file.
# Command : cut -f1,3 /etc/passwd


# 28.	Count the number of people logged in on system and trap them in file using tee command
# Command : who | tee users
 
 


# 29.	Convert the contents of mystates into uppercase
# Command : tr ‘[a-z]’ ‘[A-Z]’ < mystates


# 30.	Create any two files and display the common values in them
# Command : comm capitals1 capitals
