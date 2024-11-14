/**
* Author: Indy256
* Description: desc
*/
#include "modint.h"





constexpr int mod = (int)1e9 + 7;
using mint = modint<mod>;

// usage example
int main() {
    mint a = 1;
    mint b = 1;
    b += 1;
    mint c = 1000'000'000;
    mint d = a / b * c / c;
    cout << ((int)d) << endl;
}