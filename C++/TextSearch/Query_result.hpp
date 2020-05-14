#ifndef query_Result_HPP
#define query_Result_HPP 
#include <iostream>
#include<string>
#include <memory>
#include <vector>
#include <map>
#include<set>
#include<sstream>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

class QueryResult
{
	public:
	QueryResult(const string& s,const set<size_t>& line,shared_ptr<vector<string>> text):sought(s),lineno(line),ptext(text){}
	QueryResult(){}

	friend ostream& operator<< (ostream& os, const QueryResult& qresult)
	{
		os<<qresult.sought<<"occurs"<<qresult.lineno.size()<<"times:"<<endl;
		for (auto n:qresult.lineno)
		{

			os<<"line["<<n+1<<"]"<<(*qresult.ptext)[n];
		}
		return os;
	}
	friend QueryResult operator+(const QueryResult& lhs,const QueryResult& rhs)
	{
		if (lhs.ptext != rhs.ptext)
		{
			std::cout<<"text is not the same"<<endl;
			return QueryResult();
		}
		string newsought = lhs.sought+"||"+rhs.sought;
		set<size_t> linenonew = lhs.lineno;
		linenonew.insert(rhs.lineno.begin(),rhs.lineno.end());
		return QueryResult(newsought,linenonew,lhs.ptext);
	}
	friend QueryResult operator-(const QueryResult& lhs,const QueryResult& rhs)
	{
		if (lhs.ptext != rhs.ptext)
		{
			std::cout<<"text is not the same"<<endl;
			return QueryResult();
		}
		string newsought = lhs.sought+"&&"+rhs.sought;
		set<size_t> linenonew;
		set_intersection(lhs.lineno.begin(),lhs.lineno.end(),rhs.lineno.begin(),rhs.lineno.end(),inserter(linenonew , linenonew.begin()));

		return QueryResult(newsought,linenonew,lhs.ptext);
	}

	QueryResult Reverse()
	{
		string newsought = "~("+ sought+"）";
		set<size_t> linenonew; 
		size_t num = ptext->size();
		for (size_t i=0;i<num;++i)
			if (lineno.find(i)==lineno.end())
				linenonew.insert(i);
		return QueryResult(newsought,linenonew,ptext);
	}
	

	private:
	string sought;
	set<size_t> lineno;
	shared_ptr<vector<string>> ptext;
};

#endif