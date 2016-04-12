运算符重载
"<<" 左移运算符在iostream中进行了重载  
<pre>
osstream & osstream::operator<<(int n)/(const char *s)
{
	......
	return *this;
}
</pre>

####++/--运算符的重载
***
* 前置运算符  
成员函数：  
T operator++();  
T operator--();  
全局函数  
T operator++(T);  
T operator--(T);  
++obj,obj.operator++(),operator++(obj)都会调用上述函数
* 后置运算符  多写一个参数，具体无意义,编译器会自动编译成0  
成员函数  
T operator++(int);  
T operator--(int);  
全局函数  
T operator++(T,int);  
T operator--(T,int);
obj++,obj,operator++(0),operator++(obj,0)都会调用上述函数 
* 强制类型转换运算符重载  
<pre>
class Demo{
	int n;
	operator int(){
		return n;
	}
}

Demo d;
(int)d;   //d.int()
</pre>
不能写返回值类型，实际上其返回值就是强制类型转换的类型

####不能被重载的运算符
“.",".*","::","?:",sizeof 以上运算符均不能被重载  
运算符(),[],->,=的重载函数必须声明为类的成员函数