#include<bits/stdc++.h>
using namespace std;

void reIO() {
#ifndef ROCCOSHI
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

string check(string s) { 
	string k = "";
	for (int i = 0; i < s.size(); ++i) {
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			k += s[i];
		}
		else if(s[i] >= 'A' && s[i] <= 'Z') {
			k += s[i] - 'A' + 'a';
		}
	}
	return k;
}


bool isPalindrome(string s) {
	string k = check(s);
	int i = 0;
	int j = k.size()-1;
	bool flag = true;
	while(i < j) {
		flag = (k[i++] == k[j--]);
		if(flag == false) return flag;
	}
	return flag;
}

int main() {
	reIO();
	string s = ",; W;:GlG:;l ;,";
	cout << isPalindrome(s);
    return 0;
}