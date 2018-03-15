// https://www.facebook.com/hackercup/problem/582396081891255/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAXN 10000005
int p[MAXN];
int kp[MAXN][11];
void pre(){
	for(int i=2;i<MAXN;i++)
		if(p[i]==0)
			for(int j=i;j<MAXN;j+=i)
				p[j]++;
	for(int i=2;i<MAXN;i++)
		for(int j=1;j<11;j++)
			kp[i][j] = kp[i-1][j]+(p[i]==j?1:0);
}
int main(){
  freopen("question.txt","r",stdin); freopen("answer.txt","w",stdout);
	pre();
	int t,a,b,k;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d%d%d",&a,&b,&k);
		printf("Case #%d: ",cas);
		printf("%d\n",kp[b][k]-kp[a-1][k]);
	}
	return 0;
}
