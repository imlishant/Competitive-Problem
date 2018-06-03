#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    int** arr = new int *[n];
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr[i] = new int [k];
        for(int j = 0; j < k; j++){
            
            cin >> arr[i][j];
        }
    }
    
    for(int m = 0; m < q; m++){
        int i, j;
        cin >> i >> j;
        cout << arr[i][j] << endl;
    }
    return 0;
}
