#ifndef query_HPP
#define query_HPP 
#include <iostream>
#include<string>
#include <memory>
#include <vector>
#include <map>
#include<set>
#include<sstream>
#include <fstream>
#include <algorithm>
#include "Query_result.hpp"
#include "TextQuery.hpp"
using namespace std;

class Query;

class Query_base
{
	friend class Query;
	protected:
		virtual QueryResult eval(const TextQuery& text) = 0;// { cout << "Qbase::pure eval:" <<this<<endl; return QueryResult(); };
		virtual string rep() =0;//{ cout << "pure rep" << endl; return "0"; }
	//public:
	//virtual ~Query_base()=default;
	

};
class WordQuery: public Query_base
{
	friend class Query;
	public:
	WordQuery(string word):m_word(word){}
	virtual QueryResult eval(const TextQuery& text) override;
	virtual string rep() override{return m_word;}
	string m_word;

};
class NotQuery: public Query_base
{
	friend class Query; //only Query can visit
	NotQuery(const Query& q1):q(make_shared<Query>(q1)){}
	virtual QueryResult eval(const TextQuery& text) override;
	virtual string rep() override;
	weak_ptr<Query> q;
};
class BinaryQuery: public Query_base
{
	friend class Query;
	protected:
	BinaryQuery(const Query&q1,const Query&q2,string _op):lhs(make_shared<Query>(q1)),rhs(make_shared<Query>(q2)),op(_op){}
	shared_ptr<Query> lhs;
	shared_ptr<Query> rhs;
	string op;

};
class AndQuery: public BinaryQuery
{
	friend class Query;
	AndQuery(const AndQuery&) = delete;
public:
	AndQuery(const Query& q1,const Query& q2):BinaryQuery(q1,q2,"&&"){}
	virtual QueryResult eval(const TextQuery& text) override;
	virtual string  rep() override;
};
class OrQuery: public BinaryQuery
{
	friend class Query;
	OrQuery(const Query& q1,const Query& q2):BinaryQuery(q1,q2,"||"){}
	virtual QueryResult eval(const TextQuery& text) override;
	virtual string  rep() override;
};


class Query
{
	public:

	Query(const string& s);
	Query(shared_ptr<Query_base> q):pq(q){}

	Query operator &&(const Query& q1);

	Query operator ||(const Query& q1);

	Query operator~ ();

	QueryResult eval(const TextQuery& text) const { cout << "eval address" << this->pq.get() << endl; return pq->eval(text); }
	string rep() const {return pq->rep();}
	public:
	shared_ptr<Query_base> pq;
};


#endif