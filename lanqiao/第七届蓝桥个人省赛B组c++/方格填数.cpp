/*
方格填数

如下的10个格子
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+

（如果显示有问题，也可以参看【图1.jpg】）

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）

一共有多少种可能的填数方案？

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a[]={0,1,2,3,4,5,6,7,8,9};
int ans=0;
int mp[3][4];//赋值区域
int flag[3][4];//区域标记
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};

void init(){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            flag[i][j]=1;
        }
    }
    flag[0][0]=0;
    flag[2][3]=0;
}
void solve(){
    //判断该可能是否成立
    int book = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(flag[i][j]==0) continue;
            for(int k=0;k<8;k++){
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x< 0 || x>=3 || y<0 || y>=4 || flag[x][y]==0) continue;
                if(abs(mp[i][j]-mp[x][y])==1) book = 0;
            }
        }
    }
    if(book) ans++;
}
void fun(){
    //给整个区域赋值
    int t=0;
    for(int i=1;i<4;i++) mp[0][i]=a[t++];
    for(int i=0;i<4;i++) mp[1][i]=a[t++];
    for(int i=0;i<3;i++) mp[2][i]=a[t++];
}
int main(){
    init();
    do{
        //生成全排列
        fun();
        solve();

    }while(next_permutation(a,a+10));

    printf("%d\n",ans);
    return 0;
}
