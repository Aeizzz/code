#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 20000+10;
int w[60],v[60];
int dp[maxn];
const int inf = 9999999;
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    for(int i=1;i<=m;i++) dp[i]=inf;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=v[i];j++){
            for(int k=m;k>=w[i];k--){
                dp[k]=min(dp[k-w[i]]+1,dp[k]);
            }
        }
    }
    if(dp[m]==inf) printf("><");
    else printf("%d\n",dp[m]);

    return 0;
}
