#include<bits/stdc++.h>
using namespace std;

multimap <int, int> mmap;


int main()
{

mmap.insert( pair <int, int> (1, 60) );
mmap.insert( pair <int, int> (2, 60) );
mmap.insert( pair <int, int> (3, 60) );
mmap.insert( pair <int, int> (6, 50) );
mmap.insert( pair <int, int> (6, 10) );

    cout << "\n\nsize:: = " << mmap.size();
  return 0;
}