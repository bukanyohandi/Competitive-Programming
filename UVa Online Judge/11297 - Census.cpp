#include <bits/stdc++.h>
/*
	Karya anak bangsa yang paling agung
	Author : Yohandi or... bukan..
*/

#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define Mid (Low+High)/2

#define all(a) a.begin(),a.end()
#define lb(a,x) (lower_bound(all(a),x)-a.begin())
#define ub(a,x) (upper_bound(all(a),x)-a.begin())

#define rep(a,x,y) for(int a=(int)x;a<=(int)y;++a)
#define repd(a,x,y,d) for(int a=(int)x;a<=(int)y;a+=d)
#define res(a,x,y) for(int a=(int)x;a>=(int)y;--a)
#define resd(a,x,y,d) for(int a=(int)x;a>=(int)y;a-=d)

// Ordered Set, Ordered Multiset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define o_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define o_multiset tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
// .order_of_key(x) -> Number of elements less than x
// * .find_by_order(k) -> Kth smallest element (0-based)
// .erase(x) -> Remove all elements equal to x

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using lint=long long;

mt19937 rng(time(NULL));

lint Power(lint A,lint B,lint C){
	if(!B) return 1LL;
	lint tmp=Power(A,B>>1,C);
	return tmp*tmp%C*(B&1?A:1)%C;
}

int N,Q,Le,Ri,Ans1,Ans2,Ans3;
int Arr[111111],Start[111111],Count[111111],Tree[444444];

int Build(int Low,int High,int Pos){
    if(Low==High) return Tree[Pos]=Count[Low];
    return Tree[Pos]=max(Build(Low,Mid,2*Pos),Build(Mid+1,High,2*Pos+1));
}

int Query(int Low,int High,int Pos){
    if(Le<=Low&&High<=Ri) return Tree[Pos];
    if(Ri<Low||Le>High) return 0;
    return max(Query(Low,Mid,2*Pos),Query(Mid+1,High,2*Pos+1));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while(cin>>N){
        if(N==0) return 0;
        cin>>Q;
        for(int i=1;i<=N+1;++i){
            if(i<=N) cin>>Arr[i]; else Arr[N+1]=Arr[N]+1;
            if((i==1)||(Arr[i]!=Arr[i-1])){
                Start[i]=i;
                if(i!=1){
                    for(int j=Start[i-1];j<=i-1;++j){
                        Count[j]=i-Start[i-1];
                    }
                }
            } else {
                Start[i]=Start[i-1];
            }
        }
        Build(1,N,1);
        for(int i=1;i<=Q;++i){
            cin>>Le>>Ri;
            if(Arr[Le]==Arr[Ri]){
                cout<<Ri-Le+1<<endl;
            } else {
                Ans1=Start[Le]+Count[Le]-Le;
                Ans2=Ri-Start[Ri]+1;
                Le=Start[Le]+Count[Le];
                Ri=Start[Ri]-1;
                Ans3=Query(1,N,1);
                cout<<max(Ans1,max(Ans2,Ans3))<<endl;
            }
        }
    }
	return 0;
}


