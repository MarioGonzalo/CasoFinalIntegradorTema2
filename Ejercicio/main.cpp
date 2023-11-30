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

        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0){
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if(show_script){
            cout << ColorConsole::fg_black << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }

    catch(...){
        cerr << "Error: no de la lectura del archivo " << filename << endl;
        if(f)
            fclose(f);
    }
}
int main() {
    load_script("script.txt", true);
    return 0;
}
