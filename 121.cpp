// easy
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int maxProfit(vector<int>& prices) {
	stack<int> s;
	int ans = 0;
	int bottom = 0;
	if (prices.size() == 0) return 0;
	else s.push(prices[0]);
	bottom = s.top();
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] > s.top())
			s.push(prices[i]);
		else if (prices[i] < s.top()) {
			while ( !s.empty() && prices[i] < s.top()) {
				ans = max(ans, s.top()-bottom); 
				s.pop(); 
			}
			if (s.empty())
				bottom = prices[i];
			s.push(prices[i]);
		}
//	        cout << "top : " << s.top() << "bottom : " << bottom << endl;
	}
	ans = max(ans, s.top()-bottom);
	return ans; 
}

int main() {
	int a[6] = {7,1,5,3,6,4};
	std::vector<int> v(a,a+6);
	cout << maxProfit(v) << endl;
	return 0;
}