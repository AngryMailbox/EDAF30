#ifndef FINDPRIME_H
#define FINDPRIME_H
#include <string>
#include <vector>

class findPrime
{
public:
    findPrime(){};
    bool isPrime(int);
    std::string getPrimeText(int, int);
    std::vector<int> getPrimes(int, int);
    int getBiggestPrimeFrom(int);

private:
    int num;
    std::string primetext;
};
#endif