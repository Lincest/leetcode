#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
	if(len1 + len2 != len3)
		return false;
	vector< vector<bool> > dp(len1+1, vector<bool>(len2+1, false));	// s1的前i个和s2的前j个是否可以成为s3的前i+j个
	dp[0][0] = true;
	for (int i = 1; i <= len1; ++i) {
		dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
	}
	for (int j = 1; j <= len2; ++j) {
		dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
				dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
		}
	}
	return dp[len1][len2];
}


int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t; 
	cin >> t;
	while(t--){
		string s1, s2, s3;
		cin>>s1>>s2>>s3;
		cout<<isInterleave(s1,s2,s3)<<endl;
	}
	return 0;
}