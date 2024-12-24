#include <iostream>
#include <vector>
using namespace std;

struct tree
{
	char data;
	char leftChild;
	char rightChild;
};

tree t[26];
void preorder(int index)
{
	cout << t[index].data;
	if(t[index].leftChild != '.')
		preorder(t[index].leftChild - 'A');
	if (t[index].rightChild != '.')
		preorder(t[index].rightChild - 'A');
}

void inorder(int index)
{
	if (t[index].leftChild != '.')
		inorder(t[index].leftChild - 'A');
	cout << t[index].data;
	if (t[index].rightChild != '.')
		inorder(t[index].rightChild - 'A');
}

void postorder(int index)
{
	if (t[index].leftChild != '.')
		postorder(t[index].leftChild - 'A');
	if (t[index].rightChild != '.')
		postorder(t[index].rightChild - 'A');
	cout << t[index].data;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		int index = parent - 'A';
		t[index].data = parent;
		t[index].leftChild = left;
		t[index].rightChild = right;
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
}