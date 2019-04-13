#pragma once
namespace Games
{

	class Person;
	class Level;

	class Game
	{
	public:
		char** levelNames;
		Person* person;
		Level* level;
		int levelsCount;

		Game();
		~Game();

		void initialize();
		void Run();

	};
}