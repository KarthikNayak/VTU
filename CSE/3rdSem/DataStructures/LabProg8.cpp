/*
 * This program is written for the G++ compiler and varies slightly if other compilers like Turbo C++ are used.
 * This program will demonstrate a linked list; similar to "LabProg1.c"
 */

#include <iostream>
using namespace std; // This statement can be omitted if the Turbo C++ compiler is used.


/* Define a class that will be used to store the data. */
class N_LIST
{
public:
  int data;   // Will contain hold the element (aka data)
  N_LIST *ptr; //Will contain the link of the next node.
};  


/* Define a class that will be used to make and maintain the linked lists. */
class L_LIST
{
private:
  N_LIST *head;
public:
  L_LIST()
  {
    head = NULL;
  }
  void insert_front();
  int delete_front();
  void display();
  ~L_LIST()
  {
    delete head;
  }
};

void L_LIST::insert_front()
{
  N_LIST *newnode;
  int item;
  newnode = new N_LIST; // dynamically allocate memory and point the pointer *newnode to it. That is, the address of the allocated memory is stored as the value of newnode.
  cout << "\tEnter the element to be inserted: ";
  cin >> item; 
  newnode->data = item; // Store the just input data into the data member of newnode which is of type N_LIST.
  /* Assign the value of head to ptr member of the newnode object (which is of class N_LIST).
   * 'head' is the first element of the list. It contains the address of the last element in the list.
   * Eg: head -> node1 -> node2 -> node3 -> NULL. Remember NULL was the initial value of head.
   * 0 elements:
   head -> NULL
   * 1 element:
   head -> node1 -> NULL
   * 2 elements:
   head -> node2 -> node1 -> NULL
  */
  newnode->ptr = head;
  head = newnode;
}

int L_LIST::delete_front()
{
  N_LIST *temp;
  int item;
  if (head == NULL)
    {
      cout << "\tList is empty." << endl;
      return 1;
    }
  temp = head;
  cout << "\tDeleted element is " << temp->data << endl;
  item = temp->data;
  head = head->ptr;
  delete(temp);
  return item;
}

void L_LIST::display()
{
  N_LIST *temp;
  temp = head;
  if( head == NULL )
    {
      cout << "List is empty." << endl;
      return;
    }
  cout << "\n\tContents of the list..." << endl;
  while (temp != NULL)
    {
      cout << temp->data << "-->";
      temp = temp->ptr;
    }
  cout << "NULL" << endl;
}

int main()
{
  L_LIST LL;
  int choice, rpt=1;
  while(rpt)
    {
      cout << "\n\n\t1.Insert at front." << endl;
      cout << "\t2. Delete from front." << endl;
      cout << "\t3. Display." << endl;
      cout << "\t4. Exit." << endl;
      cout << "\n\tEnter your choice: ";
      cin >> choice;
      switch(choice)
	{
	case 1:
	  LL.insert_front();
	  break;
	case 2:
	  LL.delete_front();
	  break;
	case 3:
	  LL.display();
	  break;
	case 4:
	  return 1;
	}
      cout << "\tPress 1 to continue or 0 to exit." << endl;
      cin >> rpt;
    }
  return 0; // Program successfully completed.
}
