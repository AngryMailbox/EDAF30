#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"
#include "edit_distance.h"
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Dictionary::Dictionary()
{
	for (int i = 0; i < maxlen; ++i)
	{
		vector<Word> vec;
		words[i] = vec;
	}

	std::ifstream readFile("/Users/mans/documents/projekt/labs-edaf30/lab2/words.txt");

	if (!readFile.is_open())
	{
		std::cout << "couldn't open file" << std::endl;

		return;
	}

	string line;
	while (getline(readFile, line))
	{

		string word;
#if 0
		for (char c : line)
		{
			if (c == ' ')
			{
				break;
			}
			if (isalpha(c))
			{
				word += c;
			}
		}
#else
		std::istringstream ss(line);
		ss >> word;
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
#endif
		if (word.length() < maxlen)
		{
			words[word.length()].push_back(Word(word, find_trigrams(word)));
		}

		wordSet.insert(word);
	}
}

bool Dictionary::contains(const string &word) const
{
#if 1
	const auto &wordref = words[word.length()];
	auto iterator = std::find_if(
		wordref.begin(), wordref.end(), [&word](const Word &w)
		{ return w.get_word() == word; });
	return iterator != wordref.end();
#else
	return wordSet.find(word) != wordSet.end();
#endif
}

vector<std::string> Dictionary::find_trigrams(string word) const
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

	std::sort(trigrams.begin(), trigrams.end());

	return trigrams;
}

vector<string> Dictionary::add_triagram_suggestions(const string &word) const
{
	vector<string> suggestions;
	int length = word.length();

	for (int i = length - 1; i < length + 1; i++)
	{
		for (Word wordToMatch : words[i])
		{
			vector<string> triagrams = find_trigrams(word);
			int matches = wordToMatch.get_matches(triagrams);

			if (wordToMatch.get_word() == "federate")
			{
				cout << "found match" << endl;
				// cout << matches << endl;
				cout << triagrams.size() << endl;
			}

			if ((int)triagrams.size() / 2 <= matches)
			{
				suggestions.push_back(wordToMatch.get_word());
			}
		}
	}

	return suggestions;
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	vector<string> suggestions = add_triagram_suggestions(word);

	vector<std::pair<int, string>> distSuggestions;
	for (string suggestion : suggestions)
	{
		int distance = edit_distance(word, suggestion);
		distSuggestions.push_back(make_pair(distance, suggestion));
	}

	rank_suggestions(&distSuggestions);

	for (int i = 0; i < 7; i++)
	{
		if (i < distSuggestions.size())
			cout << i + 1 << " " << distSuggestions[i].second << endl;
	}

	suggestions.resize(0);

	trim_suggestions(distSuggestions, &suggestions);

	return suggestions;
}

void Dictionary::rank_suggestions(vector<pair<int, string>> *distPtr) const
{
	std::sort(distPtr->begin(), distPtr->end());
}

void Dictionary::trim_suggestions(vector<pair<int, string>> &distSuggestions, vector<string> *suggestionsPtr) const
{
	int count = 0;
	for (std::pair<int, string> pair : distSuggestions)
	{
		if (count++ > 4)
		{
			break;
		}
		suggestionsPtr->push_back(pair.second);
	}
}