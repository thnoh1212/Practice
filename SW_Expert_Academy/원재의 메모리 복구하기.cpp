#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
    	string memory;
        cin >> memory;
        int count = 0, flag = 1;
        for(int i = 0; i < memory.size(); i++){
        	if(memory[i] == flag + '0'){
            	if(flag == 0)
                    flag = 1;
                else
                    flag = 0;
                count += 1;
            }
        }
        cout << "#" << test_case << " " <<  count << "\n";
    }
    return 0;
}
