#include <iostream>
#include <string>
#include <vector>

using namespace std;


// ======================
//     main function
// ======================
int main()
{
	int a1, b1, a2, b2;

	int** matrix1 = nullptr, ** matrix2 = nullptr, ** resultMatrix;

	cin >> a1 >> b1 >> a2 >> b2;

	if (b1 != a2)
		cout << "Matrix multiplication failed.";
	else
	{

		matrix1 = new int* [a1];
		matrix2 = new int* [a2];
		resultMatrix = new int* [a1];

		for (int i = 0; i < a1; i++)
			matrix1[i] = new int[b1];

		for (int i = 0; i < a2; i++)
			matrix2[i] = new int[b2];

		for (int i = 0; i < a1; i++)
			matrix1[i] = new int[b2];

		for (int i = 0; i < a1; i++)
			for (int j = 0; j < b1; j++)
				cin >> matrix1[i][j];

		for (int i = 0; i < a2; i++)
			for (int j = 0; j < b2; j++)
				cin >> matrix2[i][j];

		for (int i = 0; i < a1; i++)
		{
			for (int j = 0; j < b2; j++)
			{
				int sum = 0;

				for (int k = 0; k < b1; k++)
					sum += matrix1[i][k] * matrix2[k][j];

				cout << sum;

				if (j != b2 - 1)
					cout << " ";
			}

			cout << endl;
		}

	}
	return 0;
}

