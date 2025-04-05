// File   : Metrolinked.c
// Author : Nauval Khairiyan - 241524021
// Desc   : Implementasi operasi untuk Kota dan Nama menggunakan Double Linked List

#include "Metrolinked.h"

///=================================///
/// ===== FUNGSI OPERASI KOTA ===== ///
///=================================///

// Menambahkan kota baru ke akhir DLL kota
void tambahKota(KotaNode** head, KotaNode** tail, int* jumlahKota, char namaKota[]) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("\n Kapasitas maksimum kota (%d) telah tercapai.\n", MAX_KOTA);
        return;
    }
    if (searchKota(*head, namaKota)) {
        printf("\n Kota '%s' sudah ada. Tidak dapat menambahkan duplikat.\n", namaKota);
        return;
    }
    insertKota(head, tail, namaKota);
    (*jumlahKota)++;
    printf("\n Kota '%s' berhasil ditambahkan.\n", namaKota);
}

// Menyisipkan kota setelah kota tertentu di DLL kota
void insertKotaBetween(KotaNode** head, KotaNode** tail, int* jumlahKota, char kotaSebelum[], char kotaBaru[]) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("\n Tidak dapat menyisipkan. Kapasitas maksimum kota telah tercapai.\n");
        return;
    }
    if (searchKota(*head, kotaBaru)) {
        printf("\n Kota '%s' sudah ada. Tidak dapat menambahkan duplikat.\n", kotaBaru);
        return;
    }
    KotaNode* temp = searchKota(*head, kotaSebelum);
    if (!temp) {
        printf("\n Kota '%s' tidak ditemukan. Gagal menyisipkan.\n", kotaSebelum);
        return;
    }
    insertKotaBetweenLinked(head, tail, kotaSebelum, kotaBaru);
    (*jumlahKota)++;
    printf("\n Kota '%s' berhasil disisipkan setelah kota '%s'.\n", kotaBaru, kotaSebelum);
}

// Menghapus kota dari DLL kota
void hapusKota(KotaNode** head, KotaNode** tail, int* jumlahKota, char namaKota[]) {
    KotaNode* target = searchKota(*head, namaKota);
    if (!target) {
        printf("\n Kota '%s' tidak ditemukan. Tidak ada yang dihapus.\n", namaKota);
        return;
    }
    deleteAllName(&(target->head));  // Hapus semua nama terlebih dahulu
    deleteKota(head, tail, namaKota);
    (*jumlahKota)--;
    printf("\n Kota '%s' berhasil dihapus beserta semua datanya.\n", namaKota);
}

// Mengedit nama kota pada DLL kota
void editKota(KotaNode* head, char namaLama[], char namaBaru[]) {
    KotaNode* target = searchKota(head, namaLama);
    if (!target) {
        printf("\n Kota '%s' tidak ditemukan. Tidak dapat mengedit.\n", namaLama);
        return;
    }
    if (searchKota(head, namaBaru)) {
        printf("\n Kota '%s' sudah ada. Tidak dapat menggunakan nama yang sama.\n", namaBaru);
        return;
    }
    editKotaLinked(head, namaLama, namaBaru);
    printf("\n Nama kota '%s' berhasil diubah menjadi '%s'.\n", namaLama, namaBaru);
}

///=================================///
/// ===== FUNGSI OPERASI NAMA ===== ///
///=================================///

// Menambahkan nama orang ke kota tertentu
void tambahOrang(KotaNode* headKota, char namaKota[], char namaOrang[]) {
    KotaNode* kota = searchKota(headKota, namaKota);
    if (!kota) {
        printf("\n Kota '%s' tidak ditemukan. Tidak dapat menambahkan nama.\n", namaKota);
        return;
    }
    if (searchNama(kota->head, namaOrang)) {
        printf("\n Nama '%s' sudah ada di kota '%s'.\n", namaOrang, namaKota);
        return;
    }
    insertNama(&(kota->head), namaOrang);
    printf("\n Nama '%s' berhasil ditambahkan ke kota '%s'.\n", namaOrang, namaKota);
}

// Menghapus nama dari kota tertentu
void hapusOrang(KotaNode* headKota, char namaKota[], char namaOrang[]) {
    KotaNode* kota = searchKota(headKota, namaKota);
    if (!kota) {
        printf("\n Kota '%s' tidak ditemukan. Tidak dapat menghapus nama.\n", namaKota);
        return;
    }
    if (!searchNama(kota->head, namaOrang)) {
        printf("\n Nama '%s' tidak ditemukan di kota '%s'.\n", namaOrang, namaKota);
        return;
    }
    deleteNama(&(kota->head), namaOrang);
    printf("\n Nama '%s' berhasil dihapus dari kota '%s'.\n", namaOrang, namaKota);
}

// Menyisipkan nama di antara dua nama dalam kota
void insertNamaBetween(KotaNode* headKota, char namaKota[], char namaSebelum[], char namaBaru[]) {
    KotaNode* kota = searchKota(headKota, namaKota);
    if (!kota) {
        printf("\n Kota '%s' tidak ditemukan. Tidak dapat menyisipkan nama.\n", namaKota);
        return;
    }
    if (searchNama(kota->head, namaBaru)) {
        printf("\n Nama '%s' sudah ada di kota '%s'.\n", namaBaru, namaKota);
        return;
    }
    NamaNode* posisi = searchNama(kota->head, namaSebelum);
    if (!posisi) {
        printf("\n Nama '%s' tidak ditemukan di kota '%s'.\n", namaSebelum, namaKota);
        return;
    }
    insertNamaBetweenLinked(&(kota->head), namaSebelum, namaBaru);
    printf("\n Nama '%s' berhasil disisipkan setelah '%s' di kota '%s'.\n", namaBaru, namaSebelum, namaKota);
}

// Mengedit nama dalam kota tertentu
void editNama(KotaNode* headKota, char namaKota[], char namaLama[], char namaBaru[]) {
    KotaNode* kota = searchKota(headKota, namaKota);
    if (!kota) {
        printf("\n Kota '%s' tidak ditemukan. Tidak dapat mengedit nama.\n", namaKota);
        return;
    }
    if (!searchNama(kota->head, namaLama)) {
        printf("\n Nama '%s' tidak ditemukan di kota '%s'.\n", namaLama, namaKota);
        return;
    }
    if (searchNama(kota->head, namaBaru)) {
        printf("\n Nama '%s' sudah ada di kota '%s'. Tidak dapat mengganti.\n", namaBaru, namaKota);
        return;
    }
    editNamaLinked(kota->head, namaLama, namaBaru);
    printf("\n Nama '%s' berhasil diubah menjadi '%s' di kota '%s'.\n", namaLama, namaBaru, namaKota);
}

///====================================///
/// ===== FUNGSI OPERASI LAINNYA ===== ///
///====================================///

// Mencari nama di seluruh kota
void cariNama(KotaNode* headKota, char namaOrang[]) {
    int ditemukan = 0;
    KotaNode* kota = headKota;
    while (kota != NULL) {
        NamaNode* orang = searchNama(kota->head, namaOrang);
        if (orang != NULL) {
            printf("\n Nama '%s' ditemukan di kota '%s'.\n", namaOrang, kota->nama);
            ditemukan = 1;
        }
        kota = kota->next;
    }
    if (!ditemukan) {
        printf("\n Nama '%s' tidak ditemukan di kota manapun.\n", namaOrang);
    }
}

// Menampilkan semua nama dalam satu kota
void tampilkanSatuKota(KotaNode* headKota, char namaKota[]) {
    KotaNode* kota = searchKota(headKota, namaKota);
    if (!kota) {
        printf("\n Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }
    printf("\nDaftar orang di kota '%s':\n", namaKota);
    displayNama(kota->head);
}

// Menampilkan semua kota dan nama orang di dalamnya
void tampilkanSemua(KotaNode* headKota) {
    if (!headKota) {
        printf("\n Tidak ada kota yang terdaftar.\n");
        return;
    }
    KotaNode* kota = headKota;
    while (kota != NULL) {
        printf("\nKota: %s\n", kota->nama);
        displayNama(kota->head);
        kota = kota->next;
    }
}

// Menampilkan semua kota secara terbalik (hanya nama kota)
void tampilkanReverseKota(KotaNode* headKota) {
    if (!headKota) {
        printf("\n Tidak ada kota yang terdaftar.\n");
        return;
    }

    // Maju ke kota terakhir dulu
    KotaNode* kota = headKota;
    while (kota->next != NULL) {
        kota = kota->next;
    }

    // Cetak dari kota terakhir ke awal
    printf("\nDaftar kota secara terbalik:\n");
    while (kota != NULL) {
        printf("- %s\n", kota->nama);
        kota = kota->prev;
    }
}

// Menampilkan nama dalam satu kota secara terbalik
void tampilkanReverseNama(KotaNode* headKota, char namaKota[]) {
    KotaNode* kota = searchKota(headKota, namaKota);
    if (!kota) {
        printf("\n Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }
    printf("\nDaftar orang di kota '%s' (terbalik):\n", namaKota);
    displayNamaReverse(kota->head);
}

///============================///
/// ===== TAMPILKAN MENU ===== ///
///============================///

void tampilkanMenu() {
    printf("\n============ MENU KOTA =============\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Kota Diantara Kota Lain\n");
    printf("3. Hapus Kota\n");
    printf("4. Edit Kota\n");
    printf("\n============ MENU NAMA =============\n");
    printf("5. Tambah Orang dalam Kota\n");
    printf("6. Tambah Orang Diantara Nama lain\n");
    printf("7. Hapus Orang dalam Kota\n");
    printf("8. Edit Nama Orang dalam Kota\n");
    printf("9. Cari Nama Orang Berada\n");
    printf("\n=========== MENU DISPLAY ===========\n");
    printf("10. Tampilkan Data Satu Kota\n");
    printf("11. Tampilkan Semua Data\n");
    printf("12. Tampilkan Kota Terbalik\n");
    printf("13. Tampilkan Nama Terbalik\n");
    printf("\n====================================\n");
    printf("0. Keluar\n\n");
    printf("Pilihan Anda: ");
}
