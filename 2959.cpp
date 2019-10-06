#include <bits/stdc++.h>
using namespace std;
int A,B,V,E,Q,P[401];
int find(int X){return P[X]==X?X:P[X]=find(P[X]);}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>V>>E>>Q;
	for(int i=1;i<=V;++i) P[i]=i;
	for(int i=1;i<=E;++i){
		cin>>A>>B;
		P[find(A)]=find(B);
	}
	for(int i=1;i<=Q;++i){
		cin>>A>>B;
		if(find(A)==find(B)) cout<<"Lets que lets\n";
		else cout<<"Deu ruim\n";
	}
}
