///not complete.Please skip this








#include<bits/stdc++.h>
#include <numeric>
using namespace std;
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define forc(c,n) for(int i=c;i<n;i++)
#define PI (acos(-1.0))
#define pb push_back
#define vi vector<long long >
#define eps 1e-12
#define all(a) sort(a.begin(),a.end());
#define torad(x) ((x) * ((2*acos(0))/180.0))
#define todeg(x) ((x) * (180.0/(2*acos(0))))

/* //functions template paste here*/
///_______________________MAMUN___________________________


int main()
{
///infix to postfix
    stack<char>s;
    vector<char>p;
    s.push('(');
    string q;
    cin>>q;
    q+= ')';
    for(int i =0; i<q.size(); i++)
    {
        if(q[i] == '+' || q[i] == '-' || q[i] == '*' || q[i] == '/'|| q[i] == '(' || q[i] == '|'|| q[i] == ')'   )
        {
            if(q[i] == '+' || q[i] == '-' )
            {
                while (s.top() != '(' )
                {
                    p.pb(s.top());
                    s.pop();
                }
                s.push(q[i]);
            }
            else if(q[i] == '*' || q[i] == '/')
            {
                while (s.top() != '(' && s.top() != '|' && s.top() != '+' && s.top() != '-' && s.top() != '*')
                {
                    p.pb(s.top());
                    s.pop();
                }
                s.push(q[i]);
            }
            else if(q[i] == '|')
            {
                while (s.top() == '|' && s.top() != '(')
                {
                    p.pb(s.top());
                    s.pop();
                }
                s.push(q[i]);
            }
            else if( q[i] == ')' )
            {
                while(s.top() != '(')
                {
                    p.pb(s.top());
                    s.pop();
                }
                s.pop();
            }
            else
                s.push(q[i]);
        }

        else
            p.pb(q[i]);
    }
    for(auto x: p)
        cout<<x<<" ";
    cout<<endl;
    
    ///postfix to solution
    stack < int > s2;
    int t1,t2;
    for(int i =0; i<p.size(); i++)
    {
        if(p[i] == '+')
        {
            t1 = s2.top() ;
            s2.pop();
            t2 = s2.top() ;
            s2.pop();

            s2.push(t1+t2);
        }
        else if(p[i] == '-')
        {
            t1 = s2.top() ;
            s2.pop();
            t2 = s2.top() ;
            s2.pop();

            s2.push(t2-t1);
        }
        else if(p[i] == '/')
        {
            t1 = s2.top() ;
            s2.pop();
            t2 = s2.top() ;
            s2.pop();

            s2.push(t2/t1);
        }
        else if(p[i] == '*')
        {
            t1 = s2.top() ;
            s2.pop();
            t2 = s2.top() ;
            s2.pop();

            s2.push(t2*t1);
        }
        else if(p[i] == '|')
        {
            t1 = s2.top() ;
            s2.pop();
            t2 = s2.top() ;
            s2.pop();

            s2.push(pow(t2,t1));
        }
        else
        {
            t1 = p[i] - 48;
            s2.push(t1);
        }
    }
    cout<<s2.top()<<endl;
}
