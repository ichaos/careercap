/*
 * Given - a number (n) and a sorted array 
 * Find a number in the array having least difference with the given number (n).
 */

#include <iostream>

using namespace std;

int leastDiff(int t, vector<int> &v) {
    //binary search
    int i = 0;
    int j = v.size() - 1;
    if (j < 0) return -1;
    int mid = (i + j) / 2;
    while (i < j) {
        mid = (i + j) / 2;
        if (t == v[mid]) return v[mid];
        if (t < v[mid]) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    int ret = v[mid];
    int diff = abs(v[t] - v[mid]);
    if (mid - 1 >= 0 && diff > abs(v[t] - v[mid - 1]))
        ret = v[mid - 1];
    if (mid + 1 < v.size() && diff > abs(v[t] - v[mid + 1]))
        ret = v[mid + 1];
    
    return ret;
}
