/*
 정렬문제
 sort함수 간략화
*/

#include <iostream>
#include <algorithm>

using namespace std;

int Sum(string a)
{
	int sum = 0;
	for(int i = 0; i < a.length(); i++){
		
		if(a[i] - '0' >= 0 && a[i] - '0' <= 9){
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool cmp(const string a, const string b)
{
	if(a.length() != b.length())
		return a.length() < b.length();
	else
	{
		int a_sum = Sum(a);
		int b_sum = Sum(b);
		
		if(a_sum != b_sum)
			return a_sum < b_sum;
		else
			return a < b;
	}
}

int main(void)
{
	int n;
	cin >> n;
	string *serial = new string[n];
	
	for(int i = 0; i < n; i++)
		cin >> serial[i];
	
	sort(serial, serial + n, cmp);
	
	for(int i = 0; i < n; i++)
		cout << serial[i] << endl;
	

	return 0;
}
