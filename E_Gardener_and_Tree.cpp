/*  
*/

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<math.h>
#include<stack>
#include<list>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include <iomanip> 
#include<unordered_map>
#include<unordered_set>
#include<utility>
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vin(x,v) for(auto &x:v)cin>>x;
#define vout(x,v)for(auto x:v)cout<<x<<" ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i=j ; i<k ; i+=1)
#define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
//cout <<setprecision(15)
#define NEED_FOR_SPEED_MOST_WANTED ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;


/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
#ifndef ONLINE_JUDGE
#define deb(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define deb(x)
#endif

void _print(int32_t t){ cerr<<t;}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(unordered_set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
/*-----------------------------------D-E-B-U-G-----------------------------------------------*/

void solve(){
    unordered_map<int,int>deg;
    unordered_map<int,vi>graph;
    unordered_map<int,unordered_set<int>>aalu;

    int n,k;cin>>n>>k;
    rep(i,n-1){
        int a,b;cin>>a>>b;
        deg[a]++;
        deg[b]++;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    loop(i,1,n+1){
        int x=deg[i];
        aalu[x].insert(i);
    }
    int ans=n;
    unordered_set<int>removed;
    while(k--){
        deb(aalu[1]);
        if(ans<=1){
            ans=0;break;
        }
        unordered_set<int>temp;
        for(auto x:aalu[1]){
            deg[x]--;
            if(deg[x]<=0){ans--;removed.insert(x);}
            for(auto z:graph[x]){
                deg[z]--;
                // if(deg[z]==0){
                //     ans--;
                // }
                if(deg[z]==1 )temp.insert(z);
            }
        }
        for(auto z:temp){
            if(removed.find(z)!=removed.end())removed.erase(z);
        }
        aalu[1].clear();
        aalu[1]=temp;
    }
    cout<<ans;
}

signed main(){
NEED_FOR_SPEED_MOST_WANTED; 
 //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    //freopen("output.txt", "w", stdout);
//	#endif
  int t=1;
  cin>>t;
  while(t--){
   solve();
  cout<<endl;
  }
}