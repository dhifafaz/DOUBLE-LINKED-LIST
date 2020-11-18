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

void print_ala_ala (List a, int bts)
{
    float con = 0, sum = 0, con1=0, sum1=0;
    float rata, rata1;
    address baca= a.first;
    while (baca->info != bts)
    {
        baca = baca->next;
        if (baca->info == bts) baca = baca;
    }
    address baca1= baca;
    if (baca==a.first&&baca==a.last) cout << "[] = "<< 0 <<endl;
    else if (baca==a.first)
    {
        cout << "[] = "<< 0 <<endl;
        cout << "[";
        while (baca1!= a.last)
        {
        
            baca1 = baca1->next;
            cout << baca1->info;
            con1++; sum1+=baca1->info;
            if (baca1!= a.last) cout << ",";
        }
        rata1 = sum1 /con1;
        cout << "] = "<<rata1;

    }
    else if (baca==a.last)
    {
        cout << "[";
        while (baca!= a.first)
        {
            baca = baca->prev;
            cout << baca->info;
            con++; sum += baca->info;
            if (baca!= a.first) cout << ",";
        }
        rata = sum / con;
        cout << "] = "<< rata<<endl;
        cout << "[] = "<< 0 ;
    }
    else{ 
        //cout << baca->info << endl;
        cout << "[";
        while (baca!= a.first)
        {
            baca = baca->prev;
            cout << baca->info;
            con++; sum += baca->info;
            if (baca!= a.first) cout << ",";
        }
        rata = sum / con;
        cout << "] = "<< rata<<endl;
        cout << "[";
        while (baca1!= a.last)
        {
        
            baca1 = baca1->next;
            cout << baca1->info;
            con1++; sum1+=baca1->info;
            if (baca1!= a.last) cout << ",";
        }
        rata1 = sum1 /con1;
        cout << "] = "<<rata1;
    }
}
int main()
{
    List a;
    CreateEmpty(&a);
    int i, n,m,bts;
    cin >> n ;
    for (i=0; i<n; i++)
    {
        cin >> m;
        if (i%2==0) InsertFirst(&a,m);
        else InsertLast(&a,m);
    }   
    cin >> bts;
    print_ala_ala(a,bts);
    return 0;
    
}