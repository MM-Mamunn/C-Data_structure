#include<bits/stdc++.h>
using namespace std;

int main()
{
string p,t;
cin>>t>>p;
int index =0;
int s ,r;
s= t.size();
r=p.size();

for(int i =1 ;i<=(s-r+1);i++) 
{ bool a=false;
    for(int j =1;j<=r;j++)
    {
        if(p[j] != t [i+j-1])
       {
       a = true;
       }
    }
    if(a == true)
    continue;
    index = i;
    break;
}
cout<<index<<endl;
}