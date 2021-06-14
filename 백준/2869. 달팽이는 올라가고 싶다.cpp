#include <iostream>

using namespace std;

int main()
{
	int A, B, V;

	cin >> A >> B >> V;
	int temp = A - B;

	V -= A;
	if (V % temp != 0) {
		V /= temp;
		V += 1;
	}
	else
		V /= temp;

	cout << V + 1;
}
