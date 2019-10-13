#include <bits/stdc++.h>
using namespace std;
int Le,Ri,K,N,Q,Sparse[101010][25];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>N; K=log2(N);
	for(int i=1;i<=N;++i) cin>>Sparse[i][1];
	for(int j=1;j<=K;++j)
		for(int i=1;i<=N-(1<<j)+1;++i)
			Sparse[i][j+1]=min(Sparse[i][j],Sparse[i+(1<<(j-1))][j]);
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>Le>>Ri;
		Le++; Ri++;
		K=log2(Ri-Le+1);
		cout<<min(Sparse[Le][K+1],Sparse[Ri-(1<<K)+1][K+1])<<'\n';
	}
}
