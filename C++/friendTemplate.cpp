template<class T>
class testmultiply
{
public:
	testmultiply() = default;
	testmultiply(T i) :a(i) {}
	const testmultiply<T> operator*(const testmultiply<T>& te) { this->a = this->a * te.a; return *this; }
private:
	T a;
	friend const testmultiply<T> operator*(const testmultiply<T>& te1, const testmultiply<T>& te2);
};
template<class T>
const testmultiply<T> operator*(const testmultiply<T>& te1, const testmultiply<T>& te2)
{
	testmultiply<T> te;
	te.a = te1.a * te2.a;
	return te;
}
int main()
{
	testmultiply<int> mul1(10);
	testmultiply<int> mul2 = mul1 * 5;
	testmultiply<int> mul3 = 5 * mul1;
	
}