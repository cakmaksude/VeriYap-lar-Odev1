/*/* 
* @file ./include/YoneticiListesi.hpp
* @description YoneticiListesi sınıfının başlık dosyası
* @course 1. öğretim A grubu
* @assignment 1. ödev
* @date 19.11.2022
* @author Sude Çakmak  sude.cakmak1@ogr.sakarya.edu.tr
*/

#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include "SatirlarListesi.hpp"

class YoneticiListesi {
private:
	SatirlarListesi* head;
	bool isEmpty()const;
	int siralama(SatirlarListesi* );
	void insert(int, SatirlarListesi*);
	void remove(SatirlarListesi*);
	void adresiniYaz(SatirlarListesi*, SatirlarListesi*);
	void prvYaz(SatirlarListesi*, SatirlarListesi*);
	void nxtYaz(SatirlarListesi*, SatirlarListesi*);
	void ortYaz(SatirlarListesi*, SatirlarListesi*);
	void cizgiCiz(int);
	void usIsareti();
	void boslukGit(int);	
	void satirListesiYaz(int);
	void ilkYaz();
	void solaDayaliOk();
	void sagaDayaliOk(int);
	void sonYaz(int);
	void yoneticiListYaz(int);
	void silinecekSayiYaz(int, int);
	
public:
	int length;
	YoneticiListesi();
	SatirlarListesi* FindPreviousByPosition(int);
	void insert(SatirlarListesi*);
	void removeIndex(int);
	int selectionRemove(int);
	void ortGoreYaz(int, int, SatirlarListesi*);
	void ekran(int, int);
	void ekran2(int, int, int);
	~YoneticiListesi();
		
};


#endif