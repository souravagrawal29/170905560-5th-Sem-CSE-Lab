echo the name of this script is $0
echo the first argument is $1
echo a list of all the arguments is $*
echo this script places the date into a temporary file
echo called $1.$$
date>$1.$$ #redirect the output of date
ls $1.$$   # list the file
rm $1.$$  #remove the file
