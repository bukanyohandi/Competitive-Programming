#include <bits/stdc++.h>
using namespace std;
long long Q,N,A;
map<int,int> Save;
int main(){
	cin>>Q;
	while(Q--){
		Save.clear();
		cin>>N;
		while(N--){
			cin>>A;
			if(A<=2048) Save[A]++;
		}
		for(int i=0;i<11;++i)
			Save[(1<<(i+1))]+=Save[(1<<i)]/2;
		if(Save[2048]) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
