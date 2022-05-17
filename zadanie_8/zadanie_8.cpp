//PO – zadania zadanie_8 <L2> <Damian Hanusiak> <08.12.2021>
#include <iostream>
using namespace std;

class interval
{
	private:
		double left;
		double right;
	
	public:
		interval()
		{
			left = 3;
			right = 3;
			//cout << "Kontruktor domyslny (bezparametrowy) interval\n";
		};
		
		interval(double l, double r) : left(l),right(r)
		{
			//cout << "Konstruktor z lista inicjalizacyjna interval\n";
		};
		
		~interval()
		{
			//cout << "Destruktor interval\n";
		};
		
		double return_left()
		{
			cout << "Lewy koniec przedzialu: ";
			return left;
		}
		
		double return_right()
		{
			cout << "Prawy koniec przedzialu: ";
			return right;
		}
		
		double return_medium()
		{
			cout << "Srodek przedzialu: ";
			return (left+right)/2.0;
		}
		
		double return_length()
		{
			cout << "Dlugosc przedzialu: ";
			return right-left+1;
		}
		
		friend interval operator-(const interval& x); //operator jednoargumentowy (-[a,b]=[-a,-b]
    	friend interval operator+(const interval& x1, const interval& x2);	//operator [a,b]+[c,d]=[a+c,b+d]
    	friend interval operator-(const interval& x1, const interval& x2);	//operator [a,b]-[c,d]=[a-c,b-d]
    	friend interval operator*(const interval& x, const int s);	//operator [a,b]*s
		friend interval operator*(const int s, const interval& x); //operator s*[a,b]
    	friend interval operator*(const interval& x1, const interval& x2);	//operator [a,b]*[c,d]
    	friend interval operator/(const interval& x1, const interval& x2); //operator [a,b]/[c,d]
    	friend ostream& operator<<(ostream& out,const interval& x);
};

interval operator-(const interval& x)
{
	interval wynik;
	wynik.left=-x.left;
	wynik.right=-x.right;
	return wynik;
}

interval operator+(const interval& x1,const interval& x2)
{
	interval wynik;
	wynik.left=x1.left+x2.left;
	wynik.right=x1.right+x2.right;
	return wynik;
}

interval operator-(const interval& x1,const interval& x2)
{
	interval wynik;
	wynik.left=x1.left-x2.left;
	wynik.right=x1.right-x2.right;
	return wynik;
}

interval operator*(const interval& x,const int s)
{
	interval wynik;
	wynik.left=x.left*s;
	wynik.right=x.right*s;
	return wynik;
}

interval operator*(const int s,const interval& x)
{
	interval wynik;
	wynik.left=s*x.left;
	wynik.right=s*x.right;
	return wynik;
}

interval operator*(const interval& x1,const interval& x2)
{
	interval wynik;
	wynik.left=x1.left*x2.left;
	wynik.right=x1.right*x2.right;
	return wynik;
}

interval operator/(const interval& x1, const interval& x2)
{
	interval wynik;
	wynik.left=x1.left/x2.left;
	wynik.right=x1.right/x2.right;
	return wynik;
}

ostream& operator<<(ostream& out,const interval& x)
{
  out << "[" << x.left << "," << x.right << "]";
  return out;
}


int main()
{
	interval przedzial_1;	//przedzia³ o d³ugoœci 0 [left=right] = [3,3]
	interval przedzial_2(2,6);	//przedzia³ o d³ugoœci >0 [left<=right] =  [2,6]
	
	cout << "PRZEDZIAL 1 = " << przedzial_1 << "\n";
	cout << przedzial_1.return_left() <<"\n";
	cout << przedzial_1.return_right() <<"\n";
	cout << przedzial_1.return_medium() <<"\n";
	cout << przedzial_1.return_length() <<"\n\n";
	
	cout << "PRZEDZIAL 2 = " << przedzial_2 << "\n";
	cout << przedzial_2.return_left() <<"\n";
	cout << przedzial_2.return_right() <<"\n";
	cout << przedzial_2.return_medium() <<"\n";
	cout << przedzial_2.return_length() <<"\n\n";
	
	cout << "Operator - jednoargumentowy:\n";
	cout <<-przedzial_1 << "\n";
	cout <<-przedzial_2 << "\n\n";
	
	cout << "Operator +:\n";
	cout << przedzial_1 << "+" << przedzial_2 << "=" << przedzial_1 + przedzial_2 << "\n\n";
	
	cout << "Operator -:\n";
	cout << przedzial_1 << "-" << przedzial_2 << "=" << przedzial_1 - przedzial_2 << "\n\n";
	
	cout << "Operator * przez liczbe s \"z obu stron\":\n";
	cout << przedzial_1 << "*2=" << przedzial_1*2 << "\n";
	cout << przedzial_2 << "*3=" << przedzial_2*3 << "\n";
	cout << "4*" << przedzial_1 << "=" << 4*przedzial_1 <<"\n";
	cout << "5*" << przedzial_2 << "=" << 5*przedzial_2 <<"\n\n";
	
	cout << "Operator *:\n";
	cout << przedzial_1 << "*" << przedzial_2 << "=" <<przedzial_1*przedzial_2 << "\n\n";
	
	cout << "Operator /:\n";
	cout << przedzial_1 << "/" << przedzial_2 << "=" <<przedzial_1/przedzial_2 << "\n\n";
	
	cout << "Operator << wypisujacy przedzial w formie [left,right]:\n";
	cout << przedzial_1 << "\n";
	cout << przedzial_2 << "\n";
	
	return 0;
}

