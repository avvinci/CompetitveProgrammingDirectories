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
ll ind,cnt,sz,sm,mx,mn;
ll a ,b ,ar[N] ,vis[N] ,arr[N];
vector< ll > g[N] ,v ; 
map< ll ,ll > cp ,rcp ,ans,mp; 


void dfs(int u ){

	if(vis[u]) return ; 
	vis[u] =1; 
	v.pb(u) ; 
	// ws(rcp[u]);
	// ws(x);
	if(mp.find(a - rcp[u]) == mp.end()) x = 1; 
	if(mp.find(b- rcp[u] ) == mp.end()) y = 1;
	for(auto it : g[u]) dfs(it) ; 
}


int main(){
INP

if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>a>>b;

fr(i,0,n){
	cin>>ar[i]; 
	arr[i] = ar[i] ; 
	mp[ar[i]] = 1; 
}
sort(ar,ar+n) ; 

fr(i,0,n) {
	rcp[i] = ar[i] ; 
	cp[ar[i]] = i ; 
}

fr(i,0,n){
	if(mp.find(a - ar[i]) != mp.end()){
		g[i].pb(cp[a-ar[i]]) ; 
		g[cp[a-ar[i]]].pb(i);
	}

	if(mp.find(b-ar[i]) != mp.end()){
		g[i].pb(cp[b-ar[i]]);
		g[cp[b-ar[i]]].pb(i) ; 
	}
}

fr(i,0,n){
	// ws(ar[i]);
	if(!vis[i]){

		v.clear() ;  
		x = 0; 
		y = 0 ; 
		dfs(cp[ar[i]]) ;
		fr(j,0,v.size()){
			if(x == 0 ) ans[rcp[v[j]]] = 0 ; 
			else if( y == 0 ) ans[rcp[v[j]]] = 1; 
			else
			{
				cout<<"NO" ; 
				return 0 ; 
			}
		}
		// cout<<"\n";
	}
}

cout<<"YES\n" ; 
fr(i,0,n) cout<<ans[arr[i]]<<" " ;  	




return 0 ;
}
