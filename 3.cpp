#include<bits/stdc++.h>
using namespace std;

void reIO() {
#ifndef ROCCOSHI
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

int lengthOfLongestSubstring(string s) {
	int ans = 0;
	int cnt = 0;
	unordered_map<char, int> mp;
	int r = 0;
	int l = 0;
	while (r < s.size()) {
		if (!mp.count(s[r]) || mp[s[r]] < l) {
			mp[s[r]] = r;
			cnt++;
		}
		else {
			cnt = r - mp[s[r]];
			l = mp[s[r]] + 1;
			mp[s[r]] = r; 
		}
		ans = max(ans, cnt);
		r++;
	}
	return ans;
}

int main() {

	string s;
	cin >> s;
	cout << lengthOfLongestSubstring(s) << endl;

	return 0;
}