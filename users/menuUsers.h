#include "../operation.h"

void menu_admin()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "\t=== Admin Menu ===" << endl;
        cout << "\t1. Lihat Jadwal" << endl;
        cout << "\t2. Tambah Jadwal" << endl;
        cout << "\t3. Hapus Jadwal" << endl;
        cout << "\t4. Lihat Driver" << endl;
        cout << "\t5. Tambah Driver" << endl;
        cout << "\t6. Lihat Pesanan" << endl;
        cout << "\t7. Rekap Pesanan" << endl;
        cout << "\t8. Logout" << endl;
        cout << "\tPilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            lihatJadwal();
            break;
        case 2:
        {
            tambahJadwal();
            break;
        }
        case 3:
        {
            int id;
            cout << "\tMasukkan ID jadwal yang ingin dihapus: ";
            cin >> id;
            hapusJadwal(id - 1);
            break;
        }
        case 4:
            tampilDriver();
            break;
        case 5:
        {
            string namaSupir, plat;
            bool status;
            cin.ignore();
            cout << "\tMasukkan nama driver: ";
            getline(cin, namaSupir);
            cout << "\tMasukkan plat nomor: ";
            getline(cin, plat);
            cout << "\tMasukkan status (1 untuk aktif, 0 untuk tidak aktif): ";
            cin >> status;
            tambahDriver(namaSupir, plat, status);
            break;
        }
        case 6:
        {
            tampilRiwayat();
            break;
        }
        case 7:
            rekapPesanan();
            break;
        case 8:
            cout << "\tLogout berhasil!" << endl;
            break;
        default:
            cout << "\tPilihan tidak valid!" << endl;
        }
        cout << endl;
        system("pause");
    } while (pilihan != 8);
}

void menu_customer()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "\t=== Customer Menu ===" << endl;
        cout << "\t1. Lihat Jadwal" << endl;
        cout << "\t2. Pesan Jadwal" << endl;
        cout << "\t3. Lihat Pesanan" << endl;
        cout << "\t4. Lihat Riwayat Pesanan" << endl;
        cout << "\t5. Logout" << endl;
        cout << "\tPilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            lihatJadwal();
            break;
        case 2:
        {
            tambahPesanan();
            break;
        }
        case 3:
            lihatPesanan();

            char bayar;
            cout << "\t\nBayar Pesanan? (y/n): ";
            cin >> bayar;
            if (bayar == 'y' || bayar == 'Y')
            {
                bayarPesanan();
            }
            break;
        case 4:
            tampilRiwayat();
            break;
        case 5:
            cout << "\tLogout berhasil!" << endl;
            break;
        default:
            cout << "\tPilihan tidak valid!" << endl;
        }
        cout << endl;
        system("pause");
    } while (pilihan != 5);
}
