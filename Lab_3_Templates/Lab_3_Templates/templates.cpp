#include "templates.h"
#include <math.h>
#include <stdexcept>

using namespace std;

template<class numType> int getNOD(numType a, numType b) {
    int l = a, n = b;
    while (l > 0 && n > 0) {
        if (l > n) l %= n;
        else n %= l;
    }
    return l + n;
}