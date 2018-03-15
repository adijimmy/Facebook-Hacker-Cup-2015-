// https://www.facebook.com/hackercup/problem/759650454070547/
#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define PB push_back
#define N 512345
#define K 25
#define INF 112345678
int dp1[N][K], dp2[N][K];
int Q[N], p[N], rtl[K], ltr[K];
vector<int> child[N];
inline void solve() {
	int ans, i, j, l, u, v, st, ed, n;
	sd(n);
	for(i = 0; i < n; i++) {
		child[i].clear();
		sd(p[i]);
		p[i]--;
	}
	for(i = 1; i < n; i++) {
		child[p[i]].PB(i);
	}
	st = 0;
	ed = 0;
	Q[st] = 0;
	while(st <= ed) {
		u = Q[st];
		st++;
		for(i = (int)child[u].size() - 1; i >= 0; i--) {
			ed++;
			Q[ed] = child[u][i];
		}
	}
	for(i = n - 1; i >= 0; i--) {
		u = Q[i];
		if(child[u].size() == 0) {
			for(j = 1; j < K; j++) {
				dp1[u][j] = 0;
				dp2[u][j] = j;
			}
			dp1[u][0] = 1;
			dp2[u][0] = 0;
			continue;
		}
		for(j = 0; j < K; j++) {
			dp2[u][j] = j;
		}
		for(j = child[u].size() - 1; j >= 0; j--) {
			v = child[u][j];
			for(l = 0; l < K; l++) {
				dp2[u][l] += dp1[v][l];
			}
		}
		for(j = 0; j < K; j++) {
			ltr[j] = dp2[u][j];
			rtl[j] = dp2[u][j];
		}
		for(j = 1; j < K; j++) {
			rtl[j] = min(rtl[j], rtl[j - 1]);
		}
		for(j = K - 2; j >= 0; j--) {
			ltr[j] = min(ltr[j], ltr[j + 1]);
		}
		for(j = 1; j < K - 1; j++) {
			dp1[u][j] = min(rtl[j - 1], ltr[j + 1]);
		}
		dp1[u][0] = ltr[1];
		dp1[u][K - 1] = rtl[K - 2];
	}
	ans = INF;
	for(j = 0; j < K; j++) {
		ans = min(ans, dp2[0][j]);
	}
	ans += n;
	cout<<ans<<endl;
}
int main() {
	freopen("corporate_gifting.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	sd(t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
