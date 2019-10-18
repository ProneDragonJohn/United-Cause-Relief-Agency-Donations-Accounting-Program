#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include "AccountingClassDefined.h"
using namespace std;

void displayMenu();
void createDonationHeadings();
void createDonationHeadings(ofstream &fout);
void OpenFiles(ifstream &in, ofstream &out, string file);
void OpenFiles(ifstream &in, ofstream &out);
Accounting readFile(string &sLine, vector<string> &sParsed, ifstream &fin);
void writeFile(Accounting s, ofstream &fout);
void sortCompanyAscending(vector<Accounting> &s);
void sortCompanyDescending(vector<Accounting> &s);
void writeFile(Accounting s);
void sortCategory(vector<Accounting> &s);
void sortGift(vector<Accounting> &s);
int search(vector<Accounting> s, int sLookFor);