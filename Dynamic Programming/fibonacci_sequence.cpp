 #include <bits/stdc++.h>
 using namespace std;


int fibonacci_iterative(int n) {
	if (n <= 1) return n;
	vector<int> dp(n + 1);
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}

int fibonacci_recursive(int n) {
	if (n <= 1) return n;
	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}


int main() {
	int n = 10;
	cout << "Fibonacci number at position " << n << " (iterative): " << fibonacci_iterative(n) << endl;
	cout << "Fibonacci number at position " << n << " (recursive): " << fibonacci_recursive(n) << endl;
	cout << "Fibonacci sequence up to " << n << " (iterative): ";
	for (int i = 0; i <= n; i++) cout << fibonacci_iterative(i) << " ";
	cout << endl;
	cout << "Fibonacci sequence up to " << n << " (recursive): ";
	for (int i = 0; i <= n; i++) cout << fibonacci_recursive(i) << " ";
	cout << endl;
	return 0;
}
