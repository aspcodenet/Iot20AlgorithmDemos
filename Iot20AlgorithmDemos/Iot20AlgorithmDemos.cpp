// Iot20AlgorithmDemos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric> //POWER OF ABSTRACTION. ok tyckte du det var svårt att använda DVD-spelaren?
				//svårt att använda accumulate? Kolla in "kretskortet"

using namespace std;

typedef enum
{
	SIZE_SMALL,
	SIZE_MEDIUM,
	SIZE_LARGE
}SIZE;

class Julklapp
{
private:
	string _till;
	float _value;
	SIZE _size;
	string _sak;

public:
	string GetTillVem()
	{
		return _till;
	}
	SIZE GetSize()
	{
		return _size;
	}
	string GetSak()
	{
		return _sak;
	}

	float GetValue()
	{
		return _value;
	}
	void SetValue(float newValue)
	{
		_value = newValue;
	}


	Julklapp(string till, float value, SIZE size, string sak)
	{
		_till = till;
		_value = value;
		_size = size;
		_sak = sak;
	}
};


void a(int b)
{
	
}


int main()
{
	//// namn = 0x011111432
	//char namn[123] = "Stefan";
	//namn[3] = 'A'; //0x011111432 + (sizeof(char) * 3)


	//list<char> ma;   // ma = håller en påekare till första. 0x231312
	//ma.push_back('S');   //0x231312 - 'S' struct - char ä'S' - åeklare till nästa 0x473829678342
	//ma.push_back('t');  //0x473829678342 - 't' struct - char ä't' - åeklare till nästa 0x432243432
	//ma.push_back('e'); //0x432243432
	//ma.push_back('f');

	//
	//vector<int> ints = { 12,11,44,55 };
	//ints.push_back(66);

	//sort(ints.begin(), ints.end(),std::greater<int>());
	//for(int i: ints)
	//{
	//	cout << i;
	//}


	//

	//int summa = 0;
	//for(int i = 0; i < ints.size();i++)
	//{
	//	summa += ints[i]; //start + sizeof(det som lagras) * index
	//}
	//
	//int sum = accumulate(ints.begin(), ints.end(),0);

	//list<int> intLista = { 12,11,44,55 };
	//intLista.push_back(1111);
	//sum = accumulate(intLista.begin(), intLista.end(), 0);

	////Old way...
	////sum = 0;
	////for(int i = 0 ; i < intLista.size();i++)
	////{
	////	summa += intLista[i];
	////}



	////sum = 0;
	///*for (vector<int>::iterator it = ints.begin(); it != ints.end(); it++) {
	//	sum += *it;
	//}*/

	////
	//////Hello iterators
	////sum = 0;
	////for (list<int>::iterator it = intLista.begin(); it != intLista.end(); it++) {
	////	sum += *it;
	////}

	////goodbuy iterators...eller INTE = detta ÄR samma som ovan - bara syntaktiskt socker
	//sum = 0;
	//for (int i : intLista) {
	//	sum += i;
	//}
	//


	
	vector<Julklapp> julklappar = {
		Julklapp("Stefan", 300, SIZE_SMALL, "Raspberry Pi4"),
		Julklapp("Kerstin", 20, SIZE_SMALL, "Strumpor"),
		Julklapp("Stefan", 100, SIZE_MEDIUM, "Skor"),
		Julklapp("Oliver", 300, SIZE_SMALL, "GTA Online för PC"),
		Julklapp("Stefan", 50, SIZE_SMALL, "Handbok mobil"), //Så han kan lära sig byta signal ;)
		Julklapp("Oliver", 10000, SIZE_LARGE, "Speldator"),
		Julklapp("Oliver", 500, SIZE_SMALL, "GTA Online konto"),
	};


	////INFLATION... Loopa igenom alla och sätt pris till pris * 2
	///   for vs for_each  & vs inte...
	for (Julklapp &julklapp : julklappar) { //  &   *[]£
		julklapp.SetValue(julklapp.GetValue()*2) ;
	}

	for (Julklapp& julklapp : julklappar) { //  &   *[]£
		julklapp.SetValue(julklapp.GetValue() * 2);
	}
	
	for (Julklapp julklapp : julklappar) {
		cout << julklapp.GetTillVem() << " " << julklapp.GetValue() << endl;
	}



	float summan = 0;
	for (Julklapp julklapp : julklappar) {
		summan += julklapp.GetValue();
	}




	for_each(julklappar.begin(), julklappar.end(), [](Julklapp &j)
		{
			j.SetValue(j.GetValue() * 2);
		});

	
	for_each(julklappar.begin(), julklappar.end(), [](Julklapp j)
		{
			cout << j.GetTillVem() << endl;
		});


	


	


	sort(julklappar.begin(), julklappar.end(), [](Julklapp a, Julklapp b) {
		if (a.GetTillVem() == b.GetTillVem()) return a.GetValue() < b.GetValue();
		return a.GetTillVem() < b.GetTillVem();
		});


	//vs for
	//Gör ngt med alla...
	//
	
	
	for (Julklapp julklapp : julklappar) {
		cout << julklapp.GetTillVem();
	}

}