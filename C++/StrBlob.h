#include "includes.h"
using namespace std;
class StrBlob 
{
public:
	StrBlob() :m_data(make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<string> il) : m_data(make_shared<vector<string>>(il)) {}
	size_t size() const { return m_data->size(); }
	bool empty() const { return m_data->empty(); }
	void push_back(const string &st) { m_data->push_back(st); }
	void pop_back();
	string& front();
	string back();
	const string& front() const;
	const string& back() const;
private:
	shared_ptr<vector<string>> m_data;
	void check(size_t i, const string &msg) const ;

};