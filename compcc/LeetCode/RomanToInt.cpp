#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});
        int val = 0;
        for (int i = 0; i < s.length(); i++) {
            if ( (i+1 < s.length()) && (m[s[i]] < m[s[i+1]]) ) {
                val -= m[s[i]];
                continue;
            }
            val += m[s[i]];
        }

        return val;
    }
};