#pragma once
#include "ObjGrafico.h"
class Persecutor : public ObjGrafico {
private:
	double dxbase, dybase;
public:
	Persecutor(int n) : ObjGrafico(n + 500) { dxbase = dx, dybase = dy; };
	~Persecutor() {};
	void seguir(int xpj, int ypj) { dx = (xpj - x) / 500; dy = (ypj - y) / 500; };
	void resetseguir() { dx = pow(-1, rand() % 2)*dxbase, dy = pow(-1,rand()%2)*dybase; }
	void mostrar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle porcion = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho / 4.5, alto / 4.5);
		area = Rectangle(x, y, ancho / 4.5, alto / 4.5);
		buffer->Graphics->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	};
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (x + ancho / 4.5 > 545) dx = -abs(dx);		//
		if (y + alto / 4.5 > 552) dy = -abs(dy);		//
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
			if (skip % 6 == 0) {
				if (indiceX < 3) indiceX++;
				if (indiceX == 3) indiceX = 0;
			}
			skip++;
			if (skip > 100) skip = 0;
		}

		x += dx * vel*(0.7 + nivel / 5.0);
		y += dy * vel*(0.7 + nivel / 5.0);

		mostrar(buffer, bmp);
	}
};