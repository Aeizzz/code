/*

???????

??????????1+2+3+ ... + 49 = 1225
??????????????????????????????????????2015

???��
1+2+3+...+10*11+12+...+27*28+29+...+49 = 2015
?????????????

?????????????????????????��???????????????????????????????????????10????

????????????????????????????��?�ʦ�?????????

??????????16,24????????16
???16
*/



#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    for(int i=1;i<=49;i++){
        for(int j=1;j<=49;j++){
            if(( 1225-(i+i+1)-(j+j+1)+i*(i+1)+j*(j+1) )==2015){
                printf("%d %d\n",i,j);
            }
        }
    }
}
