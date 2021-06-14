/*
 문자열 정렬
 각 문자열간의 사전순서 정렬은 a<b의 간결한 형태로 할 수 있음
 sort함수용 cmp함수를 만들 경우 예외처리 확실하게
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b){
	if(a.length() < b.length())
		return true;
	else if(a.length() > b.length())
		return false;
	else
		return a < b;
}

/*
bool cmp(const string a, const string b) {
	return make_tuple(a.length(), a) < make_tuple(b.length(), b);
}
*/

int main()
{
	int N;
  cin >> N;
	string *words = new string[N];

   	for (int i = 0; i < N; i++) 
    	cin >> words[i];
	
	sort(words, words + N, cmp);
	
   	string check;
   	check = words[0];
   	cout << check << '\n';
   	for (int i = 1; i < N; i++) {
      	if(check != words[i]){
        	cout << words[i] << '\n';
        	check = words[i];
      	}
   }

}
