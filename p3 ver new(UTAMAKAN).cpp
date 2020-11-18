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
	address curr;
};

void CreateEmpty(List* L) 
{
	(*L).first = NULL;
	(*L).last = NULL;
}

bool IsEmpty(List L) 
{
	return ((L.first == NULL) && (L.last == NULL));
}

address Allocation(infotype x) 
{
	address NewElmt;
	NewElmt = (address) malloc (sizeof(ElmtList));
	NewElmt->info = x;
	NewElmt->prev = NULL;
	NewElmt->next = NULL;
	return NewElmt;
}
void InsertLast(List *L, infotype x) 
{
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
    List Desimal;
    List simpen ;
    List DataAngka;
    CreateEmpty(&DataAngka);
    CreateEmpty (&Desimal);
    CreateEmpty (&simpen);
    int n=7, bin, hasil;
    int arr[8] = {128,64,32,16,8,4,2,1};
    
    for (int i=0; i<n+1; i++)
    {
        InsertLast(&DataAngka, arr[i]);
    }

    address B;
	B = DataAngka.first;
    
	while (B!= NULL&&n>=0)
    { 
        cin >> bin;
        InsertLast(&Desimal,bin);
        int x = B->info;
        if (bin == 1 )
        {
            hasil = x*1;
            InsertLast(&simpen,hasil);
        }
        else if (bin == 0)
        {
            hasil = x*0;
            InsertLast(&simpen,hasil);
        }
        
        B= B->next;
        n--;
    }

    //arrange(&DataAngka);
    arrange(&simpen);

	address BacaData;
	BacaData = simpen.first;
	int pangkat = 7;
	
	while (pangkat >-1) 
	{
		cout << "2^" << pangkat << " = " << BacaData->info << endl;
        pangkat -=2;
		BacaData = BacaData->next;  
	}

    BacaData = simpen.last;
    pangkat = 0;
    
	while (pangkat <=6) 
	{
		cout << "2^" << pangkat << " = " << BacaData->info << endl;
		BacaData = BacaData->prev;
        pangkat +=2;
	}
	
    int x = decimal_value(&Desimal);
    cout << "Total = "<<x;	
	return 0;
}
