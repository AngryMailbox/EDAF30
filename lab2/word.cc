#include <string>
#include <vector>
#include "word.h"

using std::string;
using std::vector;

Word::Word(const string &w, const vector<string> &t)
{
	word = w;
	trigrams = t;
}

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	unsigned int count = 0;

	for (auto trigram1 : t)
	{
		for (auto trigram2 : trigrams)
		{
			if (trigram1.compare(trigram2) == 0)
			{
				count++;
			}
		}
	}

	return count;
}