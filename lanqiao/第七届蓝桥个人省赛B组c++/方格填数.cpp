/*
��������

���µ�10������
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+

�������ʾ�����⣬Ҳ���Բο���ͼ1.jpg����

����0~9�����֡�Ҫ���������������ֲ������ڡ�
�����ҡ����¡��ԽǶ������ڣ�

һ���ж����ֿ��ܵ�����������

����д��ʾ������Ŀ��������
ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�
*/
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a[]={0,1,2,3,4,5,6,7,8,9};
int ans=0;
int mp[3][4];//��ֵ����
int flag[3][4];//������
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};

void init(){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            flag[i][j]=1;
        }
    }
    flag[0][0]=0;
    flag[2][3]=0;
}
void solve(){
    //�жϸÿ����Ƿ����
    int book = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(flag[i][j]==0) continue;
            for(int k=0;k<8;k++){
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x< 0 || x>=3 || y<0 || y>=4 || flag[x][y]==0) continue;
                if(abs(mp[i][j]-mp[x][y])==1) book = 0;
            }
        }
    }
    if(book) ans++;
}
void fun(){
    //����������ֵ
    int t=0;
    for(int i=1;i<4;i++) mp[0][i]=a[t++];
    for(int i=0;i<4;i++) mp[1][i]=a[t++];
    for(int i=0;i<3;i++) mp[2][i]=a[t++];
}
int main(){
    init();
    do{
        //����ȫ����
        fun();
        solve();

    }while(next_permutation(a,a+10));

    printf("%d\n",ans);
    return 0;
}
