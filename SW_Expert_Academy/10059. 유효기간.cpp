#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
	cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        int temp;
        cin >> temp;
        int a = temp / 100;
        int b = temp % 100;
        cout << "#" << test_case << " ";
        if((a >12 && b > 12) || (a >12 && b == 0) || (a == 0 && b > 12) || (a == 0 && b == 0))
            cout << "NA\n";
        else if((b > 12 || b == 0) && (a > 0 && a < 13))
            cout << "MMYY\n";
        else if((a > 12 || a == 0) && (b > 0 && b < 13))
            cout << "YYMM\n";
        else
            cout << "AMBIGUOUS\n";
	}
	return 0;
}
