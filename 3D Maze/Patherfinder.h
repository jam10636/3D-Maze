#pragma once
#include"PathfinderInterface.h"
#include<ctime>
#include<vector>
class Pathfinder :public PathfinderInterface
{
public:
	Pathfinder() {
		srand(time(0));
	}
	string toString() const;
	bool importMaze(string file_name);
	vector<string> solveMaze();
	bool findpath(string x[5][5][5]);
	bool findpath(string x[5][5][5], int row, int colum, int height);
	void createRandomMaze();
private:
	string maze;
	string mazelocation[5][5][5];
	vector<string>solution;
	vector<string>b;
}; 
