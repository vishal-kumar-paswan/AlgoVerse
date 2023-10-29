// Day 145
// https://codeforces.com/problemset/problem/550/A
// 550 A. Two Substrings

import java.util.*;

public class twoSubstringsCF {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String str = s;
        if (s.contains("AB")) {
            s = s.replaceFirst("AB", "QQ");

            if (s.contains("BA")) {
                System.out.println("YES");
                return;
            }
        }
        if (str.contains("BA")) {
            str = str.replaceFirst("BA", "QQ");

            if (str.contains("AB")) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
        in.close();
    }
}
