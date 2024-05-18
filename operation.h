#include <iostream>
#include <limits>

using namespace std;

struct Users
{
    string nama;
    float usia;
    string username, password;
    string role;
};

int jml_user = 0;

Users *user = new Users[99];

string Login(string dataUsr, string dataPw)
{
    for (int i = 0; i < jml_user; ++i)
    {
        if (user[i].username == dataUsr && user[i].password == dataPw)
        {
            if (user[i].role == "user")
            {
                return "user";
            }
            else if (user[i].role == "admin")
            {
                return "admin";
            }
        }
    }

    return "login_failed";
}

void Register(string dataNama, int dataUsia, string dataUsr, string dataPw)
{
    user[jml_user].nama = dataNama;
    user[jml_user].usia = dataUsia;
    user[jml_user].username = dataUsr;
    user[jml_user].password = dataPw;
    user[jml_user].role = "user";

    jml_user++;

    cout << "Berhasil mendaftar sebagai customer." << endl;
}

void Tampil(int jml_data)
{
    for (int i = 0; i < jml_data; i++)
    {
        cout << "Nama: " << user[i].nama << endl;
        cout << "Username: " << user[i].username << endl;
        cout << "Password: " << user[i].password << endl;
        cout << endl;
    }
}

// fungsi jadwal
struct Jadwal
{
    string asal;
    string tujuan;
    string waktu;
    int kapasitasKursi;
    int kursiTersisa;
    Jadwal *next;
    Jadwal *prev;
};

Jadwal *jadwal;
Jadwal *head;
Jadwal *tail;
Jadwal *helper;
Jadwal *wanted;
Jadwal *deleted;

// jadwal keberangkatan dari bumiayu
// jadwal keberangkatan dari purwokerto

void lihatJadwal(string tempatAsal)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Tidak ada jadwal yang tersedia." << endl;
    }
    else
    {
        helper = head;

        cout << tempatAsal << endl;
        do
        {
            if (helper->asal == tempatAsal)
            {
                cout << "Asal: " << helper->asal << endl;
                cout << "Tujuan: " << helper->tujuan << endl;
                cout << "Waktu: " << helper->waktu << endl;
                cout << "Kursi Tersisa: " << helper->kapasitasKursi << endl;
                cout << "--------------------------" << endl;
            }
            helper = helper->next;
        } while (helper != head);
    }
}

void buatJadwal(string dataAsal, string dataTujuan, string dataWaktu, int dataMaxKursi)
{
    jadwal = new Jadwal;
    jadwal->asal = dataAsal;
    jadwal->tujuan = dataTujuan;
    jadwal->waktu = dataWaktu;
    jadwal->kapasitasKursi = dataMaxKursi;
    jadwal->next = NULL;
    jadwal->prev = NULL;
}

void cariJadwal(string dataCari)
{
    wanted = head;
    while (wanted != NULL && wanted->nama != dataCari)
    {
        wanted = wanted->next;
    }
    if (wanted == NULL)
    {
        cout << "Data yang dicari tidak ditemukan." << endl;
        return;
    }

    helper = wanted->prev;
}

// melihat jadwal + kursi yang tersisa max=5 orang
void tambahJadwal(string dataAsal, string dataTujuan, string dataWaktu, int dataMaxKursi)
{
    if (head == NULL && tail == NULL)
    {
        buatJadwal(dataAsal, dataTujuan, dataWaktu, dataMaxKursi);
        head = jadwal;
        tail = jadwal;
    }
    buatJadwal(dataAsal, dataTujuan, dataWaktu, dataMaxKursi);
    jadwal->prev = head;
    head->next = jadwal;
    tail = jadwal;
    tail->next = head;
    head->prev = tail;

    cout << "Jadwal berhasil ditambahkan!\n";
}

void UpdateJadwal(string dataAsal, string dataTujuan, string dataWaktu, int dataMaxKursi, sting dataCari)
{
    cariJadwal(dataCari);

    buatJadwal(dataAsal, dataTujuan, dataWaktu, dataMaxKursi);
    wanted->prev = jadwal;
    helper->next = jadwal;
    jadwal->next = wanted;
    jadwal->prev = helper;
}

void hapusJadwal(string dataCari)
{
    cariJadwal(dataCari);

    deleted = helper;
    helper = helper->prev;
    deleted->next = NULL;
    deleted->prev = NULL;
    delete(deleted);

    wanted->prev = helper;
    helper->next = wanted;
}

// fungsi pesanan
struct Pesanan
{
    string namaPemesan;
    string alamatPenjemputan;
    int jumlahOrang;
    int jadwalIndex;
};

void tambahPesanan()
{
}
// input berapa orang
// input alamat penjemputan + keberangkatan

void lihatPesanan() {}
// filter berdasarkan jadwal
// filter berdasarkan barang / orang

void updatePesanan() {}
// edit pesanan
void batalkanPesanan() {}

// fungsi rekapPesanan
struct rekapPesanan
{
};

void rekap() {}
// merekap semua pemesanan travel yang telah dilakukan