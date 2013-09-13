#include<iostream>
#include<conio.h>
#include<process.h>
class date
{
	int flag,dd,mm,yy;
	public:date(int d,int m,int y)
			{
				dd=d,mm=m,yy=y;
				if(y%4==0)
				flag=1;
				else
				{
					flag=0;
					if(m==2&&d>28)
					{
						cout<<"error since not a leap year";
						getch();
						exit(0);
					}
				}	
			}
	int return_date(date.d);
	int operator-(date d2);
	date operator+(int n);
	friend ostream & operator<<(ostream & out,date d1);
};
int a[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[20]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int date :: operator-(date d2)
{
	int a1,a2,x=0;
	date d1(dd,mm,yy);
	if(d1.dd==d2.dd&&d1.mm==d2.mm&&d1.yy==d2.yy)
		return x;
	if(d1.dd<d2.dd&&d1.mm==d2.mm&&d1.yy==d2.yy)
	{
		cout<<"error since 2nd data is greater than 1st";
		getch();
		exit(0);
	}
	if(d1.mm<d2.mm&&d1.yy==d2.yy)
	{
		cout<<"error since 2nd date is greater than 1st";
		getch();
		exit(0);
	}
	if(d1.yy<d2.yy)
	{
		cout<<"error since 2nd date is greater than 1st";
		getch();
		exit(0);
	}
	a1=return_date(d1);
	a2=return_date(d2);
	for(int i=d1.yy-1;i>d2.yy;i--)
	{
		if(i%yy==0)
			x=x+366;
		else
			x=x+365;
	}
	if(d1.yy==d2.yy)
		x=x+a1-a2;
	else
	{
		x=x+a;
		if(d2.yy%4==0)
			x=x+(366-a2);
		else
			x=x+(365-a2);
	}
	return x;
}
int date :: return_date(date d)
{
	int int_val=d.dd;
	if((d.flag==1)&&(d.mm>2))
	{
		for(int i=0;i<d.mm;i++)
		int_val=int_val+a[i];
		int_val++
	}
	else
	{
		for(int i=0;i<d.mm;i++)
		int_val=int_val+a[i];
	}
	return int_val;
}
date :: operator +(int n)
{
	date d(dd,mm,yy);
	for(int i=0;i<n;i++)
	{
		d.dd++;
		if(d.yy%4==0)
			{
				d.flag=1;
				if(d.dd>b[d.mm])
				{
					d.dd=1;
					d.mm++;
				}
			}
			else
			{
				d.flag=0;
				if(d.dd>a[d.mm])
				{
					d.dd=1;
					d.mm++;
				}
			}
			if(d.mm>12)
			{
				d.mm=1;
				d.yy++;
			}
	}
	return d;
}
otream & operator<<(ostream&out,date d1)
{
	cout<<d1.dd<<"-"<<d1.mm<<"-"<<d.yy;
	return out;
}
void main()
{
	int d,m,,no_of_day;
	clrscr();
	cout<<"enter a valid date";
	cin>>d>>m>>y;
	if(d>b[m]||m>12)
	{
		cout<<"error";
		getch();
		exit(0);
	}
	date d1(d,m,y)
	cout<<"enter a valid date lesser than first date";
	cin>>d>>m>>y;
	if(d>b[m]||m>12)
		{
			cout<<"error";
			getch();
			exit(0);
		}
		date d2(d,m,y);
		no_of_days=d1-d2;
		cout<<"difference btw 2 dates is"<<no_of_days;
		cout<<"enter no of days to be added ti first date:\n";
		cin>>no_of_days;
		d2=d2+no_of_days;
		cout<<"the new date is:"<<d2<<endl;
		getch();
	}	