#pragma once
#include "Jugador.h"
#include "VectorSpin.h"
#include "VectorPers.h"
using namespace System::Drawing;

enum Pantalla { MenuPrincipal, Niveles, Config, Creditos, Gameover, Juego };

class UPCDiskRoom {
private:
	short nivel;
	bool slow;
	int gameoverframes = 0;
	int cooldown = 0;
public:
	int restricSlow = 0;
	Jugador * pj;
	VectorSpin* ListaSp;
	VectorPers* ListaPr;
	UPCDiskRoom() : nivel(1) {
		pj = new Jugador();
		ListaSp = new VectorSpin();
		ListaPr = new VectorPers();
	};
	~UPCDiskRoom() {};
	
		//Faltaría implementar de acuerdo al diagrama de clases
	short getNivel() { return nivel; }
	void setNivel(short n) { nivel = n, pj->setNivel(n), ListaSp->SetNivel(n), ListaPr->SetNivel(n), clear(), restricSlow = 2 * nivel - 2;
	if (nivel == 1) { newSp(3), newPr(1); }
	else if (nivel == 2) { newSp(3), newPr(2); }
	else if (nivel==3) { newSp(4), newPr(1); }
	else if (nivel == 4) { newSp(4), newPr(2); }
	else if (nivel == 5) { newSp(5), newPr(3); }
	}
	void resetframes() { gameoverframes = 0; }

	void setFondo(BufferedGraphics^ buffer, Bitmap^m1, Bitmap^m2, Bitmap^m3, Bitmap^m4, Bitmap^m5, Bitmap^m1s, Bitmap^m2s, Bitmap^m3s, Bitmap^m4s, Bitmap^m5s, int slw) {
		Rectangle tamanio = Rectangle(0, 0, 1080, 1080);
		Rectangle zoom = Rectangle(0, 0, 600, 600);
		Bitmap^ mapa;
		if (slw == 0) {
			switch (nivel)
			{
			case 1: mapa = m1; break;
			case 2: mapa = m2; break;
			case 3: mapa = m3; break;
			case 4: mapa = m4; break;
			case 5: mapa = m5; break;
			default: break;
			}
		}
		else if (slw == 1) {
			switch (nivel)
			{
			case 1: mapa = m1s; break;
			case 2: mapa = m2s; break;
			case 3: mapa = m3s; break;
			case 4: mapa = m4s; break;
			case 5: mapa = m5s; break;
			default: break;
			}
		}
		buffer->Graphics->DrawImage(mapa, zoom, tamanio, GraphicsUnit::Pixel);
	};
	void gameover(BufferedGraphics^ buffer, Bitmap^ gameover, Graphics^ g) {
		if (gameoverframes < 8) {
			Rectangle tamanio = Rectangle(0,0,2000,200);
			Rectangle zoom = Rectangle(0, 260, 600, 65);
			buffer->Graphics->DrawImage(gameover, zoom, tamanio, GraphicsUnit::Pixel);
			buffer->Render(g);
		}
		if (gameoverframes<8) gameoverframes++;
		ListaPr->clear();
		ListaSp->clear();
		
	}
	void setSlow() { 
		if (restricSlow > 0) {
			pj->setSlow(), ListaSp->SetSlow(), ListaPr->SetSlow(); 
		}
	}
	void setNormal() { pj->setNormal(), ListaSp->SetNormal(), ListaPr->SetNormal(); }
	void resetSeguir() { ListaPr->resetSeguir(); }


	void newSp(int n) {
		for (int i = 0; i < n; i++) {
			Spinning* aux = new Spinning(ListaSp->size() + 1); ListaSp->agregar(aux);
		}
	}
	void newPr(int n) {
		for (int i = 0; i < n; i++) {
			Persecutor* aux = new Persecutor(ListaPr->size() + 1); ListaPr->agregar(aux);
		}
	}
	void clear() { ListaSp->clear(), ListaPr->clear(); }

	void colision() {
		for (int i = 0; i < ListaSp->size(); i++) {
			if (pj->area.IntersectsWith(ListaSp->area(i))) {
					if (cooldown == 0) pj->lostVidas(), cooldown = 1;
			}
		}
		for (int i = 0; i < ListaPr->size(); i++) {
			if (pj->area.IntersectsWith(ListaPr->area(i))) {
				if (cooldown == 0) pj->lostVidas(), cooldown = 1;
			}
		}
		if (cooldown != 0) { cooldown++; if (cooldown % 7 == 0) pj->toggleProtec(); }
		if (cooldown == 70) cooldown = 0;
	}

	void mostrar(BufferedGraphics^ buffer, Bitmap^ bmpMenu) {
		Rectangle tamanio = Rectangle(0, 0, 600, 600);
		buffer->Graphics->DrawImage(bmpMenu, tamanio, tamanio, GraphicsUnit::Pixel);
	}
	void mostrarSlow(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (nivel != 1) {
			Rectangle porcion = Rectangle(0, 0, 501 * restricSlow / (2 * nivel - 2), 40);
			Rectangle zoom = Rectangle(22, 578, 280 * restricSlow / (2 * nivel - 2), 22);
			buffer->Graphics->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
		}
	}
};