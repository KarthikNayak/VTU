#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include "iostream"
#include<unistd.h>
using namespace std;
int main()
{
	#ifdef _POSIX_JOB_CONTROL
		cout<<"system supports job control:"<<_POSIX_JOB_CONTROL<<endl;
	#else
		cout<<"sys does not support"<<endl;
	#endif
	#ifdef _POSIX_SAVED_IDS
		cout<<"sys suppostrs saved set UID and GID:"<<_POSIX_SAVED_IDS<<endl;
	#else
		cout<<"sys does not support"<<endl;
	#endif
	#ifdef _POSIX_CHOWN_RESTRICTED
		cout<<"chown restricted option:"<<_POSIX_CHOWN_RESTRICTED<<endl;
	#else
		cout<<"sys does not support"<<endl;
	#endif
	#ifdef _POSIX_NO_TRUNC
		cout<<"Truncation option:"<<_POSIX_NO_TRUNC<<endl;
	#else
		cout<<"sys does not support"<<endl;
	#endif
	#ifdef _POSIX_VDISABLE
		cout<<"disable char for terminal files"<<_POSIX_VDISABLE<<endl;
	#else
		cout<<"sys does not support"<<endl;
	#endif
	return 0;
}
