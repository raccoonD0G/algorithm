/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Meeting
{
public:
    int startTime;
    int endTime;
    bool isChecked;
};

int main()
{
    int numOfMeeting = 0;
    
    cin >> numOfMeeting;
    
    vector<Meeting> meetingVec(numOfMeeting);
    
    for (int i = 0; i < numOfMeeting; i++)
    {
        cin >> meetingVec[i].startTime >> meetingVec[i].endTime;
        meetingVec[i].isChecked = false;
    }
    
    sort(meetingVec.begin(), meetingVec.end(), [](Meeting a, Meeting b)->bool{ if (a.endTime != b.endTime) return a.endTime < b.endTime; else return a.startTime < b.startTime; });
    int lastStartTime = 0;
    int lastEndTime = 0;
    int count = 0;
    
    for (int i = 0; i < numOfMeeting; i++)
    {
        if (meetingVec[i].isChecked == false)
        {
            if (lastEndTime <= meetingVec[i].startTime)
            {
                count++;
                lastStartTime = meetingVec[i].startTime;
                lastEndTime = meetingVec[i].endTime;
                meetingVec[i].isChecked = true;
            }
        }
    }
    
    cout << count;
    
    return 0;
}