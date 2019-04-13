#include "game.h"
#include "Level.h"
#include "Person.h"
#include <fstream>
#include <iostream>

Games::Game::Game()
{
	auto level = NULL;
	auto person = NULL;
	auto levelNames = NULL;
	auto levelsCount = NULL;
}

//Запуск игры
void Games::Game::initialize()
{
	std::ifstream in("Levels.txt");
	int  maxFileNamesLenght = 0;
	char temp[256] = { 0 };

	in >> temp >> levelsCount >> temp >> maxFileNamesLenght;

	levelNames = new char* [levelsCount];
	for (int i = 0; i < levelsCount; i++)
	{
		levelNames[i] = new char[maxFileNamesLenght];
	}

	in.get();
	for (int i = 0; i < levelsCount; i++)
	{
		in.getline(levelNames[i], maxFileNamesLenght);
	}
	in.close();

	level = new Games::Level();
	level->numLevel = 1;
	level->Load(levelNames[0]);

	char personSymbol = 0;
	int lookRadius = 0;
	in = std::ifstream("Person.txt");
	in >> temp >> personSymbol >> temp >> lookRadius;

	person = new Games::Person(level->personStartLine, 
								level->personStartColumne, 
								lookRadius, level, personSymbol);
	level->person = person;
}

//Логика игры
void Games::Game::Run()
{
	char command = 0;
	while (command != 'q')
	{
		system("cls");
		person->lookAround();

		level->Print();
		command = _getch();
		person->Move(command);

		if (level->isExit(person->line, person->columne))
		{
			if (levelsCount > level->numLevel)
			{
				level->Load(levelNames[level->numLevel]);
				++(level->numLevel);
				person->line = level->personStartLine;
				person->columne = level->personStartColumne;
			}
			else
			{
				std::cout << "\nYou win!\n";
				system("pause");
				break;
			}
		}
	}
}

//Дуструктор
Games::Game::~Game()
{
	if (levelsCount > 0)
	{
		for (int i = 0; i < levelsCount; i++)
		{
			delete[] levelNames[i];
		}
		delete levelNames;
	}
}