#include <iostream>

using namespace std;

int main()
{
	int moveF, moveB, goal;
	cin >> moveF >> moveB >> goal;

	int position = 0;
	int day = 0;
	int disLeft = 0;
	int movePerDay = moveF - moveB;

	int trueGoal = goal - moveF;

	disLeft = trueGoal % movePerDay;
	day = trueGoal / movePerDay;

	if (disLeft == 0) cout << day + 1;
	else cout << day + 2;
}