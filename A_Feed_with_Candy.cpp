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
void _print(set<T> v);
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
void _print(set<T> v)
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

bool comp(pii a, pii b){
    return a.second<b.second;
}


void solve(){
    int n,k;cin>>n>>k;
    vii v,vv;
    rep(i,n){
        int x,y,z;cin>>x>>y>>z;
        if(x==1){
            v.pb({y,z});
        }
        else{
            vv.pb({y,z});
        }
    }
    sort(all(v),comp);sort(all(vv),comp);
    int i=0,j=0;
    int ans=0,anss=0;
    int kk=k;
    bool check=true;
    while(true){
        if(check){
            if(k>=v[i].first)k+=v[i].second,ans++,i++;
            else break;
        }
        if(j==vv.size())break;
        if(!check){
            if(k>=vv[j].first)k+=vv[j].second,ans++,j++;
            else break;
        }
        if(i==v.size())break;
        check=!check;
        deb(k);
        deb(i);deb(j);
    }
    check=false;
    anss=ans;
    ans=0,k=kk;
    i=0,j=0;
    while(true){
        if(check){
            if(k>=v[i].first)k+=v[i].second,ans++,i++;
            else break;
        }
        if(j==vv.size())break;
        if(!check){
            if(k>=vv[j].first)k+=vv[j].second,ans++,j++;
            else break;
        }
        if(i==v.size())break;
        check=!check;
    }
    cout<<max(ans,anss);
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
  //cin>>t;
  while(t--){
   solve();
  cout<<endl;
  }
}