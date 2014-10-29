clear
if [ $# -eq 0 ]; then
    echo "No arguments"
else
    for ((i=$#; $i!=0; i=$i-1));
    do
	echo ${!i}
    done
fi
