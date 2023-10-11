/*
Question URL:  https://codeforces.com/contest/1877/problem/A
Approach:
The efficiencies of all the teams add up to zero

so, we sup all the given elements and find out the negative of that figure
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++)
    {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
        }
        cout << -1 * sum << "\n";
    }
    return 0;
}
