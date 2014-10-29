echo "Enter the two filenames"
read file1
read file2
perm1=`ls -l $file1 | gawk '{ print $1}'`
perm2=`ls -l $file2 | gawk '{ print $1}'`
if [ "$perm1" == "$perm2" ]; then
    echo "$perm1"
else
    echo "File : $file1, Permission : $perm1"
    echo "File : $file2, Permission : $perm2"
fi
