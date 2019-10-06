#include <bits/stdc++.h>
using namespace std;
unsigned long long F[21]={1,1};
int N,M;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int i=2;i<=20;++i) F[i]=F[i-1]*i;
	while(cin>>N>>M) cout<<F[N]+F[M]<<'\n';
}
