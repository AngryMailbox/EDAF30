#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "findPrime.h"

bool findPrime::isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    else if (num == 2)
    {
        return true;
    }
    else
    {
        for (auto i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

string findPrime::getPrimeText(int num1, int num2)
{
    // generate string of num2-num1 number of P's
    string primetext;
    for (auto i = num1; i < num2; i++)
    {
        primetext += "P";
    }
    return primetext;
}

std::vector<int> findPrime::getPrimes(int num1, int num2)
{
    std::string text = getPrimeText(num1, num2);
    std::vector<int> primes;

    int pos = 0;

    while (true)
    {
        auto i = text.find_first_of('P', pos);
        if (i == std::string::npos)
        {
            break;
        }

        int num = i + num1;
        if (isPrime(num))
        {
            primes.push_back(num);
            pos = i + 1;

            // replace all multiples of num with C
            for (auto j = num; j < num2; j += num)
            {
                text[j - num1] = 'C';
            }
        }
        else
        {
            text[i] = 'C';
            pos = i + 1;
        }
    }
    return primes;
}

int findPrime::getBiggestPrimeFrom(int from)
{

    std::string text = getPrimeText(0, from);

    while (true)
    {
        if (text.find_last_of('P') == string::npos)
        {
            break;
        }
        auto i = text.find_last_of('P');
        int num = i;
        if (isPrime(num))
        {
            return num;
        }
        else
        {
            // replace all lesser multiples of num with C
            for (auto j = num; j > 0; j -= num)
            {
                text[j] = 'C';
            }
        }
    }

    return 0;
}