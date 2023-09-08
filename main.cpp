#include <iostream>
#include "Note.h"
#include "Notebook.h"

using namespace std;

struct findTitleCollection{
    int count;
    bool found;
};

findTitleCollection findTitle(vector<Notebook*> notebook, const string &title, int n){
    findTitleCollection result{};
    result.count = 0;
    result.found = false;

    while(result.count <= n-1 && !result.found){
        if(notebook[result.count]->getTitolo() == title){
            result.found = true;
        }
        else{
            result.count++;
        }
    }

    return result;
}

void creaNota(Note& nota){
    string title;
    string text;
    bool locked;

    cout << "Inserisci il titolo della nota: ";
    cin >> title;
    cout << "Inserisci il testo della nota: ";
    cin >> text;
    cout << "Inserisci se la nota e' bloccata (0 = no, 1 = si): ";
    cin >> locked;

    nota.setTitle(title);
    nota.setText(text);
    if(locked == 0)
        nota.setLocked(false);
    else
        nota.setLocked(true);

}

int main() {
int scelta = 0;
bool execute = true;

    do{
        //creo una nota

        //creo un notebook

        //aggiungo la nota al notebook

        //stampo il notebook

        //stampo la nota

        //cambio il titolo della nota

        //rimuovo la nota dal notebook
    }while(execute);


    return 0;
}
