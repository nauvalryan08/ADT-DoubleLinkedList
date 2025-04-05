// File   : Metrolinked.h
// Author : Nauval Khairiyan - 241524021
// Desc   : File header untuk operasi kota dan orang dengan double linked list

#ifndef METROLINKED_H
#define METROLINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked.h"

// Fungsi Operasi Kota (versi refactor dengan jumlahKota & tail)
void tambahKota(KotaNode** head, KotaNode** tail, int* jumlahKota, char namaKota[]);
void insertKotaBetween(KotaNode** head, KotaNode** tail, int* jumlahKota, char kotaSebelum[], char kotaBaru[]);
void hapusKota(KotaNode** head, KotaNode** tail, int* jumlahKota, char namaKota[]);
void editKota(KotaNode* head, char namaLama[], char namaBaru[]);

// Fungsi Operasi Nama
void tambahOrang(KotaNode* headKota, char namaKota[], char namaOrang[]);
void insertNamaBetween(KotaNode* headKota, char namaKota[], char namaSebelum[], char namaBaru[]);
void hapusOrang(KotaNode* headKota, char namaKota[], char namaOrang[]);
void editNama(KotaNode* headKota, char namaKota[], char namaLama[], char namaBaru[]);

// Fungsi Search dan Display
void cariNama(KotaNode* headKota, char namaOrang[]);
void tampilkanSatuKota(KotaNode* headKota, char namaKota[]);
void tampilkanSemua(KotaNode* headKota);
void tampilkanReverseKota(KotaNode* headKota); 
void tampilkanReverseNama(KotaNode* headKota, char namaKota[]);

// Fungsi Menu Utama di Main Program
void tampilkanMenu();

#endif

