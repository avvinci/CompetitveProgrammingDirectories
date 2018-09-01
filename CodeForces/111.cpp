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

const long long infl = 1e13+5;

ll n,m,k,q,f,val,t,i,j;
ll ind,cnt,sz,sm,ans,mx,mn;
ll a[N][3] ,b[N][3] , x[N][3] , y[N][3] ;


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
fr(i,0,3){
	a[n+1][i] = a[0][i] = b[0][i] = b[n+1][i] = -infl ;
	x[0][i] = y[0][i] = x[n+1][i] = y[n+1][i] = infl ; 
}
fr(i,1,n+1){
	cin>>a[i][0]>>b[i][0]>>x[i][0]>>y[i][0] ; 
	a[i][1] = max(a[i][0], a[i-1][1]) ; 
	b[i][1] = max(b[i][0], b[i-1][1]) ;
	x[i][1] = min(x[i][0], x[i-1][1]) ;
	y[i][1] = min(y[i][0], y[i-1][1]) ; 
	
}

for(i=n;i>=1 ;i--){
	a[i][2] = max(a[i][0], a[i+1][2]) ; 
	b[i][2] = max(b[i][0], b[i+1][2]) ;
	x[i][2] = min(x[i][0], x[i+1][2]) ;
	y[i][2] = min(y[i][0], y[i+1][2]) ; 

	// cout<<a[i][2] <<" " <<b[i][2]<<" " <<x[i][2]<<" "<<y[i][2]<<"\n" ;
}

fr(i,1,n+1){
	// cout<<a[i-1][1] <<" " <<b[i-1][1]<<" " <<x[i-1][1]<<" "<<y[i-1][1]<<"\n" ;  
	if(max(a[i-1][1] ,a[i+1][2]) <= min(x[i-1][1] ,x[i+1][2]) &&  max(b[i-1][1] ,b[i+1][2]) <= min(y[i-1][1],y[i+1][2]) ){
		cout<<max(a[i-1][1] ,a[i+1][2])  <<" " <<  max(b[i-1][1] ,b[i+1][2]);
		return 0 ; 
	}
}


return 0 ;
}