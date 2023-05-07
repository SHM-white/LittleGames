#pragma once
class Question
{
public:
	Question(int difficulty) :m_difficulty{ difficulty } {};
	std::string getQuestion();
	int TickRun(int tick);
	bool isCorrect(bool answer);
	bool newQuestion();
	bool setDifficulty(int difficulty);
	int m_score;
private:
	int m_leftTime{0};
	int m_firstNumber;
	int m_secondNumber;
	int m_correctAnswer;
	int m_notCorrectAnswer;
	bool m_isAnswerCorrect;
	enum operators
	{
		add,
		minus,
		multiply,
		divide
	};
	operators op;
	int m_result;
	int m_difficulty{5};
	bool spawnNumber(int range, bool haveNegative);
	bool setLeftTime();
};

