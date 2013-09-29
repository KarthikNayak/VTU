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
  N_LIST *head; //make a pointer, head, of type class N_LIST. 
public:
  L_LIST() // constructor. Sets the initial (empty list) value of head as NULL
  {
    head = NULL;
  }
  // declare all the member functions
  void insert_front();
  int delete_front();
  void display();
  ~L_LIST() //destructor
  {
    delete head;
  }
};

void L_LIST::insert_front()
{
  N_LIST *newnode; // make a pointer of type N_LIST called newnode.
  int item;
  newnode = new N_LIST; // dynamically allocate memory and point the pointer newnode to it. That is, the address of the allocated memory is stored as the value of newnode.
  cout << "\tEnter the element to be inserted: ";
  cin >> item; // get the new item from the user.
  newnode->data = item; // Store just input data into the data member of newnode which is of type N_LIST.
  /* Assign the value of head to ptr member of the newnode object (which is of class N_LIST).
   * 'head' points to the first element of the list.
   * Eg: head -> node1 -> node2 -> node3 -> NULL. Remember, NULL was the initial value of head.
   * 0 elements:
   head -> NULL
   * 1 element:
   head -> node1 -> NULL
   * 2 elements (insertion at front of list)
   head -> node2 -> node1 -> NULL
  */
  newnode->ptr = head;
  head = newnode;
}

int L_LIST::delete_front()
{
  N_LIST *temp;
  int item;
  if (head == NULL) // head is usually pointing to the next element in the list. If it doesn't point in anything(ie., points to NULL), it is taken that the list is empty.
    {
      cout << "\tList is empty." << endl;
      return 1;
    }
  temp = head; //Assign the current first node to temp. 
  cout << "\tDeleted element is " << temp->data << endl; //output the data that is about to be deleted.
  item = temp->data; // the function returns the item that was deleted and hence we shall keep it aside before freeing so that we can return it later.
  head = head->ptr;
  /*
   * head is the first node. It's ptr (link) is pointing to the second node.
   * After deletion, the second element will be the first element. So we assign the new head as the second node.
   */
  delete(temp); // free the memory occupied by the first node (we pointed temp to head earlier)
  return item; // return the item that was deleted.
}

void L_LIST::display() // function to display the whole list
{
  N_LIST *temp; 
  temp = head; // make temp point to the first node.
  if( head == NULL ) //empty list
    {
      cout << "List is empty." << endl;
      return;
    }
  cout << "\n\tContents of the list..." << endl;
  while (temp != NULL) // Starting at the first element, traverse the whole list. Break when temp points to NULL.
    {
      cout << temp->data << "-->"; //output the data field.
      temp = temp->ptr; // make temp to point to the next node (whose link is contained in the current node's ptr field). The last node will contain NULL as it's ptr value.
    }
  cout << "NULL" << endl;
}

int main()
{
  L_LIST LL; //make an object of class L_LIST
  int choice, rpt=1;
  while(rpt) //loops until 0 is entered. You could just use while(1) instead, since case 4 exits the program -- removing the need for rpt.
    {
      //print everytime:
      cout << "\n\n\t1.Insert at front." << endl;
      cout << "\t2. Delete from front." << endl;
      cout << "\t3. Display." << endl;
      cout << "\t4. Exit." << endl;
      cout << "\n\tEnter your choice: ";
      cin >> choice;
      switch(choice)
	{
	case 1:
	  LL.insert_front(); //invoke the insert_front() method of the LL object. Insert at front of list
	  break;
	case 2:
	  LL.delete_front(); //delete from the front of list
	  break;
	case 3:
	  LL.display(); // display whole list
	  break;
	case 4:
	  return 1; // returns control from the main function back to the OS.
	}
      cout << "Press 1 to continue or press 0 to exit";
      cin >> rpt; 
    }
  return 0; // Program successfully completed.
}
/*
 * On a side note, returning 0 from the main function tells the OS that the program executed and terminated normally, whereas returning 1 indicates abnormal program termination.
