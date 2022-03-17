#define _USE_MATH_DEFINES
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include <iostream>
#include <string>
#include<numeric>
#include<cmath>
#include <functional>
#include <vector>
#include<regex>
#include"lab1.h"
#include<fstream>
#include<list>
#include<hash_map>
#include "my_linked_list.h"
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
	 char name[32];
	int population;
	city(std::string name, int pop)
	{
		int i = 0;
		for (; i < name.size(); i++)
			this->name[i] = name[i];
		this->name[i] = '\0';
		population = pop;
	}
	city()
	{
		name[0] = '\0';
		population = 0;
	}
	void print()
	{
		std::cout << name << " " << population<<std::endl;
	}
	bool operator<=(const city& ct)
	{
		for (int i = 0; name[i] && ct.name[i]; i++)
		{
			if (name[i] < ct.name[i])
				return true;
			else if(name[i] > ct.name[i])
				return false;
		}
		return true;
	}
	bool operator>=(const city& ct)
	{
		for (int i = 0; name[i] && ct.name[i]; i++)
		{
			if (name[i] > ct.name[i])
				return true;
			else if (name[i] < ct.name[i])
				return false;
		}
		return true;
	}
};

std::list<city> get_cities()
{
	std::ifstream file = std::ifstream("cities");
	std::list<city> cities = std::list<city>();
	city ct = city();
	if (!file.is_open())
		return cities;
	while (file.read((char*)&ct, sizeof(city)))
	{
			cities.push_back(ct);
	}
	file.close();
	return cities;
}
std::list<city> get_cities(int left, int right)
{
	std::ifstream file = std::ifstream("cities");
	std::list<city> cities = std::list<city>();
	city ct = city();
	while (file.read((char*)&ct, sizeof(city)) && ct.population<= right)
	{
		if (ct.population >= left && ct.population <= right)
			cities.push_back(ct);
	}
	file.close();
	return cities;
}

void add_city(city ct)
{
	std::list<city> cities = get_cities();
	std::ofstream file = std::ofstream("cities");
	city lastCit;
	bool alreadyAdd = false;
	for (city& cit : cities)
	{
		if (((lastCit <= ct && ct <= cit) || (lastCit.name[0] == '\0' && cit >= ct)) && !alreadyAdd)
		{
			file.write((char*)&ct, sizeof(city));
			alreadyAdd = true;
		}
		file.write((char*)&cit, sizeof(city));
		lastCit = cit;
	}
	if (!alreadyAdd)
	{
		file.write((char*)&ct, sizeof(city));
	}
	file.close();
}


class vehicle_handler
{
private:
	std::vector<coach*> coaches;
	std::vector<automobile*> automobiles;
	std::vector<aeroplane*> aeroplanes;
	std::vector<electric_car*> electric;
	std::vector<petrol_car*> petrol;
	void output_vehicle(std::vector<vehicle*>& v)
	{

		std::cout << "Name\tSpeed\tDist\tTime\n";
		for (auto veh : v)
		{
			std::cout << veh->get_name() << '\t' << veh->get_speed() << '\t' << veh->get_total_distance() << '\t' << veh->get_total_time() << std::endl;
		}
	}
public: 
	void add(coach* v)
	{
		coaches.push_back(v);
	}
	void add(automobile* v)
	{
		automobiles.push_back(v);
	}
	void add(aeroplane* v)
	{
		aeroplanes.push_back(v);
	}
	void add(electric_car* v)
	{
		electric.push_back(v);
	}
	void add(petrol_car* v)
	{
		petrol.push_back(v);
	}
	std::vector<vehicle*> get_all()
	{
		std::vector<vehicle*> vehicles;
		vehicles.insert(vehicles.end(), coaches.begin(), coaches.end());
		vehicles.insert(vehicles.end(), aeroplanes.begin(), aeroplanes.end());
		vehicles.insert(vehicles.end(), automobiles.begin(), automobiles.end());
		vehicles.insert(vehicles.end(), electric.begin(), electric.end());
		return vehicles;
	}
	void output_all()
	{
		auto vehicles = get_all();
		vehicles.insert(vehicles.end(), petrol.begin(), petrol.end());
		std::sort(vehicles.begin(), vehicles.end());

		output_vehicle(vehicles);
	}
	
};
void commit_random_trips(std::vector<vehicle*>& vehicles)
{
	for (int i = 0; i < vehicles.size(); ++i) {
		double randomDistance = double(rand() % 20001) / 10.;
		vehicles[i]->make_trip(randomDistance);
	}
}

void lab1()
{
	vehicle_handler handler;
	auto a = electric_car();
	handler.add(&a);
	aeroplane plane = aeroplane();
	handler.add(&plane);
	auto vec = handler.get_all();
	commit_random_trips(vec);
	handler.output_all();
}
//вариантн 5
namespace lab4
{
	const std::string START_FILE = "lab4_1.txt";
	const std::string END_FILE = "lab4_2.txt";
	std::vector<std::string> get_words()
	{
		std::vector<std::string> words = std::vector<std::string>();
		std::ifstream file;
		file.exceptions(std::ifstream::badbit | std::ifstream::failbit);

		try
		{
			file.open(START_FILE);
			while (!file.eof())
			{
				std::string word;
				file >> word;
				words.push_back(word);
			}
			file.close();
		}
		catch (std::ifstream::failure ex)
		{
			std::cout << ex.what();
			exit(1);
		}
		return words;
	}
	void hardest_task(std::vector<std::string> vec)
	{
		std::regex reg = std::regex(R"([aoeiyu])", std::regex::icase);
		std::vector<std::string>::iterator minIt;
		std::vector<std::string>::iterator maxIt;
		double min = DBL_MAX;
		double max = DBL_MIN;
		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			double match_count = std::distance(std::sregex_iterator(i->begin(), i->end(), reg), std::sregex_iterator());
			match_count /= i->size();
			if (match_count < min)
			{
				min = match_count;
				minIt = i;
			}
			if (match_count > max)
			{
				max = match_count;
				maxIt = i;
			}

		}
		if (minIt > maxIt)
			std::swap(minIt, maxIt);
		std::ofstream file = std::ofstream(END_FILE);
		for (; minIt != maxIt + 1; minIt++)
		{
			file<<*minIt+"\n";
		}
		file.close();
	}

}

//вариант 2
namespace lab5
{
	template<typename T>
	class my_forward_list
	{
	private:
		template<typename T>
		class link
		{
		public:
			link<T>* next;
			T data;
			link<T>(T dat)
			{
				data = dat;
				next = nullptr;
			}
		};
		link<T>* start;
		link<T>* end;
		link<T>* current;
	public:
		my_forward_list()
		{
			end = nullptr;
			start = end;
			current = start;
		}
		int size()
		{
			link<T> *ln = start;
			if (ln == nullptr)
				return 0;
			int counter = 1;
			while (ln->next != nullptr)
			{
				counter++;
				ln = ln->next;
			}
			return counter;

		}
		void add(T item)
		{
			if (size() == 0)
			{
				start = new link<T>(item);
				start->next;
				end = start;
			}
			else
			{
				end->next = new link<T>(item);
				end = end->next;
			}
		}
		void add(T item, int pos)
		{
			link<T> *ln = start;
			link<T>* prew = start;
			if (pos == 0 && size() == 0)
			{
				add(item);
				return;
			}
			if (pos > size())
				throw std::exception("position greater than size");
			for (int i = 0; i < pos; i++)
			{
				prew = ln;
				ln = ln->next;
			}
			link<T>* newLink = new link<T>(item);
			if (start == ln)
			{

				newLink->next = start;
				start = newLink;
				return;
			}
			newLink->next = ln;
			prew->next = newLink;
		}
		T get_current()
		{
			if (current == nullptr)
			{
				if (start != nullptr)
					current = start;
				else
					throw std::exception("list is empty");
			}
			return current->data;
		}
		T get_first()
		{
			if(start == nullptr)
				throw std::exception("list is empty");
			return start->data;
		}
		T get_last()
		{
			if (end == nullptr)
				throw std::exception("list is empty");
			return end->data;
		}
		void reset_iter()
		{
			current = nullptr;
		}
		bool move_next()
		{
			if (current == nullptr)
			{
				current = start;
				return start != nullptr;
			}
			if (current->next != nullptr)
			{
				current = current->next;
				return true;
			}
			return false;
		}
		bool is_last()
		{
			return current == end;
		}
		~my_forward_list()
		{
			link<T>* ln = start;
			while (ln->next != nullptr)
			{
				link<T>* nex = ln->next;
				delete ln;
				ln = nex;
			}
		}
	};

	void main_funk()
	{
		std::string fu;
		std::cin >> fu;
		//TODO: regex ignore 'xx' 
		std::regex reg = std::regex(R"(([+-]?\d{1,})(x(\^([+-]?\d{1,}))?)?)");
		std::vector<std::string> matches{ std::sregex_token_iterator{fu.begin(),fu.end(), reg, 0},std::sregex_token_iterator() };
		struct polynom
		{
			int coef;
			int degree;
		};
		my_forward_list<polynom> list = my_forward_list<polynom>();
		for (int i =0;i< matches.size();i++)
		{
			std::smatch match;
			std::regex_match(matches[i],match, reg);
			int c = atoi(match[1].str().c_str());
			if (c == 0)
				continue;
			int d;
			if (match[4].matched)
			{
				 d= atoi(match[4].str().c_str());
			}
			else
			{
				if (match[2].matched)
					d = 1;
				else d = 0;
			}
			polynom p = { c,d };
			list.add(p);
		}
		int dot;
		std::cin >> dot;
		double res = 0;
		while (list.move_next())
		{
			res += list.get_current().coef * pow(dot, list.get_current().degree);
		}
		std::cout << res << "\n";
		list.reset_iter();
		my_forward_list<polynom> derivative;
		while (list.move_next())
		{
			polynom p = { list.get_current().coef * list.get_current().degree, list.get_current().degree - 1 };
			if(p.coef != 0)
				derivative.add(p);
		}
		bool first = true;
		while (derivative.move_next())
		{
			if (!first)
			{
				std::cout << (derivative.get_current().coef > 0 ? "+" : "");
			}
			std::cout << derivative.get_current().coef;
			if (derivative.get_current().degree != 0)
			{
				std::cout << "x";
				if(derivative.get_current().degree > 1)
					std::cout << "^" << derivative.get_current().degree;
			}
			first = false;
		}
	}
}
int main()
{
	srand(time(0));
	my_linked_list<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(8, 2);
	list.add(9, 4);
	auto iter = list.begin();
	do
	{
		std::cout << iter.get_current();
	} while (iter.move_next());
	iter = list.end();
	std::cout << "\n";
	do
	{
		std::cout << iter.get_current();
	} while (iter.move_back());

}