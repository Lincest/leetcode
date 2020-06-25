#include<bits/stdc++.h>
using namespace std;
#define debug(x) \
(void)(cerr << "L" << __LINE__\
			<< " : " << #x << " = " \
			<< (x) << endl )

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int absans = 0x3f3f3f3f;
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		int l = i + 1;
		int r = nums.size() - 1;
		while (l < r) {
			int tmpsum = nums[i] + nums[l] + nums[r];
			int tmpabs = abs(tmpsum - target);
			if(tmpabs < absans){
				sum = tmpsum;
				absans = tmpabs;
			}
			// debug(sum);
			// debug(absans);
			// debug(nums[i]);
			// debug(nums[l]);
			// debug(nums[r]);
			// cout << " ---------- " << endl;
			if (tmpabs == 0) return sum;
			else if (tmpsum < target) l++;
			else if (tmpsum > target) r--;
		}
	}
	return sum;
}

int main() {
	int n[8] = {1,2,4,8,16,32,64,128};
	vector<int> num(n, n+8);
	int target = 82;
	cout << threeSumClosest(num, target);
    return 0;
}
