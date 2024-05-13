#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int>prefix_func(string str)
{
	int lenght = str.length();
	vector<int> prefix(lenght);
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (str.substr(0, j) == str.substr(i - j + 1, j))
			{
				prefix[i] = str.substr(0, j).length();
			}
		}
	}
	return prefix;
}

vector<int> z_func(string str)
{
	int lenght = str.length();
	vector<int> z(lenght);
	int left = 0, right = 0;
	for (int i = 1; i < lenght; i++) {
		if (i <= right)
		{
			z[i] = min(right - i + 1, z[i - left]);
		}
		while (i + z[i] < lenght && str[z[i]] == str[i + z[i]])
		{
			z[i]++;
		}
		if (i + z[i] - 1 > right) 
		{
			right = i + z[i] - 1;
			left = i;
		}
	}
	return z;
}
void print(vector<int> vec, string s)
{
	cout<<"String: " << s << endl;
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}
int main()
{
	string s1 = "abcdabcabcdabcdab";
	string s2 = "abacaba";

	vector<int> prefix = prefix_func(s1);
	vector<int> z = z_func(s2);

	print(prefix, s1);
	print(z, s2);
}

