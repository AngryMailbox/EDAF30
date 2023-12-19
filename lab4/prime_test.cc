#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "findPrime.h"
#include <cassert>
using namespace std;

int main()
{
    findPrime fp;
    // cout << fp.getPrimeText(0, 100) << endl;
    std::vector<int> primeVector = fp.getPrimes(1, 200);

    for (int i : primeVector)
    {
        assert(fp.isPrime(i) == true);
    }

    assert(9973 == fp.getBiggestPrimeFrom(10000) && fp.isPrime(fp.getBiggestPrimeFrom(10000)));
    cout << "TEST OK" << endl;
}