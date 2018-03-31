/*
��Ȼ��������

������ȡ�������Կ��Ե���������ȡ��

��ȷ�����½磬�Ͻ�����һ����+1������������������һ�����������ֵ+1��

���ȷ�����������ֵ�أ�

����һ����������ά��

��dp[i]��ʾƴ��i�������Ҫ��������Ʊ����

���ݱ�������ֵ�����Ĵ�С��������1��

ͳ��dp[i]<=n������i�ĸ���
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int res;
int ans[100];
int temp[100];
int dp[2000];
int n,k;
int calc(int dep,int sum){
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=dep;i++){
        for(int j=temp[i];j<=n*sum;j++){
            dp[j]=min(dp[j],dp[j-temp[i]]+1);
        }
    }
    for(int i=1;i<=n*sum;i++){
        if(dp[i]>n) return i-1;
    }
    return n*sum;
}
void dfs(int dep,int lst1,int lst2,int sum){
    if(dep>k){
        if(res<lst2){
            res=lst2;
            for(int i=1;i<=k;i++){
                ans[i]=temp[i];
            }
        }
        return ;
    }
    for(int i=lst1+1;i<=lst2+1;i++){
        temp[dep]=i;
        int x=calc(dep,sum+i);
        dfs(dep+1,i,x,sum+i);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    dfs(1,0,0,0);
    for(int i=1;i<=k;i++){
        printf("%d ",ans[i]);
    }
    printf("\nMAX=%d\n",res);
    return 0;
}
