#include <bits/stdc++.h> 
using namespace std; 
int main() 
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    int test;
    cin >> test;
    for(int t = 0; t < test; t++)
    {
        int flag = 1;
        long int N;
        cin >> N;
        
        long long int a[N];
        for(long int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        if(N%2 == 1){
            cout << "NO" << endl;
            continue;
        }
        long int mid = N / 2;
        for(long int i = 0; i < mid; i++)
        {
            if(a[i] == -1 && a[mid + i] == -1)
            {
                flag = 0; // NO
                break;
            }else if(a[i] == -1 || a[mid + i] == -1)
            {
                if(a[i] == -1){
                    a[i] = a[mid + i];
                }else a[mid + i] = a[i];
            }else if(a[i] != a[mid + i])
            {
                flag = 0; // NO 
                break;
            }
        }
        if(flag == 1)
        {
            cout << "YES" << endl;
            for(long int i = 0; i < N; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }else cout << "NO" << endl;
        
    }
    
    return 0; 
} 
