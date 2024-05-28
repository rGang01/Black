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



