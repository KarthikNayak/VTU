/*
 * Create a stack of integers. The '+' and '-' operators are overloaded to push and pop elements from the stack respectively.
 *
 *Written for the Turbo C compiler. 
 */

#include <iostream.h>

/* create a class called STACK. Internally an array will be used to store the elements. The variable 'top' will always point to the top of the STACK. The variable 'size' will hold the maximum size of the stack */
class STACK 
{
	private:
		int a[10],size,top; 
	public:
		STACK(int n)
		{
			top = -1;
			size = n;
		}
  // declare the member functions. They will be defined later on.
		void operator + (int x); 
  		void operator - ();
  // A friend function can access all the members of the class STACK
  		friend ostream &operator << (ostream &out, STACK &st);
};

void STACK::operator + (int x) // overload the operator '+'
{
	if (top == size - 1)
		cout<<"Stack overflow.";
	else
	  // increment the variable 'top' and then assign 'x' to the new top position.
		a[++top] = x;
}

/* A detailed explanation on ostream is available at http://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/

 * A brief explanation is offered here:
 * The cout object and an object of class STACK is passed to the overloading function.
 * The return type is ostream to allow chaining of output commands. Eg. cout << s1 << s2;
 * The function basically outputs the contents of the whole stack. 
 */

ostream &operator << (ostream &out, STACK &st)
{
  //check for stack empty condition. If the variable 'top' is pointing to a negative number, the stack has to be empty.
	if (st.top == -1) 
		cout<<"Stack underflow.";
	else
	{
		for (int i = st.top; i >= 0; i--)
			cout<<st.a[i]<<"-->";
		// print the top element first until the bottom-most element of the stack.
		cout<<endl;
	}
	return out; // out is of type ostream
}

void STACK::operator - () // define the function that you declared in the class STACK
{
	if (top == -1)
	  cout<<"Stack empty."; // check for stack empty
  	else
	  cout<<"Element popped" << a[top--];
	/* Print the element that is about to be popped (removed) and then decrement the variable 'top'; essentially pointing to the variable 'top' the next element in the stack, hence removing any reference to the deleted element. */
}

int main()
{
	int n,ch,x;
	cout<<"Enter the size of the stack: ";
	cin>>n;
	STACK s1(n); // create an object of class STACK and pass 'n' to the constructor
	while(1) // infinite loop, until broken.
	{
		cout<<"\n1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter your choice\t";
		cin>>ch; 
		switch (ch) // switch to the choice.
		  {
		  case 1:
		    cout << "Enter the data: ";
		    cin >> x;
		    s1 + x;
		    /* operator '+' has been overloaded. Hence, when the '+' operator receives an object as an operand, the overloaded operator function is called. It is essentially pushing the value of x to the stop of the stack.*/
		    break;

		  case 2:
		    -s1; // the operator '-' has been overloaded and the object 's1' is sent as a parameter to the overloading function. It essentially pops the top element. 
		    break;

		  case 3:
		    cout << "Stack contents: " << endl;
		    cout << s1; // The operator << is overloaded
		    break;

		  case 4:
		    return 1; // equivalent to exit(0);
		  }
	}
	return 0;
}
