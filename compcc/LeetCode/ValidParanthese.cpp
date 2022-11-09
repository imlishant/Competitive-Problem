#include <bits/stdc++.h>
using namespace std;


/*
class Solution {
public:
    bool isValid (string s) {
        stack<char> st;
        for (char c : s) {
            if ( c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if ( st.empty() == false && 
             ( ( c == ')' && st.top() == '(' ) 
            || ( c == ']' && st.top() == '[' )
            || ( c == '}' && st.top() == '{' ) )
            ) {
                st.pop();
            } else {
                return false;
            }
        }

        if (st.empty() == false) {
            return false;
        }
        return true;
    }
};

*/

class Solution {
public:
    bool match(char a, char b) {
        return ( (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}') );
    }

    bool isValid (string s) {
        stack<char> st;
        for (char c : s) {
            if ( c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (st.empty() == true) {
                return false;
            } else if ( match(st.top(), c) == true ) {
                st.pop();
            } else {
                return false;
            }
        }

        return (st.empty() == true);
    }
};