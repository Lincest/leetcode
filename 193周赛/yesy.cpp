#include<bits/stdc++.h>
using namespace std;

bool can(int mid, vector<int>& b, int m, int k) {
	int cnt = 0;
	for (int i = 0; i < b.size(); ++i)
	{			
		if(b[i] <= mid)
			cnt++;
		else
			cnt = 0;
		if(cnt==k){
			cnt = 0;
			m--;
		}
		if(m==0)
			return true;
	}
	return false;
}


int minDays(vector<int>& bloomDay, int m, int k) {
	if (k*m > bloomDay.size())
		return -1;
	int l = 0;
	int r = 1e9;
	while (l < r) {
		cout << l << ' ' << r << endl;
		//int mid = (l + r) >> 1;
		int mid = l + ((r - l) >> 1);
		if (can(mid, bloomDay, m, k))
			r = mid;
		else 
			l = mid + 1;
	}
	return l;
}


int main() {
	int a[5] = {1e9,1e9,1e9,1e9,1e9};
	std::vector<int> v(a,a+5);
	cout << minDays(v,3,1);
    return 0;
}