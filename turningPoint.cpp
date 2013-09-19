//turning point
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//find turning point in the vector from v[i] to v[j], unpredictable in case of no turning point
int turningPoint(vector<int> &v, int i, int j) {
	if (i == j) return i;

	if (j - 1 == i) {
		if (v[i] > v[j]) return j;
		else return -1; // no turning point
	}

	int m = (i + j) / 2;

	if (v[m] > v[i]) {
		return turningPoint(v, m + 1, j);
	} else if (v[m] < v[i]) {
		return turningPoint(v, i + 1, m);
	}
	int l = turningPoint(v, i, m - 1);
	int r = turningPoint(v, m + 1, j);

	if (l == -1) return r;
	if (r == -1) return l;
	return v[l] < v[r] ? l : r;
}

int main() {
	int a[] = {6, 7, 8, 9, 10, 13, 16, 26, 36};

	vector<int> v(a, a + 9);
	cout << turningPoint(v, 0, 8) << endl;
}