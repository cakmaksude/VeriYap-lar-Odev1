/*/* 
* @file ./src/Sayi.cpp
* @description Sayi sınıfının kaynak dosyası
* @course 1. öğretim A grubu
* @assignment 1. ödev
* @date 19.11.2022
* @author Sude Çakmak  sude.cakmak1@ogr.sakarya.edu.tr
*/
#include "Sayi.hpp"

Sayi::Sayi() {
	this->item = 0;
	this->prev = NULL;
	this->next = NULL;
}

Sayi::Sayi(double data) {
	item = data;
}

Sayi::Sayi(const int item, Sayi* nx, Sayi* prv) {
	this->item = item;
	this->next = nx;
	this->prev = prv;
}
