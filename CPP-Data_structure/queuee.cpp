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
        if(f == 1 && r == n || (r+1) == f)
        {
            cout<<"Overflow\n";
        }
        else if(f == 0)
        {
            f+=1;
            r+=1;
            arr[r] = x;
        }
        else
        {
            r+=1;
            if(r > n)
                r= 1;
            arr[r] = x;

        }
        //cout<<"f r "<<f<<" "<<r<<endl;
    }
    void pop()
    {
        if(f == 0 )
        {
            cout<<"underflow\n";
            f=0,r=0;
        }
        else if(f == r)
        {
            f=0;
            r=0;
        }
        else
        {
            f+=1;
            if(f> n)
                f = 1;
        }
        cout<<"f r "<<f<<" "<<r<<endl;
    }
    int sizee()
    {
        if(f == 0)
            return 0;
        else if( r<f)
            return ((n-f)+r+1);
        else
            return (r-f+1);
    }

    void show()
    {
        int i =f;
        if(f == 0)
        {
            cout<<"Empty\n";
            return;
        }
        else if(f == r)
        {
            cout<<arr[f]<<endl;
            return;
        }
        for(;;)
        {
            if(i == r)
            {
                cout<<arr[i]<<" ";
                break;
            }

            cout<<arr[i]<<" ";
            i++;
            if(i == (n+1))
                i= 1;
        }
        cout<<endl;
    }
    void top()
    {
        if(f == 0)
            cout<<"empty\n";
        else
            cout<<arr[f]<<endl;
    }

};
int main()
{
    int k;
    queuee<int> q(5);

    for(;;)
    {
        cout<<"Enter 1 for push\nEnter 2 for pop\nEnter 3 for size\nEnter 4 for top\nEnter 5 for show all\n";
        cin>>k;
        if( k == 1)
        {
            int j;
            cin>>j;
            q.push(j);
            q.top();
        }
        else if(k == 2)
        {
            q.pop();
        }
        else if( k == 3)
        {
            cout<<q.sizee()<<endl;
        }
        else if( k == 4)
        {
            q.top();
        }

        else if( k == 5)
        {
            q.show();
        }
    }
    return 0;
}
