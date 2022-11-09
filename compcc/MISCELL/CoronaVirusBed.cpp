
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 1000001

int totalWays(int n, string str)
{
	vector<int> IdxOf1s;

	int cntWays = 1;

	for (int i = 0; i < n; i++) {

		if (str[i] == '1') {
			IdxOf1s.push_back(i);
		}
	}

	int M = IdxOf1s.size();

	if (M == 0 or M % 2) {

		return -1;
	}

	for (int i = 2; i < M; i += 2) {

		cntWays = ( (cntWays%mod) * ( (IdxOf1s[i])	- (IdxOf1s[i - 1]) ) % mod );
	}

	return cntWays%mod;
}

int main()
{
	string str = "110010001000010010011";

	int n = str.length();

	cout << totalWays(n, str);

	return 0;
}
