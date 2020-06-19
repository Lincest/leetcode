// 列条件, 二分搜索

#include<bits/stdc++.h>
using namespace std;

void reIO() {
#ifndef ROCCOSHI
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

int search(vector<int>& nums, int target) {
	int l = 0; 
	int r = nums.size() - 1;
	int mid; 
	while(l < r) {
		mid = l + ((r - l) >> 1);
		if (nums[l] <= nums[mid] && target <= nums[mid] && nums[l] <= target) 
			r = mid;
		else if (nums[l] > nums[mid] && (target >= nums[l] || target <= nums[mid]))
			r = mid;
		else
			l = mid + 1;
	}
	return l == r && nums[l] == target ? l : -1;
}

int main() {
	reIO();
	int nums[7] = {4,5,6,7,0,1,2};
	vector<int> v(nums,nums + 7);
	cout << search(v, 0);
    return 0;
}