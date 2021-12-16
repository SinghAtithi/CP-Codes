#include<bits/stdc++.h>
#define ll long long

using namespace std;

// longest common subsequence
int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    // fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int>v,vv;
    // input the vectors
    for(int i=0; i<n; i++) {
        int x;cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<n; i++) {
        int x;cin>>x;
        vv.push_back(x);
    }
    

    return 0;
}