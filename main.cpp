#include <iostream>
#include <cstring> //memcpy
using namespace std;

class Resurse {
private:
    char* resurse; // resursa gestionata
    size_t dimensiune;  

public:
    // constructor 
    Resurse(size_t dim = 0) : resurse(nullptr), dimensiune(dim)
   {
        if (dimensiune > 0) {
            resurse = new char[dimensiune];
            cout << "Resursa alocata.\n";
        }
    }

 // constructor de copiere
//este apelat atunci cand un obiect este initializat cu unul deja existent
    Resurse(const Resurse& other) : dimensiune(other.dimensiune), resurse(nullptr) {
        if (dimensiune > 0) {
            resurse = new char[dimensiune];
            memcpy(resurse, other.resurse, dimensiune);
            cout << "Resursa copiata.\n";
        }
    }

    // atribuire
    //copiaza un obiect existent in altul deja creat
    Resurse& operator=(const Resurse& other) {
        if (this == &other) {
            cout << "Sursa este acelasi obiect cu cel curent! \n";
            return *this;
        }
        delete[] resurse;

        dimensiune = other.dimensiune;
        resurse = nullptr;
        if (dimensiune > 0) {
            resurse = new char[dimensiune];
            memcpy(resurse, other.resurse, dimensiune);
        }
        return *this;
    }

    // destructor
    ~Resurse() {
        delete[] resurse;
        cout << "Resursa dealocata.\n";
    }

    //Informatii despre resursa
    void afisare() const {
        if (resurse) {
            cout << "Dimensiune: " << dimensiune << " \n";
        } else {
            cout << "Nicio resursa.\n";
        }
    }
};


int main() {
  
    Resurse resursa1(10);   
    resursa1.afisare();

    Resurse resursa2 = resursa1;  // constructorul de copiere
    resursa2.afisare();

    Resurse resursa3;       
    resursa3 = resursa1;          // Operatorul de atribuire
    resursa3.afisare();

    resursa3 = resursa3;  //auto-atribuire
    return 0;
