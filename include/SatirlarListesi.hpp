/*/* 
* @file ./include/SatirlarListesi.hpp
* @description SatirlarListesi sınıfının başlık dosyası
* @course 1. öğretim A grubu
* @assignment 1. ödev
* @date 19.11.2022
* @author Sude Çakmak  sude.cakmak1@ogr.sakarya.edu.tr
*/
#ifndef SATIRLARLISTESI_HPP
#define SATIRLARLISTESI_HPP

#include "Sayi.hpp"

class SatirlarListesi {
private:
	void ortHesapla();
	void clear();
public:
	SatirlarListesi* prev;
	SatirlarListesi* next;
	Sayi* head;
	double toplam;
	int length;
	double ort;
	SatirlarListesi();
	SatirlarListesi(const int);
	Sayi* FindPreviousByPosition(int);
	bool isEmpty()const ;
	void add(double);
	void remove(Sayi*);
	void removeAt(int);
	int selectionRandom();
	~SatirlarListesi();

};


#endif