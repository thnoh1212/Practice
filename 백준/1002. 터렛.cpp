#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, d1;
		int x2, y2, d2;

		cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;

		int dx = x2 - x1;
		int dy = y2 - y1;
		int length = dx * dx + dy * dy;
		d1 += d2;
		int distance = d1 * d1;
		d1 -= d2 * 2;
		int chk = d1 * d1;

		if (distance > length && chk < length) cout << "2\n";
		else if (length == distance || (length != 0 && length == chk)) cout << "1\n";
		else if (chk > length || distance < length) cout << "0\n";
		else if (length == 0) {
			if (d1 - d2) cout << "-1\n";
			else cout << "0\n";
		}
	}
		
}
