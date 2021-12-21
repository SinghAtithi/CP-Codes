/*
    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    Karmanye vadhikaraste Ma Phaleshu Kadachana,
    Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    The meaning of the verse is :—
    You have the right to work only but never to its fruits.
    Let not the fruits of action be your motive, nor let your attachment be to
   inaction
*/

#include <math.h>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vin(x, v) \
    for (auto& x : v) cin >> x;
#define vout(x, v) \
    for (auto x : v) cout << x << " ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i = j; i < k; i += 1)
#define rloop(i, j, k) for (int i = j; i >= k; i -= 1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MODD 998244353
// cout <<setprecision(15)
#define NEED_FOR_SPEED_MOST_WANTED    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
#ifndef ONLINE_JUDGE
#define deb(x)         \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define deb(x)
#endif

void _print(int32_t t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
int r(string s) {
    int ans = 0;
    
    // first check if it lies in positive half or negetive half
    
    for (auto x : s) {
        if (x == '(')
            ans++;
        else
            ans--;
    }

    int temp=0;

    // if it lies in positive half then check if it can be a part or not
    // example ()))(((( can not be a part even though it is in positive half
    // positive means it is in first half negetive means in second half

    if(ans>=0){
        rep(i,s.size()){
            if(s[i]=='(')
                temp++;
            else
                temp--;
            if(temp<0)
                return INF;
        }
    }

    // but for negetive part we have to check from begind
    // remember this!! 
    // because this gave me WA

    else{
        for(int i=s.size()-1;i>=0;i--){
            char x=s[i];
            if(x=='(')
                temp++;
            else
                temp--;
            if(temp>0)
                return INF;
        }
    }
    if(ans>=0 && s[0]==')')return INF;
    if(ans<0 && s.back()=='(')return INF;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        int temp = r(s);
        if (temp != INF) mp[temp]++;
    }
    int ans = 0;
    for (auto x : mp) {
        if (x.first < 0) {
            ans += min(x.second, mp[-x.first]);
        }
    }
    // we have to check for 0 seperately
    // could have done in the map itself but i am lazy
    
    ans += mp[0] / 2;
    cout << ans;
}

signed main() {
    NEED_FOR_SPEED_MOST_WANTED;
    //#ifndef ONLINE_JUDGE
    // FOR GETTING INPUT FROM input.txt
    // freopen("input.txt", "r", stdin);
    // FOR GETTING INPUT FROM input.txt
    // freopen("output.txt", "w", stdout);
    //	#endif
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cout << endl;
    }
}