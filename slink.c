#include "slink.h"
#include "boolean.h"
#include <string.h>
boolean isEmpty(address p){
	if(p == Nil){
		return true;
	}
	else return false;
}

void Create_Node (address *p){
	*p = (address) malloc(sizeof(dt_mhs));
	if(isEmpty(*p)) printf("Alokasi Gagal");	
}

void Isi_Node(address *p,infotype nilai){
	if(!isEmpty(*p)){
		strcpy(info(*p),nilai);
   		next(*p) = Nil;	
	}
	else printf("Isi Nilai Gagal");    
} 

//infotype Create_Word(){
//	fflush(stdin);
//	infotype value;
//	value = (char*) malloc(20*sizeof(char));
//	printf("Masukan Nama [Max 20] : "); gets(value);
//	if (value == Nil) {
//		printf("Alokasi Gagal");
//		return Nil;
//	}
//	else return value;
//}

void Tampil_List (address p){
	int count=1;
   	while(!isEmpty(p)){
   	printf("\t[%d]. %s",count,info(p));
	p = next(p);
	count++;
   }
   printf("\n");
}

void Ins_Awal (address *p, address PNew){
	if(isEmpty(*p)){
		next(PNew) = Nil;        
   		*p = PNew;
	}
	else {
			next(PNew) = Nil; 
		   	next(PNew) = *p;    
		   	*p = PNew;
	}	
}

void Ins_Akhir (address *p, address PNew){
	address temp;					
	if(isEmpty(*p)){		
		next(PNew) = Nil;        
   		*p = PNew;
	}
	else {							
		temp = *p;
		while(!isEmpty(next(temp))){
			temp=next(temp);
		}
		next(temp) = PNew;	
	}	
}

int NbElmt (address p){
	if(p == Nil) return 0;
	return 1 + NbElmt(next(p));
	
}

address Search (address p, infotype nilai){
		if(isEmpty(p)){
			return 0;
		}
		else {
		address temp;
		boolean found=false;
		temp = p;
		while(!isEmpty(p) && !found){
			if (strcmp(info(temp),nilai) == 0)found = true;
			else temp = next(temp);
		}
		if(next(temp) == Nil) return Nil;
		else return temp;
		}
}
	
void InsertAfter (address *pBef, address PNew){
	if(!isEmpty(*pBef)){
	next(PNew) = next(*pBef);
	next(*pBef) = PNew;
	}
}
	
void Del_Awal (address * p, infotype *X){
		if(!isEmpty(*p)){
			address temp;
			temp = *p;
			*p = next(temp);
			strcpy(*X,info(temp));
			next(temp) = Nil;
			DeAlokasi(&temp);	
		}
	}
	
void DeAlokasi (address *p){
	if(isEmpty(*p)) free(*p);
}

void Del_Akhir (address * p, infotype *X){
		address temp;
		address temp2;
		if(!isEmpty(*p)){
			temp = temp2 = *p;
			while(!isEmpty(next(temp))){
				temp2=temp;
				temp=next(temp);
			}
			if(*p == temp){
				Del_Awal(p,X);
			}
			else {
				next(temp2) = Nil;
				strcpy(*X,info(temp));
				DeAlokasi(&temp); 	
			}	
		}
	}

	
	
address BalikList (address p)
	{
		if(!isEmpty(p)){
			address current, prev, next1;	
			current = p;
			prev = Nil;
			while (current != Nil){
				next1 = next(current);
				next(current) = prev;
				prev = current;
				current = next1;
			}
			p = prev;
			return p;
		}
		else return 0;
	}
void Del_After(address *pBef,infotype *X){
	if(!isEmpty(*pBef)){
		address temp;
		temp = next(*pBef);
		next(*pBef) = Nil;
		next(*pBef) = next(temp);
		next(temp) = Nil;
		DeAlokasi(&temp);	
	}
	
}

//int Search_Kota(dt_kota temp_kota[3],char* value_kota){
//	int i=1;
//	boolean found=false;
//	while(!found){
//		if(temp_kota[i].info == value_kota) found = true;
//		else i++;
//	}
//	if(found) return i;
//	else {
//		i = 0;
//		return i;
//	}
//}
				
//void Sort(address *p)
//{
//    boolean swapped;
//	int i;
//    address ptr1;
//    address lptr = NULL;
//    infotype temp;
// 
//    do{
//        swapped = false;
//        ptr1 = *p;
//
//        while (ptr1->next != lptr){
//        	
//            if (ptr1->info > ptr1->next->info){ 
//            	temp = ptr1->info;
//            	ptr1->info = ptr1->next->info;
//            	ptr1->next->info = temp;
//                swapped = true;
//            }
//            ptr1 = ptr1->next;
//        }
//        lptr = ptr1;
//    }
//    while (swapped);
//}
