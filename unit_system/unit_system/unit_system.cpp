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

	cout << "Light Speed: " << light_speed << endl;
	cout << "1 Light Year = " << convert<kilometer>(light_speed * second(3600 * 24 * 365)) << endl;

	typedef rec_unit<second> herts;

	const herts power_freq(50);

	cout << "The power frequency: " << power_freq << endl;
	cout << "Every period, light goes: " << convert<kilometer>(light_speed / power_freq) << endl;
	cout << "It cost " << height / light_speed << " for light to run " << height << endl;

	return 0;
}

