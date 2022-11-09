#include <bits/stdc++.h>

using namespace std;

/*
#include<bits/stdc++.h>
using namespace std;

string getres(string s){
    int i=s.length()-1;
    string res="";
    while(i>=0){
        if(i%2!=0){
            if(s.substr(0,(i+1)/2)==s.substr((i+1)/2,(i+1)/2)){
                res="*"+res;
                i=i/2;
                continue;
            }else
                res=s[i]+res;
        }
        else
            res=s[i]+res;
        i--;

    }

    return res;
}

int main() {
    std::cout <<getres("ABAB");
    cout<<endl;
    std::cout <<getres("ABCDABCE");
    cout<<endl;
    std::cout <<getres("ABCABCE");
    cout<<endl;
    std::cout <<getres("AAA");
    cout<<endl;
    std::cout <<getres("BBB");
    cout<<endl;
    std::cout <<getres("AAAAAA");
    return 0;

}
*/

/*
#include <bits/stdc++.h>

using namespace std;

void prefixarray(string s, int m, int lps[]){
int j = 0, i=1;
lps[0] = 0;

while(i < m){
    if(s[i] == s[j]){
        j++;
        lps[i] = j;
        
        i++;
    }else{
        if(j != 0 ){
            j = lps[j-1];
            
        }else{
           
            lps[i] = 0;
            i++;
        }
    }
}

cout<<endl;
}

int main() {

// string s = "ABACABACD";
// string s = "ABCABCE";
// string s = "AAAAAA";
// string s = "ABAB";
string s = "BBB";

int lps[s.length()];

prefixarray(s,s.length(),lps);

string ans = "";

for(int i=0; i<s.length();i++){
    if(lps[i] == 0) ans+=s[i];
    else{
        int l = 0,k=i;
        
        while(k<s.length() && lps[k]>0){
            l++;
            k++;
        }
        
       
        if(l == i){
            ans += '*';
            i = k-1;
        }else{
            ans+=s[i];
        }
    }
}
cout<<ans<<endl;
}
*/

int main() {
    int i = 7;
    cout << "ans::= " << (i & (-i)) << endl;
}