#include "./users/menuUsers.h"

int inputUsia;
string inputUsr;
string inputPw;

void menuLogin()
{
    cin.ignore();
    cout << "Masukkan username: ";
    getline(cin, inputUsr);
    cout << "Masukkan password: ";
    getline(cin, inputPw);

    string role = login(inputUsr, inputPw);
    if (role == "admin")
    {
        menu_admin();
    }
    else if (role == "user")
    {
        menu_customer();
    }
    else
    {
        cout << "Login gagal!" << endl;
    }
}

void menuRegister()
{
    cin.ignore();
    cout << "Masukkan username: ";
    getline(cin, inputUsr);
    cout << "Masukkan password: ";
    getline(cin, inputPw);

    cout << "Masukkan Usia: ";
    cin >> inputUsia;
    registrasi(inputUsr, inputPw, inputUsia);
}

int main()
{
    inisialisasiAdmin();
    int pilihan;
    do
    {
        cout << "=== Menu ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            menuLogin();
            break;
        }
        case 2:
        {
            menuRegister();
            break;
        }
        case 3:
            cout << "Keluar program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);

    return 0;
}