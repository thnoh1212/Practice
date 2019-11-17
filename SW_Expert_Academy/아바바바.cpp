#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		unsigned long N;
        cin >> N;
        N = (N/2 * (1 + N -2))/2;
        cout << "#" << test_case << " " << N <<  "\n";
	}
	return 0;
}
