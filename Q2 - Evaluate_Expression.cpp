#include "bits/stdc++.h"
using namespace std;

class Solve
{
public:
	vector<string> ans;
	void dfs(int i, string curr_path, int curr_result, string &expr, int &target)
	{
		if (i == expr.length() && curr_result == target)
		{
			ans.push_back(curr_path);
		}

		string curStr = "";
		int curNum = 0;
		for (int j = i; j < expr.length(); j++)
		{
			if (j > i && expr[j] == '0')
				break;

			curStr.push_back(expr[j]);
			curNum = curNum * 10 + (expr[j] - '0');

			if (i == 0)
				dfs(j + 1, curr_path + curStr, curNum, expr, target);
			else
			{
				dfs(j + 1, curr_path + "+" + curStr, curr_result + curNum, expr, target);
				dfs(j + 1, curr_path + "-" + curStr, curr_result - curNum, expr, target);
			}
		}
		return;
	}
	vector<string> evaluate(string &expr, int &target)
	{
		dfs(0, "", 0, expr, target);
		return ans;
	}
};
int main()
{
	Solve s;
	string a = "123456789";
	int target = 100;
	vector<string> result;
	result = s.evaluate(a, target);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}