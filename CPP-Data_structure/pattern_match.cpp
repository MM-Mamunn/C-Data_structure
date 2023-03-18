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

for(int i =0 ;i<=(s-r);i++) 
{ bool a=false;
    for(int j =0;j<r;j++)
    {
        if(p[j] != t [i+j])
       {
       a = true;
       }
    }
    if(a == true)
    continue;
    
    index = i+1;
    break;
    
}
cout<<index<<endl;
}
