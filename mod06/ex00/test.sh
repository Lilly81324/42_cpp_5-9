#!/bin/bash

NAME="ex00"
OUTPUT_FILE="test_output.txt"
EXPECTED_FILE="test_expected.txt"
DIFFERENCES_FILE="test_differences.txt"
DIFF_COUNTER="diff_counter.txt"
SAME_COUNTER="same_counter.txt"
ERIMP="impossible"
ERND="Non displayable"

rm -f $OUTPUT_FILE $EXPECTED_FILE $DIFF_COUNTER $SAME_COUNTER $DIFFERENCES_FILE 
touch $DIFF_COUNTER $SAME_COUNTER $DIFFERENCES_FILE
make

# ---=============================================----
TEST_CASE="0"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: $ERND
int: 0
float: 0.0f
double: 0.0" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="nan"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: $ERIMP
int: $ERIMP
float: nanf
double: nan" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="42"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: '*'
int: 42
float: 42.0f
double: 42.0" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="32"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: ' '
int: 32
float: 32.0f
double: 32.0" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="100"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: 'd'
int: 100
float: 100.0f
double: 100.0" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="-1"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: $ERIMP
int: -1
float: -1.0f
double: -1.0" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="9999999"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: $ERIMP
int: 9999999
float: 9999999.0f
double: 9999999.0" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="1.1"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: $ERND
int: 1
float: 1.1f
double: 1.1" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="1.4f"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: $ERND
int: 1
float: 1.4f
double: 1.4" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

# ---=============================================----
TEST_CASE="1.94"
./$NAME "$TEST_CASE" > $OUTPUT_FILE
echo \
"char: $ERND
int: 1
float: 1.9f
double: 1.9" \
> $EXPECTED_FILE
diff $OUTPUT_FILE $EXPECTED_FILE >> $DIFFERENCES_FILE
if [ $? -eq 1 ] ;
	then 
		echo "Error" >> $DIFF_COUNTER
		echo "Failed Case: $TEST_CASE"
else
	echo >> $SAME_COUNTER
fi

echo "---===Results===---"
echo -n "Failed : "
cat $DIFF_COUNTER | wc -l
echo -n "Working: "
cat $SAME_COUNTER | wc -l

LINES=$(wc -l < $DIFF_COUNTER)

if [ "$LINES" -eq 0 ];
	then
		echo "All correct, well done"
		rm -f $DIFFERENCES_FILE
	else
		echo "Error(s) encountered, generated $DIFFERENCES_FILE"
fi

rm -f $OUTPUT_FILE $EXPECTED_FILE $DIFF_COUNTER $SAME_COUNTER

# Notes: Struggles with very big numbers, such as 99999999 and above, rounds them weirdly for floats
# Also rounds up 