#include "Diary.h"
#include "Creature.h"

int main()
{

	Diary::NewDay("0000");
	Creature unknownA("UA");
	unknownA["leg"] = 16;

	Diary::NewDay("0102");
	Creature unknownB("UB", unknownA);
	unknownB["leg"] += 26;
	unknownA.PrintLog();

	Diary::NewDay("0227");
	unknownA["leg"] = 0;
	unknownA.PrintStatus();
	unknownB.PrintLog();

	Diary::NewDay("0353");
	unknownA["leg"] += 6;
	unknownA["head"] += 4;
	unknownA["hammer?"] += 4;
	unknownA["aina"] += 4;
	unknownA.PrintLog();
	cout << "==========================" << endl;
	unknownA.PrintStatus();
	unknownB.PrintStatus();
	/***********************************************************************





	
	








	***********************************************************************/

	return 0;

}
