#include "pch.h"
#include "Coordinate.h"
#include <iostream>
using namespace std;

Coordinate::Coordinate(int x, int y) {
	m_iX = x;
	m_iY = y;
}

void Coordinate::printCoordinate() {
	cout << "(" << m_iX << ", " << m_iY << ")" << endl;
}

Coordinate &Coordinate::operator=(Coordinate &coordinate) {
	this->m_iX = coordinate.m_iX;
	this->m_iY = coordinate.m_iY;
	return *this;
}

bool Coordinate::operator==(Coordinate &coordinate) {
	if (this->m_iX == coordinate.m_iX && this->m_iY == coordinate.m_iY) {
		return true;
	}
	return false;
}

ostream &operator<<(ostream &out, Coordinate &coordinate) {
	out << "(" << coordinate.m_iX << ", " << coordinate.m_iY << ")";
	return out;
}
