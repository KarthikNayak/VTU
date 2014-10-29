if [ $# -eq 0 ]; then
    echo "No arguments specified."
    exit
fi

for file in $@
do
    echo "cat << FileInputDelimiter > $file
`cat $file`
FileInputDelimiter"
done > generator.sh
