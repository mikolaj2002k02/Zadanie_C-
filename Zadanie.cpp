//Autor: Marcin Przyby³
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int liczbaRekordow=0;
int rekord, rekord1, rekord2, rekord3;
int main(int argc, char** argv)
{
 ifstream file; //plik wejsciowy
  ifstream file2; //plik wejsciowy
 ifstream file3; //plik wejsciowy
 ofstream fileOut; //plik wynikowy do zapisu
 char* endptr; // to jest wskaŸnik na miejsce, gdzie przy konwersji z systemu czworkowego wyst¹pi b³¹d - nieu¿ywana zmienna
 long liczba,  liczba3, liczba5, max, max2, max3; //liczba dziesietna, minimum z pliku
 string liczba1, liczba2, liczba4, liczba6; //dwie liczby w systemie czworkowym wczytujemy jako "string" bo mog¹ byæ d³u¿sze od long long
 file.open("dane_systemy1.txt"); //otworz plik liczb
 file2.open("dane_systemy2.txt"); //otworz plik liczb
file3.open("dane_systemy3.txt"); //otworz plik liczb

 fileOut.open("wyjscie.txt"); //otworz plik do wynikow
 bool pierwszy = true;  //do algorytmu MINIMUM - zak³adamy, ¿e pierwsza liczba jest najmniejsza z dotychczas przeczytanych
 
 if(file.good())  //sprawdzenie czy plik istnieje
     while(!file.eof())        //petla wykonuje sie az program dojedzie do konca pliku
     {
               file>>liczba1 >> liczba2;   // wczyta dwie liczby z pliku (w wierszu) do 2 stringów
                file2>>liczba3 >> liczba4;   // wczyta dwie liczby z pliku (w wierszu) do 2 stringów
               file3>>liczba5 >> liczba6;   // wczyta dwie liczby z pliku (w wierszu) do 2 stringów

               liczba =  strtol(liczba2.c_str(), &endptr, 2);
               liczba3 =  strtol(liczba4.c_str(), &endptr, 4);
               liczba5 =  strtol(liczba6.c_str(), &endptr, 8);

               //^konwersja z systemu czworkowego do dziesietnego, string (C++) trzeba zamieniæ na char * (C) funkcja .c_str()
               //zmienna endptr wskazuje na znak w stringu, który nie pasuje do systemu czwórkowego - tu niesprawdzone, bo zak³adamy, ¿e dane s¹ poprawne!
               if(pierwszy) //jeœli to pierwsza liczba z pliku - bêdzie nowym MINIMUM
               {
                            max = liczba;
                            pierwszy = false;
               }
               else{
				bool rekord1 = false;
               	if (liczba > max)
               	rekord1 = true;
               	bool rekord2 = false;
               	if (liczba3 > max2)
               	rekord2 = true;
               	bool rekord3 = false;
               	if (liczba5 > max3)
               	rekord3 = true;
			   }
if (rekord1||rekord2||rekord3)
if (rekord) liczbaRekordow++;
			  
//jeœli to kolejna liczba z pliku...
                  if(liczba > max) //... i jest mniejsza od dotychczasowego minimum...
                       max = liczba; // ... to nadpisz min
                        if(liczba3 > max2) //... i jest mniejsza od dotychczasowego minimum...
                       max2 = liczba3;
                        if(liczba5 > max3) //... i jest mniejsza od dotychczasowego minimum...
                       max3 = liczba5;
                     
     }//eof() koniec pliku
 fileOut<< "Pierwszy: " << max <<endl; //zapisanie najmniejszej liczby z pliku czworkowego do pliku wynikowego
fileOut << "Drugi:" << max2 <<"\n";
fileOut << "Trzeci:" << max3 <<"\n";
 file.close();
 file2.close();
file3.close();

 fileOut.close();
 return 0;
}
