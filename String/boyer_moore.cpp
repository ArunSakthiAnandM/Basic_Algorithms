 #include <bits/stdc++.h>
 using namespace std;

const int NO_OF_CHARS = 256;

void badCharHeuristic(const string& str, vector<int>& badChar) {
	int n = str.size();
	for (int i = 0; i < NO_OF_CHARS; i++) badChar[i] = -1;
	for (int i = 0; i < n; i++) badChar[(int)str[i]] = i;
}

void boyerMooreSearch(const string& txt, const string& pat) {
	int m = pat.size();
	int n = txt.size();
	vector<int> badChar(NO_OF_CHARS);
	badCharHeuristic(pat, badChar);
	int s = 0;
	while (s <= (n - m)) {
		int j = m - 1;
		while (j >= 0 && pat[j] == txt[s + j]) j--;
		if (j < 0) {
			cout << "Pattern occurs at index " << s << "\n";
			s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
		} else {
			s += max(1, j - badChar[txt[s + j]]);
		}
	}
}

int main() {
	string txt = "ABAAABCD";
	string pat = "ABC";
	boyerMooreSearch(txt, pat);
	return 0;
}
