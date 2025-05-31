/**
* @file Gezegen
* @description tum turlerin kalıtım aldıgı Gezegen sınıfı
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "Gezegen.H"
#include "Zaman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Gezegen gezegenOlustur(char* isim, int gezegenTuru, int gunSaati, char* tarih)
{
    Gezegen this;
    this = (Gezegen)malloc(sizeof(struct GEZEGEN));
    this->super = zamanOlustur();
    this->isim = isim;

    this->nufus = 0;
    
    this->gezegenTuru = gezegenTuru;
    this->gunSaati = gunSaati;
    this->tarih = tarih;
    
    
    
    char* tarihCopy = strdup(tarih);
    char* token = strtok(tarihCopy, ".");
    int gun=token ? atoi(token):0;//inte cevirir
    token=strtok(NULL, ".");
    int ay=token ? atoi(token):0;
    token=strtok(NULL, ".");
    int yil=token ? atoi(token):0;
    free(tarihCopy);
    this->gun = gun;
    this->ay = ay;
    this->yil = yil;
    
    this->yazdir = &yazdir;
    this->getGunSaati = &getGunSaati;
    this->getTarih = &getTarih;
    this->getIsim = &getIsim;
    this->setNufus=&setNufus;
    this->getNufus=&getNufus;
    this->getGezegenTuru = &getGezegenTuru;
    this->tariheDonustur=&tariheDonustur;
    this->zamaniIlerlet=&zamaniIlerlet;
    return this;
}
int getGunSaati(const Gezegen this)
{
    return this->gunSaati;
}
char* getTarih(const Gezegen this)
{
    return this->tarih;
}
char* getIsim(const Gezegen this)
{
    return this->isim;
}
int getGezegenTuru(const Gezegen this)
{
    return this->gezegenTuru;
}
int getNufus(const Gezegen this)
{
    return this->nufus;
}
void setNufus(const Gezegen this, int nufus)
{
    this->nufus=nufus;
}
void gezegenYoket(Gezegen this)
{
    if (this == NULL)
    {
        return;
    }
    if (this->super != NULL) //this->super->zamanYoket(this->super);
    free(this);
}
void yazdir(const Gezegen this)
{
   printf("gun: %d\n", this->gun);
}
char* tariheDonustur(const Gezegen this, int saat)
{
   int yil= saat/(12*30*this->gunSaati);
   int ay = (saat%(12*30*this->gunSaati))/(30*this->gunSaati);
		if(ay==0) {
			ay=12;
			yil--;
		}
		int gun =(((saat%(12*30*this->gunSaati))%(30*this->gunSaati)))/this->gunSaati;
		if(ay==1||ay==3||ay==5||ay==7||ay==8||ay==10||ay==12)
        {
            if(gun==0) {
                gun=31;
                ay--;
            }
        }
        else{
            if(gun==0) {
                gun=30;
                ay--;
            }
        }
        char* tarih = (char*)malloc(20 * sizeof(char));
		sprintf(tarih, "%02d.%02d.%04d", gun, ay, yil);
        char* tarihstr=tarih;
        //free(tarih);
        return tarih;
}

void zamaniIlerlet(const Gezegen this)
{
    this->super->zamanArttir(this->super);
    if(this->super->saat==this->gunSaati)
		{
			this->gun++;
			this->super->saat=0;
		}
        if(this->ay==1||this->ay==3||this->ay==5||this->ay==7||this->ay==8||this->ay==10||this->ay==12)
		{
            if(this->gun==32)
            {
                this->ay++;
                this->gun=1;
            }
        } else{
            if(this->gun==31)
            {
                this->ay++;
                this->gun=1;
            }
        }
		if(this->ay==13)
		{
			this->yil++;
			this->ay=1;
		}
        char geciciTarih[20];
		sprintf(geciciTarih, "%02d.%02d.%04d", this->gun, this->ay, this->yil);
        strcpy(this->tarih, geciciTarih);
		
}