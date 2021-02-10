#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    set<int> s;
    for (int i = 0; i < nums.size(); ++i)
    {
        s.insert(nums[i]);
    }
    for (int i = 1; i <= nums.size() + 1; ++i)
    {
        if(!s.count(i)) return i;
    }
    return 1;
}

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < (size_t)nums.size(); ++i) {
        while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) return (i + 1);
    }
    return nums.size() + 1;
}

int main() {
    int x[4] = {3, 4, -1, 1};
    vector<int> num(x, x + 4);
    cout << firstMissingPositive(num) << endl; 
    return 0;
}