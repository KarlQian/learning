#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
#include <string.h>
using namespace std;

//excel convert , from num to letter, 27 to AA,702 to ZZ
vector<char> convertToletter(int n)
{

	vector<char> c;
	while (n != 0) {
        int mod = n%26;
        if (0==mod)
        {
            mod=26;
            c.push_back(mod + 64);
            n = n / 26 -1;
        }
        else
        {
            c.push_back(mod + 64);
            n = n / 26;
        }
    } 
    for (auto it = c.rbegin(); it != c.rend(); ++it)
		cout << *it;
	return c;
}

int main()
{
	string s;
    int sum = 0;
    while(cin>>sum){
    // int len = s.length();
    // for (int i=0;i<len;++i)
    // {
    //     sum = sum*10+s[i]-'0';
    // }
	vector<char> c = convertToletter(sum);
	
}
