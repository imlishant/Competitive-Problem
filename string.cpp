#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char ch, s[100], sen[100];
    int c=0, i=0;

    scanf("%c", &ch);
    scanf("\n%s",s);
    scanf("\n%[^\n]", sen);

    if( (ch!='\0') && (s[c]!='\0') && (sen[i]!='\0') )
    {
      printf("%c", ch);
      printf("\n%s",s);
      c++;
      printf("\n%s", sen);
      i++;


    }
    else
    {
      return 1;
    }
    
    return 0;
    
}
