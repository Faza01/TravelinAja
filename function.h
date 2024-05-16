#include "operation.h"

string Login(const Users &user)
{
    if (user.role == "admin")
    {
        return "admin";
    }
    else
    {
        return "customer";
    }
}

void Register(string dataNama, int dataUsia, string dataUsr, string dataPw)
{
    Costumer[jml_costumer].nama = dataNama;
    Costumer[jml_costumer].usia = dataUsia;
    Costumer[jml_costumer].username = dataUsr;
    Costumer[jml_costumer].password = dataPw;

    // cout << "Masukkan nama: ";
    // getline(cin, Costumer[jml_costumer].nama);
    // cout << "Masukkan Usia: ";
    // cin >> Costumer[jml_costumer].usia;

    // cin.ignore();
    // cout << "Masukkan email: ";
    // getline(cin, Costumer[jml_costumer].username);
    // cout << "Masukkan password: ";
    // getline(cin, Costumer[jml_costumer].password);

    jml_costumer++;

    cout << "Berhasil mendaftar sebagai customer." << endl;
}

void Tampil(const Users *user, int jml_data)
{
    for (int i = 0; i < jml_data; i++)
    {
        cout << "Nama: " << user[i].nama << endl;
        cout << "Username: " << user[i].username << endl;
        cout << "Password: " << user[i].password << endl;
        cout << endl;
    }
}