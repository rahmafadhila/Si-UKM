#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "UKM.h"

void clrscr()
{
    system("cls");
}

void createListUKM(List_u &LU)
{
    first(LU)=NULL;
    last(LU) = NULL;
}

void createListMahasiswa(List_m &LM)
{
    first(LM)= NULL;
    last(LM) = NULL;
}

address_u allocateUKM(string nama)
{
    address_u p = new elmlist_u;
    info(p).nama = nama;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
}

address_m allocateMahasiswa(string nama, string NIM)
{
    address_m p = new elmlist_m;
    info(p).nama = nama;
    info(p).NIM = NIM;
    next(p) = NULL;
    prev(p) = NULL;
    relasifirst(p) = NULL;
    relasilast(p) = NULL;

    return p;
}

address_r allocateRelasi(address_u &p)
{
    address_r q = new elmlist_r;
    next_ukm(q) = p;
    next(q) = NULL;
    prev(q) = NULL;

    return q;
}

void printInfoU(List_u &LU)
{
    if (first(LU) != NULL)
    {
        cout<<"======================"<<endl;
        cout<<"       List UKM"<<endl;
        cout<<"======================"<<endl;
        int i = 1;
        address_u p = first(LU);
        while(p != NULL)
        {
            cout<<i<<"  Nama UKM : "<<info(p).nama<<endl;
            i++;
            p = next(p);
        }
    }
    else
    {
        cout<<"List UKM Kosong"<<endl;
    }
}

void printinfoAll(List_m &LM)
{
    if (first(LM) != NULL)
    {
        address_m p = first(LM);
        cout<<"List Mahasiwa"<<endl<<"======================"<<endl<<endl;
        while (p != NULL)
        {
            cout<<"Nama Mahasiswa = "<<info(p).nama<<endl;
            cout<<"NIM            = "<<info(p).NIM<<endl<<endl;
            if (relasifirst(p) != NULL)
            {
                address_r q = relasifirst(p);
                int z = 1;
                cout<<"List UKM "<<info(p).nama<<endl;
                cout<<"======================"<<endl;
                while (q != NULL)
                {
                    cout<<z<<". "<<info(next_ukm(q)).nama<<endl;
                    q = next(q);
                    z++;
                }
                cout<<"======================"<<endl;
                cout<<"======================"<<endl<<endl;
            }
            else
            {
                cout<<"LIST UKM KOSONG"<<endl;
                cout<<"======================"<<endl;
                cout<<"======================"<<endl<<endl;
            }
            p = next(p);
        }
    }
    else
    {
        cout<<"LIST MAHASISWA KOSONG"<<endl;
    }
}


bool cekUKM(List_u &LU,address_u &p)
{
    bool cek = false;
    address_u q = first(LU);
    while(q != NULL)
    {
        if(info(p).nama == info(q).nama)
        {
            cek = true;
            return cek;
        }
        q = next(q);
    }
    return cek;
}

bool cekMahasiswa(List_m &LM,address_m &p)
{
    bool cek = false;
    address_m q = first(LM);
    while(q != NULL)
    {
        if((info(p).NIM) != (info(q).NIM))
        {
            cek = true;
            return cek;
        }
        q = next(q);
    }
    return cek;
}

bool cekRelasi(List_m &LM, List_u &LU,address_m &p, address_r &r)
{
    bool cek = false;
    address_r z = relasifirst(p);
    while(z != NULL)
    {
        if((next_ukm(z)) == (next_ukm(r)))
        {
            cek = true;
            return cek;
        }
        z = next(z);
    }
    return cek;
}

void insertFirstM(List_m &LM,address_m &p)
{
    bool cek = cekMahasiswa(LM,p);
    if(first(LM) !=NULL)
    {
        if(cek == true)
        {
            next(p) = first(LM);
            prev(first(LM)) = p;
            first(LM) = p;
        }
        else
        {
            cout<<"NIM Tersebut Telah Terdaftar"<<endl;
        }
    }
    else
    {
        first(LM) = p;
        last(LM) = p;
    }
}

void insertFirstU(List_u &LU,address_u &p)
{
    bool cek = cekUKM(LU,p);
    if(first(LU) != NULL)
    {
        if (cek == true)
        {
            cout<<"UKM Tersebut Telah Terdaftar"<<endl;
        }
        else
        {
            next(p) = first(LU);
            prev(first(LU)) = p;
            first(LU) = p;
        }
    }
    else
    {
        first(LU) = p;
        last(LU) = p;
    }
}

address_u searchUKM(List_u &LU, string x)
{
   if (first(LU)!= NULL)
    {
        address_u p = first(LU);
        address_u q = first(LU);
        while ((p != NULL))
        {
            if(info(p).nama == x)
            {
                return p;
                cout<<x<<endl;
            }
            p = next(p);
        }
    }
    else
    {
        return NULL;
        cout<<"UKM Tidak Ditemukan"<<endl;
    }
}

address_m searchMahasiswa(List_m &LM, string x)
{
    if((first(LM)) != (NULL))
    {
        address_m p = first(LM);
        while (p!=NULL)
        {
            if(info(p).NIM==x)
            {
                return p;
                cout<<x<<endl;
            }
            p =  next(p);
        }
    }
    else
    {
        return NULL;
        cout<<"Mahasiswa Tidak Ditemukan"<<endl;
    }
}

void addUKM(List_m &LM, List_u &LU, string x, string y)
{
    address_u p = searchUKM(LU,x);
    address_m q = searchMahasiswa(LM,y);
    bool cek = false;
    if ((p!= NULL) && (q!= NULL))
    {
        address_r z = allocateRelasi(p);
        cek = cekRelasi(LM,LU,q,z);
        if(cek == false)
        {
            if (relasifirst(q)!=NULL)
            {
                next(z) = relasifirst(q);
                prev(relasifirst(q)) = z;
                relasifirst(q) = z;
            }
            else
            {
                relasifirst(q) = z;
                relasilast(q) = z;
            }
            cout<<"UKM Berhasil Terdaftar"<<endl;
        }
        else if(cek == true)
        {
            cout<<"Mahasiswa telah terdaftar di UKM tersebut "<<endl;
        }
    }
    else if(p == NULL)
    {
        cout<<"UKM Tidak Ditemukan"<<endl;
    }
    else if(q == NULL)
    {
        cout<<"Mahasiswa Tidak Ditemukan"<<endl;
    }
}


void deleteRelasi(List_m &LM,address_m &p, address_r &z)
{
    if(next(z)==NULL && prev(z)== NULL)
    {
        relasifirst(p)=NULL;
        relasilast(p)=NULL;
        delete z;
    }
    else if(prev(z)== NULL && next(z)!= NULL)
    {
        relasifirst(p) = next(relasifirst(p));
        next(z) = NULL;
        prev(relasifirst(p)) = NULL;
        delete z;
    }
    else if(next(z)== NULL && prev(z)!= NULL)
    {
        relasilast(p) = prev(relasilast(p));
        prev(z) = NULL;
        next(relasilast(p)) = NULL;
        delete z;
    }
    else if(next(z)!= NULL && prev(z)!=NULL)
    {
        prev(next(z)) = prev(z);
        next(prev(z)) = next(z);
        next(z) = NULL;
        prev(z) = NULL;
        delete z;
    }
}

void deleteUKMSub(List_u &LU, address_u &p)
{
    if((next(p) == NULL) && (prev(p)==NULL))
    {
        first(LU) = NULL;
        last(LU) = NULL;
        delete p;
    }
    else if(prev(p) == NULL)
    {
        first(LU) = next(first(LU));
        prev(first(LU)) = NULL;
        next(p) = NULL;
        delete p;
    }
    else if(next(p) == NULL)
    {
        last(LU) = prev(p);
        next(last(LU)) = NULL;
        prev(p) = NULL;
        delete p;
    }
    else
    {
        prev(next(p)) = prev(p);
        next(prev(p)) = next(p);
        next(p) = NULL;
        prev(p) = NULL;
        delete p;
    }

}

void deleteUKM(List_m &LM,List_u &LU,string x)
{
    if (first(LM)!=NULL && first(LU)!=NULL)            //Kondisi Jika List Mahasiswa dan List UKM Ada
    {
        address_m p = first(LM);
        address_u q = searchUKM(LU,x);
        address_r r;
        if (q!=NULL)
        {
            while (p!= NULL)
            {
                r = relasifirst(p);
                while (r!=NULL)
                {
                    if(next_ukm(r) == q)
                    {
                        deleteRelasi(LM,p,r);
                        r = NULL;
                    }
                    else if(next_ukm(r) != q)
                    {
                        r = next(r);
                    }
                }
                p = next(p);
            }
            deleteUKMSub(LU,q);
            cout<<"Berhasil dihapus!";
        }
        else
        {
            cout<<"UKM Tidak Ditemukan"<<endl;
        }
    }
    else if((first(LM) == NULL) && (first(LU) != NULL))      //Kondisi Jika List Mahasiswa Kosong dan List UKM Ada
    {
        address_u q = searchUKM(LU,x);
        if(q != NULL)
        {
            deleteUKMSub(LU,q);
            cout<<"Berhasil dihapus!";
        }
        else
        {
            cout<<"UKM Tidak Ditemukan"<<endl;
        }
    }
    else                                                //Kondisi Jika List Mahasiswa dan List UKM Kosong
    {
        cout<<"List Kosong"<<endl;
    }
}

void printinfoM(List_m &LM)
{
    if (first(LM) != NULL)
    {
        cout<<"======================"<<endl;
        cout<<"     List Mahasiswa"<<endl;
        cout<<"======================"<<endl;
        int i = 1;
        address_m bismilah = first(LM);
        while(bismilah != NULL)
        {
            cout<<i<<" Nama Mahasiswa : "<<info(bismilah).nama<<endl;
            cout<<"  NIM Mahasiswa : "<<info(bismilah).NIM<<endl;
            i++;
            bismilah = next(bismilah);
        }
    }
    else
    {
        cout<<"List Mahasiswa Kosong"<<endl;
    }
}

void deleteMahasiswa(List_m &LM, string x)
{
    address_r r;
    if(first(LM)!= NULL)
    {
        address_m p = searchMahasiswa(LM,x);
        address_r r;
        if(p!= NULL)
        {
            r = relasifirst(p);
            while(r!=NULL)
            {
                deleteRelasi(LM,p,r);
                r = relasifirst(p);
            }
            if (next(p)== NULL && prev(p)== NULL)
            {
                first(LM)= NULL;
                last(LM)=NULL;
                delete p;
                cout<<"Berhasil dihapus !";
            }
            else if(prev(p)== NULL && next(p)!= NULL)
            {
                first(LM) = next(p);
                next(p) = NULL;
                prev(first(LM)) = NULL;
                delete p;
                cout<<"Berhasil dihapus !";
            }
            else if(next(p)== NULL && prev(p)!=NULL)
            {
                last(LM) = prev(p);
                next(last(LM)) = NULL;
                prev(p) = NULL;
                delete p;
                cout<<"Berhasil dihapus !";
            }
            else if(next(p)!= NULL && prev(p)!=NULL)
            {
                prev(next(p)) = prev(p);
                next(prev(p)) = next(p);
                next(p) = NULL;
                prev(p) = NULL;
                delete p;
                cout<<"Berhasil dihapus !";
            }
        }
        else
        {
            cout<<"Mahasiswa tidak terdaftar"<<endl;
        }
    }
    else
    {
        cout<<"List kosong "<<endl;
    }
}
