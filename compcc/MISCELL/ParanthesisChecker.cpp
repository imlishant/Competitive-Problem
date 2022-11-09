// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        
        for (char c : x) {
            if ((c == '(') || (c == '[') || (c == '{')) {
                stk.push(c);
            } else if ((stk.empty() == false) &&
                ((stk.top() == '(' && c == ')')
                || (stk.top() == '[' && c == ']')
                || (stk.top() == '{' && c == '}'))
                ) {
                
                stk.pop();
            } else if ((c == ')') || (c == ']') || (c == '}'))
            {
                return false;
            }
        }
        
        if (stk.empty() == true){
            return true;
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends