#include <iostream>
#include <stack>
#include <string>
using namespace std;

int alpha[26];
int main()
{
	int n;
	string str;
	cin >> n >> str;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		alpha[i] = input;
	}

	stack<double> operand;
	for (int i = 0; i < str.length(); i++)
	{
		int temp = str[i] - 'A';

		if (temp >= 0 && temp < 26)
			operand.push(alpha[temp]);
		else
		{
			if (str[i] == '+')
			{
				double second = operand.top();
				operand.pop();
				double first = operand.top();
				operand.pop();

				operand.push(first + second);
			}
			if (str[i] == '-')
			{
				double second = operand.top();
				operand.pop();
				double first = operand.top();
				operand.pop();

				operand.push(first - second);
			}
			if (str[i] == '*')
			{
				double second = operand.top();
				operand.pop();
				double first = operand.top();
				operand.pop();

				operand.push(first * second);
			}
			if (str[i] == '/')
			{
				double second = operand.top();
				operand.pop();
				double first = operand.top();
				operand.pop();

				operand.push(first / second);
			}
		}
	}

	printf("%.2lf", operand.top());
}