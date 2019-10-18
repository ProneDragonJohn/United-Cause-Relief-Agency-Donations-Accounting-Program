#include "Accounting.h"
using namespace std;

int main()
{
	string sFileLine;
	vector<string> sParsedLine;
	vector<Accounting> donations;

	ifstream fin;
	ofstream fout;
	string file;
	OpenFiles(fin, fout);
	while (!fin.eof())
		donations.push_back(readFile(sFileLine, sParsedLine, fin));
	int sArraySize = donations.size();
	for (int i = 0; i < sArraySize; i++)
		writeFile(donations[i], fout);
	int choice;
	int valueSearch;
	do
	{
		displayMenu();
		cout << "\nPlease select a report you wish to be run from menu above (1-6): ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 0:
			break;
		case 1:
			fout.close();
			cout << "Enter the name of the file: ";
			cin >> file;
			file.append(".dat");
			fout.open(file);
			createDonationHeadings(fout);
			for(int i = 0; i < sArraySize; i++)
				writeFile(donations[i], fout);

			fout.close();
			break;
		case 2:
			sortCompanyAscending(donations);
			fout.close();
			cout << "Enter the name of the file: ";
			cin >> file;
			file.append(".dat");
			fout.open(file);
			createDonationHeadings(fout);
			for (int i = 0; i < sArraySize; i++)
				writeFile(donations[i], fout);

			fout.close();
			break;
		case 3:
			sortCompanyDescending(donations);
			fout.close();
			cout << "Enter the name of the file: ";
			cin >> file;	
			file.append(".dat");
			fout.open(file);
			createDonationHeadings(fout);
			for (int i = 0; i < sArraySize; i++)
				writeFile(donations[i], fout);
			break;
		case 4:
			sortCategory(donations);
			fout.close();
			cout << "Enter the name of the file: ";
			cin >> file;
			file.append(".dat");
			fout.open(file);
			createDonationHeadings(fout);
			for (int i = 0; i < sArraySize; i++)
				writeFile(donations[i], fout);

			fout.close();
			break;
		case 5:
			sortGift(donations);
			fout.close();
			cout << "Enter the name of the file: ";
			cin >> file;
			file.append(".dat");
			fout.open(file);
			createDonationHeadings(fout);
			for (int i = 0; i < sArraySize; i++)
				writeFile(donations[i], fout);

			fout.close();
			break;
		case 6:
			fout.close();
			cout << "Does nothing as of now...";
			break;
		}
		cout << "\n";
	} while (choice != 0);

	return 0;
}


void displayMenu()
{
	cout << "United Cause Relief Agency Daily Donations Reports Menu\n"
		 << "=======================================================\n"
		 << "      1: All by Natural Order of Input File\n"
		 << "      2: All by Company name, Ascending\n"
		 << "      3: All by Company name, Descending\n"
		 << "      4: All by Category, Ascending\n"
		 << "      5: All by Gift ID, Ascending\n"
		 << "      6: One Donor only by Value, Descending\n"
		 << "      0: Exit the program\n";

}

void createDonationHeadings()
{ 
	cout << "                              United Cause Relief Agency Daily Donations\n"
		 << "                            ----------------------------------------------\n"
		 << "Gift ID   Company                          Phone             POC            Item Donated           Category       Value\n"
		 << "=======================================================================================================================\n";
} 

void createDonationHeadings(ofstream &fout)
{
	fout << "                              United Cause Relief Agency Daily Donations\n"
		<< "                            ----------------------------------------------\n"
		<< "Gift ID   Company                           Phone             POC            Item Donated           Category       Value\n"
		<< "========================================================================================================================\n";
}

void OpenFiles(ifstream &in, ofstream &out)
{
	in.open("Donations.csv");
	if (!in)
	{
		cout << "Input file did not open. Program will exit." << endl;
		exit(0);
	}

	out.open("DonationsReport.dat");
	if (!out)
	{
		cout << "Output file did not open. Program will exit." << endl;
		exit(0);
	}

}

void OpenFiles(ifstream &in, ofstream &out, string file)
{
	in.open("Donations.csv");
	if (!in)
	{
		cout << "Input file did not open. Program will exit." << endl;
		exit(0);
	}

	out.open(file);
	if(!out)
	{
		cout << "Output file did not open. Program will exit." << endl;
		exit(0);
	}

}

Accounting readFile(string &sLine, vector<string> &sParsed, ifstream &fin)
{
	getline(fin, sLine);
	stringstream lineStream(sLine);
	string field;
	sParsed.clear();

	while(getline(lineStream, field, ','))
	{
		sParsed.push_back(field);
	}
	return Accounting(sParsed[0], sParsed[1], sParsed[2], 
		sParsed[3], sParsed[4], sParsed[5], stod(sParsed[6]));
}

void writeFile(Accounting s, ofstream &fout)
{
	static int lineCount = 60;
	if (lineCount == 60)
	{
		fout << endl;
		createDonationHeadings(fout);
		lineCount = 0;
	}
	fout << setw(10) << s.getGiftID() << setw(10) << left << setw(30) << s.getCompany()
		<< "    " << left << setw(18) << s.getPhone()
		<< setw(15) << s.getPOC() << left << setw(20) << s.getItemDonated()
		<< "   " << left << setw(15) << s.getCategory() << s.getValue() << endl;
	lineCount++;
}

void writeFile(Accounting s)
{
	static int lineCount = 30;
	if (lineCount == 60)
	{
		cout << endl;
		createDonationHeadings();
		lineCount = 0;
	}
	cout << setw(10) << s.getGiftID() << setw(10) << left << setw(30) << s.getCompany()
		<< "    " << left << setw(18) << s.getPhone()
		<< setw(15) << s.getPOC() << left << setw(20) << s.getItemDonated()
		<< "   " << left << setw(15) << s.getCategory() << s.getValue() << endl;
	lineCount++;
}

void sortCompanyAscending(vector<Accounting> &s)
{
	Accounting temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (s.size() - 1); count++)
		{
			if (s[count].getCompany() > s[count + 1].getCompany())
			{
				temp = s[count];
				s[count] = s[count + 1];
				s[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void sortCompanyDescending(vector<Accounting> &s)
{
	Accounting temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (s.size() - 1); count++)
		{
			if (s[count].getCompany() < s[count + 1].getCompany())
			{
				temp = s[count];
				s[count] = s[count + 1];
				s[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void sortCategory(vector<Accounting> &s)
{
	Accounting temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (s.size() - 1); count++)
		{
			if (s[count].getCategory() > s[count + 1].getCategory())
			{
				temp = s[count];
				s[count] = s[count + 1];
				s[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void sortGift(vector<Accounting> &s)
{
	Accounting temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (s.size() - 1); count++)
		{
			if (s[count].getGiftID() > s[count + 1].getGiftID())
			{
				temp = s[count];
				s[count] = s[count + 1];
				s[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int search(vector<Accounting> s, string sLookFor)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < s.size() && !found)
	{
		if (s[index].getGiftID() == sLookFor)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}