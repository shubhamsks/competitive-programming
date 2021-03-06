#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 1000000000000000000LL

int T, N, TYPE;
char S[100001];
int wb[100001], wg[100001], wbs, wgs;

int main(){
  int i, k;
  int B, G;
  ll res, tmp;

  scanf("%d",&T);
  while(T--){
    scanf("%d",&TYPE);
    scanf("%s",S);
    N = strlen(S);

    res = INF;
    rep(k,2){
      rep(i,N) S[i] = (S[i]=='B'?'G':'B');
      
      B = G = 0;
      rep(i,N) if(S[i]=='B') B++; else G++;
      if(B!=G && B!=G+1) continue;

      if(TYPE==0){
        tmp = 0;
        for(i=0;i<N;i+=2) if(S[i]!='B') tmp++;
        res = min(res, tmp);
      } 
      else {
        tmp = 0;
        wbs = wgs = 0;
        for(i=0;i<N;i+=2) if(S[i]!='B') wb[wbs++] = i;
        for(i=1;i<N;i+=2) if(S[i]!='G') wg[wgs++] = i;
        rep(i,wbs) tmp += abs(wb[i]-wg[i]);
        res = min(res, tmp);
      }
    }

    if(res==INF) res = -1;
    printf("%lld\n", res);
  }

  return 0;
}