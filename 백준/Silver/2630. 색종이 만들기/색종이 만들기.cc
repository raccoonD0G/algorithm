#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


class Answer
{
public:
    int blue;
    int white;
    Answer& operator+=(const Answer& a)
    {
        this->blue += a.blue;
        this->white += a.white;
        return *this;
    }
};

Answer GetAnswer(vector<vector<int>>& paper, int cut, int startRow, int startColumn)
{
    int blueCount = 0;
    int whiteCount = 0;
    for (int i = startRow; i < startRow + (paper.size() / cut); i++)
    {
        for (int j = startColumn; j < startColumn + (paper.size() / cut); j++)
        {
            if (paper[i][j] == 1) blueCount++;
            else whiteCount++;
        }
    }
    
    Answer answer;
    if (blueCount == 0)
    {
        answer.blue = 0;
        answer.white = 1;
        return answer;
    }
    else if (whiteCount == 0)
    {
        answer.blue = 1;
        answer.white = 0;
        return answer;
    }
    else
    {
        answer.blue = 0;
        answer.white = 0;
        answer += GetAnswer(paper, cut * 2, startRow, startColumn);
        answer += GetAnswer(paper, cut * 2, startRow, startColumn + paper.size() / (cut * 2));
        answer += GetAnswer(paper, cut * 2, startRow + paper.size() / (cut * 2), startColumn);
        answer += GetAnswer(paper, cut * 2, startRow + paper.size() / (cut * 2), startColumn + paper.size() / (cut * 2));
        return  answer;
    }
}
int main()
{
    int length = 0;
    cin >> length;
    
    vector<vector<int>> paper(length);
    
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            int tmp = 0;
            cin >> tmp;
            paper[i].push_back(tmp);
        }
    }

    Answer answer = GetAnswer(paper, 1, 0, 0);
    cout << answer.white << "\n";
    cout << answer.blue << "\n";
}