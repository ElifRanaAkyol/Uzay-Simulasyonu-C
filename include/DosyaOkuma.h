/**
* @file DosyaOkuma
* @description dosyaOkuma baslik sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Kisi.h"
#include "CuceGezegen.h"
#include "GazDeviGezegen.h"
#include "KayacGezegen.h"
#include "BuzDeviGezegen.h"
#include "UzayAraci.h"
#include "Gezegen.h"

struct DOSYAOKUMA{

    Kisi* kisiDizisi; //Kisi dizisi
    int kisiSayisi; //Kisi sayisini tutan bir degisken
    UzayAraci* uzayAraciDizisi; //Uzay araci dizisi
    int uzayAraciSayisi; //Uzay araci sayisini tutan bir degisken
    Gezegen* gezegenDizisi;
    int gezegenSayisi;
    Kisi* (*kisiDosyaOkuma)(struct DOSYAOKUMA*, char*); //Kisi dosyasini okuyan fonksiyon
    UzayAraci* (*uzayAraciDosyaOkuma)(struct DOSYAOKUMA*, char*, Kisi*, Gezegen*);
    Gezegen* (*gezegenDosyaOkuma)(struct DOSYAOKUMA*, char*);
    int maxKapasite;
    void (*dosyaOkumaYokEt)(struct DOSYAOKUMA*);
    
}; 

typedef struct DOSYAOKUMA* DosyaOkuma; //DosyaOkuma yapisini tanimlayan bir typedef
DosyaOkuma dosyaOkumaOlustur();
Kisi* kisiDosyaOkuma(const DosyaOkuma, char*); //Kisi dosyasini okuyan fonksiyon
UzayAraci* uzayAraciDosyaOkuma(const DosyaOkuma, char*, Kisi* kisiDizisi, Gezegen* gezegenDizisi);
Gezegen* gezegenDosyaOkuma(const DosyaOkuma, char*);
void dosyaOkumaYokEt(const DosyaOkuma);


#endif
