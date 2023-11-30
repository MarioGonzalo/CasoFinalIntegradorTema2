#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct ColorConsole{
    static constexpr auto fg_black = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox{
    void new_text(){/*...*/}
    void set_text(const string &text){cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;

void load_script(const char* filename, bool show_script = false){
    string script;
    FILE* f = nullptr;
    try{
        f = fopen(filename, "rb");
        if(!f){
            cerr << "Error: no se pudo abrir el archivo " << filename << endl;
            return;
        }
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
