#include <algorithm>
#include <cstdio>
using namespace std;
/**


三羊献瑞

观察下面的加法算式：

      祥 瑞 生 辉
  +   三 羊 献 瑞
-------------------
   三 羊 生 瑞 气

(如果有对齐问题，可以参看【图1.jpg】)

其中，相同的汉字代表相同的数字，不同的汉字代表不同的数字。

请你填写“三羊献瑞”所代表的4位数字（答案唯一），不要填写任何多余内容。


**/

int a[] = {0,1,2,3,4,5,6,7,8,9};
int main(){

    do {
        if(a[0] !=0 && a[4]!=0){
            int p = a[0]*1000+a[1]*100+a[2]*10+a[3];
            int g = a[4]*1000+a[5]*100+a[6]*10+a[1];
            int s = a[4]*10000+a[5]*1000+a[2]*100+a[1]*10+a[7];
            if(p+g==s){
                for(int i=0;i<=7;i++){
                    printf("%d   ",a[i]);
                }
                printf("\n");
            }
        }

    }while(next_permutation(a,a+10));





    return 0;
}