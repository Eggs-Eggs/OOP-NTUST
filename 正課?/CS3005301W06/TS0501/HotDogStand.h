#pragma once
class HotDogStand
{
public:
	const char* standId;
	int hotDogSellAmount;
	static int totalSellAmount;
	HotDogStand();
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:

};

