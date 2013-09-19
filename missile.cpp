/*
 * [NOIP1999]拦截导弹
 * 某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
 * 输入格式

输入数据为两行，
第一行为导弹的数目N(n<=1000)
第二行导弹依次飞来的高度，所有高度值均为不大于30000的正整数。

输出格式

输出只有一行是这套系统最多能拦截的导弹数和要拦截所有导弹最少要配备这种导弹拦截系统的套数。两个数据之间用一个空格隔开.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int h = 0;
	cin >> n;

	int height[n];
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	//first question
	int dp[n];
	int maxMissiles = 0;
	int num = 0;
	std::vector<int> parent(n, 0);
	int rm = n;
	while (rm) {
		for (int i = 0; i < n; i++) {
			if (parent[i] == -1) continue;
			dp[i] = 1;
			parent[i] = i;
			for (int j = 0; j < i; j++) {
				if (parent[j] == -1) continue;
				if (height[i] < height[j]) {
					if (dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
						parent[i] = j;
					}
				}
			}
			maxMissiles = max(maxMissiles, dp[i]);
			//cout << maxMissiles << ". " << num << endl;
		}
		
		for (int i = n - 1; i >= 0; i--) {			
			if (parent[i] == -1) continue;
			num++;
			int j = i;
			while (j != -1) {
				if (parent[j] != -1) rm--;
				int tmp = parent[j];
				parent[j] = -1;
				j = tmp;
			}
			break;
		}

	}	
	cout << maxMissiles << " " << num << endl;
	return 0;
}