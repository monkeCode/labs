#pragma once
#include <string>
#include <exception>
class computer {
public:
	static double defaultTimeToBoot;
	computer(double timeToBoot = defaultTimeToBoot) :baseTimeToBoot(defaultTimeToBoot) {}
	double get_time_to_boot()
	{
		return baseTimeToBoot;
	}
private:
	double baseTimeToBoot;
};

class vehicle
{
private:
	std::string name = defaultName;
	double baseSpeed = defaultSpeed;
protected:
	double totalTime = 0;
	double totalDistance = 0;
	vehicle(std::string name, double speed)
	{
		this->name = name;
		baseSpeed = speed;
	}
public:
	static std::string defaultName;
	static double defaultSpeed;
	std::string get_name()
	{
		return name;
	}
	double get_base_speed()
	{
		return baseSpeed;
	}
	double get_total_distance()
	{
		return totalDistance;
	}
	double get_total_time()
	{
		return totalTime;
	}
	virtual bool make_trip(double distance) = 0;
	virtual double get_speed() = 0;

	bool operator< (vehicle& rhs)
	{
		if (get_speed() < rhs.get_speed()) {
			return true;
		}
		return false;
	}
	bool operator> (vehicle& rhs)
	{
		if (get_speed() > rhs.get_speed()) {
			return true;
		}
		return false;
	}

};


class coach : public vehicle
{
private:
	static const double MAX_DISTANCE;

public:
	static std::string defaultName;
	static double defaultSpeed;
	coach(std::string name = defaultName, double speed = defaultSpeed) : vehicle(name, speed) {}
	bool make_trip(double distance) override
	{/*
		double startDistance = totalDistance;
		while (startDistance < distance + totalDistance && startDistance < MAX_DISTANCE)
		{
			startDistance += 1;
			totalTime += 1 / get_speed();
		}
		totalDistance = startDistance;
		return startDistance < MAX_DISTANCE;*/
		bool deterministicTrip = true;
		if (distance + totalDistance > MAX_DISTANCE)
		{
			distance = MAX_DISTANCE - totalDistance;
			deterministicTrip = false;
		}
		totalDistance += distance;
		totalTime += distance / get_speed();
		return deterministicTrip;
	}
	double get_speed() override
	{
		return get_base_speed() * exp(-totalTime / 500);
	}
};
const double coach::MAX_DISTANCE = 1000;
class automobile :public vehicle
{
public:
	static std::string defaultName;
	static double defaultSpeed;
	automobile(std::string name = defaultName, double speed = defaultSpeed) :vehicle(name, speed) {}
	bool make_trip(double distance) override
	{
		/*double startDistance = totalDistance;
		while (startDistance < distance + totalDistance)
		{
			startDistance += 1;
			totalTime += 1 / get_speed();
		}
		totalDistance = startDistance;*/

		totalDistance += distance;
		totalTime += distance / get_speed();
		return 1;
	}
	double get_speed() override
	{
		return get_base_speed() * exp(-totalTime / 500);
	}

};
class aeroplane : public vehicle
{
private:
	static double maxFlyTime;
	double timeSinceLastRepair = 0;
	computer bortComputer = computer();
public:
	static std::string defaultName;
	static double defaultSpeed;
	aeroplane(std::string name = defaultName, double speed = defaultSpeed) :vehicle(name, speed) {}
	bool make_trip(double distance) override
	{
		double timeOfTrip = distance / get_speed() + bortComputer.get_time_to_boot();
		if (timeSinceLastRepair + timeOfTrip > maxFlyTime) {
			return false;
		}
		timeSinceLastRepair += timeOfTrip;
		totalDistance += distance;
		totalTime += timeOfTrip;
		return true;
	}
	double get_speed() override { return get_base_speed(); }
	static void set_max_fly_time(double time)
	{
		maxFlyTime = time;
	}
	void repair() {
		timeSinceLastRepair = 0;
	}
	double get_time_since_last_repair() const {
		return timeSinceLastRepair;
	}
	void update_computer(double newTimeToBoot)
	{
		bortComputer = computer(newTimeToBoot);
	}
};
double aeroplane::maxFlyTime = 1000;
class ITank
{
public:
	void virtual refuel(double fuel) = 0;
	double virtual getCurrentFuel() = 0;
};
class fuel_tank:ITank
{
private:
	double maxFuel;
	double currentFuel;
public:
	void refuel(double fuel) override
	{
		if (currentFuel + fuel < 0)
			throw std::exception("not enough fuel");
		currentFuel += (currentFuel + fuel) > maxFuel ? maxFuel - currentFuel : fuel;
	}
	fuel_tank(double maxFuel = 100) :maxFuel(maxFuel), currentFuel(maxFuel){}
	double getCurrentFuel() override
	{
		return currentFuel;
	}
};

class accumulator :public ITank
{
private:
	int countOfRecharges;
	double maxCharge;
	double currentCharge;
public:
	void refuel(double fuel) override
	{
		if (countOfRecharges <= 0)
			throw std::exception("the battery is broken");
		if (currentCharge + fuel < 0)
			throw std::exception("not enough fuel");
		currentCharge += (currentCharge + fuel) > maxCharge ? maxCharge - currentCharge : fuel;
		countOfRecharges--;

	}
	accumulator(double maxCharge, int countOfRechagres = 300)
	{
		this->maxCharge = maxCharge;
		currentCharge = (rand() % 40 + 60) / 100. * maxCharge;
		this->countOfRecharges = countOfRechagres; //+ (rand() % (int)(countOfRechagres*0.15) - (int)(countOfRechagres * 0.1));
	}
	double getCurrentFuel() override
	{
		return currentCharge;
	}
};
class fuel_car:public automobile
{
protected:
	ITank* tank;
	double fuelWaste;
public:
	fuel_car(std::string name, double speed, ITank* tank, double fuelWaste):automobile(name,speed), tank(tank),fuelWaste(fuelWaste) {}
	bool virtual make_trip(double distance) override
	{
		bool deterministicTrip = true;
		if (distance > get_current_fuel() / fuelWaste)
		{
			distance = get_current_fuel() / fuelWaste;
			deterministicTrip = false;
		}
		automobile::make_trip(distance);
		refuel_car(-distance * fuelWaste);
		return deterministicTrip;
	}
	void refuel_car(double fuel)
	{
		tank->refuel(fuel);
	}
	double get_current_fuel()
	{
		return tank->getCurrentFuel();
	}
};
class petrol_car :public fuel_car
{
public:
	petrol_car(std::string name = "default petrol car", double speed = defaultSpeed, fuel_tank* tank = &fuel_tank(), double litresPerK = 1) :
		fuel_car(name, speed, (ITank*)tank,litresPerK) {}
};
class electric_car :public fuel_car
{
public:
	electric_car(std::string name = "default electric car", double speed = defaultSpeed, accumulator* tank = &accumulator(100), double energyWaste = 1) :
		fuel_car(name, speed, (ITank*)tank, energyWaste) {}
	accumulator* change_accumulator(accumulator* ac)
	{
		ITank* temp = tank;
		tank = ac;
		return (accumulator*)temp;
	}
};

double computer::defaultTimeToBoot = 4;
double vehicle::defaultSpeed = -1;
std::string vehicle::defaultName = "untyped vehicle";
std::string coach::defaultName = "default coach name";
double coach::defaultSpeed = 10;
std::string automobile::defaultName = "default automobile name";
double automobile::defaultSpeed = 100;
std::string aeroplane::defaultName = "default aeroplane name";
double aeroplane::defaultSpeed = 500;