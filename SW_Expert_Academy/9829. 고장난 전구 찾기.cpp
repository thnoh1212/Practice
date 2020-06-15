#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        bool chk[101] = { false };
        bool answer[101] = { false };
        vector<vector<int> > bulbs;

        int L, S, cnt = 0;
        cin >> L >> S;

        for (int i = 0; i < S; i++) {
            cnt = 0;
            vector<int> bulb;
            for (int j = 0; j < L; j++) {
                int temp;
                cin >> temp;
                if (temp == 1)
                    cnt++;
                 bulb.push_back(temp);
            }
            if (cnt > L / 2)
                chk[i] = true;
            bulbs.push_back(bulb);
        }

        for (int i = 0; i < S; i++) {
            if (chk[i]){
                for (int j = 0; j < L; j++) {
                    if (answer[j]) continue;
                    else {
                        if (!bulbs[i][j])
                            answer[j] = true;
                    }
                }
            }
            else {
                for (int j = 0; j < L; j++) {
                    if (answer[j]) continue;
                    else {
                        if (bulbs[i][j])
                            answer[j] = true;
                    }
                }
            }
        }
        for (int k = 0; k < L; k++) {
            if (!answer[k]) 
                cout << "#" << test_case << " " << k + 1 << "\n";
        }
    }
    return 0;
}
