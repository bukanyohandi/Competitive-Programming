#include <bits/stdc++.h>
using namespace std;
int tmp1,tmp2,Le,Ri,T,N,M,Q,X,Root,Euler[1010],H[1010];
pair<int,int> Tree[8080];
vector<int> Edg[1010],Idx[1010];
bool hasPar[1010],Vis[1010];
inline void Add(int A){
	cin>>X;
	hasPar[X]=1;
	Edg[A].push_back(X);
	Edg[X].push_back(A);
	return;
}
inline bool check(int A){
	if(hasPar[A]) return false;
	Root=A;
	return true;
}
void eulerTree(int A,int &Pos,int Height){
	Vis[A]=1;
	Idx[A].push_back(Pos);
	Euler[Pos]=A;
	H[Pos++]=Height;
	for(auto i:Edg[A]){
		if(!Vis[i]){
			eulerTree(i,Pos,Height+1);
			Idx[A].push_back(Pos);
			Euler[Pos]=A;
			H[Pos++]=Height;
		}
	}
	return;
}
pair<int,int> build(int low,int high,int pos){
	if(low==high) return Tree[pos]={H[low],low};
	int mid=(low+high)/2;
	return Tree[pos]=min(build(low,mid,2*pos),build(mid+1,high,2*pos+1));
}
pair<int,int> query(int low,int high,int pos){
	if(Le<=low&&high<=Ri) return Tree[pos];
	if(Ri<low||high<Le) return {381654729,381654729};
	int mid=(low+high)/2;
	return min(query(low,mid,2*pos),query(mid+1,high,2*pos+1));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;++t){
		cout<<"Case "<<t<<":\n";
		memset(Vis,0,sizeof(Vis));
		memset(hasPar,0,sizeof(hasPar));
		cin>>N;
		for(int i=1;i<=N;++i){
			Edg[i].clear();
			Idx[i].clear();
			cin>>M;
			for(int j=0;j<M;++j) Add(i);
		}
		for(int i=1;!check(i);++i);
		eulerTree(Root,N=1,1);
		build(1,N-1,1);
		cin>>Q;
		for(int i=1;i<=Q;++i){
			cin>>Le>>Ri;
			Le=Idx[Le][0];
			Ri=Idx[Ri][0];
			if(Le>Ri) swap(Le,Ri);
			cout<<Euler[query(1,N-1,1).second]<<'\n';
		}
	}
}
