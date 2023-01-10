// Library
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Struct
struct Gitar {
    string merek, jenis, no_seri;
    int id_gitar, harga, stok;
};

// Struct Node
struct Node {
  Gitar data;
  Node *next = NULL;
};

// ----------------------------------------------------------------
// CRUD LINKED LIST
// ----------------------------------------------------------------

// Fungsi Jika Node Kosong
int isEmpty(Node *head) {
	if(head == NULL) {
		return 1;
	}
	else return 0;
}

// Fungsi mengukur panjang linkedlist
int panjang(Node *head) {
  int jumlah = 0;
  while (head != NULL)
  {
    jumlah++;
    head = head->next;
  }
  return jumlah;
}

// Fungsi membuat node baru
Node *newNode(){

    // Membuat node baru
    Node *nodeBaru = new Node;

    cout << "\nMasukkan ID Gitar      : ";
    cin >> nodeBaru->data.id_gitar;
    cout << "Masukkan Merek Gitar   : ";
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

// Prosedur Menambah data linkedlist di awal
void addFirst(Node **head){
    Node *nodeBaru = newNode();
    nodeBaru->next = *head;
    *head = nodeBaru;
}

// Prosedur Menambah data linkedlist di tengah
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
            << "ID Gitar      : " << display->data.id_gitar << endl
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

    if (index == 1 ){ 
        cout << "\n>>>>>>>>>>> Tidak Dapat Menambah Data <<<<<<<<<<<<" << endl; 
        cout << ">>>>> Karena Data Tidak Berada Diantara Node <<<<<" << endl;    
    }
    else if (index > 0 && index <= panjang(*head)){     
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

// Prosedur Menambah data linkedlist di akhir
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
void ubah(Node **head) {

    // Jika linked list kosong
    if (isEmpty(*head)) {
        return;
    }

    int ubah;
    cout << "\n- Nomor Berapa Yang Ingin Diubah ?? >> ";
    cin >> ubah;

    Node *temp = (*head);

    if (ubah > 0 && ubah <= panjang(*head)){
        for (int i = 1; i < ubah; i++){
            temp = temp->next;
        }

        cout << "\nMasukkan ID Gitar              : ";
        cin >> temp->data.id_gitar;
        cout << "Masukkan Merek Gitar Yang Baru : ";
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
             << "ID Gitar      : " << temp->data.id_gitar << endl
             << "Merek Gitar   : " << temp->data.merek << endl
             << "Jenis Gitar   : " << temp->data.jenis << endl
             << "No Seri Gitar : " << temp->data.no_seri << endl
             << "Harga Gitar   : Rp. " << temp->data.harga << endl
             << "Stok Gitar    : " << temp->data.stok << endl;
        index += 1;
        temp = temp->next;
    }
}

// Prosedur Menghapus data linkedlist di awal
void delFirst(Node **head) {

    // Jika linked list kosong
    if (isEmpty(*head)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        return;
    }

    *head = (*head)->next;
    cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
}

// Prosedur Menghapus data linkedlist di tengah
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

    if (hapus > 0 && hapus <= panjang(*head)){

        if (hapus == 1 or hapus == panjang(*head)){

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

// Prosedur Menghapus data linkedlist di akhir
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

// ----------------------------------------------------------------
// TAMPILAN MENU-MENU
// ----------------------------------------------------------------

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
         << "5) Urutkan Data Gitar" << endl
         << "6) Cari Data Gitar" << endl
         << "7) Exit" << endl;
}

// Prosedur Tampilan Menu Tambah
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

// Prosedur Tampilan Menu Hapus
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

// Prosedur Tampilan Menu Sorting
void menu_sort(){
    
    cout << "\n================================================" << endl
         << "|----------------------Sort--------------------|" << endl
         << "|-------------------LinkedList-----------------|" << endl
         << "================================================" << endl
         << "\n>>> --------Menu-------- <<<" << endl
         << "1) Ascending" << endl
         << "2) Descending" << endl;
}

// Prosedur Tampilan Menu Searching
void menu_search(){
    cout << "\n================================================" << endl
         << "|-------------------Searching------------------|" << endl
         << "|-------------------LinkedList-----------------|" << endl
         << "================================================" << endl
         << "\n>>> --------Menu-------- <<<" << endl
         << "1) ID Gitar (Jump)" << endl
         << "2) No Seri Gitar (Fibonacci)" << endl;
}

// ----------------------------------------------------------------
// SORTING MERGE SORT
// ----------------------------------------------------------------

// Ascending 
Node *SortedMergeASC(Node *a, Node *b, int kategoriASC) {
    
    Node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    
    bool kondisi = false;

    if (kategoriASC == 1){
        kondisi = a->data.id_gitar <= b->data.id_gitar;
    }
    else if (kategoriASC == 2){
        kondisi = a->data.merek <= b->data.merek;
    }
    else if (kategoriASC == 3){
        kondisi = a->data.jenis <= b->data.jenis;
    }
    else if (kategoriASC == 4){
        kondisi = a->data.no_seri <= b->data.no_seri;
    }
    else if (kategoriASC == 5){
        kondisi = a->data.harga <= b->data.harga;
    }
    else if (kategoriASC == 6){
        kondisi = a->data.stok <= b->data.stok;
    }

    if (kondisi){
        result = a;
        result->next = SortedMergeASC(a->next, b, kategoriASC);
    }
    else{
        result = b;
        result->next = SortedMergeASC(a, b->next, kategoriASC);
    }
    return (result);
}

// Descending
Node *SortedMergeDSC(Node *a, Node *b, int kategoriDSC) {
    Node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    
    bool kondisi = false;

    if (kategoriDSC == 1){
        kondisi = a->data.id_gitar >= b->data.id_gitar;
    }
    else if (kategoriDSC == 2){
        kondisi = a->data.merek >= b->data.merek;
    }
    else if (kategoriDSC == 3){
        kondisi = a->data.jenis >= b->data.jenis;
    }
    else if (kategoriDSC == 4){
        kondisi = a->data.no_seri >= b->data.no_seri;
    }
    else if (kategoriDSC == 5){
        kondisi = a->data.harga >= b->data.harga;
    }
    else if (kategoriDSC == 6){
        kondisi = a->data.stok >= b->data.stok;
    }

    if (kondisi){
        result = a;
        result->next = SortedMergeDSC(a->next, b, kategoriDSC);
    }
    else{
        result = b;
        result->next = SortedMergeDSC(a, b->next, kategoriDSC);
    }
    return (result);
}

// Prosedur Membagi Merge Sort
void split(Node *source, Node **frontRef, Node **backRef) {
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Merge Sort Ascending
void MergeSortASC(Node **headRef, int kategoriASC) {
    Node *head = *headRef;
    Node *a;
    Node *b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    split(head, &a, &b);
    MergeSortASC(&a, kategoriASC);
    MergeSortASC(&b, kategoriASC);
    *headRef = SortedMergeASC(a, b, kategoriASC);
}

// Merge Sort Descending
void MergeSortDSC(Node **headRef, int kategoriDSC) {
    Node *head = *headRef;
    Node *a;
    Node *b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    split(head, &a, &b);
    MergeSortDSC(&a, kategoriDSC);
    MergeSortDSC(&b, kategoriDSC);
    *headRef = SortedMergeDSC(a, b, kategoriDSC);
}

// Prosedur menentukan kategori ascending
void valueASC(Node **head){
    int atribut;
    system("cls");
    cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
    cout << "\n================================================" << endl
         << "|--------------------Kategori------------------|" << endl
         << "|-------------------LinkedList-----------------|" << endl
         << "================================================" << endl
         << "\n>>> --------Menu-------- <<<" << endl
         << "1) ID Gitar" << endl
         << "2) Merek" << endl
         << "3) Jenis" << endl
         << "4) No Seri" << endl
         << "5) Harga" << endl
         << "6) Stok" << endl;
    cout << "Masukkan Kategori Pilihan : ";
    cin >> atribut;

    if (atribut <= 0 || atribut > 6){
        cout << "\n>>>>>>>>>>> KATEGORI TIDAK TERSEDIA <<<<<<<<<<<<" << endl;
        cout << ">>>>>>>>>>>>> Data Gagal Diurutkan <<<<<<<<<<<<<" << endl;
    }else{
        MergeSortASC(head, atribut);
    }
}

// Prosedur menentukan kategori descending
void valueDSC(Node **head){
    int atribut;
    system("cls");
    cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
    cout << "\n================================================" << endl
         << "|--------------------Kategori------------------|" << endl
         << "|-------------------LinkedList-----------------|" << endl
         << "================================================" << endl
         << "\n>>> --------Menu-------- <<<" << endl
         << "1) ID Gitar" << endl
         << "2) Merek" << endl
         << "3) Jenis" << endl
         << "4) No Seri" << endl
         << "5) Harga" << endl
         << "6) Stok" << endl;
    cout << "Masukkan Kategori Pilihan : ";
    cin >> atribut;

    if (atribut <= 0 || atribut > 6){
        cout << "\n>>>>>>>>>>> KATEGORI TIDAK TERSEDIA <<<<<<<<<<<<" << endl;
        cout << ">>>>>>>>>>>>> Data Gagal Diurutkan <<<<<<<<<<<<<" << endl;
    }else{
        MergeSortDSC(head, atribut);
    }
}

// ----------------------------------------------------------------
// SEARCHING
// ----------------------------------------------------------------

// Urutkan Data

Node *SortedMerge(Node *a, Node *b, int pilihSearch){
    Node *result = NULL;
    if (a == NULL) return (b);
    else if (b == NULL) return (a);
    
    bool kondisi = false;

    if (pilihSearch == 1){
        kondisi = a->data.id_gitar <= b->data.id_gitar;
    }
    else if (pilihSearch == 2){
        kondisi = a->data.no_seri <= b->data.no_seri;
    }
    
    if (kondisi){
        result = a;
        result->next = SortedMerge(a->next, b, pilihSearch);
    }else{
        result = b;
        result->next = SortedMerge(a, b->next, pilihSearch);
    }
    return (result);
}
 
void MergeSort(Node **headRef, int pilihSearch){
    Node *head = *headRef;
    Node *a;
    Node *b;
    if ((head == NULL) || (head->next == NULL)) return;
    split(head, &a, &b);
    MergeSort(&a, pilihSearch);
    MergeSort(&b, pilihSearch);
    *headRef = SortedMerge(a, b, pilihSearch);
}
 
// ----------------------------------------------------------------
// JUMP
// ----------------------------------------------------------------

// Fungsi Jump Searching
int jumpSearch(struct Node *node, int x, int n){
    int step = sqrt(n);
    int prev;

    Node *head = node;

    if(head->data.id_gitar == x){
        return 0;
    }

    for (int trv = 0; head->next != NULL && trv < min(step, n)-1; trv++){
        head = head->next;
    } 

    while (head->data.id_gitar < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
 
        for (int trv = 0; head->next != NULL && trv < min(step, n)-1; trv++){
            head = head->next;
        } 
    }

    Node *head2 = node;

    for (int trv = 0; head2->next != NULL && trv < prev; trv++){
        head2 = head2->next;
    }

    while (head2->data.id_gitar < x) {
        prev++;
        if (prev == min(step, n)) return -1;
        
        for (int trv = 0; head2->next != NULL && trv < prev; trv++){
            head2 = head2->next;
        }
    }

    if (head2->data.id_gitar == x) return prev;	
    return -1;
}

// ----------------------------------------------------------------
// FIBONACCI
// ----------------------------------------------------------------

// Fungsi Fibonacci Searching
int fibonacciSearch(Node *node, string x, int n){
    int F0 = 0; 
    int F1 = 1; 
    int F = F0 + F1; 
    while (F < n){
        F0 = F1;
        F1 = F;
        F = F0 + F1;
    }
    int offset = -1;
    int trv = 0;
    
    while (F > 1){
        Node *temp = node;
        int i = min(offset + F0, n - 1);

        while (temp->next != NULL && trv < i){
            temp = temp->next;
            trv++;
        }

        if (temp->data.no_seri < x){
            F = F1;
            F1 = F0;
            F0 = F - F1;
            offset = i;
        }

        else if (temp->data.no_seri > x){
            F = F0;
            F1 = F1 - F0;
            F0 = F - F1;
        }

        else return i;
        trv = 0;

    }

    Node  *temp2 = node;
    while (temp2->next != NULL && trv < offset +1){
        temp2 = temp2->next;
        trv++;
    }
    if (F1 && temp2->data.no_seri == x) return offset + 1;
    return -1;
}

// Prosedur untuk input cari
void cari(Node **head, int pilihSearch){

    int key1;
    string key2;
    int kondisi;

    Node *temp = *head;

    int panjangList = panjang(*head);
    int index = 0;

    cout << "\nInfo :  " << endl
         << "Data akan otomatis terurut saat proses pencarian dilakukan." << endl;
    cout << "\n!!! Peringatan !!!" << endl
         << "Perhatikan tipe, kelengkapan, dan bentuk penulisan (besar/kecil huruf)" << endl
         << "dalam pencarian" << endl;

    if(pilihSearch == 1){
        cout << "\n~ Masukkan Nomor ID Gitar yang dicari >> ";
        cin >> key1;
        kondisi = jumpSearch(*head, key1, panjangList);
    }
    else if(pilihSearch == 2){
        cout << "\n~ Masukkan Nomor Seri Gitar yang dicari >> ";
        fflush(stdin);
        getline(cin, key2); 
        kondisi = fibonacciSearch(*head, key2, panjangList);
    }

    int idx = kondisi;

    int nomor = idx + 1;
    if (idx >= 0) {
        while (temp != NULL){

            if (index == idx){
                cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>  | "<< nomor <<" | <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
                     << "ID Gitar      : " << temp->data.id_gitar << endl
                     << "Merek Gitar   : " << temp->data.merek << endl
                     << "Jenis Gitar   : " << temp->data.jenis << endl
                     << "No Seri Gitar : " << temp->data.no_seri << endl
                     << "Harga Gitar   : Rp. " << temp->data.harga << endl
                     << "Stok Gitar    : " << temp->data.stok << endl;
                break;
            }
            index++;
            temp = temp->next;
        }
    }else{
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    }
}

// ----------------------------------------------------------------
// DATA
// ----------------------------------------------------------------

void insertData(Node **head, int id, string merek, string jenis, string no_seri, int harga, int stok) {

    Node *nodeBaru = new Node;

    nodeBaru->data.id_gitar = id;
    nodeBaru->data.merek = merek;
    nodeBaru->data.jenis = jenis;
    nodeBaru->data.no_seri = no_seri;
    nodeBaru->data.harga = harga;
    nodeBaru->data.stok = stok;

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

// Program Utama
int main() {   

    bool akhiri;
    string ulang;

    struct Node* HEAD = NULL;
    insertData(&HEAD, 101, "Yamaha", "Akustik", "APX600", 3000000, 2);
    insertData(&HEAD, 103, "Yamaha", "Klasik", "C40", 1300000, 2);
    insertData(&HEAD, 102, "Yamaha", "Elektrik", "PACIFICA112J", 2900000, 1);

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

            // Kondisi Mengurutkan Data
            case 5:
                system("cls");
                cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
                
                if (isEmpty(HEAD)) {
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                    break;
                }

                menu_sort();
                cout << "Masukkan nomor menu >> "; cin >> no;
                if (no == 1){
                    if(panjang(HEAD) == 1){
                        system("cls");
                        cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
                        lihat(HEAD);
                        cout << "\n>>>>>>>>>>>>>>>>> Tidak Dapat Mengurutkan Data <<<<<<<<<<<<<<<<<<" << endl; 
                        cout << ">>>>>>>>>>>>>>>>>>>>>  Karena Data Hanya 1 <<<<<<<<<<<<<<<<<<<<<<" << endl;
                    }
                    else{
                        valueASC(&HEAD);
                        lihat(HEAD);
                    }
                }
                else if (no == 2){
                    if(panjang(HEAD) == 1){
                        system("cls");
                        cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
                        lihat(HEAD);
                        cout << "\n>>>>>>>>>>>>>>>>> Tidak Dapat Mengurutkan Data <<<<<<<<<<<<<<<<<<" << endl; 
                        cout << ">>>>>>>>>>>>>>>>>>>>>  Karena Data Hanya 1 <<<<<<<<<<<<<<<<<<<<<<" << endl;
                    }
                    else{
                        valueDSC(&HEAD);
                        lihat(HEAD);
                    }
                }
                else{
                    cout << "\n>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
                }
                break;
            
            // Kondisi Mencari Data
            case 6:
                system("cls");
                cout << "<<===========================|Menu Cari Data|===================================>>" << endl;
                
                if (isEmpty(HEAD)) {
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                    break;
                }

                menu_search();
                cout << "\nMasukkan Nomor Menu Searching : ";
                cin >> no;

                if (no == 1){
                    system("cls");
                    cout << "<<===========================|Menu Cari Data|===================================>>" << endl;
                    MergeSort(&HEAD, no);
                    cari(&HEAD, no);
                }
                else if (no == 2){
                    system("cls");
                    cout << "<<===========================|Menu Cari Data|===================================>>" << endl;
                    MergeSort(&HEAD, no);
                    cari(&HEAD, no);
                }
                else{
                    cout << "\n>>>>>>>>>>> KATEGORI TIDAK TERSEDIA <<<<<<<<<<<<" << endl;
                    cout << ">>>>>>>>>>>>> Data Gagal Diurutkan <<<<<<<<<<<<<" << endl;
                }
                break;

            // Kondisi Untuk Keluar Program
            case 7:
                cout << "\n<------ Terima Kasih ------>" << endl;
                exit(0);

            // Kondisi Default
            default:
                cout << "\n>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
                break;
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