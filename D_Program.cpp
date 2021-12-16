/*  
    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।          
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    Karmanye vadhikaraste Ma Phaleshu Kadachana,
    Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    The meaning of the verse is :—
    You have the right to work only but never to its fruits.
    Let not the fruits of action be your motive, nor let your attachment be to inaction
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
#define MODD 998244353
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
struct Node
{
    int mini;
    int maxi;
};

vector<Node> segTree;
vector<int> arr;

Node merge(Node a, Node b)
{
    Node ans;
    ans.maxi = max(a.maxi, b.maxi);
    ans.mini = min(a.mini, b.mini);
    return ans;
}

void build(int ind, int l, int r)
{
    if (l == r)
    {
        segTree[ind].maxi = arr[l];
        segTree[ind].mini = arr[r];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    segTree[ind] = merge(segTree[ind * 2], segTree[ind * 2 + 1]);
}

// seg tree query
Node query(int ind, int l, int r, int i, int j)
{
    if (i > r || j < l)
        return {INT_MAX, INT_MIN};
    if (i <= l && r <= j)
        return segTree[ind];
    int mid = (l + r) / 2;
    Node left = query(ind * 2, l, mid, i, j);
    Node right = query(ind * 2 + 1, mid + 1, r, i, j);
    return merge(left, right);
}

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    string s;
    cin >> s;
    segTree.clear();
    segTree.resize(4 * n);
    int temp = 0;

    arr.push_back(temp);

    for (auto x : s)
    {
        if (x == '+')
            temp++;
        else
            temp--;
        arr.push_back(temp);
    }
    build(1, 0, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        Node ans = query(1, 1, n, l, r);
        Node a = query(1, 0, n, 0, l - 1);
        Node b ;
        if(r!=n)
         query(1, 0, n, r + 1, n);
        else b=a;
        cerr << ans.maxi << " " << ans.mini << endl;
        cerr << a.maxi << " " << a.mini << endl;
        cerr << b.maxi << " " << b.mini << endl;
        cerr<<"\n";
        int z = a.maxi - a.mini + 1;
        z += b.maxi - b.mini + 1;
        z -= max(a.maxi - b.mini + 1, (int)0);
        cout << z<<"\n";
    }
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
    while (t--)
    {
        solve();
        cout << endl;
    }
}