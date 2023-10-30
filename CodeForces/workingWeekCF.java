// Day 68
// https://codeforces.com/problemset/problem/1735/A
// 1735 A. Working Week
// Approach: We simply count the number of working days in a week, and then divide it by 3 and subtract 2. This is because we know that there are 3 days off in a week, and that the last day must be a day off, so we only need to consider the remaining 2 days off.
// Time complexity: O(1)
// Space complexity: O(1)

import java.util.*;

public class workingWeekCF {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            System.out.println(n / 3 - 2);
        }
        in.close();
    }
}
