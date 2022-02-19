#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>
#include <functional>
#include <vector>
#include<regex>
#include "labs.h"
#include<fstream>
#include<list>
//lab 2, 23
struct user
{
public:
	enum phone_type { home, office };
	std::string lastName;
	std::string phoneNumber;
	phone_type phoneType;

	user(std::string lastName, std::string phoneNum, phone_type type)
	{
		this->lastName = lastName;
		phoneNumber = phoneNum;
		phoneType = type;
	}
	bool operator<(const user& us)
	{
		return phoneType < us.phoneType;
	}
	bool operator>(const user& us)
	{
		return phoneType > us.phoneType;
	}
};
std::string fileName = "base_users.txt";
std::string secondFileName = "base_users2.txt";
std::list<user> load_users()
{
	std::ifstream file = std::ifstream(fileName);
	std::list<user> users = std::list<user>();
	while (file.good())
	{
		std::string lastname;
		std::string phone;
		int code;
		file >> lastname;
		file >> phone;
		file >> code;
		auto user = user::user(lastname, phone, (user::phone_type)code);
		users.push_back(user);
	}
	file.close();
	return users;

}
void add_user(std::string lastname, std::string phone, user::phone_type code)
{
	std::ofstream file = std::ofstream(fileName, std::ios_base::app);
	file << lastname << " " << phone << " " << code << "\n";
	file.close();
}
void add_user(user us)
{
	add_user(us.lastName, us.phoneNumber, us.phoneType);
}

void update_second_file(char ch[])
{
	std::list<user> users = load_users();

		auto removeIter = std::remove_if(users.begin(), users.end(), [ch](user us)
			{
				for (char* c = ch; *c; c++)
				{
					if (us.lastName[0] == *c)
						return false;
				}
				return true;
			});
		users.erase(removeIter, users.end());
	users.sort();

	std::ofstream file = std::ofstream(secondFileName);
	for(auto us : users)
	{
		file << us.lastName << " " << us.phoneNumber << " " << (int)us.phoneType << "\n";
	}
	file.close();
}

//lab 3, 23
struct city
{
	std::string name;
	int population;
	city(std::string name, int pop)
	{
		this->name = name;
		population = pop;
	}
};
void add_city(city ct)
{
	std::ofstream file = std::ofstream("cities", std::ofstream::app);
	file.write((char*)&ct, sizeof(city));
	file.close();
}
std::list<city> get_cities(int left, int right)
{
	std::ifstream file = std::ifstream("cities");
	std::list<city> cities = std::list<city>();
	city *ct = new city("", 1);
	while (!file.eof())
	{
		file.read((char*)ct, sizeof(city));
		cities.push_back(*ct);
	}
	file.close();
	return cities;
}
int main()
{
	//add_city(city("chicago2", 200));
	//add_city(city("chicago3", 300));
	get_cities(1, 1);

}