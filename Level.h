#pragma once
namespace Games
{

	class Person;


	class Level
	{
	public:
		char floorSymbol;
		char wallSymbol;
		char exitSymbol;

		int numLevel;
		int width;
		int height;
		char** area;
		bool** areaMask;
		Person* person;
		int personStartLine;
		int personStartColumne;
		int exitLine;
		int exitColumne;

		Level();
		~Level();
		void Load(char* filename);
		void Print();
		bool canMove(int line, int columne);
		bool isExit(int line, int columne);
	};
}