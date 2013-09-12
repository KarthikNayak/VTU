#include<iostream.h>
class EMPLOYEE
{
 private:
  int emp_code, basic_sal, all_allowances;
  int net_sal, gross_sal;
  float it;

  char emp_name[20];

 public:

  void getData()
  {
    cout << "Enter the emp_name: ";
    cin >> emp_name;
    cout << "Enter the employee code: ";
    cin >> emp_code;
    cout << "Enter the basic salary: ";
    cin >> basic_sal;
  }

  void calculate()
  {
    all_allowances = (12.3 / 100) * basic_sal;
    gross_sal = basic_sal - all_allowances;
    it = (30.0 / 100) * gross_sal;
    net_sal = basic_sal + all_allowances - it;
  }

  void display()
  {
    cout << "All allowances = " << all_allowances << endl;
    cout << "Income Tax = " << it << endl;
    cout << "Net Salary = " << net_sal << endl;
  }
};

void main()
{
  EMPLOYEE P;
  clrscr();
  p.getdata();
  p.calculate();
  p.display();
  getch();
} 
  
