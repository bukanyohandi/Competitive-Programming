#include <bits/stdc++.h>
using namespace std;
int Cnt,U,V,X,Y,N,Piv,Indeg[26];
string Dict[100];
vector<int> Edg[26],Order;
bool Memo[26][26];
set<int> Node;
inline void TopoSort(){
	while(!Node.empty()){
		U=*Node.begin();
		Node.erase(Node.begin());
		Order.push_back(U); Cnt++;
		for(int i=0;i!=Edg[U].size();++i){
			V=Edg[U][i];
			Indeg[V]--;
			if(!Indeg[V]) Node.insert(V);
		}
	}
	return;
}
int main(){
	cin>>N;
	for(int i=0;i<N;++i)
		cin>>Dict[i];
	for(int i=0;i<N-1;++i){
		Piv=0;
		while(Piv<min(Dict[i].length(),Dict[i+1].length())){
			X=Dict[i][Piv]-'a'; Y=Dict[i+1][Piv]-'a';
			if(Dict[i][Piv]!=Dict[i+1][Piv]){
				if(!Memo[X][Y]){
					Memo[X][Y]=true;
					Edg[X].push_back(Y);
					Indeg[Y]++;
				}
				break;
			}
			Piv++;
		}
		if(Piv==Dict[i+1].length()&&Dict[i].length()>Piv){
			cout<<"Impossible\n";
			return 0;
		}
	}
	for(int i=0;i<26;++i) if(!Indeg[i]) Node.insert(i);
	TopoSort();
	if(Cnt!=26){
		cout<<"Impossible\n";
		return 0;
	}
	for(auto i:Order) cout<<(char)('a'+i);
	cout<<'\n';
}
