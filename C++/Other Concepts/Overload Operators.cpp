//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator +(const Complex &a,const Complex &b){
	Complex r;
	r.a = a.a + b.a;
	r.b = a.b + b.b;
	return r;
}
namespace std{
	ostream& operator<<(ostream& out,const Complex &r){
		return out << r.a << "+i" << r.b;
	}
}
