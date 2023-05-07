using System;

class Question
{
    public int m_score;
    private int m_leftTime = 0;
    private int m_firstNumber;
    private int m_secondNumber;
    private int m_correctAnswer;
    private int m_notCorrectAnswer;
    private bool m_isAnswerCorrect;
    private enum operators
    {
        add,
        minus,
        multiply,
        divide
    };
    private operators op;
    private int m_result;
    private int m_difficulty = 5;

    public Question(int difficulty)
    {
        m_difficulty = difficulty;
    }

    public string getQuestion()
    {
        return $"{m_firstNumber} {op} {m_secondNumber} = ?";
    }

    public int TickRun(int tick)
    {
        m_leftTime -= tick;
        if (m_leftTime <= 0)
        {
            m_leftTime = 0;
            return 0;
        }
        return m_leftTime;
    }

    public bool isCorrect(bool answer)
    {
        if (answer == m_isAnswerCorrect)
        {
            m_score += m_difficulty;
            return true;
        }
        else
        {
            m_score -= m_difficulty;
            return false;
        }
    }

    public bool newQuestion()
    {
        bool haveNegative = true;
        if (m_difficulty < 0)
        {
            haveNegative = false;
        }
        if (!spawnNumber(m_difficulty, haveNegative))
        {
            return false;
        }
        setLeftTime();
        return true;
    }

    public bool setDifficulty(int difficulty)
    {
        if (difficulty < 1 || difficulty > 10)
        {
            return false;
        }
        m_difficulty = difficulty;
        return true;
    }

    private bool spawnNumber(int range, bool haveNegative)
    {
        Random rnd = new Random();
        int first = rnd.Next(0, range);
        int second = rnd.Next(0, range);
        if (haveNegative)
        {
            first = rnd.Next(-range, range);
            second = rnd.Next(-range, range);
        }
        op = (operators)rnd.Next(0, 4);
        switch (op)
        {
            case operators.add:
                m_correctAnswer = first + second;
                break;
            case operators.minus:
                m_correctAnswer = first - second;
                break;
            case operators.multiply:
                m_correctAnswer = first * second;
                break;
            case operators.divide:
                if (second == 0)
                {
                    return false;
                }
                m_correctAnswer = first / second;
                break;
        }
        m_firstNumber = first;
        m_secondNumber = second;
        m_isAnswerCorrect = true;
        if (rnd.Next(0, 2) == 0)
        {
            m_notCorrectAnswer = m_correctAnswer + rnd.Next(1, 10);
            m_isAnswerCorrect = false;
        }
        else
        {
            m_notCorrectAnswer = m_correctAnswer - rnd.Next(1, 10);
        }
        return true;
    }

    private bool setLeftTime()
    {
        m_leftTime = m_difficulty * 10;
        return true;
    }
}
