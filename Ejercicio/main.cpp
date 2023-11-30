#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct ColorConsole{
    static constexpr auto fg_black = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
