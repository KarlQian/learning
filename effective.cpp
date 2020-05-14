#include <iostream>
#include <string>
#include<vector>
#include<list>
#include <memory>
#include <algorithm>
using namespace std;
void test()
{
	list<int> foo, bar;
	for (int i = 0; i < 5; ++i)
	{
		foo.push_back(i); bar.push_back(10 * i);
	}
	auto it = foo.begin();
	advance(it, 3);
	copy(bar.begin(), bar.end(), bar.end());
}

class ElementImpl 
{
private:
	int a;
	int b;
	vector<double> c;
};
class Element 
{
	typedef unique_ptr<ElementImpl> UPtrImpl;
private:
	UPtrImpl p;
public:
	Element(UPtrImpl _p = make_unique<ElementImpl>()) :p(std::move(_p)){}
	//ElementImpl(const ElementImpl& e);
	Element& operator=(const Element& rhs)
	{if (this!=&rhs)
	{
		//using std::swap;
		Element temp(rhs);
		this->swap(temp);
	}
	return *this;
	}
	void swap(Element& e)
	{
		using std::swap;
		swap(p, e.p);
	}
	//~Element();
};
//namespace std 
//{
//	template<>
//	void swap<Element>(Element&s1, Element&s2)
//	{
//		s1.swap(s2);
//	}
//}

void  testswap() 
{
	Element e1;
	Element e2;
	//Element e2 = e1;
}
int  main() 
{
	testswap();
}