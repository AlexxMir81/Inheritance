#include<iostream>
#include<string>

using namespace std;

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const std::string& get_last_name()const
	{
		return last_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HKonstrucror:\t" << endl;
	}
	~Human()
	{
		cout << "HDestrucror:\t" << endl;
	}
	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет\n";
	}
};

void main()
{

	setlocale(LC_ALL, "");
	Human human("Тупенко", "Василий", 18);
	human.print();
}