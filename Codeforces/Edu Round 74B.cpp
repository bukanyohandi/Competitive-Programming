#include <bits/stdc++.h>
using namespace std;
int Ans,Piv,Q,N,R,Arr[100000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>Q;
	while(Q--){
		cin>>N>>R;
		Ans=Piv=0;
		for(int i=0;i<N;++i) cin>>Arr[i];
		sort(Arr,Arr+N);
		N=unique(Arr,Arr+N)-Arr-1;
		for(int i=N-1;i>=0;--i){
			Piv+=R;
			if(Arr[i]<=Piv) break;
			Ans++;
		}
		cout<<Ans+1<<'\n';
	}
}
