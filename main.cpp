#include <iostream>
#include <vector>
#include "Note.h"
#include "Notebook.h"
#include "Displayer.h"
#include "SetCollezioni.h"

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

void SetNoteImportance (const Note &n, Notebook &c, SetCollezioni &ctrl){
    int s;
    ctrl.setCol(&c);
    std::cout << "\nQuesta nota è importante? (0=yes / 1=no)" << std::endl;
    do {
        std::cin >> s;
    } while (s != 1 && s != 0);
    if (s == 0){
        ctrl.AddNote(n);
    }
}

int main() {
int scelta = 0;
bool execute = true;
auto *importante = new Notebook("Importante");
auto *controllore = new SetCollezioni(importante);
auto *displayer = new Displayer(controllore);
vector<Notebook*> notebook;
notebook.push_back(importante);
    do{
        std::cout << "\n\n================MENU'================\n\n" << std::endl;
        std::cout << "#==============AZIONI==============#" << std::endl;
        std::cout << "#  1 - Crea una nuova collezione   #" << std::endl;
        std::cout << "#  2 - Crea una nuova nota         #" << std::endl;
        std::cout << "#  3 - Modifica una nota           #" << std::endl;
        std::cout << "#  4 - Leggi una nota              #" << std::endl;
        std::cout << "#  5 - Eliminare una nota          #" << std::endl;
        std::cout << "#  6 - Eliminare una collezione    #" << std::endl;
        std::cout << "#  0 - Exit                        #" << std::endl;
        std::cout << "#==================================#" << std::endl;
        displayer->ShowTotal();
        std::cout << "\nCollezioni: " << std::endl;

        for(const auto itr : notebook){
            controllore->setCol(itr);
            controllore->ViewCol();
            displayer->ShowCol();
        }
        do{

            cout<< "Hai scelto: " << endl;
            cin>> scelta;
        }while(scelta < 0 || scelta > 6);
        cin.ignore();
        switch(scelta){
            case 1:{
                //creo una nota
                string collezione;
                string tiolo, testo;
                bool lock;
                int blocca;
                cin.ignore();
                cout<< "Inserisci il titolo della nota: " <<endl;
                cin>> tiolo;
                cin.ignore();
                cout<<"testo nota: "<<endl;
                cin>> testo;
                cout<<"bloccata? (0 = no, 1 = si): "<<endl;
                do{
                    cin.ignore();
                    cin>> blocca;
                    if(blocca == 0)
                        lock = false;
                    else
                        lock = true;
                }while(blocca < 0 || blocca > 1);
                auto *note = new Note (tiolo, testo, lock);
                creaNota(*note);
                cout<< "In quale collezione vuoi inserire la nota? " <<endl;
                cin.ignore();
                cin>> collezione;
                auto result = findTitle(notebook, collezione, notebook.size());
                if(result.found){
                    controllore->setCol(notebook[result.count]);
                    controllore->AddNote(*note);
                    SetNoteImportance(*note, *importante, *controllore);
                }
                else{
                    cout<< "Collezione non trovata, se ne vuole creare una nuova? (0=si, 1=no) " <<endl;
                    int creaNuovaCollezione;
                    do{
                        cin.ignore();
                        cin>> creaNuovaCollezione;
                        if(creaNuovaCollezione == 0){
                            auto *newNotebook = new Notebook(collezione);
                            notebook.push_back(newNotebook);
                            controllore->setCol(newNotebook);
                            controllore->AddNote(*note);
                            SetNoteImportance(*note, *importante, *controllore);
                        }
                        else if(creaNuovaCollezione == 1){
                            cout<< "Non è stata creata una nuova collezione. " <<endl;
                        }
                    }while(creaNuovaCollezione < 0 || creaNuovaCollezione > 1);
                }
                break;
            }
            case 2:{
                //creo un notebook
                break;
            }
            case 3:{
                //modifico la nota
                break;
            }
            case 4:{
                //leggo la nota
                break;
            }
            case 5:{
                //rimuovo la nota dal notebook
                break;
            }
            case 6:{
                //rimuovo il notebook
                break;
            }
            case 0:{
                execute = false;
            }
        }

    }while(execute);


    return 0;
}
