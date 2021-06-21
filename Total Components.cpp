#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector<ll>
#define vecs vector<string>
#define ul unsigned long long
#define pair pair<ll,ll>
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vi,greater<ll> >
#define f(i,j,n) for(ll i = j; i < n; ++i)
#define rev(i,j,n) for(ll i = j; i >=n; --i)
#define mp make_pair
#define mod 1000000007
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define sort(ar) sort(ar.begin(), ar.end)
const ll N = 1e5+10;
ll hsh[N];

 
 
 
 
ll binarySearch(ll *arr, ll n, ll target) {
	
	ll lo = 0, hi = n-1;
	while(lo <= hi) {
		ll m = mid(lo, hi);
		if(arr[m] == target) {
			return m;
		} else if (arr[m] > target) {
			hi = m - 1;
		} else {
			lo = m + 1;
		}
	}
	return -1;
}
 
ll fact(ll x) {
    if (x == 1 || x == 0)return 1;
    return (x * (fact(x - 1)));
}
 
void sieve(ll *arr,ll n)
{
	arr[0] =1, arr[1] = 1;
	for(ll i = 2; i * i <= n; i++) {
    		if(arr[i]==1) {
        		for(ll j = i * i; j <= n; j += i){
            		arr[j] = 1;
        		}
    	}
	}
 
}
 
ll gcd(ll l,ll b)
{
    if(l==b)
    return l;
    if(l>b)
    return gcd(l-b,b);
    else
    return gcd(l,b-l);
}
 

 
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("error.txt", "w", stderr);
	    freopen("output.txt", "w", stdout);
	#endif
}

ll getposi(vec ar, ll e){
	auto it = find(ar.begin(), ar.end(),e);
	if(it != ar.end())
	{
		return (it-ar.begin());
	}
	else
		return -1;  
}

int bs(string arr[],string x,ll n){ 

        ll l = 0 ; 
        ll r = n - 1; 
        while (l <= r)  
        { 
            ll m = l + (r - l) / 2; 
  
        ll res; 
        if (x == (arr[m])) 
            res = 0; 
              
  
            // Check if x is present at mid 
            if (res == 0) 
                return m; 
  
            // If x greater, ignore left half 
            if (x > (arr[m])) 
                l = m + 1; 
  
            // If x is smaller, ignore right half 
            else
                r = m - 1; 
        } 
  
        return -1; 
    } 

  

	ll match(string s1, string s2) {
		ll j=0;ll flag=0;
		for(ll i=0;i<s1.length();i++)
		{
			if(s1[i]==s2[j]){
				j++;
			}
			else j=j;
			if(j==s2.length()){
				flag=1;
				break;
			}
		}
		return flag;
	}

	string getbinary(ll n) {
		string r;
   		 while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    	return r;
	}
	
	
	//convert string to lower or upper
	//transform(a.begin(), a.end(), a.begin(), ::tolower)
	//transform(b.begin(), b.end(), b.begin(), ::toupper)


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
 	
	ll t;
	cin>>t;
	set<ll> s1;
    for(ll i=2;i<=N;i+=2)
    s1.insert(i);
  
   for(ll i=3;i<=N;i++)
   {
       if(i%2==0)
       continue;
       else
       {
           for(ll j=i+1;j<=N;j*=j)
           {
               if(__gcd(i,j)>1)
               {
                   
                   if(s1.count(i))
                   s1.insert(j);
                   else if(s1.count(j))
                   s1.insert(i);
               }
           }
       }
   	}

   	while(t--)
   	{
   		ll n;
   		cin>>n;
   		ll sum=0;
   		f(i,2,n+1)
   		{
   			if(s1.count(i))
   				sum++;
   		}

   		cout<<(sum+(n-sum))<<endl;
   	}



    #ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}


 #include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    
   
   ll t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       set<ll> s1;
    for(ll i=2;i<=n;i+=2)
    s1.insert(i);
  ll k=2;
   for(ll i=3;i<=n;i++)
   {
   		k=2;
       if(i%2==0)
       continue;
       else
       {
           for(ll j=i+1;j<=n;)
           {
               if(__gcd(i,j)>1)
               {
                   
                   if(s1.count(i))
                   s1.insert(j);
                   else if(s1.count(j))
                   s1.insert(i);
               }
               j*=k;
               k++;
           }
       }
   }
       
       
       cout<<(1+(n-1-s1.size()))<<endl;
   }
   
   return 0;
}