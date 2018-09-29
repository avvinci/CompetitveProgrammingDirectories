// avvinci -  summers 18    
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long > P;

#define mod 1000000007 
#define pb emplace_back
#define fs first
#define sc second
#define ll long long 
#define fr(it,st,en) for(it=st;it<en;it++)
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl;
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t,i,j;
ll ind,cnt,sz,sm,ans,mx,mn;
ll a[N] ,tr[N];
vector<ll > v ; 

void upd(ll x ){
	while(x < N){
		tr[x]++ ; 
		x += (x & -x) ; 
	}
}

ll get(ll x ){
	ll res = 0 ;
	while(x > 0 ) {
		res += tr[x] ; 
		x -= (x & -x) ; 
	}
	return res; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>k;

v.pb(0) ; 
fr(i,0,n){
	cin>>a[i] ; 
	x += a[i] ; 
	v.pb(x) ;  
} 
sort(all(v)) ; 
auto it = unique (v.begin(), v.end()); 
v.resize(distance(v.begin(),it) ) ; 
// ws(v) ; 

sm = 0;
it = lower_bound(all(v), sm) ; 
upd(1 + (it - v.begin()) ) ; 
fr(i,0,n){
	sm += a[i] ; 
	val = sm - k ; 
	auto it  = lower_bound(all(v) , val ) ; 
	if(*it == val ){
		y = get(1 + it -v.begin()) ; 
		ans += i+1 - y ; 
	}
	else if( it == v.begin()) {
		ans += i+1; 
	}
	else {
		it-- ; 
		y = get(1 + it -v.begin()) ; 
		ans += i+1 - y ; 
	}
	it = lower_bound(all(v), sm) ; 
	upd(1 + (it - v.begin()) ) ; 
}



cout<<ans ; 

return 0 ;
}
