#include <iostream>
#include <limits>
#include <unistd.h>

using namespace std;

struct User
{
    string username;
    string password;
    float usia;
    string role;
};

const int MAX_USER = 99;
int jml_user = 0;
User *users = new User[MAX_USER];

void inisialisasiAdmin()
{
    users[jml_user++] = {"admin", "admin", 30, "admin"};
}

string login(string username, string password)
{
    for (int i = 0; i < jml_user; i++)
    {
        if (users[i].username == username && users[i].password == password)
        {
            return users[i].role;
        }
    }
    return "login_gagal";
}

void registrasi(string username, string password, float usia)
{
    for (int i = 0; i < jml_user; i++)
    {
        if (users[i].username == username)
        {
            cout << "\tUsername sudah digunakan" << endl;
            return;
        }
    }
    if (jml_user < MAX_USER)
    {
        users[jml_user++] = {username, password, usia, "user"};
        cout << "\tBerhasil mendaftar sebagai customer." << endl;
        sleep(2);
    }
    else
    {
        cout << "\tUser limit reached" << endl;
        sleep(2);
    }
}

void tampilUser()
{
    for (int i = 0; i < jml_user; i++)
    {
        cout << "\tUsername: " << users[i].username << endl;
        cout << "\tPassword: " << users[i].password << endl;
        cout << "\tRole: " << users[i].role << endl
             << endl;
    }
}

const int MAX_SUPIR = 10;
struct Driver
{
    string nama;
    string plat_nomor;
    bool status;
};
Driver drivers[MAX_SUPIR];
int jumlah_supir = 0;

void tambahDriver(string nama, string plat_nomor, bool status)
{
    for (int i = 0; i < jumlah_supir; i++)
    {
        if (drivers[i].nama == nama)
        {
            cout << "\tSupir ini sudah ada" << endl;
            return;
        }
    }
    if (jumlah_supir < MAX_SUPIR)
    {
        drivers[jumlah_supir++] = {nama, plat_nomor, status};
    }
    else
    {
        cout << "\tSupir sudah penuh" << endl;
        sleep(2);
    }
}

void tampilDriver()
{
    if (jumlah_supir == 0)
    {
        cout << "\tMaaf Belum ada data Supir" << endl;
        return;
    }

    for (int i = 0; i < jumlah_supir; i++)
    {
        cout << "\t" << i + 1 << ". Nama: " << drivers[i].nama << endl;
        cout << "\tPlat: " << drivers[i].plat_nomor << endl;
        cout << "\tStatus: " << (drivers[i].status ? "Aktif" : "Tidak Aktif") << endl;
    }
}

bool cekDriver(int index)
{
    if (index < 0 || index >= jumlah_supir)
    {
        cout << "\tDriver tidak ditemukan." << endl;
        return false;
    }
    else if (!drivers[index].status)
    {
        cout << "\tDriver tidak aktif" << endl;
        return false;
    }
    return true;
}

struct Jadwal
{
    int id;
    string asal;
    string tujuan;
    string hari;
    string waktu;
    float estimasi;
    string supir;
    int kursi;
    int harga;
    Jadwal *next;
    Jadwal *prev;
};

const int MAX_HARI = 7;
const string HARI[MAX_HARI] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
int id_jadwal = 0;
Jadwal *jadwal;
Jadwal *head = NULL;
Jadwal *tail = NULL;

void buatJadwal(string asal, string tujuan, int hariIndex, string waktu, float estimasi, int supir, int kursi, int harga)
{
    jadwal = new Jadwal{id_jadwal++, asal, tujuan, HARI[hariIndex], waktu, estimasi, drivers[supir - 1].nama, kursi, harga, NULL, NULL};
    if (!head && !tail)
    {
        head = tail = jadwal;
        head->next = head->prev = head;
    }
    else
    {
        tail->next = jadwal;
        jadwal->prev = tail;
        jadwal->next = head;
        head->prev = tail = jadwal;
    }
}

void tambahJadwal()
{
    if (jumlah_supir == 0)
    {
        cout << "\tMaaf Belum ada data Supir" << endl;
        cout << "\tData supir diperlukan untuk membuat jadwal!" << endl;
        cout << "\tSilahkan tambah supir terlebih dahulu..." << endl;
        return;
    }

    string asal, tujuan, waktu;
    int hariIndex, estimasi, kursi, harga, pilihSupir;
    cin.ignore();
    cout << "\tMasukkan asal: ";
    getline(cin, asal);
    cout << "\tMasukkan tujuan: ";
    getline(cin, tujuan);
    cout << "\tMasukkan hari (0-6): ";
    cin >> hariIndex;
    if (hariIndex < 0 || hariIndex >= MAX_HARI)
    {
        cout << "\tHari index tidak valid." << endl;
        return;
    }
    cout << "\tMasukkan waktu: ";
    cin >> waktu;
    cout << "\tMasukkan estimasi: ";
    cin >> estimasi;

    // memilih supir
    tampilDriver();
    cout << "\tPilih supir (masukkan nomor): ";
    cin >> pilihSupir;

    if (pilihSupir < 1 || pilihSupir > jumlah_supir)
    {
        cout << "\tPilihan tidak valid." << endl;
        return;
    }
    cout << "\tMasukkan jumlah kursi: ";
    cin >> kursi;
    cout << "\tMasukkan harga: ";
    cin >> harga;

    buatJadwal(asal, tujuan, hariIndex, waktu, estimasi, pilihSupir, kursi, harga);
    cout << "\tJadwal berhasil ditambahkan!" << endl;
}

void lihatJadwal()
{
    if (!head && !tail)
    {
        cout << "\tTidak ada jadwal yang tersedia." << endl;
        return;
    }
    Jadwal *current = head;
    do
    {
        cout << "\tId Jadwal: " << current->id + 1 << endl;
        cout << "\tAsal          : " << current->asal << endl;
        cout << "\tTujuan        : " << current->tujuan << endl;
        cout << "\tHari          : " << current->hari << endl;
        cout << "\tWaktu         : " << current->waktu << endl;
        cout << "\tEstimasi      : " << current->estimasi << " jam" << endl;
        cout << "\tSupir         : " << current->supir << endl;
        cout << "\tKursi Tersisa : " << current->kursi << endl;
        cout << "\tHarga         : Rp. " << current->harga << endl;
        cout << "\t--------------------------" << endl;
        current = current->next;
    } while (current != head);
}

Jadwal *cariJadwal(int id)
{
    Jadwal *current = head;
    if (!current)
        return NULL;
    do
    {
        if (current->id == id)
            return current;
        current = current->next;
    } while (current != head);
    return NULL;
}

void hapusJadwal(int id)
{
    Jadwal *target = cariJadwal(id);
    if (!target)
    {
        cout << "\tData yang dicari tidak ditemukan." << endl;
        return;
    }
    if (target == head && target == tail)
    {
        head = tail = NULL;
    }
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        if (target == head)
            head = head->next;
        if (target == tail)
            tail = tail->prev;
    }

    // Jadwal *current = target->next;
    // while (current != head)
    // {
    //     current->id -= 1;
    //     current = current->next;
    // }

    delete target;
    cout << "\tJadwal berhasil dihapus!" << endl;
}

const int MAX_PESANAN = 100;
struct Pesanan
{
    string namaPemesan[MAX_PESANAN];
    string asal[MAX_PESANAN];
    string alamat_asal[MAX_PESANAN];
    string tujuan[MAX_PESANAN];
    string alamat_tujuan[MAX_PESANAN];
    string noHp[MAX_PESANAN];
    string waktu[MAX_PESANAN];
    float estimasi[MAX_PESANAN];
    int harga[MAX_PESANAN];
    int jumlahOrang[MAX_PESANAN];
    string status[MAX_PESANAN];
    string driver[MAX_PESANAN];
};
Pesanan pesanan;
int pesananDepan = -1;
int pesananBelakang = -1;

Pesanan riwayatPesanan;
int posisiRiwayat = -1;

const string STATUS[2] = {"Belum Bayar", "Sukses"};

void tambahPesanan()
{
    string namaPemesan, alamat_asal, alamat_tujuan, noHp;
    int jadwalId, jumlahOrang;

    cout << "\tMasukkan ID jadwal: ";
    cin >> jadwalId;

    Jadwal *jadwal = cariJadwal(jadwalId - 1);
    if (!jadwal)
    {
        cout << "\tJadwal tidak ditemukan." << endl;
        return;
    }

    if (jadwal->kursi == 0)
    {
        cout << "\tMaaf tiket untuk travel ini sudah habis" << endl;
        return;
    }

    cin.ignore();
    cout << "\tPesanan atas Nama: ";
    getline(cin, namaPemesan);
    cout << "\tMasukkan alamat asal: ";
    getline(cin, alamat_asal);
    cout << "\tMasukkan alamat tujuan: ";
    getline(cin, alamat_tujuan);
    cout << "\tMasukkan no HP: ";
    cin >> noHp;
    cout << "\tMasukkan jumlah orang: ";
    cin >> jumlahOrang;
    if (jumlahOrang > jadwal->kursi)
    {
        cout << "\tMaaf, kursi tidak cukup" << endl;
        return;
    }

    if (pesananDepan == -1 && pesananBelakang == -1)
    {
        pesananDepan = pesananBelakang = 0;
    }
    else
    {
        pesananBelakang++;
    }
    int idP = pesananBelakang;
    pesanan.namaPemesan[idP] = namaPemesan;
    pesanan.asal[idP] = jadwal->asal;
    pesanan.alamat_asal[idP] = alamat_asal;
    pesanan.tujuan[idP] = jadwal->tujuan;
    pesanan.alamat_tujuan[idP] = alamat_tujuan;
    pesanan.noHp[idP] = noHp;
    pesanan.waktu[idP] = jadwal->waktu;
    pesanan.estimasi[idP] = jadwal->estimasi;
    pesanan.jumlahOrang[idP] = jumlahOrang;
    pesanan.harga[idP] = jadwal->harga;
    pesanan.status[idP] = STATUS[0];
    pesanan.driver[idP] = jadwal->supir;

    jadwal->kursi -= jumlahOrang;
    cout << "\tPesanan berhasil ditambahkan." << endl;
}

void lihatPesanan()
{
    if (pesananDepan == -1 && pesananBelakang == -1)
    {
        cout << "\tTidak ada pesanan." << endl;
        return;
    }
    for (int i = pesananDepan; i <= pesananBelakang; i++)
    {
        cout << "\tPesanan ke-" << i + 1 << endl;
        cout << "\tNama Pemesan  : " << pesanan.namaPemesan[i] << endl;
        cout << "\tAsal          : " << pesanan.asal[i] << endl;
        cout << "\tAlamat Asal   : " << pesanan.alamat_asal[i] << endl;
        cout << "\tTujuan        : " << pesanan.tujuan[i] << endl;
        cout << "\tAlamat Tujuan : " << pesanan.alamat_tujuan[i] << endl;
        cout << "\tNo. HP        : " << pesanan.noHp[i] << endl;
        cout << "\tWaktu         : " << pesanan.waktu[i] << endl;
        cout << "\tEstimasi      : " << pesanan.estimasi[i] << " jam" << endl;
        cout << "\tJumlah Orang  : " << pesanan.jumlahOrang[i] << endl;
        cout << "\tDriver        : " << pesanan.driver[i] << endl;
        cout << "\tHarga         : Rp. " << pesanan.harga[i] << endl;
        cout << "\tTotal Harga   : Rp. " << pesanan.jumlahOrang[i] * pesanan.harga[i] << endl;
        cout << "\tStatus        : " << pesanan.status[i] << endl;
        cout << "\t--------------------------" << endl;
    }
}

void gantiStatus(int idPesanan, int statusId)
{
    if (idPesanan > 0 && idPesanan <= pesananBelakang + 1)
    {
        pesanan.status[idPesanan - 1] = STATUS[statusId - 1];
        cout << "\tStatus berhasil diubah." << endl;
    }
    else
    {
        cout << "\tPesanan tidak ditemukan." << endl;
    }
}

void bayarPesanan()
{
    posisiRiwayat++;
    int idR = posisiRiwayat;
    int idP = pesananDepan;

    riwayatPesanan.namaPemesan[idR] = pesanan.namaPemesan[idP];
    riwayatPesanan.asal[idR] = pesanan.asal[idP];
    riwayatPesanan.alamat_asal[idR] = pesanan.alamat_asal[idP];
    riwayatPesanan.tujuan[idR] = pesanan.tujuan[idP];
    riwayatPesanan.alamat_tujuan[idR] = pesanan.alamat_tujuan[idP];
    riwayatPesanan.noHp[idR] = pesanan.noHp[idP];
    riwayatPesanan.waktu[idR] = pesanan.waktu[idP];
    riwayatPesanan.estimasi[idR] = pesanan.estimasi[idP];
    riwayatPesanan.jumlahOrang[idR] = pesanan.jumlahOrang[idP];
    riwayatPesanan.harga[idR] = pesanan.harga[idP];
    riwayatPesanan.status[idR] = STATUS[1];
    riwayatPesanan.driver[idR] = pesanan.driver[idP];

    for (int x = pesananDepan; x < pesananBelakang; x++)
    {
        pesanan.namaPemesan[x] = pesanan.namaPemesan[x + 1];
        pesanan.asal[x] = pesanan.asal[x + 1];
        pesanan.alamat_asal[x] = pesanan.alamat_asal[x + 1];
        pesanan.tujuan[x] = pesanan.tujuan[x + 1];
        pesanan.alamat_tujuan[x] = pesanan.alamat_tujuan[x + 1];
        pesanan.noHp[x] = pesanan.noHp[x + 1];
        pesanan.waktu[x] = pesanan.waktu[x + 1];
        pesanan.estimasi[x] = pesanan.estimasi[x + 1];
        pesanan.jumlahOrang[x] = pesanan.jumlahOrang[x + 1];
        pesanan.harga[x] = pesanan.harga[x + 1];
        pesanan.status[x] = pesanan.status[x + 1];
        pesanan.driver[x] = pesanan.driver[x + 1];
    }
    pesananBelakang--;

    cout << "\tMemproses Pesananan......." << endl;
    sleep(1);
    cout << "\n\tPembayaran berhasil. Status pesanan berubah menjadi 'Sukses'." << endl;
}

void tampilRiwayat()
{
    if (posisiRiwayat == -1)
    {
        cout << "\tTidak ada Riwayat" << endl;
        return;
    }

    cout << "\tDaftar Pesanan yang Sudah di Bayar:" << endl;
    for (int i = posisiRiwayat; i >= 0; i--)
    {
        cout << "\tPesanan ke-" << i + 1 << endl;
        cout << "\tNama Pemesan  : " << riwayatPesanan.namaPemesan[i] << endl;
        cout << "\tAsal          : " << riwayatPesanan.asal[i] << endl;
        cout << "\tAlamat Asal   : " << riwayatPesanan.alamat_asal[i] << endl;
        cout << "\tTujuan        : " << riwayatPesanan.tujuan[i] << endl;
        cout << "\tAlamat Tujuan : " << riwayatPesanan.alamat_tujuan[i] << endl;
        cout << "\tNo. HP        : " << riwayatPesanan.noHp[i] << endl;
        cout << "\tWaktu         : " << riwayatPesanan.waktu[i] << endl;
        cout << "\tEstimasi      : " << riwayatPesanan.estimasi[i] << " jam" << endl;
        cout << "\tJumlah Orang  : " << riwayatPesanan.jumlahOrang[i] << endl;
        cout << "\tDriver        : " << riwayatPesanan.driver[i] << endl;
        cout << "\tHarga         : Rp. " << riwayatPesanan.harga[i] << endl;
        cout << "\tTotal Harga   : Rp. " << riwayatPesanan.jumlahOrang[i] * riwayatPesanan.harga[i] << endl;
        cout << "\tStatus        : " << riwayatPesanan.status[i] << endl;
        cout << "\t--------------------------" << endl;
    }
}

// fungsi rekap
const int maxRekap = 99;
struct rekapPenjualan
{
    string asalTravel;
    string tujuanTravel;
    int jumlahTiket;
    int pendapatan;
};
rekapPenjualan rekap[maxRekap];
int hitungRekap = 0;

void rekapPesanan()
{
    if (posisiRiwayat == -1)
    {
        cout << "\tTidak ada pesanan yang dapat direkap." << endl;
        return;
    }

    for (int i = 0; i < maxRekap; i++)
    {
        rekap[i] = {"", "", 0, 0};
    }

    int totalTiketTerjual = 0;
    int totalPendapatan = 0;
    hitungRekap = 0;

    for (int i = 0; i <= posisiRiwayat; i++)
    {
        bool ketemu = false;
        for (int j = 0; j < hitungRekap; j++)
        {
            if (rekap[j].asalTravel == riwayatPesanan.asal[i] && rekap[j].tujuanTravel == riwayatPesanan.tujuan[i])
            {
                rekap[j].jumlahTiket += riwayatPesanan.jumlahOrang[i];
                rekap[j].pendapatan += riwayatPesanan.harga[i] * riwayatPesanan.jumlahOrang[i];
                ketemu = true;
                break;
            }
        }
        if (!ketemu)
        {
            rekap[hitungRekap].asalTravel = riwayatPesanan.asal[i];
            rekap[hitungRekap].tujuanTravel = riwayatPesanan.tujuan[i];
            rekap[hitungRekap].jumlahTiket = riwayatPesanan.jumlahOrang[i];
            rekap[hitungRekap].pendapatan = riwayatPesanan.harga[i] * riwayatPesanan.jumlahOrang[i];
            hitungRekap++;
        }

        totalTiketTerjual += riwayatPesanan.jumlahOrang[i];
        totalPendapatan += riwayatPesanan.harga[i] * riwayatPesanan.jumlahOrang[i];
    }

    cout << "\tRekap Penjualan:" << endl;
    for (int i = 0; i < hitungRekap; ++i)
    {
        cout << "\tRute: " << rekap[i].asalTravel << " - " << rekap[i].tujuanTravel << endl;
        cout << "\tTerjual: " << rekap[i].jumlahTiket << " tiket" << endl;
        cout << "\tPendapatan: Rp. " << rekap[i].pendapatan << endl;
        cout << "\t--------------------------" << endl;
    }

    cout << "\tTotal Tiket Terjual: " << totalTiketTerjual << " tiket" << endl;
    cout << "\tTotal Pendapatan: Rp. " << totalPendapatan << endl;
}
