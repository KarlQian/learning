
#include <string>
#include <iostream>
using namespace std;
void main()
{
	constexpr size_t n = 10;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	alloc.construct(q++, 10, 'c');
	cout << *p << endl;
	//cout << *q << endl;

	while (q != p) { alloc.destroy(--q); }

}