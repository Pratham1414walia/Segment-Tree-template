#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n" 
const long long mod = 1000000007;
#define all(a)        a.begin(),a.end()

ll ceil_fun(ll a, ll b) {return (a + b - 1) / b;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}

//   vector<ll> fact(1003,1);

// 	 for(ll j=1;j<=1000;j++){
//        fact[j]=(fact[j-1]*j*1ll)%mod;
// 	 }
ll sum_digit(ll n){
	ll tp=n;
	ll ans=0;
	while(tp>0){
ans+=(tp%10);
		tp/=10;
	}
return ans;
}





void solve(){

}

int main(){
  
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
  
	ll t;
	cin>>t;
	
	for(ll T=1;T<=t;T++){
        // cout<<"Case #"<<T<<": ";

	solve();
	}

	// solve();
	return 0;
}
