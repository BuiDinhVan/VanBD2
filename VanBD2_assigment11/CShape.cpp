#include<iostream>
#include"CShape.h"
using namespace std;

/*********************************************************
* Input: length, color of Line
* Description: Constructor function
**********************************************************/
CLine::CLine(int length, int color) {
	this->length = length;
	this->color = color;
}

/*********************************************************
* Input: start point of Line
* Description: draw line function
**********************************************************/
void CLine::draw(int x, int y, HDC hdc) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 5, colorr);
	SelectObject(hdc, pen);
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x + length, y);	
}

/*********************************************************
* Input: radium, color of Circle
* Description: Constructor function
**********************************************************/
CCircle::CCircle(int radium, int color) {
	this->radium = radium;
	this->color = color;
}

/*********************************************************
* Input: center point of Circle
* Description: draw circle function
**********************************************************/
void CCircle::draw(int x, int y, HDC hdc) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 3, colorr);
	SelectObject(hdc, pen);
	Ellipse(hdc, x, y, x + 2 * radium, y + 2 * radium);
}

/*********************************************************
* Input: width, heigh, color of Rectangle
* Description: Constructor function
**********************************************************/
CRectangle::CRectangle(int width, int heigh, int color) {
	this->width = width;
	this->heigh = heigh;
	this->color = color;
}

/*********************************************************
* Input: start point of Rectangle
* Description: draw rectangle function
**********************************************************/
void CRectangle::draw(int x, int y, HDC hdc) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 3, colorr);
	SelectObject(hdc, pen);
	Rectangle(hdc, x, y, x + width, y + heigh);
}

/*********************************************************
* Input: length, color of Square
* Description: Constructor function
**********************************************************/
CSquare::CSquare(int len, int color) {
	this->width = len;
	this->heigh = len;
	this->color = color;
}

/*********************************************************
* Input: start point of Square
* Description: draw square function
**********************************************************/
void CSquare::draw(int x, int y, HDC hdc) {
	COLORREF colorr = RGB(color >> 16, (color & 0xff00) >> 8, color & 0xff);
	HPEN pen = CreatePen(PS_SOLID, 3, colorr);
	SelectObject(hdc, pen);
	Rectangle(hdc, x, y, x + width, y + heigh);
}

int main() {
	CPicture Pic;
	Pic.picture[0] = new CLine(100, 0xff0000);
	Pic.picture[1] = new CCircle(10, 0x00ff00);
	Pic.picture[2] = new CRectangle(20, 10, 0x0000ff);
	Pic.picture[3] = new CSquare(20, 0xaabbcc);
	HWND console_hanle = GetConsoleWindow();
	HDC device_context = GetDC(console_hanle);
	
	int line = 70;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j != i) {
				for (int k = 0; k < 4; k++) {
					if (k != j && k != i) {				
						for (int l = 0; l < 4; l++) {
							if (l != k && l != j && l != i) {
								Pic.picture[i]->draw(100, line, device_context);
								Pic.picture[j]->draw(300, line, device_context);
								Pic.picture[k]->draw(500, line, device_context);
								Pic.picture[l]->draw(700, line, device_context);
								line += 50;
							}
						}
					}
				}
			}
		}
	}
	ReleaseDC(console_hanle, device_context);
	return 0;
}