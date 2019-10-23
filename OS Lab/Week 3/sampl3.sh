x=0
while [ $x -le 20 ]
  do 
  	echo $x
  	x=$((x+12))
  done 

  while test $# != 0
  do 
  	echo $1
  	shift
  done 

