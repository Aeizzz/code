#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000+10;
int a[maxn];
bool cmd(int a,int b){
    return a<b;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmd);
    int ans=0;
    int cnt=n/m;
    while(cnt--){
        for(int j=0;j<cnt*m;j++){
            ans+=a[j];
        }
    }
    for(int i=n/m*m;i<n;i++){
        for(int j=i%m;j<n/m*m;j+=m){
            ans+=a[j];
        }
    }
    printf("%d\n",ans);






    return 0;
}
