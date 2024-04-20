#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct CompCountSymbol {
    bool operator()(const std::pair<char, size_t>& lhs, const std::pair<char, size_t>& rhs) const {
        if (lhs.second == rhs.second) {
            return lhs.first > rhs.first;
        }
        return lhs.second > rhs.second;
    }

};

std::map<char, size_t> get_symbol_count(const std::string& text) {
    std::map<char, size_t> symbol_to_count;
    for (char c : text) {
        ++symbol_to_count[c];
    }
    return symbol_to_count;
}

std::vector<std::pair<char, size_t>> get_sorted_symbol_to_pair(const std::map<char, size_t>& symbol_to_count) {
    std::vector<std::pair<char, size_t>> result;
    result.reserve(symbol_to_count.size());
    for (auto p : symbol_to_count) {
        result.push_back(p);
    }

    std::sort(result.begin(), result.end(), CompCountSymbol());
    return result;
}

void print_symbol_count(const std::vector<std::pair<char, size_t>>& symbol_to_count) {
    for (auto [k, v] : symbol_to_count) {
        std::cout << k << ": " << v << std::endl;
    }
}


int main() {
    std::string text = "Hello, World!!";
    std::cout << text << std::endl;

    auto symbol_to_count = get_symbol_count(text);

    auto symbol_to_count_sorted = get_sorted_symbol_to_pair(symbol_to_count);
    print_symbol_count(symbol_to_count_sorted);

    return 0;
}
