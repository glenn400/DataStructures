#include <iostream>
using namespace std;

class Ship{
	private:
		string Name;
		string year;;
		public:
			Ship()
			{
				Name = "No se";
				year = "No se";
			}
			Ship(string n, string x)
			{
				Name = n;
				year = x;
			}
			void setName(string nombre)
			{
				Name = nombre;
			}
			void setYear(string anos)
			{
				year = anos;
			}
			string getYear() const
			{
				return year;
			}
			string getName() const
			{
				return Name;
			}
			virtual void displayInfo() const
			{
				cout <<  "The name of the ship is " << getName() << endl;
				cout << "It was built in " << getYear() << endl;
			}
};
class CruiseShip : public Ship{
		private:
		int MaxPass;
		public:
			CruiseShip() : Ship()
			{
				MaxPass = 0.0;
			}
			CruiseShip(int number, string n, string x) : Ship(n,x)
			{
				MaxPass = number;
			}
			void setMax(int Big)
			{
				MaxPass = Big;
			}
			int getMax()
			{
				return MaxPass;
			}
			virtual void displayInfo() const override
			{
				cout << "The name of this cruiseship is " <<  getName() << endl;
				cout << "The maxium amount of passengers is " << MaxPass << endl;
			}
	
};
class CargoShip : public Ship{
	private:
		int Carry;				// Carry capacity in tonage or tons 
	public :
	CargoShip() : Ship()
	{
		Carry = 0.0;
	}
	CargoShip(int C, string n, string x) : Ship(n,x)
	{
		Carry = C;
	}
	void setCapacity(int x)
	{
		Carry = x;
	}
	int getCapacity() const
	{
		return Carry;
	}
	virtual void displayInfo() const override
	{
		cout << "The name of the Cargoship is "<< getName() << endl;
		cout << "The maxium weight of the cargo ship in tons is " << Carry << endl;
	} 
};
void displayThis(const Ship *Obj)
{
	Obj->displayInfo();
}

int main()
{
	int NumBoats = 9;
	Ship *Boats[] = {new Ship("HaHa", "2009"), 
					new CruiseShip(2500, "The Voyage", "1991"), 
					new CargoShip(20,"Crusher", "2002"),
					new Ship("El Diablo", "2015"),
					new CruiseShip(10000,"Halo" , "1913"),
					new CargoShip(200, "BankHead", "1578"),
					new Ship(),
					new CruiseShip(),
					new CargoShip()	
					};
	for (int x = 0; x < NumBoats; x++)
	{
		displayThis(Boats[x]);
	}
	
	

	return 0;
}

