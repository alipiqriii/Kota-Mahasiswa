#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX_ELM 4
main(){
	dt_kota kota[MAX_ELM];
	dt_mhs mhs;
	int pilihan,pilihan_search;
	address p;
	infotype Del_Nama;
	int idkota;
	int i;
	
	strcpy(kota[1].info,"Bandung");
	strcpy(kota[2].info,"Jakarta");
	strcpy(kota[3].info,"Garut");
	
	kota[1].next = kota[2].next = kota[3].next = Nil;
	

	while(1){
		system("cls");
		printf("===========================================================\n");
		printf("1. Tambah Data\n");
		printf("2. Delete Data\n");
		printf("3. Tampil Data\n");
		printf("4. Search Data\n");
		printf("===========================================================\n");
		printf("Pilihan : ");scanf("%d",&pilihan);
		switch(pilihan){
			case 1 :
				Menu_Kota();
				printf("ID Kota : "); scanf("%d",&idkota); fflush(stdin);
				Add_Data(&kota[idkota].next);	
				break;
			case 2 :
				Menu_Kota();
				printf("ID Kota : "); scanf("%d",&idkota); fflush(stdin);
				Tampil_Mhs(kota[idkota].next);
				printf("\n Indeks Data Yang Akan Dihapus : ");scanf("%d",&i); fflush(stdin);
				Del_Data(&kota[idkota].next,i,&Del_Nama);
				printf("%s Di Delete",Del_Nama);
				break;
			case 3 :
				Menu_Kota();
				printf("ID Kota : "); scanf("%d",&idkota); fflush(stdin);
				printf("%s : \n",kota[idkota].info); 
				Tampil_Mhs(kota[idkota].next);
				system("pause");
				break;
			case 4 :
				
				printf("1. Search Kota\n2. Search Nama\n\nPilihan : ");
				scanf("%d",&pilihan_search);
				int count;
				address String;
				infotype CariInfo;
				
				switch(pilihan_search){
					case 1 :
					printf("===================================\nSearch Kota \n===================================\n");
					printf("Uppercase Lowercase Berpengaruh\n");
					printf("Masukan Kota Untuk Dicari : ");
					fflush(stdin);gets(CariInfo);
					idkota=1;
					while(idkota<=MAX_ELM){
						if(strcmp(kota[idkota].info,CariInfo)==0) {
							printf("\tNama Kota : %s\n",kota[idkota].info);
							Tampil_Mhs(kota[idkota].next);
						}
						idkota++;
					}
					break;
					case 2:
					printf("===================================\nSearch Nama \n===================================\n");
					printf("Masukan Nama Untuk Dicari : ");
					fflush(stdin);gets(CariInfo);
					idkota=1;
					count=0;
					while(idkota<=MAX_ELM){
						String=kota[idkota].next;
						while(String!=NULL){
							if(CekString(String->info,CariInfo)) {
								count++;
								printf("\t[%d] Kota : %s \t Nama : %s",count,kota[idkota].info,String->info);	
							}  
							String = String->next;
						}
						idkota = idkota+1;
					}
					if (count==0) printf("\nData Tidak Ditemukan\n");
					break;
					default : break;
				}
				system("pause");
				break;
				default : break;
				
		}
	}
}
