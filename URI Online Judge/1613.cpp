#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
int tc,P,G,Ans;
double m1,m2,m3,Ex,Ey,x,y;
vector<pair<double,double> > Wall;
vector<double> Grad;
int Binser1(double x){
    int le=0,ri=G-1,mid,save=-1;
    while(le<=ri){
        mid=(le+ri)/2;
        if(x>Grad[mid]){
            save=mid;
            le=mid+1;
        } else {
            ri=mid-1;
        }
    }
    return save;
}
int Binser2(double x){
    int le=0,ri=G-1,mid,save=-1;
    while(le<=ri){
        mid=(le+ri)/2;
        if(x>=Grad[mid]){
            save=mid;
            le=mid+1;
        } else {
            ri=mid-1;
        }
    }
    return save;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
        Wall.clear(); Grad.clear();
        cin>>Ex>>Ey; Ans=0;
        cin>>P;
        for(int i=0;i<P;++i){
            cin>>x>>y;
            x=(Ey-x)/Ex;
            y=(Ey-y)/Ex;
            if(x>y) swap(x,y);
            Wall.push_back({x,y});
        }
        cin>>G;
        for(int i=0;i<G;++i){
            cin>>x>>y;
            Grad.push_back((Ey-y)/(Ex-x));
        }
        sort(Grad.begin(),Grad.end());
        for(auto i:Wall){
            Ans+=Binser1(i.sc)-Binser2(i.fs);
        }
        cout<<Ans<<'\n';
    }
}
