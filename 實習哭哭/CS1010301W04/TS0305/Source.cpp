// Name: 葉珧仲
// Date: March 17, 2023
// Last Update: March 17, 2023
// Problem statement: This C++ program output some figure.
#include<iostream>
#include<string>

using namespace std;
bool drawSquare(int, int, int, char**);				//畫正方形
bool drawTriangle(int, int, int, string, char**);	//畫三角形
bool drawLine(int, int, int, int, char**);			//畫直線
void swap(int&, int&);								//交換兩數
void outputFigure(char**, int, int);				//輸出圖型

int main()
{
	int maxWidth, maxHight;
	cin >> maxWidth >> maxHight;		//輸入寬高
	char** board;
	char* Hight;
	board = new char* [maxWidth];
	for (int i = 0; i < maxWidth; i++)	//配置記憶體
	{
		board[i] = new char[maxHight];
	}
	for (int i = 0; i < maxHight; i++)	//初始化陣列
	{
		for (int j = 0; j < maxWidth; j++)
		{
			board[j][i] = '*';
		}
	}
	while (1)
	{
		string figureType;
		cin >> figureType;															//輸入圖型種類
		bool checkDraw = 0;
		if (figureType == "S")														//畫方形
		{
			int w, x, y;
			cin >> w >> x >> y;
			if (w + x > maxWidth || w + y > maxHight)								//檢查是否可以畫
				checkDraw = 0;
			else
				checkDraw = drawSquare(w, x, y, board);
		}
		else if (figureType == "T")													//畫三角形
		{
			int w, x, y;
			string figureTypeOfT;													//三角形的種類
			cin >> w >> x >> y >> figureTypeOfT;
			if (figureTypeOfT == "LU" && (x - w < 0 || y - w < 0))					//檢查是否可以畫
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
		else if (figureType == "L")													//畫直線
		{
			int x1, x2, y1, y2;
			cin >> x1 >> x2 >> y1 >> y2;
			if (x1 < 0 || maxWidth <= x1 || x2 < 0 || maxWidth <= x2 || y1 < 0 || maxHight <= y1 || y2 < 0 || maxHight <= y2)//檢查是否可以畫
				checkDraw = 0;
			else
			{
				if (x1 > x2)														//X小的排前面
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
	if (x1 == x2 || y1 == y2)				//如果為水平或鉛直線
	{
		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				board[i][j] = 'X';
			}
		}
	}
	else if (y1 > y2)						//如果為斜右上
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
	else if (y1 < y2)						//如果為斜左下
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