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
    cout << "\nQuesta nota è importante? (0=yes / 1=no)" << endl;
    do {
        cin >> s;
    } while (s > 1 || s < 0);
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
        std::cout << "#  1 - Crea una nuova nota         #" << std::endl;
        std::cout << "#  2 - Crea una nuova collezione   #" << std::endl;
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

        switch(scelta){
            case 1:{
                //creo una nota

                string collezione;
                string tiolo, testo;
                bool lock;
                int blocca;
                cin.ignore();
                cout<< "Inserisci il titolo della nota: " <<endl;
                getline(cin, tiolo);
                cin.ignore();
                cout<<"testo nota: "<<endl;
                getline(cin, testo);
                cin.ignore();
                cout<<"bloccata? (0 = no, 1 = si): "<<endl;
                do{

                    cin>> blocca;

                    if(blocca == 0)
                        lock = false;
                    else
                        lock = true;
                }while(blocca < 0 || blocca > 1);
                auto *note = new Note (tiolo, testo, lock);
                //creaNota(*note);
                cout<< "In quale collezione vuoi inserire la nota? " <<endl;
                cin.ignore();
                getline(cin, collezione);

                auto result = controllore->ricercaCollezione(notebook, collezione);
                if(result != -1){

                    controllore->setCol(notebook[result]);
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

                string nomeCollezione;
                cout << "\n==== Creazione di una  nuova Collezione ====" << endl;
                cout << "\n \nInserire il titolo della Collezione:"<< endl;
                cin.ignore();
                getline(cin, nomeCollezione);

                auto* collezione = new Notebook(nomeCollezione);
                notebook.push_back(collezione);

                break;
            }
            case 3:{
                //modifico la nota
                string titoloCollezione;

                //findTitleCollection result{};
                //result.found = false;



                int modifica;
                string newTesto = " ";
                bool modificaEffettuata;
                do{
                    int nota;
                    cout<< "In quale collezione si trova la nota che vuoi modificare? " <<endl;
                    getline(cin, titoloCollezione);
                    auto result = controllore->ricercaCollezione(notebook, titoloCollezione);
                    if(result!=-1){
                        cout<< "Nota da modificare:  " <<endl;
                        controllore->setCol(notebook[result]);
                        controllore->ViewCol();
                        do{
                            cin>> nota;

                        }while(nota < 0 || nota > notebook[result]->CollectionSize());
                        //TODO controlli da fare nella classe collezione
                        if(controllore->IsNoteLocked(nota)){
                            cout<< "La nota è bloccata, non puoi modificarla. " <<endl;
                        }
                        else{
                            cout<< "Cosa vuoi modificare? ( 1=titolo, 2=testo) " <<endl;
                            do{
                                cin>> modifica;
                            }while(modifica < 0 || modifica > 2);
                            if(modifica == 1){
                                string newTitolo;
                                cout<< "Inserisci il nuovo titolo: " <<endl;
                                cin.ignore();
                                getline(cin, newTitolo);

                                modificaEffettuata = controllore->ModifyNote(nota, modifica, newTitolo);
                                if(modificaEffettuata){
                                    cout<< "Modifica effettuata con successo. " <<endl;
                                }
                                else{
                                    cout<< "Modifica non effettuata. " <<endl;
                                }
                            }
                            else if(modifica == 2){
                                cout<< "Inserisci il nuovo testo: " <<endl;
                                cin.ignore();
                                getline(cin, newTesto);

                                modificaEffettuata = controllore->ModifyNote(nota, modifica, newTesto);
                                if(modificaEffettuata){
                                    cout<< "Modifica effettuata con successo. " <<endl;
                                }
                                else{
                                    cout<< "Modifica non effettuata. " <<endl;
                                }
                            }

                        }


                    }
                    else{
                        cout<< "Collezione non trovata. " <<endl;
                    }
                }while(!result.found);

                break;
            }
            case 4:{
                //leggo la nota

                string collezione;
                findTitleCollection result{};
                result.found = false;
                do{

                    cout<< "In quale collezione si trova la nota che vuoi leggere? " <<endl;
                    getline(cin, collezione);
                    result = findTitle(notebook, collezione, notebook.size());
                    if(result.found && notebook[result.count]->CollectionSize() > 0){
                        cout<< "Nota da leggere:  " <<endl;
                        controllore->setCol(notebook[result.count]);
                        controllore->ViewCol();
                        int nota;
                        do{
                            cin>> nota;
                        }while(nota < 0 || nota > notebook[result.count]->CollectionSize());
                        controllore->ViewNote (nota);
                    }
                    else{
                        cout<< "Collezione non trovata o vuota. " <<endl;
                    }

                }while(!result.found);


                break;
            }
            case 5:{
                //rimuovo la nota dal notebook


                string collezione;
                findTitleCollection result{};
                result.found = false;
                do{

                    cout<< "In quale collezione si trova la nota che vuoi eliminare? " <<endl;
                    getline(cin, collezione);
                    result = findTitle(notebook, collezione, notebook.size());
                    if(result.found){
                        cout<< "Nota da eliminare:  " <<endl;
                        controllore->setCol(notebook[result.count]);
                        controllore->ViewCol();
                        int nota;
                        do{
                            cin>> nota;
                        }while(nota < 0 || nota > notebook[result.count]->CollectionSize());
                        controllore->RemoveNote (nota);
                    }
                    else{
                        cout<< "Collezione non trovata. " <<endl;
                    }

                }while(!result.found);

                break;
            }
            case 6:{
                //rimuovo il notebook


                string collezione;
                findTitleCollection result{};
                result.found = false;
                do{

                    cout<<"Quale collezione vuoi eliminare? " <<endl;
                    cin.ignore();
                    getline(cin, collezione);
                    result = findTitle(notebook, collezione, notebook.size());
                    if(result.found){
                        notebook[result.count]->~Notebook();
                        notebook.erase(notebook.begin()+result.count);
                        for(int i = result.count + 1; i < notebook.size(); i++){
                            notebook[i-1] = notebook[i];
                        }

                    }
                    else{
                        cout<< "Collezione non trovata. " <<endl;
                    }

                }while(!result.found);
                break;
            }
            case 0:{
                execute = false;
                break;
            }
            default:{
                cout<< "Scelta non valida. " <<endl;
                scelta = 0;
                break;
            }
        }

    }while(execute);


    return 0;
}
