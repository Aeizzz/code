/*

��������

С�����ٳֵ�X�ĳǣ�����������3�����ơ�
һ���˿��ƣ�ȥ����С���ƣ���52�ţ������ȷ���4���ˣ�ÿ����13�š�
��ʱ��С��������ͻȻð��һ�����⣺
��������ǻ�ɫ��ֻ���ǵ�����Ҳ�������Լ��õ����Ƶ��Ⱥ�˳���Լ��������õ��ĳ�ʼ�������һ���ж������أ�

����д����������Ҫ��д�κζ�������ݻ�˵�����֡�

*/




#include<cstdio>
#include<algorithm>
using namespace std;
//num���Ƶ�����
//cur�������Ƶ�����
int num=0;
int sum=0;
void dfs(int cur){
    if(num>13) return ;
    if(cur==13){
        if(num==13){
            sum++;

        }
        return ;
    }
    for(int i=0;i<5;i++){
        num+=i;
        dfs(cur+1);
        num-=i;
    }

}





int main(){
    dfs(0);
    printf("%d\n",sum);

    return 0;
}
