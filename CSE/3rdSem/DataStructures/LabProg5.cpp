/*
 * Program to calculate the total allowances, income tax, and net salary of an employee.
 * Total Allowances = 12.3% of basic salary
 * Gross Salary = Basic Salary - Total Allowances
 * Income Tax = 30% of gross salary
 * Net Salary = Basic Salary + Total Allowances - Income Tax
 */

#include<iostream>
using namespace std; // used for cin and cout. If you want to avoid using it, try std::cout or std::cin

// define a new class named EMPLOYEE
class EMPLOYEE
{
  //private data members
 private:
  int emp_code, basic_sanl, all_allowances;
  int net_sal, gross_sal;
  float it;
  char emp_name[20];
  
  //public data members
 public:
  
  void getData() //get employee's data
  {
    cout << "Enter the emp_name: ";
    cin >> emp_name;
    cout << "Enter the employee code: ";
    cin >> emp_code;
    cout << "Enter the basic salary: ";
    cin >> basic_sal;
  }

  void calculate() // calculate financial data
  {
    all_allowances = (12.3 / 100) * basic_sal; 
    gross_sal = basic_sal - all_allowances;
    it = (30.0 / 100.00) * gross_sal;
    net_sal = basic_sal + all_allowances - it;
  }

  void display() // display all data
  {
    cout << "All allowances = " << all_allowances << endl;
    cout << "Income Tax = " << it << endl;
    cout << "Net Salary = " << net_sal << endl;
  }
};

int main()
{
  EMPLOYEE p; // create object 'p' of class EMPLOYEE 
  p.getData(); // call getData function/method of the object 'p'. Get all employee data
  p.calculate(); // calculate financial details
  p.display(); // display all data
  return 1;
}
