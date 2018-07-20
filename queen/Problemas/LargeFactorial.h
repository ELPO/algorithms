#ifndef LARGEFACTORIAL_H
#define LARGEFACTORIAL_H

#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class LargeFactorial
{
public:
    static char cmult(char a, char b, int &c);

    static string add(vector<string> &in);

    static string mult(string ao, string bo);

    static void extraLongFactorials(int n);
};

#endif // LARGEFACTORIAL_H
