/*#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Teren {

private:
	bool intravilan;
	int latimeTeren;
	int lungimeTeren;
	char* adresa;
	//retine numarul terenurilor create
	static int nrTerenuri;
	const int idTeren;

public:

	Teren() :idTeren(++nrTerenuri) {

		this->intravilan = 0;
		this->latimeTeren = 0;
		this->lungimeTeren = 0;
		this->adresa = new char[strlen("Necunoscut") + 1];
		strcpy(this->adresa, "Necunoscut");
	}

	Teren(bool intravilan, int latimeTeren, int lungimeTeren, const char* adresa) : idTeren(++nrTerenuri) {

		if (latimeTeren > 0 && lungimeTeren > 0)
		{
			this->latimeTeren = latimeTeren;
			this->lungimeTeren = lungimeTeren;
			this->intravilan = intravilan;
			if (adresa != nullptr)
			{
				this->adresa = new char[strlen(adresa) + 1];
				strcpy(this->adresa, adresa);
			}
		}

	}
	~Teren() {

		if (this->adresa != nullptr)
			delete[] this->adresa;
	}

	Teren(const Teren& t) :idTeren(++nrTerenuri) {

		this->intravilan = t.intravilan;
		this->latimeTeren = t.latimeTeren;
		this->lungimeTeren = t.lungimeTeren;
		this->adresa = new char[strlen(t.adresa) + 1];
		strcpy(this->adresa, t.adresa);
	}

	friend ostream& operator<< (ostream& out, const Teren& t) {

		out << "Teren intravilian: Da/Nu:" << t.intravilan << ", ";
		out << "Latimea terenului este de:" << t.latimeTeren << ", ";
		out << "Lungimea terenului este de: " << t.lungimeTeren << ", ";
		out << "Adresa terenului este: " << t.adresa << endl;

		return out;
	}

	int getlatimeTeren() {

		return this->latimeTeren;
	}

	char* getadresa() {

		return this->adresa;
	}

	void setlatimeTeren(int latime) {

		if (latime > 0)
			this->latimeTeren = latime;
	}

	void setadresa(const char* a) {

		if (a != nullptr)
		{
			delete[]this->adresa;
			this->adresa = new char[strlen(a) + 1];
			strcpy(this->adresa, a);
		}
		else
			throw exception();
	}


	int getArie() {

		int arie = this->latimeTeren * this->lungimeTeren;
		return arie;
	}

	bool operator>(Teren& t) const {

		return this->latimeTeren * this->lungimeTeren > t.latimeTeren * t.lungimeTeren;
	}

	bool operator!() const {

		if (this->intravilan)
			return this->intravilan;

	}
};
int Teren::nrTerenuri = 0;
int main()
{
	Teren t1;
	Teren t2(1, 30, 40, "Banu Manta 16");
	cout << t2;
	Teren t3 = t2;
	cout << t3;

	cout << "Latime teren 3:" << t3.getlatimeTeren() << endl;
	cout << "Adresa teren 3:" << t3.getadresa() << endl;
	t3.setlatimeTeren(50);
	t3.setadresa("Tudor Vladimirescu 19");
	cout << t3;
	if (t2 > t3)
		cout << "aria t2 mai mare" << endl;
	else
		cout << "aria t3 mai mare" << endl;
	return 0;
}*/