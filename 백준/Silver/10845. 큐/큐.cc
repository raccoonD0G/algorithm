#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
	queue<int> m_queue;

	int m_num;
	cin >> m_num;

	vector<string> m_inputArr;
	string m_tmp;

	cin.ignore();

	for (int i = 0; i < m_num; i++)
	{
		getline(cin, m_tmp);
		m_inputArr.push_back(m_tmp);
	}

	int m_new;
	for (int i = 0; i < m_num; i++)
	{
		if (m_inputArr[i].find("push") != string::npos)
		{
			m_new = stoi(m_inputArr[i].substr(4, m_inputArr[i].size()));
			m_queue.push(m_new);
		}
		else if (m_inputArr[i] == "pop")
		{
			if (m_queue.size() > 0)
			{
				cout << m_queue.front();
				m_queue.pop();
			}
			else cout << -1;
			cout << "\n";
		}
		else if (m_inputArr[i] == "size")
		{
			cout << m_queue.size();
			cout << "\n";
		}
		else if (m_inputArr[i] == "empty")
		{
			if (m_queue.size() == 0) cout << 1;
			else cout << 0;
			cout << "\n";
		}
		else if (m_inputArr[i] == "front")
		{
			if (m_queue.size() > 0) cout << m_queue.front();
			else cout << -1;
			cout << "\n";
		}
		else if (m_inputArr[i] == "back")
		{
			if (m_queue.size() > 0) cout << m_queue.back();
			else cout << -1;
			cout << "\n";
		}
	}
}