#include<iostream>
#include <string>
#include <vector>
using namespace std;

int decToBin(int dec) {
	int result = 0, temp = dec, j = 1;
	while (temp) {
		result = result + j * (temp % 2);
		temp = temp / 2;
		j = j * 10;
	}
	return result;
}


vector<string> split (string s,const char del)
{
	vector<string> v;
	size_t pos;
	while ((pos =s.find(del)) != string::npos)
	{
		v.push_back(s.substr(0, pos));
		s = s.substr(pos, s.length() - pos);
	}
	v.push_back(s);
	return v;
}

void checknetmask(const string& netmask)
{
	vector<string> v = split(netmask,'.');
	for (auto &elem:v)
	{
		 elem = decToBin(std::stoi(elem));
	}
}
int main()
{
	string line;
	string ip;
	string mac;
	while (getline(cin, line))
	{
		size_t pos = line.find('~');
		ip = line.substr(0, pos);
		mac = line.substr(pos + 1, line.length() - pos - 1);
		
		
	}
	return 0;
}

