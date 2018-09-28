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
}
stack<ll > st ; 
ans =0 ; 
fr(i,0,n){
	while(!st.empty() && st.top() < a[i]){
		ans = max(ans , st.top() ^ a[i]) ; 
		st.pop() ; 
	}

	if(!st.empty())
		ans = max(ans , st.top() ^ a[i]) ; 
	st.push(a[i]) ; 
}
// ws(ans);
// while(!st.empty()) st.pop() ; 

// fr(i,0,n){
// 	while(!st.empty() && st.top() > a[i]){
// 		ans = max(ans , st.top() ^ a[i]) ; 
// 		st.pop() ; 
// 	}
	
// 	if(!st.empty())
// 		ans = max(ans , st.top() ^ a[i]) ; 
// 	st.push(a[i]) ; 
// }

cout<<ans;

return 0 ;
}
