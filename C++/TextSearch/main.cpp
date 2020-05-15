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
#include <unistd.h>
using namespace std;


int main()
{char buf[256];
    getcwd(buf,sizeof(buf));
	string cwd = buf;
	string file = cwd+"/file.txt";
	cout<<file<<endl; //error to build folder
	//string file = "/home/qianchen/Public/learning/C++/TextSearch/file.txt";
	TextQuery t1(file);
	cout<<t1.get_text()->at(0)<<endl;
	std::string word;
	Query q1 = Query("fiery") && Query("bird") || Query("wind");

	auto result1 = q1.eval(t1);
	//auto result2 = q2.eval(t1);

	cout << q1.rep() << endl;
	cout << result1 << endl;
	//cout << result2 << endl;

	
	cin.get();
}

