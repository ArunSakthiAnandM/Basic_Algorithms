 #include <bits/stdc++.h>
 using namespace std;

void computeLPSArray(const string& pat, vector<int>& lps) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < pat.size()) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(const string& pat, const string& txt) {
	int M = pat.size();
	int N = txt.size();
	vector<int> lps(M);
	computeLPSArray(pat, lps);
	int i = 0, j = 0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			i++; j++;
		}
		if (j == M) {
			cout << "Found pattern at index " << i - j << "\n";
			j = lps[j - 1];
		} else if (i < N && pat[j] != txt[i]) {
			if (j != 0) j = lps[j - 1];
			else i++;
		}
	}
}

int main() {
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}
