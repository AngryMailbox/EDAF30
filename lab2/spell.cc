#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include "dictionary.h"
#include "word.h"
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void check_word(const string &word, const Dictionary &dict)
{
    if (dict.contains(word))
    {
        cout << "Correct." << endl;
    }
    else
    {
        vector<string> suggestions = dict.get_suggestions(word);
        if (suggestions.empty())
        {
            cout << "Wrong, no suggestions." << endl;
        }
        else
        {
            cout << "Wrong. Suggestions:" << endl;
            for (const auto &w : suggestions)
            {
                cout << "    " << w << endl;
            }
        }
    }
}

vector<string> findTrigrams(string word)
{
    vector<string> trigrams;

    if (word.length() > 2)
    {
        for (size_t i = 0; i <= word.length() - 3; i++)
        {
            string trigram = word.substr(i, 3);
            trigrams.push_back(trigram);
        }
    }

    return trigrams;
}

string processWord(string word)
{
    if (!word.empty())
    {
        word[0] = std::tolower(static_cast<unsigned char>(word[0]));
    }
    string newLine = word + " ";

    vector<string> trigrams = findTrigrams(word);

    std::string result = word + " " + std::to_string(trigrams.size());

    for (const auto &trigram : trigrams)
    {
        result += " " + trigram;
    }

    return result;
}

int main()
{
    Dictionary dict;
    string word;

    while (cin >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        check_word(word, dict);
    }
    return 0;
}