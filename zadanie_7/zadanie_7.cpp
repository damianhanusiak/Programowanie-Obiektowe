//PO – zadania zadanie_7 <L2> <Damian Hanusiak> <01.12.2021>
#include <iostream>
#define N 10
using namespace std;

class Figura
{
	public:
		virtual void Rysuj()=0;	
};

class Kwadrat : public Figura
{
	public:
		void Rysuj()
		{
			cout << "Rysuje kwadrat." << "\n";	
		}	
};

class Okrag : public Figura
{
	public:
		void Rysuj()
		{
			cout << "Rysuje okrag." << "\n";
		}
};

class Figury
{
	public:
		Figura *tablica[N]; //tablica wskaznikow
		
		void Dodaj_Figure(Figura *wsk, int n)
		{
			tablica[n]=wsk;	
		}	
		
		void Rysuj()
		{
			for(int i=0;i<N;i++)
			{
				tablica[i]->Rysuj();
			}
		}
};

int main()
{
	Figura *wsk;
	Figury moje_figury;
	
	Kwadrat kwadrat_1;
	wsk = &kwadrat_1;		
	moje_figury.Dodaj_Figure(wsk,0);
	
	Okrag okrag_1;
	wsk = &okrag_1;
	moje_figury.Dodaj_Figure(wsk,1);
	
	Kwadrat kwadrat_2;
	wsk = &kwadrat_2;		
	moje_figury.Dodaj_Figure(wsk,2);
	
	Okrag okrag_2;
	wsk = &okrag_2;
	moje_figury.Dodaj_Figure(wsk,3);
	
	moje_figury.Rysuj();
	
	return 0;
}


















