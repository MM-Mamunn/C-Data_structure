
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val =0;
    node *left=0;
    node *right=0;
    node(int val =0)
    {
        this->val = val;
    }
};

void add_node(node *root,int val)
{
    node *n = new node(val);
    node *prev = n;
    int l =0,r=0;
    node *ptr = root;
    while(ptr!= 0)
    {
        if(ptr->val > val)
        {
            prev = ptr;
            ptr = ptr->left;
            l=1;r=0;

        }
        else{
            prev = ptr;
            ptr= ptr->right;
            r=1;l=0;
             }
    }
    if( l ==1)
    prev->left= n;
    else
        prev->right = n;
}

//its an pre order travarsal--- Root->left->right
void print(node *ptr)
{

       if(ptr == 0)
        return;
       cout<<ptr->val<<endl;
       print(ptr->left);
       print(ptr->right);

}

int main()
{
    node *root = new node(50);
    node *prev = root;
    //cout<<"hi";
    for(;;)
    {
        int n;
        cin>>n;
        if(n ==1 )
        {
            int c;
            cin>>c;
            add_node(root,c);
        }
        else
            print(root);
    }

    return 0;
}