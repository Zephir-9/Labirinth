#pragma once
namespace Games
{
	class Level;


	class Person
	{
	public:
		int lookRadius;
		int line;
		int columne;
		Level* level;
		char symbol;

		Person(int line, int columne,int lookRadius, Level *level, char symbol);
		void Move(int command);
		void lookAround();

	};
}