#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    for(int test = 0; test < T; test++)
    {
        long long int N;
        cin >> N;
        int sum = 0, i;
        
        if(N == 0){
            sum = 6;
        }else{
                while(N != 0)
            {
                i = N % 10;
                N /= 10;
                sum += arr[i];
            }
        }
        
        
        long long int output = 0;
        if (sum % 2 == 0){
            for(int j = 0; j < sum/2; j++)
            {
                output += pow(10, j);
            }
            
        }else{
            int expo = sum/2 -1;
            output = 7 * pow(10, expo);
            for(int j = expo - 1; j >= 0; j--){
                output += pow(10, j);
            }
        }
        
        cout << output << endl;
    }
    
    
    return 0;
}
