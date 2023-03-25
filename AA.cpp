#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define endl "\n" 
const long long mod = 1000000007;
#define pb push_back
ll gcd(ll joke_a, ll joke_b){if (joke_b == 0)return joke_a;return gcd(joke_b, joke_a % joke_b);}
int lcm(ll joke_a, ll joke_b){return (joke_a * joke_b) / gcd(joke_a, joke_b);}
ll bin_exp_mod(ll joke_a,ll joke_b){ll result=1;if(joke_a==0){return 0;}while(joke_b>0){if(joke_b&1){result=(result*joke_a*1LL)%mod;}joke_a=(joke_a*joke_a*1LL)%mod;joke_b=joke_b>>1;}return result;}
ll bin_exp(ll joke_a,ll joke_b){ll result=1;if(joke_a==0){return 0;}while(joke_b>0){if(joke_b&1){result=(result*joke_a*1LL);}joke_a=(joke_a*joke_a*1LL);joke_b=joke_b>>1;}return result;}
ll reverse(ll n){ll r=0;while(n>0){r=r*10 + n%10;n=n/10; }return r;}
#define all(joke_a)        joke_a.begin(),joke_a.end()
 
bool is_prime(ll n){if (n == 1 ) return 0;if (n == 2 || n == 3) return 1;if ((n & 1) == 0) return 0;	if (n % 3 == 0)return 0;for (ll start = 5; start * start <= n; start += 6){if (n % start == 0 || n % (start + 2) == 0) return 0;}return 1;}
 
 
void _swap(ll &joke_a,ll &joke_b){joke_a=joke_a^joke_b;joke_b=joke_a^joke_b;joke_a=joke_a^joke_b;}

// unordered_map<int,int>m1;
// ll divisors_lesstime(ll n){
// 	if(m1[n]>0){
// 		return m1[n];
// 	}
// 	ll steps=0;for(ll start=1;start*start<=n;start++){if(n%start==0){if(n/start==start){steps++;}else{steps+=2;}}}
//        m1[n]=steps;
// 	return steps;}
 
ll divisors_moretime(ll n){ll steps=0;for(ll start=1;start*start<=n;start++){if(n%start==0){if(n/start==start){steps++;}else{steps+=2;}}}return steps;}
 
ll digits_sum( ll n){ll sum=0;while(n>0){sum+=(n%10);n=n/10;}return sum;}
 

struct cmp {
	bool operator() (const pair<int, int> &joke_a, const pair<int, int> &joke_b) const {
		int lena = joke_a.second - joke_a.first + 1;
		int lenb = joke_b.second - joke_b.first + 1;
		if (lena == lenb) return joke_a.first < joke_b.first;
		return lena > lenb;
	}
};

	   vector<ll> prime(32000,1);
vector<ll> prime_nos; 
bool square_check(ll n){
  
 ll x=sqrt(n);
 
 return (x*x)==n;
} 
ll ceil_fun(ll joke_a, ll joke_b) {
    return (joke_a + joke_b - 1) / joke_b;
}
bool is_pal(string s){if(s.length()==0)return true;ll start=0;ll end=s.length()-1;while(start<=end){if(s[start]!=s[end]){return false;} start++;end--;}return true;} 
 
 ll sq_root(ll x){
 ll low=1;
 ll high=1e9;
 ll result=0;
 while(low<=high){
  ll mid=(low+high)/2;
   if((mid*mid)>x){
   high=mid-1;
   }
    else{
		low=mid+1;
		result=mid;
	}


 }

	return result;
 }

ll fact(ll n){
	ll result=1;
	for(ll start=1;start<=n;start++){
		result=result*start;
 
	}
	return  result;
}

ll sum_digit(ll n){
	ll res=0;
	while(n>0){
		res+=(n%10);
		n/=10;
	}
	return res;
}
void solve(){
ll n;
cin>>n;
vector<ll> v(n);
for(ll i=0;i<n;i++){
	cin>>v[i];
}

sort(all(v));
if(v[0]!=1){
	cout<<"NO"<<endl;
	return;
}
ll cur=1;
for(ll i=1;i<n;i++){
if(v[i]<=cur){
	cur+=v[i];
	continue;
}
else{
	cout<<"NO"<<endl;
	return;
}
}

cout<<"YES"<<endl;


}


int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	ll test;
	cin>>test;
	
	for(ll T=1;T<=test;T++){
        // cout<<"Case #"<<T<<": ";	

		solve();
	}
	// solve();
	return 0;
}
