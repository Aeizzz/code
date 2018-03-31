#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000+10;
int a[maxn];
int dp[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int Max=-1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[i]>=a[j]) dp[i]=max(dp[j]+1,dp[i]);
        }
        Max=max(Max,dp[i]);
    }
    printf("%d\n",Max);







    return 0;
}
