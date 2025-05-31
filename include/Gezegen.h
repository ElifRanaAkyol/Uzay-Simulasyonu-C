/**
* @file Gezegen
* @description Gezegen baslik sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef GEZEGEN_H
#define GEZEGEN_H

#include "Zaman.h"
#include "Kisi.h"


#include "time.h"
#include "math.h"
#include "string.h"



struct GEZEGEN{
    Zaman super;
    char* isim;
    int gezegenTuru;
    int gunSaati;
    char* tarih;
    int gun;
    int ay;
    int yil;
   
    int nufus;

    int (*getGunSaati)(struct GEZEGEN*);
    char* (*getTarih)(struct GEZEGEN*);
    char* (*getIsim)(struct GEZEGEN*);
    int (*getGezegenTuru)(struct GEZEGEN*);
    void (*gezegenYoket)(struct GEZEGEN*);
    void (*yazdir)(struct GEZEGEN*);
    char* (*tariheDonustur)(struct GEZEGEN*, int);
    void (*zamaniIlerlet)(struct GEZEGEN*);
    int (*getNufus)(struct GEZEGEN*);
    void (*setNufus)(struct GEZEGEN*, int);
    void (*yolcuOmurHesapla)();


};
typedef struct GEZEGEN *Gezegen;
Gezegen gezegenOlustur(char*, int, int, char*);
int getGunSaati(const Gezegen);
char* getTarih(const Gezegen);
char* getIsim(const Gezegen);
int getGezegenTuru(const Gezegen);    
void gezegenYoket(Gezegen);
void yazdir(const Gezegen);
char* tariheDonustur(const Gezegen, int);
int getNufus(const Gezegen);
void setNufus(const Gezegen, int);
void zamaniIlerlet(const Gezegen);


#endif