#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int maxn = 1000+10;
int dp[maxn][maxn];
int dfs(string s1,string s2){
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int t=dfs(s1,s2);
    printf("%d\n",t);





    return 0;
}
