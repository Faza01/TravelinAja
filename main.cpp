#include "operation.h"

string inputNama;
float inputUsia;
string inputUsr;
string inputPw;

void menuLogin()
{
    cin.ignore();
    cout << "Masukkan username: ";
    getline(cin, inputUsr);
    cout << "Masukkan password: ";
    getline(cin, inputPw);

    Register(inputNama, inputUsia, inputUsr, inputPw);
}

void menuRegister()
{
    cout << "Masukkan nama: ";
    getline(cin, inputNama);
    cout << "Masukkan Usia: ";
    cin >> inputUsia;

    cin.ignore();
    cout << "Masukkan username: ";
    getline(cin, inputUsr);
    cout << "Masukkan password: ";
    getline(cin, inputPw);

    Register(inputNama, inputUsia, inputUsr, inputPw);
}

int main()
{
    Register("Tes", 12, "Tes", "Tes");
    Tampil(jml_user);

    // menuRegister();
    // Tampil(Costumer, jml_costumer);
    return 0;
}