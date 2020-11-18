#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtList* address;
typedef struct TElmtList {
	infotype info;
	address prev;
	address next;
} ElmtList;

struct List {
	address first;
	address last;
};

void CreateEmpty(List* L) {
	(*L).first = NULL;
	(*L).last = NULL;
}

bool IsEmpty(List L) {
	return ((L.first == NULL) && (L.last == NULL));
}

void Deallocation(address hapus) {
	free(hapus);
}

address Allocation(infotype x) {
	address NewElmt;
	NewElmt = (address) malloc (sizeof(ElmtList));

	NewElmt->info = x;
	NewElmt->prev = NULL;
	NewElmt->next = NULL;

	return NewElmt;
}

void InsertFirst(List *L, infotype x) {
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL) {
		if (IsEmpty(*L)) {
			//Kondisi dimana List Kosong
			(*L).first = NewElmt;
			(*L).last = NewElmt;
		} else {
			//Kondisi dimana List tidak kosong
			NewElmt->next = (*L).first;
			((*L).first)->prev = NewElmt;
			(*L).first = NewElmt;
		}
	}
}

void InsertAfter(List *L, address *PredElmt, infotype x) {
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL) {
		if ((*PredElmt != NULL) && (*PredElmt == (*L).last)) {
			//Kondisi dimana PredElmt adalah elemen terakhir
			NewElmt->prev = *PredElmt;
			(*PredElmt)->next = NewElmt;
			(*L).last = NewElmt;
		} else if (*PredElmt != NULL) {
			//Kondisi dimana PredElmt bukan merupakan elemen terakhir
			NewElmt->next = (*PredElmt)->next;
			((*PredElmt)->next)->prev = NewElmt;
			NewElmt->prev = *PredElmt;
			(*PredElmt)->next = NewElmt;
		}
	}
}

void InsertLast(List *L, infotype x) {
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL) {
		if (IsEmpty(*L)) {
			//Kondisi dimana List kosong
			(*L).first = NewElmt;
			(*L).last = NewElmt;
		} else {
			//Kondisi dimana List tidak kosong
			NewElmt->prev = (*L).last;
			((*L).last)->next = NewElmt;
			(*L).last = NewElmt;
		}
	}
}

void DeleteFirst(List *L, infotype *x) {
	address hapus;
	hapus = (*L).first;

	if (!IsEmpty(*L)) {
		if ((*L).first == (*L).last) {
			//Di dalam List tinggal menyisakan satu elemen
			(*L).first = NULL;
			(*L).last = NULL;
		} else {
			//Di dalam List masih terdapat lebih dari satu elemen
			(*L).first = hapus->next;
			hapus->next = NULL;
			((*L).first)->prev = NULL;
		}

		*x = hapus->info;
		Deallocation(hapus);
	}
}

void DeleteAfter(List *L, address pred, infotype *x) {
	if ((pred)->next != NULL) {
		address hapus;
		hapus = (pred)->next;

		if (hapus == (*L).last) {
			(*L).last = pred;
			hapus->prev = NULL;
			(pred)->next = NULL;
		} else {
			(pred)->next = hapus->next;
			(hapus->next)->prev = pred;
			hapus->prev = NULL;
			hapus->next = NULL;
		}

		*x = hapus->info;
		Deallocation(hapus);
	}
}
void DelLast (List *L, infotype *P){
    address hapus;
	hapus = (*L).last;
    if (!IsEmpty(*L)) {
        if ((*L).first == (*L).last) {
			//Di dalam List tinggal menyisakan satu elemen
			(*L).first = NULL;
			(*L).last = NULL;
        } else {
            (*L).last= hapus->prev;
            hapus->prev = NULL;
	        (*L).last->next = NULL;
	        
        }
        *P = hapus->info;
	    Deallocation(hapus);
    }
}

int main() {
	List DataAngka;
	infotype SimpanAngka;

	CreateEmpty(&DataAngka);
	InsertLast(&DataAngka, 20);
	InsertFirst(&DataAngka, 11);
	InsertFirst(&DataAngka, 10);
	InsertFirst(&DataAngka, 8);

	DelLast(&DataAngka,&SimpanAngka);
	cout << "Hapus -> " << SimpanAngka << endl;

	InsertFirst(&DataAngka, 6);

	address Bantu = DataAngka.first;
	InsertAfter(&DataAngka, &Bantu, 7);

	address BacaData;
	BacaData = DataAngka.last;
	while (BacaData != NULL) {
		cout << BacaData->info << endl;
		BacaData = BacaData->prev;
	}

	return 0;
}





