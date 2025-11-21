#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Autobuz {
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:
    Autobuz() : idAutobuz(++nrAutobuze) {
        this->capacitate = 0;
        this->nrPersoaneImbarcate = 0;
        this->producator = new char[strlen("Necunoscut") + 1];
        strcpy(this->producator, "Necunoscut");
    }

    Autobuz(const char* producator, int capacitate, int nrPersoaneImbarcate) : idAutobuz(++nrAutobuze) {
        this->capacitate = capacitate > 0 ? capacitate : 0;
        this->nrPersoaneImbarcate = nrPersoaneImbarcate <= capacitate ? nrPersoaneImbarcate : 0;
        this->producator = new char[strlen(producator) + 1];
        strcpy(this->producator, producator);
    }

    Autobuz(const Autobuz& a) : idAutobuz(++nrAutobuze) {
        this->capacitate = a.capacitate;
        this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
        this->producator = new char[strlen(a.producator) + 1];
        strcpy(this->producator, a.producator);
    }

    ~Autobuz() {
        delete[] this->producator;
    }

    Autobuz& operator=(const Autobuz& a) {
        if (this == &a) return *this;

        delete[] this->producator;

        this->capacitate = a.capacitate;
        this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
        this->producator = new char[strlen(a.producator) + 1];
        strcpy(this->producator, a.producator);

        return *this;
    }

    friend ostream& operator<<(ostream& out, const Autobuz& a) {
        out << "ID: " << a.idAutobuz << "; Capacitate: " << a.capacitate << "; Persoane: "
            << a.nrPersoaneImbarcate << "; Producator: " << a.producator << endl;
        return out;
    }

    // Suprasarcină: operatorul +
    Autobuz operator+(int persoane) const {
        Autobuz temp = *this;
        if (temp.nrPersoaneImbarcate + persoane <= temp.capacitate) {
            temp.nrPersoaneImbarcate += persoane;
        }
        else {
            cout << "Eroare: depasire a capacitatii autobuzului!" << endl;
        }
        return temp;
    }

    // Suprasarcină: operatorul -
    Autobuz operator-(int persoane) const {
        Autobuz temp = *this;
        if (temp.nrPersoaneImbarcate - persoane >= 0) {
            temp.nrPersoaneImbarcate -= persoane;
        }
        else {
            cout << "Eroare: numarul de persoane nu poate deveni negativ!" << endl;
        }
        return temp;
    }

    // Suprasarcină: operatorul ++ (prefixat)
    Autobuz& operator++() {
        if (this->nrPersoaneImbarcate + 1 <= this->capacitate) {
            this->nrPersoaneImbarcate++;
        }
        else {
            cout << "Eroare: depasire a capacitatii autobuzului!" << endl;
        }
        return *this;
    }

    // Suprasarcină: operatorul ++ (postfixat)
    Autobuz operator++(int) {
        Autobuz temp = *this;
        ++(*this); // Folosim suprasarcina prefixată pentru a evita duplicarea codului
        return temp;
    }

    // Suprasarcină: operatorul -- (prefixat)
    Autobuz& operator--() {
        if (this->nrPersoaneImbarcate - 1 >= 0) {
            this->nrPersoaneImbarcate--;
        }
        else {
            cout << "Eroare: numarul de persoane nu poate deveni negativ!" << endl;
        }
        return *this;
    }

    // Suprasarcină: operatorul -- (postfixat)
    Autobuz operator--(int) {
        Autobuz temp = *this;
        --(*this); // Folosim suprasarcina prefixată
        return temp;
    }

    Autobuz operator+(char c) const {
        // Creează o copie temporară a obiectului curent
        Autobuz temp = *this;

        // Dimensiunea noului șir
        int lungimeNoua = strlen(temp.producator) + 2; // +1 pentru caracter, +1 pentru '\0'

        // Alocare spațiu pentru noul șir
        char* sirNou = new char[lungimeNoua];

        // Copiază șirul existent
        strcpy(sirNou, temp.producator);

        // Adaugă noul caracter la final
        sirNou[lungimeNoua - 2] = c;

        // Terminatorul de șir
        sirNou[lungimeNoua - 1] = '\0';

        // Eliberăm memoria vechiului `producator` și copiem conținutul în `temp.producator`
        delete[] temp.producator;
        temp.producator = new char[lungimeNoua]; // Alocă din nou memorie pentru `producator`
        strcpy(temp.producator, sirNou); // Copiază conținutul noului șir

        // Returnează obiectul temporar
        delete[] sirNou; // Eliberăm memoria pentru `sirNou`
        return temp;
    }



    // Suprasarcină: operatorul ()
    int operator()(int nrPersoane) {
        if (nrPersoane >= 0 && nrPersoane <= this->capacitate) {
            this->nrPersoaneImbarcate = nrPersoane;
        }
        else {
            cout << "Eroare: numarul de persoane nu este valid!" << endl;
        }
        return this->nrPersoaneImbarcate;
    }

    // Suprasarcină: operatorul []
    int operator[](int index) const {
        switch (index) {
        case 0: return this->capacitate;
        case 1: return this->nrPersoaneImbarcate;
        default:
            cout << "Eroare: index invalid!" << endl;
            return -1;
        }
    }

    char* operator[](const char* key) const {
        if (strcmp(key, "producator") == 0) {
            return this->producator;
        }
        cout << "Eroare: cheie invalida!" << endl;
        return nullptr;
    }

    static int getNrAutobuze() {
        return nrAutobuze;
    }
};

int Autobuz::nrAutobuze = 0;

int main() {
    Autobuz a1("Mercedes", 50, 20);

    // Suprasarcină: operatorul []
    cout << "Capacitate: " << a1[0] << endl;        // Accesăm capacitatea
    cout << "Nr persoane: " << a1[1] << endl;      // Accesăm nrPersoaneImbarcate
    cout << "Producator: " << a1["producator"] << endl; // Accesăm producătorul

    return 0;
}


