// unit_system.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "units/units.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	using namespace units;

	metre height(1.7);
	kilogram weight(70);
	auto emi = weight / height / height;

	cout << "Height: " << height << endl;
	cout << "  which is: " << convert<centimeter>(height) << endl;
	cout << "Weight: " << weight << endl;
	cout << "   EMI: " << emi << endl;

	const div_unit<metre, second> light_speed(3e8);
	auto energy = weight * light_speed * light_speed;

	cout << "Energy: " << energy << endl;
	
	return 0;
}

