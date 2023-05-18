#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Form
{
private:
	string inputWord;
	string fileName;
	vector<string> foundWord;
	ifstream file;
public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
