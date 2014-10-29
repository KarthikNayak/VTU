if [ $# -eq 0 ]; then
    echo "No arguments specified."
    exit
fi

rm -f generator.sh
for file in $@
do
    content=`cat $file`
    # FIX: Messes up with files with quotes
    echo "echo \"$content\" > $file" >> generator.sh
done
