#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,N,K,P;
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        scanf("%d %d %d",&N,&K,&P);
        printf("Case %d: %d\n",i+1,1+(K+P-1)%N);
    }
}