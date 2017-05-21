#include "utilities.h"

void BalanceCheck(string file_name, ifstream &infile)
{
	infile.open(file_name.c_str());
	bool match = true;
	stack <char> S;
	char c, d, e;
	int counter = 0;
	int lineNumber = 1;
	stack<int> lines;

	while (infile.get(c))
	{
		if (c == '\n')
			lineNumber++;
		// if c is a // comment, read in until the end of a line
		if (c == '/' && infile.peek() == '/')
		{
			while (c != '\n')
				infile.get(c);
			lineNumber++;
		}
		if (c == '\'')
		{
			// put ' on the stack
			S.push(c);
			infile.get(c);
			do
			{
				if (!infile.get(c))
				{
					cout << "unbalanced symbol \' on line " << lineNumber << endl;
					match = false;
					return;
				}
			} while (c != '\'');

			d = S.top();
			S.pop();
			if (MatchingQuotes(c, d))
			{
				cout << "pair matching " << c << " and " << d << endl;
				match = true;
			}
			if (!MatchingQuotes(c, d))
			{
				if (match == true)
				{
					cout << "unbalanced symbol \' on line " << lineNumber << endl;
					match = false;
					break;
				}
			}
		}
		if (c == '\"')
		{
			// put ' on the stack
			S.push(c);
			infile.get(c);
			do
			{
				if (!infile.get(c))
				{
					cout << "unbalanced symbol \" on line " << lineNumber;
					break;
				}
			} while (c != '"');
			d = S.top();
			S.pop();
			if (MatchingQuotes(c, d))
			{

				cout << "pair matching " << c << " and " << d << endl;
				match = true;
			}
			if (!MatchingQuotes(c, d))
			{
				cout << "unbalanced symbol \" on line " << lineNumber << endl;
				match = false;
				break;
			}
		}
		// if c is a /*
		if (c == '/' && infile.peek() == '*')
		{
			// put /* on the stack
			S.push(c);
			infile.get(c);
			S.push(c);
			while (c != '*' && infile.peek() != '/')
			{
				infile.get(c);
			}
			if (infile.peek(), infile.eof())
			{
				cout << "unbalanced symbol /* on line " << lineNumber << endl;
				break;
			}
		}
		else if (c == '*' && infile.peek() == '/')
		{
			char f = infile.peek();
			if (S.empty())
			{
				match = false;
				cout << "unbalanced symbol " << c << f << " at line " << lineNumber << endl;
				break;
			}
			d = S.top();
			S.pop();
			e = S.top();
			S.pop();

			if (MatchingBlockQuotes(c, d, e, infile))
			{

				cout << "pair matching " << e << d << " and " << c << f << endl;
				match = true;
			}
			if (!MatchingBlockQuotes(c, d, e, infile))
			{
				cout << "unbalanced" << c << f << "symbol on line " << lineNumber;
				match = false;
			}
		}
		// if c is a (, {, or [, push onto the stack
		if (c == '(' || c == '{' || c == '[')
		{
			S.push(c);
			lines.push(lineNumber);
		}
		// if c is a ), }, or ]
		else if (c == ')' || c == '}' || c == ']')
		{
			//if the stack is empty, return false
			if (S.empty())
			{
				cout << "unbalanced symbol " << c << " at line " << lineNumber << endl;
				match = false;
				break;
			}

			d = S.top();
			S.pop();
			if (MatchingParens(c, d))
			{
				lines.pop();
				cout << "pair matching " << d << " and " << c << endl;
				match = true;
			}
			// if c and d are not matching parenthesis return false

			if (!MatchingParens(c, d))
			{
				cout << "unbalanced " << c << " symbol at line " << lineNumber << endl;
				match = false;
				break;
			}
		}
	}
	if (!S.empty())
	{
		cout << "unbalanced symbol " << S.top() << " at line " << lines.top() << endl;
		match = false;
	}

	if (match == true)
		cout << "Balance is OK!" << endl;
	if (match == false)
		cout << "Balance is BAD" << endl;
}


void PrintLines(ifstream &infile)
{
	string line;
	int i = 1;
	while (getline(infile, line))
	{
		cout << setw(3) << i << " " << line << endl;
		i++;
	}
	infile.close();
}

bool MatchingBlockQuotes(char c, char d, char e, ifstream &infile)
{
	if (c == '*' && infile.peek() == '/' && d == '*' && e == '/')
		return true;

	else return false;
}

bool MatchingQuotes(char c, char d)
{
	if (c == '"' && d == '"')
		return true;
	else if (c == '\'' && d == '\'')
		return true;
	else return false;
}

bool MatchingParens(char c, char d)
{
	if (c == '}' && d == '{')
		return true;
	else if (c == ')' && d == '(')
		return true;
	else if (c == ']' && d == '[')
		return true;
	else return false;
}