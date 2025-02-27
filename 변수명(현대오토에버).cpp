#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 문자열 전체를 소문자로 변환하는 함수
string toLowerCase(const string& s) {
    string result = s;
    for (size_t i = 0; i < result.size(); i++) {
        result[i] = tolower(static_cast<unsigned char>(result[i]));
    }
    return result;
}

// 문자열의 첫 글자만 대문자로, 나머지는 소문자로 변환하는 함수
string capitalize(const string& s) {
    if (s.empty())
        return s;
    string lowerStr = toLowerCase(s);
    lowerStr[0] = toupper(static_cast<unsigned char>(lowerStr[0]));
    return lowerStr;
}

class Solution {
public:
    vector<string> ChangeInput(string input) {
        vector<string> words;
        vector<string> res(3);

        char style = input[0];
        string str = input.substr(2); // 스타일 식별자와 공백 제거
        int n = str.size();

        // 스타일에 따른 단어 분리
        if (style == '1' || style == '3') { // Camel 또는 Pascal: 대문자를 기준으로 단어 분리
            int start = 0;
            for (int i = 1; i < n; i++) {
                if ('A' <= str[i] && str[i] <= 'Z') {
                    words.push_back(str.substr(start, i - start));
                    start = i;
                }
            }
            words.push_back(str.substr(start)); // 마지막 단어 추가
        }
        else if (style == '2') { // Snake: '_'를 기준으로 단어 분리
            int start = 0;
            for (int i = 0; i < n; i++) {
                if (str[i] == '_') {
                    words.push_back(str.substr(start, i - start));
                    start = i + 1;
                }
            }
            words.push_back(str.substr(start));
        }

        // Camel Case: 첫 단어는 모두 소문자, 이후 단어는 첫 글자만 대문자로 변환
        string camel;
        if (!words.empty()) {
            camel += toLowerCase(words[0]);
            for (size_t i = 1; i < words.size(); i++) {
                camel += capitalize(words[i]);
            }
        }

        // Snake Case: 모든 단어를 소문자로 변환하고 '_'로 연결
        string snake;
        for (size_t i = 0; i < words.size(); i++) {
            if (i > 0) snake += '_';
            snake += toLowerCase(words[i]);
        }

        // Pascal Case: 각 단어의 첫 글자를 대문자로 변환하여 연결
        string pascal;
        for (const string& w : words) {
            pascal += capitalize(w);
        }

        res[0] = camel;
        res[1] = snake;
        res[2] = pascal;
        return res;
    }
};

int main() {
    Solution sol;
    string input;

    getline(cin, input);

    vector<string> res = sol.ChangeInput(input);
    cout << res[0] << "\n";
    cout << res[1] << "\n";
    cout << res[2] << "\n";

    return 0;
}
