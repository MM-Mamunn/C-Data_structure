///here start->link is the address of the first node.
///start used to store the location of the first node and does'nt 
///have any funtion to store data

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
  node *ptr = start->link;
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
 n->link=start->link;
 start->link= n;

  return;
}

// 1,2  2,3  3,4  4,0
void insert_tail(node *start, int val)
{
  node *n = new node(val);
  node *ptr = start->link;

  if (start->link == 0)
  {
    insert_head(start, val);
    return;
  }
  while (ptr->link != 0)
    ptr = ptr->link;

  ptr->link = n;
}

// 1,2  2,3  3,4  4,5  5,0
//alternative given below-that is not recommended
void insert(node *start, int index, int val)
{
  node *ptr = start->link;
  node *prev = start->link;
  int index_check = 0;
  if(index == 0)
  {
    insert_head(start,val);
    return;
  }
  while (ptr != 0)
  {
    index_check += 1;
    prev = ptr;
    ptr = ptr->link;
     if (index_check == index)
      break;
  }
  if (ptr == 0 && index_check != index)
  {
    cout << "Location not found\n";
    return;
  }
  // else
  node *n = new node(val);
  n->link = prev->link;
  prev->link = n;
}


// 1,2  2,3  3,4  4,5  5,0
void DELETE(node *start, int index)
{
  node *ptr = start->link;
  node *prev = start->link;
  node *prev2 = start->link;
  int index_check = 0;

  while (ptr != 0)
  {
    index_check += 1;
    prev2 = prev;
    prev = ptr;
    ptr = ptr->link;
     if (index_check == index)
      break;
  }
  if (ptr == 0 && index_check != index || index == 0)
  {
    cout << "Location not found\n";
    return;
  }
 
  if (ptr == 0 && index == 1)
  {
    // start->info = start->link->info;
    // start->link = start->link->link;
    start->link=0; 
    return;
  }
  if(index == 1)
  {
    start->link=start->link->link;
    //or start->link=ptr;
    return;
  }
  prev2->link = ptr;
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


///alternative of insert- not recommended
// void insert(node *start, int index, int val)
// {
//   node *ptr = start->link;
//   int index_check = 0;
//   if(index == 0 && ptr->link == 0 )
//   {
//     insert_head(start,val);
//     return;
//   }
//   while (ptr->link != 0)
//   {
//     index_check += 1;
//     if (index_check == index)
//       break;
//     ptr = ptr->link;
//   }
//   // cout<<"ptr-link "<<ptr->link<<" indexchc "<<index_check<<" index "<<index<< endl;
//   if (ptr->link == 0 && index_check + 1 != index)
//   {
//     cout << "Location not found\n";
//     return;
//   }

//   // else
//   node *n = new node(val);
//   n->link = ptr->link;
//   ptr->link = n;
// }
