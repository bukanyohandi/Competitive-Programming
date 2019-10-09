#include <bits/stdc++.h>
#define ll long long
#define INF 111222333444555666
using namespace std;
ll Memo[3][300003];
int Q,N,A[300003],B[300003];
ll Dp(int Take,int Pos){
	if(Pos==N) return 0;
	ll &ret=Memo[Take][Pos];
	if(ret!=-1) return ret;
	ret=INF;
	for(int i=0;i<3;++i)
		if(A[Pos]+i!=A[Pos-1]+Take||Pos==0)
			ret=min(ret,Dp(i,Pos+1)+i*B[Pos]);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>Q;
	while(Q--){
		cin>>N;
		for(int i=0;i<N;++i) cin>>A[i]>>B[i];
		for(int i=0;i<=N;++i) Memo[0][i]=Memo[1][i]=Memo[2][i]=-1;
		cout<<Dp(0,0)<<'\n';
	}
}
