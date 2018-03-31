#include<cstdio>
#include<algorithm>
using namespace std;
const double MAX = 10000000000;
int n,m,tmp[1005],fa[1005];
double ans;
struct Edge{
    int u,v;
    double val,w;
}e[1005];
bool cmd(Edge a,Edge b){
    return a.w<b.w;
}
void UF_set(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int a,int b){
    int root1=Find(a);
    int root2=Find(b);
    if(root1!=root2) fa[root2]=root1;
}
void kru(int sum){
    UF_set(n);
    int cnt=0;
    double f_all=0;
    double all=0;
    double ave=sum*1.0/(n-1);
    for(int i=0;i<m;i++){
        e[i].w=(e[i].val-ave)*(e[i].val-ave);
    }
    sort(e,e+m,cmd);
    for(int i=0;i<m;i++){
        int u=e[i].u;
        int v=e[i].v;
        if(Find(u)!=Find(v)){
            Union(u,v);
            f_all+=e[i].w;
            all+=e[i].val;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    if((int)all==sum){
        ans=min(ans,f_all);
    }
}
int main(){
    int ca=1;
    freopen("1.in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF && (n+m)!=0){
        int minv=0;
        int maxv=0;
        ans=MAX;
        for(int i=0;i<m;i++){
            scanf("%d%d%lf",&e[i].u,&e[i].v,&e[i].val);
            tmp[i]=e[i].val;
        }
        sort(tmp,tmp+m);
        for(int i=0;i<n-1;i++){
            minv+=tmp[i];
        }
        for(int i=m-1;i>m-n;i--){
            maxv+=tmp[i];
        }
        for(int i=minv;i<=maxv;i++){
            kru(i);
        }
        ans=ans/(n-1);
        printf("Case %d: %.2f\n",ca++,ans);
    }







    return 0;
}
