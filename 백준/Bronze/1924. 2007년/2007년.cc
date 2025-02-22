#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	int time = 0;
	while (true)
	{
		x--;
		if (x <= 0)
			break;

		switch (x)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			time += 31;
			break;
		case 4: case 6: case 9: case 11:
			time += 30;
			break;
		case 2:
			time += 28;
			break;
		default:
			break;
		}
	}

	time += y;

	switch (time % 7)
	{
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
		break;
	default:
		break;
	}
}