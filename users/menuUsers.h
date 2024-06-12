#include "../operation.h"

void menu_admin()
{
    int pilihan;
    do
    {
        cout << "=== Admin Menu ===" << endl;
        cout << "1. Lihat Jadwal" << endl;
        cout << "2. Tambah Jadwal" << endl;
        cout << "3. Hapus Jadwal" << endl;
        cout << "4. Lihat Driver" << endl;
        cout << "5. Tambah Driver" << endl;
        cout << "6. Lihat Pesanan" << endl;
        cout << "7. Ubah Status Pesanan" << endl;
        cout << "8. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            lihatJadwal();
            break;
        case 2:
        {
            string asal, tujuan, waktu;
            int hari, estimasi, kursi, harga;
            cout << "Masukkan asal: ";
            cin >> asal;
            cout << "Masukkan tujuan: ";
            cin >> tujuan;
            cout << "Masukkan hari (0-6): ";
            cin >> hari;
            cout << "Masukkan waktu: ";
            cin >> waktu;
            cout << "Masukkan estimasi: ";
            cin >> estimasi;
            cout << "Masukkan jumlah kursi: ";
            cin >> kursi;
            cout << "Masukkan harga: ";
            cin >> harga;
            tambahJadwal(asal, tujuan, waktu, hari, estimasi, kursi, harga);
            break;
        }
        case 3:
        {
            int id;
            cout << "Masukkan ID jadwal yang ingin dihapus: ";
            cin >> id;
            hapusJadwal(id - 1);
            break;
        }
        case 4:
            tampilDriver();
            break;
        case 5:
        {
            string nama, plat;
            bool status;
            cout << "Masukkan nama driver: ";
            cin >> nama;
            cout << "Masukkan plat nomor: ";
            cin >> plat;
            cout << "Masukkan status (1 untuk aktif, 0 untuk tidak aktif): ";
            cin >> status;
            tambahDriver(nama, plat, status);
            break;
        }
        case 6:
            lihatPesanan();
            break;
        case 7:
        {
            int id, status;
            cout << "Masukkan ID pesanan: ";
            cin >> id;
            cout << "Masukkan status (1. Belum Bayar, 2. Mencari Supir, 3. Sukses): ";
            cin >> status;
            gantiStatus(id, status);
            break;
        }
        case 8:
            cout << "Logout berhasil!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);
}

void menu_customer()
{
    int pilihan;
    do
    {
        cout << "=== Customer Menu ===" << endl;
        cout << "1. Lihat Jadwal" << endl;
        cout << "2. Pesan Jadwal" << endl;
        cout << "3. Lihat Pesanan" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            lihatJadwal();
            break;
        case 2:
        {
            string nama, asal, tujuan, noHp;
            int jadwalId, jumlahOrang;
            cout << "Masukkan ID jadwal: ";
            cin >> jadwalId;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan alamat asal: ";
            cin >> asal;
            cout << "Masukkan alamat tujuan: ";
            cin >> tujuan;
            cout << "Masukkan no HP: ";
            cin >> noHp;
            cout << "Masukkan jumlah orang: ";
            cin >> jumlahOrang;
            tambahPesanan(jadwalId, nama, asal, tujuan, noHp, jumlahOrang);
            break;
        }
        case 3:
            lihatPesanan();
            break;
        case 4:
            cout << "Logout berhasil!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);
}
