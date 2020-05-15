#include "includes.h"
using namespace std;
void process(shared_ptr<int> ptr)
{
	std::cout << "use_count:"<<ptr.use_count() << endl;
	std::cout<<"value:"<<*ptr<<endl;
}
int pointerError() 
{
	shared_ptr<int> p(new int(32));
	//process(shared_ptr<int>(p)); //ok
	cout << p.use_count()<<endl;
	process(shared_ptr<int>(p.get())); 
	//wrong: will destory the memory when out of the process function , as p and prt are two different ptr for the complier
	cout << p.use_count()<<endl;
	cout << *p; // unexpected error, as the memory is destored before
	return 0;
}
int destoryerror() {
	shared_ptr<int> p(new int(32));
	int *q = p.get();
	{
		shared_ptr<int> p2(q); // two shared_ptr p,p2 points to the same block
	} // ends and q is destoryed, so the block is destoried

	int foo = *p;
	return 0;
}

int main() 
{
	auto p = new int();
	auto sp = make_shared<int>();
	process(sp); //ok
	//process(new int()); //wrong argument is not the same
	//process(p);
	process(shared_ptr<int>(p));// dangling pointer
	return 0;
}

