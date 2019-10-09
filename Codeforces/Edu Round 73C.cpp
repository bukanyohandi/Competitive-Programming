#include <bits/stdc++.h>
using namespace std;
int Q,C,M,X;
int main(){
	cin>>Q;
	while(Q--){
		cin>>C>>M>>X;
		cout<<min(min(C,M),(C+M+X)/3)<<'\n';
	}
}
