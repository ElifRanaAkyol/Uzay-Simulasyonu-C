/**
* @file BuzDeviGezegen
* @description BuzDeviGezegeni sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "BuzDeviGezegen.h"
#include "Kisi.h"
#include "UzayAraci.h" // Ensure this header contains the full definition of struct UZAYARACI
#include <stdlib.h>
#include <stdio.h>
BuzDeviGezegen buzDeviOlustur(char* isim, int gezegenTuru, int gunSaati, char* tarih)
{
    BuzDeviGezegen this;
    this = (BuzDeviGezegen)malloc(sizeof(struct BUZDEVIGEZEGEN));
    char* ad = strdup(isim);

    this->superGezegen = gezegenOlustur(ad, gezegenTuru, gunSaati, tarih);
    this->gezegenTuru = gezegenTuru;
    this->buzDeviYoket = &buzDeviYoket;
    this->superGezegen->yolcuOmurHesapla=&yolcuOmurBuzDevi;
    return this;
}

void yolcuOmurBuzDevi(const Gezegen this, Kisi yolcu)
{
    if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Bekliyor") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->cikisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=0.5;
            }
        }
        else if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Vardi") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->varisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=0.5;
            }

        }else if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Yolda") == 0)
        {  
            yolcu->azalmaMiktari=1;
        }

}
void buzDeviYoket(BuzDeviGezegen this)
{
    if (this == NULL) return;

    if (this->superGezegen != NULL)
    {
        gezegenYoket(this->superGezegen);
    }

    free(this);
}
