/*

剪邮票

如【图1.jpg】, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

请你计算，一共有多少种不同的剪取方法。

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。





*/




#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[12];
int visit[13];
int ans=0;
int have[13];
int mp[3][4];
int flag[3][4];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int Count;
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int dx=x+dir[i][0];
        int dy=y+dir[i][1];
        if(dx<0 || dx>=3 || dy<0 || dy >=4 ) continue;
        if(have[mp[dx][dy]] == 0 || flag[dx][dy]) continue;
        flag[dx][dy]=1;
        Count++;
        dfs(dx,dy);
    }
}
void solve(){
        memset(have,0,sizeof(have));
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=5;i++) have[a[i]]=1;
        int f=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                if(have[mp[i][j]]){
                    flag[i][j]=1;
                    Count=1;
                    dfs(i,j);
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        if(Count==5){
            ans++;
        }

}


void init(){
    int t=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            mp[i][j]=t;
            t++;
        }
    }
}
void dfs_creat(int index){
    if(index==6){
        solve();
        return ;
    }
    for(int i=a[index-1]+1;i<13;i++){
        if(!visit[i]){
            visit[i]=1;
            a[index]=i;
            dfs_creat(index+1);
            visit[i]=0;
        }
    }
}
int main(){
    init();
    dfs_creat(1);
    printf("%d\n",ans);




    return 0;
}


