#include <iostream>
using namespace std;

class N_LIST
{
public:
  int data;
  N_LIST *ptr;
};

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

void L_LIST :: insert_front()
{
  N_LIST *newnode;
  int item;
  newnode = new N_LIST;
  cout << "\tEnter the element to be inserted: ";
  cin >> item;
  newnode->data = item;
  newnode->ptr = head;
  head = newnode;
}

int L_LIST :: delete_front()
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

void L_LIST :: display()
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
    return 1;
}
