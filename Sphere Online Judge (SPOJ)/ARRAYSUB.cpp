#include <bits/stdc++.h>
using namespace std;
int i,N,K,Arr[1000000];
deque<int> MaxSub;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>N;
	for(i=0;i<N;++i) cin>>Arr[i];
	cin>>K;
	for(i=0;i<K;++i){
		while(!MaxSub.empty()&&Arr[i]>=Arr[MaxSub.back()])
			MaxSub.pop_back();
		MaxSub.push_back(i);
	}
	for(;i<N;++i){
		cout<<Arr[MaxSub.front()]<<" ";
		while(!MaxSub.empty()&&MaxSub.front()<=i-K)
			MaxSub.pop_front();
		while(!MaxSub.empty()&&Arr[i]>=Arr[MaxSub.back()])
			MaxSub.pop_back();
		MaxSub.push_back(i);
	}
	cout<<Arr[MaxSub.front()]<<'\n';
}
