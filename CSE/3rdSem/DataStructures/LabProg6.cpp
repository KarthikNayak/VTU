/*Program to add two strings using a class STRIGN and overloading 
the << operator. The Stings are "VTU" and "BELGAUM" and we must 
use the cioy constructor*/
 
//Header File 
#include <iostream>
#include <string.h>
using namespace std;

class STRING
{
	private:
		char str[20];
	public:
		STRING()
		{
			strcpy(str,"");
		}
		STRING(const char *s)
		{
			strcpy(str,s);
		}
		STRING operator+(STRING ss)
		{
			STRING temp;
			strcpy(temp.str,str);
			strcat(temp.str,ss.str);
			return temp;
		}
		friend ostream& operator<<(ostream& out,STRING ss)
		{
			cout<<ss.str;
			return out;
		}
};

int main()
{
	STRING S1="VTU";
	STRING S2="BELGAUM";
	cout<<"String 1:	";
	cout<<S1<<endl;
	cout<<"String 2:	";
	cout<<S2<<endl;
	STRING S3=S1+S2;
	cout<<"String 3:	";
	cout<<S3<<endl;
	return 1;
}