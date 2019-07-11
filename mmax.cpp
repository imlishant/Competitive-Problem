#include <bits/stdc++.h>
using namespace std;

#define ld long long int

ld mod(string k, ld n){
    ld ans = 0; 
    for(int i = 0; i < k.length(); i++){
        ans = (ans * 10 + (k[i] - '0')) % n;
    }
    return ans;
}

ld solve(string k, ld n){
    // in long long int range
    // ld num = k % n;
    ld num = mod(k, n);
    if(2 * num == n){
        return 2*num-1;
    }else if(2 * num < n){
        return 2*num;
    }else return 2*(n-num);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ld test;
    ld N;
    string k;
    cin >> test;
    while(test--){
        cin >> N;
        cin >> k;
        ld result = solve(k, N);
        cout << result << "\n";
    }
    return 0;
}