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

    return "login_gagal";
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
        cout << "Role: " << user[i].role << endl;
        cout << endl;
    }
}

// fungsi jadwal
struct Jadwal
{
    int indexJadwal;
    string asal;
    string tujuan;
    string waktu;
    int kapasitasKursi;
    int kursiTersisa;
    int harga;
    Jadwal *next;
    Jadwal *prev;
};

int id_jadwal = 0;
Jadwal *jadwal;
Jadwal *head;
Jadwal *tail;
Jadwal *helper;
Jadwal *wanted;
Jadwal *deleted;

// jadwal keberangkatan dari bumiayu
// jadwal keberangkatan dari purwokerto

void lihatJadwal()
{
    if (head == NULL && tail == NULL)
    {
        cout << "Tidak ada jadwal yang tersedia." << endl;
    }
    else
    {
        helper = head;

        // cout << tempatAsal << "\n"
        //      << endl;
        do
        {
            cout << "Id Jadwal: " << helper->indexJadwal + 1 << endl;
            cout << "Asal: " << helper->asal << endl;
            cout << "Tujuan: " << helper->tujuan << endl;
            cout << "Waktu: " << helper->waktu << endl;
            cout << "Kursi Tersisa: " << helper->kursiTersisa << endl;
            cout << "Harga: Rp. " << helper->harga << endl;
            cout << "--------------------------" << endl;
            // if (helper->asal == tempatAsal)
            // {
            // }
            helper = helper->next;
        } while (helper != head);
    }
}

void buatJadwal(string dataAsal, string dataTujuan, string dataWaktu, int dataMaxKursi, int dataHarga)
{
    jadwal = new Jadwal;
    jadwal->indexJadwal = id_jadwal++;
    jadwal->asal = dataAsal;
    jadwal->tujuan = dataTujuan;
    jadwal->waktu = dataWaktu;
    jadwal->kapasitasKursi = dataMaxKursi;
    jadwal->kursiTersisa = dataMaxKursi;
    jadwal->harga = dataHarga;
    jadwal->next = NULL;
    jadwal->prev = NULL;
}

void cariJadwal(int dataCari)
{
    wanted = head;
    while (wanted != NULL && wanted->indexJadwal != dataCari)
    {
        wanted = wanted->next;
    }
    if (wanted == NULL)
    {
        cout << "Data yang dicari tidak ditemukan." << endl;
        return;
    }
}

// melihat jadwal + kursi yang tersisa max=5 orang
void tambahJadwal(string dataAsal, string dataTujuan, string dataWaktu, int dataMaxKursi, int dataHarga)
{
    if (head == NULL && tail == NULL)
    {
        buatJadwal(dataAsal, dataTujuan, dataWaktu, dataMaxKursi, dataHarga);
        head = jadwal;
        tail = jadwal;
    }
    else
    {
        buatJadwal(dataAsal, dataTujuan, dataWaktu, dataMaxKursi, dataHarga);
        jadwal->prev = tail;
        tail->next = jadwal;
        tail = jadwal;

        tail->next = head;
        head->prev = tail;
    }

    cout << "Jadwal berhasil ditambahkan!" << endl;
}

// void UpdateJadwal(int dataCari, string dataAsal, string dataTujuan, string dataWaktu, int dataMaxKursi)
// {
//     cariJadwal(dataCari);

//     buatJadwal(dataAsal, dataTujuan, dataWaktu, dataMaxKursi);
//     wanted->prev = jadwal;
//     jadwal->next = wanted;
//     helper->next = jadwal;
//     jadwal->prev = helper;
// }

void hapusJadwal(int dataCari)
{
    cariJadwal(dataCari);

    deleted = wanted;
    helper = wanted->prev;
    wanted = wanted->next;

    deleted->next = NULL;
    deleted->prev = NULL;

    wanted->prev = helper;
    helper->next = wanted;

    delete (deleted);
}

// fungsi pesanan
const int max_pesanan = 100;
struct Pesanan
{
    string namaPemesan[max_pesanan];
    string asal[max_pesanan];
    string tujuan[max_pesanan];
    string waktu[max_pesanan];
    int harga[max_pesanan];
    int jumlahOrang[max_pesanan];
    int depan = -1;
    int belakang = -1;
};
Pesanan pesanan;

void tambahPesanan(int tambahPesan, string dataPemesan, int jmlOrg)
{
    cariJadwal(tambahPesan - 1);

    if (wanted != NULL)
    {
        if (pesanan.depan == -1 && pesanan.belakang == -1)
        {
            pesanan.depan = 0;
            pesanan.belakang = 0;

            pesanan.namaPemesan[pesanan.belakang] = dataPemesan;
            pesanan.asal[pesanan.belakang] = wanted->asal;
            pesanan.tujuan[pesanan.belakang] = wanted->tujuan;
            pesanan.waktu[pesanan.belakang] = wanted->waktu;
            pesanan.jumlahOrang[pesanan.belakang] = jmlOrg;
            pesanan.harga[pesanan.belakang] = wanted->harga;

            wanted->kursiTersisa -= jmlOrg;

            cout << "Data berhasil masuk" << endl;
        }
        else if (pesanan.belakang != sizeof(pesanan))
        {
            pesanan.belakang++;
            pesanan.namaPemesan[pesanan.belakang] = dataPemesan;
            pesanan.asal[pesanan.belakang] = wanted->asal;
            pesanan.tujuan[pesanan.belakang] = wanted->tujuan;
            pesanan.waktu[pesanan.belakang] = wanted->waktu;
            pesanan.jumlahOrang[pesanan.belakang] = jmlOrg;
            pesanan.harga[pesanan.belakang] = wanted->harga;

            wanted->kursiTersisa -= jmlOrg;
            cout << "Data berhasil masuk" << endl;
        }
        else
        {
            cout << "antrian penuh" << endl;
        }
    }
    return;
}

void lihatPesanan()
{
    if (pesanan.depan == -1 && pesanan.belakang == -1)
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        for (int z = pesanan.depan; z <= pesanan.belakang; z++)
        {
            cout << "Pesanan ke: " << z + 1 << endl;
            cout << "Asal " << pesanan.asal[z] << " Tujuan " << pesanan.tujuan[z] << endl;
            cout << "Atas Nama: " << pesanan.namaPemesan[z] << endl;
            cout << "Waktu Penjemputan: " << pesanan.waktu[z] << endl;
            cout << "Jumlah Penumpang: " << pesanan.jumlahOrang[z] << endl;
            cout << "Harga: " << pesanan.harga[z] << endl;
            cout << "Total Harga: " << pesanan.harga[z] * pesanan.jumlahOrang[z] << endl;
            cout << endl;
        }
        cout << endl;
    }
}

void layaniPesanan()
{
    if (pesanan.depan == -1 && pesanan.belakang == -1)
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        cout << "Pesanan atas nama " << pesanan.namaPemesan[pesanan.depan] << endl;
        for (int x = pesanan.depan; x <= pesanan.belakang; x++)
        {
            pesanan.namaPemesan[x] = pesanan.namaPemesan[x + 1];
            pesanan.asal[x] = pesanan.asal[x + 1];
            pesanan.tujuan[x] = pesanan.tujuan[x + 1];
            pesanan.waktu[x] = pesanan.waktu[x + 1];
            pesanan.jumlahOrang[x] = pesanan.jumlahOrang[x + 1];
            pesanan.harga[x] = pesanan.harga[x + 1];
        }
        pesanan.belakang--;
    }
}

// void batalkanPesanan()
// {
//     // hapus pesanan
// }

// void riwayat()
// {
//     // riwayat pemesanan berdasarkan user/pengguna
// }

// // fungsi rekapPesanan
// struct rekapPesanan
// {
// };

// void rekap()
// {
// }
// // merekap semua pemesanan travel yang telah dilakukan