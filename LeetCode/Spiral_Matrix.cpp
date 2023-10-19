// Given an m x n matrix, return all elements of the matrix in spiral order.

// here m = n = 3

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) {
        return result;
    }

    int top = 0, bottom = 2, left = 0, right = 2;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top boundary
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom along the right boundary
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Check if there are more rows to traverse
        if (top <= bottom) {
            // Traverse from right to left along the bottom boundary
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Check if there are more columns to traverse
        if (left <= right) {
            // Traverse from bottom to top along the left boundary
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> a{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int x : spiralOrder(a)) {
        cout << x << " ";
    }

    return 0;
}