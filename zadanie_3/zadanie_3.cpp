#include <iostream>
using namespace std;

class trojkat
{
	public:
		int x;
		int y;
		int z;
		///x,y,z - boki trojkata
	
	trojkat()
	{
		x=1;
		y=2;
		z=3;
		cout << "Konstruktor domyslny (bezparametrowy).\n";
	}
	
	trojkat(int xp, int yp, int zp)
	{
		x=xp;
		y=yp;
		z=zp;
		cout << "Konstruktor wieloargumentowy.\n"; 
	};
	
	trojkat(int xp) : x(xp+10), y(50), z(70)
	{
		cout << "Konstruktor z lista inicjalizacyjna.\n";
	}
	
	trojkat(const trojkat& trojkat2)
	{
		x=trojkat2.x;
		y=trojkat2.y;
		z=trojkat2.z;
		cout << "Konstruktor kopiujacy.\n";
	}
	
	~trojkat()
	{
		cout << "Destruktor.\n";
	};
};

int main()
{
	//przedstawienie konstruktora domyslnego
	trojkat a1;
	cout << "x = " << a1.x << '\n';
	cout << "y = " << a1.y << '\n';
	cout << "z = " << a1.z << '\n';
	
	//przedstawienie konstruktora wieloargumentowego
	trojkat a2(10,20,30);
	cout << "x = " << a2.x << '\n';
	cout << "y - " << a2.y << '\n';
	cout << "z - " << a2.z << '\n';
	
	//przedstawienie konstruktora z lista inicjalizacyjna
	trojkat a3(30);
	cout << "x = " << a3.x << '\n';
	cout << "y = " << a3.y << '\n';
	cout << "z = " << a3.z << '\n';
	
	//przedstawienie konstruktora kopiujacego
	trojkat a4(a1);
	cout << "x = " << a4.x << '\n';
	cout << "y = " << a4.y << '\n';
	cout << "z = " << a4.z << '\n';
	

	return 0;
}
