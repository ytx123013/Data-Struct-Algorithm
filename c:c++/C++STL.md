##string
string是一个模版类，定义如下：  
<pre>
typedef basic_string<char> string;
</pre>
经常使用的初始化函数
<pre>
string s1("Hello");			//Hello
string s2(3,'x'); 			//xxx
string s3 = "Match";		//Match
</pre>
若想用字符初始化string，不能直接使用下面方法
<pre>
string c1 = 'c';			//error
</pre>
而是声明后再复制，如下
<pre>
string c1;
c1 = 'c';					//correct
</pre>
###常用函数
***
长度
<pre>
s1.length();				//字符串包含的字符个数（不包括/0）
</pre>
***
输入
<pre>
string cinString;
cin >> cinString;			//支持流读取
</pre>
<pre>
string s;
getline(cin,s);				//支持getline();
</pre>
***
复制
<pre>
string s1("aaa"),s2;
s2 = s1;					//=复制
</pre>
<pre>
string s1("aaa"),s2;
s2.assign(s1);				//assign复制
</pre>
<pre>
string s1("aaabbb"),s2;
s2.assign(s1,1,3);			//部分复制
</pre>
支持[]赋值和读取
<pre>
string s1("aaabbb");
char c = s1[3];
s1[4] = 'c';
</pre>
***
连接
<pre>
string s1("good"),s2("morning!");
s1 += s2;					//goodmorning!
</pre>
<pre>
s1.append(s2);
s1.append(s2,3,2);
</pre>
***
比较  
==,>,>=,<,<=,!=  
返回值都为bool类型
***
字串  
<pre>
string s1("hello world"),s2;
s2 = s1,substr(4,5);		//
</pre>
***
查找  
find()  :	从前向后找  
rfind()  :  从后向前找
<pre>
string s1("hello world");
s1.find("lo"); 				//返回"lo"第一次出现的位置，若找到 返回l所在的下标，若没找到则返回string::npos
s1.find("lo",3);			//从下标3开始查找
</pre>
find_first_of()  :  查找第一次出现的位置  
find_last_of()	:	查找最后一次出现的位置
<pre>
s1.find_first_of("abcd");	//在s1中从前向后查找"abcd"中任何一个字符第一次出现的位置，若找不到，则返回string::npos
</pre>
find_first_not_of(s1) : 查找不存在于s1中的字符第一次出现的位置
find_last_not_of(s1) : 查找不存在于s1中的字符最后一次出现的位置
***
替换
erase()
<pre>
s1.erase(5);				//去掉下标5及以后的字符
</pre>
replace()
<pre>
s1.replace(2,3,"hahaha");	//从下标2开始的3个字符替换成 hahaha
</pre>
insert()
<pre>
s2 = "abcdefg";
s1.insert(5,s2);			//在下标5处插入s2
s1.insert(5,s2,3,2);		//在s1下标5处插入de
</pre>
c_str()  
返回const char *类型,以'\0'结尾
##Vector
