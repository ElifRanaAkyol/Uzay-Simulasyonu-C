/**
* @file BuzDeviGezegen
* @description BuzDeviGezegeni baslik sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef BUZDEVIGEZEGEN_H
#define BUZDEVIGEZEGEN_H

#include "Gezegen.h"
#include "Kisi.h"
struct BUZDEVIGEZEGEN{
    Gezegen superGezegen;
    double yaslanmaMiktari;
    int gezegenTuru;
    void (*buzDeviYoket)(struct BUZDEVIGEZEGEN*);
};
    typedef struct BUZDEVIGEZEGEN *BuzDeviGezegen;
    BuzDeviGezegen buzDeviOlustur(char*, int , int, char*);
    void zamaniIlerletBuzDevi(const Gezegen, Kisi);
    void buzDeviYoket(BuzDeviGezegen);
    void yolcuOmurBuzDevi(const Gezegen, Kisi);


#endif
