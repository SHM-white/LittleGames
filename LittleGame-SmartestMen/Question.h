#pragma once
class Question
{
public:
	std::string getQuestion();
	bool isCorrect(bool answer);
	bool newQuestion();
	bool setDifficulty(int difficulity);
	int score;
private:
	int m_firstNumber;
	int m_secondNumber;
	enum operators
	{
		add,
		minus,
		multiply,
		divide
	};
	operators op;
	int m_result;
	int m_difficulty;
};

