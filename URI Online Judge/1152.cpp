#include <bits/stdc++.h>
#define fs first
#define sc second
#define piii pair<int,pair<int,int>>
using namespace std;
int Ans,V,E,A,B,C,P[200000];
int find(int X){return P[X]==X?X:P[X]=find(P[X]);}
priority_queue<piii,vector<piii>,greater<piii>> Edg;
piii Tmp;
inline void Reset(){
	Ans=0;
	while(!Edg.empty()) Edg.pop();
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while(cin>>V>>E){
		if(!V&&!E) return 0;
		Reset();
		for(int i=0;i<V;++i) P[i]=i;
		for(int i=0;i<E;++i){
			cin>>A>>B>>C;
			Edg.push({C,{A,B}});
			Ans+=C;
		}
		while(!Edg.empty()){
			Tmp=Edg.top(); Edg.pop();
			A=find(Tmp.sc.fs);
			B=find(Tmp.sc.sc);
			if(A==B) continue;
			Ans-=Tmp.fs;
			P[A]=B;
		}
		cout<<Ans<<'\n';
	}
}
