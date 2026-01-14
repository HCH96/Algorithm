#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int T;
string PreOrder;
string InOrder;
map<char, int> m;

void Sol(int PreLeft, int PreRight, int InLeft, int InRight)
{
	if (PreLeft >= PreRight || InLeft >= InRight)
		return;

	char RootChar = PreOrder[PreLeft];
	int RootIdx = m[RootChar];

	int SubTreeSize = RootIdx - InLeft;

	Sol(PreLeft + 1, PreLeft + SubTreeSize + 1, InLeft, RootIdx);
	Sol(PreLeft + 1 + SubTreeSize, PreRight, RootIdx + 1, InRight);

	cout << RootChar;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	while (cin >> PreOrder >> InOrder)
	{
		m.clear();
		
		int Size = PreOrder.size();
		for (int i = 0; i < Size; ++i)
		{
			m[InOrder[i]] = i;
		}

		Sol(0, Size, 0, Size);

		cout << endl;
	}

	return 0;
}
