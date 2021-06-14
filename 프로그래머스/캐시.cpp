// 벡터에는 pop_front가 없으므로 이를 대체하기 위해 v.erase(v.begin()) 사용

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cnt = 0;
    vector<string> cache;
    
    if(cacheSize == 0)// 캐시 사이즈가 0인경우는 모든 경우가 cache miss
        return cities.size() * 5;
    
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    
    for(auto a = cities.begin(); a != cities.end(); a++){
        if(cnt == 0){ // 시작
            cache.push_back(*a);
            answer += 5;
            cnt++;
        }
        else{ // 그 외
            int flag = -1;
            for(int i = 0; i < cnt; i++){
                if(cache[i] == *a){
                    flag = i;
                    break;
                }
            }
            if(flag != -1){ // flag == -1 인 경우를 제외하고는 cache hit. 이 경우 이번에 사용한 값을 cache의 맨 마지막으로 이동
                answer += 1;
                cache.erase(cache.begin() + flag);
                cache.push_back(*a);
            }
            else{// cache miss인 경우
                if(cnt < cacheSize){// 캐시 용량이 남아있는 경우 cache에 이번 값 추가
                    cache.push_back(*a);
                    answer += 5;
                    cnt++;
                }
                else{// 캐시 용량이 가득 찬 경우 가장 마지막에 사용한 값 삭제 후 이번값 추가
                    cache.push_back(*a);
                    cache.erase(cache.begin());
                    answer += 5;
                }
            }
        }
    }
    return answer;
}
