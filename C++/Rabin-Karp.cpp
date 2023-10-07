#include <bits/stdc++.h>

using namespace std;

const int prime = 101;

int calculateHash(string str, int length) {
    int hash = 0;
    for (int i = 0; i < length; ++i) {
        hash = (hash * prime + str[i]) % prime;
    }
    return hash;
}

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = calculateHash(pattern, m);
    int textHash = calculateHash(text, m);

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at position " << i << endl;
            }
        }
        if (i < n - m) {
            textHash = (prime * (textHash - text[i] * (int)pow(prime, m - 1)) + text[i + m]) % prime;
            if (textHash < 0) {
                textHash += prime;
            }
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search for: ";
    cin >> pattern;

    rabinKarp(text, pattern);

    return 0;
}
