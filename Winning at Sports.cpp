// https://www.facebook.com/hackercup/problem/688426044611322/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
#define MAX 2005
int n,m;
ll dp[MAX][MAX];
ll stressfree(int l,int r){
 if(l==n && r==m) return 1;
 if(l<=r || l>n || r>m) return 0;
 if(dp[l][r] != -1) return dp[l][r];
 ll res = 0;
 res = (res+stressfree(l+1,r))%mod;
 res = (res+stressfree(l,r+1))%mod;
 dp[l][r] = res;
 return res;
}
ll stressfull(int l,int r){
 if(l==n && r==m) return 1;
 if(l>r && r<m) return 0;
 if(l>n || r>m) return 0;
 if(dp[l][r] != -1) return dp[l][r];
 ll res = 0;
 res = (res+stressfull(l+1,r))%mod;
 res = (res+stressfull(l,r+1))%mod;
 dp[l][r] = res;
 return res;
}
int main(){
freopen("question.txt","r",stdin); freopen("answer.txt","w",stdout);
int t;
scanf("%d",&t);
for(int cas=1;cas<=t;cas++){
  scanf("%d-%d",&n,&m);
  memset(dp,-1,sizeof dp);
  ll res1 = stressfree(1,0);
  res1 = (res1+stressfree(0,1))%mod;
  memset(dp,-1,sizeof dp);
  ll res2 = stressfull(0,0);
  printf("Case #%d: %lld %lld\n",cas,res1,res2);
}
return 0;
}
