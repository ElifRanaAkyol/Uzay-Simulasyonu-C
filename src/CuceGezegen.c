/**
* @file CuceGezegen
* @description CuceGezegeni sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "CuceGezegen.h"
#include "Kisi.h"
#include "UzayAraci.h" // Ensure this header contains the full definition of struct UZAYARACI
#include <stdlib.h>
#include <stdio.h>
CuceGezegen cuceOlustur(char* isim, int gezegenTuru, int gunSaati, char* tarih)
{
    CuceGezegen this;
    this = (CuceGezegen)malloc(sizeof(struct CUCEGEZEGEN));
    char* ad = strdup(isim);

    this->superGezegen = gezegenOlustur(ad, gezegenTuru, gunSaati, tarih);
    this->gezegenTuru = gezegenTuru;
    this->cuceYoket = &cuceYoket;
    this->superGezegen->yolcuOmurHesapla=&yolcuOmurCuce;
    return this;
}

void yolcuOmurCuce(const Gezegen this, Kisi yolcu)
{
    if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Bekliyor") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->cikisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=0.01;
            }
        }
        if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Vardi") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->varisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=0.01;
            }

    }else if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Yolda") == 0)
    {  
        yolcu->azalmaMiktari=1;
    }
}
void cuceYoket(CuceGezegen this)
{
    if (this == NULL) return;

    if (this->superGezegen != NULL)
    {
        gezegenYoket(this->superGezegen);
    }

    free(this);
}