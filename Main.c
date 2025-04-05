// File   : Main.c
// Author : Nauval Khairiyan - 241524021
// Desc   : File utama untuk menjalankan program

#include "Metrolinked.h"

int main() {
    KotaNode* head = NULL;
    KotaNode* tail = NULL;
    int jumlahKota = 0;
    int pilihan;

    // Variabel umum
    char kotaNew[STR_MAX], kotaBefore[STR_MAX], kotaName[STR_MAX];
    char namaNew[STR_MAX], namaBefore[STR_MAX], namaName[STR_MAX];

    do {
    	system("cls");
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1: // Tambah Kota
            	system("cls");
                printf("\nMasukkan nama kota baru: ");
                fgets(kotaNew, STR_MAX, stdin);
                kotaNew[strcspn(kotaNew, "\n")] = 0;
                tambahKota(&head, &tail, &jumlahKota, kotaNew);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;

            case 2: // Tambah Kota ditengah
            	system("cls");
                printf("\nMasukkan nama kota sebelum: ");
                fgets(kotaBefore, STR_MAX, stdin);
                kotaBefore[strcspn(kotaBefore, "\n")] = 0;
                printf("Masukkan nama kota baru: ");
                fgets(kotaNew, STR_MAX, stdin);
                kotaNew[strcspn(kotaNew, "\n")] = 0;
                insertKotaBetween(&head, &tail, &jumlahKota, kotaBefore, kotaNew);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;

            case 3: // Hapus Kota
            	system("cls");
                printf("\nMasukkan nama kota yang akan dihapus: ");
                fgets(kotaName, STR_MAX, stdin);
                kotaName[strcspn(kotaName, "\n")] = 0;
                hapusKota(&head, &tail, &jumlahKota, kotaName);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;

            case 4: // Edit Kota
            	system("cls");
                printf("\nMasukkan nama kota lama: ");
                fgets(kotaBefore, STR_MAX, stdin);
                kotaBefore[strcspn(kotaBefore, "\n")] = 0;
                printf("Masukkan nama kota baru: ");
                fgets(kotaNew, STR_MAX, stdin);
                kotaNew[strcspn(kotaNew, "\n")] = 0;
                editKota(head, kotaBefore, kotaNew);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;
                
            case 5: // Tambah Nama
            	system("cls");
                printf("Masukkan nama kota: ");
                fgets(kotaName, STR_MAX, stdin);
                kotaName[strcspn(kotaName, "\n")] = '\0';
                printf("Masukkan nama orang: ");
                fgets(namaNew, STR_MAX, stdin);
                namaNew[strcspn(namaNew, "\n")] = '\0';
                tambahOrang(head, kotaName, namaNew);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;
                
            case 6: // Tambah Nama ditengah
            	system("cls");
                printf("Masukkan nama kota: ");
                fgets(kotaName, STR_MAX, stdin);
                kotaName[strcspn(kotaName, "\n")] = '\0';
                printf("Masukkan nama sebelum: ");
                fgets(namaBefore, STR_MAX, stdin);
                namaBefore[strcspn(namaBefore, "\n")] = '\0';
                printf("Masukkan nama yang ingin disisipkan: ");
                fgets(namaNew, STR_MAX, stdin);
                namaNew[strcspn(namaNew, "\n")] = '\0';
                insertNamaBetween(head, kotaName, namaBefore, namaNew);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;
                
            case 7: // Hapus Nama
            	system("cls");
                printf("Masukkan nama kota: ");
                fgets(kotaName, STR_MAX, stdin);
                kotaName[strcspn(kotaName, "\n")] = '\0';
                printf("Masukkan nama orang yang ingin dihapus: ");
                fgets(namaName, STR_MAX, stdin);
                namaName[strcspn(namaName, "\n")] = '\0';
                hapusOrang(head, kotaName, namaName);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;
                
            case 8: // Edit Nama
            	system("cls");
                printf("Masukkan nama kota: ");
                fgets(kotaName, STR_MAX, stdin);
                kotaName[strcspn(kotaName, "\n")] = '\0';
                printf("Masukkan nama lama: ");
                fgets(namaBefore, STR_MAX, stdin);
                namaBefore[strcspn(namaBefore, "\n")] = '\0';
                printf("Masukkan nama baru: ");
                fgets(namaNew, STR_MAX, stdin);
                namaNew[strcspn(namaNew, "\n")] = '\0';
                editNama(head, kotaName, namaBefore, namaNew);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;
                
            case 9: // Cari Nama dalam Kota
            	system("cls");
                printf("Masukkan nama orang yang ingin dicari: ");
                fgets(namaName, STR_MAX, stdin);
                namaName[strcspn(namaName, "\n")] = '\0';
                cariNama(head, namaName);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                break;
            
            case 10: // Tampilkan Satu Kota
            	system("cls");
			    printf("Masukkan nama kota yang ingin ditampilkan: ");
			    fgets(kotaName, STR_MAX, stdin);
			    kotaName[strcspn(kotaName, "\n")] = '\0';
			    tampilkanSatuKota(head, kotaName);
			    printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
			    break;

			case 11: // Tampilkan Semua Kota beserta Nama
				system("cls");
			    tampilkanSemua(head);
			    printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
			    break;
			
			case 12: // Tampilkan Kota Terbalik
				system("cls");
			    tampilkanReverseKota(head);
			    printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
			    break;
			
			case 13: // Tampilkan Nama Terbalik
				system("cls");
			    printf("Masukkan nama kota untuk menampilkan nama secara terbalik: ");
			    fgets(kotaName, STR_MAX, stdin);
			    kotaName[strcspn(kotaName, "\n")] = '\0';
			    tampilkanReverseNama(head, kotaName);
			    printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
			    break;
		        
            case 0:
                printf("\nProgram selesai.\n");
                break;

            default:
                printf("\n? Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (pilihan != 0);

    return 0;
}

