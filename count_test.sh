# !/bin/bash
if [ "$1" == "-1" ]; then
	ARG=`ruby -e "puts (-99..0).to_a.shuffle.join(' ')"`;
	echo $ARG;
	if [ "$2" == "-nowc"  ]; then
		./push_swap $ARG;
	elif [ "$2" == "-ch" ]; then
		./push_swap $ARG | ./checker $ARG;
	else
		./push_swap $ARG | wc -l;
	fi
elif [ "$1" == "-2" ]; then
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
	echo $ARG;
	if [ "$2" == "-nowc"  ]; then
		./push_swap $ARG;
	elif [ "$2" == "-ch" ]; then
		./push_swap $ARG | ./checker $ARG;
	else
		./push_swap $ARG | wc -l;
	fi
elif [ "$1" == "-3" ]; then
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`;
	echo $ARG;
	if [ "$2" == "-nowc"  ]; then
		./push_swap $ARG;
	elif [ "$2" == "-ch" ]; then
		./push_swap $ARG | ./checker $ARG;
	else
		./push_swap $ARG | wc -l;
	fi
elif [ "$1" == "-4" ]; then
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`;
	echo $ARG;
	if [ "$2" == "-nowc"  ]; then
		./push_swap $ARG;
	elif [ "$2" == "-ch" ]; then
		./push_swap $ARG | ./checker $ARG;
	else
		./push_swap $ARG | wc -l;
	fi
elif [ "$1" == "-5" ]; then
	for i in {1..100}
	do
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
		echo $ARG;
		if [ "$2" == "-nowc"  ]; then
			./push_swap $ARG;
		elif [ "$2" == "-ch" ]; then
			./push_swap $ARG | ./checker $ARG;
		else
			./push_swap $ARG | wc -l;
		fi
	done
elif [ "$1" == "-6" ]; then
	for i in {1..100}
	do
		ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`;
		echo $ARG;
		if [ "$2" == "-nowc"  ]; then
			./push_swap $ARG;
		elif [ "$2" == "-ch" ]; then
			./push_swap $ARG | ./checker $ARG;
		else
			./push_swap $ARG | wc -l;
		fi
	done
elif [ "$1" == "-7" ]; then
	for i in {1..100}
	do
		ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`;
		echo $ARG;
		if [ "$2" == "-nowc"  ]; then
			./push_swap $ARG;
		elif [ "$2" == "-ch" ]; then
			./push_swap $ARG | ./checker $ARG;
		else
			./push_swap $ARG | wc -l;
		fi
	done
elif [ "$1" == "-8" ]; then
	ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
	echo $ARG;
	if [ "$2" == "-nowc"  ]; then
		./push_swap $ARG;
	elif [ "$2" == "-ch" ]; then
		./push_swap $ARG | ./checker $ARG;
	else
		./push_swap $ARG | wc -l;
	fi
elif [ "$1" == "-9" ]; then
	for i in {1..100}
	do
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
		echo $ARG;
		if [ "$2" == "-nowc"  ]; then
			./push_swap $ARG;
		elif [ "$2" == "-ch" ]; then
			./push_swap $ARG | ./checker $ARG;
		else
			./push_swap $ARG | wc -l;
		fi
	done
elif [ "$1" == "-10" ]; then
	for i in {1..100}
	do
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`;
		echo $ARG;
		if [ "$2" == "-nowc"  ]; then
			./push_swap $ARG;
		elif [ "$2" == "-ch" ]; then
			./push_swap $ARG | ./checker $ARG;
		else
			./push_swap $ARG | wc -l;
		fi
	done
elif [ "$1" == "-11" ]; then
	ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`;
	echo $ARG;
	if [ "$2" == "-nowc"  ]; then
		./push_swap $ARG;
	elif [ "$2" == "-ch" ]; then
		./push_swap $ARG | ./checker $ARG;
	else
		./push_swap $ARG | wc -l;
	fi
fi

