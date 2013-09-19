/*
 * Find kth number in two sorted array. K = 1 means the first number.
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

//array a & b can't be empty
int findK(vector<int> &a, int i, int m, vector<int> &b, int j, int n, int k) {
	if (k <= 0 || k > m + n) return -1;

	if (m > n) return findK(b, j, n, a, i, m, k);

	//corner cases:
	if (k == 1) return min(a[i], b[j]);

	if (m == 0) return b[j + k - 1];

	int pa = min(k / 2, m);
	int pb = k - pa;

	if (a[i + pa - 1] < b[j + pb - 1])
		return findK(a, i + pa, m - pa, b, j, pb, k - pa);
	else if (a[i + pa - 1] > b[j + pb - 1])
		return findK(a, i, pa, b, j + pb, n - pb, k - pb);
	else return a[i + pa - 1];
}

int findKth(vector<int> &a, int i, int m, vector<int> &b, int j, int n, int k) {
        if (m > n) {
            return findKth(b, j, n, a, i, m, k);
        }

        if (m == 0) {
            return b[j + k - 1];
        }

        if (k == 1) {
            return min(a[i], b[j]);
        }

        int pa = min(k / 2, m);
        int pb = k - pa;

        if (a[i + pa - 1] < b[j + pb - 1]) {
            return findKth(a, i + pa, m - pa, b, j, n, k - pa);
        } else if (a[i + pa - 1] > b[j + pb - 1]) {
            return findKth(a, i, m, b, j + pb, n - pb, k - pb);
        } else {
            return a[i + pa - 1];
        }
    }

//test
int main() {
	int a[5] = {1, 3, 5, 7, 9};
	int b[5] = {2, 4, 6, 8, 10};

	vector<int> va(a, a + 5);
	vector<int> vb(b, b + 5);

	for (int i = 0; i < 10; i++) {
		cout << findK(va, 0, 5, vb, 0, 5, i + 1) << endl;
	}
	return 0;
}