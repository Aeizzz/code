/*

移动距离

X星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为1,2,3...
当排满一行时，从下一行相邻的楼往反方向排号。
比如：当小区排号宽度为6时，开始情形如下：

1  2  3  4  5  6
12 11 10 9  8  7
13 14 15 .....

我们的问题是：已知了两个楼号m和n，需要求出它们之间的最短移动距离（不能斜线方向移动）

输入为3个整数w m n，空格分开，都在1到10000范围内
w为排号宽度，m,n为待计算的楼号。
要求输出一个整数，表示m n 两楼间最短移动距离。

例如：
用户输入：
6 8 2
则，程序应该输出：
4

再例如：
用户输入：
4 7 20
则，程序应该输出：
5

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


*/


#include<cstdio>
#include<algorithm>
using namespace std;
int w;
int getX(int n){
    int p=(n-1)/w;
    return p+1;
}
int getY(int n){
    int p=getX(n);
    if(p%2==1){ //奇数行
        int x=n%w;
        if(x==0){
            return w;
        }else{
            return x;
        }
    }else{
        int x=n%w;
        if(x==0){
            return 1;
        }else{
            return (w-x+1);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d%d",&w,&n,&m);
    int x1,x2;
    int y1,y2;
    x1=getX(n);
    x2=getX(m);
    y1=getY(n);
    y2=getY(m);
    printf("%d\n",abs(x1-x2)+abs(y1-y2));

    return 0;
}
