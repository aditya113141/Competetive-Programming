// https://codeforces.com/contest/862/problem/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	
	vector<vector<ll>>vec(n);
	vector<ll>color(n,-1);
	
	for(int i=0;i<n-1;i++){
	    ll x,y;
	    cin >> x >> y;
	    x--;
	    y--;
	    vec[x].push_back(y);
	    vec[y].push_back(x);
	}
	
	for(int i=0;i<n;i++){
	    if(color[i]==-1){
	        color[i] = 0;
	        queue<ll>q;
	        q.push(i);
	        while(!q.empty()){
	            ll node = q.front();
	            q.pop();
	            
	            for(auto it:vec[node]){
	                if(color[it]==-1){
	                    color[it] = color[node]^1;
	                    q.push(it);
	                }
	                else if(color[it]==color[node]){
	                    cout << "Not a bipartite graph";
	                }
	            }
	        }
	    }
	}
	
	ll cnt0 = 0, cnt1 = 0;
	for(int i=0;i<n;i++){
	    if(color[i]==0){
	        cnt0++;
	    }
	    else cnt1++;
	}
	
	cout << (cnt0*cnt1-n+1) << endl;
	
	
}
