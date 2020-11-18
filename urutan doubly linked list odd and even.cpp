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


address Allocation(infotype x) {
	address NewElmt;
	NewElmt = (address) malloc (sizeof(ElmtList));

	NewElmt->info = x;
	NewElmt->prev = NULL;
	NewElmt->next = NULL;

	return NewElmt;
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
void arrange (List *L)
{
	int count = 0;
	address end =(*L).first;
	while (end->next != NULL)
	{
		end = end->next;
		count +=1;
	}

	count = count&1? (count/2)+1 : count/2;
	address temp =(*L).first;
	while(count!=0)
	{
		(*L).last->next = temp->next;
		(temp->next->next)->prev = temp;
		(temp->next)->prev=(*L).last;
		temp->next = temp->next->next;
		(*L).last = (*L).last->next;
		(*L).last->next=NULL;
		
		temp =temp->next;
		count--;
	}
	


}
int main() {
    List DataAngka;
	infotype SimpanAngka;
    CreateEmpty (&DataAngka);
    
    int n=8;
    
    for(int i=0;i<n;i++)
    {
        int bin;
        cin >> bin;
        InsertLast(&DataAngka, bin);
    }
    arrange(&DataAngka);
	address BacaData;
	BacaData = DataAngka.first;
	while (BacaData != NULL) {
		cout << BacaData->info << endl;
		BacaData = BacaData->next;
	}

	
	
	return 0;
}