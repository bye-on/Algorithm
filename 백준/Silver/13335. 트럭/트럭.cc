#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, w, L;
	cin >> n >> w >> L;

	vector<int> truck;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		truck.push_back(input);
	}

	queue<int> bridge;
	int weight = 0;
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			if (bridge.size() == w) // 트럭 하나가 다리를 다 건넜을 때
			{
				weight -= bridge.front();
				bridge.pop();
			}

			if (weight + truck[i] <= L)
				break;

			bridge.push(0); // 투명 트럭
			time++;
		}

		bridge.push(truck[i]);
		weight += truck[i];
		time++;
	}

	cout << time + w;
}