#!/bin/bash

test_count=0

make

echo
echo "--- Testing errors ------"

echo
echo "No args given:"
valgrind --leak-check=full ./RPN 2>val.output
test_count=$((test_count + 1))


echo
echo "Too many args:"
valgrind --leak-check=full ./RPN "a" "b" "c" 2>>val.output
test_count=$((test_count + 1))


CMD="*5 3 +"
echo
echo "Invalid sign, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="+ 2"
echo
echo "Operator missing Numbers, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="2 3 ++"
echo
echo "Operator after Operator, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="10"
echo
echo "Number not less then 10, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="lel"
echo
echo "Invalid character, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))



CMD=""
echo
echo "No numbers given, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="1 2"
echo
echo "Missing Operators, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


echo
echo "--- Testing negatives ---"


CMD="-1"
echo
echo "Signedness, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="-1 -1 +"
echo
echo "Adding neg numbers, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="-4000 -20000 -500000 + +"
echo
echo "Adding big neg numbers, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


echo
echo "--- Testing positives ---"


CMD="+1"
echo
echo "Signedness, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="1 1 +"
echo
echo "Adding pos numbers, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="9 9 9 9 9 9 + + + + +"
echo
echo "Adding big pos numbers, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


echo
echo "----- Subject Tests -----"


CMD="8 9 * 9 - 9 - 9 - 4 - 1 +"
echo
echo "Subject 1, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="7 7 * 7 -"
echo
echo "Subject 2, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="1 2 * 2 / 2 * 2 4 - +"
echo
echo "Subject 2, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


CMD="(1 + 1)"
echo
echo "Subject 1, Given: [$CMD]"
valgrind --leak-check=full ./RPN "$CMD" 2>>val.output
test_count=$((test_count + 1))


echo "
...----===  Results  ===----...
"
cat val.output | grep "All heap blocks were freed -- no leaks are possible" | wc -l | awk '{printf $0}' 
echo "/$test_count Tests were leakless"

rm -f val.output