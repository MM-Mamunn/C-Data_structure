#include<bits/stdc++.h>
using namespace std;
class stk{
    public:
      int arr[100];
      int n;
      int i = 0;
      stk(){};
      stk(int n)
      {
       this->n = n;
      }
      void top()
      {
        if(i == 0)
        cout<<0<<endl;
        else
        cout<<arr[i]<<endl;
      }
      void push(int x)
      {
        if(i == n)
        {
            cout<<"overflow ";
            return;
        }
        i+=1;
        arr[i]= x;
      }
      void pop()
      {if(i == 0)
      {
         cout<<"underflow";
            return;
      }
        i-=1;
      }
      void all ()
      {
        for(int j =1;j<=i;j++)
        {
            cout<<arr[j]<<" ";
        }
      }
} ;

int main()
{
    stk obj(3);
   for(;;)
   {
    int k;
    cin>>k;
    if(k ==1 )
    {
        int c;
        cin>>c;
        obj.push(c);
        obj.top();
    }
     if(k ==2 )
    {
        
        obj.pop();
        obj.top();
    }
 if(k ==3 )
    {
        
        obj.all();
    }

   }   


}