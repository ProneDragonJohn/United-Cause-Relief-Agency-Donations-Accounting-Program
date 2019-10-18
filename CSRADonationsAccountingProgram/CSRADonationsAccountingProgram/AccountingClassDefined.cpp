#include "AccountingClassDefined.h"


Accounting::Accounting()
{
	GiftID = "";
	Company = "";
	Phone = "";
	POC = "";
	ItemDonated = "";
	Category = "";
	Value = 0;
}


Accounting::Accounting(string g,
					   string co,
					   string p,
					   string poc,
					   string i,
					   string cat,
					   double v)
{
	setGiftID(g);
	setCompany(co);
	setPhone(p);
	setPOC(poc);
	setItemDonated(i);
	setCategory(cat);
	setValue(v);
}

bool Accounting::setGiftID(string g)
{
	if (g.empty())
	{
		GiftID = "invalid";
		return false;
	}
	GiftID = g;
	return true;
}

bool Accounting::setCompany(string co)
{
	if (co.empty())
	{
		Company = "invalid";
		return false;
	}
	Company = co;
	return true;
}

bool Accounting::setPhone(string p)
{
	if (p.empty())
	{
		Phone = "invalid";
		return false;
	}
	Phone = p;
	return true;
}

bool Accounting::setPOC(string poc)
{
	if (poc.empty())
	{
		POC = "invalid";
		return false;
	}
	POC = poc;
	return true;
}

bool Accounting::setItemDonated(string i)
{
	if (i.empty())
	{
		ItemDonated = "invalid";
		return false;
	}
	ItemDonated = i;
	return true;
}

bool Accounting::setCategory(string cat)
{
	if (cat.empty())
	{
		Category = "invalid";
		return false;
	}
	Category = cat;
	return true;
}

bool Accounting::setValue(double v)
{
	if (v < 0)
	{
		Value = 0;
		return false;

	}
	Value = v;
	return true;
}

string Accounting::getGiftID()
{
	return GiftID;
}
string Accounting::getCompany()
{
	return Company;
}
string Accounting::getPhone()
{
	return Phone;
}
string Accounting::getPOC()
{
	return POC;
}
string Accounting::getItemDonated()
{
	return ItemDonated;
}
string Accounting::getCategory()
{
	return Category;
}
double Accounting::getValue()
{
	return Value;
}
