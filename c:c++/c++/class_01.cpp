class Complex
{
public:
	Complex(double r,double i);
	~Complex();
private:
	double real,img;

};

Complex::Complex(double r, double i){
	real = r;
	img = i;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}