// Library
#include <iostream>
using namespace std;

// Struct
struct Gitar {
    string merek, jenis, no_seri;
    int harga, stok;
};

// Struct Node
struct Node {
  Gitar data;
  Node *next = NULL;
};

// Fungsi Jika Node Kosong
int isEmpty(Node *head) {
	if(head == NULL) {
		return 1;
	}
	else return 0;
}

int urut(Node *head) {
  int jumlah = 0;
  while (head != NULL)
  {
    jumlah++;
    head = head->next;
  }
  return jumlah;
}

Node *newNode(){

    // Membuat node baru
    Node *nodeBaru = new Node;

    cout << "\nMasukkan Merek Gitar   : ";
    fflush(stdin);
    getline(cin, nodeBaru->data.merek);
    cout << "Masukkan Jenis Gitar   : ";
    fflush(stdin);
    getline(cin, nodeBaru->data.jenis);
    cout << "Masukkan No Seri Gitar : ";
    fflush(stdin);
    getline(cin, nodeBaru->data.no_seri);
    cout << "Masukkan Harga Gitar   : Rp. ";
    cin >> nodeBaru->data.harga;
    cout << "Masukkan Stok Gitar    : ";
    cin >> nodeBaru->data.stok;

    cout << "\n>>>>>>>>>>>>> DATA TELAH DITAMBAH <<<<<<<<<<<<<" << endl;

    return nodeBaru;
}

void addFirst(Node **head){
    Node *nodeBaru = newNode();
    nodeBaru->next = *head;
    *head = nodeBaru;
}

void addMid(Node **head) {

    // Jika linked list kosong
    if (isEmpty(*head)) {
        cout << "\n>>>>>>>>> Tidak Dapat Menambahkan Data <<<<<<<<<" << endl; 
        cout << ">>>>>>>>>>  Karena Data Masih Kosong <<<<<<<<<<<" << endl;
        return;
    }

    Node *display = *head;

    int i = 1;
    while (display != NULL) {
    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>  | "<< i <<" | <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
            << "Merek Gitar   : " << display->data.merek << endl
            << "Jenis Gitar   : " << display->data.jenis << endl
            << "No Seri Gitar : " << display->data.no_seri << endl
            << "Harga Gitar   : Rp. " << display->data.harga << endl
            << "Stok Gitar    : " << display->data.stok << endl;
        i += 1;
        display = display->next;
    }

    int index;
    cout << "\n- Masukkan Data Pada Nomor >> ";
    cin >> index;

    if (index > 0 && index <= urut(*head)){        
        Node *nodeBaru = newNode();

        int nomor = 1;
        Node *temp = (*head);
        while(nomor < index-1){
            temp = temp->next;
            nomor++;
        }

        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
    else{
        cout << "\n>>>>>>>>>>>>> DATA TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
    }

}

void addLast(Node **head){
    Node *nodeBaru = newNode();

    // Jika linked kosong
    if (isEmpty(*head)) {
        *head = nodeBaru;
    }
    else{
        // Traversal ke node terakhir
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Menghubungkan node terakhir dengan node baru
        temp->next = nodeBaru;
    }
}

// Prosedur Ubah Data
void ubah(Node **head)
{   
    // Jika linked list kosong
    if (isEmpty(*head)) {
        return;
    }

    int ubah;
    cout << "\n- Nomor Berapa Yang Ingin Diubah ?? >> ";
    cin >> ubah;

    Node *temp = (*head);

    if (ubah > 0 && ubah <= urut(*head)){
        for (int i = 1; i < ubah; i++){
            temp = temp->next;
        }
        cout << "\nMasukkan Merek Gitar Yang Baru : ";
        fflush(stdin);
        getline(cin, temp->data.merek);
        cout << "Masukkan Jenis Gitar Yang Baru : ";
        fflush(stdin);
        getline(cin, temp->data.jenis);
        cout << "Masukkan No Seri Baru Gitar    : ";
        fflush(stdin);
        getline(cin, temp->data.no_seri);
        cout << "Masukkan Harga Gitar Yang Baru : Rp. ";
        cin >> temp->data.harga;
        cout << "Masukkan Stok Gitar Yang Baru  : ";
        cin >> temp->data.stok;

        cout << "\n>>>>> DATA TELAH DIUBAH <<<<<";
        cout << endl;
    }
    else {
        cout << "\n>>>>>>>>>>>>> DATA TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
    }
}

// Prosedur Lihat Data
void lihat(Node *head) {

    int index = 1;
    
    // Jika linked list kosong
    if (isEmpty(head)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>  | "<< index <<" | <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << "Merek Gitar   : " << temp->data.merek << endl
             << "Jenis Gitar   : " << temp->data.jenis << endl
             << "No Seri Gitar : " << temp->data.no_seri << endl
             << "Harga Gitar   : Rp. " << temp->data.harga << endl
             << "Stok Gitar    : " << temp->data.stok << endl;
        index += 1;
        temp = temp->next;
    }
}

void delFirst(Node **head) {

    // Jika linked list kosong
    if (isEmpty(*head)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        return;
    }

    *head = (*head)->next;
    cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
}

void delMid(Node **head){

    // Jika linked list kosong
    if (isEmpty(*head)) {
        return;
    }

    int nomor = 1;
    Node *previous, *del;
    int hapus;
    cout << "\n- Nomor Berapa Yang Ingin Dihapus ?? >> ";
    cin >> hapus;

    if (hapus > 0 && hapus <= urut(*head)){

        if (hapus == 1 or hapus == urut(*head)){

            cout << "\n>>>>>>>>>>> Tidak Dapat Menghapus Data <<<<<<<<<<<" << endl; 
            cout << ">>>>> Karena Data Tidak Berada Diantara Node <<<<<" << endl;

        }
        else{

            Node *temp = (*head);

            while( nomor <= hapus ){
            if( nomor == hapus-1 ){
                previous = temp;
            }
            if( nomor == hapus ){
                del = temp;
            }
            temp = temp->next;
            nomor++;
            }
            previous->next = temp;
            delete del;
            cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
        }
    }
    else{
        cout << "\n>>>>>>>>>>>>> DATA TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
    }
}

void delLast(Node **head) {
    // Jika linked list kosong
    if (isEmpty(*head)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        return;
    }
    if ((*head)->next == NULL) {
        *head = NULL;
        cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    Node *varDelete = temp->next;
    temp->next = NULL;
    delete varDelete;
    cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
}

// Prosedur Tampilan Menu Utama
void display_menu() {

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

void menu_add(){

  cout << "\n================================================" << endl
       << "|---------------------Tambah-------------------|" << endl
       << "|-------------------LinkedList-----------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "1) AddFirst" << endl
       << "2) AddMid" << endl
       << "3) AddLast" << endl;
}

void menu_del(){
  cout << "\n================================================" << endl
       << "|---------------------Hapus--------------------|" << endl
       << "|-------------------LinkedList-----------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "1) DeleteFirst" << endl
       << "2) DeleteMid" << endl
       << "3) DeleteLast" << endl;
}

// Program Utama
int main() {   

    bool akhiri;
    string ulang;

    struct Node* HEAD = NULL;

    // Perulangan while
    while(akhiri == false){

        system("cls");

        display_menu();
        int pilih, no;
        cout << "Masukkan Nomor Menu : ";
        cin >> pilih;

        // Percabangan Switch
        switch (pilih) {

            // Kondisi Menambahkan Data
            case 1:
                system("cls");
                cout << "<<==========================|Menu Tambah Data|==================================>>" << endl;
                menu_add();
                cout << "Masukkan nomor menu >> "; cin >> no;
                if (no == 1){
                    addFirst(&HEAD);
                }
                else if(no == 2){
                    addMid(&HEAD);
                }
                else if(no == 3){
                    addLast(&HEAD);
                }
                else{
                    cout << "\n>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
                }
                break;

            // Kondisi Melihat Data
            case 2:
                system("cls");
                cout << "<<==========================|Menu Lihat Data|===================================>>" << endl;
                lihat(HEAD);
                break;

            // Kondisi Mengubah Data
            case 3:
                system("cls");
                cout << "<<===========================|Menu Ubah Data|===================================>>" << endl;
                lihat(HEAD);
                ubah(&HEAD);
                break;

            // Kondisi Menghapus Data
            case 4:
                system("cls");
                cout << "<<===========================|Menu Hapus Data|==================================>>" << endl;
                menu_del();
                cout << "Masukkan nomor menu >> "; cin >> no;
                if (no == 1){
                    delFirst(&HEAD);
                }
                else if(no == 2){
                    lihat(HEAD);
                    delMid(&HEAD);
                }
                else if(no == 3){
                    delLast(&HEAD);
                }
                else{
                    cout << "\n>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
                }
                break;

            // Kondisi Untuk Keluar Program
            case 5:
                cout << "\n<------ Terima Kasih ------>" << endl;
                exit(0);

            // Kondisi Default
            default:
                cout << "\n>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
        }

        // Konfirmasi Kembali ke Menu Utama
        cout << "\nIngin Kembali Ke Menu Utama ?? (y/t) >> "; cin >> ulang;
        cout << endl;

        // Kondisi Penentu Nilai While
        if (ulang == "y" || ulang == "Y"){
            akhiri = false;
        }
        else if (ulang == "t" || ulang == "T"){
            cout << "<------ Terima Kasih ------>" << endl;
            akhiri = true;
        }
        else{
            cout << "<------ Terima Kasih ------>" << endl;
            akhiri = true;
        }
    }
}