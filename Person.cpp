#include "Person.h"
#include "Level.h"

Games::Person::Person(int line, int columne, int lookRadius, Level *level, char symbol)
{
	this->line = line;
	this->columne = columne;
	this->lookRadius = lookRadius;
	this->level = level;
	this->symbol = symbol;
}


void Games::Person::Move(int command)
{
	switch (command)
	{
	case ('w'):
		if (level->canMove(line - 1, columne)) --line;

		break;
	case('a'):
		if (level->canMove(line, columne - 1)) --columne;
		break;
	case('d'):
		if (level->canMove(line, columne + 1)) ++columne;
		break;
	case('s'):
		if (level->canMove(line + 1, columne)) ++line;
		break;
	default:
		break;
	}
}

void Games::Person::lookAround()
{
	for (int i = 0; i < level->height; ++i)
	{
		for (int j = 0; j < level->width; ++j)
		{
			if ((line - i) * (line - i) + (columne - j) * (columne - j) <= lookRadius * lookRadius)
			{
				level->areaMask[i][j] = true;
			}
		}
	}
}