//beautiful people : sgu 199
/*
	The most prestigious sports club in one city has exactly N members. Each of its members is strong and beautiful. More precisely, i-th member of this club (members being numbered by the time they entered the club) has strength Si and beauty Bi . Since this is a very prestigious club, its members are very rich and therefore extraordinary people, so they often extremely hate each other. Strictly speaking, i-th member of the club Mr X hates j-th member of the club Mr Y if Si ≤ Sj and Bi ≥ Bj or if Si ≥ Sj and Bi ≤ Bj (if both properties of Mr X are greater then corresponding properties of Mr Y, he doesn't even notice him, on the other hand, if both of his properties are less, he respects Mr Y very much). 

To celebrate a new 2003 year, the administration of the club is planning to organize a party. However they are afraid that if two people who hate each other would simultaneouly attend the party, after a drink or two they would start a fight. So no two people who hate each other should be invited. On the other hand, to keep the club presti≥ at the apropriate level, administration wants to invite as many people as possible. 

Being the only one among administration who is not afraid of touching a computer, you are to write a program which would find out whom to invite to the party. 

Input

The first line of the input file contains integer N — the number of members of the club. ( 2 ≤ N ≤ 100,000 ). Next N lines contain two numbers each — Si and Bi respectively ( 1 ≤ Si, Bi ≤ 109 ). 

Output

On the first line of the output file print the maximum number of the people that can be invited to the party. On the second line output N integers — numbers of members to be invited in arbitrary order. If several solutions exist, output any one. 

Sample test(s)

Input

4 
1 1 
1 2 
2 1 
2 2 

Output

2 
1 4 
 */
/*
 * DP问题，对所有来客排序，第一顺序为力量，第一顺序相同按照美丽值降序排列，
 * 然后查找所有来客按照美丽值的最长上升序列
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct people {
	int s;
	int b;
	int i;

	bool operator<(const people &n) const {
		if (s == n.s) return b > n.b;
		else return s < n.s;
	}
};

struct compareLess {
	bool operator()(const struct people &l, const struct people &r) {
		if (l.s == r.s) return l.b > r.b;
		else return l.s < r.s;
	}
};

//longest increase sequence
int lis(vector<struct people> &ps, vector<int> &result) {
	int n = ps.size();
	int dp[n];
	int l = 0;
	int last = 0;
	int parent[n];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		parent[i] = i;
		for (int j = 0; j < i; j++) {
			if (ps[j].b < ps[i].b) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					parent[i] = j;
				}
			}
		}
		if (l < dp[i]) {
			l = dp[i];
			last = i;
		}
	}

	//find the sequence;
	while (last != parent[last]) {
		result.insert(result.begin(), ps[last].i);
		last = parent[last];
	}
	result.insert(result.begin(), ps[last].i);

	return l;
}

int main() {
	int n = 0;
	cin >> n;

	vector<struct people> ps;

	for (int i = 0; i < n; i++) {
		people np;
		np.i = i + 1;
		cin >> np.s >> np.b;

		ps.push_back(np);
	}

	//sort(ps.begin(), ps.end(), compareLess());
	sort(ps.begin(), ps.end());

	for (int i = 0; i < ps.size(); i++) {
		cout << ps[i].s << " " << ps[i].b << endl;
	}

		//find LIS of people's beauty
		vector<int> result;
		int num = lis(ps, result);

		cout << num << endl;
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
			if (i == result.size() - 1) cout << endl;
			else cout << " ";
		}

	return 0;
} 