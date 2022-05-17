//PO – zadania zadanie_2 <L2> <Damian Hanusiak> <20.10.2021>
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
		
	samochod(double s = 7.5, int pb = 50)
	{
		spalanie = s;
		pojemnosc_baku = pb;
		std::cout << "Kontruktor domyslny (bezparametrowy)\n";
	};

	~samochod()
	{
		std::cout << "Destruktor\n";
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
			std::cout << "Ile litrow paliwa chcesz zatankowac? (Pojemnosc baku: " << pojemnosc_baku << " litrow)\n";
			std::cin >> ilosc_tankowania;
			if(paliwo+ilosc_tankowania<=pojemnosc_baku)
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


int main()
{
	samochod s1;
	int wybor;
	s1.stan=0; //zak³adam na pocz¹tku, ¿e samochód jest wy³¹czony
	s1.paliwo=0; //zak³adam, ¿e pocz¹tkowo nie mam paliwa
	//s1.spalanie=7.5; //spalanie na 100 km
	//s1.pojemnosc_baku=50; 
	s1.przebieg=100000; 
	
	for(;;)
	{
		std::cout << "----------------------------\n";
		std::cout << "OBSLUGA SAMOCHODU:\n";
		std::cout << "----------------------------\n";
		std::cout << "1.Uruchom silnik\n";
		std::cout << "2.Zatrzymaj silnik\n";
		std::cout << "3.Jedz\n";
		std::cout << "4.Tankuj\n";
		std::cout << "5.Prezentuj\n";
		std::cout << "6.Zakoncz program\n";
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
			
			case 6 : std::cout << "Koniec programu!\n";
			exit(1);
			
			default : std::cout << "Brak takiej opcji!\n";
		}
	}
	
	return 0;
}
