#include <iostream>

using namespace std;

class Person
{
public:
	float weight;
	float height;
	int rank;
	Person();
	Person(float weight, float height);
	void SetPerson(float weight, float height);
};

Person::Person()
{
	this->weight = 0;
	this->height = 0;
	this->rank = 1;
}

Person::Person(float weight, float height)
{
	this->weight = weight;
	this->height = height;
	rank = 1;
}

void Person::SetPerson(float weight, float height)
{
	this->weight = weight;
	this->height = height;
	rank = 1;
}


int main()
{
	int personNum;
	cin >> personNum;
	Person* personArr;
	personArr = new Person[personNum];

	for (int i = 0; i < personNum; i++)
	{
		int tmpWeight;
		int tmpHeight;

		cin >> tmpWeight >> tmpHeight;

		personArr[i].SetPerson(tmpWeight, tmpHeight);
	}

	for (int i = 0; i < personNum; i++)
	{
		for (int j = 0; j < personNum; j++)
		{
			if (i != j)
			{
				if (personArr[j].weight > personArr[i].weight && personArr[j].height > personArr[i].height)
				{
					personArr[i].rank++;
				}
			}
		}
	}

	for (int i = 0; i < personNum; i++)
	{
		cout << personArr[i].rank << ' ';
	}
}