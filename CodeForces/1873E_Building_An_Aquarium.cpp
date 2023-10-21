/*
Question URL:  https://codeforces.com/contest/1873/problem/E
Approach:
We binary search over possible values between 1 and 1e13
Time Complexity: O(n)
Space Complexity: O(n)
*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        long long l = 1, r = 1e13, ans;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long cur = 0;
            for (int i : arr) cur += max(mid - i, 0ll);
            if (cur <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}