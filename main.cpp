#include <iostream>
#include <conio.h>
#include "UKM.h"

using namespace std;

int main()
{
    List_u LU;
    List_m LM;
    address_m p;
    address_u q;
    string  x,y;
    char pilih, pil;
    address_m cariMHS;
    address_u cariUKM;
    createListUKM(LU);
    createListMahasiswa(LM);

    while(pilih != '5')
    {
        clrscr();
        cout<<" ============================================================="<<endl;
        cout<<"|              SISTEM INFORMASI PENDAFTARAN UKM               |"<<endl;
        cout<<" ============================================================="<<endl;
        cout<<"|                 SELAMAT DATANG DI Si-UKM                    |"<<endl;
        cout<<" ============================================================="<<endl;
        cout<<"|                            MENU                             |"<<endl;
        cout<<"|                                                             |"<<endl;
        cout<<"|                   1. ADD                                    |"<<endl;
        cout<<"|                   2. DELETE                                 |"<<endl;
        cout<<"|                   3. SEARCH                                 |"<<endl;
        cout<<"|                   4. VIEW DATA                              |"<<endl;
        cout<<"|                   5. EXIT                                   |"<<endl;
        cout<<" ============================================================="<<endl;
        cout<<endl;
        cout<<" MASUKKAN PILIHAN ANDA : ";
        cin>>pilih;
        switch(pilih){
        case '1':
              do
              {
                clrscr();
                cout<<" ============================================================="<<endl;
                cout<<"|                 SELAMAT DATANG DI Si-UKM                    |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<"|                            MENU                             |"<<endl;
                cout<<"|                          Tambahkan                          |"<<endl;
                cout<<"|                                                             |"<<endl;
                cout<<"|                   1. Data Mahasiswa                         |"<<endl;
                cout<<"|                   2. UKM                                    |"<<endl;
                cout<<"|                   3. Mahasiswa & UKM                        |"<<endl;
                cout<<"|                   0. EXIT                                   |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<endl;
                cout<<" MASUKKAN PILIHAN ANDA : ";
                cin>>pil;
                switch(pil)
                {
                    case '1':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        cout<<"Nama Mahasiswa : ";
                        cin>>x;
                        cout<<"NIM            : ";
                        cin>>y;
                        p = allocateMahasiswa(x,y);
                        if((x != "Kosong" && x!= "kosong" && x!="KOSONG")||(y!="Kosong" && y != "kosong" && y != "KOSONG")){
                            insertFirstM(LM,p);
                            cout<<endl<<"Data berhasil ditambahkan";
                            getch();
                            break;
                        }
                        else
                        {
                            cout<<"Lengkapi data Anda terlebih dahulu!";
                            getch();
                            break;
                        }
                    case '2':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        cout<<"Nama UKM : ";
                        cin>>x;
                        q = allocateUKM(x);
                        if(x != "kosong" && x!= "KOSONG" && x!="Kosong" ){
                            insertFirstU(LU,q);
                            cout<<endl<<"Data berhasil ditambahkan";
                            getch();
                            break;
                        }
                        else
                        {
                            cout<<"Lengkapi data Anda terlebih dahulu!";
                            getch();
                            break;
                        }
                    case '3':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        cout<<"NIM            : ";
                        cin>>y;
                        cout<<"UKM            : ";
                        cin>>x;
                        addUKM(LM,LU,x,y);
                        cout<<"Selamat Anda sudah terdaftar";
                        getch();
                        break;

                }
              }
        while(pil != '0');
        break;
        case '2' :
              do
              {
                clrscr();
                cout<<" ============================================================="<<endl;
                cout<<"|                 SELAMAT DATANG DI Si-UKM                    |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<"|                            MENU                             |"<<endl;
                cout<<"|                                                             |"<<endl;
                cout<<"|                   1. Mahasiswa                              |"<<endl;
                cout<<"|                   2. UKM                                    |"<<endl;
                cout<<"|                   0. EXIT                                   |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<endl;
                cout<<" MASUKKAN PILIHAN ANDA : ";
                cin>>pil;
                switch(pil)
                {
                    case '1':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        cout<<"Masukkan NIM            : ";
                        cin>>x;
                        deleteMahasiswa(LM,y);
                        getch();
                        break;
                    case '2':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        cout<<"Masukkan UKM : ";
                        cin>>x;
                        deleteUKM(LM,LU,x);
                        getch();
                        break;
                }
              }
        while(pil != '0');
        break;
        case '3':
              do
              {
                clrscr();
                cout<<" ============================================================="<<endl;
                cout<<"|                 SELAMAT DATANG DI Si-UKM                    |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<"|                            MENU                             |"<<endl;
                cout<<"|                                                             |"<<endl;
                cout<<"|                   1. Search Mahasiswa                       |"<<endl;
                cout<<"|                   2. Search UKM                             |"<<endl;
                cout<<"|                   0. EXIT                                   |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<endl;
                cout<<" MASUKKAN PILIHAN ANDA : ";
                cin>>pil;
                switch(pil)
                {
                    case '1':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        cout<<"Masukkan NIM            : ";
                        cin>>x;
                        cariMHS = searchMahasiswa(LM,x);
                        cout<<" "<<endl;
                        cout<<"Nama Mahasiswa : "<<info(cariMHS).nama<<endl;
                        cout<<"NIM Mahasiswa : "<<info(cariMHS).NIM<<endl;
                        getch();
                        break;
                    case '2':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        cout<<"Masukkan UKM : ";
                        cin>>(x);
                        cariUKM = searchUKM(LU,x);
                        cout<<" "<<endl;
                        cout<<"Nama UKM : "<<info(cariUKM).nama<<endl;
                        cout<<"Nama Kategori UKM : "<<info(cariUKM).NIM<<endl;
                        getch();
                        break;
                 }
               }
        while(pil != '0');
        break;
        case '4':
              do
              {
                clrscr();
                cout<<" ============================================================="<<endl;
                cout<<"|                 SELAMAT DATANG DI Si-UKM                    |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<"|                            MENU                             |"<<endl;
                cout<<"|                                                             |"<<endl;
                cout<<"|                   1. View Data Mahasiswa                    |"<<endl;
                cout<<"|                   2. View UKM                               |"<<endl;
                cout<<"|                   3. View Mahasiswa X UKM                   |"<<endl;
                cout<<"|                   0. EXIT                                   |"<<endl;
                cout<<" ============================================================="<<endl;
                cout<<endl;
                cout<<" MASUKKAN PILIHAN ANDA : ";
                cin>>pil;
                switch(pil)
                {
                    case '1':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        printinfoM(LM);
                        getch();
                        break;
                    case '2':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        printInfoU(LU);
                        getch();
                        break;
                    case '3':
                        clrscr();
                        cout<<" ============================================================="<<endl;
                        cout<<"|                 YUK DAFTAR Si-UKM!!                         |"<<endl;
                        cout<<" ============================================================="<<endl;
                        cout<<endl;
                        printinfoAll(LM);
                        getch();
                        break;
                 }
               }
         while(pil != '0');
         break;
        }
    }


    cout<<endl;
    cout<<endl;
    cout<<"            TERIMAKASIH TELAH MENGUNJUNGI Si-UKM               "<<endl;
    cout<<"               SOLUSI MUDAH PENDAFTARAN UKM                    "<<endl;
    return 0;
}
