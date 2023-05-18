// Name: �~����
// Date: March 17, 2023
// Last Update: March 17, 2023
// Problem statement: This C++ program output some figure.
#include<iostream>
#include<string>

using namespace std;
bool drawSquare(int, int, int, char**);				//��������
bool drawTriangle(int, int, int, string, char**);	//��������
bool drawLine(int, int, int, int, char**);			//��ֱ��
void swap(int&, int&);								//���Q�ɔ�
void outputFigure(char**, int, int);				//ݔ���D��

int main()
{
	int maxWidth, maxHight;
	cin >> maxWidth >> maxHight;		//ݔ�댒��
	char** board;
	char* Hight;
	board = new char* [maxWidth];
	for (int i = 0; i < maxWidth; i++)	//����ӛ���w
	{
		board[i] = new char[maxHight];
	}
	for (int i = 0; i < maxHight; i++)	//��ʼ�����
	{
		for (int j = 0; j < maxWidth; j++)
		{
			board[j][i] = '*';
		}
	}
	while (1)
	{
		string figureType;
		cin >> figureType;															//ݔ��D�ͷN�
		bool checkDraw = 0;
		if (figureType == "S")														//������
		{
			int w, x, y;
			cin >> w >> x >> y;
			if (w + x > maxWidth || w + y > maxHight)								//�z���Ƿ���Ԯ�
				checkDraw = 0;
			else
				checkDraw = drawSquare(w, x, y, board);
		}
		else if (figureType == "T")													//��������
		{
			int w, x, y;
			string figureTypeOfT;													//�����εķN�
			cin >> w >> x >> y >> figureTypeOfT;
			if (figureTypeOfT == "LU" && (x - w < 0 || y - w < 0))					//�z���Ƿ���Ԯ�
				checkDraw = 0;
			else if (figureTypeOfT == "LD" && (x - w < 0 || y + w > maxHight))
				checkDraw = 0;
			else if (figureTypeOfT == "RU" && (x + w > maxWidth || y - w < 0))
				checkDraw = 0;
			else if (figureTypeOfT == "RD" && (x + w > maxWidth || y + w > maxHight))
				checkDraw = 0;
			else
				checkDraw = drawTriangle(w, x, y, figureTypeOfT, board);
		}
		else if (figureType == "L")													//��ֱ��
		{
			int x1, x2, y1, y2;
			cin >> x1 >> x2 >> y1 >> y2;
			if (x1 < 0 || maxWidth <= x1 || x2 < 0 || maxWidth <= x2 || y1 < 0 || maxHight <= y1 || y2 < 0 || maxHight <= y2)//�z���Ƿ���Ԯ�
				checkDraw = 0;
			else
			{
				if (x1 > x2)														//XС����ǰ��
				{
					swap(x2, x1);
					swap(y2, y1);
				}
				checkDraw = drawLine(x1, x2, y1, y2, board);
			}
		}
		else if (figureType == "EXIT")
			break;
		if (checkDraw == 1)
			outputFigure(board, maxWidth, maxHight);
		else
			cout << "Out of range." << endl;
		cout << endl;
	}
	return 0;
}

bool drawSquare(int width, int x, int y, char** board)
{
	for (int i = x; i < width + x; i++)
	{
		for (int j = y; j < width + y; j++)
		{
			board[i][j] = 'X';
		}
	}
	return 1;
}
bool drawTriangle(int width, int x, int y, string type, char** board)
{
	int count = 1;
	if (type == "LU")
	{
		for (int i = x - width + 1; i <= x; i++)
		{
			for (int j = y; j > -count + y; j--)
			{
				board[i][j] = 'X';
			}
			count++;
		}
	}
	else if (type == "LD")
	{
		for (int i = x - width + 1; i <= x; i++)
		{
			for (int j = y; j < count + y; j++)
			{
				board[i][j] = 'X';
			}
			count++;
		}
	}
	else if (type == "RU")
	{
		count = width;
		for (int i = x; i < x + width; i++)
		{
			for (int j = y - count + 1; j <= y; j++)
			{
				board[i][j] = 'X';
			}
			count--;
		}
	}
	else if (type == "RD")
	{
		count = width;
		for (int i = x; i < x + width; i++)
		{
			for (int j = count + y - 1; j >= y; j--)
			{
				board[i][j] = 'X';
			}
			count--;
		}
	}
	return 1;
}
bool drawLine(int x1, int y1, int x2, int y2, char** board)
{
	if (x1 == x2 || y1 == y2)				//�����ˮƽ���Uֱ��
	{
		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				board[i][j] = 'X';
			}
		}
	}
	else if (y1 > y2)						//�����б����
	{
		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j >= y2; j--)
			{
				board[i][j] = 'X';
				i++;
			}
		}
	}
	else if (y1 < y2)						//�����б����
	{
		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				board[i][j] = 'X';
				i++;
			}
		}
	}
	return 1;
}
void outputFigure(char** board, int maxWidth, int maxHight)
{
	for (int i = 0; i < maxHight; i++)
	{
		for (int j = 0; j < maxWidth; j++)
		{
			cout << board[j][i];
		}
		cout << endl;
	}
}
void swap(int& a, int& b)
{
	int i = a;
	a = b;
	b = i;
}