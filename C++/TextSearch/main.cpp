#include <iostream>
#include<string>
#include <memory>
#include <vector>
#include <map>
#include<set>
#include<sstream>
#include <fstream>
#include <algorithm>
#include "query.hpp"
#include "TextQuery.hpp"
using namespace std;


int main()
{
	string file = "file.txt";
    
	TextQuery t1(file);
	std::string word;
	Query q1 = Query("fiery") && Query("bird") || Query("wind");

	auto result1 = q1.eval(t1);
	//auto result2 = q2.eval(t1);

	cout << q1.rep() << endl;
	cout << result1 << endl;
	//cout << result2 << endl;

	
	cin.get();
}

