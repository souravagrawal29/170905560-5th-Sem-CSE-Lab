#!/bin/bash

echo "Enter a, b and c coefficients of eqn:"
read a
read b
read c

discriminant=$(( $b * $b - ( 4 * $a * $c ) ))

D=2

if [ $discriminant -gt 0 ]
then
	D=1
elif [ $discriminant -eq 0 ]
then
	D=0
fi

case $D in
	"1")
		Droot=$(echo "scale=4; sqrt($discriminant)" | bc)
		root1=$(echo "scale=4; ( ( -1 * $b + $Droot ) / ( 2 * $a ) )" |bc)
		root2=$(echo "scale=4; ( ( -1 * $b - $Droot ) / ( 2 * $a ) )" |bc)
		echo "The 2 roots are $root1 and $root2"
		;;
	"0")
		Droot=$(echo "scale=4; sqrt($discriminant)" | bc)
		root=$(echo "scale=4; ( ( -1 * $b + $Droot ) / ( 2 * $a ) )" |bc)
		echo "The roots are identical with value $root"
		;;
	"2")
		echo "Roots are imaginary"
		;;
	esac