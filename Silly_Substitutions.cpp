/*  
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include <stack>
#include <list>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <utility>
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
#define vin(x, v)     \
    for (auto &x : v) \
        cin >> x;
#define vout(x, v)   \
    for (auto x : v) \
        cout << x << " ";
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
//cout <<setprecision(15)
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

void _print(int32_t t)
{
    cerr << t;
}
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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string temp = "";
    while (true)
    {
        bool check=true;
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '0' && s[i + 1] == '1')
                temp += '2', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '1' && s[i + 1] == '2')
                temp += '3', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '2' && s[i + 1] == '3')
                temp += '4', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '3' && s[i + 1] == '4')
                temp += '5', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '4' && s[i + 1] == '5')
                temp += '6', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '5' && s[i + 1] == '6')
                temp += '7', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '6' && s[i + 1] == '7')
                temp += '8', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '7' && s[i + 1] == '8')
                temp += '9', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '8' && s[i + 1] == '9')
                temp += '0', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp = "";
        n = s.size();
        rep(i, n)
        {
            if (s[i] == '9' && s[i + 1] == '0')
                temp += '1', i++, check=false;
            else
                temp += s[i];
        }
        s = temp;
        temp="";
        if(check)break;
    }
    cout << s;
}

signed main()
{
    NEED_FOR_SPEED_MOST_WANTED;
    //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt
    //freopen("output.txt", "w", stdout);
    //	#endif
    int t = 1;
    cin >> t;
    int j = 1;
    while (t--)
    {
        cout << "Case #" << j++ << ": ";
        solve();
        cout << endl;
    }
}