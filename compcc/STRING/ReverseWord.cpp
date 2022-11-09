// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    vector<string> vstr;
    stack<string> stk;
    void simple_tokenizer(string s)
    {
        stringstream ss(s);
        string word;
        while (getline(ss, word, '.')) {
            vstr.push_back(word);
            stk.push(word);
        }
    }
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        simple_tokenizer(S);
        string ans = "";
        while (stk.empty() == false) {
            ans += stk.top();
            stk.pop();
            if (stk.empty() == false) {
                ans += ".";
            }
        }
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        getline(cin, s);
        // cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends