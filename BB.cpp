
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define ll long long int
#define pll pair<ll,ll>
#define pii pair<int ,int>
// #define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define f first
#define s second
#define pb push_back
#define vpop pop_back
#define mod 1000000007  
#define all(a) a.begin(),a.end()
#define rep(i, sVal, j) for(ll i = sVal; i <= j; i++)
#define repr(i, sVal, j) for (ll i = sVal; i >= j; i--)
#define inf 1844674407370955000
#define ub upper_bound
#define lb lower_bound
#define mem1(X) memset((X),-1,sizeof((X)))
#define mem(a,b) memset((a),(b),sizeof(a))
#define endl "\n"    //--> Comment this for interactive problem.

//2,147,483,647 -> INT_MAX. 2147483647
//cout<<fixed<<setprecision(8)<<val<<endl;
//cout.flush();

ll mod_inv(ll a){
	ll p = mod-2,res = 1;
	while(p>0){
		if(p&1) res=(res*a)%mod;
		p=(p>>1);
		a=(a*a)%mod;
	}
	return res % mod;
}
void _swap(ll &a,ll &b){a=a^b;b=a^b;a=a^b;}

// ll fact[200001]; // must initialise fact.
// ll nCk(ll n, ll k) { 
// 	return ( (fact[n] * mod_inv(fact[k])) % mod * mod_inv(fact[n - k]) ) % mod; 
// }
ll _ceil_fun(ll a, ll b) { return a%b==0?a/b:(a/b+1);}
ll _pow_fun(ll b, ll p){
	if (p == 0)return 1;
	ll res = 1;
	while(p){if(p & 1){ res=(res*b); }b=(b*b); p=p/2;}
	return res;
}
ll _pow_fun_mod(ll b, ll p){
	if (p == 0) return 1; ll res = 1;
	while (p){if (p & 1LL){ res=(res*b)%mod;} b=(b*b)%mod; p=p/2;}
	return (res % mod);
}
ll _lcm(ll a, ll b){return (a * b)/__gcd(a, b);}
bool _isPrime(ll n){
	if (n == 1 ) return 0;
	if (n == 2 || n == 3) return 1;
	if ((n & 1) == 0) return 0;
	if (n % 3 == 0)return 0;
	for (ll i = 5; i * i <= n; i += 6){
		if (n % i == 0 || n % (i + 2) == 0) return 0;
	}
	return 1;
}
void _sieve(vector<int> &vec){
	int size = vec.size();
	vec[1] = 0;
	for (int i = 2; i < size; i++){
		if (vec[i] == -1){
			for (int  j = 2 * i; j < size; j += i){
					if (vec[j] == -1){
					vec[j]=1;
				}
			}
		}		
	}
}
ll _find(ll n,vll &par){
	if(par[n]==-1) return n;
	return par[n]=_find(par[n],par);
}
void _union(ll a,ll b,vll &par){
	ll ppa=_find(a,par);
	ll ppb=_find(b,par);
	if(ppa!=ppb){
		if(ppa>ppb)	par[ppb]=ppa;
		else par[ppa]=ppb;
	}
}
ll _log(ll n,ll b){
	if(b==1 || b==0) return n;
	ll res=0;
	while(n){
		res++;
		n/=b;
	} 
	return res-1;
} 
void google(int i) {cout<<"Case #"<<i<<": ";}
ll _mod(ll n){return n%mod;}

void solve() {
cout<<"BHELLO"<<endl;

} 		

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// int t=1;
	// cin>>t;
	// rep(i,1,t){
		
	// 	solve();
	// }
    solve();
	return 0;
}

// long long merge(int joke_a[], int temp[], int left, int mid, int right) {
//    int i, j, k;
//    long long count = 0;
//    i = left;
//    j = mid;
//    k = left;
//    while ((i <= mid - 1) && (j <= right)) {
//       if (joke_a[i] <= joke_a[j]){
//       temp[k++] = joke_a[i++];
//       } else {
//          temp[k++] = joke_a[j++];
//          count += (mid - i);
//       }
//    }
//    while (i <= mid - 1)
//       temp[k++] = joke_a[i++];
//    while (j <= right)
//       temp[k++] = joke_a[j++];
//    for (i=left; i <= right; i++)
//       joke_a[i] = temp[i];
//    return count;
// }
// long long mergeSort(int joke_a[], int temp[], int left, int right){
//    int mid;
//    long long count = 0;
//    if (right > left) {
//       mid = (right + left)/2;
//       count = mergeSort(joke_a, temp, left, mid);
//       count += mergeSort(joke_a, temp, mid+1, right);
//       count += merge(joke_a, temp, left, mid+1, right);
//    }
//    return count;
// }
// long long aInversion(int joke_a[], int n) {  // O(nlogn) me nikal deta he saare pairs joke_a[i]>joke_a[j] && i<j
//    int temp[n];
//    return mergeSort(joke_a, temp, 0, n - 1);
// }


    // set<ll> prime_arr;
	//   for(ll i=2;i<=1000000;i++){
    //       if(prime[i]==1){
	// 	      prime_arr.insert(i);	
	// 	  }
 
	//   }
     


//  prime[0]=prime[1]=0;
//         for(ll i=2;i*i<32000;i++){
//             if(prime[i]==1){
//                 for(int j=i*i;j<32000;j+=i){
//                     prime[j]=0;
//                 }
//             }
//         }



//  for(ll p=2;p<32000;p++){
// if(prime[p]==1){
// 	prime_nos.push_back(p);
// }
// }



    








// #define pll pair<ll,ll>
// #define pii pair<int ,int>

// #define vb vector<bool>
// #define vs vector<string>
// #define vll vector<ll>
// #define vpll vector<pll>
// #define vvll vector<vector<ll>>
// #define f first
// #define s second
// #define pb push_back
// #define vpop pop_back
// #define M 1000000007  
// #define all(a) a.begin(),a.end()
// #define loop(i, sVal, j) for(ll i = sVal; i <= j; i++)
// #define rloop(i, sVal, j) for (ll i = sVal; i >= j; i--)

// #define ub upper_bound
// #define lb lower_bound
// #define endl "\n"    

// ll mod_inv(ll a){
// 	ll p = M-2,res = 1;
// 	while(p>0){
// 		if(p&1) res=(res*a)%M;
// 		p=(p>>1);
// 		a=(a*a)%M;
// 	}
// 	return res % M;
// }
// void _swap(ll &a,ll &b){a=a^b;b=a^b;a=a^b;}

// // ll fact[200001]; // must initialise fact.
// // ll nCk(ll n, ll k) { 
// // 	return ( (fact[n] * mod_inv(fact[k])) % M * mod_inv(fact[n - k]) ) % M; 
// // }
// ll _ceil_fun(ll a, ll b) { return a%b==0?a/b:(a/b+1);}
// ll _pow_fun(ll b, ll p){
// 	if (p == 0)return 1;
// 	ll res = 1;
// 	while(p){if(p & 1){ res=(res*b); }b=(b*b); p=p/2;}
// 	return res;
// }
// ll _pow_fun_mod(ll b, ll p){
// 	if (p == 0) return 1; ll res = 1;
// 	while (p){if (p & 1LL){ res=(res*b)%M;} b=(b*b)%M; p=p/2;}
// 	return (res % M);
// }
// ll _lcm(ll a, ll b){return (a * b)/__gcd(a, b);}
// bool _isPrime(ll n){
// 	if (n == 1 ) return 0;
// 	if (n == 2 || n == 3) return 1;
// 	if ((n & 1) == 0) return 0;
// 	if (n % 3 == 0)return 0;
// 	for (ll i = 5; i * i <= n; i += 6){
// 		if (n % i == 0 || n % (i + 2) == 0) return 0;
// 	}
// 	return 1;
// }
// void _sieve(vector<int> &vec){
// 	int size = vec.size();
// 	vec[1] = 0;
// 	for (int i = 2; i < size; i++){
// 		if (vec[i] == -1){
// 			for (int  j = 2 * i; j < size; j += i){
// 					if (vec[j] == -1){
// 					vec[j]=1;
// 				}
// 			}
// 		}		
// 	}
// }
// ll _find(ll n,vll &par){
// 	if(par[n]==-1) return n;
// 	return par[n]=_find(par[n],par);
// }
// void _union(ll a,ll b,vll &par){
// 	ll ppa=_find(a,par);
// 	ll ppb=_find(b,par);
// 	if(ppa!=ppb){
// 		if(ppa>ppb)	par[ppb]=ppa;
// 		else par[ppa]=ppb;
// 	}
// }
// ll _log(ll n,ll b){
// 	if(b==1 || b==0) return n;
// 	ll res=0;
// 	while(n){
// 		res++;
// 		n/=b;
// 	} 
// 	return res-1;
// } 



// 		vector<ll> least_mult(N,-1); // least multiple of n

// for(ll j=2;j<N;j++){
// if(least_mult[j]==-1){
// for(ll j=j*2;j<N;j+=j){least_mult[j]=j;
//  }
// }
// }

// string s;
// cin>>s;
// string t;
// cin>>t;
// ll n=s.length();
// ll m=t.length();
// vector<ll> pos[26];
// for(ll j=0;j<n;j++){
// pos[s[j]-'a'].push_back(j);
// }


// ll ans=0;
// ll cur_pos=0;
// for(ll j=0;j<m;j++){

// ll cur=t[j]-'a';
// if(pos[cur].size()==0){
// 	cout<<-1<<endl;
// 	break;
// }

// auto it=lower_bound(pos[cur].begin(),pos[cur].end(),cur_pos);
// if(it==pos[cur].end()){
// ans++;
// cur_pos=0;
// j--;
// }
// else{
//   cur_pos=*it;
// }


// }

// cout<<ans<<endl;


// ll ask(ll low, ll high) {
//         if (low >= high) return -1;
//         cout << "? " << low  << ' ' << high  << endl;
//          ll ans;
//         cin >> ans;
//         return ans;
//     }
// const int N=1e5;
// vector<ll> prime(N,1);
//  prime[0]=prime[1]=0;
//         for(ll j=2;j*j<32000;j++){
//             if(prime[j]==1){
//                 for(int j=j*j;j<32000;j+=j){
//                     prime[j]=0;
//                 }
//             }
//         }



