#include "stdafx.h"
#include "Sentence.h"


Sentence::Sentence()
{
}


Sentence::~Sentence()
{
}

void Sentence::AddNextQuestionId(int value)
{
	nextquestionsid.push_back(value);
}

void Sentence::AddAnswer(std::string value)
{
	answers.push_back(value);
}

void Sentence::SetQuestion(std::string value)
{
	question = value;
}

std::string Sentence::GetAnswer(int index)
{
	return answers[index];
}

int Sentence::GetQuestionId(int index)
{
	return nextquestionsid[index];
}

std::string Sentence::GetQuestion()
{
	return question;
}

int Sentence::AnswersSize()
{
	return answers.size();
}

void Sentence::SetAction(Action *a)
{
	action = a;
}

int Sentence::DoAction(Player *p)
{
	if (action != NULL)
		return action->Do(p);
	else
		return 0;
}
