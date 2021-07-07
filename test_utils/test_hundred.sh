n=1
while [ $n -le 100 ]
do
	echo "****************************************************************************"
    ARG=$(python3 ./test_utils/generate_hundred.py) ; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./checker $ARG
	n=$(( n+1 ))	 # increments $n
done