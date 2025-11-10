#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

class Solution {
public:
    std::vector<std::string> letterCombinations(const std::string& digits) {
        if (digits.empty()) return {};

        std::map<char, std::string> digit_to_letters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        std::vector<std::string> result;
        std::string path;
        path.reserve(digits.size());

        std::function<void(int)> backtrack = [&](int index) {
            if (index == (int)digits.length()) {
                result.push_back(path);
                return;
            }

            char d = digits[index];
            auto it = digit_to_letters.find(d);
            if (it == digit_to_letters.end()) return;

            for (char letter : it->second) {
                path.push_back(letter);
                backtrack(index + 1);
                path.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};

// ✅ main() must be outside the class
int main() {
    Solution sol;
    std::vector<std::string> combos = sol.letterCombinations("23");

    for (const auto& combo : combos) {
        std::cout << combo << std::endl;
    }

    return 0;
}