/**
* @file Zaman
* @description zaman parametreleri ve fonksiyonlarını içeren sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "Zaman.h"
#include <stdlib.h>

Zaman zamanOlustur()
{
    Zaman this;
    this = (Zaman)malloc(sizeof(struct ZAMAN));
    this->saat = 0;
    
    this->getSaat = &getSaat;
    this->zamanArttir = &zamanArttir;
    this->zamanYoket = &zamanYoket;
    
    return this;
}
int getSaat( const Zaman this)
{
    return this->saat;
}
void zamanArttir(const Zaman this)
{
    this->saat=this->saat+1;
}
void zamanYoket(Zaman this)
{
    if (this == NULL)
    {
        return;
    }
    free(this);
}