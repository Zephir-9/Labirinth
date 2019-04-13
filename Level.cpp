#include "Level.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include "game.h"

Games::Level::Level()
{
	floorSymbol = 0;
		wallSymbol = 0;
		 exitSymbol = 0;
	 numLevel = width = height = personStartLine = personStartColumne = exitLine = exitColumne = 0;
	 area = 0;
	 areaMask = 0;
	 person = 0;

}

Games::Level::~Level()
{
	if (area != 0)
	{
		for (int i = 0; i < height; ++i)
		{
			delete[] area[i];
			delete[] areaMask[i];
		}
		delete[] area;
		delete[] areaMask;
	}
}

bool Games::Level::canMove(int line, int columne)
{
	return area[line][columne] != wallSymbol;
}

bool Games::Level::isExit(int line, int columne)
{
	return line == exitLine && columne == exitColumne;
}

void Games::Level::Print()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (areaMask[i][j])
			{
				if ((i != person->line || j != person->columne) && !isExit(i, j))
				{
					std::cout << area[i][j];
				}
				else if (isExit(i, j))
				{
					std::cout << exitSymbol;
				}
				else if((i == person->line || j == person->columne))
				{
					std::cout << person->symbol;
				}
			}
			else {
				std::cout << " ";
			}
		}
	}
}

void Games::Level::Load(char* filename)
{
	std::ifstream in(filename);
	char temp[256] = {0};
	in >> temp >> floorSymbol
		>> temp >> wallSymbol
		>> temp >> exitSymbol
		>> temp >> personStartLine
		>> temp >> personStartColumne
		>> temp >> exitLine
		>> temp >> exitColumne;

	if (area != 0)
	{
		for (int i = 0; i < height; ++i)
		{
			delete[] area[i];
			delete[] areaMask[i];
		}
		delete[] area;
		delete[] areaMask;
	}
	in >> temp >> height 
		>> temp >> width;

		area = new char* [height];
		areaMask = new bool*[height];

		for (int i = 0; i < height; ++i)
		{
			area[i] = new char[width];
			areaMask[i] = new bool[width];
		}
		in.get();

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				area[i][j] = in.get();
				areaMask[i][j] = false;
			}
			in.get();
		}

		in.close();
}