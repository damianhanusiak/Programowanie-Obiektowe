//PO – zadania zadanie_4 <L2> <Damian Hanusiak> <03.11.2021>
#include <iostream>

class samochod
{
	public:
		int stan; // 1 - w³¹czony, 0 - wy³¹czony
		double paliwo;
		double spalanie;
		int pojemnosc_baku;
		int przebieg;
		//poni¿ej dodatkowe potrzebne mi zmienne
		double spalone_paliwo;
		double ilosc_tankowania;
		int km;
		double dystans;
		
	//konstruktor domyœlny
	samochod()
	{
		stan=0;
		paliwo=0;
		spalanie=7.5;
		pojemnosc_baku=50;
		przebieg=100000;
		std::cout << "Kontruktor domyslny (bezparametrowy)\n";	
	};
	
	//konstrukor z list¹ inicjalizacyjn¹
	samochod(int st,double pa,double sp,int pb, int pr) : 
	stan(st),paliwo(pa),spalanie(sp),pojemnosc_baku(pb),przebieg(pr)
	{
		std::cout << "Konstruktor samochod\n";	
	};
		
	//konstrukor kopiujacy
	samochod(const samochod& samochod1)
	{
		spalanie = samochod1.spalanie;
		pojemnosc_baku = samochod1.pojemnosc_baku;
		std::cout << "Konstruktor kopiujacy samochod\n";
	};
	
	//destruktor
	~samochod()
	{
		std::cout << "Destruktor samochod\n";
	};
		
		int uruchom_silnik()
		{
			if(paliwo>0 && stan!=1)
			{
				stan=1;
				std::cout << "Wlaczyles swoj samochod!\n";
			}
			else if(stan==1)
			{
				std::cout << "Samochod jest juz wlaczony!\n";
			}
			else
			{
				std::cout << "Brak paliwa!\n";
			}
			
			return stan;
		}
		
		int zatrzymaj_silnik()
		{
			if(stan==1)
			{
				stan=0;
				std::cout << "Wylaczyles swoj samochod!\n";
			}
			else if(stan==0)
			{
				std::cout << "Samochod jest juz wylaczony!\n";
			}
			
			return stan;
		}
		
		void jedz()
		{
			if(paliwo==0)
			{
				std::cout << "Brak paliwa! Zatankuj aby jechac!\n";
			}
			else if(stan==0)
			{
				std::cout << "Samochod jest wylaczony!\n";
			}
			else
			{
				dystans=paliwo*100/spalanie;
				std::cout << "Masz " << paliwo << " litrow paliwa, mozesz przejechac " << dystans << " kilometrow.\n";
				std::cout << "Ile kilometrow chcesz przejechac? ";
				std::cin >> km;
				if(km<dystans)
				{
					przebieg=przebieg+km;
					spalone_paliwo=(km*spalanie)/100;
					paliwo=paliwo-spalone_paliwo;
					std::cout << "Jedziesz " << km << " kilometrow... Spalisz " << spalone_paliwo << " litrow paliwa\n";
				}
				else
				{
					std::cout << "Nie mozesz przejechac takiej odleglosci!\n";
				}
			}
		}
		
		double tankuj()
		{
			std::cout << "Ile litrow paliwa chcesz zatankowac? (Stan paliwa: " << paliwo << "/" << pojemnosc_baku << " litrow)\n";
			std::cin >> ilosc_tankowania;
			if(paliwo+ilosc_tankowania<=pojemnosc_baku && ilosc_tankowania>0)
			{
				std::cout << "Zatankowales " << ilosc_tankowania << " litrow\n";
				paliwo=paliwo+ilosc_tankowania;
			}
			else
			{
				std::cout << "Nie mozesz zatankowac tyle paliwa!\n";
			}
			
			return paliwo;
		}
		
		void prezentuj()
		{
			std::cout << "STAN SAMOCHODU: ";
			if(stan==1)
				std::cout << "wlaczony\n";
			else
				std::cout << "wylaczony\n";
			
			std::cout << "PALIWO: " << paliwo << " litrow \n";
			
			std::cout << "SPALANIE: " << spalanie << " l/100 km\n";
			
			std::cout << "POJEMNOSC BAKU: " << pojemnosc_baku << " litrow \n";
			
			std::cout << "PRZEBIEG: " << przebieg << " km\n";
		}	
};

class samochod_osobowy: public samochod
{
	public:
		int ilosc_miejsc; 
	
	samochod_osobowy(int st,double pa,double sp,int pb, int pr, int im) : 
	samochod(st,pa,sp,pb,pr), ilosc_miejsc(im)
	{
		std::cout << "Konstruktor samochod_osobowy\n";	
	};
	
	samochod_osobowy(const samochod_osobowy& samochod_osobowy1):samochod(samochod_osobowy1)
	{
		ilosc_miejsc=samochod_osobowy1.ilosc_miejsc;
		std::cout << "Konstruktor kopiujacy samochod_osobowy\n";
	}
	
	~samochod_osobowy()
	{
		std::cout << "Destruktor samochod_osobowy\n";
	}
	
	void wypisz_im()//wypisz ilosc miejsc
	{
		std::cout << "ILOSC MIEJSC: " << ilosc_miejsc << "\n";
	}
	
	
	void prezentuj() //tu dodac ilosc miejsc 
	{
		samochod::prezentuj();
		wypisz_im();
	}
	
};

class samochod_ciezarowy: public samochod
{
	public:
		int max_ladownosc;
		int ladunek;
		//dodatkowe zmienne
		double ilosc_ladowania;
		double ilosc_rozladowania;
		
	samochod_ciezarowy(int st,double pa,double sp,int pb,int pr,double ml, double l) :
	samochod(st,pa,sp,pb,pr), max_ladownosc(ml), ladunek(l)
	{
		std::cout << "Konstruktor samochod_ciezarowy\n";
	};
	
	samochod_ciezarowy(const samochod_ciezarowy& samochod_ciezarowy1):samochod(samochod_ciezarowy1)
	{
		max_ladownosc=samochod_ciezarowy1.max_ladownosc;
		ladunek=samochod_ciezarowy1.ladunek;
		std::cout << "Konstruktor kopiujacy samochod_ciezarowy\n";	
	};
	
	~samochod_ciezarowy()
	{
		std::cout << "Destruktor samochod_ciezarowy\n";	
	};
		
	double laduj()
	{
			std::cout << "Ile ton chcesz zaladowac? (Max ladownosc: " << max_ladownosc << " ton(y))\n";
			std::cin >> ilosc_ladowania;
			if(ladunek+ilosc_ladowania<=max_ladownosc && ilosc_ladowania>0)
			{
				std::cout << "Zaladowales " << ilosc_ladowania << " ton(y)\n";
				ladunek=ladunek+ilosc_ladowania;
			}
			else
			{
				std::cout << "Nie mozesz zaladowac tyle ton!\n";
			}
			
			return ladunek;
	}
	
	double rozladuj()
	{
		std::cout << "Ile ton chcesz rozladowac? (Masz zaladowane: " << ladunek << " ton(y))\n";
		std::cin >> ilosc_rozladowania;
		if(ilosc_rozladowania<=ladunek && ilosc_rozladowania>0)
		{
			ladunek=ladunek-ilosc_rozladowania;
			std::cout << "Rozladowales " << ilosc_rozladowania << " ton(y)\n";
			std::cout << "Pozostalo Ci " << ladunek << " ton(y)\n";
		}
		else
		{
			std::cout << "Nie mozesz tyle rozladowac!\n";
		}
		
		return ladunek;
	}
	
	void wypisz_ml() //wypisz max ladownosc
	{
		std::cout << "MAX LADOWNOSC: " << max_ladownosc <<" ton(y)\n";
	}
	
	void wypisz_l() //wypisz ladunek
	{
		std::cout << "LADUNEK: " << ladunek << " ton(y)\n";
	}
	
	void prezentuj() 
	{
		samochod::prezentuj();
		wypisz_ml();
		wypisz_l();
	}	
};


int main()
{
	samochod_osobowy s1(0,0,7.5,50,100000,5);
	samochod_ciezarowy s2(0,0,25.5,550,50000,20,0);
	
	int wybor_samochodu;
	int wybor;
	
	std::cout << "----------------------------\n";
	std::cout << "Wybierz samochod:\n";
	std::cout << "----------------------------\n";
	std::cout << "1.Samochod osobowy.\n";
	std::cout << "2.Samochod ciezarowy.\n";
	std::cin >> wybor_samochodu;
	
	switch(wybor_samochodu)
	{
		case 1 : {
		while(wybor!=0)
		{
			std::cout << "----------------------------\n";
			std::cout << "OBSLUGA SAMOCHODU OSOBOWEGO:\n";
			std::cout << "----------------------------\n";
			std::cout << "1.Uruchom silnik\n";
			std::cout << "2.Zatrzymaj silnik\n";
			std::cout << "3.Jedz\n";
			std::cout << "4.Tankuj\n";
			std::cout << "5.Prezentuj\n";
			std::cout << "0.Zakoncz program\n";
			std::cout << "----------------------------\n";
			std::cin >> wybor;
		
			switch(wybor)
			{
				case 1 : s1.uruchom_silnik();
				break;
			
				case 2 : s1.zatrzymaj_silnik();
				break;
			
				case 3 : s1.jedz();
				break;
			
				case 4 : s1.tankuj();
				break;
			
				case 5 : s1.prezentuj();
				break;
				
				case 0 : std::cout <<"Koniec programu!\n";
				break;
			
				default : std::cout << "Brak takiej opcji!\n";
				break;
			}
		}
		break;
	}
	
		case 2 : {
		while(wybor!=0)
		{
			std::cout << "----------------------------\n";
			std::cout << "OBSLUGA SAMOCHODU CIEZAROWEGO:\n";
			std::cout << "----------------------------\n";
			std::cout << "1.Uruchom silnik\n";
			std::cout << "2.Zatrzymaj silnik\n";
			std::cout << "3.Jedz\n";
			std::cout << "4.Tankuj\n";
			std::cout << "5.Prezentuj\n";
			std::cout << "6.Laduj\n";
			std::cout << "7.Rozladuj\n";
			std::cout << "0.Zakoncz program\n";
			std::cout << "----------------------------\n";
			std::cin >> wybor;
		
			switch(wybor)
			{
				case 1 : s2.uruchom_silnik();
				break;
			
				case 2 : s2.zatrzymaj_silnik();
				break;
			
				case 3 : s2.jedz();
				break;
			
				case 4 : s2.tankuj();
				break;
			
				case 5 : s2.prezentuj();
				break;
				
				case 6 : s2.laduj();
				break;
			
				case 7 : s2.rozladuj();
				break;
				
				case 0 : std::cout <<"Koniec programu!\n";
				break;
			
				default : std::cout << "Brak takiej opcji!\n";
				break;
			}
		}
		break;
	}
		default : std::cout << "Brak takiej opcji!\n";
		break;
	}
	
	return 0;
}
