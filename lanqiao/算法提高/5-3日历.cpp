#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int Day[2][13] = {
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366},
};
int xx[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int judge(int y){
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}
int delta(int y, int m, int d){
	return ((y-1)*365 + (y-1)/4 - (y-1)/100 + (y-1)/400) + Day[judge(y)][m-1] + d-1;
}
int getday(int n,int y){
    return (delta(n,y,1)-delta(2007,1,1));
}
int main(){
    int n,y;
    scanf("%d%d",&n,&y);
    int day=getday(n,y);
    //cout<<day%7<<endl;
    printf("Calendar %d - %02d\n",n,y);
    printf("---------------------\nSu Mo Tu We Th Fr Sa\n---------------------\n");
    int p=day%7;
    int x=0;
    for(int i=0;i<=p;i++,x++){
        printf("%2c ",' ');
    }
    int l=xx[judge(n)][y];
    for(int i=1;i<=l;i++,x++){
        if(x%7==0) printf("\n");
        printf("%2d ",i);
    }
    printf("\n---------------------");

    return 0;
}
