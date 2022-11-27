/*/* 
* @file ./include/Sayi.hpp
* @description Sayi sınıfının başlık dosyası
* @course 1. öğretim A grubu
* @assignment 1. ödev
* @date 19.11.2022
* @author Sude Çakmak  sude.cakmak1@ogr.sakarya.edu.tr
*/
#ifndef SAYI_HPP
#define SAYI_HPP

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

class Sayi {
public:
	double item;
	Sayi* prev;
	Sayi* next;
	Sayi();
	Sayi(double);
	Sayi(const int, Sayi*, Sayi*);

};

#endif