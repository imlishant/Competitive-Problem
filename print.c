    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
        char cha = 'F';
        int ca = cha ;
        
        char chb = 'P';
        int cb = chb;
        for(int c = ca; c <= cb; c++)
            printf("%d\n", c);
        
        return EXIT_SUCCESS ;
    }
