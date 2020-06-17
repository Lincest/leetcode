class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size());
        stack<int> s;
        for (int i = 0; i < T.size(); ++i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};