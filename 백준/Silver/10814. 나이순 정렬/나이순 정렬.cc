#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
	int age;
	string name;
	int order;
};

int main()
{
	int num;

	cin >> num;

	int ageTmp;
	string nameTmp;
	Person personTmp;

	vector<Person> arr;

	for (int i = 0; i < num; i++)
	{
		cin >> ageTmp;
		cin >> nameTmp;
		personTmp.age = ageTmp;
		personTmp.name = nameTmp;
		personTmp.order = i;
		arr.push_back(personTmp);
	}

	sort(arr.begin(), arr.end(), [](Person& a, Person& b)-> bool { if (a.age == b.age) return a.order < b.order; return a.age < b.age; });

	for (int i = 0; i < num; i++)
	{
		cout << arr[i].age << " " << arr[i].name << "\n";
	}
}