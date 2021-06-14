#include <string>
#include <iostream>

using namespace std;

int main()
{
	string words, bomb, answer = "";

	cin >> words >> bomb;

	for (int i = 0; i < words.length(); i++) {
		answer += words[i];
		if (words[i] == bomb[bomb.length() - 1]) {
			int count = bomb.length() - 2;
			bool flag = 0;
			for (int j = answer.length() - 2; count >= 0; j--) {
				if (answer[j] != bomb[count--]) {
					flag = 1;
					break;
				}
			}
			
			if (flag) continue;
			else 
				answer.erase(answer.length() - bomb.length(), bomb.length());
			
		}
	}

	if (answer == "")
		cout << "FRULA";
	else
		cout << answer;

}
