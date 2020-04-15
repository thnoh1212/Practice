#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 13
using namespace std;

int lotto[MAX];
bool check[MAX];
int N;

void print() {

	for (int i = 0; i < MAX; i++) {
		if (check[i] == true)
			cout << lotto[i] << " ";
	}
	cout << endl;
}

void dfs(int now, int count) {
	if (count == 6){
		print();
		return;
	}

	for (int i = now; i < N; i++) {
		if (check[i] == true) continue;
		check[i] = true;
		dfs(i, count + 1);
		check[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> N && N){
		for (int i = 0; i < N; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << endl;

	}
}
