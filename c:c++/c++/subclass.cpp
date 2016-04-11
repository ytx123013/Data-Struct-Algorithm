#include <iostream>
class People
{
public:
	People(int a){
		age = a;
	}
	int get_people_age(){
		return age;
	}
private:
	int age;
};

class Student : public People
{
public:
	Student(int id, int age);
private:
	int id;
	
};

Student::Student(int id,int age):People(age){
	this->id = id;
}


int main(int argc, char const *argv[])
{
	Student s(1,2);
	std::cout << s.get_people_age() << std::endl;
	return 0;
}