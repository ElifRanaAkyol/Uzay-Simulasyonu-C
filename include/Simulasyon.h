/**
* @file Simulasyon
* @description simulasyon baslik sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef SIMULASYON_H
#define SIMULASYON_H
#include <string.h>
#include "KayacGezegen.h"
#include "GazDeviGezegen.h"
#include "CuceGezegen.h"
#include "BuzDeviGezegen.h"
#include "Kisi.h"
#include "UzayAraci.h"


struct SIMULASYON {
    Kisi* kisiDizisi;
    int kisiSayisi; //Kisi sayisini tutan bir degisken
    Gezegen* gezegenDizisi; //Cuce gezegen dizisi
    int gezegenSayisi; //Cuce gezegen sayisini tutan bir degisken
    UzayAraci* uzayAraciDizisi; //Uzay araci dizisi
    int uzayAraciSayisi;
    

    void (*baslat)(struct SIMULASYON*); //Gezegen olustur fonksiyonu
    void (*simulasyonYoket)(struct SIMULASYON*); //Gezegen yoket fonksiyonu
};
    typedef struct SIMULASYON* Simulasyon; //Simulasyon yapisini tanimlayan bir typedef
    Simulasyon simulasyonOlustur(Kisi*, UzayAraci*, Gezegen*, int, int, int); //Simulasyon olustur fonksiyonu
    void baslat(struct SIMULASYON*); //Simulasyon baslat fonksiyonu
    void simulasyonYoket(struct SIMULASYON*); //Simulasyon yoket fonksiyonu

#endif
