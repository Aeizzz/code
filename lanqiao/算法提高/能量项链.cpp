#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100+10;
int a[maxn];
int f[maxn<<1][maxn<<1];
struct ball{
    int l,r;
    ball(){}
    ball(int _,int __):l(_),r(__){}
}bs[maxn<<1];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        bs[i]=ball(a[i],a[(i+1)%n]);
        for(int i=n;i<(n<<1);i++) bs[i]=bs[i-n];
    }
    for(int l=1;l<(n<<1);l++){
        for(int i=0;i+l<(n<<1);i++){
            int j=i+l;
            for(int k=i;k<j;k++){
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+bs[i].l*bs[k].r*bs[j].r);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,f[i][i+n-1]);

    }
    printf("%d\n",ans);
    return 0;








    return 0;
}
