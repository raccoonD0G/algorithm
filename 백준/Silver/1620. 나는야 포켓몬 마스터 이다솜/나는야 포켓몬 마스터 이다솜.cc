#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Pokemon
{
public:
    int num;
    string name;
};

class Question
{
public:
    int num;
    string name;
    bool isNumQues;
};

Question FindAnswer(const vector<Pokemon>& pokemonVec, const vector<Pokemon>& sortedPokemonVec, const Question& ques)
{
    Question answer;
    if (ques.isNumQues == true)
    {
        answer.name = pokemonVec[ques.num - 1].name;
        answer.isNumQues = true;
    }
    else
    {

        answer.num = (*lower_bound(sortedPokemonVec.begin(), sortedPokemonVec.end(), ques.name, [](const Pokemon& a, const string& b) { return a.name < b; })).num;
        answer.isNumQues = false;
    }
    return answer;
}

int main()
{
    int numOfPokemon = 0;
    int numOfQuestion = 0;
    cin >> numOfPokemon >> numOfQuestion;

    vector<Pokemon> pokemonVec(numOfPokemon);

    for (int i = 0; i < numOfPokemon; i++)
    {
        pokemonVec[i].num = i;
        cin >> pokemonVec[i].name;
    }

    vector<Question> quesVec(numOfQuestion);

    for (int i = 0; i < numOfQuestion; i++)
    {
        Question tmpQues;
        cin >> tmpQues.name;
        if (tmpQues.name[0] >= '0' && tmpQues.name[0] <= '9')
        {
            tmpQues.num = stoi(tmpQues.name);
            tmpQues.name = "";
            tmpQues.isNumQues = true;
        }
        else
        {
            tmpQues.num = -1;
            tmpQues.isNumQues = false;
        }
        quesVec[i] = tmpQues;
    }

    vector<Question> answerVec(numOfQuestion);
    vector<Pokemon> sortedPokemonVec(pokemonVec);
    sort(sortedPokemonVec.begin(), sortedPokemonVec.end(), [](Pokemon a, Pokemon b)->bool { return a.name < b.name; });

    for (int i = 0; i < numOfQuestion; i++)
    {
        Question tmpQues = FindAnswer(pokemonVec, sortedPokemonVec, quesVec[i]);
        if (tmpQues.isNumQues == false)
        {
            cout << tmpQues.num + 1 << "\n";
        }
        else
        {
            cout << tmpQues.name << "\n";
        }
    }
}