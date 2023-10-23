/* URL : https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/

Constraints:
3 <= nums.length <= 10^5
1 <= nums[i] <= 10^8


Approach: 
Step 1: We must understand that we cannot use brute force approach to solve as this will produce TLE
        Since brute force will use atleats two for loops making it 1^10 iterations taking more than 1 sec
        thus giving TLE
Step 2: To solve this question with given constraint in 1 sec we must use prefix and suffix array.
        These array will store the minimum number from the left and the minimum number from the right of 
        the particular element as we need to find the mountain as given in the question.
Step 3: When we are able to find the prefix and the suffix array we can simply run a for loop over the
        elements of the actual array and check which element is greater than its prefix element and suffix 
        element at the same index and calculate their sum.
        The overall Time complexity will be O(3n) which is equivalent to O(n).
Step 4: While running a for loop use the mini variable to find the smallest sum of the mountain 
Step 5: Finally print the answer store in the mini variable.
*/

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref, suff(n);
        pref.push_back(nums[0]);
        suff[n-1] = nums[n-1];
        
        for(int i = 1 ;i < n ;i++) pref.push_back(min(nums[i], pref.back()));
        for(int i = n-2; i>=0 ; i--){
            suff[i] = min(nums[i], suff[i+1]);
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > pref[i] && nums[i] > suff[i]){
                ans = min(ans, pref[i] + suff[i] + nums[i]);
            }
        }
        if(ans == INT_MAX) ans = -1;
        return ans;
    }

void solve(){
    int n ;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    cout << minimumSum(v) << endl;

}
int main(){
    #ifdef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1LL;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}