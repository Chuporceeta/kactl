/**
* Author: Indy256
* Description: desc
*/
#include "Fft.h"





// usage example
int main() {
    vector<int> a{9, 9};
    vector<int> b{8, 9};
    vector<int> mul = multiply_bigint(a, b, 10);
    for (int x : mul)
        cout << x << " ";
    cout << endl;
}