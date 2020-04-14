/*
 int형의 나눗셈의 경우 소수점 밑의 자리를 버리게 되므로 숫자가 1개 적게 나오는 경우 발생
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int check[10] = { 0 };
	int max = 0;
	string temp;
	cin >> temp;

	for (int i = 0; i < temp.length(); i++) {
		check[temp[i] - '0']++;
	}

	check[6] = (check[9] + check[6] + 1) / 2;
	check[9] = 0;
	for (int i = 0; i < 10; i++) {
		if (max < check[i])
			max = check[i];
	}

	cout << max;
}
