#include "HiguestValPolindrome.h"

#include <vector>

string HiguestValPolindrome::highestValuePalindrome(string s, int n, int k) {
    string sol = s;
    int changes = 0;
    vector<bool> vc;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - 1 -i]) {
            if (changes >= k)
                return "-1";
            else changes++;

            if (sol[i] > sol[n-i-1])
                sol[n-i-1] = sol[i];
            else
                sol[i] = sol[n-i-1];

            vc.push_back(true);
        } else vc.push_back(false);
    }

    changes = k - changes;

    for (int i = 0; i < n/2; i++) {
        if (changes == 0)
            break;

        if (s[i] != '9') {
            if (vc[i]) {
                sol[i] = '9';
                sol[n-i-1] = '9';
                changes--;
            } else if (changes > 1) {
                sol[i] = '9';
                sol[n-i-1] = '9';
                changes -= 2;
            }
        }
    }

    if (changes > 0 && n%2 != 0){
        sol[n/2] = '9';
    }

    return sol;
}
