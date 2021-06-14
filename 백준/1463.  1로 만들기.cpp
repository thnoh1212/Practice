#include <iostream>
#include <algorithm>

using namespace std;

int check[1000001] = { 0 };

int main()
{
	int N, count = 0;
	cin >> N;
	check[1] = 0;
	for (int i = 2; i <= N; i++) {
		check[i] = check[i - 1] + 1;

		if (i % 2 == 0)
			check[i] = std::min(check[i], check[i / 2] + 1);
		if(i % 3 == 0)
			check[i] = std::min(check[i], check[i / 3] + 1);
	}
	cout << check[N] << endl;
}
