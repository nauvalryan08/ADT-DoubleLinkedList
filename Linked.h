// File   : Linked.h
// Author : Nauval Khairiyan - 241524021
// Desc   : Header file untuk Double Linked List (DLL) nama dan kota

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 20
#define STR_MAX 50

// Struktur node untuk nama (DLL per kota)
typedef struct NamaNode {
    char nama[STR_MAX];           // Nama Orang
    struct NamaNode* next;        // Pointer ke nama berikutnya
    struct NamaNode* prev;        // Pointer ke nama sebelumnya
} NamaNode;

// Struktur node untuk kota (DLL antar kota)
typedef struct KotaNode {
    char nama[STR_MAX];           // Nama kota
    struct KotaNode* next;        // Pointer ke kota berikutnya
    struct KotaNode* prev;        // Pointer ke kota sebelumnya
    NamaNode* head;               // Pointer ke linked list orang dalam kota
} KotaNode;

/// ===== OPERASI UNTUK LINKED LIST KOTA =====
KotaNode* createKotaNode(char nama[]);
void insertKota(KotaNode** head, KotaNode** tail, char nama[]);
void insertKotaBetweenLinked(KotaNode** head, KotaNode** tail, char kotaSebelum[], char kotaBaru[]);
void deleteKota(KotaNode** head, KotaNode** tail, char nama[]);
void editKotaLinked(KotaNode* head, char namaLama[], char namaBaru[]);
void displayKota(KotaNode* head);
void displayKotaReverse(KotaNode* tail);
KotaNode* searchKota(KotaNode* head, char nama[]);

/// ===== OPERASI UNTUK LINKED LIST NAMA =====
NamaNode* createNamaNode(char nama[]);
void insertNama(NamaNode** head, char nama[]);
void insertNamaBetweenLinked(NamaNode** head, char namaSebelum[], char namaBaru[]);
void deleteNama(NamaNode** head, char nama[]);
void deleteAllName(NamaNode** head);
void editNamaLinked(NamaNode* head, char namaLama[], char namaBaru[]);
void displayNama(NamaNode* head);
void displayNamaReverse(NamaNode* head);
NamaNode* searchNama(NamaNode* head, char nama[]);

#endif

