#pragma once
#include <utility>
#include <assert.h>
#include <iostream>
using namespace std;
namespace ptr {
	template<class T>
	class Ptr
	{
	public:
		Ptr(T* _element) :element(_element), count(new int(1)) {}
		Ptr(const Ptr& _ptr) :element(_ptr.element), count(_ptr.count) 
		{ (*count)++; }
		Ptr(Ptr&& _ptr)
		{
			element = _ptr.element;
			count = _ptr.count;
			_ptr.element = nullptr;
			_ptr.count = nullptr;
		}
		Ptr& operator=(const Ptr&_ptr)
		{
			if (this != &_ptr)
			{
				if (this)
				{
					this->~Ptr();
				}
				element = _ptr.element;
				count = _ptr.count;
				(*count)++;
				return *this;
			}
			else return *this;
		}
		Ptr&  operator=( Ptr&& _ptr)
			{
				if (this != &_ptr)
				{
					std::swap(element, _ptr.element);
					std::swap(count, _ptr.count);
					
					//this->~Ptr();
					//Ptr temp(_ptr);
					////element = _ptr.element;
					////count = _ptr.count;
					////(*count)++;
					_ptr.~Ptr();
					return *this;
				}
				else return *this;
			}
		T& operator*() 
		{
			if (*count == 0) return (T*)0;
			return *element;
		}
		T* operator->()
		{
			if (*count == 0) return 0;
			else return element;
		}
		~Ptr()
		{
			(*count)--;
			if (element && *count == 0) 
			{
				delete element;
				element = nullptr;
				delete count;
				count = nullptr;
			}
		}
		int get_count() { return *count; }
		T* get() { return element; }
	private:
		T* element;
		int* count;

	};

	inline int  testptr()
	{
		try {
			Ptr<double> p(new double(66.2));
			{auto p2 = p;
			assert(p2.get_count() == 2);
			assert(p.get_count() == 2);
			assert(*(p2.get()) == 66.2);
			}
			assert(p.get_count() == 1);

			{
				auto p3(std::move(p));
				assert(p.get() == nullptr);
				assert(p3.get_count() == 1);
				assert(*(p3.get()) == 66.2);
				//assert(p2.get() == p3.get());
			}

			Ptr<double> pnew(new double(66.2));
			{
				Ptr<double> pp(new double(68.8));
				pp = pnew;
				assert(*(pnew.get()) == 66.2);
				assert(pp.get_count() == 2);
				assert(*(pp.get()) == 66.2);
			}
			assert(pnew.get_count() == 1);

			Ptr<double> pp2(new double(68.8));
			pp2 = std::move(pnew);
		}
		catch (exception &e)
		{
			cerr << e.what() << endl;
		}
		return 0;

	}
}

