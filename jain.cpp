#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    
    ll test, n;
    map<char, int> m;
    m['a'] = 1;
    m['e'] = 2;
    m['i'] = 4;
    m['o'] = 8;
    m['u'] = 16;
    
    cin >> test;
    while(test--){
        cin >> n;
        string s[n];
        set<char> st;
        std::vector<ll> arr(32);
        for(ll i = 0; i < n; i++){
            cin >> s[i];
            ll sum = 0;
            st.insert(s[i].begin(), s[i].end());
            set<char>::iterator it;
            for(it=st.begin(); it!=st.end(); it++){
                sum+=m[*it];
            }
            arr[sum]++;
            st.clear();
        }
        ll answer = 0;
        for(ll i = 1; i < 31; i++){
            for(ll j = i+1; j <= 31; j++){
                if((int)(i|j) == 31)
                    answer += (arr[i]*arr[j]);
                cerr << answer << " " << i << " " << j << "\n";
            }
        }
        
        answer += (arr[31]*(arr[31] - 1))/2;
        cout << answer << "\n";
        for(ll i = 1; i < 32; i++){
            cerr << arr[i] << " ";
        }
        
    }
    
	return 0;
}
