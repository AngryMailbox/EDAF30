#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "edit_distance.h"

int edit_distance(const std::string &word1, const std::string &word2)
{
    const std::size_t len1 = word1.length();
    const std::size_t len2 = word2.length();
    std::vector<std::vector<int>> d(len1 + 1, std::vector<int>(len2 + 1));

    for (std::size_t i = 0; i <= len1; ++i)
        d[i][0] = i;
    for (std::size_t j = 0; j <= len2; ++j)
        d[0][j] = j;

    for (std::size_t i = 1; i <= len1; ++i)
    {
        for (std::size_t j = 1; j <= len2; ++j)
        {
            int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;

            d[i][j] = std::min({d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost});
        }
    }

    return d[len1][len2];
}