#include <bits/stdc++.h>
#define INF 381456729
using namespace std;
int Dis[64][64],dx[8]={-2,-1,-1,-2,2,1,1,2},dy[8]={-1,-2,2,1,-1,-2,2,1};
inline bool inRange(int X,int Y){return X>=0&&X<8&&Y>=0&&Y<8;}
inline int Translate(string X){return (X[0]-'a')*8+X[1]-'1';}
string S,T;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int i=0;i<64;++i)
		for(int j=0;j<64;++j)
			Dis[i][j]=i==j?0:INF;
	for(int i=0;i<8;++i)
		for(int j=0;j<8;++j)
			for(int k=0;k<8;++k)
				if(inRange(i+dx[k],j+dy[k]))
					Dis[i*8+j][(i+dx[k])*8+(j+dy[k])]=1;
	for(int k=0;k<64;++k)
		for(int i=0;i<64;++i)
			for(int j=0;j<64;++j)
				Dis[i][j]=min(Dis[i][j],Dis[i][k]+Dis[k][j]);
	while(cin>>S>>T)
		cout<<"To get from "<<S<<" to "<<T<<" takes "<<Dis[Translate(S)][Translate(T)]<<" knight moves.\n";
}
