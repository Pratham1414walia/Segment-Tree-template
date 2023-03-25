#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
#define ll long long int
#define endl "\n" 
const int N=505050;
ll parent[N];
ll SIZE[N];
multiset<ll> sizes;
 
void make(ll v){
   SIZE[v]=1;
	parent[v]=v;
//    sizes.insert(1);
}
 
ll find(ll v){
	if(v==parent[v]) return v;
	return parent[v]=find(parent[v]);
}
 
void merge(int a,int b){
sizes.erase(sizes.find(SIZE[a]));
sizes.erase(sizes.find(SIZE[b]));
sizes.insert(SIZE[a] + SIZE[b]);
}

void Union(ll a,ll b){
	
	a=find(a);
	b=find(b);
	if(a!=b){

   if(SIZE[a]<SIZE[b]){
	swap(a,b);
   }   
  parent[b]=a;
//    merge(a,b);
  SIZE[a] += SIZE[b];

}
 
return;
}


ll get_size(ll v){
	if(v==parent[v]) return SIZE[v];
	return get_size(parent[v]);
	
}



bool isCycle(vector<int> graph[],int parent,int source,vector<int> &vis){
    
   vis[source]=1;
   bool isCycleExist=false; 
//    cout<<source<<" "<<parent<<endl;
   for(auto child:graph[source]){
        if(child!=parent && vis[child]==1){
			// cout<<"HELLO"<<endl;
            return true;
        }
        if(vis[child]==0){
	    isCycleExist|=isCycle(graph,source,child,vis); 
		}
        // cout<<child<<" "<<source<<endl;
        
   } 
    
    return isCycleExist;
}



void solve(){
cout<<"hello"<<endl;
}


int main(){
ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

// ll t;
// cin>>t;
// while(t--){

// }
 solve();
	return 0;
}

// void dfs(ll source,vector<ll> adj[],vector<ll>&vis,ll &cycle_len,vector<ll> &recst,bool &cycle){

// cycle_len++;
// vis[source]=cycle_len;
// recst[source]=1;
// for(auto pr:adj[source]){
//  if(recst[pr]==1){
// 	vis[source]=cur_len-vis[pr] + 1;
// 	cycle=pr+1;
// 	return;
//  }
//  if(vis[pr]==1){
// 	vis[source]=vis[pr] + 1;
// 	return;
//  }  

//  if( vis[pr]==-1 ){
//    dfs(pr,adj,vis,cycle_len,recst,cycle);
//     if(cycle){
// 		vis[source]=vis[pr];
// 		if(cycle==pr+1){
// 			cycle=false;
// 		}
// 	}
// 	else{
// 		vis[source]=vis[pr]+1;
// 	}
//  }


// }

// recst[source]=0;

// }

// void solve(){
// ll n;
// cin>>n;
// vector<ll> vis(n,-1),v(n),ans(n,0),recst(n,0);
// vector<ll> adj[n];
// for(ll i=0;i<n;i++){
// 	ll x;
// 	cin>>x;
// 	x--;
//    adj[i].push_back(x);
// }

// for(ll i=0;i<n;i++){

//  if(vis[i]==-1){
//   ll cur_len=0;
//   dfs(i,adj,vis,cur_len,recst);
//  }

// }


// for(auto pr:vis){
// 	cout<<pr<<" ";
// }
// cout<<endl;

// }


// BIPARTITE GRAPH YES OR NO USING BFS


//bool bipartite_bfs(ll source,vector<ll> adj[] ,vector<ll> &color){

// queue<ll> q;
// q.push(source);
// color[source]=0;
// while(!q.empty()){
// ll cur_v=q.front();
// q.pop();
// for(auto pr:adj[cur_v]){

// 	if(color[pr]==-1){
// 		q.push(pr);
// 		color[pr]=!color[cur_v];
// 		}

// 	else if(color[pr]==color[cur_v]){
// 		return false;
// 	}	
// }


// }


// return true;
// }
 

// void solve(){
// ll n,m;
// cin>>n>>m;
// vector<ll > adj[n];
// for(ll i=1;i<=m;i++){
// 	ll u,v;
// 	cin>>u>>v;
// 	adj[u-1].push_back(v-1);
// 	adj[v-1].push_back(u-1);
// }
// vector<ll> color(n,-1);
// for(ll i=0;i<n;i++){
 
// if(color[i]==-1){
	
// bool comp_bip=bipartite_bfs(i,adj,color);
// if(comp_bip==false){
	
// 	cout<<"IMPOSSIBLE"<<endl;
// 	return;
// }


// }

// }

// for(auto pr:color){
// 	cout<<pr+1<<" ";
// }
// cout<<endl;

// }











// NO OF WAYS TO REACH SOURCE TO DESTINATION USING TOPOLOGICAL SORT AND DP

//void dfs(ll s,vector<ll> &vis,stack<ll> &st,vector<ll> adj[]){
//   vis[s]=1;
//   for(auto pr:adj[s]){
//  if(vis[pr]==0){
// 	dfs(pr,vis,st,adj);
//  }

//   }

// st.push(s);

// }
// void solve(){
// ll n,m;
// cin>>n>>m;
// vector<ll> adj[n];
// for(ll i=1;i<=m;i++){
// 	ll u,v;
// 	cin>>u>>v;
// 	adj[u-1].push_back(v-1);

// }
// ll source=0;
// ll destination=n-1;

// vector<ll>topo,dp(n,0),vis(n,0);
// stack<ll> st;

// dfs(0,vis,st,adj);
// // dp[i]= no of ways of going from n t0 i vertex in a graph
// dp[destination] = 1;
// while(!st.empty()){

//  topo.push_back(st.top());
// 	st.pop();
// }
// for(ll i=topo.size()-1;i>=0;i--){

// ll parent=topo[i];
// for(auto child:adj[parent]){
// 	dp[parent] = dp[parent] + dp[child];
// 	dp[parent]=dp[parent]%mod;
// }

// }


// cout<<dp[source]<<endl;

// }




// BELLMAN FORD FOR NEGATIVE CYCLE CHECK AND PRINT CYCLE AS WELL

//void dfs(ll source,vector<ll> &ans,map<ll,ll> &vis,map<ll,ll>  &recst,map<ll,vector<ll>> &graph,vector<ll> &cur){
// vis[source]=1;
// recst[source]=1;
// cur.push_back(source);
// for(auto pr:graph[source]){
//  if(recst[pr]==1 && ans.size()==0){
//     ans.push_back(pr);
//     ll pos=cur.size()-1;
//     while(pos>=0 && cur[pos]!=pr){
//         ans.push_back(cur[pos]);
//         pos--;
//     } 
//     ans.push_back(pr);
//  }
//  if(vis[pr]==0){
//    dfs(pr,ans,vis,recst,graph,cur);
//  }
 
 
// }
 
 
// recst[source]=0;
// cur.pop_back();
// }
 
 
//  void solve(){
//     ll n,m;
//     cin>>n>>m;
// vector<vector<ll>> graph;
// for(ll i=1;i<=m;i++){
//   ll u,v,wt;
//   cin>>u>>v>>wt;
//   vector<ll> temp={u-1,v-1,wt};
//   graph.push_back(temp);
// }
 
// vector<ll> dist(n,1e10);
// dist[0]=0;
// for(ll count =0 ;count<n-1;count++){
//     for(auto &pr:graph){
//         if(dist[pr[1]]>dist[pr[0]] + pr[2]){
//            dist[pr[1]]=dist[pr[0]] + pr[2];
//         }
//     }
// }
 
// bool cycle_he=false;
// // for(int i=0;i<n;i++){
// //     cout<<i+1<<"   "<<dist[i]<<endl;
// // }
// map<ll,vector<ll>> m1;
// map<ll,ll>visited,recst;
// for(auto &pr:graph){
// // 	4 5
// // 1 2 1        // for this condition  dist[pr[1]]==dist[pr[0]] + pr[2] && pr[2]<0
// // 2 4 1
// // 3 1 1
// // 4 1 -3
// // 4 3 -2


//         if(dist[pr[1]]>dist[pr[0]] + pr[2] ||(dist[pr[1]]==dist[pr[0]] + pr[2] && pr[2]<0)){
//            dist[pr[1]]=dist[pr[0]] + pr[2];
//            cycle_he=true;
//            m1[pr[0]].push_back(pr[1]);
//            visited[pr[0]]=0;
//            visited[pr[1]]=0;
//            recst[pr[0]]=0;
//            recst[pr[1]]=0;
//         }
//     }
 
//  // 
//  // 1  2  -8
//  // here it will give only when ans.size =0 i.e there is no cycle

// vector<ll> ans,cur;
// for(auto pr:visited){
//  if(visited[pr.first]==0){
//     dfs(pr.first,ans,visited,recst,m1,cur);
//  }
 
// }

// if(ans.size()==0 || cycle_he==false){
//     cout<<"NO"<<endl;
//     return;
// }
// cout<<"YES"<<endl;
// reverse(ans.begin(),ans.end());
// for(auto pr:ans){
//     cout<<pr+1<<" ";
// }
// cout<<endl;
 
 
//  }
 








// Detect and PRINT CYCLE IN DIRECTED GRAPH
 
 
// void dfs(ll source,vector<ll> &ans,vector<ll> &vis,vector<ll> &recst,vector<ll> graph[],vector<ll> &cur){
// vis[source]=1;
// recst[source]=1;
// cur.push_back(source);
// for(auto pr:graph[source]){
//  if(recst[pr]==1 && ans.size()==0){
//     ans.push_back(pr);
//     ll pos=cur.size()-1;
//     while(pos>=0 && cur[pos]!=pr){
//         ans.push_back(cur[pos]);
//         pos--;
//     } 
//     ans.push_back(pr);
//  }
//  if(vis[pr]==0){
//    dfs(pr,ans,vis,recst,graph,cur);
//  }
 
 
// }
 
 
// recst[source]=0;
// cur.pop_back();
// }
 
// void solve(){
// ll n,m;
// cin>>n>>m;
// vector<ll> graph[n];
// for(ll i=1;i<=m;i++){
//     ll u,v;
//     cin>>u>>v;
//     graph[u-1].push_back(v-1);
// }
 
// vector<ll> ans,vis(n,0),recst(n,0),cur;
// for(ll i=0;i<n;i++){
//     if(vis[i]==0){
//      dfs(i,ans,vis,recst,graph,cur);
//     }
// }
 
 
// if(ans.size()==0){
//     cout<<"IMPOSSIBLE"<<endl;
//     return;
// }
 
// cout<<ans.size()<<endl;
// reverse(ans.begin(),ans.end());
// for(auto pr:ans){
//     cout<<pr+1<<" ";
// }
// cout<<endl;
// }
 
 
 
 
 
 
 
 
 
 
// DETECT AND PRINT CYCLE IN AN UNDIRECTED GRAPH
 
//void dfs(ll source,ll parent,vector<ll> &vis,vector<ll> adj[],vector<ll> &cur_track,bool &milgya,vector<ll> &ans){
//   vis[source]=1;
// cur_track.emplace_back(source);
// for(auto pr:adj[source]){
//  if(vis[pr]==0){
// 	dfs(pr,source,vis,adj,cur_track,milgya,ans);
//  }
//  else if(vis[pr]==1){
//    if(pr!=parent){
 
// 	if(milgya==false){
// 	milgya=true;
	
// 	ans.push_back(pr);
// 	ll pos=cur_track.size();
// 	pos--;
// 	while(pos>=0 && cur_track[pos]!=pr){
// 	ans.push_back(cur_track[pos]);
// // 		cout<<cur_track[pos]<<endl;
// 		pos--;
// 	}
//          ans.push_back(pr);
// 	}
 
	
//    }
 
 
 
//  }
 
 
 
// }
// vis[source]=2;
// cur_track.pop_back();
 
// }
 
// void solve(){
//  ll n,m;
//  cin>>n>>m;
//  vector<ll> vis(n+1,0);
//  vector<ll> adj[n+1];
//  for(ll i=1;i<=m;i++){
// 	ll u,v;
// 	cin>>u>>v;
// 	adj[u].push_back(v);
// 	adj[v].push_back(u);
//  } 
// bool milgya=false;
// vector<ll> ans;
// vector<ll> cur_track;
//  for(ll i=1;i<=n;i++){
//   if(vis[i]==0){
// 	dfs(i,-1,vis,adj,cur_track,milgya,ans);
//   }
 
//  }
 
//  if(milgya==false){
 
// 	cout<<"IMPOSSIBLE"<<endl;
//     return;
//  }
 
 
 
// cout<<ans.size()<<endl;
// for(ll i=0;i<ans.size();i++){
// 	cout<<ans[i]<<" ";
// }
// cout<<endl;
 
// }
 
 
 
// DIJKSTRA ALGROTIHM WITH PATH PRINTING ALSO
// ll n,m;
// cin>>n>>m;
// vector<pair<ll,ll>>adj[n+1];
// for(ll i=1;i<=m;i++){
// 	ll u,v;
// 	cin>>u>>v;
// 	adj[u].push_back({v,1});	
// 	adj[v].push_back({u,1});	
// }
// vector<ll> vis(n+1,0);
// vector<ll> dist(n+1,1e11);
// set<pair<ll,ll>> st;
// st.insert({0,1});
// dist[1]=0;
// vector<ll> parent(n+1,0);
// for(ll i=1;i<=n;i++){
// 	parent[i]=i;
// }
// while(st.size()>0){
// auto it=*st.begin();
// st.erase(st.begin());
// ll cur_v=it.second;
// if(vis[cur_v]==1)continue;
 
// vis[cur_v]=1;
// for(auto pr:adj[cur_v]){
// 	ll child=pr.first;
// 	ll wt=pr.second;
//   if(dist[child]>dist[cur_v] + wt ){
//    dist[child]=dist[cur_v]+wt;
//    st.insert({dist[child],child});
//    parent[child]=cur_v; 
//     }
 
// }
 
 
 
// }
 
// if(dist[n]==1e11){
// 	cout<<"IMPOSSIBLE"<<endl;
// 	return;
// }
// vector<ll> path;
// ll cur_node=n;
// while(parent[cur_node]!=cur_node){
// 	path.push_back(cur_node);
// 	cur_node=parent[cur_node];
// }
 
// path.push_back(1);
// reverse(path.begin(),path.end());
// cout<<path.size()<<endl;
// for(auto pr:path){
// 	cout<<pr<<" ";
// }
// cout<<endl;
 
 
 
// FLOOD WARSHAL
 
// ll n,m,q;
// cin>>n>>m>>q;
// vector<vector<ll>> dist(n+1,vector<ll> (n+1,1e17));
// for(ll i=1;i<=n;i++){
// 	dist[i][i]=0;
// }
 
// for(ll i=1;i<=m;i++){
// 	ll u,v,wt;
// 	cin>>u>>v>>wt;
// 	dist[u][v]=min(dist[u][v],wt);
// 	dist[v][u]=min(dist[v][u],wt);
// }
 
// for(ll k=1;k<=n;k++){
 
//   for(ll i=1;i<=n;i++){
//     for(ll j=1;j<=n;j++){
//       if(dist[i][k]!=1e17 && dist[k][j]!=1e17){
// 		dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
// 		dist[j][i]=dist[i][j];
// 	  }
 
       
// 	}
    
//   }
 
// }
 
// while(q--){
// ll start,end;
// cin>>start>>end;
// if(dist[start][end]==1e17){
// 	cout<<-1<<endl;
	
// }
// else{
// cout<<dist[start][end]<<endl;
// }
 
 
// }
 
 
 
 
 
// topological sort
 
    //    int n,m;
	//    cin>>n>>m;
	//    vector<int> adj[n];
	//    for(ll i=0;i<m;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	adj[u-1].push_back(v-1);
	//    }   
    //   vector<int> topo,indeg(n,0);
	//    for(int i=0;i<n;i++){
	// 	for(auto pr:adj[i]){
	// 		indeg[pr]++;
	// 	}
	//    }  
	//    queue<int> q;
    //    for(ll i=0;i<n;i++){
	// 	if(indeg[i]==0){
	// 		q.push(i);
	// 	}
	//    }
 
	// while(!q.empty()){
    //     int cur_v=q.front();
	// 	q.pop(); 
    //     topo.push_back(cur_v); 
    //     for(auto pr:adj[cur_v]){
	// 		indeg[pr]--;
	// 		if(indeg[pr]==0){
	// 			q.push(pr);
	// 		}
	// 	}
          
	// }	
    // if(topo.size()!=n){
	// 	cout<<"IMPOSSIBLE"<<endl;
	// } 
	// else{
	// 	for(auto pr:topo){
	// 		cout<<pr+1<<" ";
	// 	}
	// 	cout<<endl;
	// }
 
  
// BELLMAN FORD ALGORITHM
 
// ll n,m;
// cin>>n>>m;
// vector<vector<ll>> graph;
// for(ll i=1;i<=m;i++){
//   ll u,v,wt;
//   cin>>u>>v>>wt;
//   vector<ll> temp={u-1,v-1,wt};
//   graph.push_back(temp);
// }
 
// vector<ll> dist(n,1e15),vis(n,0);l
// dist[0]=0;
// for(ll count=0;count<n-1;count++){
// 	for(auto &pr:graph){
// 		if(dist[pr[1]]>dist[pr[0]] + pr[2]){
// 			dist[pr[1]]=dist[pr[0]] + pr[2];
// 		}
// 	}
// }
// if(dist[n-1]==1e15){cout<<-1<<endl;return; }
// cout<<dist[n-1]<<endl;