#include <bits/stdc++.h>
using namespace std;

/*
array element only 1 and 2. 
1 <= test <= 5;
1 <= N <= 2*10^6;
find no. of contiguous subseq. of sum == s;
0 <= s <= 2*N;
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for(int t = 0; t < test; t++)
    {
        long int N;
        cin >> N;
        long int sum[N] = {0}, s[2*N+1] = {0};
        int a[N];
        for(long int n = 0; n < N; n++)
        {
            cin >> a[n];
            
            if(n == 0){
                sum[n] = a[n];
            }else{
                sum[n] = sum[n-1] + a[n];
            }
            
            for(long int i = 0; i <= n; i++)
            {
                if(i == 0)
                {
                    s[sum[n]]++;
                }else{
                    s[sum[n] - sum[i-1]]++;
                }
            }
        }
        long int count = 0;
        for(long int j = 0; j < 2*N + 1; j++)
        {
            if(s[j] == 0){
                count++;
            }
        }
        cout << 2*N + 1 - count << "\n";
    }
    
    
    return 0;
}
