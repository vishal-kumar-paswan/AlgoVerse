// Day 113
// https://codeforces.com/problemset/problem/381/A
// 381 A. Sereja and Dima
// Approach: The algorithm works by iterating over the array from both ends, and taking the larger element at each end on each iteration. The algorithm also keeps track of whether the current iteration is for Sereja or Dima, and adds the element to the corresponding sum.
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

public class serejaAndDimaCF {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        int ser = 0, dim = 0;
        int count = 1;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0, j = n - 1; i <= j;) {
            int max;
            if (a[i] < a[j]) {
                max = a[j];
                j--;
            } else {
                max = a[i];
                i++;
            }
            if (count % 2 == 0)
                dim += max;
            else
                ser += max;
            count++;
        }

        System.out.print(ser + " " + dim);
    }
}
