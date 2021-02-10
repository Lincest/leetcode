#include<bits/stdc++.h>
using namespace std;

int minSumOfLengths(vector<int>& arr, int target) {
	const int maxn = 0x3f3f3f3f;
	int n = arr.size();
	int sum = 0;
	int ans = maxn;
	vector<int> dp(n, maxn);
	map<int, int> mp;
	mp[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		
		if(i)
			dp[i] = dp[i - 1];
		if (mp.count(sum - target)) { 
			int cur = i - mp[sum - target];
			int bfindex = mp[sum - target];
			if (bfindex >= 0 && dp[bfindex] < maxn) {
				ans = min(ans, cur + dp[bfindex]);
			} 
			if(i)
				dp[i] = min(dp[i-1], cur);
			else
				dp[i] = min(cur, maxn);
		}
		mp[sum] = i;
	}
	return ans == maxn ? -1 : ans;
}

int main() {
	int a[5] = {3,2,2,4,3};
	std::vector<int> v(a,a+5);
	cout << minSumOfLengths(v,3);
    return 0;
}
