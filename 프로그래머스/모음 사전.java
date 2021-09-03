import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    static Set<String> set;
    String[] temp = {"A","E","I","O","U"};
    public int solution(String word) {
        int answer = 0;
        set = new HashSet<>();
        for(int i = 0; i < 5; i++) addData(temp[i], 1);
        List<String> list = new ArrayList<>(set);
        Collections.sort(list);
        answer = list.indexOf(word) + 1;
        return answer;
    }
    void addData(String word, int len){
        if(len == 5)
            set.add(word);
        else{
            addData(word, len+1);
            for(int i = 0; i < 5; i++) addData(word + temp[i], len + 1);
        }

    }
}

/*
{A, E, I ,O, U}
{" ", A, E, I, O, U}
{" ", A, E, I, O, U}
{" ", A, E, I, O, U}
{" ", A, E, I, O, U}
6480
5
1296
"A A A" == "AAA  "
-> 실제론 값 더 적게나옴.

A
AA
AAA
AAAA
AAAAA
AAAAE
AAAAI
AAAAO
AAAAU
AAAE
AAAEA
AAAEE
AAAEI
AAAEO
AAAEU
AAAI
AAAIA
AAAIE
AAAII
AAAIO
AAAIU
*/