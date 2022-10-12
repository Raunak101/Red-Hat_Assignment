#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;

	vector<int> alpha_map(26, 0);
	for (int i = 0; i < s1.length(); i++)
		alpha_map[s1[i] - 'a']++;

	for (int j = 0; j < s2.length(); j++)
		alpha_map[s2[j] - 'a']--;

	for (int i = 0; i < 26; i++)
		if (alpha_map[i] < 0 || alpha_map[i] > 0)
			return false;

	return true;
}
int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	bool ans = checkAnagram(s1, s2);
	if (ans)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}