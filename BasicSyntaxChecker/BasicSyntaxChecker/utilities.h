#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;

void PrintLines(ifstream &infile);
void BalanceCheck(string file_name, ifstream &infile);
bool MatchingQuotes(char c, char d);
bool MatchingParens(char c, char d);
bool MatchingBlockQuotes(char c, char d, char e, ifstream &infile);


#endif
