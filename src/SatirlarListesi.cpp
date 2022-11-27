/*/* 
* @file ./src/SatirlarListesi.cpp
* @description SatirlarListesi sınıfının kaynak dosyası
* @course 1. öğretim A grubu
* @assignment 1. ödev
* @date 19.11.2022
* @author Sude Çakmak  sude.cakmak1@ogr.sakarya.edu.tr
*/
#include "SatirlarListesi.hpp"

SatirlarListesi::SatirlarListesi() {
	length = 0;
	toplam = 0;
	ort = 0;
}

SatirlarListesi::SatirlarListesi(const int data) {
	this->head = new Sayi();
	head->prev = NULL;
	head->next = NULL;
	head->item = data;
	length = 1;
	toplam = data;
	ort = toplam / length;
}

void SatirlarListesi::ortHesapla() {
	ort = toplam / length;
}

Sayi* SatirlarListesi::FindPreviousByPosition(int index) {
	int position = 0;
	Sayi* itr = head;
	for (; itr != NULL; itr = itr->next, position++) {
		if (position == index) return itr;
	}
	return NULL;
}

bool SatirlarListesi::isEmpty()const {
	return length == 0;
}

void SatirlarListesi::add(double data) {
	if (length == 0) {
		Sayi* p = new Sayi(data, NULL, NULL);
		head = p;
		length++;
		toplam = toplam + data;
		ortHesapla();
	}
	else {
		Sayi* itr = FindPreviousByPosition(length - 1);
		Sayi* p = new Sayi(data, NULL, itr);
		itr->next = p;
		length++;
		toplam = toplam + data;
		ortHesapla();
	}
}

void SatirlarListesi::remove(Sayi* del) {
	if (del == head) {
		del->next->prev = NULL;
		head = del->next;
	}
	else {
		if (del->next != NULL) del->next->prev = del->prev;
		del->prev->next = del->next;
	}
	length--;
	toplam = toplam - del->item;
	ortHesapla();
	delete del;
}

void SatirlarListesi::removeAt(int index) {
	Sayi* del;
	if (index == 0) {
		del = head;
		head = head->next;
		if (head != NULL) head->prev = NULL;
	}
	else {
		Sayi* prv = FindPreviousByPosition(index);
		del = prv;
		del->prev->next = del->next;
		if (del->next != NULL)
			del->next->prev = del->prev;
	}
	length--;
	toplam = toplam - del->item;
	ortHesapla();
	delete del;
}

void SatirlarListesi::clear() {
	while (head != NULL) {
		removeAt(0);
	}
}

int SatirlarListesi::selectionRandom() {
	srand(time(0));
	int index = rand() % length;
	return index;
}

SatirlarListesi::~SatirlarListesi(){
	clear();
}