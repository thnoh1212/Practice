/*
  주어지는 정수형의 크기가 100 <= num <= 10^10000 의 크기이므로, 문자열의 형태로 값을 받은 후
  문자열의 길이를 통해 값의 크기 파악, 유효숫자는 앞의 2자리이므로 반올림을 판단할 3번째 값을 제외하곤
  연산에 필요가 없음.
  아스키 값을 통해 연산. 9 다음의 값이 :임을 생각하여 연산. 반올림을 통해 9 -> 10으로 되는 경우의
  예외처리 
*/

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
        string temp;
        int num;
        cin  >> temp;        
        num =  temp.size() - 1;
        
        if(temp[2] >= '5')
        {
        	temp[1] += 1;
            if(temp[1] == ':')
            {
                temp[1] = '0';
                temp[0] += 1;
                if(temp[0] == ':')
                {
                	temp[0] = '1';
                    num += 1;
                }   
            }
        }
    	cout << "#" << test_case << " " << temp[0] << '.' << temp[1] <<
       		"*10^" << num << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
