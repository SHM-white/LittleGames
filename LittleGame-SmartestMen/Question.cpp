#include "pch.h"
#include "Question.h"
#include <format>

std::string Question::getQuestion()
{
    std::string first{ m_firstNumber < 0 ? std::format("({})",m_firstNumber):std::format("{}",m_firstNumber) };
    std::string second{ m_secondNumber < 0 ? std::format("({})",m_secondNumber) : std::format("{}",m_secondNumber) };
    std::string operate;
    switch (op)
    {
    case Question::add:
        operate = "+";
        break;
    case Question::minus:
        operate = "-";
        break;
    case Question::multiply:
        operate = "*";
        break;
    case Question::divide:
        operate = "/";
        break;
    default:
        break;
    }
    std::string result{ std::to_string(m_isAnswerCorrect ? m_correctAnswer : m_notCorrectAnswer) };
    return first + operate + second + "=" + result;
}

int Question::TickRun(int tick)
{
    rand();
    if (m_leftTime) {
        m_leftTime -= tick;
    }
    return max(m_leftTime,0);
}

bool Question::isCorrect(bool answer)
{
    if (answer == m_isAnswerCorrect) { return true; }
    else { return false; }
}

bool Question::newQuestion()
{
    int questionType;
    m_score = 1;
    if (m_difficulty < 5) {
        questionType = rand() % 2;
    }
    else {
        questionType = rand() % 4;
    }

    switch (questionType)
    {
    case 0:
        op = add;
        if (m_difficulty < 2) {
            spawnNumber(10, false);
        }
        else if (m_difficulty < 4) {
            spawnNumber(20, false);
            m_score = 2;
        }
        else {
            spawnNumber(20, true);
            m_score = 3;
        }
        break;
    case 1:
        op = minus;
        if (m_difficulty < 2) {
            spawnNumber(10, false);
        }
        else if (m_difficulty < 4) {
            spawnNumber(20, false);
            m_score = 2;
        }
        else {
            spawnNumber(20, true);
            m_score = 3;
        }
        break;
    case 2:
        op = multiply;
        if (m_difficulty < 6) {
            spawnNumber(10, false);
            m_score = 3;
        }
        else {
            spawnNumber(10, true);
            m_score = 4;
        }
        break;
    case 3:
        op = divide;
        if (m_difficulty < 6) {
            spawnNumber(10, false);
            m_score = 3;
        }
        else {
            spawnNumber(10, true);
            m_score = 4;
        }
        break;
    default:
        break;
    }
    setLeftTime();
    m_isAnswerCorrect = rand() % 2;
    switch (op)
    {
    case Question::add:
        m_correctAnswer = m_firstNumber + m_secondNumber;
        break;
    case Question::minus:
        m_correctAnswer = m_firstNumber - m_secondNumber;
        break;
    case Question::multiply:
        m_correctAnswer = m_firstNumber * m_secondNumber;
        break;
    case Question::divide:
        while (m_secondNumber == 0) { m_secondNumber += 1; }
        m_correctAnswer = m_firstNumber / m_secondNumber;
        if ((m_correctAnswer * m_secondNumber) != m_firstNumber) {
            m_isAnswerCorrect = false;
        }
        break;
    default:
        break;
    }
    if (!m_isAnswerCorrect) {
        do {
            m_notCorrectAnswer = m_correctAnswer + (rand() % 10 - 5);
        } while (m_notCorrectAnswer == m_correctAnswer);
    }
    else {
        m_notCorrectAnswer = m_correctAnswer;
    }
    return true;
}

bool Question::setDifficulty(int difficulty)
{
    m_difficulty = difficulty;
    return true;
}

bool Question::setLeftTime()
{
    switch (m_score)
    {
    case 1:m_leftTime = 1200; break;
    case 2:m_leftTime = 1400; break;
    case 3:m_leftTime = 1500; break;
    case 4:m_leftTime = 2200; break;
    case 5:m_leftTime = 2500; break;
    default:
        break;
    }
    return false;
}

bool Question::spawnNumber(int range, bool haveNegative)
{
    if (haveNegative) {
        m_firstNumber = rand() % (range * 2) - range;
        m_secondNumber = rand() % (range * 2) - range;
    }
    else {
        m_firstNumber = rand() % range;
        m_secondNumber = rand() % range;
    }
    return true;
}





