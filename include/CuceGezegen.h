/**
* @file CuceGezegen
* @description CuceGezegeni baslik sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef CUCEGEZEGEN_H
#define CUCEGEZEGEN_H

#include "Gezegen.h"
#include "Kisi.h"
struct CUCEGEZEGEN{
    Gezegen superGezegen;
    double yaslanmaMiktari;
    int gezegenTuru;
    void (*cuceYoket)(struct CUCEGEZEGEN*);
};
    typedef struct CUCEGEZEGEN *CuceGezegen;
    CuceGezegen cuceOlustur(char*, int , int, char*);
    void zamaniIlerletCuce(const Gezegen, Kisi);
    void cuceYoket(CuceGezegen);
    void yolcuOmurCuce(const Gezegen, Kisi);


#endif
