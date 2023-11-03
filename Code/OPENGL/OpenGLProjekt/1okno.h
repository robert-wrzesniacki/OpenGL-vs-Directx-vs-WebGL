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
	/// Summary for My1okno
	/// </summary>
	public ref class My1okno : public System::Windows::Forms::Form
	{
	public:
		My1okno(void)
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
		System::Void Kill(){
				if (m_hRC)											
	{
		if (!wglMakeCurrent(NULL,NULL))					
		{
			MessageBox::Show("zwolnienie");
		}

		if (!wglDeleteContext(m_hRC))						
		{
			MessageBox::Show("usuwanie");
		}
		m_hRC=NULL;										
	}
		if (m_hDC && !ReleaseDC(m_hWnd,m_hDC))				
	{
		MessageBox::Show("zwolnienie 2");
		m_hDC=NULL;										
	}

	if (m_hWnd && !DestroyWindow(m_hWnd))					
	{
		MessageBox::Show("niszczenie");
		m_hWnd=NULL;										
	}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~My1okno()
		{
	
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
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

		int a;
		int rotacja2;
	    int b2;
		int a2;
		float c2;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::NumericUpDown^  fps2;
private: System::Windows::Forms::NumericUpDown^  znaki;
private: System::Windows::Forms::NumericUpDown^  wiersze;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Button^  polygon;
private: System::Windows::Forms::Button^  quadss;
private: System::Windows::Forms::Button^  quads;
private: System::Windows::Forms::Button^  trianglesf;
private: System::Windows::Forms::Button^  triangless;
private: System::Windows::Forms::Button^  triangles;
private: System::Windows::Forms::Button^  linel;
private: System::Windows::Forms::Button^  liness;
private: System::Windows::Forms::Button^  lines;
private: System::Windows::Forms::Button^  points;
private: System::Windows::Forms::GroupBox^  Sterowanie;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::NumericUpDown^  liczba2;
private: System::Windows::Forms::NumericUpDown^  liczba1;
private: System::Windows::Forms::TextBox^  Codeview;
private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Panel^  OpenGLPanel;




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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fps2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->znaki = (gcnew System::Windows::Forms::NumericUpDown());
			this->wiersze = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->polygon = (gcnew System::Windows::Forms::Button());
			this->quadss = (gcnew System::Windows::Forms::Button());
			this->quads = (gcnew System::Windows::Forms::Button());
			this->trianglesf = (gcnew System::Windows::Forms::Button());
			this->triangless = (gcnew System::Windows::Forms::Button());
			this->triangles = (gcnew System::Windows::Forms::Button());
			this->linel = (gcnew System::Windows::Forms::Button());
			this->liness = (gcnew System::Windows::Forms::Button());
			this->lines = (gcnew System::Windows::Forms::Button());
			this->points = (gcnew System::Windows::Forms::Button());
			this->Sterowanie = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->liczba2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->liczba1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->Codeview = (gcnew System::Windows::Forms::TextBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->BeginInit();
			this->Sterowanie->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->liczba2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->liczba1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &My1okno::timer1_Tick);
			// 
			// OpenGLPanel
			// 
			this->OpenGLPanel->Location = System::Drawing::Point(10, 10);
			this->OpenGLPanel->Name = L"OpenGLPanel";
			this->OpenGLPanel->Size = System::Drawing::Size(500, 500);
			this->OpenGLPanel->TabIndex = 0;
			this->OpenGLPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &My1okno::OpenGLPanel_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->fps2);
			this->groupBox1->Controls->Add(this->znaki);
			this->groupBox1->Controls->Add(this->wiersze);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(777, 373);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(195, 140);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Informacje";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(20, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Iloœæ wierszy:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 55);
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
			this->fps2->Location = System::Drawing::Point(102, 88);
			this->fps2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
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
			this->znaki->Location = System::Drawing::Point(102, 55);
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
			this->wiersze->Location = System::Drawing::Point(102, 18);
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
			this->label4->Location = System::Drawing::Point(20, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"FPS:";
			// 
			// polygon
			// 
			this->polygon->Location = System::Drawing::Point(882, 530);
			this->polygon->Name = L"polygon";
			this->polygon->Size = System::Drawing::Size(90, 60);
			this->polygon->TabIndex = 16;
			this->polygon->Text = L"GL_POLYGON";
			this->polygon->UseVisualStyleBackColor = true;
			this->polygon->Click += gcnew System::EventHandler(this, &My1okno::polygon_Click);
			// 
			// quadss
			// 
			this->quadss->Location = System::Drawing::Point(802, 530);
			this->quadss->Name = L"quadss";
			this->quadss->Size = System::Drawing::Size(70, 60);
			this->quadss->TabIndex = 15;
			this->quadss->Text = L"GL_QUAD_STRIP";
			this->quadss->UseVisualStyleBackColor = true;
			this->quadss->Click += gcnew System::EventHandler(this, &My1okno::quadss_Click);
			// 
			// quads
			// 
			this->quads->Location = System::Drawing::Point(712, 530);
			this->quads->Name = L"quads";
			this->quads->Size = System::Drawing::Size(80, 60);
			this->quads->TabIndex = 17;
			this->quads->Text = L"GL_QUADS";
			this->quads->UseVisualStyleBackColor = true;
			this->quads->Click += gcnew System::EventHandler(this, &My1okno::quads_Click);
			// 
			// trianglesf
			// 
			this->trianglesf->Location = System::Drawing::Point(612, 530);
			this->trianglesf->Name = L"trianglesf";
			this->trianglesf->Size = System::Drawing::Size(90, 60);
			this->trianglesf->TabIndex = 19;
			this->trianglesf->Text = L"GL_TRIANGLE_FAN";
			this->trianglesf->UseVisualStyleBackColor = true;
			this->trianglesf->Click += gcnew System::EventHandler(this, &My1okno::trianglesf_Click);
			// 
			// triangless
			// 
			this->triangless->Location = System::Drawing::Point(512, 530);
			this->triangless->Name = L"triangless";
			this->triangless->Size = System::Drawing::Size(90, 60);
			this->triangless->TabIndex = 18;
			this->triangless->Text = L"GL_TRIANGLE_STRIP";
			this->triangless->UseVisualStyleBackColor = true;
			this->triangless->Click += gcnew System::EventHandler(this, &My1okno::triangless_Click);
			// 
			// triangles
			// 
			this->triangles->AllowDrop = true;
			this->triangles->Location = System::Drawing::Point(402, 530);
			this->triangles->Name = L"triangles";
			this->triangles->Size = System::Drawing::Size(100, 60);
			this->triangles->TabIndex = 14;
			this->triangles->Text = L"GL_TRIANGLES";
			this->triangles->UseVisualStyleBackColor = true;
			this->triangles->Click += gcnew System::EventHandler(this, &My1okno::triangles_Click);
			// 
			// linel
			// 
			this->linel->Location = System::Drawing::Point(292, 530);
			this->linel->Name = L"linel";
			this->linel->Size = System::Drawing::Size(100, 60);
			this->linel->TabIndex = 11;
			this->linel->Text = L"GL_LINE_LOOP";
			this->linel->UseVisualStyleBackColor = true;
			this->linel->Click += gcnew System::EventHandler(this, &My1okno::linel_Click);
			// 
			// liness
			// 
			this->liness->Location = System::Drawing::Point(182, 530);
			this->liness->Name = L"liness";
			this->liness->Size = System::Drawing::Size(100, 60);
			this->liness->TabIndex = 10;
			this->liness->Text = L"GL_LINE_STRIP";
			this->liness->UseVisualStyleBackColor = true;
			this->liness->Click += gcnew System::EventHandler(this, &My1okno::liness_Click);
			// 
			// lines
			// 
			this->lines->Location = System::Drawing::Point(102, 530);
			this->lines->Name = L"lines";
			this->lines->Size = System::Drawing::Size(70, 60);
			this->lines->TabIndex = 13;
			this->lines->Text = L"GL_LINES";
			this->lines->UseVisualStyleBackColor = true;
			this->lines->Click += gcnew System::EventHandler(this, &My1okno::lines_Click);
			// 
			// points
			// 
			this->points->Location = System::Drawing::Point(12, 530);
			this->points->Name = L"points";
			this->points->Size = System::Drawing::Size(80, 60);
			this->points->TabIndex = 12;
			this->points->Text = L"GL_POINTS";
			this->points->UseVisualStyleBackColor = true;
			this->points->Click += gcnew System::EventHandler(this, &My1okno::points_Click);
			// 
			// Sterowanie
			// 
			this->Sterowanie->Controls->Add(this->checkBox3);
			this->Sterowanie->Controls->Add(this->checkBox2);
			this->Sterowanie->Controls->Add(this->checkBox1);
			this->Sterowanie->Controls->Add(this->label3);
			this->Sterowanie->Controls->Add(this->label2);
			this->Sterowanie->Controls->Add(this->label1);
			this->Sterowanie->Controls->Add(this->liczba2);
			this->Sterowanie->Controls->Add(this->liczba1);
			this->Sterowanie->Location = System::Drawing::Point(522, 373);
			this->Sterowanie->Name = L"Sterowanie";
			this->Sterowanie->Size = System::Drawing::Size(251, 140);
			this->Sterowanie->TabIndex = 9;
			this->Sterowanie->TabStop = false;
			this->Sterowanie->Text = L"Sterowanie";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(53, 88);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 17);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"Oœ X";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(117, 88);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(49, 17);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"Oœ Y";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Rotacja:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Wielkoœæ punktów:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Iloœæ punktów:";
			// 
			// liczba2
			// 
			this->liczba2->DecimalPlaces = 1;
			this->liczba2->Location = System::Drawing::Point(110, 53);
			this->liczba2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->liczba2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->liczba2->Name = L"liczba2";
			this->liczba2->Size = System::Drawing::Size(120, 20);
			this->liczba2->TabIndex = 0;
			this->liczba2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// liczba1
			// 
			this->liczba1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->liczba1->Location = System::Drawing::Point(110, 18);
			this->liczba1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {17, 0, 0, 0});
			this->liczba1->Name = L"liczba1";
			this->liczba1->Size = System::Drawing::Size(120, 20);
			this->liczba1->TabIndex = 0;
			// 
			// Codeview
			// 
			this->Codeview->BackColor = System::Drawing::Color::Black;
			this->Codeview->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->Codeview->ForeColor = System::Drawing::Color::LimeGreen;
			this->Codeview->Location = System::Drawing::Point(522, 13);
			this->Codeview->Multiline = true;
			this->Codeview->Name = L"Codeview";
			this->Codeview->ReadOnly = true;
			this->Codeview->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Codeview->Size = System::Drawing::Size(450, 350);
			this->Codeview->TabIndex = 8;
			this->Codeview->WordWrap = false;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(181, 88);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(49, 17);
			this->checkBox3->TabIndex = 4;
			this->checkBox3->Text = L"Oœ Z";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// My1okno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->polygon);
			this->Controls->Add(this->quadss);
			this->Controls->Add(this->quads);
			this->Controls->Add(this->trianglesf);
			this->Controls->Add(this->triangless);
			this->Controls->Add(this->triangles);
			this->Controls->Add(this->linel);
			this->Controls->Add(this->liness);
			this->Controls->Add(this->lines);
			this->Controls->Add(this->points);
			this->Controls->Add(this->Sterowanie);
			this->Controls->Add(this->Codeview);
			this->Controls->Add(this->OpenGLPanel);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 640);
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->Name = L"My1okno";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"C++ & OpenGL: Podstawowe elementy grafiki";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &My1okno::My1okno_FormClosed);
			this->Load += gcnew System::EventHandler(this, &My1okno::My1okno_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->EndInit();
			this->Sterowanie->ResumeLayout(false);
			this->Sterowanie->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->liczba2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->liczba1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::Void Punkty(int p, float w)
  {
	glPointSize(w);
	glBegin(GL_POINTS);
	switch(p) 
	{
		case 1:
			glVertex2f( 0.0f, 0.0f);
			break;
		case 2:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			break;
		case 3:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			break;
		case 4:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			break;
		case 5:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			break;
		case 6:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);		
			break;
		case 7:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			break;
		case 8:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			break;
		case 9:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			break;
		case 10:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);

			glVertex2f( 0.0f, 2.0f); 
			break;
		case 11:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			break;
		case 12:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			break;
		case 13:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			break;
		case 14:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			break;
		case 15:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			break;
		case 16:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			break;
		case 17:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( -1.75f, 1.75f);
			break;
	}
	glEnd();
   }
		System::Void Linie(int p)
  {
	glBegin(GL_LINES);
	switch (p)
	{
		case 2:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			break;
		case 4:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			break;
		case 6:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			break;
		case 8:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			break;
		case 10:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);		
			break;
		case 12:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);			
			break;	
		case 14:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);			
			break;
		case 16:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			break;
		case 18:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);			
			break;
		case 20:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);	
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);			
			break;
		case 22:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);	
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);	
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( 0.0f, 2.0f);			
			break;
		case 24:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);	
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);	
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 2.0f, 0.0f);			
			break;
		case 26:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);	
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);	
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 0.0f, -2.0f);			
			break;
		case 28:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);	
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);	
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -2.0f, 0.0f);
			break;
		case 30:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);	
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);	
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( -2.0f, -2.0f);
			glVertex2f( -2.0f, 2.0f);			
			break;
		case 32:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);	
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);	
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( -2.0f, -2.0f);
			glVertex2f( -2.0f, 2.0f);	
			glVertex2f( -2.0f, 2.0f);
			glVertex2f( 2.0f, 2.0f);			
			break;
		case 34:
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( -1.0f, 1.0f);
			glVertex2f( 1.0f, 1.0f);	
			glVertex2f( 1.0f, 1.0f);
			glVertex2f( 1.0f, -1.0f);			
			glVertex2f( 1.0f, -1.0f);
			glVertex2f( -1.0f, -1.0f);			
			glVertex2f( -1.0f, -1.0f);
			glVertex2f( -1.0f, 1.0f);				
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( 0.0f, 2.0f);		
			glVertex2f( 0.0f, 2.0f);
			glVertex2f( 2.0f, 0.0f);	
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 0.0f, -2.0f);	
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -2.0f, 0.0f);		
			glVertex2f( -2.0f, -2.0f);
			glVertex2f( -2.0f, 2.0f);			
			glVertex2f( -2.0f, 2.0f);
			glVertex2f( 2.0f, 2.0f);		
			glVertex2f( 2.0f, 2.0f);
			glVertex2f( 2.0f, -2.0f);			
			break;
	}
	glEnd();
  }
		System::Void Linie2(int p)
   {
	   glBegin(GL_LINE_STRIP);
	   switch(p) 
	{

		case 2:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			break;
		case 3:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			break;
		case 4:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			break;
		case 5:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);		
			break;
		case 6:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			break;
		case 7:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			break;
		case 8:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			break;
		case 9:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);
			break;
		case 10:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			break;
		case 11:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			break;
		case 12:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			break;
		case 13:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			break;
		case 14:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			break;
		case 15:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			break;
		case 16:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			break;
		case 17:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( -1.75f, 1.75f);
			break;
		case 18:
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			glVertex2f( 0.0f, 1.0f);

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( -1.75f, 1.75f);
			glVertex2f( 0.0f, 2.0f);
			break;
	}
	glEnd();
   }
   		System::Void Linie3(int p)
   {
	   glBegin(GL_LINE_LOOP);

		switch(p) 
	{
		case 2:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			break;
		case 3:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			break;
		case 4:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			break;
		case 5:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			break;
		case 6:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);		
			break;
		case 7:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			break;
		case 8:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			break;
		case 9:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);
			break;
		case 10:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);

			glVertex2f( 0.0f, 2.0f); 
			break;
		case 11:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			break;
		case 12:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			break;
		case 13:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			break;
		case 14:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			break;
		case 15:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			break;
		case 16:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			break;
		case 17:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( -1.75f, 1.75f);
			break;
		case 18:
			glVertex2f( 0.0f, 0.0f);
			glVertex2f( 0.0f, 1.0f);
			glVertex2f( 0.75f, 0.75f);
			glVertex2f( 1.0f, 0.0f);
			glVertex2f( 0.75f, -0.75f);
			glVertex2f( 0.0f, -1.0f);
			glVertex2f( -0.75f, -0.75f);
			glVertex2f( -1.0f, 0.0f);
			glVertex2f( -0.75f, 0.75f);		

			glVertex2f( 0.0f, 2.0f); 
			glVertex2f( 1.75f, 1.75f);
			glVertex2f( 2.0f, 0.0f);
			glVertex2f( 1.75f, -1.75f);
			glVertex2f( 0.0f, -2.0f);
			glVertex2f( -1.75f, -1.75f);
			glVertex2f( -2.0f, 0.0f);
			glVertex2f( -1.75f, 1.75f);
			glVertex2f( 0.0f, 2.0f);
			break;
	}
	glEnd();
   }
		System::Void Trojkaty(int p)
   {
	   glBegin(GL_TRIANGLES);
		switch (p)
	{
		case 3:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
			break;
		case 6:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 
			break;
		case 9:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 

			glVertex3f( -0.5f, 2.0f, 0.0f);   
			glVertex3f( 0.5f, 2.0f, 0.0f);       
			glVertex3f( 0.0f, 1.0f, 0.0f); 
			break;
		case 12:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 

			glVertex3f( -0.5f, 2.0f, 0.0f);   
			glVertex3f( 0.5f, 2.0f, 0.0f);       
			glVertex3f( 0.0f, 1.0f, 0.0f); 

			glVertex3f( 2.0f, 2.0f, 0.0f);           
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.5f, 1.0f, 0.0f); 
			break;
		case 15:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 

			glVertex3f( -0.5f, 2.0f, 0.0f);   
			glVertex3f( 0.5f, 2.0f, 0.0f);       
			glVertex3f( 0.0f, 1.0f, 0.0f); 

			glVertex3f( 2.0f, 2.0f, 0.0f);           
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.5f, 1.0f, 0.0f); 
	
			glVertex3f( 2.0f, 0.5f, 0.0f);          
			glVertex3f( 2.0f, -0.5f, 0.0f);       
			glVertex3f( 1.0f, 0.0f, 0.0f); 
			break;
		case 18:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 

			glVertex3f( -0.5f, 2.0f, 0.0f);   
			glVertex3f( 0.5f, 2.0f, 0.0f);       
			glVertex3f( 0.0f, 1.0f, 0.0f); 

			glVertex3f( 2.0f, 2.0f, 0.0f);           
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.5f, 1.0f, 0.0f); 
	
			glVertex3f( 2.0f, 0.5f, 0.0f);          
			glVertex3f( 2.0f, -0.5f, 0.0f);       
			glVertex3f( 1.0f, 0.0f, 0.0f); 
		
			glVertex3f( 2.0f, -2.0f, 0.0f); 
			glVertex3f( 1.0f, -2.0f, 0.0f); 
			glVertex3f( 1.5f, -1.0f, 0.0f); 
			break;
		case 21:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 

			glVertex3f( -0.5f, 2.0f, 0.0f);   
			glVertex3f( 0.5f, 2.0f, 0.0f);       
			glVertex3f( 0.0f, 1.0f, 0.0f); 

			glVertex3f( 2.0f, 2.0f, 0.0f);           
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.5f, 1.0f, 0.0f); 
	
			glVertex3f( 2.0f, 0.5f, 0.0f);          
			glVertex3f( 2.0f, -0.5f, 0.0f);       
			glVertex3f( 1.0f, 0.0f, 0.0f); 

			glVertex3f( 2.0f, -2.0f, 0.0f); 
			glVertex3f( 1.0f, -2.0f, 0.0f); 
			glVertex3f( 1.5f, -1.0f, 0.0f); 

			glVertex3f( -0.5f, -2.0f, 0.0f);       
			glVertex3f( 0.5f, -2.0f, 0.0f);         
			glVertex3f( 0.0f, -1.0f, 0.0f);

			break;
		case 24:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 

			glVertex3f( -0.5f, 2.0f, 0.0f);   
			glVertex3f( 0.5f, 2.0f, 0.0f);       
			glVertex3f( 0.0f, 1.0f, 0.0f); 

			glVertex3f( 2.0f, 2.0f, 0.0f);           
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.5f, 1.0f, 0.0f); 
	
			glVertex3f( 2.0f, 0.5f, 0.0f);          
			glVertex3f( 2.0f, -0.5f, 0.0f);       
			glVertex3f( 1.0f, 0.0f, 0.0f); 

			glVertex3f( 2.0f, -2.0f, 0.0f); 
			glVertex3f( 1.0f, -2.0f, 0.0f); 
			glVertex3f( 1.5f, -1.0f, 0.0f); 
			
			glVertex3f( -0.5f, -2.0f, 0.0f);       
			glVertex3f( 0.5f, -2.0f, 0.0f);         
			glVertex3f( 0.0f, -1.0f, 0.0f);

			glVertex3f( -2.0f, -2.0f, 0.0f);       
			glVertex3f( -1.0f, -2.0f, 0.0f);         
			glVertex3f( -1.5f, -1.0f, 0.0f); 
			break;
		case 27:
			glVertex3f( 0.0f, 0.75f, 0.0f); 
			glVertex3f(-0.75f,-0.75f, 0.0f); 
			glVertex3f( 0.75f,-0.75f, 0.0f); 
	
			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.5f, 1.0f, 0.0f); 

			glVertex3f( -0.5f, 2.0f, 0.0f);   
			glVertex3f( 0.5f, 2.0f, 0.0f);       
			glVertex3f( 0.0f, 1.0f, 0.0f); 

			glVertex3f( 2.0f, 2.0f, 0.0f);           
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.5f, 1.0f, 0.0f); 
	
			glVertex3f( 2.0f, 0.5f, 0.0f);          
			glVertex3f( 2.0f, -0.5f, 0.0f);       
			glVertex3f( 1.0f, 0.0f, 0.0f); 

			glVertex3f( 2.0f, -2.0f, 0.0f); 
			glVertex3f( 1.0f, -2.0f, 0.0f); 
			glVertex3f( 1.5f, -1.0f, 0.0f); 

			glVertex3f( -0.5f, -2.0f, 0.0f);       
			glVertex3f( 0.5f, -2.0f, 0.0f);         
			glVertex3f( 0.0f, -1.0f, 0.0f);

			glVertex3f( -2.0f, -2.0f, 0.0f);       
			glVertex3f( -1.0f, -2.0f, 0.0f);         
			glVertex3f( -1.5f, -1.0f, 0.0f); 

			glVertex3f( -2.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.0f, 0.0f); 
			break;

	}
	   glEnd();  
   }
		System::Void Trojkaty2(int p)
   {
	   glBegin(GL_TRIANGLE_STRIP);
		switch (p)
	{
		case 3:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 
			break;
		case 4:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);		
			break;
		case 5:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 0.0f, 0.0f); 		
			break;
		case 6:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 0.0f, 0.0f); 

			glVertex3f( 0.5f, 0.0f, 0.0f); 		
			break;
		case 7:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 0.0f, 0.0f); 

			glVertex3f( 0.5f, 0.0f, 0.0f); 
			
			glVertex3f( 0.0f, -1.0f, 0.0f); 		
			break;
		case 8:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 0.0f, 0.0f); 

			glVertex3f( 0.5f, 0.0f, 0.0f); 
			
			glVertex3f( 0.0f, -1.0f, 0.0f); 

			glVertex3f( 1.0f, -1.0f, 0.0f);		
			break;
		case 9:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 0.0f, 0.0f); 

			glVertex3f( 0.5f, 0.0f, 0.0f); 
			
			glVertex3f( 0.0f, -1.0f, 0.0f); 

			glVertex3f( 1.0f, -1.0f, 0.0f);
			
			glVertex3f( 0.5f, -2.0f, 0.0f);
			break;
		case 10:
			glVertex3f( -1.5f, 2.0f, 0.0f);      
			glVertex3f( -0.5f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 0.0f, 0.0f); 

			glVertex3f( 0.5f, 0.0f, 0.0f); 
			
			glVertex3f( 0.0f, -1.0f, 0.0f); 

			glVertex3f( 1.0f, -1.0f, 0.0f);
			
			glVertex3f( 0.5f, -2.0f, 0.0f);
			
			glVertex3f( 1.5f, -2.0f, 0.0f);			
			break;
	}
	   glEnd();  
   }
		System::Void Trojkaty3(int p)
   {
	   glBegin(GL_TRIANGLE_FAN);
		switch (p)
	{
		case 3:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			break;
		case 4:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			break;
		case 5:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);	
			break;
		case 6:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);
			break;
		case 7:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);
			break;
		case 8:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);

			glVertex3f( 0.0f, -2.0f, 0.0f);
			break;
		case 9:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);

			glVertex3f( 0.0f, -2.0f, 0.0f);

			glVertex3f( -1.0f, -1.75f, 0.0f);
			break;
		case 10:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);

			glVertex3f( 0.0f, -2.0f, 0.0f);

			glVertex3f( -1.0f, -1.75f, 0.0f);

			glVertex3f( -1.75f, -1.0f, 0.0f);
			break;
		case 11:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);

			glVertex3f( 0.0f, -2.0f, 0.0f);

			glVertex3f( -1.0f, -1.75f, 0.0f);

			glVertex3f( -1.75f, -1.0f, 0.0f);

			glVertex3f( -2.0f, 0.0f, 0.0f);
			break;
		case 12:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);

			glVertex3f( 0.0f, -2.0f, 0.0f);

			glVertex3f( -1.0f, -1.75f, 0.0f);

			glVertex3f( -1.75f, -1.0f, 0.0f);

			glVertex3f( -2.0f, 0.0f, 0.0f);
			
			glVertex3f( -1.75f, 1.0f, 0.0f);
			break;
		case 13:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);

			glVertex3f( 0.0f, -2.0f, 0.0f);

			glVertex3f( -1.0f, -1.75f, 0.0f);

			glVertex3f( -1.75f, -1.0f, 0.0f);

			glVertex3f( -2.0f, 0.0f, 0.0f);
			
			glVertex3f( -1.75f, 1.0f, 0.0f);
			
			glVertex3f( -1.0f, 1.75f, 0.0f); 
			break;
		case 14:
			glVertex3f( 0.0f, 0.0f, 0.0f);      
			glVertex3f( 0.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.75f, 0.0f); 
			
			glVertex3f( 1.75f, 1.0f, 0.0f);
			
			glVertex3f( 2.0f, 0.0f, 0.0f);

			glVertex3f( 1.75f, -1.0f, 0.0f);

			glVertex3f( 1.0f, -1.75f, 0.0f);

			glVertex3f( 0.0f, -2.0f, 0.0f);

			glVertex3f( -1.0f, -1.75f, 0.0f);

			glVertex3f( -1.75f, -1.0f, 0.0f);

			glVertex3f( -2.0f, 0.0f, 0.0f);
			
			glVertex3f( -1.75f, 1.0f, 0.0f);
			
			glVertex3f( -1.0f, 1.75f, 0.0f); 

			glVertex3f( 0.0f, 2.0f, 0.0f);		
			break;
	}
	   glEnd();  
   }
		System::Void Czworokaty(int p)
   {
	   glBegin(GL_QUADS);
		switch(p)
	{
		case 4:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);
			break;
		case 8:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);
			break;
		case 12:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 2.0f, 0.0f);      
			glVertex3f( 0.5f, 2.0f, 0.0f);     
			glVertex3f( 0.5f, 1.0f, 0.0f);
			glVertex3f( -0.5f, 1.0f, 0.0f);
			break;
		case 16:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 2.0f, 0.0f);      
			glVertex3f( 0.5f, 2.0f, 0.0f);     
			glVertex3f( 0.5f, 1.0f, 0.0f);
			glVertex3f( -0.5f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 2.0f, 0.0f);      
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.0f, 0.0f);
			glVertex3f( 2.0f, 1.0f, 0.0f);
			break;
		case 20:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 2.0f, 0.0f);      
			glVertex3f( 0.5f, 2.0f, 0.0f);     
			glVertex3f( 0.5f, 1.0f, 0.0f);
			glVertex3f( -0.5f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 2.0f, 0.0f);      
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.0f, 0.0f);
			glVertex3f( 2.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);      
			glVertex3f( 1.0f, 0.5f, 0.0f);     
			glVertex3f( 1.0f, -0.5f, 0.0f);
			glVertex3f( 2.0f, -0.5f, 0.0f);
			break;
		case 24:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 2.0f, 0.0f);      
			glVertex3f( 0.5f, 2.0f, 0.0f);     
			glVertex3f( 0.5f, 1.0f, 0.0f);
			glVertex3f( -0.5f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 2.0f, 0.0f);      
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.0f, 0.0f);
			glVertex3f( 2.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);      
			glVertex3f( 1.0f, 0.5f, 0.0f);     
			glVertex3f( 1.0f, -0.5f, 0.0f);
			glVertex3f( 2.0f, -0.5f, 0.0f);

			glVertex3f( 2.0f, -1.0f, 0.0f);      
			glVertex3f( 1.0f, -1.0f, 0.0f);     
			glVertex3f( 1.0f, -2.0f, 0.0f);
			glVertex3f( 2.0f, -2.0f, 0.0f);
			break;
		case 28:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 2.0f, 0.0f);      
			glVertex3f( 0.5f, 2.0f, 0.0f);     
			glVertex3f( 0.5f, 1.0f, 0.0f);
			glVertex3f( -0.5f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 2.0f, 0.0f);      
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.0f, 0.0f);
			glVertex3f( 2.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);      
			glVertex3f( 1.0f, 0.5f, 0.0f);     
			glVertex3f( 1.0f, -0.5f, 0.0f);
			glVertex3f( 2.0f, -0.5f, 0.0f);

			glVertex3f( 2.0f, -1.0f, 0.0f);      
			glVertex3f( 1.0f, -1.0f, 0.0f);     
			glVertex3f( 1.0f, -2.0f, 0.0f);
			glVertex3f( 2.0f, -2.0f, 0.0f);

			glVertex3f( -0.5f, -2.0f, 0.0f);      
			glVertex3f( 0.5f, -2.0f, 0.0f);     
			glVertex3f( 0.5f, -1.0f, 0.0f);
			glVertex3f( -0.5f, -1.0f, 0.0f);
			break;
		case 32:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 2.0f, 0.0f);      
			glVertex3f( 0.5f, 2.0f, 0.0f);     
			glVertex3f( 0.5f, 1.0f, 0.0f);
			glVertex3f( -0.5f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 2.0f, 0.0f);      
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.0f, 0.0f);
			glVertex3f( 2.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);      
			glVertex3f( 1.0f, 0.5f, 0.0f);     
			glVertex3f( 1.0f, -0.5f, 0.0f);
			glVertex3f( 2.0f, -0.5f, 0.0f);

			glVertex3f( 2.0f, -1.0f, 0.0f);      
			glVertex3f( 1.0f, -1.0f, 0.0f);     
			glVertex3f( 1.0f, -2.0f, 0.0f);
			glVertex3f( 2.0f, -2.0f, 0.0f);

			glVertex3f( -0.5f, -2.0f, 0.0f);      
			glVertex3f( 0.5f, -2.0f, 0.0f);     
			glVertex3f( 0.5f, -1.0f, 0.0f);
			glVertex3f( -0.5f, -1.0f, 0.0f);

			glVertex3f( -2.0f, -2.0f, 0.0f);      
			glVertex3f( -1.0f, -2.0f, 0.0f);     
			glVertex3f( -1.0f, -1.0f, 0.0f);
			glVertex3f( -2.0f, -1.0f, 0.0f);
			break;
		case 36:
			glVertex3f( -0.5f, 0.5f, 0.0f);      
			glVertex3f( 0.5f, 0.5f, 0.0f);     
			glVertex3f( 0.5f, -0.5f, 0.0f);
			glVertex3f( -0.5f, -0.5f, 0.0f);

			glVertex3f( -2.0f, 2.0f, 0.0f);      
			glVertex3f( -1.0f, 2.0f, 0.0f);     
			glVertex3f( -1.0f, 1.0f, 0.0f);
			glVertex3f( -2.0f, 1.0f, 0.0f);

			glVertex3f( -0.5f, 2.0f, 0.0f);      
			glVertex3f( 0.5f, 2.0f, 0.0f);     
			glVertex3f( 0.5f, 1.0f, 0.0f);
			glVertex3f( -0.5f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 2.0f, 0.0f);      
			glVertex3f( 1.0f, 2.0f, 0.0f);     
			glVertex3f( 1.0f, 1.0f, 0.0f);
			glVertex3f( 2.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);      
			glVertex3f( 1.0f, 0.5f, 0.0f);     
			glVertex3f( 1.0f, -0.5f, 0.0f);
			glVertex3f( 2.0f, -0.5f, 0.0f);

			glVertex3f( 2.0f, -1.0f, 0.0f);      
			glVertex3f( 1.0f, -1.0f, 0.0f);     
			glVertex3f( 1.0f, -2.0f, 0.0f);
			glVertex3f( 2.0f, -2.0f, 0.0f);

			glVertex3f( -0.5f, -2.0f, 0.0f);      
			glVertex3f( 0.5f, -2.0f, 0.0f);     
			glVertex3f( 0.5f, -1.0f, 0.0f);
			glVertex3f( -0.5f, -1.0f, 0.0f);

			glVertex3f( -2.0f, -2.0f, 0.0f);      
			glVertex3f( -1.0f, -2.0f, 0.0f);     
			glVertex3f( -1.0f, -1.0f, 0.0f);
			glVertex3f( -2.0f, -1.0f, 0.0f);

			glVertex3f( -2.0f, 0.5f, 0.0f);      
			glVertex3f( -1.0f, 0.5f, 0.0f);     
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);
			break;
	}
	   glEnd();
   }
		System::Void Czworokaty2(int p)
  {
		glBegin(GL_QUAD_STRIP);
		switch(p)
	{
		case 4:
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			glVertex3f( -2.0f, 0.5f, 0.0f);
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);     	
			break;
		case 6:
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			glVertex3f( -2.0f, 0.5f, 0.0f);
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);     	

			glVertex3f( 0.0f, -0.5f, 0.0f);      
			glVertex3f( 0.0f, 0.5f, 0.0f);  
			break;
		case 8:
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			glVertex3f( -2.0f, 0.5f, 0.0f);
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);     	

			glVertex3f( 0.0f, -0.5f, 0.0f);      
			glVertex3f( 0.0f, 0.5f, 0.0f);     

			glVertex3f( 1.0f, -0.5f, 0.0f);
			glVertex3f( 1.0f, 0.5f, 0.0f);
			break;
		case 10:
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			glVertex3f( -2.0f, 0.5f, 0.0f);
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);     	

			glVertex3f( 0.0f, -0.5f, 0.0f);      
			glVertex3f( 0.0f, 0.5f, 0.0f);     

			glVertex3f( 1.0f, -0.5f, 0.0f);
			glVertex3f( 1.0f, 0.5f, 0.0f);

			glVertex3f( 2.0f, -0.5f, 0.0f);
			glVertex3f( 2.0f, 0.5f, 0.0f);
			break;
	}
		glEnd();
  }
		System::Void Poligony(int p)
  {
		glBegin(GL_POLYGON);
		switch(p)
	{
		case 3:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);     	
			break;
		case 4:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			
			glVertex3f( 0.0f, -2.0f, 0.0f);   	
			break;
		case 5:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			
			glVertex3f( 0.0f, -2.0f, 0.0f);  

			glVertex3f( 1.5f, -1.0f, 0.0f);    	
			break;
		case 6:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			
			glVertex3f( 0.0f, -2.0f, 0.0f);  

			glVertex3f( 1.5f, -1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);   	
			break;
		case 7:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			
			glVertex3f( 0.0f, -2.0f, 0.0f);  

			glVertex3f( 1.5f, -1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);   	
			break;
		case 8:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			
			glVertex3f( 0.0f, -2.0f, 0.0f);  

			glVertex3f( 1.5f, -1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);
			
			glVertex3f( 1.5f, 1.5f, 0.0f);   	
			break;
		case 9:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			
			glVertex3f( 0.0f, -2.0f, 0.0f);  

			glVertex3f( 1.5f, -1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);
			
			glVertex3f( 1.5f, 1.5f, 0.0f);
			
			glVertex3f( 0.5f, 2.0f, 0.0f);   	
			break;
		case 10:
			glVertex3f( -1.0f, -0.5f, 0.0f);
			glVertex3f( -1.0f, 0.5f, 0.0f);
			glVertex3f( -2.0f, -0.5f, 0.0f);      
			
			glVertex3f( 0.0f, -2.0f, 0.0f);  

			glVertex3f( 1.5f, -1.0f, 0.0f); 

			glVertex3f( 0.0f, 1.0f, 0.0f);

			glVertex3f( 2.0f, 0.5f, 0.0f);
			
			glVertex3f( 1.5f, 1.5f, 0.0f);
			
			glVertex3f( 0.5f, 2.0f, 0.0f);
			
			glVertex3f( -2.0f, 2.0f, 0.0f);   	
			break;
	}
		glEnd();
  }	
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

	System::Void Render(int c, int p, float w, int r)
			{

 				wglMakeCurrent(m_hDC, m_hRC);

				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glLoadIdentity();
				glTranslatef(0.0f,0.0f,-6.0f);
			
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

				
				switch(c)
				{
				case 1:
					Punkty(p,w);
					break;
				case 2:
					Linie(p);
					break;
				case 3:
					Linie2(p);
					break;
				case 4:
					Linie3(p);
					break;
				case 5:
					Trojkaty(p);
					break;
				case 6:
					Trojkaty2(p);
					break;
				case 7:
					Trojkaty3(p);
					break;
				case 8:
					Czworokaty(p);
					break;
				case 9:
					Czworokaty2(p);
					break;
				case 10:
					Poligony(p);
					break;
				}

				rtri+=0.2f;
			
				
				glFlush();
				SwapBuffers( m_hDC );

		
			}
		System::Void tresc(int c, int p, float w, int r){
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
			switch(c)
			{
			case 1:
				Codeview->Text = Codeview->Text + "glPointSize(" + w + ");\r\n   glBegin(GL_POINTS);\r\n";
				switch(p) 
				{
					case 1:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n";

						break;
					case 2:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n";

						break;
					case 3:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n";

						break;
					case 4:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n";

						break;
					case 5:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n";

						break;
					case 6:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n";		

						break;
					case 7:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n";

						break;
					case 8:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n";

						break;
					case 9:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n";

						break;
					case 10:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n"; 
						break;
					case 11:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n";

						break;
					case 12:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n";

						break;
					case 13:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n";

						break;
					case 14:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n";

						break;
					case 15:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n";

						break;
					case 16:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n";

						break;
					case 17:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -1.75f, 1.75f);\r\n";

						break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			case 2:
				Codeview->Text = Codeview->Text + "   glBegin(GL_LINES);\r\n";
				switch (p)
				{
					case 2:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n";		
						break;
					case 4:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n";		
						break;
					case 6:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n";		
						break;
					case 8:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n";		
						break;
					case 10:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n";				
						break;
					case 12:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n";		
						break;	
					case 14:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n";			
						break;
					case 16:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n";
						break;
					case 18:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n";		
						break;
					case 20:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n";		
						break;
					case 22:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n";			
						break;
					case 24:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n";	
						break;
					case 26:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n";
						break;
					case 28:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n";
						break;
					case 30:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -2.0f, -2.0f);\r\n\tglVertex2f( -2.0f, 2.0f);\r\n";			
						break;
					case 32:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -2.0f, -2.0f);\r\n\tglVertex2f( -2.0f, 2.0f);\r\n\tglVertex2f( -2.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 2.0f);\r\n";			
						break;
					case 34:
						Codeview->Text = Codeview->Text + "\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, 1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( 1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, -1.0f);\r\n\tglVertex2f( -1.0f, 1.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -2.0f, -2.0f);\r\n\tglVertex2f( -2.0f, 2.0f);\r\n\tglVertex2f( -2.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 2.0f);\r\n\tglVertex2f( 2.0f, 2.0f);\r\n\tglVertex2f( 2.0f, -2.0f);\r\n";
						break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			case 3:
				Codeview->Text = Codeview->Text + "   glBegin(GL_LINE_STRIP);\r\n";
				switch(p) 
				{
					case 2:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n";

						break;
					case 3:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n";

						break;
					case 4:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n";

						break;
					case 5:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n";
	
						break;
					case 6:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n";

						break;
					case 7:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n";

						break;
					case 8:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n";

						break;
					case 9:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n";
						break;
					case 10:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n";
						break;
					case 11:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n";

						break;
					case 12:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n";

						break;
					case 13:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n";

						break;
					case 14:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n";

						break;
					case 15:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n";

						break;
					case 16:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n";

						break;
					case 17:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -1.75f, 1.75f);\r\n";
						break;
					case 18:
						Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -1.75f, 1.75f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n";
						break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			case 4:
				Codeview->Text = Codeview->Text + "   glBegin(GL_LINE_LOOP);\r\n";
				switch(p) 
				{
				case 2:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n";

					break;
				case 3:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n";

					break;
				case 4:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n";

					break;
				case 5:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n";

					break;
				case 6:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n";
	
					break;
				case 7:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n";

					break;
				case 8:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n";

					break;
				case 9:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n";

					break;
				case 10:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n";

					break;
				case 11:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n";

					break;
				case 12:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n";

					break;
				case 13:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n";

					break;
				case 14:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n";

					break;
				case 15:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n";

					break;
				case 16:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n";

					break;
				case 17:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -1.75f, 1.75f);\r\n";

					break;
				case 18:
					Codeview->Text = Codeview->Text + "\tglVertex2f( 0.0f, 0.0f);\r\n\tglVertex2f( 0.0f, 1.0f);\r\n\tglVertex2f( 0.75f, 0.75f);\r\n\tglVertex2f( 1.0f, 0.0f);\r\n\tglVertex2f( 0.75f, -0.75f);\r\n\tglVertex2f( 0.0f, -1.0f);\r\n\tglVertex2f( -0.75f, -0.75f);\r\n\tglVertex2f( -1.0f, 0.0f);\r\n\tglVertex2f( -0.75f, 0.75f);\r\n	\r\n\tglVertex2f( 0.0f, 2.0f);\r\n\tglVertex2f( 1.75f, 1.75f);\r\n\tglVertex2f( 2.0f, 0.0f);\r\n\tglVertex2f( 1.75f, -1.75f);\r\n\tglVertex2f( 0.0f, -2.0f);\r\n\tglVertex2f( -1.75f, -1.75f);\r\n\tglVertex2f( -2.0f, 0.0f);\r\n\tglVertex2f( -1.75f, 1.75f);\r\n\tglVertex2f( 0.0f, 2.0f);\r\n";
					break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			case 5:
				Codeview->Text = Codeview->Text + "   glBegin(GL_TRIANGLES);\r\n";
				switch (p)
			{
				case 3:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n";

					break;
				case 6:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n";

					break;
				case 9:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n";

					break;
				case 12:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, 1.0f, 0.0f);\r\n";

					break;
				case 15:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.0f, 0.0f);\r\n;";

					break;
				case 18:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n";

					break;
				case 21:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, -1.0f, 0.0f);\r\n";

					break;
				case 24:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, -1.0f, 0.0f);\r\n";

					break;
				case 27:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.0f, 0.0f);\r\n";
					break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n"; 
				break;
			case 6:
				Codeview->Text = Codeview->Text + "   glBegin(GL_TRIANGLE_STRIP);\r\n";
				switch (p)
				{
				case 3:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n";			
 
					break;
				case 4:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n";			
	
					break;
				case 5:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 0.0f, 0.0f);\r\n";			
	
					break;
				case 6:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, 0.0f, 0.0f);\r\n";			
	
					break;
				case 7:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -1.0f, 0.0f);\r\n";			
		
					break;
				case 8:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.0f, 0.0f);\r\n";			
	
					break;
				case 9:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n";			

					break;
				case 10:
					Codeview->Text = Codeview->Text + "\tglVertex3f( -1.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, -2.0f, 0.0f);\r\n";			
					break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			case 7:
				Codeview->Text = Codeview->Text + "   glBegin(GL_TRIANGLE_FAN);\r\n";
				switch (p)
				{
				case 3:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n";

					break;
				case 4:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n";

					break;
				case 5:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n";

					break;
				case 6:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n";

					break;
				case 7:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n";

					break;
				case 8:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n";

					break;
				case 9:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, -1.75f, 0.0f);\r\n";

					break;
				case 10:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, -1.0f, 0.0f);\r\n";

					break;
				case 11:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 0.0f, 0.0f);\r\n";

					break;
				case 12:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, 1.0f, 0.0f);\r\n";

					break;
				case 13:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, 1.75f, 0.0f);\r\n";
 
					break;
				case 14:
					Codeview->Text = Codeview->Text + "\tglVertex3f( 0.0f, 0.0f, 0.0f);\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, -1.75f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 0.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.75f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -1.0f, 1.75f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 2.0f, 0.0f);\r\n";
					break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";  
				break;
			case 8:
				Codeview->Text = Codeview->Text + "   glBegin(GL_QUADS);\r\n";
				switch(p)
				{
					case 4:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n";
						break;
					case 8:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n";
						break;
					case 12:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 1.0f, 0.0f);\r\n";
						break;
					case 16:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 2.0f, 1.0f, 0.0f);\r\n";
						break;
					case 20:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n";
						break;
					case 24:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n";
						break;
					case 28:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, -1.0f, 0.0f);\r\n";
						break;
					case 32:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, -1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, -1.0f, 0.0f);\r\n";
						break;
					case 36:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, 0.5f, 0.0f);\r\n\tglVertex3f( 0.5f, -0.5f, 0.0f);\r\n\tglVertex3f( -0.5f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, 1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 2.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 2.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( 2.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( -0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -2.0f, 0.0f);\r\n\tglVertex3f( 0.5f, -1.0f, 0.0f);\r\n\tglVertex3f( -0.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, -2.0f, 0.0f);\r\n\tglVertex3f( -1.0f, -1.0f, 0.0f);\r\n\tglVertex3f( -2.0f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n";
						break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			case 9:
				Codeview->Text = Codeview->Text + "   glBegin(GL_QUAD_STRIP);\r\n";
				switch(p)
				{
					case 4:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n";
  	
						break;
					case 6:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 0.0f, 0.5f, 0.0f);\r\n";

						break;
					case 8:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 0.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.5f, 0.0f);\r\n";

						break;
					case 10:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 0.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 1.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, -0.5f, 0.0f);\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n";
						break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			case 10:
				Codeview->Text = Codeview->Text + "   glBegin(GL_POLYGON);\r\n";
				switch(p)
				{
					case 3:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n";
   	
						break;
					case 4:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n";
 	
						break;
					case 5:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n";
  	
						break;
					case 6:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n";

						break;
					case 7:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n";
	
						break;
					case 8:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, 1.5f, 0.0f);\r\n";
  	
						break;
					case 9:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, 1.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n";
   	
						break;
					case 10:
						Codeview->Text = Codeview->Text + "\tglVertex3f( -1.0f, -0.5f, 0.0f);\r\n\tglVertex3f( -1.0f, 0.5f, 0.0f);\r\n\tglVertex3f( -2.0f, -0.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, -2.0f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, -1.0f, 0.0f);\r\n\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\r\n\tglVertex3f( 2.0f, 0.5f, 0.0f);\r\n\r\n\tglVertex3f( 1.5f, 1.5f, 0.0f);\r\n\r\n\tglVertex3f( 0.5f, 2.0f, 0.0f);\r\n\r\n\tglVertex3f( -2.0f, 2.0f, 0.0f);\r\n";
						break;
				}
				Codeview->Text = Codeview->Text + "   glEnd();\r\n";
				break;
			}

			if (r>0 && r<8){
				Codeview->Text = Codeview->Text + "\t\r\nrtri+=0.2f;";
			};
	}
	private: System::Void My1okno_Load(System::Object^  sender, System::EventArgs^  e) {
				a = 1;
				liczba1->Minimum = 1;
				liczba1->Maximum = 17;
				liczba1->Increment = 1;
				liczba2->Enabled = true;
				liczba1->Value = 1;	
			 }
	private: System::Void My1okno_Closing(System::Object^  sender, System::EventArgs^  e) {
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
				 
				int b = (int)liczba1->Value;
				float c = (float)liczba2->Value;				
				
				Render(a, b, c, rotacja);
				if (a!=a2 || b!=b2 || c!=c2 || rotacja != rotacja2){
				tresc(a, b, c, rotacja);
				a2=a;
				b2=b;
				c2=c;
				rotacja2=rotacja;
				}
				wiersze->Value = Codeview->Lines->Length;
				znaki->Value = Codeview->Text->Length;
				float dd = FPS();
				fps2->Value =(System::Decimal)dd;
			 }
private: System::Void points_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 1;
			liczba1->Minimum = 1;
			liczba1->Maximum = 17;
			liczba1->Increment = 1;
			liczba2->Enabled = true;
			liczba1->Value = 1;	
		 }
private: System::Void lines_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 2;
			liczba1->Minimum = 2;
			liczba1->Maximum = 34;
			liczba1->Increment = 2;
			liczba2->Enabled = false;
			liczba1->Value = 2;
		 }
private: System::Void liness_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 3;
			liczba1->Minimum = 2;
			liczba1->Maximum = 18;
			liczba1->Increment = 1;
			liczba2->Enabled = false;
			liczba1->Value = 2;
		 }
private: System::Void linel_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 4;
			liczba1->Minimum = 2;
			liczba1->Maximum = 18;
			liczba1->Increment = 1;
			liczba2->Enabled = false;
			liczba1->Value = 2;
		 }
private: System::Void triangles_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 5;
			liczba1->Minimum = 3;
			liczba1->Maximum = 27;
			liczba1->Increment = 3;
			liczba2->Enabled = false;
			liczba1->Value = 3;
		 }
private: System::Void triangless_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 6;
			liczba1->Minimum = 3;
			liczba1->Maximum = 10;
			liczba1->Increment = 1;
			liczba2->Enabled = false;
			liczba1->Value = 3;
		 }
private: System::Void trianglesf_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 7;
			liczba1->Minimum = 3;
			liczba1->Maximum = 14;
			liczba1->Increment = 1;
			liczba2->Enabled = false;
			liczba1->Value = 3;
		 }
private: System::Void quads_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 8;
			liczba1->Minimum = 4;
			liczba1->Maximum = 36;
			liczba1->Increment = 4;
			liczba2->Enabled = false;
			liczba1->Value = 4;
		 }
private: System::Void quadss_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 9;
			liczba1->Minimum = 4;
			liczba1->Maximum = 10;
			liczba1->Increment = 2;
			liczba2->Enabled = false;
			liczba1->Value = 4;
		 }
private: System::Void polygon_Click(System::Object^  sender, System::EventArgs^  e) {
			a = 10;
			liczba1->Minimum = 3;
			liczba1->Maximum = 10;
			liczba1->Increment = 1;
			liczba2->Enabled = false;
			liczba1->Value = 3;
		 }
	
private: System::Void My1okno_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			  Application::Restart();
		 }
private: System::Void OpenGLPanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}
