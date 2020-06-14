#include<bits/stdc++.h>
using namespace std;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> iMap;
        for(int i = 0; i < arr.size(); ++i)
        {
            iMap[arr[i]]++;
        }    
        vector<pair<int, int>> vtMap;
    for (auto it = iMap.begin(); it != iMap.end(); it++)
        vtMap.push_back(make_pair(it->first, it->second));

    sort(vtMap.begin(), vtMap.end(), 
        [](const pair<int, int> &x, const pair<int, int> &y) -> int {
        return x.second < y.second;
    });

        for (vector<pair<int, int> >::iterator it=vtMap.begin();it!=vtMap.end();++it) {
            if (it->second >= k) {
                it->second-=k;
                break;
            } 
            else {
                k-=it->second;
                it->second = 0;
            }
        }
        int ans = 0;
        for (vector<pair<int, int> >::iterator it=vtMap.begin();it!=vtMap.end();++it) {
        	cout << it->second;
            if (it->second!=0)ans++; 
        }
        return ans;    
}




int main() {
	vector<int> arr(3);
	arr.push_back(1);
	arr.push_back(2);
	cout << findLeastNumOfUniqueInts(arr,1);
    return 0;
}