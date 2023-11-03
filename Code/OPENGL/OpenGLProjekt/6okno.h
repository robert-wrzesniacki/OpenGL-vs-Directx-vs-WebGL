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
#include <SOIL.h>
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
	/// Summary for My6okno
	/// </summary>
	public ref class My6okno : public System::Windows::Forms::Form
	{
	public:
		My6okno(void)
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
			piover180 = 0.017;
			MoveSpeed = 0.03;
			Heading = 90;										
			X = -2.5;												//Pozycja startowa gracza
			Z = -0.5;
			g = 0.2;
			rtri = 0.0f;
			timer1->Interval = 10;
			timer1->Enabled = true;
			s = gcnew array<int, 2>{
									{0,9,0,0},
									{1,6,1,1},
									{0,1,2,2},
									{2,7,2,2},
									{2,8,3,3},
									{1,7,4,4},
									{1,2,5,5},
									{3,7,5,5},
									{3,8,6,6},
									{0,2,7,7},
									{3,9,7,7},
									{1,4,9,9},

									{0,0,0,7},
									{1,1,1,4},
									{1,1,5,6},
									{1,1,7,9},
									{2,2,5,7},
									{3,3,6,7},
									{4,4,7,9},
									{7,7,0,2},
									{7,7,4,5},
									{8,8,1,6},
									{9,9,0,7},
									{-1 , -1, -1, -1}
									};
			kw = false; 
			ks = false; 
			ka = false; 
			kd = false;
			kl = false;
			kp = false;

		}
		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
		
			LoadGLTextures();
		//glEnable(GL_TEXTURE_2D);							// Tekstury dwówymiarowe on
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Ustawienia Blendingu
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Kolor t³a
			glClearDepth(1.0);									// Czyœci bufor g³êbi
			glFlush();
			glDepthFunc(GL_LESS);								// test g³êbi
			glShadeModel(GL_SMOOTH);							// wyg³adzenie on
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// perspektywa
			   GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 0.5 };
			   GLfloat mat_shininess[] = { 10.0 };
			   GLfloat light_ambient[] = { 0.45, 0.45, 0.45, 1.0 };
			   GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
			   GLfloat light_position[] = {  0.0, 0.0, 2.0, 1.0 };

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
		int LoadGLTextures(){
			Tekstura1 = SOIL_load_OGL_texture
				(
				"Data/sciany.jpg",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);
			Tekstura2 = SOIL_load_OGL_texture
				(
				"Data/sufit.jpg",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);
			Tekstura3 = SOIL_load_OGL_texture
				(
				"Data/podloga.jpg",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

			if(Tekstura1 == 0 || Tekstura2 == 0 || Tekstura3 == 0)
			{
				MessageBox::Show("Nie uda³o siê za³adowaæ wszystkich tekstur T_T");;
			}

			// Typical Texture Generation Using Data From The Bitmap
			//glBindTexture(GL_TEXTURE_2D, texture1);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

			return true;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~My6okno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  OpenGLPanel;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

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

		GLuint Tekstura1;
		GLuint Tekstura2;
		GLuint Tekstura3;

		float piover180;
		GLfloat X, Z;
		GLfloat HeadMovement, HeadMovAngle;
		GLfloat Heading;
		GLfloat MoveSpeed;
		bool kw, ks, ka, kd, kl, kp;
		float g;

		int s2, b2;
		int kolizje2;
		GLfloat X2, Z2;
		GLfloat HeadMovement2;
		GLfloat Heading2;
		array<int, 2> ^s;
       
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::NumericUpDown^  fps2;
private: System::Windows::Forms::NumericUpDown^  znaki;
private: System::Windows::Forms::NumericUpDown^  wiersze;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::GroupBox^  Sterowanie;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::RadioButton^  radioButton2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::RadioButton^  radioButton4;
private: System::Windows::Forms::RadioButton^  radioButton3;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::RadioButton^  radioButton5;
private: System::Windows::Forms::RadioButton^  radioButton6;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label7;

private: System::Windows::Forms::TextBox^  Codeview;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->OpenGLPanel = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fps2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->znaki = (gcnew System::Windows::Forms::NumericUpDown());
			this->wiersze = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Sterowanie = (gcnew System::Windows::Forms::GroupBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Codeview = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->BeginInit();
			this->Sterowanie->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// OpenGLPanel
			// 
			this->OpenGLPanel->Location = System::Drawing::Point(10, 10);
			this->OpenGLPanel->Name = L"OpenGLPanel";
			this->OpenGLPanel->Size = System::Drawing::Size(500, 500);
			this->OpenGLPanel->TabIndex = 2;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &My6okno::timer1_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->fps2);
			this->groupBox1->Controls->Add(this->znaki);
			this->groupBox1->Controls->Add(this->wiersze);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(769, 406);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(201, 104);
			this->groupBox1->TabIndex = 53;
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
			this->label6->Location = System::Drawing::Point(20, 47);
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
			this->fps2->Location = System::Drawing::Point(102, 72);
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
			this->znaki->Location = System::Drawing::Point(102, 47);
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
			this->label4->Location = System::Drawing::Point(20, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"FPS:";
			// 
			// Sterowanie
			// 
			this->Sterowanie->Controls->Add(this->panel3);
			this->Sterowanie->Controls->Add(this->panel2);
			this->Sterowanie->Controls->Add(this->panel1);
			this->Sterowanie->Location = System::Drawing::Point(520, 406);
			this->Sterowanie->Name = L"Sterowanie";
			this->Sterowanie->Size = System::Drawing::Size(243, 104);
			this->Sterowanie->TabIndex = 54;
			this->Sterowanie->TabStop = false;
			this->Sterowanie->Text = L"Sterowanie";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->radioButton3);
			this->panel3->Controls->Add(this->radioButton4);
			this->panel3->Location = System::Drawing::Point(149, 21);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(88, 70);
			this->panel3->TabIndex = 55;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 42;
			this->label2->Text = L"Przezroczystoœæ:";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(24, 25);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(41, 17);
			this->radioButton3->TabIndex = 43;
			this->radioButton3->Text = L"ON";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->Location = System::Drawing::Point(24, 50);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(45, 17);
			this->radioButton4->TabIndex = 44;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"OFF";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->radioButton5);
			this->panel2->Controls->Add(this->radioButton6);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(4, 21);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(65, 70);
			this->panel2->TabIndex = 54;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Checked = true;
			this->radioButton5->Location = System::Drawing::Point(15, 25);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(41, 17);
			this->radioButton5->TabIndex = 40;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"ON";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &My6okno::radioButton5_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(15, 50);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(45, 17);
			this->radioButton6->TabIndex = 41;
			this->radioButton6->Text = L"OFF";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 4);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 39;
			this->label3->Text = L"Kolizje:";
			this->label3->Click += gcnew System::EventHandler(this, &My6okno::label3_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(77, 21);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(65, 70);
			this->panel1->TabIndex = 53;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(12, 25);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(41, 17);
			this->radioButton1->TabIndex = 40;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ON";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(12, 50);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(45, 17);
			this->radioButton2->TabIndex = 41;
			this->radioButton2->Text = L"OFF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Œwiat³o:";
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
			this->Codeview->Size = System::Drawing::Size(450, 390);
			this->Codeview->TabIndex = 52;
			this->Codeview->WordWrap = false;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->ForeColor = System::Drawing::Color::Black;
			this->groupBox2->Location = System::Drawing::Point(10, 516);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(960, 74);
			this->groupBox2->TabIndex = 55;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Poruszanie siê";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &My6okno::groupBox2_Enter);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label12->Location = System::Drawing::Point(701, 29);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(250, 25);
			this->label12->TabIndex = 5;
			this->label12->Text = L"E - obrót przez prawe ramiê";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(461, 29);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(250, 25);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Q - obrót przez lewe ramiê |";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(346, 29);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(125, 25);
			this->label10->TabIndex = 3;
			this->label10->Text = L"S - w prawo |";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(244, 29);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(112, 25);
			this->label9->TabIndex = 2;
			this->label9->Text = L"A - w lewo |";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(144, 29);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(110, 25);
			this->label8->TabIndex = 1;
			this->label8->Text = L"S - do ty³u |";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(8, 29);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(146, 25);
			this->label7->TabIndex = 0;
			this->label7->Text = L"W - do przodu |";
			// 
			// My6okno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Sterowanie);
			this->Controls->Add(this->Codeview);
			this->Controls->Add(this->OpenGLPanel);
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 640);
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->Name = L"My6okno";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"C++ & OpenGL: Kamera i poruszanie siê po scenie 3D";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &My6okno::My6okno_FormClosed);
			this->Load += gcnew System::EventHandler(this, &My6okno::My6okno_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &My6okno::My6okno_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &My6okno::My6okno_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &My6okno::My6okno_KeyUp);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->EndInit();
			this->Sterowanie->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
	int test_kolizji(int koli)
{
		float SX = X;
		float SZ = Z;
		
		if(kw == true){			//W
					X -= double( sin( double( Heading ) * piover180 ) ) * 0.05f;   // FrameTime/600=movement speed
					Z += double( cos( double( Heading ) * piover180 ) ) * 0.05f;   // FrameTime/600=movement speed
					HeadMovAngle = HeadMovAngle + 15;
					HeadMovement = 0.025 * sin( double( HeadMovAngle ) * piover180 );
			}
		if(ks == true){			//S
					X += double( sin( double( Heading ) * piover180 ) ) * 0.05f;
					Z -= double( cos( double( Heading ) * piover180 ) ) * 0.05f;
					HeadMovAngle = HeadMovAngle - 15;
					HeadMovement = 0.025 * sin( double( HeadMovAngle ) * piover180 );
			}
		if(ka == true){				//A
					X += double( sin( double( ( Heading + 90 ) ) * piover180 ) ) * 0.05f;  // FrameTime/900=movement speed
					Z -= double( cos( double( ( Heading + 90 ) ) * piover180 ) ) * 0.05f;  // straffing = 50% slower
			}
		if(kd == true){			//D
					X -= double( sin( double( ( Heading + 90 ) ) * piover180 ) ) * 0.05f;
					Z += double( cos( double( ( Heading + 90 ) ) * piover180 ) ) * 0.05f;
			}
		if(kl == true){
		Heading -= 2.0f;
		}
		if(kp == true){
		Heading += 2.0f;
		}
		if (koli == 1){
		for(int a = 0; s[a, 0] != -1; a++)
		{
			if(s[a,0]!=s[a,1])
			{
				if(X<-s[a,0] && X>-s[a,1])
				{
					if(Z>(-s[a,2] - g) && Z < (-s[a,3] + g))
					{
					X = SX;
					Z = SZ;
					}
				}
			}else{
				if(Z<-s[a,2] && Z>-s[a,3])
				{
					if(X>(-s[a,0] - g) && X < (-s[a,1] + g))
					{
					X = SX;
					Z = SZ;
					}
				}
			}
		}
		}
		return true;
 }
	System::Void stworzenie_swiata()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Tekstura1);
		glBegin(GL_QUADS);
			for (int i = 0; s[i, 0] != -1; i++)
			{

				glColor3f(0.6, 0.6, 0.6);
				glTexCoord2f(0.0f, 0.0f);  glVertex3f(s[i, 0], -0.5, s[i, 2]);
				glTexCoord2f(1.0, 0.0f); glVertex3f(s[i, 1], -0.5, s[i, 3]);
				glColor3f(1.0, 1.0, 1.0);
				glTexCoord2f(1.0, 1.0f); glVertex3f(s[i, 1], 0.5, s[i, 3]);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(s[i, 0], 0.5, s[i, 2]);
			}
		glEnd();
		glBindTexture(GL_TEXTURE_2D, Tekstura2);
		glBegin(GL_QUADS);

			glColor3f(1.0, 1.0, 1.0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0.5, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(9.0, 0.5, 0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(9.0, 0.5, 9.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 9.0);

			glEnd();


			// pod³oga
		glBindTexture(GL_TEXTURE_2D, Tekstura3);
		glBegin(GL_QUADS);

			glColor3f(1.0, 1.0, 1.0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0, -0.5, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(9.0, -0.5, 0);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(9.0, -0.5, 9.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, -0.5, 9.0);

			glEnd();
		glDisable(GL_TEXTURE_2D);

	}
	System::Void Render(int s, int b, int kol)
		{
			wglMakeCurrent(m_hDC, m_hRC);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			test_kolizji(kol);
			//glTranslatef(0.0f,0.0f,-6.0f);
			glRotatef(Heading,0,1.0f,0);
			glTranslatef(X, 0 + HeadMovement , Z);
			if (s==1){
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
			};
			if (b==1)
			{
				glEnable(GL_BLEND);
				glDisable(GL_DEPTH_TEST);
			};			
			stworzenie_swiata();
			
			if (s==1)
			{
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
			};
			if (b==1)
			{
						glDisable(GL_BLEND);
						glEnable(GL_DEPTH_TEST);
			};
			glFlush();
			SwapBuffers( m_hDC );
		}
	System::Void tresc(int s, int b, int kol)
		{
			Codeview->Text = L"glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);\r\nglLoadIdentity();\r\n\r\n";
			if (kol==1){
				Codeview->Text += "test_kolizji();\r\n\r\n";
			}
			Codeview->Text += "glTranslatef("+ X +"f,"+ HeadMovement +"f,"+ Z +"f);\r\n\r\nglRotatef("+ Heading +",0.0f,1.0f,0.0f);\r\n\r\n";
			if (s==1){
				Codeview->Text += "glEnable(GL_LIGHTING)\r\nglEnable(GL_LIGHT0);\r\n\r\n";
			}
			if (b==1){
				Codeview->Text += "glEnable(GL_BLEND);\r\nglDisable(GL_DEPTH_TEST);\r\n\r\n";
			}

			Codeview->Text += "\tstworzenie_swiata();\n\n\r\n";

			if (b==1){
				Codeview->Text += "\r\nglDisable(GL_BLEND);\r\nglEnable(GL_DEPTH_TEST);;\r\n\r\n";
			}
			if (s==1){
				Codeview->Text += "\r\nglDisable(GL_LIGHTING)\r\nglDisable(GL_LIGHT0);\r\n\r\n";
			}

		}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				
				int swiatlo = 0;
				if (radioButton1->Checked){
					 swiatlo =1;
				 }else if (radioButton2->Checked){
					swiatlo =2;
				 }
				int blend = 0;
				if (radioButton3->Checked){
					 blend =1;
				 }else if (radioButton4->Checked){
					blend =2;
				 }
				int kolizje = 0;
				if (radioButton5->Checked){
					 kolizje =1;
				 }else if (radioButton6->Checked){
					kolizje =2;
				 }
				Render(swiatlo, blend, kolizje);
				if( swiatlo != s2 || blend != b2 || X != X2 || Z != Z2 || HeadMovement != HeadMovement2 || Heading != Heading2 || kolizje != kolizje2){
				tresc(swiatlo, blend, kolizje);
				s2 = swiatlo;
				b2 = blend;
				X2 = X;
				Z2 = Z;
				kolizje2=kolizje;
				HeadMovement2 = HeadMovement;
				Heading2 = Heading;
				}
				wiersze->Value = Codeview->Lines->Length;
				znaki->Value = Codeview->Text->Length;
			 	float dd = FPS();
				fps2->Value =(System::Decimal)dd;
			 }
private: System::Void My6okno_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void My6okno_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Application::Restart();
		 }
private: System::Void My6okno_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			
		 }
private: System::Void My6okno_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {


			if(e->KeyValue == 87){			//W
					kw = true;
			}
			if(e->KeyValue == 83){			//S
					ks = true;
			}
			if(e->KeyValue == 65){			//A
					ka = true;
			}
			if(e->KeyValue == 68){			//D
					kd = true;
			}
			if(e->KeyValue == 81){			//Q
					kl = true;
			}
			if(e->KeyValue == 69){			//E
					kp = true;
			}
		 }
private: System::Void My6okno_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if(e->KeyValue == 87){			//W
					kw = false;
			}
			if(e->KeyValue == 83){			//S
					ks = false;
			}
			if(e->KeyValue == 65){				//A
					ka = false;
			}
			if(e->KeyValue == 68){			//D
					kd = false;
			}
			if(e->KeyValue == 81){			//Q
					kl = false;
			}
			if(e->KeyValue == 69){			//E
					kp = false;
			}
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
