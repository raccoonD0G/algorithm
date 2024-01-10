#include <iostream>
#include <vector>

#define MAX_INPUT 40

using namespace std;

class Answer
{
public:
	int answer0;
	int answer1;

	Answer()
	{
		this->answer0 = -1;
		this->answer1 = -1;
	}

	Answer(int answer0, int answer1)
	{
		this->answer0 = answer0;
		this->answer1 = answer1;
	}

	Answer operator+(Answer answer)
	{
		return Answer(this->answer0 + answer.answer0, this->answer1 + answer.answer1);
	}
};

Answer GetAnswer(vector<Answer>& fibVec, int input)
{
	if (fibVec[input].answer0 != -1 && fibVec[input].answer1 != -1)
	{
		return fibVec[input];
	}
	else
	{
		if (input == 0)
		{
			fibVec[input].answer0 = 1;
			fibVec[input].answer1 = 0;
			return fibVec[input];
		}
		else if (input == 1)
		{
			fibVec[input].answer0 = 0;
			fibVec[input].answer1 = 1;
			return fibVec[input];
		}
		else
		{
			fibVec[input] = GetAnswer(fibVec, input - 1) + GetAnswer(fibVec, input - 2);
			return fibVec[input];
		}
	}
}

int main()
{
	int numberOfCase;
	cin >> numberOfCase;

	vector<Answer> fibVec(MAX_INPUT + 1);

	vector<int> inputVec(numberOfCase);

	for (int i = 0; i < numberOfCase; i++)
	{
		cin >> inputVec[i];
	}

	for (int i = 0; i < numberOfCase; i++)
	{
		Answer answer = GetAnswer(fibVec, inputVec[i]);
		cout << answer.answer0 << " " << answer.answer1 << "\n";
	}
}