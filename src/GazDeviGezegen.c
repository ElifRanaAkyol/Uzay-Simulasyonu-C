/**
* @file GazDeviGezegen
* @description GazDeviGezegeni sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "GazDeviGezegen.h"
#include "Kisi.h"
#include "UzayAraci.h" // Ensure this header contains the full definition of struct UZAYARACI
#include <stdlib.h>
#include <stdio.h>
GazDeviGezegen gazDeviOlustur(char* isim, int gezegenTuru, int gunSaati, char* tarih)
{
    GazDeviGezegen this;
    this = (GazDeviGezegen)malloc(sizeof(struct GAZDEVIGEZEGEN));
    char* ad = strdup(isim);
    this->superGezegen = gezegenOlustur(ad, gezegenTuru, gunSaati, tarih);
    this->gezegenTuru = gezegenTuru;
    this->yaslanmaMiktari=0.1;
    this->superGezegen->yolcuOmurHesapla = &yolcuOmurGazDevi;
    this->gazDeviYoket = &gazDeviYoket;
    return this;
}
void yolcuOmurGazDevi(const Gezegen this, Kisi yolcu)
{
    if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Bekliyor") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->cikisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=0.1;
            }
        }
        else if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Vardi") == 0)
        {
            if(strcmp(yolcu->bulunduguUzayAraci->varisGezegeni->isim, this->isim) == 0)
            {
                yolcu->azalmaMiktari=0.1;
            }

        }else if(yolcu->bulunduguUzayAraci != NULL && strcmp(yolcu->bulunduguUzayAraci->durumuDondur(yolcu->bulunduguUzayAraci), "Yolda") == 0)
         {  
            yolcu->azalmaMiktari=1;
        }


}
// void zamaniIlerletGazDevi(const Gezegen this)
// {   
//     if (this == NULL) {
//         printf("this NULL!\n");
//     }
//     if (this == NULL) {
//         printf("superGezegen NULL!\n");
//     }

//     if (this->super == NULL) {
//     printf("SAAT:");//burası çalışmıyor Tamam anladım bi dakika
//     }

//     this->super->zamanArttir(this->super);

//     if(this->super->getSaat(this->super)==this->getGunSaati(this)) 
// 	{
// 		this->gun++;
// 		this->super->saat=0;
// 	}
// 	if(this->gun==31)
// 	{
// 		this->ay++;
// 		this->gun=1;
// 	}
// 	if(this->ay==13)
// 	{
// 		this->yil++;
// 		this->ay=1;
// 	}

//     // char* strAy[2], strGun[2],strYil[11];
    
//     // sprintf(strAy, "%d", this->ay);
//     // sprintf(strAy, "%d", this->ay);
//     // sprintf(strAy, "%d", this->ay);


// }
void gazDeviYoket(GazDeviGezegen this)
{  
   
    if (this == NULL) return;

    if (this->superGezegen != NULL)
    {
        gezegenYoket(this->superGezegen);
    }

    free(this);

}