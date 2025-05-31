/**
* @file Main
* @description islemlerin birlestirildigi sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>

#include "Kisi.h"
#include "UzayAraci.h"
#include "Gezegen.h"
#include "GazDeviGezegen.h"
#include "Zaman.h"
#include "Simulasyon.h"
#include "DosyaOkuma.h"

int main()
{
    DosyaOkuma okuma = dosyaOkumaOlustur();

    Kisi* kisiDizisi = okuma->kisiDosyaOkuma(okuma, "Kisiler.txt");

    Gezegen* gezegenDizisi = okuma->gezegenDosyaOkuma(okuma, "Gezegenler.txt");
           

    UzayAraci* uzayAraciDizisi = okuma->uzayAraciDosyaOkuma(okuma, "Araclar.txt", kisiDizisi, gezegenDizisi);
    Simulasyon simulasyon= simulasyonOlustur(kisiDizisi, uzayAraciDizisi, gezegenDizisi,okuma->kisiSayisi,okuma->uzayAraciSayisi, okuma->gezegenSayisi);
    
    
    simulasyon->baslat(simulasyon);
    for (int i = 0; i < okuma->gezegenSayisi; i++) {
        gezegenYoket(gezegenDizisi[i]);
    }
    free(gezegenDizisi);

    for (int i = 0; i < okuma->gezegenSayisi; i++) {
    if (gezegenDizisi[i]->getGezegenTuru(gezegenDizisi[i]) == 1) {
        gazDeviYoket((GazDeviGezegen)gezegenDizisi[i]);
    } else {
        gezegenYoket(gezegenDizisi[i]);
    }
    }
    free(gezegenDizisi);
    for (int i = 0; i < okuma->kisiSayisi; i++) {
    kisiYoket(kisiDizisi[i]);
    }
    free(kisiDizisi);

    okuma->dosyaOkumaYokEt(okuma);
    simulasyon->simulasyonYoket(simulasyon);

    return 0;

}