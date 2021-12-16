#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include<bits/stdc++.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define ll long long int
using namespace std;
int main()
{
    ll INF=1e15;
    ll n, m, a, b, w;
    cin>>n>>m;
    vector<map<int, int>> edges(n+1);
    while (m--)
    {
        cin >> a >> b >> w;
        edges[a][b] = w;
        edges[b][a] = w;
    }
    vector<pair<ll, ll> > dis(n+1, make_pair(INF, -1));
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));
    dis[1] = make_pair(0, -1);
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();
        for (auto xy:edges[node])
        {
            ll adjNode = x->first;
            ll wt = x->second;
            if (dist + wt < dis[adjNode].first)
            {
                dis[adjNode] = make_pair(dist + wt, node);
                pq.push(make_pair(dist+wt, adjNode));
            }
        }
    }
    if (dis[n].second==-1)
    {
        cout<<"-1";
    }
    else
    {
        vector<ll> ans;
        ans.push_back(n);
        while (1)
        {
            if (ans.back() == 1)
            {
                break;
            }
            ans.push_back(dis[ans.back()].second);
        }
        for (ll i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        
    }
    
    return 0;
}
