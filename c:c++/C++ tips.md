##关于inline
* 在类中直接定义并实现的方法 系统自动会判定为 inline 函数
* inline 主要是替代了 C 中宏定义函数的功能
* inline 函数调用时直接用函数体替换掉调用函数的代码，没有参数的入栈出栈，效率很高

##关于构造函数/析构函数
####构造函数
* 当函数传递的参数是一个类的对象的时候，函数会调用复制构造函数创建一个临时对象，效率较低，
* 关于类型转换构造函数，如下代码
<pre>
class Complex
{
public:
	double real, imag;
	Complex(int i){		//类型转换构造函数
		real = i;
	};
	Complex(double r,double i){
		real = r;
		imag = i;
	}
	~Complex();
};
Complex c1(7,12);
Complex c2 = 2;
c1 = 9;
</pre>
c2 = 2;  
是直接调用的构造函数  
c1 = 9;  
9会被自动转换成一个临时的Complex对象

####析构函数
* 对象消亡时自动调用的函数，注意在这里调用 delete 去释放 new 出来的空间
* 当对象数组生命周期结束时，对象数组中每个元素的析构函数都会被调用
* 当对象超出作用范围时调用析构函数，包括main函数

##关于static
* 普通成员变量 每个类的对象均含有一份 static成员变量 该类下所有对象共享一份
* 普通成员函数 必须作用于某个对象 static成员函数 不需要作用于某一个对象
* static成员 不需要具体对象便可直接访问   类名::成员名
* 要在定义类的文件中所有函数的外面对静态成员变量进行一次初始化 eg.Person::nTotalCount = 0;
* sizeof 不会计算静态成员变量
* static 目的是将和某些类紧密相关的全局函数和变量写到类里，易于维护和理解
* 注意复制构造函数对static成员变量的影响

##关于运算符重载
目的:扩展c++中提供的运算符的适用范围，用于类表示的抽象数据  
#####重载算术运算符
***
eg.作为普通函数来说
<pre>
返回类型 operator操作符(参数1，参数2)

Location operator+(Location &a,Location &b){
    return Location(a.longtitude+b.longtitude,a.latitude+b.latitude);
}
</pre>
作为成员函数会少一个参数
<pre>
class Location {
public:
    Location(double lon,double la){
        longtitude = lon;
        latitude = lai;
    }
    Location operator+(Location &a){
    	return Location(a.longtitude+longtitude,a.latitude+latitude);
    }
    double longtitude;
    double latitude;
};
</pre>  

#####重载复制运算符 "="
***
只能重载为成员函数