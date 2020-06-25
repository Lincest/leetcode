#include<bits/stdc++.h>
using namespace std;


#define debug(x) \
(void)(cerr << "L" << __LINE__\
			<< " : " << #x << " = " \
			<< (x) << endl )

unordered_map<int, int> mark; // 标记
vector<int> tmp;
vector<vector<int> > ans; // annswer
int sizen;

void dfs(int index, vector<int>& nums) {
	if (index == sizen) {
		ans.push_back(tmp);
		return;
	}

	for (int i = 0; i < sizen; ++i)
	{
		if (!mark[i]) {
			mark[i] = 1;	// 标记
			tmp[i] = nums[index]; // 加入路径
			dfs(index + 1, nums); // 下一层dfs
			mark[i] = 0;	// 解除标记, 回溯
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	sizen = nums.size();
	for (int i = 0; i < sizen; ++i)
	{
		tmp.push_back(0);
	}
	dfs(0, nums);
	return ans;
}



int main() {
	int x[3] = {1, 2, 3};
	vector<int> num(x, x + 3);
	vector<vector<int> > a = permute(num);
	for (auto i : a) {
		for (auto j : i) 
			cout << j << ' ' ;
		cout << endl;
	}
    return 0;
}