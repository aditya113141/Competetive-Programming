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
#define c(x) cin >> x
#define fo(i,k,n) for( int i=k;i<n;i++)
#define hu 200010
#define pq priotity_queue<ll>
#define pqs priority_queue<ll,vii,greater<ll>>
#define ppq priority_queue<ip,vpp,greater<ip>>
#define INF INT_MAX
#define ff first
#define ss second
using namespace std;
const ll M = 1000000000+7;
//Grid Movement
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};

ld Pi= acos(-1);

ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}

ll mex(ll x, ll y) 
{ 
	ll res = 1;	  
	x = x % M; 
	if (x == 0) return 0; 
	while (y > 0) 
	{ 
		if (y & 1) 
		res = (res*x) % M; 
		y = y>>1; 
		x = (x*x) % M; 
	} 
	return res; 
} 

bool comp(ll comp1,ll comp2)
{
    return comp1>comp2;
}

void yes()
{
    printf("YES\n");
}

void no()
{
    printf("NO\n");
}

ll inv(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
 
    if (x < 0)
       x += m0;
 
    return x;
}

void sieve(ll n)
{
    vii primes(n+1);
    vb is_prime(n+1);
	is_prime.resize(n+1);
	primes.resize(n+1);
 
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i<=n; i++)
	{
	    if(is_prime[i])
	    {
	    	primes.pb(i);
	        for (int j = i*i; j<=n; j+=i)
	            is_prime[j] = false;
	    }
	}
}



int main()
{ll n;
   sc(n);
   ll a[n],b[n],l[n],r[n];
   fo(i,0,n)
   {
       sc(a[i]);
       b[i]=a[i];
       
   }
   reverse(b,b+n);
   ll flag = 1;
   l[n-1]=1;
   ll maxy =1;
   for(ll i =n-2;i>=0;i--)
   {
       if(a[i]<a[i+1])
       {
           flag++;
           l[i]=flag;
       }
       else
       {
           flag=1;
           l[i]=flag;
       }
       maxy = max(maxy,l[i]);
   }
   
   flag =1;
   r[0]=1;
   for(ll i =1;i<n;i++)
   {
       if(a[i]>a[i-1])
       {
           flag++;
           r[i]=flag;
       }
       else
       {
           flag=1;
           r[i]=flag;
       }
   }
   
    /*
   for(auto it: l) cout << it << " ";
   cout << endl;
    for(auto it: r) cout << it << " ";
   cout << endl;
   */
   fo(i,1,n-1)
   {
       if(a[i-1]<a[i+1]) maxy = max(maxy,l[i+1]+r[i-1]);
   }
   printf("%lli",maxy);
    
}

