echo "bol bhai numbers: "
read a 
read b 
  
echo "BATA BHAI kaunsa OP  :"
echo "1. +"
echo "2.-"
echo "3.*"
echo "4./"
read ch 
  
case $ch in
  1)res=`echo $a + $b | bc` 
  ;; 
  2)res=`echo $a - $b | bc` 
  ;; 
  3)res=`echo $a \* $b | bc` 
  ;; 
  4)res=`echo "scale=2; $a / $b" | bc` 
  ;; 
esac
echo "Result : $res"