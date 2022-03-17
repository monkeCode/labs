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
namespace lab6
{
	struct student
	{
		char surName[20];
		char group[20];
		student(std::string sname, std::string group)
		{
			int i = 0, j = 0;
			while (i < sname.size())
			{
				surName[i] = sname[i];
				i++;
			}
			while (j < group.size())
			{
				this->group[j] = group[j];
				j++;
			}
			surName[i] = '\0';
			this->group[j] = '\0';

		}
	};
	void add(my_linked_list<student>& list, student st)
	{
		if(list.size() == 0)
		{
			list.add(st);
			return;
		}
		auto iter = list.begin();
		student lastStudent{ "","" };
		for (int i = 0; i < list.size(); i++)
		{

			if ((std::string(lastStudent.surName).empty() || std::string(lastStudent.surName) >= std::string( st.surName)) && std::string(st.surName) <= std::string(iter.get_current().surName))
			{
				list.add(st, i);
				return;
			}

			lastStudent = iter.get_current();
			iter.move_next();
		}
		list.add(st);
	}

	const std::string FILE_NAME = "lab6";
	void save_file(my_linked_list<student>::list_iterator<student> iter)
	{
		std::ofstream file(FILE_NAME, std::ofstream::binary);
		do
		{
			student st = iter.get_current();
			file.write((char*)&st, sizeof(student));
		} while (iter.move_next());
		file.close();
	}
	void load_from_file(my_linked_list<student>& list)
	{
		std::ifstream file(FILE_NAME, std::ofstream::binary);
		student st("","");
		while(file.read((char*)&st, sizeof(student)))
		{
			list.add(st);
		}
		file.close();
	}
}
int main()
{
	my_linked_list<lab6::student> list;
	lab6::add(list, lab6::student{ "kolya","1" });
	lab6::add(list, lab6::student{ "banya","1" });
	lab6::add(list, lab6::student{ "anya","1" });
	lab6::add(list, lab6::student{ "gosha","1" });
	lab6::save_file(list.begin());
	my_linked_list<lab6::student> list2;
	lab6::load_from_file(list2);
	auto iter = list2.begin();
	do
	{
		std::cout << iter.get_current().surName<<"\n";
	} while (iter.move_next());

}