#pragma once
#include <string>
using namespace std;

class Accounting
{
private:
	string GiftID;
	string Company;
	string Phone;
	string POC;
	string ItemDonated;
	string Category;
	double Value;

public:
	Accounting();
	Accounting(string g,
			   string co,
			   string p,
			   string poc,
			   string i,
			   string cat,
			   double v);

	bool setGiftID(string g);
	bool setCompany(string co);
	bool setPhone(string p);
	bool setPOC(string poc);
	bool setItemDonated(string i);
	bool setCategory(string cat);
	bool setValue(double v);

	string getGiftID();
	string getCompany();
	string getPhone();
	string getPOC();
	string getItemDonated();
	string getCategory();
	double getValue();
};

