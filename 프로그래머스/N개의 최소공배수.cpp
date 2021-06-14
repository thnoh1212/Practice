#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int temp_1 = 0, temp_2 = 0, mod = 0;
    for(int i =0; i < arr.size() - 1; i++){
        if(arr[i] >= arr[i+1]){
            mod = arr[i] % arr[i+1];
            temp_1 = arr[i];
            temp_2 = arr[i+1];
        }
        else{
            mod = arr[i+1] % arr[i];
            temp_1 = arr[i+1];
            temp_2 = arr[i];
        }
        while(mod > 0){
            temp_1 = temp_2;
            temp_2 = mod;
            mod = temp_1 % temp_2;
        }
        arr[i+1] =  arr[i] * arr[i+1] / temp_2;
    }
    answer = arr[arr.size()-1];
    return answer;
}

/* N개의 정수의 최소 공배수를 구할 때에는,두 수의 최소공배수를 구한 후 다음 수와의 최소공배수를 구하는 방식으로 계속 진행하면 된다. */
