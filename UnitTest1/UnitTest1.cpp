#include "pch.h"
#include "CppUnitTest.h"
#include "../labs/lab1.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(CoachTest)
	{
		TEST_METHOD(TripTest)
		{
			coach c = coach();
			Assert::AreEqual(c.make_trip(100), true);
			Assert::AreEqual(c.get_speed() < c.get_base_speed(), true);
			Assert::AreEqual(c.make_trip(100000), false);
		}
	};
	TEST_CLASS(AutomobileTest)
	{
		TEST_METHOD(TripTest)
		{
			automobile a = automobile();
			Assert::AreEqual(a.make_trip(100), true);
			Assert::AreEqual(a.get_speed() < a.get_base_speed(), true);
			Assert::AreEqual(a.make_trip(100000000), true);
		}
	};
	TEST_CLASS(AeroplaneTest)
	{
		TEST_METHOD(TripTest)
		{
			aeroplane plane = aeroplane();
			Assert::AreEqual(plane.make_trip(100), true);
			Assert::AreEqual(plane.make_trip(500000), false);
			plane.set_max_fly_time(2000);
			Assert::AreEqual(plane.make_trip(900), true);
			plane.set_max_fly_time(1000);
			plane.repair();
			Assert::AreEqual(plane.make_trip(1000), true);
			Assert::AreEqual(plane.get_time_since_last_repair(), 1000 / plane.get_speed() + computer::defaultTimeToBoot);
		}
		TEST_METHOD(ComputerTest)
		{
			aeroplane plane = aeroplane();
			plane.make_trip(100);
			Assert::AreEqual(plane.get_total_time() -100/ plane.get_speed(), computer::defaultTimeToBoot);
		}
	};
	TEST_CLASS(PetrolCarTest)
	{
	public:
		
		TEST_METHOD(TripTest)
		{
			petrol_car pCar = petrol_car();
			Assert::AreEqual(pCar.make_trip(10), true);
		}
		TEST_METHOD(TripTest2)
		{
			petrol_car pCar = petrol_car();
			Assert::AreNotEqual(pCar.make_trip(200), true);
			Assert::AreEqual(pCar.get_total_distance(), 100.);
		}
		TEST_METHOD(FuelTest)
		{
			petrol_car pCar = petrol_car();
			pCar.make_trip(50);
			Assert::AreEqual(pCar.get_current_fuel(), 50.);
			pCar.refuel_car(50);
			Assert::AreEqual(pCar.get_current_fuel(), 100.);
			pCar.refuel_car(1000);
			Assert::AreEqual(pCar.get_current_fuel(), 100.);
			pCar.make_trip(1000);
			Assert::AreEqual(pCar.get_current_fuel(), 0.);
			auto funk = [&pCar] {pCar.refuel_car(-100); };
			Assert::ExpectException<std::exception>(funk);
		}
	};
	TEST_CLASS(electricCarTest)
	{
		TEST_METHOD(accumulatorTest)
		{
			accumulator ac = accumulator(100, 4);
			auto cur = ac.getCurrentFuel();
			Assert::AreEqual(cur >= 60 && cur <= 100, true);

			ac.refuel(-50);
			Assert::AreEqual(ac.getCurrentFuel(), cur-50);

			ac.refuel(9999);
			Assert::AreEqual(ac.getCurrentFuel(), 100.);

			auto fun = [&ac] {ac.refuel(-101); };
			Assert::ExpectException<std::exception>(fun);

			auto fun2 = [&ac] {while (1) { ac.refuel(1); }};
			Assert::ExpectException<std::exception>(fun2);
		}
		TEST_METHOD(accInCarTest)
		{
			accumulator ac = accumulator(100);
			electric_car car = electric_car("name", 100, &ac);
			auto cur = ac.getCurrentFuel();
			car.make_trip(10);
			Assert::AreEqual(ac.getCurrentFuel(), cur-10);
			Assert::AreEqual(car.make_trip(100), false);
			Assert::AreEqual(ac.getCurrentFuel(), 0.);
			Assert::AreEqual(car.get_current_fuel(), ac.getCurrentFuel());
			auto ac2 = car.change_accumulator(&accumulator(300));
			Assert::AreEqual(ac.getCurrentFuel(), ac2->getCurrentFuel());

		}
	};
}
