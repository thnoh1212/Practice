#include <iostream>

using namespace std;

int main()
{
	int N;
	int count = 1, range = 1;
	cin >> N;
	while (range < N) {
		range += 6 * count++;
	}
	cout << count;
}
