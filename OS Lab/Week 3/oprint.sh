#!/bin/bash

echo -n "Number"
read n
stop=1
count=0
while [ $count -lt $n ]
do 
	rem=`expr stop\%2`
	if [ $rem!=0 ]
	then
		echo $stop
	    count=$((count +1))
	    stop=$((stop+1))
	 else 
	 	stop=$((stop+1))
	 fi
done 
