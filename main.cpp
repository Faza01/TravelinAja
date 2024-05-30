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
    
    tambahJadwal("Bumiayu", "Purwokerto", "15:00", 5, 35000);
    tambahJadwal("Bumiayu", "Purwokerto", "13:00", 5, 35000);
    tambahJadwal("Purwokerto", "Bumiayu", "15:00", 5, 35000);
    tambahJadwal("Bojo", "Bumiayu", "12:00", 5, 35000);

    lihatJadwal();
    cout << endl;

    cout << endl;
    tambahPesanan(1, "Ojan", 2);
    tambahPesanan(2, "Ojan", 2);

    cout << endl;
    lihatPesanan();

    cout << "Layani pesanan" << endl;
    layaniPesanan();

    cout << endl;
    lihatPesanan();

    return 0;
}