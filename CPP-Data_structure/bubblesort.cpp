#include<bits/stdc++.h>

using namespace std;

int main()
{
 int n;
 cin>>n;
 
int arr[n];

 for(int i =1;i<=n;i++)
   cin>> arr[i];
 
for (int i=1;i<=n-1;i++)
{
    int ptr =1;
   
     while(ptr<=n-i)
      {
        if(arr[ptr]> arr[ptr+1])
           {
            int t;
            t = arr[ptr];
            arr[ptr] =arr[ptr+1];
            arr[ptr + 1] = t;
           }
        ptr+=1;
      } 
}

 for(int i =1;i<=n;i++)
   cout<<arr[i]<<" "; 

}
