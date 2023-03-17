#include "pch.h"
#include "Question.h"

std::string Question::getQuestion()
{
    return std::string();
}

bool Question::isCorrect(bool answer)
{
    return false;
}

bool Question::newQuestion()
{
    if (m_difficulty < 3) {
        op = Question::operators::add | Question::operators::divide;
    }
    switch (m_difficulty)
    {
    case 0:
        op
    default:
        break;
    }

    switch (rand()%4)
    {
    case 0://add
        
    default:
        break;
    }
    return false;
}

bool Question::setDifficulty(int difficulity)
{
    return false;
}
