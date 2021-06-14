#include <iostream>

using namespace std;

int main()
{
	int N;
	int count = 1, range = 1;
	cin >> N;
	while (range < N) {
		range += ++count;
	}
	if(count % 2 == 1)
		cout << range - N + 1 << '/' << count - range + N;
	else
		cout << count - range + N << '/' << range - N + 1;

}
