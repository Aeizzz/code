#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000+10;
int from[maxn];
int dp[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&from[i]);
    }
    dp[0]=0;
    int Max=-1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[from[i]]+1;
        Max=max(Max,dp[i]);
    }
    printf("%d\n",Max);








    return 0;
}
