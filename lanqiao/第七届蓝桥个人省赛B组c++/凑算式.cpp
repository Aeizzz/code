/*

����ʽ

     B      DEF
A + --- + ------- = 10
     C      GHI

�������ʾ�����⣬���Բμ���ͼ1.jpg����


�����ʽ��A~I����1~9�����֣���ͬ����ĸ����ͬ�����֡�

���磺
6+8/3+952/714 ����һ�ֽⷨ��
5+3/1+972/486 ����һ�ֽⷨ��

�����ʽһ���ж����ֽⷨ��

ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�


29��
*/

#include<cstdio>
#include<algorithm>
using namespace std;
int a[]={1,2,3,4,5,6,7,8,9};
int main(){
    int sum=0;
    do{
        int b1,b2,b3,b4,b5;
        b1=a[0];
        b2=a[1];
        b3=a[2];
        b4=a[3]*100+a[4]*10+a[5];
        b5=a[6]*100+a[7]*10+a[8];
        if(b1*b3*b5+b2*b5+b4*b3==10*b3*b5){
            for(int i=0;i<9;i++){
                printf("%d ",a[i]);
            }
                printf("\n");
            sum++;
        }
    }while(next_permutation(a,a+9));
    printf("%d\n",sum);




    return 0;
}

