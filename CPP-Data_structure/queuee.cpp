
#include<bits/stdc++.h>
#include <numeric>
using namespace std;

template <class T>
class queuee
{
public:
    T arr[100];
    int n,f =0,r=0;

    queuee(int n)
    {
        this-> n =n;
    }
    void push(T x)
    {
        if(f == 0 && r == n || (r+1) == f)
        {
            cout<<"Overflow\n";
        }
        else
        {
            arr[r] = x;
            r+=1;
            if(r > n)
                r= 0;
        }
        cout<<"f r "<<f<<" "<<r<<endl;
    }
    void pop()
    {
        if(f == r)
        {
            cout<<"underflow\n";
            f=0,r=0;
        }
        else
        {
            f+=1;
            if(f> n)
                f = 0;
        }
        cout<<"f r "<<f<<" "<<r<<endl;
    }
    int sizee()
    { if( r<f)
        return ((n - (f-r)) +1);
      else
        return (r-f);
    }

    void show()
    {
        int i =f;
        while(i != r)
        {
            cout<<arr[i]<<" ";
            i++;
            if(i == (n+1))
                i= 0;
        }
        cout<<endl;
    }
    void top()
    {
        if(f == r)
            cout<<"0\n";
        else
        cout<<arr[f]<<endl;
    }

};
int main()
{
    int k;
    queuee<int> q(5);
   q.top();


    for(;;)
    {
        cout<<"Enter 1 for push\nEnter 2 for pop\nEnter 3 for size\nEnter 4 for top\n";
        cin>>k;
        if( k == 1)
        {
            int j;
            cin>>j;
            q.push(j);
            //cout<<q.sizee()<<endl;
           q.top();

        }
        else if(k == 2)
        {
            q.pop();
         //   cout<<q.sizee()<<endl;

            //  q.top();
        }
        else if( k == 4)
        {
            q.top();
        }

          else if( k == 3)
        {
            cout<<q.sizee()<<endl;
        }
    }
    return 0;
}
