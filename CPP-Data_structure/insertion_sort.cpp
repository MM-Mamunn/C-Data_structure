#include<bits/stdc++.h>
using namespace std;

int main()
{
    int     n;
    cin>>n;
    int     a[n+1];
    
    for(int i =1; i<=n; i++)
        cin>>a[i];
    
    for(int i =2; i<=n; i++)
    {
        int     key = a[i];
        int     j = i-1;
        while(j>0 && a[j] > key)
        {
            a[j+1] = a[j];
            j-=1;
        }
        a[j+1]= key;
    }
    
    for(int i =1; i<=n; i++)
        cout<<a[i]<<" ";
    
    return 0;
}








/* method related to theory as arr[0] = -infinity */

#include<bits/stdc++.h>

using namespace std;

int main()
{
   int arr[7]={-10000,3,2,6,1,5};
   int temp,ptr;
   for(int i =1;i<=5;i++)
   {
    ptr = i -1;
    temp = arr[i];
    while(temp<arr[ptr])
    {
        arr[ptr+1]=arr[ptr];
        ptr-=1;
    }
    arr[ptr+1]= temp;
   }
   for(int i =1;i<=5;i++)
   cout<<arr[i]<<" ";
    return 0;
}
