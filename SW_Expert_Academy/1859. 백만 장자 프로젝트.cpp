#include <iostream>

using namespace std;
int temp[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	  int N;
    cin >> N;
    for(int test_case = 1; test_case <= N; test_case++){
    	int T;
      int count = 0;
      long long sum  = 0;
      int max = 0;
      cin >> T;
        
      for(int i = 0; i < T; i++)
      	cin >> temp[i];
        
		  max = temp[T-1];
      for(int j = T-2; j >= 0; j--){
        if(temp[j] > max)
          max = temp[j];
        else
          sum += max - temp[j];
      }
      cout << "#" <<test_case <<" " << sum << "\n";
    }
    return 0;
}
