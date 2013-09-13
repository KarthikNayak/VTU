#include<iostream>
#include<iomanip.h>
class OCTAL
{
	int num;
	public: OCTAL(int n)
			{
				num=n;
			}
			friend int operator+(OCTAL num1,OCTAL num2);
			friend ostream & operator<<(ostream &print,OCTAL n);
};
int operator+(OCTAL n1,OCTAL n2)
  { 
   return(n1.num+n2.num);
  }
 ostream & operator<<(ostream & print,OCTAL o)
  {
    print<<setbase(8)<<o.num;
    return print;
  } 
  void main()
  {
   int x,k,y;
   cout<<"enter the decimal no";
   cin>>x;
   OCTAL h=x;
   cout<<"the convert 1sr OCTAL num is \n"<<h;
   cout<<"enter the 2nd decimal num"<<"\n";
   cin>>k;
   y=h+k;
   cout<<"addition of two octal nos is\n"<<y;
  } 