/**
* @file Simulasyon
* @description olaylarin gerceklestirildigi sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "Simulasyon.h"
#include "UzayAraci.h"
#include <stdio.h>
#include <stdlib.h>


Simulasyon simulasyonOlustur(Kisi* kisiDizisi, UzayAraci* uzayAraciDizisi, Gezegen* gezegeDizisi, int kisiSayisi, int uzayAraciSayisi, int gezegenSayisi)
{

    Simulasyon this;
    this = (Simulasyon)malloc(sizeof(struct SIMULASYON));
    this->kisiDizisi = kisiDizisi;
    this->uzayAraciDizisi = uzayAraciDizisi;
    this->gezegenDizisi = gezegeDizisi;
    this->kisiSayisi = kisiSayisi;
    this->uzayAraciSayisi = uzayAraciSayisi;
    this->gezegenSayisi = gezegenSayisi;
    this->baslat = &baslat;
    this->simulasyonYoket = &simulasyonYoket;
    int imhaSayisi=0;
   
    return this;
}
void baslat(struct SIMULASYON* this)
{
    KayacGezegen kayac = kayacOlustur(NULL, 0, 0, NULL);
    GazDeviGezegen gazDevi = gazDeviOlustur(NULL, 0, 0, NULL);
    BuzDeviGezegen buzDevi = buzDeviOlustur(NULL, 0, 0, NULL);
    CuceGezegen cuce = cuceOlustur(NULL, 0, 0, NULL);

    char* varisTarihi;


    for (int j = 0; j < this->uzayAraciSayisi; j++)
    {

        for (int i = 0; i < this->gezegenSayisi; i++)
        {

            if(strcmp(this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]),this->uzayAraciDizisi[j]->varisGezegeni->getIsim(this->uzayAraciDizisi[j]->varisGezegeni))==0)
            {  
                this->uzayAraciDizisi[j]->setVarisGezegeni(this->uzayAraciDizisi[j], this->gezegenDizisi[i]);
    
            }
            if(strcmp(this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]),this->uzayAraciDizisi[j]->cikisGezegeni->getIsim(this->uzayAraciDizisi[j]->cikisGezegeni))==0)
            {
                this->uzayAraciDizisi[j]->setCikisGezegeni(this->uzayAraciDizisi[j], this->gezegenDizisi[i]);
            }
        
        }
        
        varisTarihi = this->uzayAraciDizisi[j]->varisTarihiHesapla(this->uzayAraciDizisi[j]);
        this->uzayAraciDizisi[j]->varisTarihi=varisTarihi;
    printf("YENIIII%-21s",varisTarihi);

        this->uzayAraciDizisi[j]->setKalanSaat(this->uzayAraciDizisi[j], this->uzayAraciDizisi[j]->getKalanSaat(this->uzayAraciDizisi[j])-1);

    }

    while(1)
    {
        for (int i = 0; i < this->uzayAraciSayisi; i++)
        {

        }
        
        for (int i = 0; i < this->gezegenSayisi; i++)
        {
            for (int j = 0; j < this->uzayAraciSayisi; j++)
            {
                int simdikiNufus=0;
                if(strcmp(this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]),this->uzayAraciDizisi[j]->cikisGezegeni->isim)==0)
                {
                    

                    if(strcmp(this->uzayAraciDizisi[j]->durumuDondur(this->uzayAraciDizisi[j]), "Bekliyor")==0)
                    {   

                        int aracKisiSayisi=this->uzayAraciDizisi[j]->kisiSayisiDondur(this->uzayAraciDizisi[j]);
                        simdikiNufus += aracKisiSayisi;

                        this->gezegenDizisi[i]->setNufus(this->gezegenDizisi[i], simdikiNufus + aracKisiSayisi);
                    }

                }
                if(strcmp(this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]),this->uzayAraciDizisi[j]->varisGezegeni->isim)==0) 
                {

                    if(strcmp(this->uzayAraciDizisi[j]->durumuDondur(this->uzayAraciDizisi[j]), "Vardi")==0)
                    {   
                        int aracKisiSayisi=this->uzayAraciDizisi[j]->kisiSayisiDondur(this->uzayAraciDizisi[j]);
                        simdikiNufus += aracKisiSayisi;
                        this->gezegenDizisi[i]->setNufus(this->gezegenDizisi[i], simdikiNufus + aracKisiSayisi);
                        
                    }
                }
            }
        }

        printf("Gezegenler:\n                    ");
        for (int i = 0; i < this->gezegenSayisi; i++)
        {
            printf("    --- %s ---    ", this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]));
        }
        printf("\n%13s","Tarih           ");
        for (int i = 0; i < this->gezegenSayisi; i++)
        {
            printf("%17s", this->gezegenDizisi[i]->getTarih(this->gezegenDizisi[i]));
        }
        printf("\n%-24s","Nufus        ");
        for (int i = 0; i < this->gezegenSayisi; i++)
        {
            printf("%-17d", this->gezegenDizisi[i]->getNufus(this->gezegenDizisi[i]));
        }

        printf("\n\n\n");
        printf("Uzay Araclari:\n");
        printf("Arac Adi                 Durum           Cikis            Varis            Hedefe Kalan Saat         Hedefe Varacagi Tarih\n");

        for (int i = 0; i < this->uzayAraciSayisi; i++)
        {

            printf("%-25s",this->uzayAraciDizisi[i]->getAdi(this->uzayAraciDizisi[i]));
            printf("%-16s", this->uzayAraciDizisi[i]->durumuDondur(this->uzayAraciDizisi[i]));
            printf("%-17s", this->uzayAraciDizisi[i]->getCikisGezegeni(this->uzayAraciDizisi[i])->getIsim(this->uzayAraciDizisi[i]->getCikisGezegeni(this->uzayAraciDizisi[i])));
            printf("%-17s", this->uzayAraciDizisi[i]->getVarisGezegeni(this->uzayAraciDizisi[i])->getIsim(this->uzayAraciDizisi[i]->getVarisGezegeni(this->uzayAraciDizisi[i])));
            if(strcmp(this->uzayAraciDizisi[i]->durumuDondur(this->uzayAraciDizisi[i]),"IMHA")==0)
            {
                char* imha="--";
                printf("%-26s", imha);
                printf("%-21s", imha);

            }
            else
            {
                printf("%-26d", this->uzayAraciDizisi[i]->getKalanSaat(this->uzayAraciDizisi[i]));
                printf("%-21s", this->uzayAraciDizisi[i]->getVarisTarihi(this->uzayAraciDizisi[i]));
            }
            printf("\n");


        }
        int sartSayisi=0;
        for (int i = 0; i < this->uzayAraciSayisi; i++)
        {
            
            if(strcmp(this->uzayAraciDizisi[i]->durumuDondur(this->uzayAraciDizisi[i]),"IMHA")==0)
            {
                sartSayisi++;
            }
            else if(this->uzayAraciDizisi[i]->kalanSaat==0)
            {
                sartSayisi++;
            }
            if(sartSayisi==this->uzayAraciSayisi){
                printf("Program tamamlanmistir.");
                exit(0);
            }
            
            this->uzayAraciDizisi[i]->zamaniIlerletArac(this->uzayAraciDizisi[i]);
            
            

        }
        for (int i = 0; i < this->gezegenSayisi; i++)
        {

            this->gezegenDizisi[i]->zamaniIlerlet(this->gezegenDizisi[i]);

            for (int j = 0; j < this->kisiSayisi; j++)
            {
        
                switch (this->gezegenDizisi[i]->gezegenTuru)
                {
                case 0:
                { 
                    kayac->superGezegen->isim=this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]);
                    kayac->superGezegen->yolcuOmurHesapla(this->gezegenDizisi[i],this->kisiDizisi[j]);

                    break;
                }
                case 1:
                {
                    gazDevi->superGezegen->isim=this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]);
                    gazDevi->superGezegen->yolcuOmurHesapla(this->gezegenDizisi[i],this->kisiDizisi[j]);
                    break;
                }
                case 2:
                {
                    buzDevi->superGezegen->isim=this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]);
                    buzDevi->superGezegen->yolcuOmurHesapla(this->gezegenDizisi[i],this->kisiDizisi[j]);

                    break;
                }
                case 3:
                {
                    cuce->superGezegen->isim=this->gezegenDizisi[i]->getIsim(this->gezegenDizisi[i]);
                    cuce->superGezegen->yolcuOmurHesapla(this->gezegenDizisi[i],this->kisiDizisi[j]);
                    

                    break;
                }    
                default:
                    printf("Geçersiz tur.\n");
                    break;
            }
               
                
                //this->gezegenDizisi[i]->super->zamanArttir(this->gezegenDizisi[i]->super);

            }
            
           

        }
        for (int i = 0; i < this->kisiSayisi; i++)
        {
            this->kisiDizisi[i]->kalanOmuruAzalt(this->kisiDizisi[i]);
        }
        
        system("cls");
        //system("pause");        
    }
    
    
}
void simulasyonYoket(struct SIMULASYON* this)
{
    if (this == NULL) return;

    free(this);
    
}