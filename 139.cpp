#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;

bool wordBreak(string s, vector<string>& wordDict) {
	for (auto i : wordDict) 
		mp[i] = true;
	int n = s.size();
	vector<bool> dp(n+1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j) {
			dp[i] = dp[j] && mp[s.substr(j, i-j)];
			if (dp[i]) break;
		}
	return dp[n];
}

int main() {
	string s = "leetcode";
	vector<string> vs = {"leet","code"};
	cout << wordBreak(s, vs) << endl;
    return 0;
}