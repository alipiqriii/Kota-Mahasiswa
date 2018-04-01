#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_ELM 3
main(){
	dt_kota kota[MAX_ELM];
	dt_mhs mhs;
	int pilihan;
	address p;
	infotype Del_Nama;
	int idkota;
	int i;
	
	//p untuk kota
	//q untuk mhs
	
	strcpy(kota[1].info,"Bandung");
	strcpy(kota[2].info,"Jakarta");
	
	kota[1].next = kota[2].next = Nil;
	

	while(1){
		system("cls");
		printf("===========================================================\n");
		printf("1. Tambah Data\n");
		printf("2. Delete Data\n");
		printf("3. Tampil Data\n");
		printf("4. Search Data\n");
		printf("5. Sort Data\n");
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
				address try_search;
				fflush(stdin);
				fgets(Del_Nama,MAX_WORD,stdin);
				printf("%s ",Del_Nama);
				try_search = Search(kota[1].next,Del_Nama);
				printf("Search : %s ",try_search->info);
				getchar();
		}
	}
}
