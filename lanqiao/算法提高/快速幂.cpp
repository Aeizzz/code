#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
ll qpow(ll a,ll b,ll p){
    ll res=1;
    while(b){
        if(b&1) res=((res%p)*(a%p))%p;
        b/=2;
        a=((a%p)*(a%p))%p;
    }
    return res%p;
}
int main(){
    ll a,b,p;
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld\n",qpow(a,b,p));
    return 0;
}
