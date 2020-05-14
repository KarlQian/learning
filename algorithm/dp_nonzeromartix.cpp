#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
#include <string.h>
using namespace std;
/*
1230
2341
3452
equals 3*3 = 9
*/ 

size_t dp_nonzeromartix()
{
	size_t n = 0;
	size_t length = 0;
	size_t res = 1;
	string s;
	vector<vector<int>> v;
	
	while (cin >> n)
	{
		for (size_t i = 0; i < n; i++)
		{
			cin >> s;
			length = s.length();
			vector<int> vc(length,0);
			for (size_t j = 0; j < s.length(); ++j)
			{
				if (s[j]=='0')
					vc[j] = 0;
				else vc[j]=1;
			}
			v.push_back(vc);
		}
		//vector<vector<int>> dp(n, vector<int>(length, 0));
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < length; ++j)
			{
				if (v[i][j] == 0)
				{
					continue;
				}
				else
				{

					size_t sum = 1;
					size_t number = 1;
					while (sum == number*number)
					{
						sum = 0;
						number++;
						size_t margin1 = min(i + number, n);
						size_t margin2 = min(j + number, length);
						for (size_t a = i; a < margin1; a++)
							for (size_t b = j; b < margin2; b++)
								sum += v[a][b];
					}
					res = max(res, (number - 1)*(number - 1));

				}
			}
		}
		cout << res << endl;
	}
	return res;
}

int main()
{
	dp_nonzeromartix();
	return 0;

}