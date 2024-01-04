#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    // 사전 순으로 먼저 정렬
    sort(words.begin(), words.end());

    // 중복 제거
    words.erase(unique(words.begin(), words.end()), words.end());

    // 길이에 따라 정렬 (길이가 같으면 사전 순으로 이미 정렬됨)
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    });

    // 결과 출력
    for (const auto &word : words) {
        cout << word << '\n';
    }

    return 0;
}
