#include "custom.h"
void Add_Data(address *p){
	address q;
	infotype value_nama;
	printf("Nama : "); fgets(value_nama,MAX_WORD,stdin);
	Create_Node(&q);
	Isi_Node(&q,value_nama);
	Ins_Akhir(p,q);
}

void Menu_Kota(){
	printf("=========================================\n");
	printf("1. Bandung\n");
	printf("2. Jakarta\n");
	printf("=========================================\n");
}

void Tampil_Mhs(address p){
	int jum_elemen;
	Tampil_List(p);
	jum_elemen=NbElmt(p);
	printf("\nJumlah Siswa : %d",jum_elemen);
}

void Del_Data(address *p,int indeks,infotype *Del_Info){
	address temp = *p;
	address before;
	int jum_elemen=NbElmt(*p);
	int count=1;
	if (1 <= indeks <= jum_elemen){
		if(indeks == 1) Del_Awal(p,Del_Info);
		else if(indeks == jum_elemen) Del_Akhir(p,Del_Info);
		else {
			if(!isEmpty(*p)){
				while(!isEmpty(next(temp)) && count != indeks){
					before=temp;
					temp=next(temp);
					count++;
				}
				next(before) = next(temp);
				strcpy(*Del_Info,info(temp));
				DeAlokasi(&temp); 	
			}
		}
	}
}
