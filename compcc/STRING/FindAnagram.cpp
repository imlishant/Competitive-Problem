// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> ans;
        vector<int> hash(26,0);
        vector<int> phash(26,0);
        // unordered_map<int, int> hash;
        // unordered_map<int, int> phash;
        int window = p.size();
        int len = s.size();
        if(len<window)
            return ans;
        int left = 0,right = 0;
        while(right<window)
        {
            phash[p[right]-'a'] +=1;
            hash[s[right++]-'a'] +=1;
        }
        right -=1;
        while(right<len)
        {
            cout << "inside while: right and len " << right << " :: " << len << endl;
            if(phash == hash) {
                ans.push_back(left);
                cout << " left: " << left << endl;
            }
            right+=1;
            if(right!=len) {
                hash[s[right]-'a'] +=1;
            }
            hash[s[left]-'a'] -=1;
            left+=1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int t = 1;
    // cin >> t;
    while (t--) 
    {
        string s = "aabacddaabaaba";
        // cin >> s;
        string p = "aaba";
        // cin >> p;
        Solution obj;
        vector<int> sol = obj.findAnagrams(s, p);
        for (int i : sol) {
            cout << i << " ";
        }
    }
    return 0;
}  // } Driver Code Ends