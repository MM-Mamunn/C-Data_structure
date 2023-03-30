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
  cout << endl
       << endl;
  for (;;)
  {
    cout << ptr->info << " ";
    if (ptr->link == 0)
      break;
    ptr = ptr->link;
  }
  cout << endl;
}

///insert at head
void insert_head(node * start,int val)
{
  node *n = new node(val);
  
  start->info= n->info;
    return;
  
}

// 1,2  2,3  3,4  4,0
void insert_tail(node *start, int val)
{
  node *n = new node(val);
  node *ptr = start;
  // if (start->info == 0)
  // {
  //   start->info = n->info;
  //   return;
  // }
  if (start->info == 0)
  {
    insert_head(start,val);
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
  node *prev = start;
  int index_check = 0;

  // while (ptr->link != 0 && index_check < index)
  // {
  //   index_check += 1;
  //   prev = ptr;
  //   ptr = ptr->link;
  // }

 for(;;)
  {
    index_check += 1; 
    if(index_check== index);
    break;
    if(ptr->link == 0)
      break;
    ptr = ptr->link;
   
  }

  //cout<<"ptr-link "<<ptr->link<<" indexchc "<<index_check<<" index "<<index<< endl;
  if (ptr->link == 0 &&  index_check < index || ptr->info == 0 &&  index == 1 )
  {
    cout << "index " << index << " in check " << index_check << endl;
    cout << "Location not found\n";
    return;
  }
    if (start->info == 0)
  {
    insert_head(start, val);
    return;
  }
  //else
  node *n = new node(val);
  n->link = ptr->link;
  ptr->link = n;
}

int main()
{
  node *start, *ptr;
  //(node *) malloc(sizeof(node));
  start = new node;

  /// insert at tail==start
  // display(start);
  insert_tail(start, 3);
  display(start);
  insert_tail(start, 4);
  display(start);
  // insert_tail(start, 5);
  // display(start);
  /// insert at tail== stop and

  /// insert start
  //display(start);
 insert(start, 1, 9);
  display(start);
  insert(start, 1, 4);
  display(start);
  // insert(start, 1, 5);
  // display(start);
  // insert(start, 1, 6);
  // display(start);
  // insert(start, 2, 7);
  // display(start);
  // insert(start, 3, 8);
  // display(start);
  /// insert stop
}