#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>
#include <functional>
#include <vector>
#include<regex>
#include"lab1.h"
//lab 1


void commit_random_trips(std::vector<vehicle*>& vehicles) 
{
	for (int i = 0; i < vehicles.size(); ++i) {
		double randomDistance = double(rand() % 20001) / 10.;
		vehicles[i]->make_trip(randomDistance);
	}
}
void output_vehicle(std::vector<vehicle*> v)
{
	std::cout << "Name\tSpeed\tDist\tTime\n";
	for (auto veh : v)
	{
		std::cout << veh->get_name() << '\t' << veh->get_speed() << '\t' << veh->get_total_distance() << '\t' << veh->get_total_time() << std::endl;
	}
}
int main()
{
	/*srand(time(0));
	std::vector<vehicle*> vehicles = std::vector<vehicle*>();
	coach c = coach("test", 5);
	automobile a = automobile("auto", 300);
	aeroplane plane = aeroplane("boing", 1000);
	vehicles.push_back(&c);
	vehicles.push_back(&a);
	vehicles.push_back(&plane);
	commit_random_trips(vehicles);
	output_vehicle(vehicles);*/
}