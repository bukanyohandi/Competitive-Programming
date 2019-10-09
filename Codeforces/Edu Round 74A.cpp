#include <bits/stdc++.h>
using namespace std;
int T;
long long X,Y;
int main(){
	cin>>T;
	while(T--){
		cin>>X>>Y;
		if(X>Y+1) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
