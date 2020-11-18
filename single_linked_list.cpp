#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;

typedef struct TElementList * address;
typedef struct TElementList {
	infotype info;
	address next;
} ElmtList;

struct List {
	address first;
};

void CreateEmpty(List *L) {
	(*L).first = NULL;
}

bool IsEmpty(List L) {
	return (L.first == NULL);
}

address Allocation(infotype x) {
	address NewElmt;
	NewElmt = (address) malloc(sizeof(ElmtList));

	NewElmt->next = NULL;
	NewElmt->info = x;
	return NewElmt;	
}

void InsertFirst(List *L, infotype x) {
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL) {
		NewElmt->next = (*L).first;
		(*L).first = NewElmt;
	}
}

void InsertAfter(address *predElmt, infotype x) {
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL) {
		NewElmt->next = (*predElmt)->next;
		(*predElmt)->next = NewElmt;
	}
}

void InsertLast(List *L, infotype x) {
	if (IsEmpty(*L)) {
		InsertFirst(&(*L), x);
	} else {
		address predElmt;
		predElmt = (*L).first;
		while (predElmt->next != NULL) {
			predElmt = predElmt->next;
		}
		InsertAfter(&predElmt, x);
	}
}

int main() {
	List DataAngka;

	CreateEmpty(&DataAngka);
	InsertFirst(&DataAngka, 12);
	InsertFirst(&DataAngka, 10);
	InsertFirst(&DataAngka, 8);
	InsertFirst(&DataAngka, 6);
	
	InsertAfter(&(((DataAngka.first)->next)->next), 11);
	InsertLast(&DataAngka, 20);

	address CekData;
	CekData = DataAngka.first;
	while (CekData != NULL) {
		cout << CekData->info << endl;
		CekData = CekData->next;
	}

	return 0;
}