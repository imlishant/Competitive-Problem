#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define for0(i,n) for(int i=0;i<n;++i)
#define for1(i,n) for(int i=1;i<=n;++i)
#define ford(i,n) for(int i=n-1;i>=0;--i)
#define forg(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
#define N 1000001
#define fast ios_base::sync_with_stdio(false),cin.tie(0);
#define deb(x) cout << #x << " " << x << endl;

// template<typename... T>
// void read(T&... args) {
//     ((cin >> args), ...);
// }

// template<typename... T>
// void write(T... args) {
//     ((cout << args << " "), ...);
// }


class Trie 
{
public:
    bool isLeaf;
    unordered_map<char, Trie*> character;
    Trie() {
        this->isLeaf = false;
    }
    void insert(string);
    bool search(string);
    bool haveChildren();
    bool removal();
};

void Trie::insert(string str) {
    Trie *curr = this;
    for (char ch : str) {
        if (curr->character.find(ch) == curr->character.end()) {
            curr->character[ch] = new Trie();
        }

        curr = curr->character[ch];
    }

    curr->isLeaf = true;
}

bool Trie::search(string str) {

    if (this == nullptr) {
        return false;
    }

    Trie *curr = this;

    for (char ch : str) {
        curr = curr->character[ch];
        if (curr == nullptr) {
            return false;
        }
    }
    return curr->isLeaf;
}

int main()
{
    Trie *head = new Trie();
    // Trie *head = nullptr;
    cout << "trie:\n";
    head->insert("hello");
    cout << "search hello: " << head->search("hello") << endl;


    return 0;
}