#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string t_name = "";
    int max = 0;
    for(int i = 0; i < m.length(); i++){
        if(m[i + 1] == '#'){
            m[i] = m[i] + 32;
            answer = answer + m[i];
            i += 1;
        }
        else
            answer = answer + m[i];
    }
    
    for(int i = 0; i < musicinfos.size(); i++){
        int A = stoi(musicinfos[i].substr(6, 2)) - stoi(musicinfos[i].substr(0, 2));
        int B = stoi(musicinfos[i].substr(9, 2)) - stoi(musicinfos[i].substr(3, 2));
        int time = A * 60 + B;
        int cnt = 0, index = 0;
        string music = musicinfos[i].substr(12, musicinfos[i].size() - 12);
        for(index = 0; music[index] != ','; index++) continue;
        string name = music.substr(0, index);
        string sound = "";
        string temp = "";
        for(int j = index + 1; j < music.size(); j++){
            if(music[j+1] == '#'){
                music[j] = music[j] + 32;
                sound = sound + music[j];
                j += 1;
            }
            else
                sound = sound + music[j];
        }
        
        while(time > cnt + sound.size()){
            temp += sound;
            cnt += sound.size();
        }
        index = 0;
        while(time != cnt){
            if(index >= sound.size()) index = 0;
            temp = temp + sound[index++];
            cnt++;
        }
        
        if(temp.find(answer) != string::npos){
            if(max < time){
                max = time;
                t_name = name;
            }           
        }
    }
    if(t_name == "")
        return "(None)";
    else
        return t_name;
    
}
