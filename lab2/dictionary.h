#ifndef DICTIONARY_H
#include <unordered_set>
#include "word.h"
#define DICTIONARY_H

#include <string>
#include <vector>
using namespace std;

constexpr int maxlen{25};

class Dictionary
{
public:
	Dictionary();
	bool contains(const string &word) const;
	vector<string> find_trigrams(string word) const;
	vector<string> add_triagram_suggestions(const string &word) const;
	vector<string> get_suggestions(const string &word) const;
	void trim_suggestions(vector<pair<int, string>> &distSuggestions, vector<string> *suggestionsPtr) const;
	void rank_suggestions(vector<pair<int, string>> *distPtr) const;

private:
	unordered_set<string> wordSet;
	vector<Word> words[maxlen];
};

#endif