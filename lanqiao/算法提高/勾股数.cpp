#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1000+10;
int a[maxn];
int main(){
    int flag=0;
    for(int i=1;i<1000;i++){
        for(int j=i+1;i+j<=1000;j++){
            int p=i*i+j*j;
            int t=sqrt(p);
            if(t*t==p){
                if(i+j+t>1000) continue;
                printf("%d %d %d\n",i,j,t);
            }
        }
    }






    return 0;
}
