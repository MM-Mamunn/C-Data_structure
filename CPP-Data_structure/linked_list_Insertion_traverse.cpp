#include<bits/stdc++.h>
#include <numeric>
using namespace std;

class node{
  public:
  int info;
  node *link;
};

int main()
{
   node *start,*ptr;
 //(node *) malloc(sizeof(node));
   start =  new node; 
   ptr = start;
  // cout<<start<<endl;
   //cout<<ptr<<endl;

   for(int i =1;i<=3;i++)
   {
    cin>>ptr->info;
     if(i != 3)
    {
      ptr->link = new node;
      ptr = ptr->link;
    }
   
   }

   ptr->link=0;
   ptr = start;
   cout<<endl;
   for(;;)
   {
    cout<<ptr->info<<endl;
    if(ptr->link == 0)
      break;
    ptr = ptr->link;
   }
}