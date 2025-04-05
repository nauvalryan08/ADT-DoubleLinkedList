// File   : linked.c
// Author : Nauval Khairiyan - 241524021
// Desc   : Implementasi struktur data DLL Kota dan DLL Nama

#include "Linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============================== //
// === FUNGSI UNTUK NAMA (DLL) === //
// =============================== //

NamaNode* createNamaNode(char nama[]) {
    NamaNode* baru = (NamaNode*)malloc(sizeof(NamaNode));
    strcpy(baru->nama, nama);
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

void insertNama(NamaNode** head, char nama[]) {
    NamaNode* baru = createNamaNode(nama);
    if (*head == NULL) {
        *head = baru;
    } else {
        NamaNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = baru;
        baru->prev = current;
    }
}

void insertNamaBetweenLinked(NamaNode** head, char sebelum[], char namaBaru[]) {
    NamaNode* current = *head;
    while (current != NULL && strcmp(current->nama, sebelum) != 0) {
        current = current->next;
    }

    if (current == NULL) return;
    NamaNode* baru = createNamaNode(namaBaru);
    baru->next = current->next;
    baru->prev = current;

    if (current->next != NULL) {
        current->next->prev = baru;
    }
    current->next = baru;
}

void deleteNama(NamaNode** head, char nama[]) {
    NamaNode* current = *head;
    while (current != NULL) {
        if (strcmp(current->nama, nama) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

void deleteAllName(NamaNode** head) {
    NamaNode* temp = *head;
    while (temp != NULL) {
        NamaNode* hapus = temp;
        temp = temp->next;
        free(hapus);
    }
    *head = NULL;
}

void editNamaLinked(NamaNode* head, char namaLama[], char namaBaru[]) {
    NamaNode* temp = head;
    while (temp) {
        if (strcmp(temp->nama, namaLama) == 0) {
            strcpy(temp->nama, namaBaru);
            return;
        }
        temp = temp->next;
    }
}

void displayNama(NamaNode* head) {
    NamaNode* temp = head;
    while (temp != NULL) {
        printf("   - %s\n", temp->nama);
        temp = temp->next;
    }
}

void displayNamaReverse(NamaNode* head) {
    if (!head) {
        printf("  (Kosong)\n");
        return;
    }

    NamaNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        printf("  - %s\n", current->nama);
        current = current->prev;
    }
}

// Mencari node nama tertentu dalam DLL nama
NamaNode* searchNama(NamaNode* head, char nama[]) {
    NamaNode* current = head;
    while (current != NULL) {
        if (strcmp(current->nama, nama) == 0) {
            return current;  // Ditemukan
        }
        current = current->next;
    }
    return NULL;  // Tidak ditemukan
}

// =============================== //
// === FUNGSI UNTUK KOTA (DLL) === //
// =============================== //

KotaNode* createKotaNode(char nama[]) {
    KotaNode* baru = (KotaNode*)malloc(sizeof(KotaNode));
    strcpy(baru->nama, nama);
    baru->prev = NULL;
    baru->next = NULL;
    baru->head = NULL;
    return baru;
}

void insertKota(KotaNode** head, KotaNode** tail, char nama[]) {
    KotaNode* baru = createKotaNode(nama);
    if (*head == NULL) {
        *head = *tail = baru;
    } else {
        (*tail)->next = baru;
        baru->prev = *tail;
        *tail = baru;
    }
}

void insertKotaBetweenLinked(KotaNode** head, KotaNode** tail, char kotaSebelum[], char kotaBaru[]) {
    KotaNode* temp = *head;
    while (temp && strcmp(temp->nama, kotaSebelum) != 0) {
        temp = temp->next;
    }
    if (!temp) return;

    KotaNode* baru = createKotaNode(kotaBaru);
    baru->next = temp->next;
    baru->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = baru;
    } else {
        *tail = baru;
    }
    temp->next = baru;
}

void deleteKota(KotaNode** head, KotaNode** tail, char nama[]) {
    KotaNode* temp = *head;
    while (temp && strcmp(temp->nama, nama) != 0) {
        temp = temp->next;
    }
    if (!temp) return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;
    else
        *tail = temp->prev;

    free(temp);
}

void editKotaLinked(KotaNode* head, char namaLama[], char namaBaru[]) {
    KotaNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nama, namaLama) == 0) {
            strcpy(temp->nama, namaBaru);
            return;
        }
        temp = temp->next;
    }
}

KotaNode* searchKota(KotaNode* head, char nama[]) {
    KotaNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nama, nama) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void displayKota(KotaNode* head) {
    KotaNode* temp = head;
    while (temp != NULL) {
        printf("\n? Kota: %s\n", temp->nama);
        displayNama(temp->head);
        temp = temp->next;
    }
}

void displayKotaReverse(KotaNode* tail) {
    KotaNode* temp = tail;
    while (temp != NULL) {
        printf("\n? Kota: %s\n", temp->nama);
        temp = temp->prev;
    }
}

