echo "hwllo"
stop=0
while test $stop -eq 0
do 
cat << EOF
1:print the date
2,3  :print the current workign directory
4:exit 
EOF
echo 
echo "choice?"
read rep
echo 
case $rep in 
	 "1")
       date 
       ;;
      "2"|"3")
        pwd 
        ;;
        "4")
		stop=1
		;;
		*) 
        echo "JJJ"
        ;;
      esac
     done
   