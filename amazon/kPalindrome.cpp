/*
 A k-palindrome is a string which transforms into a palindrome on removing at most k characters. 

Given a string S, and an interger K, print "YES" if S is a k-palindrome; otherwise print "NO". 
Constraints: 
S has at most 20,000 characters. 
0<=k<=30 

Sample Test Case#1: 
Input - abxa 1 
Output - YES 
Sample Test Case#2: 
Input - abdxa 1 
Output - No
 */

int modifiedEditDistance(string &a, string &b, int k) {
	int n = a.size();
	int dp[n + 1][n + 1];

	for (int i = 0; i < n; i++) {
		dp[i][0] = dp[0][i] = i;
	}

	for (int i = 1; i <= n; i++) {
		int from = max(1, i - k);
		int to = min(i + k, n);
		for (int j = from; j <= to; j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
		}
	}

	return dp[n][n];
}

int main() {
	int k = 5;
	int d = modifiedEditDistance("abxa", "axba", k);
}