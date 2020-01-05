/*


										Universidad Peruana de Ciencias Aplicadas
										----------------------------------------
															UPC

									“Año del diálogo y la reconciliación nacional”

														PROYECTO

													  UPC-DiskRoom

												CURSO DE PROGRAMACIÓN 2


													Sección: SI21
										Profesor:Jorge Carlos Valverde Rebaza


										--------------------------------------
													Integrantes:
										--------------------------------------
										--------------------------------------
										Alumno: Diego Vasquez Revilla
										Código: U201723333
										--------------------------------------
										--------------------------------------
										Alumno: Hector Sadaaki Suzuki Miura
										Código: U201810782
										--------------------------------------

																							Monterrico, noviembre 2018

Diagrama de clases:
-------------------

                                                                ______________________________________
                                                                | DiskRoomWindow     			     |
                                                                |_ __________________________________|
                                                           		| Graphics ^ g;						 |
	                                                            | BufferedGraphicsContext^ espacio;	 |
	                                                            | BufferedGraphics^ buffer;			 |
	                                                            | Bitmap^ bmpM1;					 |
	                                                            | Bitmap^ bmpM2;					 |
	                                                            | Bitmap^ bmpM3;					 |
	                                                            | Bitmap^ bmpM4;					 |
	                                                            | Bitmap^ bmpM5;					 |
	                                                            | Bitmap^ bmpM1s;					 |
	                                                            | Bitmap^ bmpM2s;					 |
	                                                            | Bitmap^ bmpM3s;					 |
	                                                            | Bitmap^ bmpM4s;					 |
	                                                            | Bitmap^ bmpM5s;					 |
	                                                            | Bitmap^ bmpLeft;					 |
	                                                            | Bitmap^ bmpRight;					 |
	                                                            | Bitmap^ bmpUp;					 |
	                                                            | Bitmap^ bmpDown;					 |
	                                                            | Bitmap^ bmpPLeft;					 |
	                                                            | Bitmap^ bmpPRight;				 |
	                                                            | Bitmap^ bmpPUp;					 |
	                                                            | Bitmap^ bmpPDown;					 |
	                                                            | Bitmap^ bmpSpinning;				 |
	                                                            | Bitmap^ bmpPersecutor;			 |
	                                                            | Bitmap^ gameOver;					 |
	                                                            | Bitmap^ bmpMenu;					 |
	                                                            | Bitmap^ hoverLevel;				 |
	                                                            | Bitmap^ hoverConfig;				 |
	                                                            | Bitmap^ hoverCred;				 |
																| long codigo;						 |
																| int presionado					 |
																| bool val							 |
																| UPCDiskRoom* juego				 |
																| long cooldown						 |
																| ----------------------------		 |
																| Void DiskRoomWindow_Load			 |
																| Void timer1_Tick					 |
																| void valPress(Keys Ks)			 |
																| Void DiskRoomWindow_KeyDown()		 |
																| Void DiskRoomWindow_KeyUp()		 |
																| Void ClickNiveles_MouseClick()	 |
																| Void ClickConfig_MouseClick()		 |
																| Void ClickCredit_MouseClick()		 |
                                                                |------------------------------------|
																				|
																				1
																				|
																				1
																				|
                                                                |---------------------------|
                                                                |	UPCDiskRoom()			|
                                                                |	short getNivel()		|
                                                                |	void setNivel()			|
                                                                |	void setFondo()			|
                                                                |	void resetframes()		|
                                                                |	void gameover()			|
                                                                |	void setSlow()			|
                                                                |	void setNormal()		|
                                                                |	void newSp()			|
                                                                |	void clear()			|
                                                                |	void colision ()		|
                                                                |	void mostrar()			|
                                                                |---------------------------|
																			|
																			|
																			|
																			|
																			|
																			|
                                                                _____________________________
                                                                |UPCDiskRoom                |                            
                                                                |___________________________|
                                                                |Jugador * pj;	   			|
                                                                |VectorSpin* ListaSp;		|
                                                                |VectorPers* ListaPr;		|
                                                                |short nivel;				|
                                                                |bool slow;					|
                                                                |int gameoverframes = 0;	|
                                                                |int cooldown = 0;			|
                                                                |---------------------------|
                                                                |	UPCDiskRoom()			|
                                                                |	short getNivel()		|
                                                                |	void setNivel()			|---|1|----------------------------------
                                                                |	void setFondo()			|								    	|
                                                                |	void resetframes()		|                                       |
                                                                |	void gameover()			|								    	|
                                                                |	void setSlow()			|								    	|
                                                                |	void setNormal()		|								    	|
                                                                |	void newSp()			|								    	|
                                                                |	void clear()			|								    	|
                                                                |	void colision ()		|								    	|
                                                                |	void mostrar()			|								    	|
                                                                |---------------------------|								    	_
																															    	1
																			|     |													-
																			|     |													|
																			_     _	                                    _____________________________
																			1     1	                                    |Jugador                    |
																			-     -	                                    |___________________________|
																			|     |	                                    |Direccion dirrecion;   	|
																			|     |	                                    |Direccion dir_anterior;    |
																			|     |	                                    |int vidas;		            |
																			|     |	                                    |int vidasbase;				|
																			|     |	                                    |bool protec;				|
																			|     |	                                    |---------------------------|
																			|     |	                                    |	void SetDir(direccion)	|
																			|     |	                                    |	short setslow()	        |
																			|     |	                                    |	void setNormal()		|
																			|     |	                                    |	void setVidasbase(int)	|
																			|     |	                                    |	void lostVidas()		|
																			|     |	                                    |	void resetVidas()		|
																			|     |	                                    |	void tooglePtotect()	|
																			|     |	                                    |	bool getSlow()		    |
																			|     |	                                    |	void dibujar()			|
																			|     |	                                    |	void mover()			|
																			|     |	                                    |---------------------------|
																			|     |
		--------------------------------------------------------------------|     |-------------------------------------------------------
		|																																|
		|																																|
        |                                                    ____________________________												|
        |                                                    |ObjGrafico                |												|
        |                                                    |__________________________|	                                            |
        |                                                    |	int ancho, alto, indiceX|	                                            |												
		|													 |	int indiceY, skip 	    |	                                            |
        |                                                    |	double x, y, dx, dy     |	                                            |
		|													 |	double		vel, nivel	|	                                            |
        |                                                    |	bool slow				|	                                            |
        |                                                    |	Rectangle area			|	                                            |
        |                                                    |--------------------------|	                                            |
        |                                                    |	int getX()				|	                                            |
        |                                                    |	int getY()				|	                                            |
        |                                                    |	void setNivel(int)		|	                                            |
        |                                                    |	void mostrar()			|	                                            |
        |                                                    |	void mover()			|	                                            |
        |													 ----------------------------												|
        |                                              			A						A												|
        |                                              			-						-											    _
        _                                            			|						|											    1
        1                                              			|						|-----------								    -
        -                                              			|									|							        |
        |                                              			|									|							        |
-----------------------------					 ----------------------------           |----------------------------|				______________________________
|VectorSpin					|					 |Spinning                  |			|persecutor		             |   			|VectorPers                   |
|___________________________|                    |__________________________|			|____________________________|       		|_____________________________|
|	vector<Spinning*> *Lista|                    |							|           |	int dxbase, dybase		 |       		|	vector<Persecutor*>*Lista |
|	void agregar()			|                    |	spinning(int):objGrafico|			|           	void seguir()|				|--------------------------   |
|---------------------------| -|1|--------|N|--- |--------------------------|           |----------------------------|-|N|------|1|-|	 void agregar()		      |
|	void mover()			|					 ----------------------------			|		void resetseguir()	 |		 		|	 void mover()             |
|	void SetSlow()			|															|          void mostrar()	 |	     		|	 void SetSlow()           |
|	void SetNormal()		|															|           void mover()	 |		 		|	 void SetNormal()         |
|	int getsize()			|															|  persecutor(int):objGrafico|				|    void SetNivel(int)	      |
|	void SetNivel()			|															|----------------------------|				|    void SetSeguir(int,int)  |
|	rectangle getarea(int)	|																										|	 void resetseguir()       |
|	void clear()			|																						         		|	 int size()               |
|---------------------------													        											|	 Reactangle area(int)	  |
																																	|	 void clear()             |
																																	-------------------------------
*/

#include "DiskRoomWindow.h"
using namespace System::Windows::Forms;
int main() {
	Application::EnableVisualStyles;
	Application::Run(gcnew DiskRoom::DiskRoomWindow);
	return 0;
}