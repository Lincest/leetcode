#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int climbStairs(int n) {
        return (int)((double)1/(sqrt(5)) * (pow((1 + sqrt(5))/2, n) - pow((1 - sqrt(5))/2, n)));
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout << climbStairs(3);
    climbStairs(4);
    climbStairs(5);
    cout << climbStairs(6);
	//cout << climbStairs(3);
	return 0;
}