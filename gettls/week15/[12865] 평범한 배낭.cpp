#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int dp[101][100001];
int main() {
	int n, k; // ����, ����

	cin >> n >> k;

	vector<pair<int, int>> list(n + 1);
	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		list[i] = { w,v }; // ����, ��ġ
	}

	// dp[i][j] : i ��° �������� ����ؼ� j ���� �賶�� �־��� �� �ִ�

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			// ���� ������ ���ų�, �賶 ���԰� 0�� ���� �ִ��� 0
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				// i ��° ������ ���԰� j ���� ū ���
				if (list[i].first > j) {
					dp[i][j] = dp[i - 1][j];
				}
				// i ��° ������ �־ j ���� �賶�� �־��� ����
				// i ��° ������ ���� �ʰ� j ���� �賶�� �־��� ��츦 ��
				else {
					dp[i][j] = max(dp[i - 1][j], list[i].second + dp[i - 1][j - list[i].first]);
				}
			}
		}
	}
	cout << dp[n][k];
}
