#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int flag=0;
    for(int i=0;i*i<=n;i++){
        for(int j=0;j*j<=n;j++){
            for(int k=0;k*k<=n;k++){
                int temp=n-i*i-j*j-k*k;
                int x=sqrt(temp);
                if(x*x==temp){
                    printf("%d %d %d %d\n",i,j,k,x);
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    return 0;
}
