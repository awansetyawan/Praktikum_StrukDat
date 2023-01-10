// Library
#include <iostream>
using namespace std;

// Struct
struct Gitar
{
    string merek, jenis, no_seri;
    int harga, stok;
};

// Deklarasi Struct
Gitar gitar;

// Deklarasi Pointer
Gitar *ptrGitar = &gitar;

// Data Elemen Array
int data_gitar = 3;

// Array Of Struct
Gitar guitars[100];

// Prosedur Tambah Data
void tambah_data()
{
    cout << "Masukkan Merek Gitar   : ";
    fflush(stdin);
    getline(cin, ptrGitar->merek);
    cout << "Masukkan Jenis Gitar   : ";
    fflush(stdin);
    getline(cin, ptrGitar->jenis);
    cout << "Masukkan No Seri Gitar : ";
    fflush(stdin);
    getline(cin, ptrGitar->no_seri);
    cout << "Masukkan Harga Gitar   : Rp. ";
    cin >> ptrGitar->harga;
    cout << "Masukkan Stok Gitar    : ";
    cin >> ptrGitar->stok;

    guitars[data_gitar] = gitar;
    data_gitar++;

}

// Prosedur Ubah Data
void ubah_data()
{
    int ubah, no_ubah;
    cout << "\nNomor Berapa Yang Ingin Diubah ?? >> ";
    cin >> ubah;
    no_ubah = ubah-1;
    if (ubah <= 0 or ubah > data_gitar){
        cout << "\n>>>> Data Ke-" << ubah << " Tidak Tersedia <<<<";
    }
    else{
        gitar = guitars[no_ubah];
        cout << "\nMasukkan Merek Gitar Yang Baru : ";
        fflush(stdin);
        getline(cin, ptrGitar->merek);
        cout << "Masukkan Jenis Gitar Yang Baru : ";
        fflush(stdin);
        getline(cin, ptrGitar->jenis);
        cout << "Masukkan No Seri Baru Gitar    : ";
        fflush(stdin);
        getline(cin, ptrGitar->no_seri);
        cout << "Masukkan Harga Gitar Yang Baru : Rp. ";
        cin >> ptrGitar->harga;
        cout << "Masukkan Stok Gitar Yang Baru  : Rp. ";
        cin >> ptrGitar->stok;
        guitars[no_ubah] = gitar;

        cout << "\n>>>>> DATA TELAH DIUBAH <<<<<";
    }
}

// Prosedur Lihat Data
void lihat_data()
{
    for (int i = 0; i < data_gitar; i++)
    {
        Gitar gitar = guitars[i];
        Gitar *ptrGitar = &gitar;
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << i + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << "Merek Gitar   : " << ptrGitar->merek << endl
             << "Jenis Gitar   : " << ptrGitar->jenis << endl
             << "No Seri Gitar : " << ptrGitar->no_seri << endl
             << "Harga Gitar   : Rp. " << ptrGitar->harga << endl
             << "Stok Gitar    : " << ptrGitar->stok << endl;
    }
}

// Prosedur Hapus Data
void hapus_data()
{
    int hapus, no_hapus, i;
    cout << "\nNomor Berapa Yang Ingin Dihapus ?? >> ";
    cin >> hapus;
    no_hapus = hapus - 1;

    if (hapus <= 0 or hapus > data_gitar){
        cout << "\n>>>> Data Ke-" << hapus << " Tidak Tersedia <<<<";
    }
    else{
        data_gitar--;
        for (i = no_hapus; i < data_gitar; i++)
        {
            guitars[i] = guitars[i + 1];
        }
        cout << "\n>>>> DATA TELAH DIHAPUS <<<<";
    }
}

// Prosedur Tampilan Menu Utama
void tampilan_menu()
{
    cout << "================================================" << endl
         << "|---------------Selamat Datang-----------------|" << endl
         << "|------------Di Galeri Gitar Awan--------------|" << endl
         << "================================================" << endl
         << "- Dibuat Oleh Alif Maulana Setyawan" << endl
         << "\n>>> --------Menu-------- <<<" << endl
         << "1) Tambah Data Gitar" << endl
         << "2) Lihat Data Gitar" << endl
         << "3) Ubah Data Gitar" << endl
         << "4) Hapus Data Gitar" << endl
         << "5) Exit" << endl;
}

// Program Utama
int main()
{
    guitars[0] = {
        "Yamaha",
        "Akustik",
        "APX600",
        3140000,
        3
    };

    guitars[1] = {
        "Yamaha",
        "Bass",
        "TRBX174",
        3250000,
        1
    };

    guitars[2] = {
        "Yamaha",
        "Klasik",
        "C40",
        1330000,
        5
    };

    char ulang;

    // Perulangan Do ... While
    do
    {

        system("cls");
        tampilan_menu();
        int pilih;
        cout << "Masukkan Nomor Menu : ";
        cin >> pilih;

        // Percabangan Switch
        switch (pilih)
        {

        // Kondisi Menambahkan Data
        case 1:
            system("cls");
            cout << "<<==========================|Menu Tambah Data|==================================>>" << endl;
            tambah_data();
            cout << "\n>>>> DATA TELAH DITAMBAH <<<<";
            break;

        // Kondisi Melihat Data
        case 2:
            system("cls");
            cout << "<<==========================|Menu Lihat Data|===================================>>" << endl;
            if (data_gitar > 0)
            {
                lihat_data();
            }
            else
            {
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            }
            break;

        // Kondisi Mengubah Data
        case 3:
            system("cls");
            cout << "<<===========================|Menu Ubah Data|===================================>>" << endl;
            if (data_gitar > 0)
            {
                lihat_data();
                ubah_data();
            }
            else
            {
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            }
            break;

        // Kondisi Menghapus Data
        case 4:
            system("cls");
            cout << "<<===========================|Menu Hapus Data|==================================>>" << endl;
            if (data_gitar > 0)
            {
                lihat_data();
                hapus_data();
            }
            else
            {
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            }
            break;

        // Kondisi Untuk Keluar Program
        case 5:
            cout << "\n<------ Terima Kasih ------>" << endl;
            exit(0);

        // Kondisi Default
        default:
            cout << "\n>>>> Menu Tidak Tersedia <<<<";
        }
        cout << endl;

        // Konfirmasi Perulangan
        cout << "\nIngin Kembali Ke Menu Utama ?? (y/t) >> ";
        cin >> ulang;
        cout << endl;

    } while (ulang != 't');

    cout << "\n<------ Terima Kasih ------>" << endl;
}