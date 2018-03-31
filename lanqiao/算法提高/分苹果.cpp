#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100000+10;
int a[maxn*4];
int lazy[maxn*4];

void pushdown(int num)
{
    if(lazy[num]!=0)
    {
        a[num*2]+=lazy[num];
        a[num*2+1]+=lazy[num];
        lazy[num*2]+=lazy[num];
        lazy[num*2+1]+=lazy[num];
        lazy[num]=0;
    }
}
void update(int num,int L,int R,int l,int r,int sum){
    if(l<=L && r>=R){
        a[num]+=sum;
        lazy[num]+=sum;
        return ;
    }
    pushdown(num);
    int mid = (L+R)/2;
    if(l<=mid) update(num*2,L,mid,l,r,sum);
    if(r>mid) update(num*2+1,mid+1,R,l,r,sum);
}
int query(int num,int le,int ri,int x)
{
    if(le==ri)
    {
        return a[num];
    }
    pushdown(num);
    int mid=(le+ri)/2;
    if(x<=mid)
        return query(num*2,le,mid,x);
    else
        return query(num*2+1,mid+1,ri,x);
}

int main(){
    memset(a,0,sizeof(a));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        update(1,1,n,l,r,c);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",query(1,1,n,i));
    }
    return 0;
}
