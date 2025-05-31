/**
* @file KayacGezegen
* @description KayacGezegeni baslik sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef KAYACGEZEGEN_H
#define KAYACGEZEGEN_H

#include "Gezegen.h"
#include "Kisi.h"
struct KAYACGEZEGEN{
    Gezegen superGezegen;
    double yaslanmaMiktari;
    int gezegenTuru;
    void (*kayacYoket)(struct KAYACGEZEGEN*);
};
    typedef struct KAYACGEZEGEN *KayacGezegen;
    KayacGezegen kayacOlustur(char*, int , int, char*);
    void zamaniIlerletKayac(const Gezegen, Kisi);
    void kayacYoket(KayacGezegen);
    void yolcuOmurKayac(const Gezegen, Kisi);


#endif
