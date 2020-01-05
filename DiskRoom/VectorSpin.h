#pragma once
#include <vector>
#include "Spinning.h"
class VectorSpin {
private:
	vector<Spinning*>* Lista;
public:
	VectorSpin() { Lista = new vector<Spinning*>(); };
	~VectorSpin() {
		for (Spinning* SpIndividual: *Lista)
			delete SpIndividual;
		delete Lista;
	}

	void agregar(Spinning *newSp) { this->Lista->push_back(newSp); }
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int i = 0; i < this->Lista->size(); i++) {
			Lista->at(i)->mover(buffer, bmp); Lista->at(i)->mostrar(buffer, bmp);
		}
	}

	void SetSlow() { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setSlow(); }
	void SetNormal() { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setNormal(); }
	void SetNivel(int n) { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setNivel(n); }
	int size() { return Lista->size(); }
	Rectangle area(int n) { return Lista->at(n)->area; }
	void setHardcore() { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setHardcore(); }
	void setNormalSpeed() { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setNormalSpeed(); }
	void clear() { Lista->clear(); }
};