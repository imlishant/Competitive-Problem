#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int len = nums.size();
        for (int n : nums) {
            m[n]++;
        }
        int curr = 0;
        for (auto it : m) {
            if ( (it.second << 1) >= len) {
                curr = it.first;
                break;
            }
        }
        return curr;
    }
    */

    /*
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int len = (int) nums.size();
        int counter = 0;
        for (int n : nums) {
            if (!counter) {
                major = n;
            }
            counter += (n == major ? 1 : -1);
        }
        return major;
    }
    */

    /*
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int len = (int) nums.size();
        int counter = 0;
        for (int n : nums) {
            if (!counter) {
                major = n;
            }
            counter += (n == major ? 1 : -1);
        }
        return major;
    }
    */

    int majorityElement(vector<int>& nums) {
        int major = 0;
        int mask = 1;
        for (unsigned int i = 0; i < 32; i++, mask <<= 1) {
            int bits = 0;
            //counting no. of numbers whose bit is ON with mask;
            for (int n : nums) {
                if (n & mask) {
                    bits++;
                }
            }
            if (bits > (int) nums.size()>>1) {
                major |= mask;
            }
        }

        return major;
    }

};

int main() {
    vector<int> num = {2,2,1,1,1,2,2};
    Solution obj;
    int ans = obj.majorityElement(num);
    cout << "ans : " << ans << endl;
}