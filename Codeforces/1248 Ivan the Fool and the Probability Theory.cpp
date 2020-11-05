#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define ip pair<ll,ll>
#define vii vector<ll>
#define vpp vector<ip>
#define vdd vector<ld>
#define vb vector<bool>
#define pi  pair<ll,ip>
#define sc(x) scanf("%lli",&x)
#define hu 200010
#define pq priotity_queue<ll>
#define pqs priority_queue<ll,vii,greater<ll>>
#define ppq priority_queue<ip,vpp,greater<ip>>
#define INF INT_MAX
#define ff first
#define ss second
#define fo(i,k,n) for(ll i=k;i<n;i++) 
using namespace std;

const ll M = 1e9 + 7;
int main() {
    
    ll n,m;
    cin >> n >> m;
    ll arr[max(n,m)+6];
    
	arr[0] = 1;
	arr[1] = 1;
	
	for( ll i = 2; i<=max(n,m);i++ )
	{
	    arr[i] = (arr[i-1]+arr[i-2])%M;
	}
	
	ll ans = 2*(arr[n] + arr[m] - 1 +M)%M;
	cout << ans << endl;
}

// https://codeforces.com/contest/1248/problem/C
// contributor - https://github.com/aditya113141
