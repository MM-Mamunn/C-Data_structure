///here start it self the first element of the list
///you can follow the 2nd version from the folder


#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class node
{
public:
  int info = 0;
  node *link = 0;
  node(int info = 0)
  {
    this->info = info;
  }
};

void display(node *start)
{
  node *ptr = start;
  cout << endl;

  while (ptr != 0)
  {
    cout << ptr->info << " ";
    ptr = ptr->link;
  }
  cout << endl;
}

/// insert at head
// 1,2  2,3  3,4  4,0
void insert_head(node *start, int val)
{

  node *n = new node(val);
  node *temp = new node(val);
  node *ptr = start;
  int count = 0;
  while (ptr->link != 0)
  {
    count += 1;
    ptr = ptr->link;
  }
  if (count == 0 && start->info == 0)
  {
    start->info = n->info;
    return;
  }
  // else
  n->link = start;
  temp->link = start->link;
  start->link = n;
  n->link = temp->link;

  temp->info = start->info;
  start->info = n->info;
  n->info = temp->info;

  return;
}

// 1,2  2,3  3,4  4,0
void insert_tail(node *start, int val)
{
  node *n = new node(val);
  node *ptr = start;

  if (start->info == 0)
  {
    insert_head(start, val);
    return;
  }
  while (ptr->link != 0)
    ptr = ptr->link;

  ptr->link = n;
}

// 1,2  2,3  3,4  4,5  5,0
void insert(node *start, int index, int val)
{
  node *ptr = start;
  int index_check = 0;
  if(index == 0 && ptr->link == 0 && start->info ==0)
  {
    insert_head(start,val);
  }
  while (ptr->link != 0)
  {
    index_check += 1;
    if (index_check == index)
      break;
    ptr = ptr->link;
  }
  // cout<<"ptr-link "<<ptr->link<<" indexchc "<<index_check<<" index "<<index<< endl;
  if (ptr->link == 0 && index_check + 1 != index || start->info == 0)
  {
    cout << "Location not found\n";
    return;
  }

  // else
  node *n = new node(val);
  n->link = ptr->link;
  ptr->link = n;
}
// 1,2  2,3  3,4  4,5  5,0
void DELETE(node *start, int index)
{
  node *ptr = start;
  node *prev = start;
  int index_check = 0;

  while (ptr->link != 0)
  {
    index_check += 1;
    if (index_check == index)
      break;
    prev = ptr;
    ptr = ptr->link;
  }
  // cout<<"ptr-link "<<ptr->link<<" indexchc "<<index_check<<" index "<<index<< endl;
  if (ptr->link == 0 && index_check + 1 != index || start->info == 0)
  {
    cout << "Location not found\n";
    return;
  }
  if (index_check == 0 && start->link == 0)
  {
    start->info = 0;
    return;
  }
  if (index == 1)
  {
    start->info = start->link->info;
    start->link = start->link->link;
    return;
  }
  prev->link = ptr->link;
}

int main()
{
  node *start, *ptr;
  //(node *) malloc(sizeof(node));
  start = new node;

  for(;;)
  {
    cout<<"Enter 1 for insert at head\n";
    cout<<"Enter 2 for insert at any index\n";
    cout<<"Enter 3 for insert at tail\n";
    cout<<"Enter 4 for delete at any position\n";
    cout<<"Enter 5 for display\n";
    int choice = 1;
    cin>>choice;
    if(choice == 1)
     {
       int val ;
       cout<<"Enter value to insert at head : ";
       cin>>val;
       insert_head(start,val);
       display(start);
     }
    else if(choice == 2)
     {
       int val,index;
       cout<<"Enter value to insert : ";
       cin>>val;
       cout<<"\nEnter index where to insert: ";
       cin>>index;
       insert(start,index,val);
       display(start);
     }

    else if(choice == 3)
     {
      int val ;
       cout<<"Enter value to insert at tail: ";
       cin>>val;
       insert_tail(start,val);
       display(start);
     }
    else if(choice == 4)
     {
      int index;
      
       cout<<"Enter index where to delete: ";
       cin>>index;
       DELETE(start,index);
       display(start);
     }
    else if(choice == 5)
     {
      display(start);
     }
}
}