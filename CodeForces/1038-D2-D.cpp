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
ll a[N] ;


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
fr(i,0,n){
	cin>>a[i] ; 
	if(a[i] < 0 ) cnt++ ; 
	sm += abs(a[i]) ; 
	// if(a[i] == a[i-])
}


if(n == 1) {
	cout<<a[0] ; 
	return 0 ; 
}
if(cnt > 0 && cnt < n ) {
	cout<<sm;
	return 0 ;  
}

ans = -infl ; 
fr(i,1,n){
	if(a[i] == a[i-1]) cnt++; 
	else cnt = 0 ; 

		val = sm - abs(a[i]) - abs( a[i-1]) ; 
		val += abs(a[i] - a[i-1]) ; 
		ans = max(ans,val)  ; 
	}


cout<<ans; 


return 0 ;
}
