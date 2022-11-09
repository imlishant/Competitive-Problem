#include <bits/stdc++.h>
using namespace std;


class MinStack {
    stack<int> st;
    stack<int> aux;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            aux.push(val);
        } else if (val > aux.top()) {
            st.push(val);
        } else {
            st.push(val);
            aux.push(val);
        }

        /*
        when val < min => 2*val < val + min => 2*val - min < val;
        push (2*val - min) && assign (min = val);
        */

    }
    
    void pop() {
        if (st.empty()) {
            cout << "Underflow!";
            return;
        } else if (st.top() == aux.top()) {
            aux.pop();
            st.pop();
        } else {
            st.pop();
        }

        /*
        when top < min => min to be updated with the new min
        so assign new min = (2*min-top) && pop();
        */
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return aux.top();
    }
};