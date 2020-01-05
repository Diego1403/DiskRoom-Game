#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
using namespace System;
using namespace System::Drawing;
class ObjGrafico {
protected:
	int ancho, alto, indiceX, indiceY, skip = 0;
	double x, y, dx, dy, vel, nivel=1;
	bool slow=0;
	double hardcore;
public:
	Rectangle area;
	ObjGrafico() : x(300), y(300), ancho(214), alto(274), dx(0), dy(0), indiceX(0), indiceY(0), vel(5), hardcore(0) {
		srand(time(NULL));
		dx = (rand() % 100) / 200.0 + 0.3, dy = (rand() % 100) / 200.0 + 0.3;		//	Para cuestiones de prueba
		vel = 5;
	};
	ObjGrafico(int n) : x(400), y(400), ancho(214), alto(274), dx(0), dy(0), indiceX(0), indiceY(0), vel(5), hardcore(0) {
		srand(n);
		dx = (rand() % 100) / 200.0 + 0.3, dy = (rand() % 100) / 200.0 + 0.3;		//	Para cuestiones de prueba
		vel = 5;
	};
	ObjGrafico(int X, int Y, int Ancho, int Alto) {
		x = X, y = Y, ancho = Ancho, alto = Alto, indiceX = 0, indiceY = 0, hardcore=0;
		srand(time(NULL));
		dx = (rand()%100)/200.0+0.3, dy = (rand()%100)/200.0+0.3;		//	Para cuestiones de prueba
		vel = 5;
	};
	~ObjGrafico() {};

	int getX() { return x; }
	int getY() { return y; }
	
	void setNivel(double niv) { nivel = niv; }
	void setSlow() { vel = 2, slow = 1; }
	void setNormal() { vel = 5, slow = 0; }

	void setHardcore() { hardcore = 1; }
	void setNormalSpeed() { hardcore = 0; }

	void mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle porcion = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho/3, alto/3);
		area = Rectangle(x, y, ancho / 3.6, alto / 3.6);
		buffer->Graphics->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	};

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (x + ancho/3 > 545) dx = -dx;		//
		if (y + alto/3 > 552) dy = -dy;			//
		if (x < 58) dx = abs(dx);				//	Para las sierras (pasarlo a otro .h)
		if (y < 47) dy = abs(dy);				//
		if (slow == 0) {
			if (skip % 3 == 0) {
				if (indiceX < 3) indiceX++;
				if (indiceX == 3) indiceX = 0;
			}
			skip++;
			if (skip > 100) skip = 0;
		}
		else if (slow == 1) {
			if (skip%6==0) {
				if (indiceX < 3) indiceX++;
				if (indiceX == 3) indiceX = 0;
			}
			skip++;
			if (skip > 100) skip = 0;
		}

		x += dx*vel*(0.7+hardcore+nivel/2.0);
		y += dy*vel*(0.7+hardcore+nivel/2.0);

		mostrar(buffer, bmp);
	}
};