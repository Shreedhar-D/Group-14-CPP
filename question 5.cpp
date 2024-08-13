#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);
    int n = s.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (s[j] > s[j + 1]) {
                std::swap(s[j], s[j + 1]);
            }
        }
    }
    std::cout << "Sorted string: " << s << std::endl;
    return 0;
}
