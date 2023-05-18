#include <string>
using namespace std;

class Atoi {

private:
	string beTrans;

public:
	Atoi()
	{
		beTrans = "";
	}
	Atoi(string s)
	{
		beTrans = s;
	}
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();

};