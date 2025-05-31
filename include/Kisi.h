/**
* @file Kisi
* @description kisi baslik sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef KISI_H
#define KISI_H
#include <stdbool.h>
#include <string.h>
struct UZAYARACI;                      // Sadece tipin varlığını bildir
typedef struct UZAYARACI* UzayAraci;

struct KISI{
    char* isim;
    int yas;
    double kalanOmur;
    double azalmaMiktari;
    UzayAraci bulunduguUzayAraci;
    char* aracAdi;
    void (*kalanOmuruAzalt)(struct KISI*);
    void (*setAzalmaMiktari)(struct KISI*, double);
    void (*kisiYoket)(struct KISI*);
    void (*setBulunduguUzayAraci)(struct KISI*, UzayAraci);
    UzayAraci (*getBulunduguUzayAraci)(struct KISI*);
    double (*getKalanOmur)(struct KISI*);
    char* (*toString)(struct KISI*);
    bool durum;

};

typedef struct KISI* Kisi;
Kisi kisiOlustur(char*, int, double, UzayAraci);
void kalanOmuruAzalt(const Kisi);
void setAzalmaMiktari(const Kisi, double);
void setBulunduguUzayAraci(const Kisi, UzayAraci);
UzayAraci getBulunduguUzayAraci(const Kisi);
double getKalanOmur(const Kisi);
void kisiYoket(Kisi);
char* toString(const Kisi);

#endif