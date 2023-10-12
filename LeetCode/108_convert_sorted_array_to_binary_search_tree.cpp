/*
Question URL: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

Examples:
1. Input: nums = [-10, -3, 0, 5, 9], Output: [0, -3, 9, -10, null, 5]
2. Input: nums = [1, 3], Output: [3, 1]

Approach:
1. The sortedArrayToBST function is a recursive function that takes a sorted array nums, along with the left and right indices of the current sub-array.
2. If the left index is greater than the right index, it returns nullptr, indicating an empty tree.
3. Otherwise, it calculates the middle index as the average of left and right.
4. It creates a new TreeNode with the value of nums[mid] as the root of the current subtree.
5. It recursively constructs the left subtree by calling sortedArrayToBST with updated indices, i.e., left to mid - 1.
6. It recursively constructs the right subtree by calling sortedArrayToBST with updated indices, i.e., mid + 1 to right.
7. The in-order traversal function is used to print the elements of the BST in ascending order.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

// Definiton for a Binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &nums, int left, int right)
    {
        // Check if the left is greater than right
        if (left > right)
            return nullptr;

        // Finding the middle element
        int mid = (left + right) / 2;

        // Create a root node
        TreeNode *root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtree
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);

        return root;
    }
};

// Helper function to print the BST
void inOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main()
{
    int n;
    cout << "Enter size of nums: ";
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements: ";
        cin >> nums[i];
    }

    Solution solution;
    TreeNode *root = solution.sortedArrayToBST(nums);

    inOrderTraversal(root);

    return 0;
}