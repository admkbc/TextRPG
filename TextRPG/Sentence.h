#pragma once
#include <string>
#include <vector>
#include "Action.h"

class Sentence
{
private:
	std::string question;
	std::vector<std::string> answers;
	std::vector<int> nextquestionsid;
	Action *action;
public:
	Sentence();
	~Sentence();
	void AddNextQuestionId(int value);
	void AddAnswer(std::string value);
	void SetQuestion(std::string value);
	std::string GetAnswer(int index);
	int GetQuestionId(int index);
	std::string GetQuestion();
	int AnswersSize();
	void SetAction(Action *a);
	void DoAction(Player &p);
};

