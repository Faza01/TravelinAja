#include "./users/menuUsers.h"

int inputUsia;
string inputUsr;
string inputPw;

void menuLogin()
{
    cin.ignore();
    cout << "\tMasukkan username: ";
    getline(cin, inputUsr);
    cout << "\tMasukkan password: ";
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
        cout << "\tLogin gagal!" << endl;
    }
}

void menuRegister()
{
    cin.ignore();
    cout << "\tMasukkan username: ";
    getline(cin, inputUsr);
    cout << "\tMasukkan password: ";
    getline(cin, inputPw);

    cout << "\tMasukkan Usia: ";
    cin >> inputUsia;

    if (inputUsia < 17)
    {
        cout << "\tMaaf minimal usia pendaftar adalah 17 Tahun" << endl;
        sleep(2);
        return;
    }
    registrasi(inputUsr, inputPw, inputUsia);
}

int main()
{
    tambahDriver("Pak Joko", "R 113", 1);
    buatJadwal("Bumiayu", "Purwokerto", 0, "07:00", 1.30, 1, 5, 35000);
    registrasi("budi", "budi123", 20);
    inisialisasiAdmin();
    int pilihan;
    do
    {
        system("cls");
        cout << "\t=== Selamat Datang Di TravelKu ===" << endl;
        cout << "\t1. Login" << endl;
        cout << "\t2. Register" << endl;
        cout << "\t3. Keluar" << endl;
        cout << "\tPilih: ";
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
            cout << "\tKeluar program." << endl;
            break;
        default:
            cout << "\tPilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);

    return 0;
}