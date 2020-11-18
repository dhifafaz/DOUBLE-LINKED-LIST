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
int pangkatres (int a, int b)
{
    if (b==0) return 1;
    else return a * pangkatres(a,b-1);
}

void InsertLast(List *L, infotype x) {
	address NewElmt;
	NewElmt = Allocation(x);

	if (NewElmt != NULL) {
		if (IsEmpty(*L)) {
			(*L).first = NewElmt;
			(*L).last = NewElmt;
		} else {

			NewElmt->prev = (*L).last;
			((*L).last)->next = NewElmt;
			(*L).last = NewElmt;
		}
	}
}

int decimal_value(List *L)
{
    address temp;
    temp =(*L).first;
    int result = 0;

    while (temp!=NULL){
        result = (result <<1)+ temp->info;
        temp = temp->next;
    }
    return result;
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
    List Desimal;
    CreateEmpty (&DataAngka);
    CreateEmpty (&Desimal);
    
    int n=7, bin, hasil;
    
    for(int i=n;i>=0;i--)
    {
        
        cin >> bin;
        InsertLast(&Desimal,bin);
        if (bin == 1 )
        {
            hasil = pangkatres(2,i);
            InsertLast(&DataAngka,hasil);
        }
        else if (bin == 0)
        {
            hasil = pangkatres(2,0);
            InsertLast(&DataAngka,hasil);
        }
        else 
        {
            cout << "ERROR";
            break;
        }
    }
    arrange(&DataAngka);
	address BacaData;
	BacaData = DataAngka.first;
    int pangkat = 7;
	while (pangkat >=0) {
		cout << "2^" << pangkat << " = " << BacaData->info << endl;
		BacaData = BacaData->next;
        pangkat -=2;
	}
    BacaData = DataAngka.last;
    pangkat = 2;
    while (pangkat <=6) {
		cout << "2^" << pangkat << " = " << BacaData->info << endl;
		BacaData = BacaData->prev;
        pangkat +=2;
	}
    int x = decimal_value(&Desimal);
    cout << "Total = "<<x;
	
	
	return 0;
}
