#include<cstdio>
#include<algorithm>
const int maxn = 10000;
#include<vector>
using namespace std;
vector<int> a[5];
bool cmd(int a,int b){
    return a>b;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x>=0 && x<=59){
            a[0].push_back(x);
        }else if(x>=60 && x<=69){
            a[1].push_back(x);
        }else if(x>=70 && x<=79){
            a[2].push_back(x);
        }else if(x>=80 && x<=89){
            a[3].push_back(x);
        }else if(x>=90 && x<=100){
            a[4].push_back(x);
        }
    }
    int Max=-1;
    int index=0;
    for(int i=4;i>=0;i--){
        int p=a[i].size();
        printf("%d ",p);
        if(p>Max){
            Max=p;
            index=i;
        }
    }
    printf("\n%d\n",Max);
    sort(a[index].begin(),a[index].end(),cmd);
    for(int i=0;i<Max;i++){
        printf("%d ",a[index][i]);
    }




    return 0;
}
