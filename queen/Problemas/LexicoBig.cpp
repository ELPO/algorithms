#include "LexicoBig.h"
#include <algorithm>

string LexicoBig::biggerIsGreater(string w)
{
    if (w.size() < 2)
        return "no answer";

    char prev = w.back();
    bool found = false;
    for (int i = w.length()-2; i >= 0; i--) {
        if (w[i] < prev) {
            found = true;
            for (size_t k = w.length()-1; k > i; k--) {
                if (w[k] > w[i]) {
                    //swap
                    char aux = w[i];
                    w[i] = w[k];
                    w[k] = aux;
                    break;
                }
            }

            sort(w.begin()+ i+1, w.end());
            break;
        }

        prev = w[i];
    }

    if (!found)
        return "no answer";

    return w;
}
