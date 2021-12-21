/*  
    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।          
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    Karmanye vadhikaraste Ma Phaleshu Kadachana,
    Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    The meaning of the verse is :—
    You have the right to work only but never to its fruits.
    Let not the fruits of action be your motive, nor let your attachment be to inaction
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
#define MODD 998244353
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
struct Node{
    int freq;
    int lazy;
};
vector<int>arr;
vector<Node>segTree;
int n,q;

void build(int v, int start, int end){
    if(start==end){
        segTree[v].lazy=0;
        segTree[v].freq=0;
        return;
    }
    int mid=(start+end)/2;
    build(2*v, start, mid);
    build(2*v+1, mid+1, end);
    // since It's a point query, we do not need to do anything here
}

Node query(int v, int l, int start, int end){
    if(start==end && start==l){
        return segTree[v];
    }
    int mid=(start+end)/2;
    segTree[2*v].lazy=((mid-start+1)*segTree[v].lazy)/(end-start+1);
    segTree[2*v+1].lazy=segTree[v].lazy-segTree[2*v].lazy;
    segTree[v].lazy=0;
    segTree[2*v].freq=(mid-start+1);
    segTree[2*v+1].freq=(end-mid);
    segTree[v].freq=0;
    if(l<=mid){
        return query(2*v, l, start, mid);
    }
    else{
        return query(2*v+1, l, mid+1, end);
    }
}

Node query(int l){
    return query(1,l,0,n-1);
}

void update(int v, int l,int r, int start, int end,int k){
    if(l>end || r<start)return; // no overlap
    if(l<=start && end<=r){
        segTree[v].lazy+=k*(end-start+1);
        // deb(l);deb(r);deb(start);deb(end);deb(k);
        // deb(segTree[v].lazy);
        segTree[v].freq+=k;
        return;
    }
    int mid=(start+end)/2;
    update(2*v, l, r, start, mid, k);
    update(2*v+1, l, r, mid+1, end, k);
}

void update(int l, int r, int k){
    update(1,l,r,0,n-1,k);
}


void init(){
    cin>>n;
    cin>>q;
    arr.resize(n);
    vin(x,arr);
    segTree.resize(4*n);
    build(1,0,n-1);
}

int ans(int l){
    Node node=query(l);
    int t=0;
    t=arr[l-1];
    deb(arr[l-1]);
    deb(node.lazy);
    deb(node.freq);
    t+=node.lazy*node.lazy;
    t+=node.freq*(l*l);
    t+=node.lazy*node.freq*2;
    deb(t);
    return t;
}

void solve(){
    /*
        Good Problem from CodeChef Starters,
        I will be using SegTree with Lazy Propagation
        You could have used BIT also.
        (X +i -L)^2 = (i + (X-L))^2 = (i^2) + (2*i*(X-L)) + (X-L)^2 
        The above fromula will be used, earlier i thought to use something like prefix
        sum in seg tree but then how to add constant values, Thats why using lazy propagation
        Type: Range Update Point Query
    */
   init();
   while(q--){
         int t;cin>>t;
         if(t==1){
              int l,r,k;cin>>l>>r>>k;
              int y=(k-l);
              update(l,r,y);
              deb(0);
         }
         else{
              int l;cin>>l;
              cout<<ans(l)<<"\n";
         }
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