/*
解析:   f[i][j]表示前 i 种花，摆出 j 盆的方案数，则：
        f[i][j]=sum{f[i-1][j-k]}(0<=k<=a[i])
*/

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100+10;
const int mod = 1000007;
int n,m,a[maxn];
int f[maxn][maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=a[1];i++) f[1][i]=1;
    for(int i=1;i<=n;i++){
        f[i][0]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=a[i] && k<=j;k++){
                f[i][j]+=f[i-1][j-k],f[i][j]%=mod;
            }
        }
    }
    printf("%d\n",f[n][m]);

    return 0;

}
