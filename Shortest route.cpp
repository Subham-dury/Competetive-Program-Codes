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
#define sort(ar) sort(ar.begin(), ar.end())
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
 	while(t--)
 	{
 		ll n,m;
 		cin>>n>>m;
 		vec ar(n);
 		f(i,0,n)cin>>ar[i];
 		ll prefix[n],suffix[n];
 		memset(prefix,0,sizeof(prefix));
 		memset(suffix,0,sizeof(suffix));

 		bool flag=false;
 		prefix[0]=0;
 		
 		if(ar[0]==1)
 			flag=true;

 		f(i,1,n)
 		{
 			if(ar[i]==1){
 				prefix[i]=0;
 				if(!flag) flag=true;
 			}
 			else
 			{
 				if(flag) prefix[i]=prefix[i-1]+1;
 				else prefix[i]=-1;
 			}
 		}

 		flag=false;
 		rev(i,n-1,1)
 		{
 			if(ar[i]==2){
 				suffix[i]=0;
 				if(!flag)flag=true;
 			}
 			else
 			{
 				if(flag) suffix[i]=suffix[i+1]+1;
 				else suffix[i]=-1; 				
 			}
 		}

 		ll x;
 		while(m--)
 		{
 			cin>>x;
 			if(prefix[x-1]==-1)
 				cout<<suffix[x-1]<<" ";
 			else if(suffix[x-1]==-1)
 				cout<<prefix[x-1]<<" ";
 			else if(prefix[x-1]!=-1 and suffix[x-1]!=-1)
 				cout<<min(prefix[x-1],suffix[x-1])<<" ";
 		}

 		cout<<endl;
 		
 	}
 	

    #ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}


 