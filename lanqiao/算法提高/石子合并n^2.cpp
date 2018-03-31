#include<cstdio>
#include<algorithm>
using namespace std;
const int inf = 1<<30;
const int maxn = 200+10;
int dp[maxn][maxn];
int sum[maxn];
int a[maxn];

int get(int a[],int n){
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int v=1;v<n;v++){
        for(int i=0;i<n-v;i++){
            int j=i+v;
            dp[i][j]=inf;
            int temp=sum[j]-(i>0?sum[i-1]:0);
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][k]+dp[k+1][j]+temp,dp[i][j]);
            }
        }
    }
    return dp[0][n-1];
}



int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    printf("%d\n",get(a,n));






    return 0;
}
