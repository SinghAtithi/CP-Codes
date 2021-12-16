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
vi win(100010);

void init()
{
    win[0] = 0;
    win[1] = 1;
    win[2] = 1;
    loop(i, 3, 100010)
    {
        win[i] = (win[i - 1] + win[i - 2]) % 2;
    }
    // deb(win);
}

// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
int maxProduct(vi &nums)
{
    int n = nums.size();
    int ans = INT_MIN;
    int curr_max = 1;
    int curr_min = 1;
    int curr_ans = 1;
    loop(i, 0, n)
    {
        if (nums[i] == 0)
        {
            curr_max = 1;
            curr_min = 1;
            curr_ans = 0;
        }
        else if (nums[i] < 0)
        {
            int temp = curr_max;
            curr_max = max(curr_max * nums[i], curr_min * nums[i]);
            curr_min = min(temp * nums[i], curr_min * nums[i]);
            curr_ans = curr_max;
        }
        else
        {
            curr_max = max(curr_max * nums[i], curr_min * nums[i]);
            curr_min = min(curr_max * nums[i], curr_min * nums[i]);
            curr_ans = max(curr_ans, curr_max);
        }
        ans = max(ans, curr_ans);
    }
    return ans;
}


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a,b;a=b=0;
    loop(i, 0, n)
    {
        if(s[i]=='1')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    int t=min(a,b);
    if(t%2==0)cout<<"Bob";
    else cout<<"Alice";
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
    init();
    while (t--)
    {
        solve();
        cout << endl;
    }
}