#include<bits/stdc++.h>
using namespace std;
#define ll long long int
stringstream ss;
const int N=200008;

//lazy propagation template
vector<ll> seg(4*N,-1);
vector<ll> lazy(4*N,0);
void build(ll ind,ll low,ll high,vector<ll> &nums){
    if(low==high){
        seg[ind]=nums[low];
        return ;
    }
    ll mid=(low+high)/2;
    build(2*ind+1,low,mid,nums);
    build(2*ind+2,mid+1,high,nums);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

ll query(ll ind ,ll low, ll high,ll l,ll r){
  
    if(lazy[ind]!=0){
seg[ind]+=(high-low+1)*lazy[ind];
 if(low!=high){// no leaf node
    lazy[2*ind+1]+=lazy[ind];
    lazy[2*ind+2]+=lazy[ind];
 } 
 lazy[ind]=0;
} 
// no overlap
    if(r<low || l>high)return INT_MAX ;

    if(l<=low && high<=r){
      return seg[ind];
    }

    ll mid=(low+high)/2;
    ll left=query(2*ind+1,low,mid,l,r);
    ll right=query(2*ind+2,mid+1,high,l,r);
return min(left,right);
}



void update(ll ind,ll low,ll high,ll l,ll r,ll value){

if(lazy[ind]!=0){
seg[ind]+=(high-low+1)*lazy[ind];
 if(low!=high){
    lazy[2*ind+1]+=lazy[ind];
    lazy[2*ind+2]+=lazy[ind];
 } 
 lazy[ind]=0;

}

//no overlap
if(r<low || l>high)return ;


// complete overlap
if(l<=low && high<=r){
 seg[ind]+=(high-low+1)*value;
 if(low!=high){
    lazy[2*ind+1]+=value;
    lazy[2*ind+2]+=value;
 } 
 return ;
}

// partial overlap
ll  mid=(low+high)/2;
update(2*ind+1,low,mid,l,r,value);
update(2*ind+2,mid+1,high,l,r,value);
 seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}


// void solve(){
// ll n,m;
// cin>>n>>m;
// vector<ll> v(n);
// for(ll i=0;i<n;i++){
//     cin>>v[i];
// }
// build(0,0,n-1,v);
// // for(ll i=0;i<=12;i++){
// //     cout<<seg[i]<<" ";
// // }
// // cout<<endl;

// for(ll i=0;i<m;i++){
//     ll type;
//     cin>>type;
//    if(type==2){
//  ll k;
//  cin>>k;
//  ll ans=query(0,0,n-1,k-1,k-1);
//  cout<<ans<<endl;
//    }
//    else{
//     ll l,r;
//     cin>>l>>r;
//     ll value=0;
//     update(0,0,n-1,l-1,r-1,value);
//    }  
// }

// }


int main(){

     
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
  cin >> v[i];
    }
      
    build(0,0,n-1,v);
    ll m;
    cin>>m;
    ll l, r, w;
    string s;
    getline(cin, s);
    while(m--)
    {
        ss.clear();
        ss.str("");
        getline(cin, s);
        ss.str(s);
        ss >> l >> r;
        if(ss >> w){
            if(l > r){
                ll value=w;
                update(0,0,n-1,l,n-1,value);
                update(0,0,n-1,0,r,value);
            }
            else
            { ll value=w;
                update(0,0,n-1,l,r,value);
            }
        }
        else
        {
            ll res = 1e9;
            if(l > r){
                res = min(res, query(0, 0,n-1,l,n-1));
                res = min(res, query(0, 0,n-1,0, r));
            }
            else{
                res = query(0,0,n-1,l, r);
            }
            cout << res << endl;
        }
    }
// solve();
return 0;
}


// const int N=1e6;
// vector<ll> seg(N,-1);
// void build(ll ind,ll low,ll high,vector<ll> &v){
// if(low==high){
//     seg[ind]=v[low];
//     return;
// }
// ll mid=(low+high)/2;
// build((2*ind)+1,low,mid,v);
// build((2*ind)+2,mid+1,high,v);
// seg[ind]=min(seg[(2*ind)+1],seg[(2*ind)+2]);
// }

// ll query(ll ind,ll low,ll high,ll l,ll r){
//    // no overlap 
// if(r<low || l>high){
// return INT_MAX;
// }
// // complete overlap
// if(low>=l && high<=r){
// return seg[ind];
// }
// // partial overlap go to both left node and right node
// ll mid=(low+high)/2;
// ll left=query((2*ind)+1,low,mid,l,r);
// ll right=query((2*ind)+2,mid+1,high,l,r);
//  return min(left,right);
// }

// void update(ll ind,ll low,ll high,ll pos,ll value){
// if(low==high){
//     seg[ind]=value;
//     return ;
// }
// ll mid=(low+high)/2;
// if(pos<=mid){
// update((2*ind)+1,low,mid,pos,value);
// }
// else{
// update((2*ind)+2,mid+1,high,pos,value);
// }
// seg[ind]=min(seg[(2*ind)+1],seg[(2*ind)+2]);
// }
// void solve(){
// ll n,m;
// cin>>n>>m;
// vector<ll> v(n);
// for(ll i=0;i<n;i++){
//     cin>>v[i];
// }
// build(0,0,n-1,v);
// // for(ll i=0;i<14;i++){
// //     cout<<seg[i]<<" ";
// // }
// // cout<<endl;

// for(ll i=0;i<m;i++){
//     ll type;
//     cin>>type;
//    if(type==2){
//     ll l,r;
//     cin>>l>>r;
//  cout<<query(0,0,n-1,l-1,r-1)<<endl;
//    }
//    else{
//     ll pos,value;
//     cin>>pos>>value;
//     update(0,0,n-1,pos-1,value);
//    }
   
// }

// }



// lazy propagation template
// vector<ll> seg(N,-1);
// // vector<ll> lazy(N,0);
// void build(ll ind,ll low,ll high,vector<ll> &nums){
//     if(low==high){
//         seg[ind]=nums[low];
//         return ;
//     }
//     ll mid=(low+high)/2;
//     build(2*ind+1,low,mid,nums);
//     build(2*ind+2,mid+1,high,nums);
//     seg[ind]=seg[2*ind+1]+seg[2*ind+2];
// }

// ll query(ll ind ,ll low, ll high,ll l,ll r){
//     // no overlap
// //     if(lazy[ind]!=0){
// // seg[ind]+=(high-low+1)*lazy[ind];
// //  if(low!=high){// no leaf node
// //     lazy[2*ind+1]+=lazy[ind];
// //     lazy[2*ind+2]+=lazy[ind];
// //  } 
// //  lazy[ind]=0;
// // }
//     if(r<low || l>high)return 0 ;

//     if(l<=low && high<=r){
//       return seg[ind];
//     }

//     ll mid=(low+high)/2;
//     ll left=query(2*ind+1,low,mid,l,r);
//     ll right=query(2*ind+2,mid+1,high,l,r);
// return left+right;
// }



// void update(ll ind,ll low,ll high,ll l,ll r,ll value){
// // no overlap
// // if(lazy[ind]!=0){
// // seg[ind]+=(high-low+1)*lazy[ind];
// //  if(low!=high){
// //     lazy[2*ind+1]+=lazy[ind];
// //     lazy[2*ind+2]+=lazy[ind];
// //  } 
// //  lazy[ind]=0;

// // }


// if(r<low || l>high)return ;


// // complete overlap
// if(l<=low && high<=r){
//  seg[ind]+=(high-low+1)*value;
// //  if(low!=high){
// //     lazy[2*ind+1]+=value;
// //     lazy[2*ind+2]+=value;
// //  } 
//  return ;
// }

// // partial overlap
// ll  mid=(low+high)/2;
// update(2*ind+1,low,mid,l,r,value);
// update(2*ind+2,mid+1,high,l,r,value);
//  seg[ind]=seg[2*ind+1]+seg[2*ind+2];

// }
