// https://codeforces.com/contest/20/problem/C

#include <bits/stdc++.h>
#define ll long long
#define INF LLONG_MAX
using namespace std;

int main() {
	ll m,n;
	cin >> n >> m;
	
	vector<vector<pair<ll,ll>>>vec(n);
	
	for(int i=0;i<m;i++){
	    ll x,y,w;
	    cin >> x >> y >> w;
	    x--;
	    y--;
	    vec[x].push_back({y,w});
	    vec[y].push_back({x,w});
	}
	
	
	vector<ll>dis(n,INF);
	vector<ll>par(n,-1);
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0,0});
	dis[0] = 0;
	
	while(!pq.empty()){
	    
	    auto fron = pq.top();
	    pq.pop();
	    ll node = fron.second;
	    
	    for(auto it:vec[node]){
	        ll neigh = it.first;
	        ll cost = it.second;
	        
	        if(dis[node]+cost<dis[neigh]){
	            dis[neigh] = dis[node]+cost;
	            par[neigh] = node;
	            pq.push({dis[neigh],neigh});
	        }
	    }
	    
	    
	}
	
	if(dis[n-1]==INF){
	    cout << -1 << endl;
	}
	else{
	    vector<ll>ans;
	    ll temp = n-1;
	    while(par[temp]!=-1){
	        ans.push_back(temp+1);
	        temp = par[temp];
	    }
	    
	    ans.push_back(1);
	    reverse(ans.begin(),ans.end());
	    
	    for(auto it:ans) cout << it << " ";
	    cout << endl;
	}
	
	
	
	
}
