//HW#11: Rat Class

#include <iostream>
using namespace std;

class Rat{
	private:
		int n;
		int d;
		int mn;
		bool isWhole = false;

	public:

	Rat(){
		n = 0;
		d = 1;
		mn = 0;
	}
	Rat(int i, int j){
		n = i;
		d = j;
		mn = 0;
	}
	Rat(int i){
		n = i;
		d = 1;
		mn = 0;
	}
	
	int getN(){
		return n;
	}
	int getD(){
		return d;
	}
	bool getisWhole(){
		return isWhole;
	}

	void setN(int i){
		n = i;
	}
	void setD(int j){
		d = j;
	}

	Rat operator+(Rat r){
  	Rat t;
    t.n = n*r.d + d*r.n;
    t.d = d*r.d;
		t.reduce();
    return t;
  }

	Rat operator-(Rat r){
  	Rat t;
    t.n = n*r.d - d*r.n;
    t.d = d*r.d;
		t.reduce();
    return t;
  }
	Rat operator*(Rat r){
  	Rat t;
    t.n = n*r.n;
    t.d = d*r.d;
		t.reduce();
    return t;
  }
	Rat operator/(Rat r){
  	Rat t;
    t.n = n*r.d;
    t.d = d*r.n;
		t.reduce();
    return t;
  }
	int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
	}

	void reduce(){
		if( int g = gcd(n,d) != 1){
			n = n/g;
			d = d/g;
		}
	}
	
	void mixedNum(){
		if(d == 1){
			mn = n;
			n = 1;
			d = 1;
			isWhole = true;
		}
		else if (d == n){
			mn = 1;
			n = 1;
			d = 1;
			isWhole = true;
		}
		else if(n > d){
			mn = n/d;
			n = n % d;
			isWhole = false;
		}
	}

	friend ostream& operator <<(ostream& os, Rat r);
	friend istream& operator >>(istream& is, Rat& r);
};

ostream& operator<<(ostream& os, Rat r){
	r.reduce();
	r.mixedNum();
	if (r.getisWhole()){
		os << r.mn;
	}
	else{
		if(r.mn != 0){
			os << r.mn << " "<< r.n << "/" <<r.d;
		}
		else {
			os << r.n << "/" << r.d;
		}
	}
	return os;
}

istream& operator>>(istream& is, Rat& r){
	r.reduce();
  is >> r.n >> r.d;
  return is;
}

int main() { 
	Rat x(1,2), y, z;
	Rat w(5);
	y.setN(3);
	y.setD(5);
	z = x + y;
	cout << x << "+" << y << " = "<< z <<endl;
	z = x - y;
	cout << x << "-" << y << " = "<< z <<endl;
	z = x * y;
	cout << x << "*" << y << " = "<< z <<endl;
	z = x/y;
	cout << x << " / " << y << " = "<< z <<endl;
	z = w * x;
	cout << w << "*" << y << " = "<< z <<endl;

	return 0;
}