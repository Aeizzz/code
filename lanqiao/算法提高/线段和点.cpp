/*
题目大意：找出最少的点能满足所有的区间
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10000+10;
int vis[maxn];
struct sg{
    int begin;
    int end;
}s2[maxn];
struct node{
    int cur;
    int num;
}s1[maxn*5];
bool cmd(sg a,sg b){
    if(a.begin!=b.begin){
        return a.begin<b.begin;
    }
    return a.end<b.end;
}
int main(){
    int n,m;
    int count=0;
    for(int i=0;i<maxn*5;i++){
        s1[i].cur=0;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        s1[num].cur=1;
    }
    for(int j=1;j<=m;j++){
        scanf("%d%d",&s2[j].begin,&s2[j].end);
    }
    memset(vis,0,sizeof(vis));
    sort(s2+1,s2+1+m,cmd);
    int cur;
    for(int i=1;i<=m;i++){
        int Max=-1;
        if(!vis[i]){
            for(int j=s2[i].begin;j<=s2[i].end;j++){
                if(s1[j].cur){
                    s1[j].num=0;
                    for(int k=i+1;k<=m;k++){
                        if(s2[k].begin<=j&& s2[k].end>=j && !vis[k]){
                            s1[j].num++;
                        }else{
                            break;
                        }
                    }
                    if(s1[j].num>Max){
                        Max=s1[j].num;
                        cur=j;
                    }
                }
            }
            count++;
            for(int k=i+1;k<=m;k++){
                if(s2[k].begin<=cur){
                    vis[k]=1;
                }else{
                    break;
                }
            }
        }
    }
    printf("%d",count);


    return 0;
}
