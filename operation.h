#include <iostream>
#include <limits>

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
            cout << "Username sudah digunakan" << endl;
            return;
        }
    }
    if (jml_user < MAX_USER)
    {
        users[jml_user++] = {username, password, usia, "user"};
        cout << "Berhasil mendaftar sebagai customer." << endl;
    }
    else
    {
        cout << "User limit reached" << endl;
    }
}

void tampilUser()
{
    for (int i = 0; i < jml_user; i++)
    {
        cout << "Username: " << users[i].username << endl;
        cout << "Password: " << users[i].password << endl;
        cout << "Role: " << users[i].role << endl
             << endl;
    }
}

const int MAX_SUPIR = 99;
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
            cout << "Supir sudah ada" << endl;
            return;
        }
    }
    if (jumlah_supir < MAX_SUPIR)
    {
        drivers[jumlah_supir++] = {nama, plat_nomor, status};
        cout << "Berhasil menambahkan driver." << endl;
    }
    else
    {
        cout << "Driver limit reached" << endl;
    }
}

void tampilDriver()
{
    for (int i = 0; i < jumlah_supir; i++)
    {
        cout << i + 1 << ". Nama: " << drivers[i].nama << "\nPlat: " << drivers[i].plat_nomor << "\nStatus: " << (drivers[i].status ? "Aktif" : "Tidak Aktif") << endl;
    }
}

bool cekDriver(int index)
{
    if (index < 0 || index >= jumlah_supir)
    {
        cout << "Driver tidak ditemukan." << endl;
        return false;
    }
    else if (!drivers[index].status)
    {
        cout << "Driver tidak aktif" << endl;
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
    int estimasi;
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

void buatJadwal(string asal, string tujuan, int hariIndex, string waktu, int estimasi, int kursi, int harga)
{
    jadwal = new Jadwal{id_jadwal++, asal, tujuan, HARI[hariIndex], waktu, estimasi, kursi, harga, NULL, NULL};
}

void tambahJadwal(string asal, string tujuan, string waktu, int hariIndex, int estimasi, int kursi, int harga)
{
    buatJadwal(asal, tujuan, hariIndex, waktu, estimasi, kursi, harga);
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
    cout << "Jadwal berhasil ditambahkan!" << endl;
}

void lihatJadwal()
{
    if (!head && !tail)
    {
        cout << "Tidak ada jadwal yang tersedia." << endl;
        return;
    }
    Jadwal *current = head;
    do
    {
        cout << "Id Jadwal: " << current->id + 1 << endl;
        cout << "Asal          : " << current->asal << endl;
        cout << "Tujuan        : " << current->tujuan << endl;
        cout << "Hari          : " << current->hari << endl;
        cout << "Waktu         : " << current->waktu << endl;
        cout << "Estimasi      : " << current->estimasi << " jam" << endl;
        cout << "Kursi Tersisa : " << current->kursi << endl;
        cout << "Harga         : Rp. " << current->harga << endl;
        cout << "--------------------------" << endl;
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
        cout << "Data yang dicari tidak ditemukan." << endl;
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
    delete target;
    cout << "Jadwal berhasil dihapus!" << endl;
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
    int estimasi[MAX_PESANAN];
    int harga[MAX_PESANAN];
    int jumlahOrang[MAX_PESANAN];
    string status[MAX_PESANAN];
    string driver[MAX_PESANAN];
    int depan = -1;
    int belakang = -1;
};

Pesanan pesanan;
const string STATUS[3] = {"Belum Bayar", "Mencari Supir", "Sukses"};

void tambahPesanan(int jadwalId, string namaPemesan, string alamat_asal, string alamat_tujuan, string noHp, int jumlahOrang)
{
    Jadwal *jadwal = cariJadwal(jadwalId);
    if (!jadwal)
    {
        cout << "Jadwal tidak ditemukan." << endl;
        return;
    }
    if (pesanan.depan == -1 && pesanan.belakang == -1)
    {
        pesanan.depan = pesanan.belakang = 0;
    }
    else
    {
        pesanan.belakang++;
    }
    int idB = pesanan.belakang;
    pesanan.namaPemesan[idB] = namaPemesan;
    pesanan.asal[idB] = jadwal->asal;
    pesanan.alamat_asal[idB] = alamat_asal;
    pesanan.tujuan[idB] = jadwal->tujuan;
    pesanan.alamat_tujuan[idB] = alamat_tujuan;
    pesanan.noHp[idB] = noHp;
    pesanan.waktu[idB] = jadwal->waktu;
    pesanan.estimasi[idB] = jadwal->estimasi;
    pesanan.jumlahOrang[idB] = jumlahOrang;
    pesanan.harga[idB] = jadwal->harga;
    pesanan.status[idB] = STATUS[0];
    pesanan.driver[idB] = "";
    cout << "Pesanan berhasil ditambahkan." << endl;
}

void lihatPesanan()
{
    if (pesanan.depan == -1 && pesanan.belakang == -1)
    {
        cout << "Tidak ada pesanan." << endl;
        return;
    }
    for (int i = pesanan.depan; i <= pesanan.belakang; i++)
    {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama Pemesan  : " << pesanan.namaPemesan[i] << endl;
        cout << "Asal          : " << pesanan.asal[i] << endl;
        cout << "Alamat Asal   : " << pesanan.alamat_asal[i] << endl;
        cout << "Tujuan        : " << pesanan.tujuan[i] << endl;
        cout << "Alamat Tujuan : " << pesanan.alamat_tujuan[i] << endl;
        cout << "No. HP        : " << pesanan.noHp[i] << endl;
        cout << "Waktu         : " << pesanan.waktu[i] << endl;
        cout << "Estimasi      : " << pesanan.estimasi[i] << " jam" << endl;
        cout << "Jumlah Orang  : " << pesanan.jumlahOrang[i] << endl;
        cout << "Harga         : Rp. " << pesanan.harga[i] << endl;
        cout << "Status        : " << pesanan.status[i] << endl;
        cout << "Driver        : " << (pesanan.driver[i].empty() ? "Belum ada supir" : pesanan.driver[i]) << endl;
        cout << "--------------------------" << endl;
    }
}

void gantiStatus(int idPesanan, int statusId)
{
    if (idPesanan > 0 && idPesanan <= pesanan.belakang + 1)
    {
        pesanan.status[idPesanan - 1] = STATUS[statusId - 1];
        cout << "Status berhasil diubah." << endl;
    }
    else
    {
        cout << "Pesanan tidak ditemukan." << endl;
    }
}

void bayarPesanan(int idPesanan)
{
    if (idPesanan > 0 && idPesanan <= pesanan.belakang + 1)
    {
        if (pesanan.status[idPesanan - 1] == STATUS[0])
        {
            pesanan.status[idPesanan - 1] = STATUS[1];
            cout << "Pembayaran berhasil. Status pesanan berubah menjadi 'Mencari Supir'." << endl;
        }
        else
        {
            cout << "Pesanan ini tidak dapat dibayar atau sudah dibayar." << endl;
        }
    }
    else
    {
        cout << "Pesanan tidak ditemukan." << endl;
    }
}

void layaniPesanan(int idPesanan)
{
    if (idPesanan > 0 && idPesanan <= pesanan.belakang + 1)
    {
        if (pesanan.status[idPesanan - 1] == STATUS[1])
        {
            for (int i = 0; i < jumlah_supir; i++)
            {
                if (drivers[i].status)
                {
                    pesanan.status[idPesanan - 1] = STATUS[2];
                    pesanan.driver[idPesanan - 1] = drivers[i].nama;
                    cout << "Pesanan dilayani oleh supir: " << drivers[i].nama << ". Status pesanan berubah menjadi 'Sukses'." << endl;
                    return;
                }
            }
            cout << "Tidak ada supir yang tersedia." << endl;
        }
        else
        {
            cout << "Pesanan ini tidak dapat dilayani atau sudah dilayani." << endl;
        }
    }
    else
    {
        cout << "Pesanan tidak ditemukan." << endl;
    }
}