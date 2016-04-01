class Complex
{
public:
	static int n;
	double real, imag;
	Complex(int i){
		real = i;
	};
	Complex(double r,double i){
		real = r;
		imag = i;
	}
	void hehe();
	~Complex();
};

Complex::hehe(){
	this->real++;
}