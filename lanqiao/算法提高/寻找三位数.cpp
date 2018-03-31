#include<cstdio>
#include<algorithm>
using namespace std;
int a[9]={1,2,3,4,5,6,7,8,9};

int main(){
    do{
        int x=a[0]*100+a[1]*10+a[2];
        int y=a[3]*100+a[4]*10+a[5];
        int z=a[6]*100+a[7]*10+a[8];
        if(z==x*3 && y==x*2){
            printf("%d %d %d\n",x,y,z);
        }

    }while(next_permutation(a,a+9));





    return 0;
}
