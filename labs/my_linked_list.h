#pragma once
template<typename T>
class my_linked_list
{
	template<typename T>
	class link
	{
	public:
		//friend class my_linked_list<T>;
		link(link* prev, link* next, T data) : next(next), prev(prev), data(data) {}
	
		link* next;
		link* prev;
		T data;
	};

	link<T>* first;
	link<T>* last;
	int _size;


public:
	template<typename T>
	class list_iterator
	{
		friend class my_linked_list<T>;
		my_linked_list::link<T>* current;
	public:
		list_iterator(link<T>* l)
		{
			current = l;
		}
		bool move_next()
		{
			if (current->next != nullptr)
			{
				current = current->next;
				return true;
			}
			return false;
		}
		bool move_back()
		{
			if (current->prev != nullptr)
			{
				current = current->prev;
				return true;
			}
			return false;
		}
		T get_current()
		{
			return current->data;
		}
	};
	my_linked_list()
	{
		first = nullptr;
		last = nullptr;
		_size = 0;
	}
	void add(T data)
	{
		if (_size > 0)
		{
			last->next = new link<T>(last, nullptr, data);
			last = last->next;
		}
		else
		{
			first = new link<T>(nullptr, nullptr, data);
			last = first;
		}
		_size++;
	}
	void add(T data, int index)
	{
		if (index > _size - 1)
			throw std::out_of_range("ex");
		if (index == _size - 1)
		{
			add(data);
			return;
		}
		list_iterator<T> iter = begin();
		int i = 0;
		while (i++ != index - 1)
			iter.move_next();
		link<T>* prevln = iter.current;
		link<T>* nextln = prevln->next;
		link<T>* ln = new link<T>(prevln, nextln, data);
		prevln->next = ln;
		nextln->prev = ln;
		_size++;
	}
	int size()
	{
		return _size;
	}
	void clear()
	{
		link<T>* ln = first;
		while (ln != nullptr)
		{
			auto temp = ln->next;
			delete ln;
			ln = temp;
		}
		_size = 0;
	}
	list_iterator<T> begin()
	{
		return list_iterator<T>(first);
	}
	list_iterator<T> end()
	{
		return list_iterator<T>(last);
	}
	~my_linked_list()
	{
		clear();
	}


};


