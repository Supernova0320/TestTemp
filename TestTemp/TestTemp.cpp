//否定用！，合取用*，析取用/，条件用-，双条件用=。
//判断：1.括号是否匹配 
//2.否定、其它联结符号之后只能是字母 3.字母之后只能是）、*、/、-、= 
//4.前括号之后是（、字母、！，后括号后是*、/、-、=、）  
#include<iostream>
#include<string>
#include<cstdio> 
#include<stack>
using namespace std;
bool judge1(string s)
{
	stack<char>stk;
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case'(':
			stk.push(s[i]);
			break;
		case')':
			if (stk.empty())
				return false;
			if (stk.top() == '(')
			{
				stk.pop();
			}
			else
			{
				return false;
			}
			break;
		default:
			break;
		}
	}
	return stk.empty();
}

bool judge2(string s)
{
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '-' || s[i + 1] == '=' || s[i + 1] == ')')
				continue;
			else
				return false;
		}

		else if (s[i] == '!')
		{
			if ((s[i + 1] >= 'A' && s[i + 1] <= 'Z')||s[i+1]=='(')
				continue;
			else
				return false;

		}
		else if (s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '=')
		{
			if ((s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] >= 'A' && s[i - 1] <= 'Z') || s[i + 1] == '(' || s[i - 1] == ')')
				continue;
			else
				return false;
		}


		else if (s[i] == '(') {
			if (s[i + 1] >= 'A' && s[i + 1] <= 'Z' || s[i + 1] == '(' || s[i + 1] == '!')
				continue;
			else
				return false;

		}

		else if (s[i] == ')') {
			if (s[i + 1] == ')' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '-' || s[i + 1] == '=')
				continue;
			else
				return false;
		}


		else if (s[i] == ' ') 
		{
			continue;
		}
		else {
			return false;
		}

	}
}
string delete_blank(string &s)
{
	string::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		if (*it == ' ')
		{
			s.erase(it);
		}
	}
	return s;
}

int main()
{
	while (1)
	{
		cout << "请输入一行任意公式" << endl;
		cout << "否定用！，合取用*，析取用/，条件用-，双条件用=" << endl;
		cout << "原子命题用大写字母表示" << endl;
		cout << "合式公式最外层的'('和')'不可省略" << endl;
		string str;
		getline(cin, str);
		int a = str.length();
		delete_blank(str);
		if (a == 1)
		{
			if (str[0] >= 'A' && str[0] <= 'Z')
				cout << "T" << endl;
			else
				cout << "F" << endl;
		}
		else
		{
			if (judge1(str))
			{
				if (judge2(str))
					cout << "T" << endl;
				else
					cout << "F" << endl;
			}
			else
				cout << "F" << endl;
		}
		system("pause");
		system("cls");
	}
}