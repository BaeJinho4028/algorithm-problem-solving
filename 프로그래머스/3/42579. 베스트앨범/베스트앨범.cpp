#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 1. 장르-횟수, 장르-노래(번호)-횟수
    map<string, int> genres_cnt;
    map<string, map<int, int>> genres_music_cnt;
    for (int i = 0; i < genres.size(); ++i) {
        genres_cnt[genres[i]] += plays[i];
        genres_music_cnt[genres[i]][i] += plays[i];
    }
    
    // 장르 모두 체크
    while (genres_cnt.size() > 0) {
        string genre = "";
        int mx = 0;
        
        // 장르 제일 높은 것 찾기
        for (auto gc : genres_cnt) {
            if (mx < gc.second) {
                genre = gc.first;
                mx = gc.second;
            }
        }
        
        // 2곡 찾기
        for (int i = 0; i < 2; ++i) {
            int idx = -1;
            int cnt = 0;
            
            // 노래 중 제일 높은 것 찾기
            for (auto gmc : genres_music_cnt[genre]) {
                if (cnt < gmc.second) {
                    idx = gmc.first;
                    cnt = gmc.second; 
                }
            }
            
            if (idx == -1) break;
            answer.push_back(idx);
            genres_music_cnt[genre].erase(idx);
        }
        genres_cnt.erase(genre);
    }
    return answer;
}
