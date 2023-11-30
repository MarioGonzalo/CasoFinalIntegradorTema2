#include <iostream>
#include <string>
#include <cstdio>

using namespace std; // Para no escribir std:: antes de cada función de la librería estándar

// Estructura para definir los colores de la consola
struct ColorConsole{
    static constexpr auto fg_black = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

// Estructura para definir la consola
struct ConsoleBox{
    void new_text(){/*...*/}
    void set_text(const string &text){cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;

// Void para cargar el script
void load_script(const char* filename, bool show_script = false){
    string script;
    FILE* f = nullptr;
    // Manejo de errores
    try{
        f = fopen(filename, "rb");
        // Si el archivo no tiene nombre
        if (filename == nullptr || (!*filename)){
            cerr << "Error: el archivo no tiene nombre " << endl;
            return;
        }
        // Si el archivo no se puede abrir
        if(!f){
            cerr << "Error: no se pudo abrir el archivo " << filename << endl;
            return;
        }

        // Si el archivo no se puede leer
        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0){
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        // Si el archivo está vacío
        if(show_script){
            cout << ColorConsole::fg_black << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    // Se recoge el error, se muestra y se cierra el archivo
    catch(...){
        // Si el archivo no se puede leer
        cerr << "Error: fallo durante la lectura del archivo " << filename << endl;
        if(f)
            fclose(f);
    }
}
int main() {
    // Se pide el nombre del archivo y se carga
    char filename[500];
    cout << "Ruta del archivo: ";
    cin >> filename;
    load_script(filename, true);
    return 0;
}
