#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        string pehla;
        cin >> pehla;
        string doosra;
        cin >> doosra;
        for (int i = 0; i < doosra.size() - 1; i++)
        {
            int a, b;
            for (int j = 0; j < 26; j++)
            {
                if (doosra[i] == pehla[j])
                    a = j;
            }
            for (int j = 0; j < 26; j++)
            {
                if (doosra[i + 1] == pehla[j])
                    b = j;
            }
            ans += abs(a - b);
        }
        cout << ans << "\n";
    }
    return 0;
}