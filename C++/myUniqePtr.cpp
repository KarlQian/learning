class Del
{
public:
	template<typename T>
	void operator()(const T*p) const { delete p; }
};
template<typename T,typename D = Del>
class unique_ptr
{
public:
	unique_ptr(T* unique = nullptr, const D&dd = D()) :un_ptr(unique), del(dd) {}
	~unique_ptr() { del(un_ptr); }
// no copy and = 
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;\
	unique_ptr(unique_ptr&& right_value)
	{
		un_ptr = right_value.un_ptr;
		right_value.un_ptr = nullptr;
		Del = std::move(right_value.Del);
	}
	unique_ptr& operator=(unique_ptr&& right_value) 
	{
		if (this == &s)
			return *this;
		else{
			del(*this);
			un_ptr = right_value.un_ptr;
			right_value.un_ptr = nullptr;
			Del = std::move(right_value.Del);
		}

	}
	//u.release()   u 放弃对指针的控制权，返回指针，并将 u 置为空
	T* release() 
	{
		T* tmp = un_ptr;
		un_ptr = nullptr;
		return tmp;
	}
	/*
	u.reset()   释放u指向的对象
	u.reset(q)  如果提供了内置指针q，就令u指向这个对象
	u.reset(nullptr) 将 u 置为空
	*/
	void reset() 
	{
		del(un_ptr);
	}
	void reset(T*q) { 
		if (un_ptr)
			del(un_ptr)
			un_ptr = q; 
		else
			un_ptr = nullptr
	}
	void swap(unique_ptr &other) noexcept {
		using std::swap;
		swap(un_ptr, other.un_ptr);
		swap(del, other.del);
	}
	T* get() { return un_ptr; }
	D& get_deleter() { return  del; }
	T& operator*() { return *un_ptr; }
	T* operator->() { return  un_ptr; }
private:
	T* un_ptr;
	D Del;
};