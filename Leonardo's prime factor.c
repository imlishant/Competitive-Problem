#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int q;
    long double N;
    scanf("%d", &q);
    int a[18] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
    int i, j;
    for(i = 0; i < q; i++){
        scanf("%Lf", &N);
        long double n = 1;
        int counter = 0;
        for(j = 0; j < 18; j++){
            if(n <= N){
                n = n*a[j];
                ++counter;
            }
           
        }
        printf("%d\n", counter - 1);
    }
    return 0;
}
