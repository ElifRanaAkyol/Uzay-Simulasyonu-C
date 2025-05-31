/**
* @file UzayAraci
* @description Tum uzayAraclarinin olusturuldugu sınıf
* @course 1. öğretim C grubu
* @assignment 2. ödev
* @date 16.05.2025
* @author Elif Ranagül Akyol ranagul.akyol@ogr.sakarya.edu.tr
*/
#include "UzayAraci.h"
#include "Gezegen.h"
#include "Kisi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strdup için


UzayAraci uzayAraciOlustur(char* adi, Gezegen cikisGezegeni, Gezegen varisGezegeni, char* cikisTarihi, int mesafe)
{
    UzayAraci this;
    // Zaman nesnesini oluştur
    this = (UzayAraci)malloc(sizeof(struct UZAYARACI));
    this->super = zamanOlustur(); 
    this->adi = adi;
    this->cikisGezegeni = cikisGezegeni;
    this->varisGezegeni = varisGezegeni;
    this->cikisTarihi = strdup(cikisTarihi);
    this->mesafe = mesafe;
    this->kalanSaat=mesafe;
    this->durum = "Bekliyor"; // Başlangıçta durum "Hazır"
    this->yolcular = NULL; // Başlangıçta yolcu yok
    this->yolcuSayisi = 0; // Başlangıçta yolcu sayısı 0
    this->getAdi = &getAdi;
    this->getMesafe = &getMesafe;
    this->getKalanSaat = &getKalanSaat;
    this->setKalanSaat=&setKalanSaat;
    this->getCikisTarihi = &getCikisTarihi;
    this->getVarisTarihi = &getVarisTarihi;
    this->setVarisGezegeni= &setVarisGezegeni;
    this->setCikisGezegeni= &setCikisGezegeni;
    this->getCikisGezegeni = &getCikisGezegeni;
    this->getVarisGezegeni = &getVarisGezegeni;
    this->uzayAraciYoket = &uzayAraciYoket;
    this->kisiSayisiDondur = &kisiSayisiDondur;
    this->kisiEkle = &kisiEkle;
    this->saateDonustur = &saateDonustur;
    this->varisTarihiHesapla = &varisTarihiHesapla;
    this->durumuDondur = &durumuDondur;
    this->uzayAraciYoket = &uzayAraciYoket;
    this->zamaniIlerletArac = &zamaniIlerletArac;
    this->varisTarihi="0.0.0";
    this->setVarisTarihi=&setVarisTarihi;
    this->saateDonustur=&saateDonustur;

    return this;
}
char* getAdi(const UzayAraci this)
{
    return this->adi;
}
int getMesafe(const UzayAraci this)
{
    return this->mesafe;
}
int getKalanSaat(const UzayAraci this)
{
    return this->kalanSaat;
}
int setKalanSaat(const UzayAraci this, int kalanSaat)
{
    this->kalanSaat=kalanSaat;
}
char* getCikisTarihi(const UzayAraci this)
{
    return this->cikisTarihi;
}
char* setVarisTarihi(const UzayAraci this, char* tarih)
{
    this->varisTarihi=tarih;
}
int saateDonustur(const UzayAraci this, const char* tarih, Gezegen gezegen)
{
    // Kopyalama için buffer
    char tarihKopya[256];
    strcpy(tarihKopya, tarih); // orijinali bozmadan tokenize edebilmek için

    // Token parçalama
    char* token = strtok(tarihKopya, ".");
    if (token == NULL) return -1;
    int gun = atoi(token);

    token = strtok(NULL, ".");
    if (token == NULL) return -1;
    int ay = atoi(token);

    token = strtok(NULL, ".");
    if (token == NULL) return -1;
    int yil = atoi(token);

    int gunSaati = gezegen->getGunSaati(gezegen);
    int toplamSaat = gun * gunSaati + ay * 30 * gunSaati + yil * 12 * 30 * gunSaati;

    return toplamSaat;
}

char* getVarisTarihi(const UzayAraci this)
{
    return this->varisTarihi;
    
}
Gezegen getCikisGezegeni(const UzayAraci this)
{
    return this->cikisGezegeni;
}
Gezegen getVarisGezegeni(const UzayAraci this)
{
    return this->varisGezegeni;
}
void setVarisGezegeni(const UzayAraci this, const Gezegen gezegen)
{
    this->varisGezegeni=gezegen;
}
void setCikisGezegeni(const UzayAraci this, const Gezegen gezegen)
{
    this->cikisGezegeni=gezegen;
}
void uzayAraciYoket(UzayAraci this)
{
    if (this == NULL)
    {
        return;
    }
    if (this->yolcular != NULL)
    {
        for (int i = 0; i < this->yolcuSayisi; i++)
        {
            if (this->yolcular[i] != NULL)
            {
                this->yolcular[i]->kisiYoket(this->yolcular[i]);
            }
        }
       // free(this->yolcular);
    }
    if (this->super != NULL)
    {
        this->super->zamanYoket(this->super);
    }

    free(this);
}

char* varisTarihiHesapla(UzayAraci this)
{
    int toplamGecenSure=saateDonustur(this, this->cikisTarihi, this->cikisGezegeni)-saateDonustur(this, this->cikisGezegeni->getTarih(this->cikisGezegeni), this->cikisGezegeni) + saateDonustur(this, this->varisGezegeni->getTarih(this->varisGezegeni), this->varisGezegeni)+this->mesafe;
	char* varisTarihi= this->varisGezegeni->tariheDonustur(this->varisGezegeni, toplamGecenSure);
    
    return varisTarihi;
}

int kisiSayisiDondur(UzayAraci this)
{
    int kisiSayisi=0;
    for(int i=0; i<this->yolcuSayisi; i++)
    {
        if(this->yolcular[i]->getKalanOmur(this->yolcular[i])>0)
        {
            kisiSayisi++;
        }
    }
    return kisiSayisi;
}
char* durumuDondur(const UzayAraci this)
{

    if(saateDonustur(this, this->cikisTarihi,this->cikisGezegeni)>saateDonustur(this, this->cikisGezegeni->getTarih(this->cikisGezegeni),this->cikisGezegeni))
		{
			this->durum="Bekliyor";
		}
		else
            this->durum="Yolda";
		
		if(this->kalanSaat<=0)
		{
			this->durum="Vardi";
		}
		if(this->kisiSayisiDondur(this)==0)
		{
			this->durum="IMHA";
		}
		//this->durum="Vardi";
        
		return this->durum;
}
void zamaniIlerletArac(const UzayAraci this)
{
    zamanArttir(this->super);

    if(strcmp(this->durumuDondur(this), "Yolda") == 0)
    {

        this->kalanSaat--;
    }

    if(this->kalanSaat<0)
    this->kalanSaat=0;

    // for(int i=0; i<this->yolcuSayisi; i++)
    // {
    //     this->yolcular[i]->azalmaMiktari=this->varisGezegeni->yaslanmaMiktari;

    //     this->yolcular[i]->kalanOmuruAzalt(this->yolcular[i]);
    // }
    
}
void kisiEkle(UzayAraci this, Kisi kisi)
{
    Kisi *temp = realloc(this->yolcular,(this->yolcuSayisi+1)*sizeof(Kisi));
    if(temp== NULL)
    {
        printf("Yolcu eklenemedi\n");
        return;
    }

    this->yolcular = temp;
    this->yolcular[this->yolcuSayisi] = kisi;
    this->yolcuSayisi++;
}


