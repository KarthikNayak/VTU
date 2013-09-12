/*
 *Written for the G++ compiler
 */

#include<iostream>
#include<process>

class STACK
{
  int a[10], size, top;
public:
  {
    top = -1;
    size = n;
  }

  void operator + (int x);
  void operator - ();
  friend ostream &operator << (ostream &out, STACK &st);
};

void STACK :: operator + (int x)
{
  if (top == size - 1)
    cout << "Stack overflow.";
  else
    a[++top] = x;
}

ostream &operator << (ostream &out, STACK &st)
{
  if (st.top == -1)
    cout << "Stack underflow.";
  else
    {
      for (int i = st.top; i >= 0; i--)
	cout << st.a[i] << "-->";
      cout << endl;
    }
  return out;
}

void STACK :: operator - ()
{
  if (top == -1)
    cout << "Stack empty.";
  else
    cout << "Element popped" << a[top --];
}

int main ()
{
  int n, ch, x;
  cout << "Enter the size of the stack: ";
  cin >> n;
  STACK s1(n);
  while(1)
    {
      cout << "1. Push" << endl;
      cout << "2. Pop" << endl;
      cout << "3. Display" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter your choice";
      cin >> ch;
      switch (ch)
	{
	case 1:
	  cout << "Enter the data: ";
	  cin >> x;
	  s1 + x;
	  break;

	case 2:
	  -s1;
	  break;

	case 3:
	  cout << "Stack contents: " << endl;
	  cout << s1;
	  break;

	case 4:
	  return;
	}
    }
}
