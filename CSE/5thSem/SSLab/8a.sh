if [ $# -ne 2 ]; then
    echo "arguments invalid"
    exit
fi
perm1=`ls -l $1 | gawk '{ print $1}'`
perm2=`ls -l $2 | gawk '{ print $1}'`
if [ "$perm1" == "$perm2" ]; then
    echo "$perm1"
else
    echo "File : $1, Permission : $perm1"
    echo "File : $2, Permission : $perm2"
fi
