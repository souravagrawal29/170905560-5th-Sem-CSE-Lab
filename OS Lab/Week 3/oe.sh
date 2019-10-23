#!/bin/bash
echo -n "Enter numnber : "
read n
 
rem=$(( $n % 2 ))
 
if [ $rem -eq 0 ]
then
  echo "even number"
else
  echo "oddnumber"
fi