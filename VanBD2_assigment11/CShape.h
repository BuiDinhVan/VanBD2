#pragma once
#include<Windows.h>

/*********************************************************
* Description: draw shape class
**********************************************************/
class CShape {
public:
	int color;
	virtual	void draw(int x, int y, HDC hdc) = 0;
};

/*********************************************************
* Description: draw line class
**********************************************************/
class CLine : public CShape {
private:
	int length;
public:
	CLine(int length, int color);
	void draw(int x, int y, HDC hdc);
};

/*********************************************************
* Description: draw circle class
**********************************************************/
class CCircle : public CShape {
private:
	int radium;
public:
	CCircle(int radium, int color);
	void draw(int x, int y, HDC hdc);
};

/*********************************************************
* Description: draw rectangle class
**********************************************************/
class CRectangle : public CShape {
protected:
	int width;
	int heigh;
public:
	CRectangle() {};
	CRectangle(int width, int heigh, int color);
	void draw(int x, int y, HDC hdc);
};

/*********************************************************
* Description: draw square class
**********************************************************/
class CSquare : public CRectangle {
public:
	CSquare(int len, int color);
	void draw(int x, int y, HDC hdc);
};

/*********************************************************
* Description: draw picture class
**********************************************************/
class CPicture {
public:
	CShape* picture[4];
};