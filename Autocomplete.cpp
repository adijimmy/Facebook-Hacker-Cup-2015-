// https://www.facebook.com/hackercup/problem/313229895540583/
#include <bits/stdc++.h>
typedef long long int ll;
using  namespace std;
int cnt;
struct node{
    int value;
    node * child[27];
};
node * newnode(){
    node * newt = new node;
    newt->value = 0;
    for(int i=0;i<27;i++)
        newt->child[i] = NULL;
    return newt;
}
struct trie{
   node * root;
   trie(){
      root = newnode();
   }
};
trie * dict;
void insert(string s){
    int l = s.length();
    node * ptr = dict->root;
    for(int i=0;i<l;i++){
       int index = s[i]-'a';
       if(ptr->child[index]==NULL)
         ptr->child[index] = newnode();
       ptr = ptr->child[index];
       ptr->value += 1;
    }
}

void find(string s){
    int l = s.length();
    node * ptr = dict->root;
    for(int i=0;i<l;i++){
        int in = s[i]-'a';
        ptr = ptr->child[in];
        cnt++;
        if(ptr->value == 1)
           return;
    }
}
int main(){
    freopen("autocomplete.txt","r",stdin); freopen("answer.txt","w",stdout);
    int t,n;
    string s;
    scanf("%d",&t);
    for(int cas =1;cas<=t;cas++){
      dict = new trie;
      cnt = 0;
      scanf("%d",&n);
      for(int i=0;i<n;i++){
       cin >> s;
       insert(s);
       find(s);
      }
      printf("Case #%d: %d\n",cas,cnt);
      delete dict;
    }
    return 0;
}
