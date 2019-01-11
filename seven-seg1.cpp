#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10]={6,2,5,5,4,5,6,3,7,6},t,c,i,j;
    cin>>t;
    string n;
    for(i=0; i<t; i++){
        c=0;
        cin>>n;
        for (char ch : n) {
            c += a[(int) (ch - '0')];
        }
        if(c%2==0){
            for(j=1; j<=c/2; j++)
                cout<<"1";
        }else{
            cout<<"7";
            for(j=1; j<=(c-1)/2-1; j++)
                cout<<"1";
        }
        cout<<endl;
    }
    return 0;
}
