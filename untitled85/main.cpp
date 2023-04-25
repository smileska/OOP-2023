#include <iostream>
#include <cstring>
using namespace std;
class DisciplinaryAction{
    char * ime;
    int indeks;
    char * prichina;
    int brSesii;
public:
    DisciplinaryAction(char * ime="", int indeks=0, char * prichina="", int brSesii=0){
        this->ime=new char[strlen(ime) + 1];
        strcpy(this->ime,ime);
        this->indeks=indeks;
        this->prichina=new char[strlen(prichina)+1];
        strcpy(this->prichina,prichina);
        this->brSesii=brSesii;
    }
    ~DisciplinaryAction(){
        delete [] ime;
        delete [] prichina;
    }
    DisciplinaryAction(const DisciplinaryAction &o){
        this->ime=new char[strlen(o.ime) + 1];
        strcpy(this->ime,o.ime);
        this->indeks=o.indeks;
        this->prichina=new char[strlen(o.prichina)+1];
        strcpy(this->prichina,o.prichina);
        this->brSesii=o.brSesii;
    }
    DisciplinaryAction &operator= (const DisciplinaryAction &o){
        if(this!=&o) {
            delete [] ime;
            delete [] prichina;
            this->ime = new char[strlen(o.ime) + 1];
            strcpy(this->ime, o.ime);
            this->indeks = o.indeks;
            this->prichina = new char[strlen(o.prichina) + 1];
            strcpy(this->prichina, o.prichina);
            this->brSesii = o.brSesii;
        }
        return *this;
    }
    int getIndex(){
        return indeks;
    }
    void setIndex(int indekx) {
        indeks=indekx;
    }

    friend ostream &operator<<(ostream &os, const DisciplinaryAction &action) {
        os << "Student: " << action.ime <<endl;
        os <<"Student's index: " << action.indeks <<endl;
        os<< "Reason: " << action.prichina <<endl;
        os<<"Sessions: "<< action.brSesii<<endl;
        return os;
    }
    DisciplinaryAction &operator++(){
        brSesii++;
        return *this;
    }

    bool operator>=(const DisciplinaryAction &rhs) const {
        return brSesii >= rhs.brSesii;
    }

};
int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator ++ and <<" << endl;
    for (int i = 0; i < n; i++)
        cout << (++arr[i]);


    cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }

    return 0;
}
