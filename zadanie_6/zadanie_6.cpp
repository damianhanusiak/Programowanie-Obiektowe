//PO – zadania zadanie_6 <L2> <Damian Hanusiak> <24.11.2021>
#include <iostream>
#define N 6 //N - liczba moich produktów
using namespace std;

class Towar
{
	private:
		string nazwa;
		
	public:	
		Towar(string n) : nazwa(n)
		{
			//cout << "Konstruktor Towar\n";
		}
	
		virtual ~Towar()
		{
			//cout << "Destruktor Towar\n";
		}
	
	 	virtual void Sprzedaj()
		{
			cout << "Nazwa towaru: " << nazwa << "\n";
			cout << "Sprzedaz towaru\n";
		}
};

class Towar_Spozywczy : public Towar
{
	public:
		Towar_Spozywczy(string n) : Towar(n)
		{
			//cout << "Konstruktor Towar_Spozywczy\n";
		}
		
		~Towar_Spozywczy()
		{
			//cout << "Destruktor Towar_Spozywczy\n";
		}
		
		void wypisz_waznosc() //wypisz wa¿noœæ spo¿ycia
		{
			cout << "Sprawdzenie terminu przydatnosci do spozycia\n";
		}
		
		void Sprzedaj()
		{
			Towar::Sprzedaj();
			wypisz_waznosc();
		}
		
};

class Towar_z_Gwarancja : public Towar
{
	public:
		Towar_z_Gwarancja(string n) : Towar(n)
		{
			//cout << "Konstruktor Towar_z_Gwarancja\n";
		}
		
		~Towar_z_Gwarancja()
		{
			//cout << "Destruktor Towar_z_Gwarancja\n";
		}
		
		void wypisz_gwarancje()
		{
			cout << "Podbicie gwarancji\n";
		}
		
		void Sprzedaj()
		{
			Towar::Sprzedaj();
			wypisz_gwarancje();
		}
};

class Koszyk
{
	public:
		Towar *towary[N];
	
		void Dodaj_Towar_do_Koszyka(Towar *wsk, int n)
		{
			towary[n]=wsk;
		}
	
		void Sprzedaj_Zawartosc_Koszyka()
		{
			for(int i=0;i<N;i++)
			{
				cout << "Produkt " << i+1 << ":\n";
				towary[i]->Sprzedaj();
				cout << "\n";
			}
		}
};

int main()
{
	Towar towar_1("Perfumy");
	Towar towar_2("Krem");
	Towar_Spozywczy towar_3("Jajka");
	Towar_Spozywczy towar_4("Sok");
	Towar_z_Gwarancja towar_5("Laptop");
	Towar_z_Gwarancja towar_6("Glosnik");
	
	Koszyk moj_koszyk;
	
	moj_koszyk.Dodaj_Towar_do_Koszyka(&towar_1,0);
	moj_koszyk.Dodaj_Towar_do_Koszyka(&towar_2,1);
	moj_koszyk.Dodaj_Towar_do_Koszyka(&towar_3,2);
	moj_koszyk.Dodaj_Towar_do_Koszyka(&towar_4,3);
	moj_koszyk.Dodaj_Towar_do_Koszyka(&towar_5,4);
	moj_koszyk.Dodaj_Towar_do_Koszyka(&towar_6,5);
	
	moj_koszyk.Sprzedaj_Zawartosc_Koszyka();
	
	return 0;
}


















