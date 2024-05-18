#include <iostream>

using namespace std;

string inputAsal;
string inputTujuan;
string inputWaktu;
int inputMaxKursi, inputKursiTersisa;

void menuTambah()
{
    cout << "Masukkan asal: ";
    cin >> inputAsal;
    cout << "Masukkan tujuan: ";
    cin >> inputTujuan;
    cout << "Masukkan waktu keberangkatan: ";
    cin >> inputWaktu;
    cout << "Masukkan kapasitas kursi: ";
    cin >> inputMaxKursi;
    inputKursiTersisa = inputMaxKursi;
}