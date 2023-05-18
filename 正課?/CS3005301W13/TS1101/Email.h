#pragma once

#include "Document.h"

class Email : public Document
{
public:
	string sender;
	string recipient;
	string title;

	Email(string text, string sender, string recipient, string title) : Document(text), sender(sender), recipient(recipient), title(title)
	{

	}

	Email& operator=(Email copy)
	{
		this->text = copy.text;
		this->sender = copy.sender;
		this->recipient = copy.recipient;
		this->title = copy.title;

		return *this;
	}

	string getSender() const
	{
		return sender;
	}
	string getRecipient() const
	{
		return recipient;
	}
	string getTitle() const
	{
		return title;
	}
};

