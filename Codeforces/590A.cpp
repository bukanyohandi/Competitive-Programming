#include <bits/stdc++.h>
using namespace std;
int Q,N,X,Sum;
int main(){
	cin>>Q;
	while(Q--){
		cin>>N; Sum=0;
		for(int i=1;i<=N;++i) cin>>X,Sum+=X;
		cout<<(Sum+N-1)/N<<'\n';
	}
}
