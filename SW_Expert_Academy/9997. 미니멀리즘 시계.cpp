#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int temp;
        cin >> temp;
        temp *= 2;
        int hour = temp / 60;
        int minute = temp - (hour * 60);
        if(hour == 12)
            hour = 0;
        cout <<"#" << test_case << " " << hour << " " << minute << "\n";
    }
	return 0;
}
