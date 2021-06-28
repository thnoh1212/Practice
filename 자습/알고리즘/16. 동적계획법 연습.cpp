#include <iostream>

int totalCount = 0;

int fibo_without_dp(int n) {
	totalCount += 1;
	if (n == 0 || n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int fibo_with_dp(int n) {
	int* array = new int[n + 1];
	array[0] = array[1] = 1;
	int count = 0;
	for (int i = 2; i <= n; i++) {
		array[i] = array[i - 1] + array[i - 2];
		count += 1;
	}
	return n;
}

int main(void)
{
	int num = fibo_without_dp(7);
	printf("%d\n", &answer);
	printf("%d", fibo_with_dp(7));
}


