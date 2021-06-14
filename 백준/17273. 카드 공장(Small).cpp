#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, int> > card;
	int N, M;
	int sum = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		card.push_back({ A, B });
	}

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		for (int i = 0; i < N; i++) {
			if (card[i].first <= temp) {
				int swap = card[i].first;
				card[i].first = card[i].second;
				card[i].second = swap;
			}
		}
	}

	for (int i = 0; i < N; i++)
		sum += card[i].first;
	cout << sum;
}
