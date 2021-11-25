// https://codeforces.com/contest/295/problem/A

#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
int main() {
	ll n;
	cin >> n;
	ll mat[n][n];
	
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> mat[i][j];
	
	ll x[n];
	for(int i=0;i<n;i++) {
	    cin >> x[i];
	    x[i]--;
	}
	stack<ll>st;
	for(int k=n-1;k>=0;k--){
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(mat[x[i]][x[j]]>mat[x[i]][x[k]]+mat[x[k]][x[j]]){
	                mat[x[i]][x[j]] = min(mat[x[i]][x[k]] + mat[x[k]][x[j]],mat[x[i]][x[j]]);
	            }
	        }
	    }
	    
	    ll cnt = 0;
	    
	    for(int i=n-1;i>=k;i--){
	        for(int j=n-1;j>=k;j--){
	            cnt+=mat[x[i]][x[j]];
	        }
	    }
	    
	    st.push(cnt);
	    
	}
	
	while(!st.empty()){
	    cout << st.top() << " ";
	    st.pop();
	}
	
	
}
