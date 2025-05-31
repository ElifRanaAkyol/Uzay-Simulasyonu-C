/**
* @file DosyaOkuma
* @description tum txtleri okuyan sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DosyaOkuma.h"
#include "Kisi.h"
#include "Gezegen.h"


typedef enum{
    KAYAC = 0,
    GAZDEVI,
    BUZDEVI,
    CUCE
} GezegenTuru;

typedef struct {
    Gezegen* dizi;
    int boyut;
} GezegenListesi;

DosyaOkuma dosyaOkumaOlustur()
{
    DosyaOkuma this;
    this = (DosyaOkuma)malloc(sizeof(struct DOSYAOKUMA));
    this->kisiDizisi=NULL;
    this->kisiSayisi=0;
    this->uzayAraciDizisi=NULL;
    this->uzayAraciSayisi=0;
    this->gezegenDizisi=NULL;
    this->gezegenSayisi=0;
    this->kisiDosyaOkuma = &kisiDosyaOkuma;
    this->gezegenDosyaOkuma = &gezegenDosyaOkuma;
    this->uzayAraciDosyaOkuma = &uzayAraciDosyaOkuma;
    this->dosyaOkumaYokEt = & dosyaOkumaYokEt;
   

    return this;
}
Kisi* kisiDosyaOkuma(DosyaOkuma this , char* fileName)
{
    int maxKapasite=100;
    
    FILE* dosya = fopen(fileName,"r");
    if (!dosya) {
        perror("Dosya acilamadi");
        return NULL;
    }

    char satir[256];
    int sayac=0;
    this->kisiDizisi = (Kisi*)malloc(sizeof(Kisi) * 100);

    if (!this->kisiDizisi) {
        perror("Bellek ayrilamadi");
        fclose(dosya);
        return NULL;
    }

    while (fgets(satir, sizeof(satir), dosya)) {
        this->kisiSayisi++;
        if (sayac >= maxKapasite) {
            maxKapasite*= 2;
            this->kisiDizisi = (Kisi*)realloc(this->kisiDizisi, sizeof(Kisi) * (maxKapasite+1));
            if (!this->kisiDizisi) {
                perror("Yeniden bellek ayrilamadi");
                fclose(dosya);
                return NULL;
            }
        }

        char satirKopya[256];
        strcpy(satirKopya, satir);
        char* token = strtok(satir, "#");
        if (!token) continue;

        char* isim = strdup(token); // strdup bellekte yeni kopya oluşturur


        token = strtok(NULL, "#");
        int yas =atoi(token);

        token = strtok(NULL, "#");
        int kalanOmur = atoi(token);;

        token = strtok(NULL, "#\n");
        char* uzayAraciStr = strdup(token); // strdup bellekte yeni kopya oluşturur

        UzayAraci uzayAraci;
        Kisi yeniKisi= kisiOlustur(isim, yas, kalanOmur, uzayAraci);
        yeniKisi->aracAdi=uzayAraciStr;

        this->kisiDizisi[sayac++] = yeniKisi;
    }

    fclose(dosya);
    return this->kisiDizisi;
}


Gezegen* gezegenDosyaOkuma(const DosyaOkuma this, char* fileName)
{
    int maxKapasite=100;
    FILE* dosya = fopen(fileName,"r");
    if (!dosya) {
        perror("Dosya acilamadi");
        return NULL;
    }

    char satir[256];
    int sayac=0;
    this->gezegenDizisi = (Gezegen*)malloc(sizeof(Gezegen) * (maxKapasite+1));

    if (!this->gezegenDizisi) {
        perror("Bellek ayrilamadi");
        fclose(dosya);
        return NULL;
    }

    while (fgets(satir, sizeof(satir), dosya)) {
        this->gezegenSayisi++;

        if (sayac >= maxKapasite) {
            maxKapasite *= 2;
            this->gezegenDizisi = (Gezegen*)realloc(this->gezegenDizisi, sizeof(Gezegen) * (maxKapasite+1));
            if (!this->gezegenDizisi) {
                perror("Yeniden bellek ayrilamadi");
                fclose(dosya);
                return NULL;
            }
        }

        char satirKopya[256];
        strcpy(satirKopya, satir);
        char* token = strtok(satir, "#");
        if (!token) continue;

        char* ad = strdup(token); // strdup bellekte yeni kopya oluşturur

        token = strtok(NULL, "#");
        int gezegenTuru =atoi(token);

        token = strtok(NULL, "#");
        int gunSaati = atoi(token);

        token = strtok(NULL, "#\n");
        char* tarih = strdup(token); // strdup bellekte yeni kopya oluşturur

        Gezegen yeniGezegen =gezegenOlustur(ad,gezegenTuru,gunSaati,tarih);
        // switch (gezegenTuru)
        // {
        //     case 0:
        //         yeniGezegen = (Gezegen)kayacOlustur(ad, gezegenTuru, gunSaati, tarih);
        //         break;
        //     case 1:
        //         yeniGezegen = (Gezegen)gazDeviOlustur(ad, gezegenTuru, gunSaati, tarih);
        //         break;
        //     case 2:
        //         yeniGezegen = (Gezegen)buzDeviOlustur(ad, gezegenTuru, gunSaati, tarih);
        //         break;
        //     case 3:
        //         yeniGezegen = (Gezegen)cuceOlustur(ad, gezegenTuru, gunSaati, tarih);
        //         break;    
        //     default:
        //         printf("Geçersiz tur.\n");
        //         break;
        // }
        


        this->gezegenDizisi[sayac++] = yeniGezegen;
    }
    fclose(dosya);
    return this->gezegenDizisi;

}

UzayAraci* uzayAraciDosyaOkuma(const DosyaOkuma this, char* fileName, Kisi* kisiDizisi, Gezegen* gezegenDizisi)
{
    int maxKapasite=100;
    FILE* dosya = fopen(fileName,"r");
    if (!dosya) {
        perror("Dosya acilamadi");
        return NULL;
    }

    char satir[256];
    int sayac=0;
    this->uzayAraciDizisi = (UzayAraci*)malloc(sizeof(UzayAraci) * (maxKapasite+1));

    if (!this->uzayAraciDizisi) {
        perror("Bellek ayrilamadi");
        fclose(dosya);
        return NULL;
    }

    while (fgets(satir, sizeof(satir), dosya)) {
    this->uzayAraciSayisi++;

        if (sayac >= maxKapasite) {
            maxKapasite *= 2;
            this->uzayAraciDizisi = (UzayAraci*)realloc(this->uzayAraciDizisi, sizeof(UzayAraci) * (maxKapasite+1));
            if (!this->uzayAraciDizisi) {
                perror("Yeniden bellek ayrilamadi");
                fclose(dosya);
                return NULL;
            }
        }

        char satirKopya[256];
        strcpy(satirKopya, satir);
        char* token = strtok(satir, "#");
        if (!token) continue;

        char* isim = strdup(token); // strdup bellekte yeni kopya oluşturur


        token = strtok(NULL, "#");
        char* cikisGezegeniStr =strdup(token);

        token = strtok(NULL, "#");
        char* varisGezegeniStr =strdup(token);
        token = strtok(NULL, "#");
        char* cikisTarihi =strdup(token);

        token = strtok(NULL, "#\n");
        int mesafe = atoi(token); // strdup bellekte yeni kopya oluşturur

        Gezegen cikisGezegeni = NULL, varisGezegeni =NULL;

        for (int i = 0; i < this->gezegenSayisi; i++)
        {
            if(gezegenDizisi[i])
            if(strcmp(gezegenDizisi[i]->getIsim(gezegenDizisi[i]), cikisGezegeniStr)==0)
            {   
                cikisGezegeni=gezegenDizisi[i];
            }
            if(strcmp(gezegenDizisi[i]->getIsim(gezegenDizisi[i]), varisGezegeniStr)==0)
            { 
                varisGezegeni=gezegenDizisi[i];
            }
        }
        
            if(cikisGezegeni==NULL)
            {   
                printf("Cikis gezegeni ve Uzay araci eslesemedi!!");
                exit(0);    
            }
            if(varisGezegeni==NULL)
            { 
                printf("Varis gezegeni ve Uzay araci eslesemedi!!");
                exit(0);
            }
        

        UzayAraci yeniUzayAraci = uzayAraciOlustur(isim, cikisGezegeni, varisGezegeni, cikisTarihi, mesafe);

        //yeniUzayAraci->yolcular = kisiDizisi;
        //yeniUzayAraci->yolcuSayisi=this->kisiSayisi;
        this->uzayAraciDizisi[sayac++] = yeniUzayAraci;

       
    }
    fclose(dosya);
     for (int j = 0; j < this->uzayAraciSayisi; j++)
        {
            for (int i = 0; i < this->kisiSayisi; i++)
            {
                if(strcmp(this->uzayAraciDizisi[j]->adi, kisiDizisi[i]->aracAdi)==0)
                {   
                    kisiDizisi[i]->bulunduguUzayAraci=this->uzayAraciDizisi[j];
                    this->uzayAraciDizisi[j]->kisiEkle(this->uzayAraciDizisi[j], kisiDizisi[i]);
                }
            }
        }
        for (int i = 0; i < this->kisiSayisi; i++)
            {
                if(kisiDizisi[i]->bulunduguUzayAraci->adi==NULL)
                {   
                    printf("Kisi ve Uzay araci eslesemedi!!");
                    exit(0);
                }
            }

    return this->uzayAraciDizisi;
}
void dosyaOkumaYokEt(DosyaOkuma this) {
   if (this == NULL) return;

    free(this);
}
