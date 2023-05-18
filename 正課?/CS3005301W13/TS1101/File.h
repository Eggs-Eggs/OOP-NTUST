#pragma once

#include "Document.h"

class File : public Document
{
public:
	string pathname;

	File(string text, string pathname) : Document(text), pathname(pathname)
	{

	}

	void setPathname(string pathname)
	{
		this->pathname = pathname;
	}

	string getPathname()
	{
		return this->pathname;
	}
};

