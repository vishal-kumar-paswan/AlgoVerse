// M-1) Brute force --> Gives TLE 
// T.C: O(n^3 * log(no. of unique triplets)), where n = size of the array.
// S.C: O(2 * no. of the unique triplets), for storing in set s and vector ans.
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;  // set of vectors (as duplicate triplets not allowed)

        for (int i = 0; i < n; i++) {    // check all possible triplets
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp); // set stores unique triplets (provided they are sorted before)
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());  //store the set elements in the answer
        
        return ans;
    }
};
*/

// M-2) Hasing and 2-Sum.
// T.C: O(n^2 * log(no. of unique triplets)), where n = size of the array.
// S.C: O(2 * no. of the unique triplets) + O(1), for storing in set s and vector ans. Extra O(n) for storing the array elements in map.
// unordered_map must be inside the first for-loop since we generate it for each iteration for elements >i.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        
        for(int i = 0; i < n; i++){
            if (i != 0 && nums[i] == nums[i - 1])   // remove duplicates
                continue;
            unordered_map<int, int> m;  // stores no. as key and index as value for using later (hashing)
            
            for(int j = i+1; j < n; j++){   // use 2-Sum method from here
                int rem = -(nums[i] + nums[j]);  // Calculate the 3rd element

                if(m.find(rem) != m.end()){
                    vector<int> temp = {nums[i], nums[j], rem};
                    sort(temp.begin(), temp.end());  // O(1)
                    s.insert(temp);   // O(log(no. of unique triplets))
                }
                
                m.insert({nums[j], j}); // O(1)
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};



// M-3) Two-pointer and 2-Sum technique
// T.C: O(nlogn) + O(n^2 * logn), here O(nlogn) for sorting nums and O(n^2 logn) for inserting into set inside the two for-loops.  S.C: O(n) for set.
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // O(nlogn)

        set<vector<int>> s;  // set of vectors (as duplicate triplets not allowed)
        for(int i = 0; i < n; i++){
            int j = i+1;    // use 2-Sum method from here
            int k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                   j++; 
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};  // temp will be sorted as nums is sorted.
                    s.insert(temp);   // no need to sort temp before inserting. s will store unique triplets.
                    j++;
                    k--;
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());    //store the set elements in the answer
        // vector<vector<int>> ans;
        // for(auto triplet : s){
        //     ans.push_back(triplet);
        // }

        return ans;
    }
};
*/


// M-4) Two-pointer and 2-Sum technique. But without extra space or using set.
// T.C: O(nlogn)+O(n^2), here O(nlogn) for sorting nums and O(n^2) for the two for-loops.  S.C: O(1).
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());   // O(nlogn)

        for(int i = 0; i < n; i++){
            if (i != 0 && nums[i] == nums[i - 1])   // remove duplicates
                continue;  
            
            int j = i+1;    // use 2-Sum method from here
            int k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                   j++; 
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};  // temp will be sorted as nums is sorted
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1])   //skip the duplicates
                        j++;
                    while(j < k && nums[k] == nums[k+1])   //skip the duplicates
                        k--;
                }
            }
        }

        return ans;
    }
};
*/