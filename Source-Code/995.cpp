class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> q;
        int N = A.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            while (!q.empty() && q.front() + K <= i) {
                q.pop();
            }
            if (q.size() % 2 == A[i]) {
                if (i + K > N) return -1;
                ++ans;
                q.push(i);
            }
        }
        return ans;
    }
};