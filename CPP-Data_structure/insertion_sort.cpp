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