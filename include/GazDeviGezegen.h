/**
* @file GazDeviGezegen
* @description GazDeviGezegeni baslik sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef GAZDEVIGEZEGEN_H
#define GAZDEVIGEZEGEN_H

#include "Gezegen.h"
#include "Kisi.h"
struct GAZDEVIGEZEGEN{
    Gezegen superGezegen;
    double yaslanmaMiktari;
    int gezegenTuru;
    void (*gazDeviYoket)(struct GAZDEVIGEZEGEN*);
    
};
    typedef struct GAZDEVIGEZEGEN *GazDeviGezegen;
    GazDeviGezegen gazDeviOlustur(char*, int , int, char*);
    void zamaniIlerletGazDevi(const Gezegen);
    void gazDeviYoket(GazDeviGezegen);
    void yolcuOmurGazDevi(const Gezegen, Kisi);

#endif
