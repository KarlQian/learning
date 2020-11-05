
#include <cassert>
#include <string>

template<typename T>
class Remote
{
public:
    Remote(): p{new T} {}
    ~Remote() {delete p;}

    Remote(Remote const& rhs): p{new T(*rhs.p)} {}
    Remote(Remote&& rhs): p{rhs.p} {rhs.p = nullptr;}

    Remote& operator=(Remote const& rhs)
    {
        assert(rhs.p && "trying to copy moved-from Remote<T>");
        T *tmp = new T(*rhs.p);
        delete p;
        p = tmp;
        return *this;
    }

    Remote& operator=(Remote&& rhs)
    {
        delete p;
        p = rhs.p;
        rhs.p = nullptr;
        return *this;
    }
    
    T& operator*()
    {
        assert(p && "trying to access moved-from Remote<T>");
        return *p;
    }
    
    T const& operator*() const
    {
        assert(p && "trying to access moved-from Remote<T>");
        return *p;
    }

    T* operator->()
    {
        assert(p && "trying to access moved-from Remote<T>");
        return p;
    }

    T const* operator->() const
    {
        assert(p && "trying to access moved-from Remote<T>");
        return p;
    }

private:
    T *p;
};

template<typename T1, typename T2>
bool operator==(Remote<T1> const& a, Remote<T2> const& b)
{
    return *a == *b;
}

template<typename T1, typename T2>
bool operator!=(Remote<T1> const& a, Remote<T2> const& b)
{
    return !(a == b);
}

int main()
{
    Remote<std::string> mystring;
    *mystring = "hello world";
    
    Remote<std::string> copystring( mystring );
    assert(mystring == copystring);
    
    Remote<std::string> otherstring( mystring );
    *otherstring = "good bye";
    assert(mystring != otherstring);
    assert(mystring == copystring);
}
