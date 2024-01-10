#include <iostream>
#include <cmath>

using namespace std;

void AddAnswer(unsigned long long& answer, int x, int y, unsigned long long width, unsigned long long height)
{
    unsigned long long halfWidth = width / 2;
    unsigned long long halfHeight = height / 2;

    if (x < halfWidth && y < halfHeight)
    {
        answer += 0;
    }
    else if (x < width && y < halfHeight)
    {
        answer += 1 * (width * height) / 4;
        x -= halfWidth;
    }
    else if (x < halfWidth && y < height)
    {
        answer += 2 * ((width * height) / 4);
        y -= halfHeight;
    }
    else
    {
        answer += 3 * ((width * height) / 4);
        x -= halfWidth;
        y -= halfHeight;
    }

    width = halfWidth;
    height = halfHeight;

    if (width == 1 || height == 1) return;

    AddAnswer(answer, x, y, width, height);

}

int main()
{
    int n, row, column;

    cin >> n >> column >> row;

    unsigned long long width, height;
    width = pow(2, n);
    height = width;

    unsigned long long answer = 0;
    AddAnswer(answer, row, column, width, height);
    cout << answer;
}