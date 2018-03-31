#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100+10;
int a[maxn][maxn];
int main(){
    int n;
    scanf("%d",&n);
    a[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j-i>=0) a[i][j]=a[i][j-i]+a[i-1][j];
            else a[i][j]=a[i-1][j];
        }
    }
    printf("%d\n",a[n][n]);


}
