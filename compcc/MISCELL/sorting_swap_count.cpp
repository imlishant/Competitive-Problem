#include <bits/stdc++.h>

int sort(int array[], int count);
int main(void){

    int numArray[100] = { 2, 5, 1, 3, 4 } ;
    
    int counter = 5;
    int i;
/*
    printf("Enter array length \n");
    scanf("%d", &counter); 

    int i;
    for (i = 0; i < counter; i++){
        printf("%d. Enter a numner: ", i);
        scanf("%d", &numArray[i]);
    }
*/

    // How many times would you like to sort this array?
    // You only need one sort
    /*
    i = 0;
    while(i < counter){
        sort(numArray, counter);
        i++;
    }
    */

    int totalSwaps = sort(numArray, counter);

    if (totalSwaps == 0) {
        printf("The array is already in sorted order\n");
        return 0;
    }

    printf("Swaps: %d\n", totalSwaps); 

    for (i = 0; i < counter; i++) {
        printf("Values: %d\n", numArray[i]); 
    }
    return 0;
}



int sort(int array[], int count){

    int i, j, temp;
    int swaps = 0;
    for(i = 0; i < count-1; ++i){

        for(j=0; j<count-1-i; ++j){

            if(array[j] > array[j+1]){

                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                swaps++;
            }
        }
    }

    return swaps;
}