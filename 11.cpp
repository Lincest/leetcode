#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        while (l < r) {
            ans = max(min(height[l], height[r]) * (r - l), ans);
            height[l] < height[r] ? l++ : r--;          
        }
        return ans;
    }
};

int main() {
	cout << "hello";
    return 0;
}