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

int dp_nonzeromartix()
{
	int n;
	int length;
	int res = 1;
	string s;
	vector<vector<int>> v;
	
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			length = s.length();
			vector<int> vc(length,0);
			for (int j = 0; j < s.length(); ++j)
			{
				if (s[j]=='0')
					vc[j] = 0;
				else vc[j]=1;
			}
			v.push_back(vc);
		}
		//vector<vector<int>> dp(n, vector<int>(length, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < length; ++j)
			{
				if (v[i][j] == 0)
				{
					continue;
				}
				else
				{

					int sum = 1;
					int number = 1;
					while (sum == number*number)
					{
						sum = 0;
						number++;
						int margin1 = min(i + number, n);
						int margin2 = min(j + number, length);
						for (int a = i; a < margin1; a++)
							for (int b = j; b < margin2; b++)
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

