// hard
#include<bits/stdc++.h>
using namespace std;

int countWidth(int l, int i, int r) {
	return r - l - 1;
}

int largestRectangleArea(vector<int>& heights) {
	stack<int> s;
	if (heights.size() == 0) return 0;
	int ans = 0, l, r;
	heights.push_back(0);
	heights.insert(heights.begin(),0);
	for (int i = 0; i < heights.size(); ++i) {
		if (!s.empty() && heights[i] < heights[s.top()]) {
			while (!s.empty() && heights[i] < heights[s.top()]) { // 严格小
				int now = s.top();
				s.pop();
				l = s.top();
				r = i;
				while(heights[l] == heights[now])
				{
					s.pop();
					l = s.top();
				}
				cout << "现在 : " << l << ' ' << now << ' ' << r << endl;
				cout << countWidth(l, now, r) * heights[now] << endl;
				ans = max (ans, countWidth(l, now, r) * heights[now]);
			}
			s.push(i);
		}		
		else if (s.empty() || heights[i] >= heights[s.top()]) {
			s.push(i); // 压栈
		}
	}
	return ans;
}

int main() {
	int h[7] = {0,1,0,2,0,3,0};
	vector<int> v(h, h + 7);
	cout << largestRectangleArea(v) << endl;
	return 0;
}