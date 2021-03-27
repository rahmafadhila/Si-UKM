#ifndef UKM_H_INCLUDED
#define UKM_H_INCLUDED
#define info(p) p->info
#define next(p) p->next
#define next_ukm(p) p->next_ukm
#define prev(p) p->prev
#define first(L) (L).first
#define last(L) (L).last
#define relasifirst(p) (p->LR).first
#define relasilast(p) (p->LR).last

using namespace std;

struct infotype
{
    string nama;
    string NIM;
};
typedef struct elmlist_u *address_u;
typedef struct elmlist_m *address_m;
typedef struct elmlist_r *address_r;


struct List_r               //LIST RELASI
{
    address_r first;
    address_r last;
};

struct elmlist_r            //ELEMEN RELASI
{
    address_u next_ukm;
    address_r next;
    address_r prev;
};

struct elmlist_u            //ELEMEN UKM
{
    infotype info;
    address_u next;
    address_u prev;
};

struct List_u               //LIST UKM
{
    address_u first;
    address_u last;
};

struct elmlist_m            //ELEMEN MAHASISWA
{
    infotype info;
    address_m next;
    address_m prev;
    List_r LR;
};

struct List_m               //LIST MAHASISWA
{
    address_m first;
    address_m last;
};

void clrscr();
void createListUKM(List_u &LU);
void createListMahasiswa(List_m &LM);
address_u allocateUKM(string nama);
address_m allocateMahasiswa(string nama, string NIM);
address_r allocateRelasi(address_u &p);
void printInfoU(List_u &LU);
void printinfoAll(List_m &LM);
bool cekUKM(List_u &LU,address_u &p);
bool cekMahasiswa(List_m &LM,address_m &p);
bool cekRelasi(List_m &LM, List_u &LU,address_m &p, address_r &r);
void insertFirstM(List_m &LM,address_m &p);
void insertFirstU(List_u &LU,address_u &p);
address_m searchMahasiswa(List_m &LM, string x);
address_u searchUKM(List_u &LU, string x);
void addUKM(List_m &LM, List_u &LU, string x, string y);
void deleteUKM(List_m &LM,List_u &LU,string x);
void deleteRelasi(List_m &LM,address_m &q, address_r &z);
void deleteUKMSub(List_u &LU, address_u &p);
void deleteMahasiswa(List_m &LM, string x);
void printinfoM(List_m &LM);


#endif // UKM_H_INCLUDED
