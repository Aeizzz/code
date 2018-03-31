#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 45;
int a[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(a,-1,sizeof(a));
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        a[x]=0;
    }
    a[1]=1;
    a[2]=a[2]==0?a[2]:1;
    for(int i=3;i<=n;i++){
        if(a[i]!=0){
            a[i]=a[i-1]+a[i-2];
        }
    }
    printf("%d\n",a[n]);

    return 0;
}
