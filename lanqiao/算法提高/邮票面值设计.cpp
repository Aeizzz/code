/*
显然是搜索。

由于是取数，所以可以单调递增地取。

再确定上下界，上界是上一个数+1，由于连续，所以上一次连续的最大值+1。

如何确定连续的最大值呢？

考虑一个背包，换维。

设dp[i]表示拼成i这个数需要的最少邮票数。

根据背包，价值是数的大小，费用是1。

统计dp[i]<=n的连续i的个数
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int res;
int ans[100];
int temp[100];
int dp[2000];
int n,k;
int calc(int dep,int sum){
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=dep;i++){
        for(int j=temp[i];j<=n*sum;j++){
            dp[j]=min(dp[j],dp[j-temp[i]]+1);
        }
    }
    for(int i=1;i<=n*sum;i++){
        if(dp[i]>n) return i-1;
    }
    return n*sum;
}
void dfs(int dep,int lst1,int lst2,int sum){
    if(dep>k){
        if(res<lst2){
            res=lst2;
            for(int i=1;i<=k;i++){
                ans[i]=temp[i];
            }
        }
        return ;
    }
    for(int i=lst1+1;i<=lst2+1;i++){
        temp[dep]=i;
        int x=calc(dep,sum+i);
        dfs(dep+1,i,x,sum+i);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    dfs(1,0,0,0);
    for(int i=1;i<=k;i++){
        printf("%d ",ans[i]);
    }
    printf("\nMAX=%d\n",res);
    return 0;
}
