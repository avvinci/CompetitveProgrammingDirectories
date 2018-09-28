// avvinci -  summers 18    
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long > P;

#define mod 998244353 
#define pb push_back
#define fs first
#define sc second
#define ll long long 
#define fr(it,st,en) for(it=st;it<en;it++)
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl;
#define N 1004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t,i,j;
ll ind,cnt,sz,sm,ans,mx,mn;
ll dp[N][N+N][5];

ll rec(int n ,int k ,int st){

	if(k < 0 ) return 0 ; 
	if(n == 0){
		if(k == 1 ){
			if(st < 1) return 1 ; 
		}
		if( k == 2) {
			if(st > 1) return 1 ; 
		}
		return  0; 
	}
	 
	if(dp[n][k][st] != -1 ) return dp[n][k][st] ; 

	ll ans = 0 ; 
	ans += rec(n-1,k,st) ;   ans %= mod; 


	if(st < 2 ){
		ans += rec(n-1,k-2,1-st) ;  ans %= mod; 
		ans += rec(n-1,k-1,2) ;  ans %= mod; 
		ans += rec(n-1,k-1,3) ;  ans %= mod; 
	}
	else{
		ans += rec(n-1,k-1,0) ;  ans %= mod; 
		ans += rec(n-1,k-1,1) ;  ans %= mod; 
		if(st == 2)
			ans += rec (n-1,k-2,3) ;
		else
			ans += rec(n-1,k-2,2)  ; 

		 ans %= mod; 
	}
	dp[n][k][st] = ans ; 
	return ans; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>k ; 
if(n == 1) {
	cout<<"2" ;
	return 0 ; 
}

memset(dp,-1, sizeof(dp)) ; 
ans = 0 ; 
ans += rec(n-1,k,1) ; ans %= mod; 
ans += rec(n-1,k,2) ; ans %= mod; 
ans += rec(n-1,k,3) ; ans %= mod; 
ans += rec(n-1,k,0) ; ans %= mod; 
cout<<ans ; 













return 0 ;
}
