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
// sum of digits of a num
int sum_digits(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// sum of a geometric progression
int sum_gp(int a, int r, int n)
{
    return (a * (1 - pow(r, n))) / (1 - r);
}

// sum of arithmatic progression
int sum_ap(int a, int d, int n)
{
    return (a + (n - 1) * d) / 2;
}

// segment tree min
int min_seg_tree(int *arr, int *st, int ss, int se, int qs, int qe)
{
    if (qs <= ss && qe >= se)
        return st[0];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = (ss + se) / 2;
    return min(min_seg_tree(arr, st, ss, mid, qs, qe), min_seg_tree(arr, st, mid + 1, se, qs, qe));
}

// build
void build_seg_tree(int *arr, int *st, int ss, int se)
{
    if (ss == se)
    {
        st[0] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    build_seg_tree(arr, st, ss, mid);
    build_seg_tree(arr, st, mid + 1, se);
    st[0] = min(st[2 * ss + 1], st[2 * ss + 2]);
}


void solve(){
    int a,b,c;cin>>a>>b>>c;
    // create a vector ans
    vector<int> ans;
    // loop 1 to 81
    for(int i=1;i<=100000;i++){
        int t;
        t=b*(pow(i,a)) +c;
        if(i==sum_digits(t) && t<(1e9)){
            ans.pb(t);
        }
        // cerr<<i<<" "<<t<<"\n";
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        // cout<<" "<<ans[i];
        cout<<ans[i]<<" ";
    }
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