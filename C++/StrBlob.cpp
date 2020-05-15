#include "StrBlob.h"

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	m_data->pop_back();
}

string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return m_data->front();
}

string StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return m_data->back();
}

const string & StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return m_data->front();
}

const string & StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return m_data->back();
}

void StrBlob::check (const size_t i, const string & msg) const
{
	if (i > m_data->size())
		throw out_of_range(msg);
}
