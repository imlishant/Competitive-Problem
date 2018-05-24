#include <stdio.h>
 
const int MAX = 3;
 
int main () {

   int  var[] = {10, 100, 200};
   int i, *ptr[MAX];
 
   for ( i = 0; i < MAX; i++) {
      ptr[i] = &var[i]; /* assign the address of integer. */
   }
   
   for ( i = 0; i < MAX; i++) {
      printf("Value of var[%d] = %d\n", i, *ptr[i] );
      printf("&var[%d] = %x\n", i, &var[i]);
      printf("ptr[%d]  = %x\n", i, ptr[i]);
      printf("&ptr[%d] = %x\n", i, &ptr[i]);
   }
   
   printf("size of var = %d\n", sizeof(var));
   printf("size of ptr = %d\n", sizeof(ptr));
   
   return 0;
}
