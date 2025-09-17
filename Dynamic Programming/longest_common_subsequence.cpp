 #include <bits/stdc++.h>
 using namespace std;


int lcs_iterative(const string& X, const string& Y) {
	int m = X.size(), n = Y.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m][n];
}

int lcs_recursive(const string& X, const string& Y, int m, int n) {
	if (m == 0 || n == 0) return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcs_recursive(X, Y, m - 1, n - 1);
	else
		return max(lcs_recursive(X, Y, m, n - 1), lcs_recursive(X, Y, m - 1, n));
}


int main() {
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	cout << "Length of LCS (iterative): " << lcs_iterative(X, Y) << endl;
	cout << "Length of LCS (recursive): " << lcs_recursive(X, Y, X.size(), Y.size()) << endl;
	return 0;
}
