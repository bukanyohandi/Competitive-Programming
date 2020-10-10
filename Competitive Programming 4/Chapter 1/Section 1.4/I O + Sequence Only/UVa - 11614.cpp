#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    long long n,le,ri,mid,save;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%lld",&n);
        le=0;
        ri=2000000000;
        while(le<=ri){
            mid=(le+ri)/2;
            if(mid*(mid+1)/2<=n){
                save=mid;
                le=mid+1;
            } else {
                ri=mid-1;
            }
        }
        printf("%lld\n",save);
    }
}