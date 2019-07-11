#include <bits/stdc++.h>
using namespace std;

#define lli long long int

long double mean(vector<long double>& v, lli n){
    long double sum = 0.0;
    for(lli i = 0; i < v.size(); i++){
        sum+=v[i];
    }
    return (sum/n);
}

int main(){
    lli test, N;
    cin >> test;
    while(test--){
        cin >> N;
        vector<long double> v(N);
        for(lli i = 0; i < N; i++){
            cin >> v[i];
        }
        long double num = mean(v, N);
        lli flag = -1;
        for(lli i = 0; i < N; i++){
            if(num == v[i]){
                flag = i;
                break;
            }
        }
        if(flag != -1)
            cout << flag + 1 << "\n";
        else 
            cout << "Impossible" << "\n";
    }
    return 0;
}