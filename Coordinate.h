#ifndef COORDINATE_H
#define COORDINATE_H

#include <ostream>
using namespace std;

class Coordinate {
	friend ostream &operator<<(ostream &out, Coordinate &coordinate);
public:
	Coordinate(int x = 0, int y = 0);
	void printCoordinate();
	Coordinate &operator=(Coordinate &coordinate);
	bool operator==(Coordinate &coordinate);

private:
	int m_iX;
	int m_iY;
};

#endif
