#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "Problemas/LexicoBig.h"

int main()
{
    string w = "dkhc";
    cout << LexicoBig::biggerIsGreater(w) << endl;

    int b = 1;
    int a = 1000000;
    cout << (int)(ceil(2.0*a/b));

    return 0;
}
