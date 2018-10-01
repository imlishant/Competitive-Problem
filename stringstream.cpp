#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	
    char ch;
    int temp;
    vector<int> v;
    stringstream sso(str);
    while(sso >> temp)
    {
        v.push_back(temp);
        sso >> ch;
    }
    return v;
    
}

int main() {
    string str;  // = {23,5,45};
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    // output:
    // 23
    // 5
    // 45
    
    return 0;
}
