// Day 117
// https://codeforces.com/problemset/problem/1626/B
// 1626 B. Minor Reductions
// Approach: iterate over the input string from the back, and to check if the sum of the current and previous characters is greater than or equal to 10. If it is, then the code replaces the two characters with the sum, and breaks the loop. Otherwise, the code continues iterating over the string.

If the loop reaches the beginning of the string without finding two characters whose sum is greater than or equal to 10, then the code simply replaces the first two characters with their sum.
// Time complexity: O(n)
// Space complexity: O(1)

import java.util.*;

public class minorReductionCF {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        while (t-- > 0) {
            String s = in.next();
            String hold = "";
            for (int i = s.length() - 1; i > 0; i--) {
                int sum = s.charAt(i - 1) - '0' + s.charAt(i) - '0';
                if (sum >= 10) {
                    hold = s.substring(0, i - 1) + sum + s.substring(i + 1);
                    break;
                }
            }
            if (hold.length() == 0) {
                int sum = s.charAt(0) - '0' + s.charAt(1) - '0';
                hold = sum + s.substring(2);
            }
            System.out.println(hold);
        }
        in.close();
    }
}
