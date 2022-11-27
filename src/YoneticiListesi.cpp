/*/* 
* @file ./src/YoneticiListesi.cpp
* @description YoneticiListesi sınıfının kaynak dosyası
* @course 1. öğretim A grubu
* @assignment 1. ödev
* @date 19.11.2022
* @author Sude Çakmak  sude.cakmak1@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"


YoneticiListesi::YoneticiListesi() {
	length = 0;
}

bool YoneticiListesi::isEmpty()const {
	return length == 0;
}

SatirlarListesi* YoneticiListesi::FindPreviousByPosition(int index) {
	int position = 0;
	SatirlarListesi* itr = head;
	for (; itr != NULL; itr = itr->next, position++) {
		if (position == index) return itr;
	}
	return NULL;
}

int YoneticiListesi::siralama(SatirlarListesi* tmp) {
	SatirlarListesi* itr = head;
	int index = 0;
	for (; itr != NULL; itr = itr->next)
	{
		if (tmp->ort < itr->ort) {
			return index;
		}
		index++;
	}
	return index;
}

void YoneticiListesi::insert(int index, SatirlarListesi* tmp) {
	if (index == 0) {
		tmp->next = head;
		if (head != NULL) head->prev = tmp;
		tmp->prev = NULL;
		head = tmp;
	}
	else {
		SatirlarListesi* prv = FindPreviousByPosition(index - 1);
		tmp->next = prv->next;
		tmp->prev = prv;
		prv->next = tmp;
		if (tmp->next != NULL) tmp->next->prev = tmp;
	}
	length++;
}

void YoneticiListesi::insert(SatirlarListesi* tmp) {
	if (length == 0) {
		head = tmp;
		tmp->prev = NULL;
		tmp->next = NULL;
		length++;
	}
	else {
		int index = siralama(tmp);
		insert(index, tmp);
	}
}

void YoneticiListesi::remove(SatirlarListesi* del) {
	if (del == head) {
		del->next->prev = NULL;
		head = del->next;
	}
	else {
		if (del->next != NULL) del->next->prev = del->prev;
		del->prev->next = del->next;
	}
	length--;
	delete del;
}

void YoneticiListesi::removeIndex(int index) {
	SatirlarListesi* del = FindPreviousByPosition(index);
	remove(del);
}

int YoneticiListesi::selectionRemove(int index) {
	SatirlarListesi* dd = FindPreviousByPosition(index);
	int del = dd->selectionRandom();
	return del;
}

void YoneticiListesi::adresiniYaz(SatirlarListesi* ilk, SatirlarListesi* son) {
	for (; ilk != son; ilk = ilk->next) {
		cout << setw(12) << ilk << " ";
	}
	cout << setw(12) << son << endl;
}

void YoneticiListesi::prvYaz(SatirlarListesi* ilk, SatirlarListesi* son) {
	for (; ilk != son; ilk = ilk->next) {
		cout << "|" << setw(10) << ilk->prev << "|" << " ";
	}
	cout << "|" << setw(10) << son->prev << "|" << endl;
}

void YoneticiListesi::nxtYaz(SatirlarListesi* ilk, SatirlarListesi* son) {
	for (; ilk != son; ilk = ilk->next) {
		cout << "|" << setw(10) << ilk->next << "|" << " ";
	}
	cout << "|" << setw(10) << son->next << "|" << endl;
}

void YoneticiListesi::ortYaz(SatirlarListesi* ilk, SatirlarListesi* son) {
	for (; ilk != son; ilk = ilk->next) {
		cout << "|" << setw(10) << ilk->ort << "| ";
	}
	cout << "|" << setw(10) << son->ort << "|" << endl;
}

void YoneticiListesi::cizgiCiz(int adet) {
	for (int i = 0; i < adet - 1; i++) {
		cout << "------------ ";
	}
	cout << "------------" << endl;
}

void YoneticiListesi::usIsareti() {
	cout << "^^^^^^^^^^^^" << endl;
}

void YoneticiListesi::boslukGit(int index) {
	for (int i = 0; i < index; i++) {
		cout << setw(13) << " ";
	}
}

void YoneticiListesi::satirListesiYaz(int index) {
	SatirlarListesi* tmp = FindPreviousByPosition(index);
	int satir = index % 8;
	boslukGit(satir);
	usIsareti();
	for (Sayi* itr = tmp->head; itr != NULL; itr = itr->next) {
		boslukGit(satir);
		cout << "|" << setw(10) << itr << "|" << endl;
		boslukGit(satir);
		cizgiCiz(1);
		boslukGit(satir);
		cout << "|" << setw(10) << itr->item << "|" << endl;
		boslukGit(satir);
		cizgiCiz(1);
		boslukGit(satir);
		cout << "|" << setw(10) << itr->next << "|" << endl;
		boslukGit(satir);
		cizgiCiz(1);
		cout << endl;
	}
}

void YoneticiListesi::ilkYaz() {
	cout << setw(12) << left << "ilk";
	cout << right;
}

void YoneticiListesi::solaDayaliOk() {
	cout << setw(12) << left << "<---";
	cout << right;
}

void YoneticiListesi::sagaDayaliOk(int index) {
	boslukGit(index - 1);
	cout << setw(12) << "--->" << endl;
}

void YoneticiListesi::sonYaz(int index) {
	boslukGit(index - 1);
	cout << setw(12) << "son" << endl;
}

void YoneticiListesi::yoneticiListYaz(int indexilk = 0) {
	int indexson = indexilk + 7;
	if (indexson > length - 1) indexson = length - 1;
	int fark = indexson - indexilk;
	if(fark == 0){ 
		if(indexilk == 0) ilkYaz();
		else sonYaz(fark);
	}
	else {
	if (indexilk == 0) ilkYaz();
	else solaDayaliOk();
	if (indexson == length - 1) sonYaz(fark);
	else sagaDayaliOk(fark);
	}
	SatirlarListesi* ilk = FindPreviousByPosition(indexilk);
	SatirlarListesi* son = FindPreviousByPosition(indexson);
	adresiniYaz(ilk, son);
	cizgiCiz(fark+1);
	prvYaz(ilk, son);
	cizgiCiz(fark+1);
	ortYaz(ilk, son);
	cizgiCiz(fark+1);
	nxtYaz(ilk, son);
	cizgiCiz(fark+1);
}

void YoneticiListesi::silinecekSayiYaz(int index, int delindex) {
	SatirlarListesi* tmp = FindPreviousByPosition(index);
	Sayi* del = tmp->FindPreviousByPosition(delindex);
	int satir = index % 8;
	boslukGit(satir);
	usIsareti();
	for (Sayi* itr = tmp->head; itr != NULL; itr = itr->next) {
		boslukGit(satir);
		cout << "|" << setw(10) << itr << "|" << endl;
		boslukGit(satir);
		cizgiCiz(1);
		boslukGit(satir);
		cout << "|" << setw(10) << itr->item << "|" << endl;
		boslukGit(satir);
		if (itr == del) {
			cout << "------------  " << "<---- silinecek secili" << endl;
		}
		else  cizgiCiz(1);
		boslukGit(satir);
		cout << "|" << setw(10) << itr->next << "|" << endl;
		boslukGit(satir);
		cizgiCiz(1);
		cout << endl;
	}
}

void YoneticiListesi::ortGoreYaz(int delindex,int indexsatir, SatirlarListesi* dd){
	dd->removeAt(delindex);
	if(dd->isEmpty()) remove(dd);
	else{
		int kontrol = siralama(dd);
		if (kontrol != indexsatir) {
			SatirlarListesi* tmp = FindPreviousByPosition(kontrol);
			if (dd->next != NULL) dd->next->prev = dd->prev;
			if (dd->prev != NULL) dd->prev->next = dd->next;
			dd->next = tmp;
			if (tmp->prev != NULL) tmp->prev->next = dd;
			dd->prev = tmp->prev;
			tmp->prev = dd;
			if(dd->prev == NULL) head = dd;
		}
	}
}

void YoneticiListesi::ekran(int indexilk = 0, int indexsatir = 0) {
	yoneticiListYaz(indexilk);
	satirListesiYaz(indexsatir);
}

void YoneticiListesi::ekran2(int indexilk , int indexsatir, int delindex){
	yoneticiListYaz(indexilk);
	silinecekSayiYaz(indexsatir, delindex);		
}

YoneticiListesi::~YoneticiListesi(){
	while(head != NULL) {
		SatirlarListesi* del = head;
		if(del->next != NULL ) {
			del->next->prev = NULL;
			head = del->next;
		}
		delete del;
	}
}

