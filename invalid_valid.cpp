#include<bits/stdc++.h>
using namespace std;

int summ(string s, int x)
{
    stringstream sso;
    int sum = 0, temp;
    sso << s[x];
    sso >> temp;
    sum += temp;
    sso.clear(); // to clear value stored in sso.
    // if(!(ss << something)){ print "INVALID" };
    // use above stmnt to see evrythng is ok.
    sso << s[x + 1];
    sso >> temp;
    sum += temp;
    int bin = sum % 2; // passing 1 for odd and 0 for even
    return bin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool str, num;
    if((s[2] == 'A' || s[2] == 'E' || s[2] == 'I' || s[2] == 'O' || s[2] == 'U' || s[2] == 'Y')){
        str = true;
    }else str = false;
    
    if(summ(s,0) || summ(s,3) || summ(s,4) || summ(s,7)){
        num = true;
    }else num = false;
    
    if(str || num){
        cout << "invalid" << endl;
    }else cout << "valid" << endl;
}
