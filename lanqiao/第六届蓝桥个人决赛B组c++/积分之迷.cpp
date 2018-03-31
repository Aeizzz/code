/*

标题：积分之迷

小明开了个网上商店，卖风铃。共有3个品牌：A，B，C。
为了促销，每件商品都会返固定的积分。

小明开业第一天收到了三笔订单：
第一笔：3个A + 7个B + 1个C，共返积分：315
第二笔：4个A + 10个B + 1个C，共返积分：420
第三笔：A + B + C，共返积分....

你能算出第三笔订单需要返积分多少吗？

请提交该整数，不要填写任何多余的内容。

答案：105
这个题虽然a,b,c的积分不能确定但是a+b+c的值是确定的

*/


#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    for(int i=1;i<200;i++){
        for(int j=1;j<=200;j++){
            for(int k=1;k<=200;k++){
                int t=3*i+7*j+k;
                int t1=4*i+10*j+k;
                if(t==315 && t1==420){
                    printf("%d %d %d %d\n",i,j,k,i+j+k);
                }
            }
        }
    }





    return 0;
}
