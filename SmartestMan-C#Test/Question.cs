using System;
using Windows.Gaming.Input.ForceFeedback;

namespace SmartestMan_C_Test
{
    public class Question
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
            return answer == m_isAnswerCorrect;
        }

        public bool newQuestion()
        {
            bool haveNegative = true;
            if (m_difficulty < 3)
            {
                haveNegative = false;
            }
            if (m_difficulty < 6)
            {
                spawnNumber(10, haveNegative);
            }
            else
            {
                spawnNumber(20, haveNegative);
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
                        do
                        {
                            second = rnd.Next(haveNegative ? -range : range, range);
                        } while (second == 0);
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

            return true;
        }

        private bool setLeftTime()
        {
            m_leftTime = m_score switch
            {
                1 => 1200,
                2 => 1400,
                3 => 1500,
                4 => 2200,
                5 => 2500,
                _ => 3000
            };
            return true;
        }
    }

}
