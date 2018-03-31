#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100+10;
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[k])
                k=j;
        }
        swap(a[i],a[k]);
        printf("swap(a[%d], a[%d]):",i,k);
        for(int m=0;m<n;m++){
            printf("%d ",a[m]);
        }
        printf("\n");
    }
    return 0;
}
