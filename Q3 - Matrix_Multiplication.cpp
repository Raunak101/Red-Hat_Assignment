#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> transpose_matrix(vector<vector<int>> &matrix)
{
	int r = matrix.size(), c = matrix[0].size();
	vector<vector<int>> transp(r, vector<int> (c, 0));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			transp[j][i] = matrix[i][j];
		}
	}
	return transp;
}
vector<vector<int>> multiply_matrix(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
{
	int R1 = matrix1.size();
	int C2 = matrix2[0].size();
	int R2 = matrix2.size();

	vector<vector<int>> prod(R1, vector<int>(C2, 0));

	for (int i = 0; i < R1; i++)
	{
		for (int j = 0; j < C2; j++)
		{
			prod[i][j] = 0;
			for (int k = 0; k < R2; k++)
			{
				prod[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return prod;
}
int main()
{

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	vector<vector<int>> mat1(r1, vector<int>(c1, 0));
	vector<vector<int>> mat2(r2, vector<int>(c2, 0));

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			int a;
			cin >> a;
			mat1[i][j] = a;
		}
	}
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			int a;
			cin >> a;
			mat2[i][j] = a;
		}
	}

	vector<vector<int>> trans_mat1 = transpose_matrix(mat1);
	vector<vector<int>> trans_mat2 = transpose_matrix(mat2);

	vector<vector<int>> ans;
	int col1 = trans_mat1[0].size();
	int row2 = trans_mat2.size();

	if (col1 != row2)
		cout << "Dimensions of both matrix doesn't match";
	else
	{
		ans = multiply_matrix(trans_mat1, trans_mat2);
		int r = ans.size();
		int c = ans[0].size();
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << ans[i][j] << "\t";
			}
			cout << endl;
		}
	}
	return 0;
}