// /*
//     कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
//     मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

//     Karmanye vadhikaraste Ma Phaleshu Kadachana,
//     Ma Karmaphalaheturbhurma Te Sangostvakarmani,

//     The meaning of the verse is :—
//     You have the right to work only but never to its fruits.
//     Let not the fruits of action be your motive, nor let your attachment be to inaction
// */

// #include<iostream>
// #include<vector>
// #include<string>
// #include<climits>
// #include<math.h>
// #include<stack>
// #include<list>
// #include<algorithm>
// #include<queue>
// #include<map>
// #include<set>
// #include <iomanip>
// #include<utility>
// #define int int64_t
// #define vi vector<int>
// #define vii vector<pair<int,int>>
// #define vs vector<string>
// #define vc vector<char>
// #define vb vector<bool>
// #define pb push_back
// #define vvi vector<vector<int>>
// #define pii pair<int,int>
// #define mp make_pair
// #define all(x) (x).begin(), (x).end()
// #define vin(x,v) for(auto &x:v)cin>>x;
// #define vout(x,v)for(auto x:v)cout<<x<<" ";
// #define MEM(a, b) memset(a, (b), sizeof(a))
// #define loop(i, j, k) for (int i=j ; i<k ; i+=1)
// #define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
// #define rep(i, j) loop(i, 0, j)
// #define rrep(i, j) rloop(i, j, 0)
// #define MP make_pair
// #define endl "\n"
// #define INF (int)1e18
// #define EPS 1e-18
// #define PI 3.1415926535897932384626433832795
// #define MOD 1000000007
// #define MODD 998244353
// //cout <<setprecision(15)
// #define NEED_FOR_SPEED_MOST_WANTED ios_base::sync_with_stdio(false);cin.tie(NULL)
// using namespace std;

// /*-----------------------------------D-E-B-U-G-----------------------------------------------*/
// #ifndef ONLINE_JUDGE
// #define deb(x)       \
//     cerr << #x << " "; \
//     _print(x);         \
//     cerr << endl;
// #else
// #define deb(x)
// #endif

// void _print(int32_t t){ cerr<<t;}
// void _print(int t) { cerr << t; }
// void _print(string t) { cerr << t; }
// void _print(char t) { cerr << t; }
// void _print(long double t) { cerr << t; }
// void _print(double t) { cerr << t; }
// void _print(unsigned long long t) { cerr << t; }

// template <class T, class V>
// void _print(pair<T, V> p);
// template <class T>
// void _print(vector<T> v);
// template <class T>
// void _print(set<T> v);
// template <class T, class V>
// void _print(map<T, V> v);
// template <class T>
// void _print(multiset<T> v);
// template <class T, class V>
// void _print(pair<T, V> p)
// {
//     cerr << "{";
//     _print(p.first);
//     cerr << ",";
//     _print(p.second);
//     cerr << "}";
// }
// template <class T>
// void _print(vector<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(set<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(multiset<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T, class V>
// void _print(map<T, V> v)
// {
//     cerr << "[ ";
//     for (auto i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// /*-----------------------------------D-E-B-U-G-----------------------------------------------*/

// void solve(){

//     string s;
//     string ss;
//     cin>>s>>ss;
//     map<char,bool>haHai;
//     for(auto x:s){
//         haHai[x]=true;
//     }
//     for(auto x:ss){
//         if(!haHai[x]){
//             cout<<-1;
//             return;
//         }
//     }
//     map<char,vi>mp;
//     int n=s.size();
//     rep(i,n){
//         mp[s[i]].pb(i);
//     }
//     int ans=1;
//     int temp=0;
//     for(auto x:ss){
//         if(temp>mp[x].back()){
//             temp=0;
//             ans++;
//         }
//         int z=lower_bound(all(mp[x]),temp)-mp[x].begin();
//         if(z==mp[x].size()){
//             temp=0;
//             ans++;
//         }
//         else{
//             temp=mp[x][z]+1;
//         }
//     }
//     cout<<ans;
// }

// signed main(){
// NEED_FOR_SPEED_MOST_WANTED;
//  //#ifndef ONLINE_JUDGE
//     //FOR GETTING INPUT FROM input.txt
//     //freopen("input.txt", "r", stdin);
//     //FOR GETTING INPUT FROM input.txt
//     //freopen("output.txt", "w", stdout);
// //	#endif
//   int t=1;
//   cin>>t;
//   while(t--){
//    solve();
//   cout<<endl;
//   }
// }

// satwik ka code

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debv(x)             \
    cout << #x << " ";      \
    for (auto val : x)      \
    {                       \
        cout << val << " "; \
    }                       \
    cout << endl;
#define debm(x)         \
    cout << #x << endl; \
    tr(it, x) { cout << it->first << "-->" << it->second << endl; }
#define deba(x, n)                    \
    cout << #x << " ";                \
    fo(i, n) { cout << x[i] << " "; } \
    cout << endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define sortallr(x) sort(x.rbegin(), x.rend())
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll n, m;
string s, t;

void solve()
{

    cin >> s >> t;

    n = s.size();
    m = t.size();

    set<char> hh;
    fo(i, n)
    {
        hh.insert(s[i]);
    }

    fo(i, m)
    {
        if (hh.find(t[i]) == hh.end())
        {
            cout << "-1" << endl;
            return;
        }
    }

    unordered_map<char, vector<ll>> hash;

    fo(i, n)
    {
        hash[s[i]].push_back(i);
    }

    ll back = -1;
    ll ans = 1;

    // 1e5
    // a-> 1e5

    fo(i, m)
    {
        // vector<ll> temp = hash[t[i]];
        if (back >= hash[t[i]].back())
        {
            back = hash[t[i]][0];
            ++ans;
            continue;
        }
        ll index = lower_bound(hash[t[i]].begin(), hash[t[i]].end(), back + 1) - hash[t[i]].begin();

        if (index < hash[t[i]].size())
        {
            back = hash[t[i]][index];
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE

    // freopen("inputf.txt", "r", stdin);
    // freopen("outputf.txt", "w", stdout);

#endif

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}