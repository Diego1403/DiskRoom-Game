#pragma once
#include <vector>
#include "Persecutor.h"
class VectorPers {
private:
	vector<Persecutor*>* Lista;
public:
	VectorPers() { Lista = new vector<Persecutor*>(); };
	~VectorPers() {
		for (Persecutor* PrIndividual : *Lista)
			delete PrIndividual;
		delete Lista;
	}

	void agregar(Persecutor *newPr) { this->Lista->push_back(newPr); }
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int i = 0; i < this->Lista->size(); i++) {
			Lista->at(i)->mover(buffer, bmp); Lista->at(i)->mostrar(buffer, bmp);
		}
	}

	void SetSlow() { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setSlow(); }
	void SetNormal() { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setNormal(); }
	void SetNivel(int n) { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->setNivel(n); }
	void SetSeguir(int xpj, int ypj) { for (int i = 0; i < Lista->size(); i++) Lista->at(i)->seguir(xpj, ypj); }
	void resetSeguir() { for (int i = 0; i < Lista->size(); i++)Lista->at(i)->resetseguir(); }
	int size() { return Lista->size(); }
	Rectangle area(int n) { return Lista->at(n)->area; }

	void clear() { Lista->clear(); }
};