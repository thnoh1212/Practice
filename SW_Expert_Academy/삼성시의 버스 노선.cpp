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
        cout << "#" << test_case;
		int bus_stop[5001] = {0};
        int N, a, b, P, temp;
        cin >> N;
        for(int i = 0; i < N ; i++){
        	cin >> a >> b;
            for(int j = a; j <= b; j++)
            	bus_stop[j] += 1;
        }
        cin >> P;
        for(int i = 0; i < P; i++){
        	cin >> temp;
            cout << " " << bus_stop[temp];
        }
        cout << "\n";
    }
	return 0;
}
