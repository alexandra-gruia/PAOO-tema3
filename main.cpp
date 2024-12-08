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

int main() {
  

    return 0;
}
