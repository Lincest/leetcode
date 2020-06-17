#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
    vector<vector<int> > threeSum(vector<int>& nums) {
	 vector< vector<int> > ans;
	 vector<int> tmp(3);
	 sort(nums.begin(), nums.end());
	 for (unsigned int i = 0; i < nums.size(); ++i)
	 {	
	 	if(i != 0)
	 		while(nums[i]==nums[i-1] && i < nums.size()-1)++i;
	 	if(nums[i] > 0 || i>=nums.size()-2) break;
	 	int a = nums[i];
	 	int l = i+1, r = nums.size() - 1;
	 	while(l < r) {
	 		//cout << a << "--" << nums[l] << "--" << nums[r] << endl;
		 	if(a + nums[l] + nums[r] == 0) {
		 		tmp[0] = a, tmp[1] = nums[l], tmp[2] = nums[r];
		 		l++;r--;
		 		while(nums[l]==nums[l-1] && l<r)l++;
		 		while(nums[r]==nums[r+1] && l<r)r--;
		 		ans.push_back(tmp);
	 		}	
	 		else{
	 			if(nums[l] + a < -nums[r])
		 			l++;
			 	else
			 		r--;
	 		}
	 	}

	 }
	 return ans;
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    int a[6] = {3, 0, -2, -1, 1, 2};
	vector<int> num(a, a+6);
    vector< vector<int> > s = threeSum(num);
    for(unsigned int i = 0; i < s.size(); ++i) {
    	for(int j = 0; j < 3; ++j) {
    		cout << s[i][j] << " ";
    	}
    	cout << endl;
    }
	return 0;
}