/**
* @file Kisi
* @description tum yolcuların olusturuldugu sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kisi.h"
#include "UzayAraci.h"
#include <stdbool.h>

Kisi kisiOlustur(char* isim, int yas, double kalanOmur, UzayAraci bulunduguUzayAraci){
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    this->isim = isim;
    this->yas = yas;
    this->aracAdi=NULL;
    this->kalanOmur = kalanOmur;
    this->bulunduguUzayAraci = bulunduguUzayAraci;
    this->azalmaMiktari = 1;
    this->setAzalmaMiktari = &setAzalmaMiktari;
    this->kalanOmuruAzalt = &kalanOmuruAzalt;
    this->kisiYoket = &kisiYoket;
    this->setBulunduguUzayAraci = &setBulunduguUzayAraci;
    this->getBulunduguUzayAraci = &getBulunduguUzayAraci;
    this->getKalanOmur = &getKalanOmur;
    this->setAzalmaMiktari = &setAzalmaMiktari;
    this->toString=&toString;
    this->durum=true;
    return this;


}

void setBulunduguUzayAraci(const Kisi this, UzayAraci bulunduguUzayAraci)
{
    this->bulunduguUzayAraci = bulunduguUzayAraci;
}
UzayAraci getBulunduguUzayAraci(const Kisi this)
{
    return this->bulunduguUzayAraci;
}
double getKalanOmur(const Kisi this)
{
    return this->kalanOmur;
}
void setAzalmaMiktari(const Kisi this, double azalmaMiktari)
{
    this->azalmaMiktari = azalmaMiktari;
}
void kisiYoket(Kisi this){
    if(this == NULL)
    {
        return;  
    }
    free(this);
} 
void kalanOmuruAzalt(const Kisi this)
{
    this->kalanOmur= this->kalanOmur - this->azalmaMiktari;
    //printf("AZALMA: %lf  KALAN OMJUE: %lf\n", this->azalmaMiktari, this->kalanOmur);
    if(this->kalanOmur < 0)
    {
        this->kalanOmur = 0;
        this->durum = false;
    }
}
char* toString(const Kisi this)
{
    int toplamUzunluk=36;
    toplamUzunluk+=strlen(this->isim);
    char* str=(char*)malloc(sizeof(char)*toplamUzunluk+1);//+1 => \n için
    //formatı string olarak birleştirmek için sprintf ile str ye aktarım yapıyoruz.
    sprintf(str,"\nRenk: %s",this->isim);
    
    return str;
}

