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
#define N 5004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t,i,j;
ll ind,cnt,sz,sm,ans,mx,mn;
ll a[N] ;
vector<ll> g[N] ; 
vector<P> v ; 

void dfs(int u){
	if(a[u]){
		return ; 
	}
	a[u] = 1; 
	cnt++;
	for(auto it : g[u]){
		dfs(it) ; 
	}
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>m>>k;
fr(i,0,m){
	cin>>x>>y;
	g[x].pb(y);
}

fr(i,1,n+1){
	dfs(i) ; 
	v.pb(cnt,i) ; 
	cnt = 0  ; 
	memset(a,0,sizeof(a)) ; 
}

sort(all(v)) ; 
reverse(all(v)) ; 
dfs(k);
fr(i,0,v.size()){
	x = v[i].sc ;
	if(a[x] ) continue; 
	// ws(x);
	if(x != k)
	ans++; 
	dfs(x) ; 

}

cout<<ans;
return 0 ;
}
