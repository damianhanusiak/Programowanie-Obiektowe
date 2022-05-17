//PO – zadania zadanie_9 <L2> <Damian Hanusiak> <15.12.2021>
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T,int POJEMNOSC>
class Kolejka
{
	T kolejka[POJEMNOSC];
	int ostatni;

	public:
		Kolejka():ostatni(-1){};
		void wloz(T const& t);
		T zdejmij();
};

template<typename T,int POJEMNOSC>
void Kolejka<T,POJEMNOSC>::wloz(T const& t)
{
  if(ostatni<POJEMNOSC-1) kolejka[++ostatni]=t;
  else throw std::out_of_range("B£¥D: Kolejka przepelniona!"); 
}

template<typename T,int POJEMNOSC>
T Kolejka<T,POJEMNOSC>::zdejmij()
{
  if(ostatni>=0)
  {
  	T pierwszy=kolejka[0];
  	for(int i=0;i<ostatni;i++)
  	{
	  kolejka[i] = kolejka[i+1];	
	}
	ostatni--;
	return pierwszy;
  }
  else throw std::out_of_range("B£¥D: Kolejka pusta!");
}

int main()
{	
	cout << "KOLEJKA 1(int):" << endl;
	Kolejka<int,10> k;
	k.wloz(1);
	k.wloz(2);
	k.wloz(3);
	k.wloz(4);
	cout << "Zdejmuje: " << k.zdejmij() << endl;
	cout << "Zdejmuje: " << k.zdejmij() << endl;
	cout << "Zdejmuje: " << k.zdejmij() << endl;
	cout << "Zdejmuje: " << k.zdejmij() << endl;
	
	cout << "KOLEJKA 2(double):" << endl;
	Kolejka<double,10> k1;
	k1.wloz(1.1);
	k1.wloz(2.2);
	k1.wloz(3.3);
	k1.wloz(4.4);
	cout << "Zdejmuje: " << k1.zdejmij() << endl;
	cout << "Zdejmuje: " << k1.zdejmij() << endl;
	cout << "Zdejmuje: " << k1.zdejmij() << endl;
	cout << "Zdejmuje: " << k1.zdejmij() << endl;
	
	return 0;
}
