#pragma once
#include "UPC-DiskRoom.h"
#include <string>
namespace DiskRoom {
	#pragma region Namespaces
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
#pragma endregion

	/// <summary>
	/// ((	Colocar una carátula	))
	/// </summary>

	public ref class DiskRoomWindow : public System::Windows::Forms::Form
	{
	private:

		#pragma region Graphics
		Graphics ^ g;						//
		BufferedGraphicsContext^ espacio;	//	Buffer + Graphics
		BufferedGraphics^ buffer;			//
#pragma endregion
		#pragma region Bitmaps
		Bitmap^ bmpM1;			//
		Bitmap^ bmpM2;			//
		Bitmap^ bmpM3;			//	Mapas
		Bitmap^ bmpM4;			//
		Bitmap^ bmpM5;			//
		Bitmap^ bmpM1s;
		Bitmap^ bmpM2s;
		Bitmap^ bmpM3s;
		Bitmap^ bmpM4s;
		Bitmap^ bmpM5s;

		Bitmap^ bmpLeft;		//
		Bitmap^ bmpRight;		//
		Bitmap^ bmpUp;			//	Personaje
		Bitmap^ bmpDown;		//

		Bitmap^ bmpPLeft;		//
		Bitmap^ bmpPRight;		//
		Bitmap^ bmpPUp;			//	Personaje protegido
		Bitmap^ bmpPDown;		//

		Bitmap^ bmpSpinning;	//
		Bitmap^ bmpPersecutor;	//	Discos

		Bitmap^ gameOver;
		Bitmap^ bmpMenu;
		Bitmap^ bmpConfig;
		Bitmap^ bmpCreditos;
		Bitmap^ bmpGreen;
		Bitmap^ bmpCorazon;
		Bitmap^ bmpSlowMotion;

		Bitmap^ bmpConfigH1;
		Bitmap^ bmpConfigH2;
		Bitmap^ bmpConfigH3;
		Bitmap^ bmpConfigNormal;
		Bitmap^ bmpConfigHardcore;
		Bitmap^ bmpConfig15;
		Bitmap^ bmpConfig25;
		Bitmap^ bmpConfig35;
		Bitmap^ bmpConfig45;
		Bitmap^ bmpConfig55;

#pragma endregion
		
		long codigo;			//	
		int presionado=0;		//	Validacion de pulsado de tecla
		bool val = 0;			//

		UPCDiskRoom* juego;

		long cooldown=0;		//	Periodo de invincibilidad
		int cooldown2 = 3;		//	Validacion de slowmotion
		long tiempo = 30000;
		long tiempobase = 30000;

		bool seguir = 0;
		double segundos = 35;
		double segundosbase = 35;

		Pantalla pantalla;

	public:
		DiskRoomWindow(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			bmpM1 = gcnew Bitmap(Map1->Image);					//
			bmpM2 = gcnew Bitmap(Map2->Image);					//
			bmpM3 = gcnew Bitmap(Map3->Image);					//	Mapas Normales
			bmpM4 = gcnew Bitmap(Map4->Image);					//
			bmpM5 = gcnew Bitmap(Map5->Image);					//
			bmpM1s = gcnew Bitmap(Map1s->Image);				//
			bmpM2s = gcnew Bitmap(Map2s->Image);				//
			bmpM3s = gcnew Bitmap(Map3s->Image);				//	Mapas Camara Lenta
			bmpM4s = gcnew Bitmap(Map4s->Image);				//
			bmpM5s = gcnew Bitmap(Map5s->Image);				//
			bmpLeft = gcnew Bitmap(pjIzquierda->Image);			//	Asignando las imagenes a los Bitmaps
			bmpRight = gcnew Bitmap(pjDerecha->Image);			//
			bmpUp = gcnew Bitmap(pjArriba->Image);				//
			bmpDown = gcnew Bitmap(pjAbajo->Image);				//
			bmpPLeft = gcnew Bitmap(prIzquierda->Image);
			bmpPRight = gcnew Bitmap(prDerecha->Image);
			bmpPUp = gcnew Bitmap(prArriba->Image);
			bmpPDown = gcnew Bitmap(prAbajo->Image);
			bmpSpinning = gcnew Bitmap(Spinning->Image);		//
			bmpPersecutor = gcnew Bitmap(Persecutor->Image);	//
			gameOver = gcnew Bitmap(GameOver->Image);
			bmpMenu = gcnew Bitmap(SourceMenu->Image);
			bmpConfig = gcnew Bitmap(SourceConfig->Image);
			bmpCreditos = gcnew Bitmap(PantallaCreditos->Image);
			bmpGreen = gcnew Bitmap(Green->Image);
			bmpCorazon = gcnew Bitmap(Corazon->Image);
			bmpSlowMotion = gcnew Bitmap(SlowMotion->Image);

			bmpConfigH1 = gcnew Bitmap(ConfigH1->Image);
			bmpConfigH2 = gcnew Bitmap(ConfigH2->Image);
			bmpConfigH3 = gcnew Bitmap(ConfigH3->Image);
			bmpConfigNormal = gcnew Bitmap(ConfigNormal->Image);
			bmpConfigHardcore = gcnew Bitmap(ConfigHardcore->Image);
			bmpConfig15 = gcnew Bitmap(Config15->Image);
			bmpConfig25 = gcnew Bitmap(Config25->Image);
			bmpConfig35 = gcnew Bitmap(Config35->Image);
			bmpConfig45 = gcnew Bitmap(Config45->Image);

			Color Tr = Color::FromArgb(0, 255, 0);	//	Verde usado en el fondo
			bmpLeft->MakeTransparent(Tr);			//
			bmpRight->MakeTransparent(Tr);			//
			bmpUp->MakeTransparent(Tr);				//	Hacer transparente los Bitmaps
			bmpDown->MakeTransparent(Tr);			//
			bmpPLeft->MakeTransparent(Tr);			//
			bmpPRight->MakeTransparent(Tr);			//
			bmpPUp->MakeTransparent(Tr);			//	Hacer transparente los Bitmaps
			bmpPDown->MakeTransparent(Tr);			//
			bmpSpinning->MakeTransparent(Tr);		//
			bmpPersecutor->MakeTransparent(Tr);		//
			bmpGreen->MakeTransparent(Tr);
			bmpCorazon->MakeTransparent(Tr);

			juego = new UPCDiskRoom();				/*	FALTA CARGAR LOS OBJETOS	*/
		}

	protected:
		#pragma region Destructor
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~DiskRoomWindow()
		{
			if (components)
			{
				delete components;
			}

			// Destruir componenetes gráficos
			delete g, espacio, buffer;
		}
#pragma endregion
	private: 
		#pragma region Componentes
				PictureBox^  Map1;
				PictureBox^  Map2;
				PictureBox^  Map3;
				PictureBox^  Map4;
				PictureBox^  Map5;
				PictureBox^  Map1s;
				PictureBox^  Map2s;
				PictureBox^  Map3s;
				PictureBox^  Map4s;
				PictureBox^  Map5s;
				PictureBox^  pjAbajo;
				PictureBox^  pjArriba;
				PictureBox^  pjDerecha;
				PictureBox^  pjIzquierda;
				PictureBox^  Spinning;
				PictureBox^  Persecutor;
				PictureBox^  prAbajo;
				PictureBox^  prArriba;
				PictureBox^  prIzquierda;
				PictureBox^  prDerecha;
				PictureBox^  GameOver;
				PictureBox^  SourceMenu;
				PictureBox^  SourceConfig;
				PictureBox^  Config15;
				PictureBox^  Config25;
				PictureBox^  Config35;
				PictureBox^  Config45;
				PictureBox^  ConfigNormal;
				PictureBox^  ConfigHardcore;
				PictureBox^  ConfigH1;
				PictureBox^  ConfigH2;
				PictureBox^  ConfigH3;
				PictureBox^  Green;
				PictureBox^  Corazon;
				PictureBox^  SlowMotion;

				PictureBox^  ClickConfig;	//
				PictureBox^  ClickCredit;	//	Validacion de click en el Menu
				PictureBox^  ClickNiveles;	//

				PictureBox^  PantallaCreditos;

				System::ComponentModel::IContainer^  components;

				System::Windows::Forms::Timer^  timer1;
				System::Windows::Forms::Timer^  Segundos;
				System::Windows::Forms::Label^  TSeg;
				System::Windows::Forms::Label^  TMil;
		#pragma endregion
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		#pragma region Windows Form Designer generated code
			/// <summary>
			/// Método necesario para admitir el Diseñador. No se puede modificar
			/// el contenido de este método con el editor de código.
			/// </summary>
			void InitializeComponent(void)
			{
				this->components = (gcnew System::ComponentModel::Container());
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DiskRoomWindow::typeid));
				this->Map1 = (gcnew System::Windows::Forms::PictureBox());
				this->Map2 = (gcnew System::Windows::Forms::PictureBox());
				this->Map3 = (gcnew System::Windows::Forms::PictureBox());
				this->Map4 = (gcnew System::Windows::Forms::PictureBox());
				this->Map5 = (gcnew System::Windows::Forms::PictureBox());
				this->pjAbajo = (gcnew System::Windows::Forms::PictureBox());
				this->pjArriba = (gcnew System::Windows::Forms::PictureBox());
				this->pjDerecha = (gcnew System::Windows::Forms::PictureBox());
				this->pjIzquierda = (gcnew System::Windows::Forms::PictureBox());
				this->Spinning = (gcnew System::Windows::Forms::PictureBox());
				this->Persecutor = (gcnew System::Windows::Forms::PictureBox());
				this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				this->Map1s = (gcnew System::Windows::Forms::PictureBox());
				this->Map2s = (gcnew System::Windows::Forms::PictureBox());
				this->Map3s = (gcnew System::Windows::Forms::PictureBox());
				this->Map4s = (gcnew System::Windows::Forms::PictureBox());
				this->Map5s = (gcnew System::Windows::Forms::PictureBox());
				this->prAbajo = (gcnew System::Windows::Forms::PictureBox());
				this->prArriba = (gcnew System::Windows::Forms::PictureBox());
				this->prIzquierda = (gcnew System::Windows::Forms::PictureBox());
				this->prDerecha = (gcnew System::Windows::Forms::PictureBox());
				this->GameOver = (gcnew System::Windows::Forms::PictureBox());
				this->SourceMenu = (gcnew System::Windows::Forms::PictureBox());
				this->ClickNiveles = (gcnew System::Windows::Forms::PictureBox());
				this->ClickConfig = (gcnew System::Windows::Forms::PictureBox());
				this->ClickCredit = (gcnew System::Windows::Forms::PictureBox());
				this->PantallaCreditos = (gcnew System::Windows::Forms::PictureBox());
				this->SourceConfig = (gcnew System::Windows::Forms::PictureBox());
				this->Config15 = (gcnew System::Windows::Forms::PictureBox());
				this->Config25 = (gcnew System::Windows::Forms::PictureBox());
				this->Config35 = (gcnew System::Windows::Forms::PictureBox());
				this->Config45 = (gcnew System::Windows::Forms::PictureBox());
				this->ConfigNormal = (gcnew System::Windows::Forms::PictureBox());
				this->ConfigHardcore = (gcnew System::Windows::Forms::PictureBox());
				this->ConfigH1 = (gcnew System::Windows::Forms::PictureBox());
				this->ConfigH2 = (gcnew System::Windows::Forms::PictureBox());
				this->ConfigH3 = (gcnew System::Windows::Forms::PictureBox());
				this->Green = (gcnew System::Windows::Forms::PictureBox());
				this->Segundos = (gcnew System::Windows::Forms::Timer(this->components));
				this->Corazon = (gcnew System::Windows::Forms::PictureBox());
				this->SlowMotion = (gcnew System::Windows::Forms::PictureBox());
				this->TSeg = (gcnew System::Windows::Forms::Label());
				this->TMil = (gcnew System::Windows::Forms::Label());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map1))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map2))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map3))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map4))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map5))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjAbajo))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjArriba))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjDerecha))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjIzquierda))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Spinning))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Persecutor))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map1s))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map2s))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map3s))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map4s))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map5s))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prAbajo))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prArriba))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prIzquierda))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prDerecha))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameOver))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceMenu))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClickNiveles))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClickConfig))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClickCredit))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PantallaCreditos))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceConfig))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config15))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config25))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config35))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config45))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigNormal))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigHardcore))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigH1))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigH2))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigH3))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Green))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Corazon))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SlowMotion))->BeginInit();
				this->SuspendLayout();
				// 
				// Map1
				// 
				this->Map1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map1.Image")));
				this->Map1->Location = System::Drawing::Point(0, 0);
				this->Map1->Name = L"Map1";
				this->Map1->Size = System::Drawing::Size(1080, 1080);
				this->Map1->TabIndex = 0;
				this->Map1->TabStop = false;
				this->Map1->Visible = false;
				// 
				// Map2
				// 
				this->Map2->BackColor = System::Drawing::SystemColors::Control;
				this->Map2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map2.Image")));
				this->Map2->Location = System::Drawing::Point(0, 0);
				this->Map2->Name = L"Map2";
				this->Map2->Size = System::Drawing::Size(1080, 1080);
				this->Map2->TabIndex = 1;
				this->Map2->TabStop = false;
				this->Map2->Visible = false;
				// 
				// Map3
				// 
				this->Map3->BackColor = System::Drawing::SystemColors::Control;
				this->Map3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map3.Image")));
				this->Map3->Location = System::Drawing::Point(0, 0);
				this->Map3->Name = L"Map3";
				this->Map3->Size = System::Drawing::Size(1080, 1080);
				this->Map3->TabIndex = 2;
				this->Map3->TabStop = false;
				this->Map3->Visible = false;
				// 
				// Map4
				// 
				this->Map4->BackColor = System::Drawing::SystemColors::Control;
				this->Map4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map4.Image")));
				this->Map4->Location = System::Drawing::Point(0, 0);
				this->Map4->Name = L"Map4";
				this->Map4->Size = System::Drawing::Size(1080, 1080);
				this->Map4->TabIndex = 3;
				this->Map4->TabStop = false;
				this->Map4->Visible = false;
				// 
				// Map5
				// 
				this->Map5->BackColor = System::Drawing::SystemColors::Control;
				this->Map5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map5.Image")));
				this->Map5->Location = System::Drawing::Point(0, 0);
				this->Map5->Name = L"Map5";
				this->Map5->Size = System::Drawing::Size(1080, 1080);
				this->Map5->TabIndex = 4;
				this->Map5->TabStop = false;
				this->Map5->Visible = false;
				// 
				// pjAbajo
				// 
				this->pjAbajo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pjAbajo.Image")));
				this->pjAbajo->Location = System::Drawing::Point(12, 12);
				this->pjAbajo->Name = L"pjAbajo";
				this->pjAbajo->Size = System::Drawing::Size(456, 137);
				this->pjAbajo->TabIndex = 5;
				this->pjAbajo->TabStop = false;
				this->pjAbajo->Visible = false;
				// 
				// pjArriba
				// 
				this->pjArriba->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pjArriba.Image")));
				this->pjArriba->Location = System::Drawing::Point(12, 155);
				this->pjArriba->Name = L"pjArriba";
				this->pjArriba->Size = System::Drawing::Size(456, 137);
				this->pjArriba->TabIndex = 6;
				this->pjArriba->TabStop = false;
				this->pjArriba->Visible = false;
				// 
				// pjDerecha
				// 
				this->pjDerecha->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pjDerecha.Image")));
				this->pjDerecha->Location = System::Drawing::Point(596, 12);
				this->pjDerecha->Name = L"pjDerecha";
				this->pjDerecha->Size = System::Drawing::Size(456, 137);
				this->pjDerecha->TabIndex = 7;
				this->pjDerecha->TabStop = false;
				this->pjDerecha->Visible = false;
				// 
				// pjIzquierda
				// 
				this->pjIzquierda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pjIzquierda.Image")));
				this->pjIzquierda->Location = System::Drawing::Point(596, 155);
				this->pjIzquierda->Name = L"pjIzquierda";
				this->pjIzquierda->Size = System::Drawing::Size(456, 137);
				this->pjIzquierda->TabIndex = 8;
				this->pjIzquierda->TabStop = false;
				this->pjIzquierda->Visible = false;
				// 
				// Spinning
				// 
				this->Spinning->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Spinning.Image")));
				this->Spinning->Location = System::Drawing::Point(12, 298);
				this->Spinning->Name = L"Spinning";
				this->Spinning->Size = System::Drawing::Size(856, 274);
				this->Spinning->TabIndex = 9;
				this->Spinning->TabStop = false;
				this->Spinning->Visible = false;
				// 
				// Persecutor
				// 
				this->Persecutor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Persecutor.Image")));
				this->Persecutor->Location = System::Drawing::Point(12, 578);
				this->Persecutor->Name = L"Persecutor";
				this->Persecutor->Size = System::Drawing::Size(850, 274);
				this->Persecutor->TabIndex = 10;
				this->Persecutor->TabStop = false;
				this->Persecutor->Visible = false;
				// 
				// timer1
				// 
				this->timer1->Enabled = true;
				this->timer1->Interval = 1;
				this->timer1->Tick += gcnew System::EventHandler(this, &DiskRoomWindow::timer1_Tick);
				// 
				// Map1s
				// 
				this->Map1s->Dock = System::Windows::Forms::DockStyle::Fill;
				this->Map1s->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map1s.Image")));
				this->Map1s->Location = System::Drawing::Point(0, 0);
				this->Map1s->Name = L"Map1s";
				this->Map1s->Size = System::Drawing::Size(599, 599);
				this->Map1s->TabIndex = 11;
				this->Map1s->TabStop = false;
				this->Map1s->Visible = false;
				// 
				// Map2s
				// 
				this->Map2s->Dock = System::Windows::Forms::DockStyle::Fill;
				this->Map2s->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map2s.Image")));
				this->Map2s->Location = System::Drawing::Point(0, 0);
				this->Map2s->Name = L"Map2s";
				this->Map2s->Size = System::Drawing::Size(599, 599);
				this->Map2s->TabIndex = 12;
				this->Map2s->TabStop = false;
				this->Map2s->Visible = false;
				// 
				// Map3s
				// 
				this->Map3s->Dock = System::Windows::Forms::DockStyle::Fill;
				this->Map3s->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map3s.Image")));
				this->Map3s->Location = System::Drawing::Point(0, 0);
				this->Map3s->Name = L"Map3s";
				this->Map3s->Size = System::Drawing::Size(599, 599);
				this->Map3s->TabIndex = 13;
				this->Map3s->TabStop = false;
				this->Map3s->Visible = false;
				// 
				// Map4s
				// 
				this->Map4s->Dock = System::Windows::Forms::DockStyle::Fill;
				this->Map4s->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map4s.Image")));
				this->Map4s->Location = System::Drawing::Point(0, 0);
				this->Map4s->Name = L"Map4s";
				this->Map4s->Size = System::Drawing::Size(599, 599);
				this->Map4s->TabIndex = 14;
				this->Map4s->TabStop = false;
				this->Map4s->Visible = false;
				// 
				// Map5s
				// 
				this->Map5s->Dock = System::Windows::Forms::DockStyle::Fill;
				this->Map5s->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map5s.Image")));
				this->Map5s->Location = System::Drawing::Point(0, 0);
				this->Map5s->Name = L"Map5s";
				this->Map5s->Size = System::Drawing::Size(599, 599);
				this->Map5s->TabIndex = 15;
				this->Map5s->TabStop = false;
				this->Map5s->Visible = false;
				// 
				// prAbajo
				// 
				this->prAbajo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prAbajo.Image")));
				this->prAbajo->Location = System::Drawing::Point(12, 12);
				this->prAbajo->Name = L"prAbajo";
				this->prAbajo->Size = System::Drawing::Size(456, 137);
				this->prAbajo->TabIndex = 16;
				this->prAbajo->TabStop = false;
				this->prAbajo->Visible = false;
				// 
				// prArriba
				// 
				this->prArriba->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prArriba.Image")));
				this->prArriba->Location = System::Drawing::Point(12, 155);
				this->prArriba->Name = L"prArriba";
				this->prArriba->Size = System::Drawing::Size(456, 137);
				this->prArriba->TabIndex = 17;
				this->prArriba->TabStop = false;
				this->prArriba->Visible = false;
				// 
				// prIzquierda
				// 
				this->prIzquierda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prIzquierda.Image")));
				this->prIzquierda->Location = System::Drawing::Point(12, 12);
				this->prIzquierda->Name = L"prIzquierda";
				this->prIzquierda->Size = System::Drawing::Size(456, 137);
				this->prIzquierda->TabIndex = 18;
				this->prIzquierda->TabStop = false;
				this->prIzquierda->Visible = false;
				// 
				// prDerecha
				// 
				this->prDerecha->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prDerecha.Image")));
				this->prDerecha->Location = System::Drawing::Point(12, 155);
				this->prDerecha->Name = L"prDerecha";
				this->prDerecha->Size = System::Drawing::Size(456, 137);
				this->prDerecha->TabIndex = 19;
				this->prDerecha->TabStop = false;
				this->prDerecha->Visible = false;
				// 
				// GameOver
				// 
				this->GameOver->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GameOver.Image")));
				this->GameOver->Location = System::Drawing::Point(12, 12);
				this->GameOver->Name = L"GameOver";
				this->GameOver->Size = System::Drawing::Size(2000, 200);
				this->GameOver->TabIndex = 20;
				this->GameOver->TabStop = false;
				this->GameOver->Visible = false;
				// 
				// SourceMenu
				// 
				this->SourceMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SourceMenu.Image")));
				this->SourceMenu->Location = System::Drawing::Point(0, 0);
				this->SourceMenu->Name = L"SourceMenu";
				this->SourceMenu->Size = System::Drawing::Size(600, 600);
				this->SourceMenu->TabIndex = 21;
				this->SourceMenu->TabStop = false;
				this->SourceMenu->Visible = false;
				// 
				// ClickNiveles
				// 
				this->ClickNiveles->BackColor = System::Drawing::Color::Transparent;
				this->ClickNiveles->Location = System::Drawing::Point(92, 168);
				this->ClickNiveles->Name = L"ClickNiveles";
				this->ClickNiveles->Size = System::Drawing::Size(200, 203);
				this->ClickNiveles->TabIndex = 25;
				this->ClickNiveles->TabStop = false;
				this->ClickNiveles->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ClickNiveles_MouseClick);
				// 
				// ClickConfig
				// 
				this->ClickConfig->BackColor = System::Drawing::Color::Transparent;
				this->ClickConfig->Location = System::Drawing::Point(306, 168);
				this->ClickConfig->Name = L"ClickConfig";
				this->ClickConfig->Size = System::Drawing::Size(200, 94);
				this->ClickConfig->TabIndex = 26;
				this->ClickConfig->TabStop = false;
				this->ClickConfig->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ClickConfig_MouseClick);
				// 
				// ClickCredit
				// 
				this->ClickCredit->BackColor = System::Drawing::Color::Transparent;
				this->ClickCredit->Location = System::Drawing::Point(306, 274);
				this->ClickCredit->Name = L"ClickCredit";
				this->ClickCredit->Size = System::Drawing::Size(200, 94);
				this->ClickCredit->TabIndex = 27;
				this->ClickCredit->TabStop = false;
				this->ClickCredit->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ClickCredit_MouseClick);
				// 
				// PantallaCreditos
				// 
				this->PantallaCreditos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PantallaCreditos.Image")));
				this->PantallaCreditos->Location = System::Drawing::Point(0, 0);
				this->PantallaCreditos->Name = L"PantallaCreditos";
				this->PantallaCreditos->Size = System::Drawing::Size(600, 600);
				this->PantallaCreditos->TabIndex = 28;
				this->PantallaCreditos->TabStop = false;
				this->PantallaCreditos->Visible = false;
				// 
				// SourceConfig
				// 
				this->SourceConfig->Dock = System::Windows::Forms::DockStyle::Fill;
				this->SourceConfig->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SourceConfig.Image")));
				this->SourceConfig->Location = System::Drawing::Point(0, 0);
				this->SourceConfig->Name = L"SourceConfig";
				this->SourceConfig->Size = System::Drawing::Size(599, 599);
				this->SourceConfig->TabIndex = 29;
				this->SourceConfig->TabStop = false;
				this->SourceConfig->Visible = false;
				// 
				// Config15
				// 
				this->Config15->BackColor = System::Drawing::Color::Transparent;
				this->Config15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Config15.Image")));
				this->Config15->Location = System::Drawing::Point(294, 335);
				this->Config15->Name = L"Config15";
				this->Config15->Size = System::Drawing::Size(56, 25);
				this->Config15->TabIndex = 30;
				this->Config15->TabStop = false;
				this->Config15->Visible = false;
				this->Config15->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::Config15_MouseClick);
				// 
				// Config25
				// 
				this->Config25->BackColor = System::Drawing::Color::Transparent;
				this->Config25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Config25.Image")));
				this->Config25->Location = System::Drawing::Point(350, 335);
				this->Config25->Name = L"Config25";
				this->Config25->Size = System::Drawing::Size(56, 25);
				this->Config25->TabIndex = 31;
				this->Config25->TabStop = false;
				this->Config25->Visible = false;
				this->Config25->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::Config25_MouseClick);
				// 
				// Config35
				// 
				this->Config35->BackColor = System::Drawing::Color::Transparent;
				this->Config35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Config35.Image")));
				this->Config35->Location = System::Drawing::Point(415, 335);
				this->Config35->Name = L"Config35";
				this->Config35->Size = System::Drawing::Size(56, 25);
				this->Config35->TabIndex = 32;
				this->Config35->TabStop = false;
				this->Config35->Visible = false;
				this->Config35->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::Config35_MouseClick);
				// 
				// Config45
				// 
				this->Config45->BackColor = System::Drawing::Color::Transparent;
				this->Config45->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Config45.Image")));
				this->Config45->Location = System::Drawing::Point(480, 335);
				this->Config45->Name = L"Config45";
				this->Config45->Size = System::Drawing::Size(56, 25);
				this->Config45->TabIndex = 33;
				this->Config45->TabStop = false;
				this->Config45->Visible = false;
				this->Config45->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::Config45_MouseClick);
				// 
				// ConfigNormal
				// 
				this->ConfigNormal->BackColor = System::Drawing::Color::Transparent;
				this->ConfigNormal->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ConfigNormal.Image")));
				this->ConfigNormal->Location = System::Drawing::Point(332, 395);
				this->ConfigNormal->Name = L"ConfigNormal";
				this->ConfigNormal->Size = System::Drawing::Size(203, 30);
				this->ConfigNormal->TabIndex = 34;
				this->ConfigNormal->TabStop = false;
				this->ConfigNormal->Visible = false;
				this->ConfigNormal->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ConfigNormal_MouseClick);
				// 
				// ConfigHardcore
				// 
				this->ConfigHardcore->BackColor = System::Drawing::Color::Transparent;
				this->ConfigHardcore->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ConfigHardcore.Image")));
				this->ConfigHardcore->Location = System::Drawing::Point(332, 439);
				this->ConfigHardcore->Name = L"ConfigHardcore";
				this->ConfigHardcore->Size = System::Drawing::Size(203, 25);
				this->ConfigHardcore->TabIndex = 35;
				this->ConfigHardcore->TabStop = false;
				this->ConfigHardcore->Visible = false;
				this->ConfigHardcore->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ConfigHardcore_MouseClick);
				// 
				// ConfigH1
				// 
				this->ConfigH1->BackColor = System::Drawing::Color::Transparent;
				this->ConfigH1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ConfigH1.Image")));
				this->ConfigH1->Location = System::Drawing::Point(411, 231);
				this->ConfigH1->Name = L"ConfigH1";
				this->ConfigH1->Size = System::Drawing::Size(30, 28);
				this->ConfigH1->TabIndex = 36;
				this->ConfigH1->TabStop = false;
				this->ConfigH1->Visible = false;
				this->ConfigH1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ConfigH1_MouseClick);
				// 
				// ConfigH2
				// 
				this->ConfigH2->BackColor = System::Drawing::Color::Transparent;
				this->ConfigH2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ConfigH2.Image")));
				this->ConfigH2->Location = System::Drawing::Point(441, 251);
				this->ConfigH2->Name = L"ConfigH2";
				this->ConfigH2->Size = System::Drawing::Size(30, 28);
				this->ConfigH2->TabIndex = 37;
				this->ConfigH2->TabStop = false;
				this->ConfigH2->Visible = false;
				this->ConfigH2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ConfigH2_MouseClick);
				// 
				// ConfigH3
				// 
				this->ConfigH3->BackColor = System::Drawing::Color::Transparent;
				this->ConfigH3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ConfigH3.Image")));
				this->ConfigH3->Location = System::Drawing::Point(471, 271);
				this->ConfigH3->Name = L"ConfigH3";
				this->ConfigH3->Size = System::Drawing::Size(30, 28);
				this->ConfigH3->TabIndex = 38;
				this->ConfigH3->TabStop = false;
				this->ConfigH3->Visible = false;
				this->ConfigH3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::ConfigH3_MouseClick);
				// 
				// Green
				// 
				this->Green->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Green.Image")));
				this->Green->Location = System::Drawing::Point(455, 12);
				this->Green->Name = L"Green";
				this->Green->Size = System::Drawing::Size(100, 100);
				this->Green->TabIndex = 39;
				this->Green->TabStop = false;
				this->Green->Visible = false;
				// 
				// Segundos
				// 
				this->Segundos->Enabled = true;
				this->Segundos->Interval = 1000;
				this->Segundos->Tick += gcnew System::EventHandler(this, &DiskRoomWindow::Segundos_Tick);
				// 
				// Corazon
				// 
				this->Corazon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Corazon.Image")));
				this->Corazon->Location = System::Drawing::Point(24, 37);
				this->Corazon->Name = L"Corazon";
				this->Corazon->Size = System::Drawing::Size(300, 280);
				this->Corazon->TabIndex = 40;
				this->Corazon->TabStop = false;
				this->Corazon->Visible = false;
				// 
				// SlowMotion
				// 
				this->SlowMotion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SlowMotion.Image")));
				this->SlowMotion->Location = System::Drawing::Point(8, 8);
				this->SlowMotion->Name = L"SlowMotion";
				this->SlowMotion->Size = System::Drawing::Size(501, 40);
				this->SlowMotion->TabIndex = 41;
				this->SlowMotion->TabStop = false;
				this->SlowMotion->Visible = false;
				// 
				// TSeg
				// 
				this->TSeg->AutoSize = true;
				this->TSeg->BackColor = System::Drawing::Color::Transparent;
				this->TSeg->ForeColor = System::Drawing::SystemColors::Control;
				this->TSeg->Location = System::Drawing::Point(306, 580);
				this->TSeg->Name = L"TSeg";
				this->TSeg->Size = System::Drawing::Size(13, 13);
				this->TSeg->TabIndex = 42;
				this->TSeg->Text = L"0";
				// 
				// TMil
				// 
				this->TMil->AutoSize = true;
				this->TMil->BackColor = System::Drawing::Color::Transparent;
				this->TMil->ForeColor = System::Drawing::SystemColors::Control;
				this->TMil->Location = System::Drawing::Point(325, 580);
				this->TMil->Name = L"TMil";
				this->TMil->Size = System::Drawing::Size(13, 13);
				this->TMil->TabIndex = 43;
				this->TMil->Text = L"0";
				// 
				// DiskRoomWindow
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::SystemColors::Control;
				this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				this->ClientSize = System::Drawing::Size(599, 599);
				this->Controls->Add(this->TMil);
				this->Controls->Add(this->TSeg);
				this->Controls->Add(this->SlowMotion);
				this->Controls->Add(this->pjDerecha);
				this->Controls->Add(this->pjIzquierda);
				this->Controls->Add(this->GameOver);
				this->Controls->Add(this->prDerecha);
				this->Controls->Add(this->ClickConfig);
				this->Controls->Add(this->prArriba);
				this->Controls->Add(this->pjArriba);
				this->Controls->Add(this->Corazon);
				this->Controls->Add(this->ConfigH1);
				this->Controls->Add(this->ConfigH2);
				this->Controls->Add(this->ConfigH3);
				this->Controls->Add(this->ClickCredit);
				this->Controls->Add(this->ClickNiveles);
				this->Controls->Add(this->prIzquierda);
				this->Controls->Add(this->prAbajo);
				this->Controls->Add(this->pjAbajo);
				this->Controls->Add(this->Green);
				this->Controls->Add(this->Spinning);
				this->Controls->Add(this->Persecutor);
				this->Controls->Add(this->ConfigHardcore);
				this->Controls->Add(this->ConfigNormal);
				this->Controls->Add(this->Config15);
				this->Controls->Add(this->Config25);
				this->Controls->Add(this->Config35);
				this->Controls->Add(this->Config45);
				this->Controls->Add(this->Map2);
				this->Controls->Add(this->Map1);
				this->Controls->Add(this->Map5s);
				this->Controls->Add(this->Map4s);
				this->Controls->Add(this->Map3s);
				this->Controls->Add(this->PantallaCreditos);
				this->Controls->Add(this->SourceMenu);
				this->Controls->Add(this->SourceConfig);
				this->Controls->Add(this->Map2s);
				this->Controls->Add(this->Map1s);
				this->Controls->Add(this->Map5);
				this->Controls->Add(this->Map4);
				this->Controls->Add(this->Map3);
				this->DoubleBuffered = true;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximumSize = System::Drawing::Size(617, 638);
				this->MinimumSize = System::Drawing::Size(615, 638);
				this->Name = L"DiskRoomWindow";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"DiskRoomWindow";
				this->Load += gcnew System::EventHandler(this, &DiskRoomWindow::DiskRoomWindow_Load);
				this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DiskRoomWindow::DiskRoomWindow_KeyDown);
				this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &DiskRoomWindow::DiskRoomWindow_KeyUp);
				this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &DiskRoomWindow::DiskRoomWindow_MouseDown);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map1))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map2))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map3))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map4))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map5))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjAbajo))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjArriba))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjDerecha))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pjIzquierda))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Spinning))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Persecutor))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map1s))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map2s))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map3s))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map4s))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Map5s))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prAbajo))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prArriba))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prIzquierda))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prDerecha))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GameOver))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceMenu))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClickNiveles))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClickConfig))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClickCredit))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PantallaCreditos))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceConfig))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config15))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config25))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config35))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Config45))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigNormal))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigHardcore))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigH1))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigH2))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ConfigH3))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Green))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Corazon))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SlowMotion))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

private: System::Void DiskRoomWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	g = this->CreateGraphics();								//
	espacio = BufferedGraphicsManager::Current;				//	Cargar los componentes gráficos
	buffer = espacio->Allocate(g, this->ClientRectangle);	//
}
private: System::Void Segundos_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (pantalla == Juego) {
		if (cooldown2 == 3) segundos -= 0.5;
		segundos -= 0.5;
	}
	if (cooldown2!=3) cooldown2--;
	TSeg->Text = Convert::ToString((int)segundos);
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	if (pantalla == MenuPrincipal) {
		ClickNiveles->Visible = 1;
		ClickConfig->Visible = 1;
		ClickCredit->Visible = 1;
		juego->mostrar(buffer, bmpMenu);
		buffer->Render(g);
	}
	else ClickNiveles->Visible = 0, ClickConfig->Visible = 0, ClickCredit->Visible = 0;
	if (pantalla == Config) { 
		ConfigH1->Visible = 1, ConfigH2->Visible = 1, ConfigH3->Visible = 1, Config15->Visible = 1, Config25->Visible = 1, Config35->Visible = 1, Config45->Visible = 1, ConfigNormal->Visible = 1, ConfigHardcore->Visible = 1;
		juego->mostrar(buffer, bmpConfig), buffer->Render(g); 
	}
	else ConfigH1->Visible = 0, ConfigH2->Visible = 0, ConfigH3->Visible = 0, Config15->Visible = 0, Config25->Visible = 0, Config35->Visible = 0, Config45->Visible = 0, ConfigNormal->Visible = 0, ConfigHardcore->Visible = 0;
	if (pantalla == Creditos) { juego->mostrar(buffer, bmpCreditos), buffer->Render(g); }
	if (pantalla == Juego) {
		juego->setFondo(buffer, bmpM1, bmpM2, bmpM3, bmpM4, bmpM5, bmpM1s, bmpM2s, bmpM3s, bmpM4s, bmpM5s, juego->pj->getSlow());
		if (juego->pj->vidas >= 1) {
			juego->pj->dibujarVida(buffer, bmpCorazon);
			juego->mostrarSlow(buffer, bmpSlowMotion);
			juego->pj->mover(buffer, bmpLeft, bmpRight, bmpUp, bmpDown, bmpPLeft, bmpPRight, bmpPUp, bmpPDown);
			if (activeHardcore == 1) juego->ListaSp->setHardcore();
			else juego->ListaSp->setNormalSpeed();
			juego->ListaSp->mover(buffer, bmpSpinning);
			juego->ListaPr->mover(buffer, bmpPersecutor);
			if (seguir == 1) juego->ListaPr->SetSeguir(juego->pj->getX(), juego->pj->getY());
			juego->colision();
			buffer->Render(g);
			tiempo--;
			if (tiempo % 100 == 0) seguir = 1;
			if (tiempo % 200 == 0) juego->resetSeguir(), seguir=0;
			if (tiempo > 1000) tiempo = 0;

			if (segundos == 0) {
				if (juego->getNivel() == 1) juego->setNivel(2);
				else if (juego->getNivel() == 2) juego->setNivel(3);
				else if (juego->getNivel() == 3) juego->setNivel(4);
				else if (juego->getNivel() == 4) juego->setNivel(5);
				else if (juego->getNivel() == 5) { pantalla = MenuPrincipal; }
				segundos = segundosbase;
				juego->pj->resetpos();
			}
		}
		else juego->gameover(buffer, gameOver, g), pantalla=Gameover, juego->pj->resetpos();
		TMil->Text = Convert::ToString(-tiempo%10);
	}
	else if (pantalla!=Gameover) TSeg->Visible = 0, TMil->Visible = 0;

}
public:
	void valPress(Keys Ks) {
		switch (Ks)
		{
		case Keys::NumPad1:
		case Keys::D1:
		case Keys::NumPad2:
		case Keys::D2:
		case Keys::NumPad3:
		case Keys::D3:
		case Keys::NumPad4:
		case Keys::D4:
		case Keys::NumPad5:
		case Keys::D5:
		case Keys::Up:		
		case Keys::Down:	
		case Keys::Left:	
		case Keys::Right:	
		case Keys::C:		
		case Keys::N:
		case Keys::M:
		case Keys::I:	val = 1; break;
		default:		val = 0; break;
		}
	}
private: System::Void DiskRoomWindow_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	valPress(e->KeyCode);
	if (val==1) {
		timer1->Enabled = 1;
		if (e->KeyCode != Keys::C) codigo = e->KeyValue;
		switch (e->KeyCode) {			//	Eventos de teclado
		case Keys::NumPad1:
		case Keys::D1: juego->setNivel(1), pantalla=Juego;		break;
		case Keys::NumPad2:
		case Keys::D2: juego->setNivel(2);		break;
		case Keys::NumPad3:
		case Keys::D3: juego->setNivel(3);		break;
		case Keys::NumPad4:
		case Keys::D4: juego->setNivel(4);		break;
		case Keys::NumPad5:
		case Keys::D5: juego->setNivel(5);		break;

		case Keys::Up:		juego->pj->setDir(Up);		break;
		case Keys::Down:	juego->pj->setDir(Down);	break;
		case Keys::Left:	juego->pj->setDir(Direccion::Left);	break;	//	Agregue Direccion:: pq daba conflicto con otro namespace
		case Keys::Right:	juego->pj->setDir(Direccion::Right);	break;	//	
		case Keys::C:		if (cooldown2 == 3) cooldown2 = 2, juego->restricSlow--; if (cooldown2 > 0) juego->setSlow(); 						break;		//	Camara Lenta
		case Keys::I:		juego->pj->resetVidas(), juego->resetframes();				break;
		case Keys::N:		juego->newSp(1);	break;
		case Keys::M:		juego->newPr(1); break;
		default: break;
		}
		if (/*juego->pj->dir_anterior != None && */juego->pj->direccion != juego->pj->dir_anterior&&presionado == 1 && e->KeyCode != Keys::C) presionado = 2;
		if (presionado == 0 && e->KeyCode != Keys::C) presionado = 1;
	}
}
private: System::Void DiskRoomWindow_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	valPress(e->KeyCode);
	if (val == 1) {
		if (juego->pj->dir_anterior == None || codigo == e->KeyValue) {
			if (presionado == 1) {
				switch (e->KeyCode)
				{
				case Keys::Up:
				case Keys::Down:
				case Keys::Left:
				case Keys::Right: juego->pj->setDir(None);  break;

				default:	break;
				}
				presionado = 0;
			}
			else if (presionado == 2) {
				switch (e->KeyCode)
				{
				case Keys::Up:
				case Keys::Down:
				case Keys::Left:
				case Keys::Right: juego->pj->setDir(juego->pj->dir_anterior);  break;
				default:	break;
				}
				presionado = 1;
			}
		}
		else if (presionado == 2 && codigo != e->KeyValue && e->KeyCode != Keys::C) juego->pj->setDir(juego->pj->direccion), presionado = 1;
		else if (e->KeyCode != Keys::C) presionado = 0, juego->pj->setDir(None);
		if (e->KeyCode == Keys::C) juego->setNormal(), cooldown2=3;	//Camara Normal
		}
	}
private: System::Void ClickNiveles_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { pantalla = Juego, juego->setNivel(1), segundos = segundosbase, TSeg->Visible=1, TMil->Visible=1; }
private: System::Void ClickConfig_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { pantalla = Config, this->BackgroundImage = (bmpConfig); if (activeNormal == 1) ConfigNormal->Image = bmpGreen; if (active35 == 1) Config35->Image=bmpGreen; }
private: System::Void ClickCredit_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { pantalla = Creditos; }
private: System::Void DiskRoomWindow_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { if (pantalla == Creditos || pantalla == Config || pantalla == Gameover) pantalla = MenuPrincipal, this->BackgroundImage = (bmpMenu), juego->pj->resetVidas(); }
private:
	bool activeH1 = 0, activeH2 = 0, activeH3 = 0, active15 = 0, active25 = 0, active35 = 1, active45 = 0, activeNormal = 1, activeHardcore = 0;

private: System::Void ConfigH1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { 
	if (activeH1 == 0) ConfigH1->Image = bmpGreen, activeH1 = 1, juego->pj->setVidasbase(juego->pj->vidasbase + 1); 
	else if (activeH1 == 1) ConfigH1->Image = bmpConfigH1, activeH1 = 0, juego->pj->setVidasbase(juego->pj->vidasbase - 1); 
}
private: System::Void ConfigH2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { 
	if (activeH2 == 0) ConfigH2->Image = bmpGreen, activeH2 = 1, juego->pj->setVidasbase(juego->pj->vidasbase + 1); 
	else if (activeH2 == 1) ConfigH2->Image = bmpConfigH2, activeH2 = 0, juego->pj->setVidasbase(juego->pj->vidasbase - 1); 
}
private: System::Void ConfigH3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { 
	if (activeH3 == 0) ConfigH3->Image = bmpGreen, activeH3 = 1, juego->pj->setVidasbase(juego->pj->vidasbase + 1);
	else if (activeH3 == 1) ConfigH3->Image = bmpConfigH3, activeH3 = 0, juego->pj->setVidasbase(juego->pj->vidasbase - 1);
}
private: System::Void ConfigNormal_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (activeNormal == 0) ConfigNormal->Image=bmpGreen, activeNormal=1, ConfigHardcore->Image=bmpConfigHardcore, activeHardcore=0;
	else if (activeNormal == 1) ConfigNormal->Image = bmpConfigNormal, activeNormal = 0, ConfigHardcore->Image = bmpGreen, activeHardcore=1;
}
private: System::Void ConfigHardcore_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (activeHardcore == 0) ConfigHardcore->Image = bmpGreen, activeHardcore = 1, ConfigNormal->Image = bmpConfigNormal, activeNormal=0;
	else if (activeHardcore == 1) ConfigHardcore->Image = bmpConfigHardcore, activeHardcore = 0, ConfigNormal->Image = bmpGreen, activeNormal=1;
}

private: System::Void Config15_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (active15 == 0) {
		Config15->Image = bmpGreen, active15 = 1;
		Config25->Image = bmpConfig25, active25 = 0;
		Config35->Image = bmpConfig35, active35 = 0;
		Config45->Image = bmpConfig45, active45 = 0;
		segundosbase = 15;
	}
}

private: System::Void Config25_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (active25 == 0) {
		Config25->Image = bmpGreen, active25 = 1;
		Config15->Image = bmpConfig15, active15 = 0;
		Config35->Image = bmpConfig35, active35 = 0;
		Config45->Image = bmpConfig45, active45 = 0;
		segundosbase = 25;
	}
}
private: System::Void Config35_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (active35 == 0) {
		Config35->Image = bmpGreen, active35 = 1;
		Config15->Image = bmpConfig15, active15 = 0;
		Config25->Image = bmpConfig25, active25 = 0;
		Config45->Image = bmpConfig45, active45 = 0;
		segundosbase = 35;
	}
}
private: System::Void Config45_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (active45 == 0) {
		Config45->Image = bmpGreen, active45 = 1;
		Config15->Image = bmpConfig15, active15 = 0;
		Config25->Image = bmpConfig25, active25 = 0;
		Config35->Image = bmpConfig35, active35 = 0;
		segundosbase = 45;
	}
}
}; //fin de clase
} //fin de namespace
