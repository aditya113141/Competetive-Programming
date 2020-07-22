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
     
    void solve()
    {
        ll n;
        sc(n);
        string s1,s2;
        
        cin >> s1;
        cin >> s2;
        ll ind =-1;
        for(ll i =n-1;i>=0;i--)
        {
            if(s1[i]!=s2[i])
            {
                ind = i;
                break;    
            }
            
        }
       // cout << ind << endl;
        if(ind==-1) 
        {
            printf("0\n");
            return;
        }
        
        vii ans;
        
        for(ll i =ind;i>=0;i--)
        {
            if(s1[i]==s2[i]) continue;
            
            if(i==0)
            {
                ans.pb(1);
                continue;
            }
            
            if(s1[0]==s2[i])
            {
                ans.pb(1);
                if(s1[0]=='1') s1[0]='0';
                else s1[0]='1';
            }
            
            if(s1[0]!=s2[i])
            {
              //  cout << s1 << endl;
                ans.pb(i+1);
                fo(j,0,i+1)
                {
              //      cout <<j << " ";
                    if(s1[j]=='0') s1[j]='1';
                    else s1[j]='0';
                }
              //   cout << s1 << endl;
                reverse(s1.begin(),s1.begin()+i+1);
            }
            
          //  cout<< i << " "<< s1 << " "<< s2<<endl;
        }
        
        ll siz = ans.size();
        printf("%lli ",siz);
        
        for(auto it : ans)
        {
           printf("%lli ",it);
        }
       
       printf("\n");
        
    }
     
    int main()
    {
        ll t=1;
        sc(t);
        while(t--) solve();
    }
     
     
     
