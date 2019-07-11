#include <bits/stdc++.h>
using namespace std;


int kadane(int arr[], int n){
    int max_global = arr[0];
    int max_current = arr[0];
    for(int i = 1; i < n; i++){
        max_current = max(arr[i], max_current + arr[i]);
        if(max_current > max_global)
            max_global = max_current;
    }
    return max_global;
}

int main(){
    int arr[] = {1, -3, 2, 1, -1, 4, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum_array = kadane(arr, n);
    cout << "max contiguous sum array : " << max_sum_array << "\n";
    return 0;
}