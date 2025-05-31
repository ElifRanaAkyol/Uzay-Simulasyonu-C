/**
* @file Zaman
* @description zaman baslik sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#ifndef ZAMAN_H
#define ZAMAN_H

#include "time.h"
#include "math.h"
#include "string.h"

struct ZAMAN{
    int saat;
    
    int (*getSaat)(struct ZAMAN*);
    void (*zamanArttir)(struct ZAMAN*);
    void (*zamanYoket)(struct ZAMAN*);

};

typedef struct ZAMAN *Zaman;
Zaman zamanOlustur();
int getSaat(const Zaman);
void zamanArttir(const Zaman);
void zamanYoket(Zaman);

#endif