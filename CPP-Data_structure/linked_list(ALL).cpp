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

  for (;;)
  {
    cout << ptr->info << " ";
    if (ptr->link == 0)
      break;
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
 //else
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
  node *prev = start;
  int index_check = 0;

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
    cout << "index " << index << " in check " << index_check << endl;
    cout << "Location not found\n";
    return;
  }

  // else
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

  // insert_tail(start, 4);
  // display(start);
  // insert_tail(start, 5);
  // display(start);
  /// insert at tail== stop and

  /// insert start
  // display(start);
  insert(start, 1, 9);
  display(start);
  insert(start, 1, 7);
  display(start);
  // insert(start, 2, 4);
  // display(start);
  // insert(start, 4, 1);
  // display(start);

  /// insert head == start
  int k;
  insert_head(start, 10);
  display(start);
  insert_head(start, 20);
  display(start);
  insert_head(start, 30);
  display(start);
  /// insert head == stop
}