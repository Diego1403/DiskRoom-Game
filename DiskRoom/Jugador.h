#pragma once
#include "ObjGrafico.h"
enum Direccion { Up, Down, Left, Right, None };
class Jugador : public ObjGrafico {
public:
	Direccion direccion;
	Direccion dir_anterior;
	int vidas;
	int vidasbase;
	bool protec;
public:
	Jugador() {
		x = 300, y = 300, ancho = 114, alto = 137, dx = 0, dy = 0, indiceX = 0, indiceY = 0, vel = 5, direccion = None, dir_anterior = None, vidas=3, vidasbase=3, protec=0;
	};
	~Jugador() {};

	void setDir(Direccion dir) { if (direccion!=dir) dir_anterior = direccion; direccion = dir; }
	void setSlow() { vel = 2, slow = 1; }
	void setNormal() { vel = 5, slow = 0; }
	void setVidasbase(int n) { vidasbase = n; }
	void lostVidas() { if (vidas>=1) vidas--; }
	void resetVidas() { vidas = vidasbase; }
	void toggleProtec() { if (protec == 0) protec = 1; else protec = 0; }
	void resetpos() { x = 300, y = 300, dx = 0, dy = 0, indiceX = 0, indiceY = 0, vel = 5, direccion = None, dir_anterior = None, vidas = 3, protec=0; }
	

	bool getSlow() { return slow; }

	void dibujar(BufferedGraphics ^buffer, Bitmap ^bmpLeft, Bitmap ^bmpRight, Bitmap ^bmpUp, Bitmap ^bmpDown, Bitmap^ bmpPLeft, Bitmap^ bmpPRight, Bitmap^ bmpPUp, Bitmap^ bmpPDown) {
		
		Rectangle porcion = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho / 3.5, alto / 3.5);
		area = Rectangle(x, y, ancho/5.3, alto/5.8);
		Bitmap^ bmpDir;
		switch (direccion)
		{
		case Up:	bmpDir = bmpUp;		break;
		case Down:	bmpDir = bmpDown;		break;
		case Left:	bmpDir = bmpLeft;		break;
		case Right: bmpDir = bmpRight;	break;
		case None: switch (dir_anterior)	//	Direccion previa
		{
		case Up: bmpDir = bmpUp;	break;
		case Down: bmpDir = bmpDown;	break;
		case Left: bmpDir = bmpLeft;	break;
		case Right: bmpDir = bmpRight;	break;
		case None: bmpDir = bmpDown;	break;
		} break;
		}
		if (protec == 1&&vidas!=3) {
			if (bmpDir == bmpUp) bmpDir = bmpPUp;
			else if (bmpDir == bmpDown) bmpDir = bmpPDown;
			else if (bmpDir == bmpLeft) bmpDir = bmpPLeft;
			else if (bmpDir == bmpRight) bmpDir = bmpPRight;
		}
		buffer->Graphics->DrawImage(bmpDir, zoom, porcion, GraphicsUnit::Pixel);
	}
	void mover(BufferedGraphics ^buffer, Bitmap ^bmpLeft, Bitmap ^bmpRight, Bitmap ^bmpUp, Bitmap ^bmpDown, Bitmap^ bmpPLeft, Bitmap^ bmpPRight, Bitmap^ bmpPUp, Bitmap^ bmpPDown) {
		
		switch (direccion)
		{
		case Up:	dy = -1, y += dy * vel*(1 + nivel / 7.0);	break;
		case Down:	dy = 1, y += dy * vel*(1 + nivel / 7.0);	break;
		case Left:	dx = -1, x += dx * vel*(1 + nivel / 7.0);	break;
		case Right:	dx = 1, x += dx * vel*(1 + nivel / 7.0);	break;
		case None:	dx = 0, dy = 0;			break;
		}
		if (x < 50) x = 50;	if (y < 35) y = 35;	//	Limites del mapa
		if (x + ancho / 3.5 > 550) x = 550 - ancho / 3.5; if (y + alto / 3.5 > 543) y = 543 - alto / 3.5;	//	Limites del mapa

		if (slow == 0) {
			if (skip % 4 == 0) {
				if (direccion != None) indiceX++;	//	Movimiento del sprite
				if (indiceX == 3) indiceX = 0;	//	Loop del sprite
			}
			skip++;
			if (skip > 100) skip = 0;
		}
		else if (slow == 1) {
			if (skip % 8 == 0) {
				if (direccion != None) indiceX++;
				if (indiceX == 3) indiceX = 0;
			}
			skip++;
			if (skip > 100) skip = 0;
		}
		dibujar(buffer, bmpLeft, bmpRight, bmpUp, bmpDown, bmpPLeft, bmpPRight, bmpPUp, bmpPDown);
	}
	void dibujarVida(BufferedGraphics ^buffer, Bitmap ^bmp) {
		for (int i = 0; i<vidas; i++) {
			Rectangle porcion = Rectangle(0, 0, 300, 280);
			Rectangle zoom = Rectangle(540 - i * 22, 547, 300 / 15, 280 / 15);
			buffer->Graphics->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
		}
	}
	
};