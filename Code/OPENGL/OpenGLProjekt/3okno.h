#include <windows.h>
#include <gl\GL.h>
#include <stdio.h>	
#include <gl\GLU.h>
#include <string>
#include <gl\glut.h>
#include <gl\glaux.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <fstream>
#pragma once

namespace OpenGLProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace System::IO;

	[DllImport("opengl32.dll")]
	extern HDC wglSwapBuffers( HDC hdc );
	/// <summary>
	/// Summary for My3okno
	/// </summary>
	public ref class My3okno : public System::Windows::Forms::Form
	{
	public:
		My3okno(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			OpenGLInit(); 
		}
		void OpenGLInit(void)
		{
			// Get Handle
			m_hWnd = (HWND)this->OpenGLPanel->Handle.ToInt32();
			m_hDC = GetDC( m_hWnd );
			//WGL::wglSwapBuffers((unsigned int)m_hDC);
			wglSwapBuffers(m_hDC);

			// Set pixel format
			PIXELFORMATDESCRIPTOR pfd = { 
				sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 
				1,                                // version number 
				PFD_DRAW_TO_WINDOW |              // support window 
				PFD_SUPPORT_OPENGL |              // support OpenGL 
				PFD_DOUBLEBUFFER,                 // double buffered 
				PFD_TYPE_RGBA,                    // RGBA type 
				24,                               // 24-bit color depth 
				0, 0, 0, 0, 0, 0,                 // color bits ignored 
				0,                                // no alpha buffer 
				0,                                // shift bit ignored 
				0,                                // no accumulation buffer 
				0, 0, 0, 0,                       // accum bits ignored 
				32,                               // 32-bit z-buffer     
				0,                                // no stencil buffer 
				0,                                // no auxiliary buffer 
				PFD_MAIN_PLANE,                   // main layer 
				0,                                // reserved 
				0, 0, 0                           // layer masks ignored 
			}; 

			int nFormat = ChoosePixelFormat(m_hDC, &pfd);
			SetPixelFormat(m_hDC, nFormat, &pfd);

			// Create OpenGL Rendering Context
			m_hRC = (wglCreateContext(m_hDC));
			if (m_hRC == 0) 
				MessageBox::Show("wglCreateContext Error");
			// Assign OpenGL Rendering Context
			if (wglMakeCurrent(m_hDC, m_hRC ) == false) 
				MessageBox::Show("wglMakeCurrent Error");

			InitGL();
			ReSizeGLScene(500,500);
			// ------------------------------------------------------------------
			rtri = 0.0f;
			timer1->Interval = 10;
			timer1->Enabled = true;
		}
		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
		
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Ustawienia Blendingu
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Kolor t³a
			glClearDepth(1.0);									// Czyœci bufor g³êbi
			glFlush();
			glDepthFunc(GL_LESS);								// test g³êbi
			glShadeModel(GL_SMOOTH);							// wyg³adzenie on
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// perspektywa
				   GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 0.5 };
			   GLfloat mat_shininess[] = { 10.0 };
			   GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 2.0 };
			   GLfloat light_diffuse[] = { 0.4, 0.4, 0.4, 3.0 };
			   GLfloat light_position[] = { 0.0, 0.0, 2.0, 1.0 };

			   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
			   glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
			   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
			   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

			glEnable(GL_COLOR_MATERIAL);
			glEnable(GL_DEPTH_TEST);

			frameCount=0;
			fps=0;
			currentTime = 0; 
			previousTime = 0;
			return TRUE;										// Initialisation went ok
		}
		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height==0)										// Prevent A Divide By Zero By
			{
				height=1;										// Making Height Equal One
			}

			glViewport(0,0,width,height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~My3okno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  OpenGLPanel;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		static HWND m_hWnd;
		static HDC  m_hDC;
		static HGLRC m_hRC;
		GLfloat	rtri;				// Angle for the triangle
		int frameCount;
		float fps;
		int currentTime, previousTime;

		int f;
		int rotacja2, f2, swiatlo2;
		float kolor12, kolor22, kolor32;
private: System::Windows::Forms::Button^  czajnik;
private: System::Windows::Forms::Button^  dwudziestoscian;
private: System::Windows::Forms::Button^  dwunastoscian;
private: System::Windows::Forms::Button^  smioscian;
private: System::Windows::Forms::Button^  czworoscian;
private: System::Windows::Forms::Button^  torus;
private: System::Windows::Forms::Button^  stozek;
private: System::Windows::Forms::Button^  szescian;
private: System::Windows::Forms::Button^  sfera;
private: System::Windows::Forms::TextBox^  Codeview;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::NumericUpDown^  fps2;
private: System::Windows::Forms::NumericUpDown^  znaki;
private: System::Windows::Forms::NumericUpDown^  wiersze;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::GroupBox^  Sterowanie;
private: System::Windows::Forms::RadioButton^  radioButton2;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::NumericUpDown^  color1a;
private: System::Windows::Forms::NumericUpDown^  color1c;
private: System::Windows::Forms::NumericUpDown^  color1b;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::CheckBox^  checkBox3;
private: System::Windows::Forms::Label^  label3;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->OpenGLPanel = (gcnew System::Windows::Forms::Panel());
			this->czajnik = (gcnew System::Windows::Forms::Button());
			this->dwudziestoscian = (gcnew System::Windows::Forms::Button());
			this->dwunastoscian = (gcnew System::Windows::Forms::Button());
			this->smioscian = (gcnew System::Windows::Forms::Button());
			this->czworoscian = (gcnew System::Windows::Forms::Button());
			this->torus = (gcnew System::Windows::Forms::Button());
			this->stozek = (gcnew System::Windows::Forms::Button());
			this->szescian = (gcnew System::Windows::Forms::Button());
			this->sfera = (gcnew System::Windows::Forms::Button());
			this->Codeview = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fps2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->znaki = (gcnew System::Windows::Forms::NumericUpDown());
			this->wiersze = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Sterowanie = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->color1a = (gcnew System::Windows::Forms::NumericUpDown());
			this->color1c = (gcnew System::Windows::Forms::NumericUpDown());
			this->color1b = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->BeginInit();
			this->Sterowanie->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1c))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1b))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &My3okno::timer1_Tick);
			// 
			// OpenGLPanel
			// 
			this->OpenGLPanel->Location = System::Drawing::Point(10, 10);
			this->OpenGLPanel->Name = L"OpenGLPanel";
			this->OpenGLPanel->Size = System::Drawing::Size(500, 500);
			this->OpenGLPanel->TabIndex = 2;
			// 
			// czajnik
			// 
			this->czajnik->Location = System::Drawing::Point(890, 530);
			this->czajnik->Name = L"czajnik";
			this->czajnik->Size = System::Drawing::Size(80, 60);
			this->czajnik->TabIndex = 32;
			this->czajnik->Text = L"CZAJNIK";
			this->czajnik->UseVisualStyleBackColor = true;
			this->czajnik->Click += gcnew System::EventHandler(this, &My3okno::czajnik_Click);
			// 
			// dwudziestoscian
			// 
			this->dwudziestoscian->Location = System::Drawing::Point(750, 530);
			this->dwudziestoscian->Name = L"dwudziestoscian";
			this->dwudziestoscian->Size = System::Drawing::Size(124, 60);
			this->dwudziestoscian->TabIndex = 31;
			this->dwudziestoscian->Text = L"DWUDZIESTOŒCIAN";
			this->dwudziestoscian->UseVisualStyleBackColor = true;
			this->dwudziestoscian->Click += gcnew System::EventHandler(this, &My3okno::dwudziestoscian_Click);
			// 
			// dwunastoscian
			// 
			this->dwunastoscian->Location = System::Drawing::Point(620, 530);
			this->dwunastoscian->Name = L"dwunastoscian";
			this->dwunastoscian->Size = System::Drawing::Size(114, 60);
			this->dwunastoscian->TabIndex = 34;
			this->dwunastoscian->Text = L"DWUNASTOŒCIAN";
			this->dwunastoscian->UseVisualStyleBackColor = true;
			this->dwunastoscian->Click += gcnew System::EventHandler(this, &My3okno::dwunastoscian_Click);
			// 
			// smioscian
			// 
			this->smioscian->Location = System::Drawing::Point(500, 530);
			this->smioscian->Name = L"smioscian";
			this->smioscian->Size = System::Drawing::Size(104, 60);
			this->smioscian->TabIndex = 33;
			this->smioscian->Text = L"OŒMIOŒCIAN";
			this->smioscian->UseVisualStyleBackColor = true;
			this->smioscian->Click += gcnew System::EventHandler(this, &My3okno::smioscian_Click);
			// 
			// czworoscian
			// 
			this->czworoscian->AllowDrop = true;
			this->czworoscian->Location = System::Drawing::Point(380, 530);
			this->czworoscian->Name = L"czworoscian";
			this->czworoscian->Size = System::Drawing::Size(104, 60);
			this->czworoscian->TabIndex = 30;
			this->czworoscian->Text = L"CZWOROŒCIAN";
			this->czworoscian->UseVisualStyleBackColor = true;
			this->czworoscian->Click += gcnew System::EventHandler(this, &My3okno::czworoscian_Click);
			// 
			// torus
			// 
			this->torus->Location = System::Drawing::Point(290, 530);
			this->torus->Name = L"torus";
			this->torus->Size = System::Drawing::Size(74, 60);
			this->torus->TabIndex = 27;
			this->torus->Text = L"TORUS";
			this->torus->UseVisualStyleBackColor = true;
			this->torus->Click += gcnew System::EventHandler(this, &My3okno::torus_Click);
			// 
			// stozek
			// 
			this->stozek->Location = System::Drawing::Point(202, 530);
			this->stozek->Name = L"stozek";
			this->stozek->Size = System::Drawing::Size(72, 60);
			this->stozek->TabIndex = 26;
			this->stozek->Text = L"STO¯EK";
			this->stozek->UseVisualStyleBackColor = true;
			this->stozek->Click += gcnew System::EventHandler(this, &My3okno::stozek_Click);
			// 
			// szescian
			// 
			this->szescian->Location = System::Drawing::Point(108, 530);
			this->szescian->Name = L"szescian";
			this->szescian->Size = System::Drawing::Size(78, 60);
			this->szescian->TabIndex = 29;
			this->szescian->Text = L"SZEŒCIAN";
			this->szescian->UseVisualStyleBackColor = true;
			this->szescian->Click += gcnew System::EventHandler(this, &My3okno::szescian_Click);
			// 
			// sfera
			// 
			this->sfera->Location = System::Drawing::Point(16, 530);
			this->sfera->Name = L"sfera";
			this->sfera->Size = System::Drawing::Size(76, 60);
			this->sfera->TabIndex = 28;
			this->sfera->Text = L"SFERA";
			this->sfera->UseVisualStyleBackColor = true;
			this->sfera->Click += gcnew System::EventHandler(this, &My3okno::sfera_Click);
			// 
			// Codeview
			// 
			this->Codeview->BackColor = System::Drawing::Color::Black;
			this->Codeview->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->Codeview->ForeColor = System::Drawing::Color::LimeGreen;
			this->Codeview->Location = System::Drawing::Point(520, 10);
			this->Codeview->Multiline = true;
			this->Codeview->Name = L"Codeview";
			this->Codeview->ReadOnly = true;
			this->Codeview->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Codeview->Size = System::Drawing::Size(450, 350);
			this->Codeview->TabIndex = 23;
			this->Codeview->WordWrap = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->fps2);
			this->groupBox1->Controls->Add(this->znaki);
			this->groupBox1->Controls->Add(this->wiersze);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(520, 370);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(450, 55);
			this->groupBox1->TabIndex = 24;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Informacje";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(18, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Iloœæ wierszy:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(171, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Iloœæ znaków:";
			// 
			// fps2
			// 
			this->fps2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->fps2->DecimalPlaces = 4;
			this->fps2->Enabled = false;
			this->fps2->ForeColor = System::Drawing::Color::Black;
			this->fps2->InterceptArrowKeys = false;
			this->fps2->Location = System::Drawing::Point(365, 20);
			this->fps2->Name = L"fps2";
			this->fps2->ReadOnly = true;
			this->fps2->Size = System::Drawing::Size(68, 20);
			this->fps2->TabIndex = 4;
			this->fps2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// znaki
			// 
			this->znaki->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->znaki->Enabled = false;
			this->znaki->ForeColor = System::Drawing::Color::Black;
			this->znaki->InterceptArrowKeys = false;
			this->znaki->Location = System::Drawing::Point(251, 20);
			this->znaki->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->znaki->Name = L"znaki";
			this->znaki->ReadOnly = true;
			this->znaki->Size = System::Drawing::Size(68, 20);
			this->znaki->TabIndex = 4;
			this->znaki->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {96, 0, 0, 0});
			// 
			// wiersze
			// 
			this->wiersze->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->wiersze->Enabled = false;
			this->wiersze->ForeColor = System::Drawing::Color::Black;
			this->wiersze->InterceptArrowKeys = false;
			this->wiersze->Location = System::Drawing::Point(95, 20);
			this->wiersze->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->wiersze->Name = L"wiersze";
			this->wiersze->ReadOnly = true;
			this->wiersze->Size = System::Drawing::Size(68, 20);
			this->wiersze->TabIndex = 4;
			this->wiersze->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(327, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"FPS:";
			// 
			// Sterowanie
			// 
			this->Sterowanie->Controls->Add(this->checkBox3);
			this->Sterowanie->Controls->Add(this->radioButton2);
			this->Sterowanie->Controls->Add(this->radioButton1);
			this->Sterowanie->Controls->Add(this->label1);
			this->Sterowanie->Controls->Add(this->label7);
			this->Sterowanie->Controls->Add(this->color1a);
			this->Sterowanie->Controls->Add(this->color1c);
			this->Sterowanie->Controls->Add(this->color1b);
			this->Sterowanie->Controls->Add(this->checkBox2);
			this->Sterowanie->Controls->Add(this->checkBox1);
			this->Sterowanie->Controls->Add(this->label3);
			this->Sterowanie->Location = System::Drawing::Point(520, 430);
			this->Sterowanie->Name = L"Sterowanie";
			this->Sterowanie->Size = System::Drawing::Size(450, 94);
			this->Sterowanie->TabIndex = 25;
			this->Sterowanie->TabStop = false;
			this->Sterowanie->Text = L"Sterowanie";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(194, 23);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(49, 17);
			this->checkBox3->TabIndex = 35;
			this->checkBox3->Text = L"Oœ Z";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(365, 49);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(45, 17);
			this->radioButton2->TabIndex = 27;
			this->radioButton2->Text = L"OFF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(365, 22);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(41, 17);
			this->radioButton1->TabIndex = 26;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ON";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(311, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Œwiat³o:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(18, 60);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Kolor:";
			// 
			// color1a
			// 
			this->color1a->DecimalPlaces = 2;
			this->color1a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1a->Location = System::Drawing::Point(72, 58);
			this->color1a->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1a->Name = L"color1a";
			this->color1a->Size = System::Drawing::Size(50, 20);
			this->color1a->TabIndex = 23;
			this->color1a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color1c
			// 
			this->color1c->DecimalPlaces = 2;
			this->color1c->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1c->Location = System::Drawing::Point(194, 58);
			this->color1c->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1c->Name = L"color1c";
			this->color1c->Size = System::Drawing::Size(50, 20);
			this->color1c->TabIndex = 21;
			this->color1c->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color1b
			// 
			this->color1b->DecimalPlaces = 2;
			this->color1b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1b->Location = System::Drawing::Point(133, 58);
			this->color1b->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1b->Name = L"color1b";
			this->color1b->Size = System::Drawing::Size(50, 20);
			this->color1b->TabIndex = 22;
			this->color1b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(72, 23);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 17);
			this->checkBox2->TabIndex = 15;
			this->checkBox2->Text = L"Oœ X";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(133, 23);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(49, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"Oœ Y";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Rotacja:";
			// 
			// My3okno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->czajnik);
			this->Controls->Add(this->dwudziestoscian);
			this->Controls->Add(this->dwunastoscian);
			this->Controls->Add(this->smioscian);
			this->Controls->Add(this->czworoscian);
			this->Controls->Add(this->torus);
			this->Controls->Add(this->stozek);
			this->Controls->Add(this->szescian);
			this->Controls->Add(this->sfera);
			this->Controls->Add(this->Codeview);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Sterowanie);
			this->Controls->Add(this->OpenGLPanel);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 640);
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->Name = L"My3okno";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"C++ & OpenGL: Obiekty 3D +  Œwiat³o";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &My3okno::My3okno_FormClosed);
			this->Load += gcnew System::EventHandler(this, &My3okno::My3okno_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->EndInit();
			this->Sterowanie->ResumeLayout(false);
			this->Sterowanie->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1c))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1b))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	float FPS(){
			frameCount++;
			currentTime = glutGet(GLUT_ELAPSED_TIME);
			int timeInterval = currentTime - previousTime;

			if(timeInterval > 1000)
			{
				fps = frameCount / (timeInterval / 1000.0f);
				previousTime = currentTime;
				frameCount = 0;
			}  
		return fps;
		}
	System::Void Render(int r, int f, int s, float c1a2, float c1b2, float c1c2)
	{
			wglMakeCurrent(m_hDC, m_hRC);
		
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			glTranslatef(0.0f,0.0f,-6.0f);
			if (s==1){
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
			};
				if (r > 0)
				{
					switch (r)
					{
						case 1:
							glRotatef(rtri,1.0f,0.0f,0.0f);
							break;
						case 2:
							glRotatef(rtri,0.0f,1.0f,0.0f);
							break;
						case 3:
							glRotatef(rtri,0.0f,0.0f,1.0f);
							break;
						case 4:
							glRotatef(rtri,1.0f,1.0f,0.0f);
							break;
						case 5:
							glRotatef(rtri,1.0f,0.0f,1.0f);
							break;
						case 6:
							glRotatef(rtri,0.0f,1.0f,1.0f);
							break;
						case 7:
							glRotatef(rtri,1.0f,1.0f,1.0f);
							break;
					}
				}else{
				rtri=0;
				}
			glColor3f(c1a2,c1b2,c1c2);
			switch(f)
			{
				case 1:
					glutSolidSphere(1.5f,15,15); //sfera
					break;
				case 2:
					glutSolidCube(1.5f); //szeœcian
					break;
				case 3:
					glutSolidCone(1.0f,1.5f,12,12); //sto¿ek
					break;
				case 4:
					glutSolidTorus(0.5f,1.0f,12,12); //Torus
					break;
				case 5:
					glutSolidTetrahedron();//czworoœcianu
					break;
				case 6:
					glutSolidOctahedron();//oœmioœcian
					break;
				case 7:
					glutSolidDodecahedron(); //dwunastoœcian
					break;
				case 8:
					glutSolidIcosahedron(); //dwudziestoœcian
					break;
				case 9:
					glutSolidTeapot(1.5f); //czajnik
					break;
			}
		
			rtri+=0.2f;
			if (s==1)
			{
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
			};

			glFlush();
			SwapBuffers( m_hDC );
		}
	System::Void tresc(int r, int f, int s, float c1a2, float c1b2, float c1c2){
			Codeview->Text = L"glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);\r\nglLoadIdentity();\r\nglTranslatef(0.0f,0.0f,-6.0f);\r\n\r\n";
			if (r > 0)
				{
					switch (r)
					{
						case 1:
							Codeview->Text += "glRotatef(rtri,1.0f,0.0f,0.0f);\r\n\r\n";
							break;
						case 2:
							Codeview->Text += "glRotatef(rtri,0.0f,1.0f,0.0f);\r\n\r\n";
							break;
						case 3:
							Codeview->Text += "glRotatef(rtri,0.0f,0.0f,1.0f);\r\n\r\n";
							break;
						case 4:
							Codeview->Text += "glRotatef(rtri,1.0f,1.0f,0.0f);\r\n\r\n";
							break;
						case 5:
							Codeview->Text += "glRotatef(rtri,1.0f,0.0f,1.0f);\r\n\r\n";
							break;
						case 6:
							Codeview->Text += "glRotatef(rtri,0.0f,1.0f,1.0f);\r\n\r\n";
							break;
						case 7:
							Codeview->Text += "glRotatef(rtri,1.0f,1.0f,1.0f);\r\n\r\n";
							break;
					}
				}
			if (s==1){
				Codeview->Text = Codeview->Text + "glEnable(GL_LIGHTING)\r\nglEnable(GL_LIGHT0);\r\n\r\n";
			}
			Codeview->Text = Codeview->Text + "glColor3f(" + c1a2  + "f," + c1b2 + "f," + c1c2 + "f);\r\n\r\n";
			switch(f)
			{
			case 1:
				Codeview->Text = Codeview->Text + "\tglutSolidSphere(1.5f,15,15);\r\n";
				break;
			case 2:
				Codeview->Text = Codeview->Text + "\tglutSolidCube(1.5f);\r\n";
				break;
			case 3:
				Codeview->Text = Codeview->Text + "\tglutSolidCone(1.0f,1.5f,12,12);\r\n";
				break;
			case 4:
				Codeview->Text = Codeview->Text + "\tglutSolidTorus(0.5f,1.0f,12,12);\r\n";
				break;
			case 5:
				Codeview->Text = Codeview->Text + "\tglutSolidTetrahedron();\r\n";
				break;
			case 6:
				Codeview->Text = Codeview->Text + "\tglutSolidOctahedron();\r\n";
				break;
			case 7:
				Codeview->Text = Codeview->Text + "\tglutSolidDodecahedron();\r\n";
				break;
			case 8:
				Codeview->Text = Codeview->Text + "\tglutSolidIcosahedron();\r\n";
				break;
			case 9:
				Codeview->Text = Codeview->Text + "\tglutSolidTeapot(1.5f);\r\n";
				break;

			}

			if (s==1){
				Codeview->Text = Codeview->Text + "\r\nglDisable(GL_LIGHTING)\r\nglDisable(GL_LIGHT0);\r\n\r\n";
			}
			if (r>0 && r<8){
				Codeview->Text = Codeview->Text + "\t\r\nrtri+=0.2f;";
			};
			}

	private: System::Void My3okno_Load(System::Object^  sender, System::EventArgs^  e) {
				 f=1;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			int rotacja = 0;
            if (checkBox1->Checked && checkBox2->Checked && checkBox3->Checked)
            {
                rotacja = 7;
            }
            else if (checkBox1->Checked && checkBox3->Checked)
            {
                rotacja = 6;
            }
            else if (checkBox2->Checked && checkBox3->Checked)
            {
                rotacja = 5;
            }
            else if (checkBox1->Checked && checkBox2->Checked)
            {
                rotacja = 4;
            }
            else if (checkBox3->Checked)
            {
                rotacja = 3;
            }
            else if (checkBox1->Checked)
            {
                rotacja = 2;
            }
            else if (checkBox2->Checked)
            {
                rotacja = 1;
            };
				 int swiatlo = 0;
				 if (radioButton1->Checked){
					 swiatlo =1;
				 }else if (radioButton2->Checked){
					swiatlo =2;
				 }

				 float kolor1 = (float)color1a->Value;
				 float kolor2 = (float)color1b->Value;
				 float kolor3 = (float)color1c->Value;

				 Render(rotacja, f, swiatlo , kolor1, kolor2, kolor3);
				 if (rotacja!=rotacja2 || f!=f2 || swiatlo!=swiatlo2 || kolor1!=kolor12 || kolor2!=kolor22 || kolor3!=kolor32){
				 tresc(rotacja, f, swiatlo , kolor1, kolor2, kolor3);
				 rotacja2=rotacja;
				 f2=f;
				 swiatlo2=swiatlo;
				 kolor12=kolor1;
				 kolor22=kolor2;
				 kolor32=kolor3;
				 }
				 wiersze->Value = Codeview->Lines->Length;
				 znaki->Value = Codeview->Text->Length;
			 	 float dd = FPS();
				 fps2->Value =(System::Decimal)dd;
			 }
private: System::Void sfera_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=1;
		 }
private: System::Void szescian_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=2;
		 }
private: System::Void stozek_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=3;
		 }
private: System::Void torus_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=4;
		 }
private: System::Void czworoscian_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=5;
		 }
private: System::Void smioscian_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=6;
		 }
private: System::Void dwunastoscian_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=7;
		 }
private: System::Void dwudziestoscian_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=8;
		 }
private: System::Void czajnik_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=9;
		 }
private: System::Void My3okno_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Application::Restart();
		 }
};
}
