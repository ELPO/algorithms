#include "largefactorial.h"

char LargeFactorial::cmult(char a, char b, int &c) {
    int mul = (a-'0')*(b-'0')+c;
    c = mul/10;
    return (mul% 10)+'0';
}

string LargeFactorial::add(vector<string> &in) {
    string sol;
    int64_t buf = 0;
    while (in.size() > 0) {
        vector<string>::iterator it = in.begin();
        while (it != in.end()) {
            buf += it->back()-'0';
            it->pop_back();

            if (it->length() == 0) {
                it = in.erase(it);
            } else it++;
        }

        sol += (buf% 10)+'0';
        buf /= 10;
    }

    while (buf > 0) {
        sol += (buf% 10)+'0';
        buf /= 10;
    }

    string rsol(sol.rbegin(), sol.rend());
    return rsol;
}

string LargeFactorial::mult(string ao, string bo) {
    string a(ao.rbegin(),ao.rend());
    string b(bo.rbegin(),bo.rend());

    vector<string> res;
    for (int i = 0; i < a.length(); i++) {
        string localSol;
        int c = 0;
        for (int k = 0; k < b.length(); k++) {
            localSol = cmult(a[i], b[k], c) + localSol;
        }

        if (c != 0) {
            char l = c+'0';
            localSol = l + localSol;
        }

        for (int r = 0; r < i; r++) {
            localSol += '0';
        }

        res.push_back(localSol);
    }

    return add(res);
}

void LargeFactorial::extraLongFactorials(int n) {
    string ini = to_string(n);
    for (int i = n -1; i > 0; i--) {
        ini = mult(ini, to_string(i));
    }

    cout << ini << endl;
}


