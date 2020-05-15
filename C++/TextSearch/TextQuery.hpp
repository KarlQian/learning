#ifndef Textquery_HPP
#define Textquery_HPP 
#include <iostream>
#include<string>
#include <memory>
#include <vector>
#include <map>
#include<set>
#include<sstream>
#include <fstream>
#include <algorithm>
#include "assert.h"
using namespace std;

class TextQuery
{
public:
	using lineno = size_t;
	TextQuery(string path):wordmap(make_shared<map<string, set<size_t>>>() ), ptext(make_shared<vector<string>>()){init(path);}
	void init(string path)
	{
		ifstream input(path);
		assert(input.is_open());
		string line = "";
		string word = "";
		size_t lineno = 0;
		while (getline(input,line))
		{
			ptext->push_back(line);
			istringstream record(line);
			while(record>>word)
			{
				if (wordmap->find(word)==wordmap->end())
				(*wordmap)[word] = set<size_t>({lineno});
				else 
				(*wordmap)[word].insert(lineno);
			} 
			lineno++;
		}
	}
	shared_ptr<vector<string>> get_text() const {return ptext;}
	shared_ptr<map<string,set<size_t>>> get_map() const {return wordmap;}

	private:
	shared_ptr<map<string,set<size_t>>> wordmap;
	shared_ptr<vector<string>> ptext;
};

#endif