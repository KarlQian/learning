#include "query.hpp"

QueryResult WordQuery::eval(const TextQuery& text) 
	{
		return QueryResult(m_word,(*text.get_map())[m_word],text.get_text());
	}
QueryResult NotQuery::eval(const TextQuery& text) 
	{
				return q.lock()->eval(text).Reverse();
	}

string NotQuery::rep() 
{
    return "~("+q.lock()->rep()+")";
}

QueryResult AndQuery::eval(const TextQuery& text) 
{

		return lhs->eval(text) - rhs->eval(text);

}
string  AndQuery::rep() 
{
    return lhs->rep()+"&&"+rhs->rep();
}

QueryResult OrQuery::eval(const TextQuery& text) 
	{
		return lhs->eval(text)+rhs->eval(text);
	}
string  OrQuery::rep() 
{
	return lhs->rep()+"||"+rhs->rep();
}
Query::Query(const string& s=""):pq(new WordQuery(s)){}

Query Query::operator &&(const Query& q1)
{
    //shared_ptr <Query_base> pnew(new  AndQuery(*this,q1));
	shared_ptr <Query_base> pnew = make_shared<AndQuery>(*this, q1);
	cout << "&&"<<pnew.get() << endl;
    return Query(pnew);
}
Query Query::operator ||(const Query& q1)
{
    shared_ptr <Query_base> pnew (new OrQuery(*this,q1));
	cout << "||" << pnew.get() << endl;

    return Query(pnew);
}
Query Query::operator~ ()
{
    shared_ptr <Query_base> pnew = make_shared<NotQuery>(NotQuery(*this));
	//shared_ptr <Query_base> pnew (new NotQuery(*this));
	return Query(pnew);
}
