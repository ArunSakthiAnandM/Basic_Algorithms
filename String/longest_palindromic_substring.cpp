 #include <bits/stdc++.h>
 using namespace std;

string longestPalindrome(const string& s) {
	int n = s.size();
	if (n == 0) return "";
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	int start = 0, maxLen = 1;
	for (int i = 0; i < n; i++) dp[i][i] = true;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			start = i;
			maxLen = 2;
		}
	}
	for (int len = 3; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
				start = i;
				maxLen = len;
			}
		}
	}
	return s.substr(start, maxLen);
}

int main() {
	string s = "babad";
	cout << "Longest Palindromic Substring: " << longestPalindrome(s) << "\n";
	return 0;
}
