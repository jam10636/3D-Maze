#include"Patherfinder.h"
#include<sstream>
#include<fstream>
#include<string>
bool Pathfinder::importMaze(string file)
{
	ifstream infile;
	string input;
	infile.open(file);
	string a;
	string x;
	string z;
	int b = 0;
	while (getline(infile, input))
	{
		int count = 0;
		if (count == 28)
		{
			x += input;
		}
		else
		{
			x += input + '\n';
		}
	}
	x;
	stringstream ss(x);
	while (ss >> z)
	{
		if (z != "1"&&z != "0")
		{
			return false;
		}
		b++;
		if (b == 1)
		{

			if (z != "1")
			{
				return false;
			}
		}
		if (b == 125)
		{
			if (z != "1")
			{
				return false;
			}
		}
	}
	if (b != 125)
	{
		return false;
	}
	stringstream sss(x);
	for (int i = 0; i < 5; i++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				sss >> a;
				mazelocation[y][z][i] = a;
			}
		}
	}
	maze = x;
	return true;
}
string Pathfinder::toString() const
{
	string x;
	if (maze.size() != 0)
	{
		return maze;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int z = 0; z < 5; z++)
				{
					if (z == 4)
					{
						x = x + "1";
					}
					else
					{
						x = x + "1" + " ";
					}
				}
				x = x + '\n';
			}
			if (i < 4)
			{
				x = x + '\n';
			}
		}
	}
	return x;
}
bool Pathfinder::findpath(string a[5][5][5], int row, int colum, int height)
{
	string axis;
	string yxis;
	string zxis;
	string whole;
	if (row < 0 || colum < 0 || height < 0 || row>4 || colum>4 || height>4)
	{
		return false;
	}
	else if (a[row][colum][height] != "1")
	{
		return false;
	}
	else if (row == 4 && colum == 4 && height == 4)
	{

		ostringstream ss;
		ss << colum;
		axis = ss.str();
		ss.str("");
		ss << row;
		yxis = ss.str();
		ss.str("");
		ss << height;
		zxis = ss.str();
		ss.str("");
		whole = "(" + axis + "," + " " + yxis + "," + " " + zxis + ")";
		solution.push_back(whole);
		a[row][colum][height] = "2";
		return true;
	}
	else
	{
		a[row][colum][height] = "0";
		{
			
			if (findpath(a, row - 1, colum, height) || findpath(a, row + 1, colum, height) || findpath(a, row, colum + 1, height) ||
				findpath(a, row, colum - 1, height) || findpath(a, row, colum, height + 1) || findpath(a, row, colum, height - 1))
			{
				ostringstream ss;
				ss << colum;
				axis = ss.str();
				ss.str("");
				ss << row;
				yxis = ss.str();
				ss.str("");
				ss << height;
				zxis = ss.str();
				ss.str("");
				whole = "(" + axis + "," + " " + yxis + "," + " " + zxis + ")";
				solution.push_back(whole);
				return true;
			}
			else
			{
				a[row][colum][height] = "3";
				return false;
			}
		}
	}
}
bool Pathfinder::findpath(string a[5][5][5])
{
	return findpath(a, 0, 0, 0);
}
vector<string> Pathfinder::solveMaze()
{
	b.clear();
	solution.clear();
	bool u=findpath(mazelocation);
	if (u==true)
	{
		int c = solution.size();
		for (int i = 0; i < solution.size(); i++)
		{
			c--;
			b.push_back(solution[c]);
		}
		return b;
	}
	else
	{
		vector<string>no;
		return no;
	}
}
void Pathfinder::createRandomMaze()
{
	//int x = 0;
	//string z;
	//string y;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int a = 0; a < 5; a++)
	//	{
	//		for (int b = 0; b < 5; b++)
	//		{
	//			x = rand() % 2;
	//			if (b == 0)
	//			{

	//				while (x != 1)
	//				{
	//					x = rand() % 2;
	//				}
	//				if (x == 1)
	//				{
	//					z = "1";
	//				}
	//				y += z + " ";
	//			}
	//			else if (i == 4 && b == 4)
	//			{
	//				x = rand() % 2;
	//				while (x != 1)
	//				{
	//					x = rand() % 2;
	//				}
	//				if (x == 1)
	//				{
	//					z = "1";
	//				}
	//				y += z;
	//			}
	//			else
	//			{
	//				if (x == 1)
	//				{
	//					z = "1";
	//				}
	//				else
	//				{
	//					z = "0";
	//				}
	//				y += z + " ";
	//			}
	//		}
	//		y += "\n";
	//	}
	//	if (i != 4)
	//	{
	//		y += "\n";
	//	}

	//}
	//maze = y;
	//stringstream ss(y);
	//string a;
	for (int i = 0; i < 5; i++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				mazelocation[y][z][i] = rand() % 2 ? "1" : "0";
			}
		}
	}

	mazelocation[0][0][0] = "1";
	mazelocation[4][4][4] = "1";
	string x;
	for (int i = 0; i < 5; i++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				if (z == 4)
				{
					x = x + mazelocation[y][z][i];
				}
				else
				{
					x = x + mazelocation[y][z][i] + " ";
				}
			}
			x = x + '\n';
		}
		x = x + '\n';
	}
	maze = x;

}