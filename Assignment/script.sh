echo "Enter string"
read str
val1=`grep $str$ $1 | wc -l`
val2=`grep $str$ $2 | wc -l`
val3=`grep $str$ $3 | wc -l`

echo "In $1 $str occurs $val1 times"
echo "In $2 $str occurs $val2 times"
echo "In $3 $str occurs $val3 times"
