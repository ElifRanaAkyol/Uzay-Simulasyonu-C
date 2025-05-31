/**
* @file KayacGezegen
* @description KayacGezegeni sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "KayacGezegen.h"
#include "Kisi.h"
#include "UzayAraci.h" // Ensure this header contains the full definition of struct UZAYARACI
#include <stdlib.h>
#include <stdio.h>
KayacGezegen kayacOlustur(char* isim, int gezegenTuru, int gunSaati, char* tarih)
{
    KayacGezegen this;
    this = (KayacGezegen)malloc(sizeof(struct KAYACGEZEGEN));
    char* ad = strdup(isim);

    this->superGezegen = gezegenOlustur(ad, gezegenTuru, gunSaati, tarih);
    this->gezegenTuru = gezegenTuru;
    this->yaslanmaMiktari=1;
    this->kayacYoket = &kayacYoket;
    this->superGezegen->yolcuOmurHesapla=&yolcuOmurKayac;
    return this;
}

void yolcuOmurKayac(const Gezegen this, Kisi yolcu)
{
    if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Bekliyor") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->cikisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=1;
            }
        }
        if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Vardi") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->varisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=1;
            }

        }else if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Yolda") == 0)
        {  
            yolcu->azalmaMiktari=1;
        }
}
void kayacYoket(KayacGezegen this)
{
    if (this == NULL) return;

    if (this->superGezegen != NULL)
    {
        gezegenYoket(this->superGezegen);
    }

    free(this);
}