/*/* 
* @file ./src/Program.cpp
* @description Dosyadan okunan verilerle çift yönlü bağıl liste oluşturur ve bağıl listenin düğümleriyle ilgili işlemler yapar.
* @course 1. öğretim A grubu
* @assignment 1. ödev
* @date 20.11.2022
* @author Sude Çakmak  sude.cakmak1@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"

int main(){

	ifstream dosyaOku("veriler.txt", ios::in);
	string satir = "";
	char bosluk = ' ';
	string number = "";
	YoneticiListesi* yonet = new YoneticiListesi();
	if (dosyaOku.is_open()) {
		cout << "Dosya acildi\n";
		while (getline(dosyaOku, satir))
		{
			cout << "Satir okuma basarili \n";
			SatirlarListesi* ss = new SatirlarListesi();
			for (int i = 0; i < satir.length(); i++) {
				if (satir[i] == bosluk) {
					if (number == "") continue;
					double tmp = stod(number);
					cout << "Double cevirme basarili\n";
					ss->add(tmp);
					cout << "SatirlarListesi ne ekleme basarili \n";
					number = "";
				}
				else number += satir[i];
			}
			if (number != "") {
				double tmp = stod(number);
				cout << "Son okunan degeri double cevirme basarili \n";
				ss->add(tmp);
				cout << "Son okunan degeri list eklendi \n";
				number = "";
			}
			yonet->insert(ss);
			cout << "Yonetici liste ekleme basarili \n";
		}
		dosyaOku.close();
	}
	int indexilk = 0;
	int indexsatir = 0;
	while (true) {
		system("cls");
		yonet->ekran(indexilk, indexsatir);
		char secim;
		cin >> secim;
		switch (secim)
		{
		case('d'):
			if (indexilk + 8 < yonet->length) {
				indexilk += 8;
				indexsatir = indexilk;
			}
			break;
		case('a'):
			indexilk -= 8;
			if (indexilk < 0) indexilk = 0;
			indexsatir = indexilk;
			break;
		case('c'):
			if (indexsatir != yonet->length - 1)
				indexsatir += 1;
			if (indexsatir > indexilk + 7) indexilk = indexsatir;
			break;
		case('z'):
			indexsatir -= 1;
			if (indexsatir < indexilk) indexilk -= 7;
			if (indexilk < 0) indexilk = 0;
			if (indexsatir < 0) indexsatir = 0;
			break;
		case('p'):
			yonet->removeIndex(indexsatir);
			if(indexsatir > yonet->length - 1) indexsatir--;
			if(indexilk > yonet->length - 1) {
				indexilk -=8;
				if(indexilk < 0) indexilk = 0;
			}
			break;
		case('k'):
			int delindex = yonet->selectionRemove(indexsatir);
			system("cls");
			yonet->ekran2(indexilk, indexsatir, delindex);
			char ch;
			cin >> ch;
			if (ch == 'k') {
				SatirlarListesi* dd = yonet->FindPreviousByPosition(indexsatir);
				yonet->ortGoreYaz(delindex, indexsatir, dd);
				if(indexsatir > yonet->length - 1) indexsatir--;
				if(indexilk > yonet->length - 1) {
				indexilk -=8;
				if(indexilk < 0) indexilk = 0;
			}
				system("cls");
				yonet->ekran(indexilk, indexsatir);
			}
			break;
		//default:
			//break;
		}
	}
	delete yonet;
	return 0;
}