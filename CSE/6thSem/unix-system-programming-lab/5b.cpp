#include<unistd.h>
#include<string.h>
#include "iostream"
#include<sys/types.h>
using namespace std;
int main(int argc,char *argv[])
{
if((argc<3&&argc>4)||(argc==4&&strcmp(argv[1],"-s")))
{
cout<<"usage:"<<argv[0]<<"[-s]<orig_file><new_link>\n";
return 1;
}
if(argc==4)
{
cout<<"symbolic link"<<endl;
return symlink(argv[2],argv[3]);
}
else 
{
cout<<"hard link"<<endl;
return link(argv[1],argv[2]);
}
return 0;
}
