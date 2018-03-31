#include<cstdio>
#include<algorithm>
int is_prime[110];
int main(){
    for(int i=2;i*i<=100;i++){
        if(!is_prime[i]){
            for(int j=i*i;j<=100;j+=i) is_prime[j]=1;
        }
    }
    for(int i=2;i<=100;i++){
        if(is_prime[i]==0){
            printf("%d\n",i);
        }
    }






    return 0;
}
