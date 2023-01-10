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
  Node *next;
  Node *prev;
};

int panjangList;

// ----------------------------------------------------------------
// CRUD LINKED LIST
// ----------------------------------------------------------------

// Fungsi Jika Node Kosong
int isEmpty(Node *head, Node *tail) {
	if(head == NULL && tail == NULL) {
		return 1;
	}
	else return 0;
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
    panjangList++;

    cout << "\n>>>>>>>>>>>>> DATA TELAH DITAMBAH <<<<<<<<<<<<<" << endl;

    return nodeBaru;
}

// Prosedur Menambah data linkedlist di awal
void addFirst(Node **head, Node **tail){
    Node *nodeBaru = newNode();
    nodeBaru->next = *head;
    nodeBaru->prev = NULL;
    if (*head == NULL && *tail == NULL){
        *head = nodeBaru;
        *tail = nodeBaru;
    } else {
        (*head)->prev = nodeBaru;
        *head = nodeBaru;
    }
}

// Prosedur Menambah data linkedlist secara spesifik
void addSpecific(Node **head, Node **tail) {
    
    if (isEmpty(*head, *tail)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>> Tidak Dapat Menambahkan Data <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl; 
        cout << ">>>>>>>>>>>>>>>>>>>>>  Karena Data Masih Kosong  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << ">>>>>>> (Masukkan Data Minimal 1 dengan add first / add last) <<<<<<<<<<<<<<<<<<<<"  << endl;
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

    if (panjangList != 0 && index >= panjangList+1 || index <= 0){
        cout << "\n>>>>>>>>>>>> Posisi Data Tidak Ada <<<<<<<<<<<<" << endl;
        return;
    }

    Node *nodeBaru = newNode();

    if (index == 1){
        nodeBaru->prev = NULL;
        nodeBaru->next = *head;
        if (*head == NULL && *tail == NULL){
            *head = nodeBaru;
            *tail = nodeBaru;
        } 
        else {
            (*head)->prev = nodeBaru;
            *head = nodeBaru;
        }
    } 
    else if (index == panjangList + 1){
        nodeBaru->prev = *tail;
        nodeBaru->next = NULL;
        (*tail)->next = nodeBaru;
        *tail = nodeBaru;
    } 
    else {
        if (index <= panjangList/2){
            Node *cur = *head;
            for (int trv = 1; trv < index - 1 && cur != NULL; trv++) cur = cur->next;
            nodeBaru->next = cur->next;
            nodeBaru->prev = cur;
            cur->next->prev = nodeBaru;
            cur->next = nodeBaru;
        }
        else if (index > panjangList/2){
            Node *cur = *tail;
            for (int trv = panjangList; trv > index + 1 && cur != NULL; trv--) cur = cur->prev;
            nodeBaru->next = cur;
            nodeBaru->prev = cur->prev;
            cur->prev->next = nodeBaru;
            cur->prev = nodeBaru;
        }
    }
}

// Prosedur Menambah data linkedlist di akhir
void addLast(Node **head, Node **tail){
    Node *nodeBaru = newNode();

    nodeBaru->prev = *tail;
    nodeBaru->next = NULL;
    if (*head == NULL && *tail == NULL){
        *head = nodeBaru;
        *tail = nodeBaru;
    } else {
        (*tail)->next = nodeBaru;
        *tail = nodeBaru;
    }
}

// Prosedur Ubah Data
void update(Node **head, Node **tail){
    
    if (isEmpty(*head, *tail)) {
        return;
    }

    int indeks = 0;
    cout << "\n- Nomor Berapa Yang Ingin Diubah ?? >> ";
    cin >> indeks;

    int ubah = indeks - 1;

    Node *temp;
    temp = *head;
    
    if (indeks > 0 && indeks <= panjangList){
        for(int i = 0; i < ubah && temp != NULL; i++){
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

// Prosedur Menghapus data linkedlist di awal
void delFirst(Node **head, Node **tail) {

    // Jika linked list kosong
    if (isEmpty(*head, *tail)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        return;
    }else if((*head)->next == NULL){
        Node *del = *head;
        *head = NULL;
        *tail = NULL;
        delete del;
        panjangList--;
    } else {
        Node *del;
        del = *head;    
        *head = (*head)->next;
        (*head)->prev = NULL;
        delete del;
        panjangList--;
    }

    cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
}

// Prosedur Menghapus data linkedlist secara spesifik
void deleteSpecific(Node **head, Node **tail){   
    
    if (isEmpty(*head, *tail)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>> Tidak Dapat Menghapus Data <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl; 
        cout << ">>>>>>>>>>>>>>>>>>>>>>  Karena Data Masih Kosong  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << ">>>>>>>>> (Masukkan Data Minimal 1 dengan add first / add last) <<<<<<<<<<<<<<<<<<"  << endl;
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
    cout << "\n- Hapus Data Pada Nomor >> ";
    cin >> index;

    int hapus = index - 1;

    if (panjangList != 0 && index >= panjangList+1 || index <= 0){
        cout << "\n>>>>>>>>>>>> Posisi Data Tidak Ada <<<<<<<<<<<<" << endl;
        return;
    }

    if (hapus == 0 && panjangList > 1){
        Node *del = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        delete del;

    } 
    else if (hapus == 0 && panjangList == 1){
        Node *del = *head;
        *head = NULL;
        *tail = NULL;
        delete del;
    } 
    else {
        if (hapus < panjangList/2){
            Node *cur = *head;
            for (int trv = 0; trv < hapus; trv++){
                cur = cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
        } else {
            Node *cur = *tail;
            for (int trv = panjangList - 1; trv > hapus; trv--){
                cur = cur->prev;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
        }
    }
    panjangList--;
    cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
}

// Prosedur Menghapus data linkedlist di akhir
void delLast(Node **head, Node **tail) {

    // Jika linked list kosong
    if (isEmpty(*head, *tail)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        return;
    }else if((*head)->next == NULL){
        Node *del = *head;
        *head = NULL;
        *tail = NULL;
        delete del;
        panjangList--;
    } else {
        Node *del;
        del = *tail;    
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        delete del;
        panjangList--;
    }

    cout << "\n>>>>>>>>>>>>>> DATA TELAH DIHAPUS <<<<<<<<<<<<<" << endl;
}

// Prosedur Lihat Data
void show(Node *head, Node *tail) {
    
    // Jika linked list kosong
    if (isEmpty(head, tail)) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        return;
    }else{
        Node *temp = head;
        int indeks;
        for (indeks = 0; temp != NULL; indeks++){
            cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>  | "<< indeks+1 <<" | <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
                << "ID Gitar      : " << temp->data.id_gitar << endl
                << "Merek Gitar   : " << temp->data.merek << endl
                << "Jenis Gitar   : " << temp->data.jenis << endl
                << "No Seri Gitar : " << temp->data.no_seri << endl
                << "Harga Gitar   : Rp. " << temp->data.harga << endl
                << "Stok Gitar    : " << temp->data.stok << endl;
            temp = temp->next;
        }
        panjangList = indeks;
    }

}

// Prosedur Foward
void foward(Node *head){
    cout << "<<==========================|Menu Lihat Data|===================================>>" << endl;
    system("cls");
    Node *temp = head;
    int i = 1;
    while (temp != NULL) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>  | "<< i <<" | <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
            << "ID Gitar      : " << temp->data.id_gitar << endl
            << "Merek Gitar   : " << temp->data.merek << endl
            << "Jenis Gitar   : " << temp->data.jenis << endl
            << "No Seri Gitar : " << temp->data.no_seri << endl
            << "Harga Gitar   : Rp. " << temp->data.harga << endl
            << "Stok Gitar    : " << temp->data.stok << endl;
        i += 1;
        temp = temp->next;
    }
}

// Prosedur Backward
void backward(Node *tail){
    system("cls");
    cout << "<<==========================|Menu Lihat Data|===================================>>" << endl;
    Node *temp = tail;
    int i = 1;
    while (temp != NULL) {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>  | "<< i <<" | <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
            << "ID Gitar      : " << temp->data.id_gitar << endl
            << "Merek Gitar   : " << temp->data.merek << endl
            << "Jenis Gitar   : " << temp->data.jenis << endl
            << "No Seri Gitar : " << temp->data.no_seri << endl
            << "Harga Gitar   : Rp. " << temp->data.harga << endl
            << "Stok Gitar    : " << temp->data.stok << endl;
        i += 1;
        temp = temp->prev;
    }
}

// ----------------------------------------------------------------
// SORTING MERGE SORT
// ----------------------------------------------------------------

// Ascending 
Node *SortedMergeASC(Node *a, Node *b, int kategoriASC) {
    
    Node *result = NULL;
    if (a == NULL){
        return (b);
    }
    else if (b == NULL){
        return (a);
    }

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
        result->next->prev = a;
        result->prev = NULL;
    }
    else{
        result = b;
        result->next = SortedMergeASC(a, b->next, kategoriASC);
        result->next->prev = b;
        result->prev = NULL;
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
        result->next->prev = a;
        result->prev = NULL;
    }
    else{
        result = b;
        result->next = SortedMergeDSC(a, b->next, kategoriDSC);
        result->next->prev = b;
        result->prev = NULL;
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

// Prosedur agar tail berpindah ke akhir node
void moveTail(Node **head, Node **tail){
    Node *cur = *head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    *tail = cur;
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
        result->next->prev = a;
        result->prev = NULL;
    }else{
        result = b;
        result->next = SortedMerge(a, b->next, pilihSearch);
        result->next->prev = b;
        result->prev = NULL;
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

    // int panjangList = panjang(*head);
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
         << "2) AddSpecific" << endl
         << "3) AddLast" << endl;
}

// Prosedur Tampilan Menu Lihat
void menu_show(){
    cout << "\n>>>>>>>>>>>>>>>>>>>> --------Menu-------- <<<<<<<<<<<<<<<<<<<<<<<" << endl
         << "1) Lihat Secara Foward" << endl
         << "2) Lihat Secara Backward" << endl
         << "3) Kembali" << endl;
}

// Prosedur Tampilan Menu Hapus
void menu_del(){
    
  cout << "\n================================================" << endl
       << "|---------------------Hapus--------------------|" << endl
       << "|-------------------LinkedList-----------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "1) DeleteFirst" << endl
       << "2) DeleteSpecific" << endl
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
// DATA
// ----------------------------------------------------------------

void insertData(Node **head, Node **tail, int id, string merek, string jenis, string no_seri, int harga, int stok) {

    Node *nodeBaru = new Node;

    nodeBaru->data.id_gitar = id;
    nodeBaru->data.merek = merek;
    nodeBaru->data.jenis = jenis;
    nodeBaru->data.no_seri = no_seri;
    nodeBaru->data.harga = harga;
    nodeBaru->data.stok = stok;

    nodeBaru->prev = *tail;
    nodeBaru->next = NULL;
    if (*head == NULL && *tail == NULL){
        *head = nodeBaru;
        *tail = nodeBaru;
    } else {
        (*tail)->next = nodeBaru;
        *tail = nodeBaru;
    }

    panjangList++;
}

// Program Utama
int main() {   

    Node *HEAD = NULL, *TAIL = NULL;

    insertData(&HEAD, &TAIL, 101, "Yamaha", "Akustik", "APX600", 3000000, 2);
    insertData(&HEAD, &TAIL, 103, "Yamaha", "Klasik", "C40", 1300000, 2);
    insertData(&HEAD, &TAIL, 102, "Yamaha", "Elektrik", "PACIFICA112J", 2900000, 1);
    moveTail(&HEAD, &TAIL);

    bool akhiri;
    string ulang;

    // Perulangan while
    while(akhiri == false){

        awal :
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
                    addFirst(&HEAD, &TAIL);
                }
                else if(no == 2){
                    addSpecific(&HEAD, &TAIL);
                }
                else if(no == 3){
                    addLast(&HEAD, &TAIL);
                }
                else{
                    cout << "\n>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
                }
                break;

            // Kondisi Melihat Data
            case 2:
                system("cls");
                cout << "<<==========================|Menu Lihat Data|===================================>>" << endl;
                show(HEAD, TAIL);
                                
                if (isEmpty(HEAD, TAIL)) {
                    break;
                }

                menu_show();
                cout << "Masukkan nomor menu >> "; cin >> no;
                if (no == 1){
                    foward(HEAD);
                }
                else if(no == 2){
                    backward(TAIL);
                }
                else if(no == 3){
                    goto awal;
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;

            // Kondisi Mengubah Data
            case 3:
                system("cls");
                cout << "<<===========================|Menu Ubah Data|===================================>>" << endl;
                show(HEAD, TAIL);
                update(&HEAD, &TAIL);
                break;
            
            // Kondisi Menghapus Data
            case 4:
                system("cls");
                cout << "<<===========================|Menu Hapus Data|==================================>>" << endl;
                menu_del();
                cout << "Masukkan nomor menu >> "; cin >> no;
                if (no == 1){
                    delFirst(&HEAD, &TAIL);
                }
                else if(no == 2){
                    deleteSpecific(&HEAD, &TAIL);
                }
                else if(no == 3){
                    delLast(&HEAD, &TAIL);
                }
                else{
                    cout << "\n>>>>>>>>>>>>> MENU TIDAK TERSEDIA <<<<<<<<<<<<<" << endl;
                }
                break;
            
            // Kondisi Mengurutkan Data
            case 5:
                system("cls");
                cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
                
                if (isEmpty(HEAD, TAIL)) {
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                    break;
                }

                menu_sort();
                cout << "Masukkan nomor menu >> "; cin >> no;
                if (no == 1){
                    if(panjangList == 1){
                        system("cls");
                        cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
                        show(HEAD, TAIL);
                        cout << "\n>>>>>>>>>>>>>>>>> Tidak Dapat Mengurutkan Data <<<<<<<<<<<<<<<<<<" << endl; 
                        cout << ">>>>>>>>>>>>>>>>>>>>>  Karena Data Hanya 1 <<<<<<<<<<<<<<<<<<<<<<" << endl;
                    }
                    else{
                        valueASC(&HEAD);
                        moveTail(&HEAD, &TAIL);
                        show(HEAD, TAIL);
                    }
                }
                else if (no == 2){
                    if(panjangList == 1){
                        system("cls");
                        cout << "<<===========================|Menu Sort Data|===================================>>" << endl;
                        show(HEAD, TAIL);
                        cout << "\n>>>>>>>>>>>>>>>>> Tidak Dapat Mengurutkan Data <<<<<<<<<<<<<<<<<<" << endl; 
                        cout << ">>>>>>>>>>>>>>>>>>>>>  Karena Data Hanya 1 <<<<<<<<<<<<<<<<<<<<<<" << endl;
                    }
                    else{
                        valueDSC(&HEAD);
                        moveTail(&HEAD, &TAIL);
                        show(HEAD, TAIL);
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
                
                if (isEmpty(HEAD, TAIL)) {
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
                    moveTail(&HEAD, &TAIL);
                    cari(&HEAD, no);
                }
                else if (no == 2){
                    system("cls");
                    cout << "<<===========================|Menu Cari Data|===================================>>" << endl;
                    MergeSort(&HEAD, no);
                    moveTail(&HEAD, &TAIL);
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