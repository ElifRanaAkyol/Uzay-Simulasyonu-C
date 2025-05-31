/**
* @file UzayAraci
* @description uzayAraci baslik sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef UZAYARACI_H
#define UZAYARACI_H

#include "Kisi.h"
#include "Gezegen.h"


struct UZAYARACI{
    Zaman super;
    char* durum;
    char* adi;
    int mesafe;
    int kalanSaat;
    Gezegen cikisGezegeni;
    Gezegen varisGezegeni;
    char* cikisTarihi;
    char* varisTarihi;
    Kisi* yolcular; //yolculari tutan bir dizi
    int yolcuSayisi;; //yolcu sayisini tutan bir degisken
   
    char* (*getAdi)(struct UZAYARACI*);
    int (*getMesafe)(struct UZAYARACI*);
    int (*getKalanSaat)(struct UZAYARACI*);
    int (*setKalanSaat)(struct UZAYARACI*, int);
    char* (*getCikisTarihi)(struct UZAYARACI*);
    char* (*getVarisTarihi)(struct UZAYARACI*);
    Gezegen (*getCikisGezegeni)(struct UZAYARACI*);
    Gezegen (*getVarisGezegeni)(struct UZAYARACI*);
    void (*setCikisGezegeni)(struct UZAYARACI*, Gezegen);
    void (*setVarisGezegeni)(struct UZAYARACI*, Gezegen);
    void (*uzayAraciYoket)(struct UZAYARACI*);
    int (*saateDonustur)(struct UZAYARACI*, const char*, Gezegen);
    char* (*varisTarihiHesapla)(struct UZAYARACI*);
    char* (*durumuDondur)(struct UZAYARACI*);
    void (*zamaniIlerletArac)(struct UZAYARACI*);
    int (*kisiSayisiDondur)(struct UZAYARACI*);
    void (*kisiEkle)(struct UZAYARACI*, Kisi);
    char* (*setVarisTarihi)(const UzayAraci,char*);

};
typedef struct UZAYARACI *UzayAraci;

UzayAraci uzayAraciOlustur(char*, Gezegen, Gezegen, char*, int);
char* getAdi(const UzayAraci);
int getMesafe(const UzayAraci);
int getKalanSaat(const UzayAraci);  
int setKalanSaat(const UzayAraci, int);
char* getCikisTarihi(const UzayAraci);
char* getVarisTarihi(const UzayAraci);
Gezegen getCikisGezegeni(const UzayAraci);
Gezegen getVarisGezegeni(const UzayAraci);
void uzayAraciYoket(UzayAraci);
int saateDonustur(const UzayAraci, const char*, Gezegen);
char* varisTarihiHesapla(const UzayAraci);
char* durumuDondur(const UzayAraci);
void zamaniIlerletArac(const UzayAraci);
int kisiSayisiDondur(const UzayAraci);
void kisiEkle(const UzayAraci, Kisi);
void setVarisGezegeni(const UzayAraci, const Gezegen);
void setCikisGezegeni(const UzayAraci,const Gezegen);
char* setVarisTarihi(const UzayAraci,char*);



#endif