#include<string>
using namespace std;
class StrVec 
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&) = default;
	StrVec& operator=(const StrVec&)  = default;
	~StrVec() = default;
	void push_back(const string&);
	size_t size() { return first_free - elements; }
	size_t capacity() { return cap - elements; }
	string* begin() { return elements; }
	string* end() { return first_free; }
private:
	static std::allocator<string> alloc;
	string* elements;
	string* first_free;
	string* cap;
};