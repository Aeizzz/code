#include<cstdio>
#include<algorithm>
using namespace std;
#define PI 3.1415926536
int main(){
    double r;
    scanf("%lf",&r);
    double v,vv,vvv;
    v=PI*r*r;
    vv=4*v;
    vvv=4*v*r/3;
    printf("%-20.10f%-20.10f%-20.10f\n",v,vv,vvv);
    return 0;
}
