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
	/// Summary for My2okno
	/// </summary>
	public ref class My2okno : public System::Windows::Forms::Form
	{
	public:
		My2okno(void)
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
			m_hWnd = (HWND)this->OpenGLPanel2->Handle.ToInt32();
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
		
			//if (!LoadGLTextures())								// Jump To Texture Loading Routine ( NEW )
			//{
			//	return FALSE;									// If Texture Didn't Load Return FALSE
			//}
			//glEnable(GL_TEXTURE_2D);							// Tekstury dwówymiarowe on
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Ustawienia Blendingu
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Kolor t³a
			glClearDepth(1.0);									// Czyœci bufor g³êbi
			glFlush();
			glDepthFunc(GL_LESS);								// test g³êbi
//			glEnable(GL_DEPTH_TEST);							// Testowanie g³êbi on
			glShadeModel(GL_SMOOTH);							// wyg³adzenie on
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// perspektywa
 /*  GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 0.5 };
   GLfloat mat_shininess[] = { 20.0 };
   GLfloat light_position[] = { 2.0, 2.0, 2.0, 2.0 };

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_COLOR_MATERIAL);*/
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
		~My2okno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  OpenGLPanel2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  Sterowanie;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::NumericUpDown^  color4a;
	private: System::Windows::Forms::NumericUpDown^  color3a;
	private: System::Windows::Forms::NumericUpDown^  color2a;
	private: System::Windows::Forms::NumericUpDown^  color4c;
	private: System::Windows::Forms::NumericUpDown^  color3c;
	private: System::Windows::Forms::NumericUpDown^  color2c;
	private: System::Windows::Forms::NumericUpDown^  color4b;
	private: System::Windows::Forms::NumericUpDown^  color3b;
	private: System::Windows::Forms::NumericUpDown^  color2b;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::NumericUpDown^  color1a;
	private: System::Windows::Forms::NumericUpDown^  color1c;
	private: System::Windows::Forms::NumericUpDown^  color1b;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  fps2;
	private: System::Windows::Forms::NumericUpDown^  znaki;
	private: System::Windows::Forms::NumericUpDown^  wiersze;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  Codeview;
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
		
		int a;
		int b;
		int a2, b2, rotacja2;
		float c1a2,c1b2,c1c2,c2a2,c2b2,c2c2,c3a2,c3b2,c3c2,c4a2,c4b2,c4c2;
private: System::Windows::Forms::CheckBox^  checkBox3;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->OpenGLPanel2 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Sterowanie = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->color4a = (gcnew System::Windows::Forms::NumericUpDown());
			this->color3a = (gcnew System::Windows::Forms::NumericUpDown());
			this->color2a = (gcnew System::Windows::Forms::NumericUpDown());
			this->color4c = (gcnew System::Windows::Forms::NumericUpDown());
			this->color3c = (gcnew System::Windows::Forms::NumericUpDown());
			this->color2c = (gcnew System::Windows::Forms::NumericUpDown());
			this->color4b = (gcnew System::Windows::Forms::NumericUpDown());
			this->color3b = (gcnew System::Windows::Forms::NumericUpDown());
			this->color2b = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->color1a = (gcnew System::Windows::Forms::NumericUpDown());
			this->color1c = (gcnew System::Windows::Forms::NumericUpDown());
			this->color1b = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fps2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->znaki = (gcnew System::Windows::Forms::NumericUpDown());
			this->wiersze = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Codeview = (gcnew System::Windows::Forms::TextBox());
			this->Sterowanie->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color4a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color3a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color4c))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color3c))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2c))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color4b))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color3b))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2b))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1c))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1b))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->BeginInit();
			this->SuspendLayout();
			// 
			// OpenGLPanel2
			// 
			this->OpenGLPanel2->Location = System::Drawing::Point(10, 10);
			this->OpenGLPanel2->Name = L"OpenGLPanel2";
			this->OpenGLPanel2->Size = System::Drawing::Size(500, 500);
			this->OpenGLPanel2->TabIndex = 1;
			this->OpenGLPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &My2okno::OpenGLPanel2_Paint);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &My2okno::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(325, 525);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 60);
			this->button2->TabIndex = 17;
			this->button2->Text = L"WIELE KOLORÓW";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &My2okno::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 525);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 60);
			this->button1->TabIndex = 16;
			this->button1->Text = L"JEDEN KOLOR";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &My2okno::button1_Click);
			// 
			// Sterowanie
			// 
			this->Sterowanie->Controls->Add(this->checkBox3);
			this->Sterowanie->Controls->Add(this->label10);
			this->Sterowanie->Controls->Add(this->label9);
			this->Sterowanie->Controls->Add(this->label8);
			this->Sterowanie->Controls->Add(this->label7);
			this->Sterowanie->Controls->Add(this->color4a);
			this->Sterowanie->Controls->Add(this->color3a);
			this->Sterowanie->Controls->Add(this->color2a);
			this->Sterowanie->Controls->Add(this->color4c);
			this->Sterowanie->Controls->Add(this->color3c);
			this->Sterowanie->Controls->Add(this->color2c);
			this->Sterowanie->Controls->Add(this->color4b);
			this->Sterowanie->Controls->Add(this->color3b);
			this->Sterowanie->Controls->Add(this->color2b);
			this->Sterowanie->Controls->Add(this->label2);
			this->Sterowanie->Controls->Add(this->checkBox2);
			this->Sterowanie->Controls->Add(this->checkBox1);
			this->Sterowanie->Controls->Add(this->label3);
			this->Sterowanie->Controls->Add(this->label1);
			this->Sterowanie->Controls->Add(this->radioButton2);
			this->Sterowanie->Controls->Add(this->radioButton1);
			this->Sterowanie->Controls->Add(this->color1a);
			this->Sterowanie->Controls->Add(this->color1c);
			this->Sterowanie->Controls->Add(this->color1b);
			this->Sterowanie->Location = System::Drawing::Point(520, 430);
			this->Sterowanie->Name = L"Sterowanie";
			this->Sterowanie->Size = System::Drawing::Size(450, 160);
			this->Sterowanie->TabIndex = 15;
			this->Sterowanie->TabStop = false;
			this->Sterowanie->Text = L"Sterowanie";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(92, 121);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(49, 17);
			this->checkBox3->TabIndex = 18;
			this->checkBox3->Text = L"Oœ Z";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(171, 132);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"4 wierzcho³ek:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(171, 102);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(77, 13);
			this->label9->TabIndex = 20;
			this->label9->Text = L"3 wierzcho³ek:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(171, 72);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(77, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"2 wierzcho³ek:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(171, 42);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"1 wierzcho³ek:";
			// 
			// color4a
			// 
			this->color4a->DecimalPlaces = 2;
			this->color4a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color4a->Location = System::Drawing::Point(269, 130);
			this->color4a->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color4a->Name = L"color4a";
			this->color4a->Size = System::Drawing::Size(50, 20);
			this->color4a->TabIndex = 19;
			this->color4a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color3a
			// 
			this->color3a->DecimalPlaces = 2;
			this->color3a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color3a->Location = System::Drawing::Point(269, 100);
			this->color3a->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color3a->Name = L"color3a";
			this->color3a->Size = System::Drawing::Size(50, 20);
			this->color3a->TabIndex = 19;
			this->color3a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color2a
			// 
			this->color2a->DecimalPlaces = 2;
			this->color2a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color2a->Location = System::Drawing::Point(269, 70);
			this->color2a->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color2a->Name = L"color2a";
			this->color2a->Size = System::Drawing::Size(50, 20);
			this->color2a->TabIndex = 19;
			this->color2a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color4c
			// 
			this->color4c->DecimalPlaces = 2;
			this->color4c->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color4c->Location = System::Drawing::Point(391, 130);
			this->color4c->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color4c->Name = L"color4c";
			this->color4c->Size = System::Drawing::Size(50, 20);
			this->color4c->TabIndex = 18;
			this->color4c->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color3c
			// 
			this->color3c->DecimalPlaces = 2;
			this->color3c->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color3c->Location = System::Drawing::Point(391, 100);
			this->color3c->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color3c->Name = L"color3c";
			this->color3c->Size = System::Drawing::Size(50, 20);
			this->color3c->TabIndex = 18;
			this->color3c->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color2c
			// 
			this->color2c->DecimalPlaces = 2;
			this->color2c->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color2c->Location = System::Drawing::Point(391, 70);
			this->color2c->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color2c->Name = L"color2c";
			this->color2c->Size = System::Drawing::Size(50, 20);
			this->color2c->TabIndex = 18;
			this->color2c->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color4b
			// 
			this->color4b->DecimalPlaces = 2;
			this->color4b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color4b->Location = System::Drawing::Point(330, 130);
			this->color4b->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color4b->Name = L"color4b";
			this->color4b->Size = System::Drawing::Size(50, 20);
			this->color4b->TabIndex = 17;
			this->color4b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color3b
			// 
			this->color3b->DecimalPlaces = 2;
			this->color3b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color3b->Location = System::Drawing::Point(330, 100);
			this->color3b->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color3b->Name = L"color3b";
			this->color3b->Size = System::Drawing::Size(50, 20);
			this->color3b->TabIndex = 17;
			this->color3b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color2b
			// 
			this->color2b->DecimalPlaces = 2;
			this->color2b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color2b->Location = System::Drawing::Point(330, 70);
			this->color2b->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color2b->Name = L"color2b";
			this->color2b->Size = System::Drawing::Size(50, 20);
			this->color2b->TabIndex = 17;
			this->color2b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(171, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Wartoœci kolorów:";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(37, 107);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 17);
			this->checkBox2->TabIndex = 15;
			this->checkBox2->Text = L"Oœ X";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(37, 133);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(49, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"Oœ Y";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Rotacja:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Figura:";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(37, 63);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(56, 17);
			this->radioButton2->TabIndex = 11;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"QUAD";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &My2okno::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(37, 40);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(79, 17);
			this->radioButton1->TabIndex = 10;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"TRIANGLE";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &My2okno::radioButton1_CheckedChanged);
			// 
			// color1a
			// 
			this->color1a->DecimalPlaces = 2;
			this->color1a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1a->Location = System::Drawing::Point(269, 40);
			this->color1a->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1a->Name = L"color1a";
			this->color1a->Size = System::Drawing::Size(50, 20);
			this->color1a->TabIndex = 9;
			this->color1a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color1c
			// 
			this->color1c->DecimalPlaces = 2;
			this->color1c->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1c->Location = System::Drawing::Point(391, 40);
			this->color1c->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1c->Name = L"color1c";
			this->color1c->Size = System::Drawing::Size(50, 20);
			this->color1c->TabIndex = 9;
			this->color1c->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color1b
			// 
			this->color1b->DecimalPlaces = 2;
			this->color1b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1b->Location = System::Drawing::Point(330, 40);
			this->color1b->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1b->Name = L"color1b";
			this->color1b->Size = System::Drawing::Size(50, 20);
			this->color1b->TabIndex = 9;
			this->color1b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
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
			this->groupBox1->TabIndex = 14;
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
			this->znaki->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {96, 0, 0, 0});
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
			this->wiersze->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
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
			this->Codeview->TabIndex = 13;
			this->Codeview->WordWrap = false;
			// 
			// My2okno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Sterowanie);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Codeview);
			this->Controls->Add(this->OpenGLPanel2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 640);
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->Name = L"My2okno";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"C++ & OpenGL: Kolorowanie";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &My2okno::My2okno_FormClosed);
			this->Load += gcnew System::EventHandler(this, &My2okno::My2okno_Load);
			this->Sterowanie->ResumeLayout(false);
			this->Sterowanie->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color4a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color3a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color4c))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color3c))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2c))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color4b))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color3b))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color2b))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1c))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1b))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->EndInit();
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
	System::Void Render(int a, int b, int r, float c1a, float c1b, float c1c, float c2a, float c2b, float c2c, float c3a, float c3b, float c3c, float c4a, float c4b, float c4c)
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
			
			switch(a)
			{
			case 1:
				glColor3f(c1a,c1b,c1c);
				if (b==1)
				{
					glBegin(GL_TRIANGLES);
						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f( 1.0f,-1.0f, 0.0f); 
						glVertex3f(-1.0f,-1.0f, 0.0f);
					glEnd(); 
				}else if (b==2)
				{
					glBegin(GL_QUADS);                  
						glVertex3f(-1.0f, 1.0f, 0.0f);
						glVertex3f( 1.0f, 1.0f, 0.0f);
						glVertex3f( 1.0f,-1.0f, 0.0f);
						glVertex3f(-1.0f,-1.0f, 0.0f);
					glEnd(); 
				};
				break;
			case 2:
				if (b==1)
				{
					glBegin(GL_TRIANGLES);
					  glColor3f(c1a,c1b,c1c);
						glVertex3f( 0.0f, 1.0f, 0.0f);
					  glColor3f(c2a,c2b,c2c);
						glVertex3f( 1.0f,-1.0f, 0.0f);						
					  glColor3f(c3a,c3b,c3c);
						glVertex3f(-1.0f,-1.0f, 0.0f);
					glEnd(); 
				}else if (b==2)
				{
					glBegin(GL_QUADS);
					  glColor3f(c1a,c1b,c1c);
						glVertex3f(-1.0f, 1.0f, 0.0f);
					  glColor3f(c2a,c2b,c2c);
						glVertex3f( 1.0f, 1.0f, 0.0f);
					  glColor3f(c3a,c3b,c3c);
						glVertex3f( 1.0f,-1.0f, 0.0f);
					  glColor3f(c4a,c4b,c4c);
						glVertex3f(-1.0f,-1.0f, 0.0f);
					glEnd(); 
				};
				break;

			}

			rtri+=0.2f;
			
			glFlush();
			SwapBuffers( m_hDC );
		}
	System::Void tresc(int a, int b, int r, float c1a, float c1b, float c1c, float c2a, float c2b, float c2c, float c3a, float c3b, float c3c, float c4a, float c4b, float c4c){
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
			switch(a)
			{
			case 1:
				Codeview->Text = Codeview->Text + "glColor3f(" + c1a  + "f," + c1b + "f," + c1c + "f);\r\n\r\n";
				if (b==1)
				{
					Codeview->Text = Codeview->Text + "   glBegin(GL_TRIANGLES);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 1.0f,-1.0f, 0.0f);\r\n\tglVertex3f(-1.0f,-1.0f, 0.0f);\r\n   glEnd();\r\n"; 
				}else if (b==2)
				{
					Codeview->Text = Codeview->Text + "   glBegin(GL_QUADS);\r\n\tglVertex3f(-1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n\tglVertex3f( 1.0f,-1.0f, 0.0f);\r\n\tglVertex3f(-1.0f,-1.0f, 0.0f);\r\n   glEnd();\r\n";
				};
				break;
			case 2:
				if (b==1)
				{
					Codeview->Text = Codeview->Text + "   glBegin(GL_TRIANGLES);\r\n      glColor3f(" + c1a  + "f," + c1b + "f," + c1c + "f);\r\n\tglVertex3f( 0.0f, 1.0f, 0.0f);\r\n      glColor3f(" + c2a  + "f," + c2b + "f," + c2c + "f);\r\n\tglVertex3f( 1.0f,-1.0f, 0.0f);\r\n      glColor3f(" + c3a  + "f," + c3b + "f," + c3c + "f);\r\n\tglVertex3f(-1.0f,-1.0f, 0.0f);\r\n   glEnd();\r\n"; 
				}else if (b==2)
				{
					Codeview->Text = Codeview->Text + "   glBegin(GL_QUADS);\r\n      glColor3f(" + c1a  + "f," + c1b + "f," + c1c + "f);\r\n\tglVertex3f(-1.0f, 1.0f, 0.0f);\r\n      glColor3f(" + c2a  + "f," + c2b + "f," + c2c + "f);\r\n\tglVertex3f( 1.0f, 1.0f, 0.0f);\r\n      glColor3f(" + c3a  + "f," + c3b + "f," + c3c + "f);\r\n\tglVertex3f( 1.0f,-1.0f, 0.0f);\r\n      glColor3f(" + c4a  + "f," + c4b + "f," + c4c + "f);\r\n\tglVertex3f(-1.0f,-1.0f, 0.0f);\r\n   glEnd();\r\n";
				};
				break;

			}


			if (r>0 && r<8){
				Codeview->Text = Codeview->Text + "\t\r\nrtri+=0.2f;";
			};
			}

private: System::Void My2okno_Load(System::Object^  sender, System::EventArgs^  e) {
			 a=1;
			 b=1;
			 label7->Visible = false;
			 label8->Visible = false;
			 label9->Visible = false;
			 label10->Visible = false;
			 color2a->Visible = false;
			 color2b->Visible = false;
			 color2c->Visible = false;
			 color3a->Visible = false;
			 color3b->Visible = false;
			 color3c->Visible = false;
			 color4a->Visible = false;
			 color4b->Visible = false;
			 color4c->Visible = false;
			 color4a->Enabled = false;
			 color4b->Enabled = false;
			 color4c->Enabled = false;
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

				 float c1a = (float)color1a->Value;
				 float c1b = (float)color1b->Value;
				 float c1c = (float)color1c->Value;
				 float c2a = (float)color2a->Value;
				 float c2b = (float)color2b->Value;
				 float c2c = (float)color2c->Value;
				 float c3a = (float)color3a->Value;
				 float c3b = (float)color3b->Value;
				 float c3c = (float)color3c->Value;
				 float c4a = (float)color4a->Value;
				 float c4b = (float)color4b->Value;
				 float c4c = (float)color4c->Value;
				 

				 Render(a,b,rotacja,c1a,c1b,c1c,c2a,c2b,c2c,c3a,c3b,c3c,c4a,c4b,c4c);
				 if (a!=a2 || b!=b2 || rotacja != rotacja2 || c1a != c1a2 || c1b != c1b2 || c1c != c1c2 || c2a != c2a2 || c2b != c2b2 || c2c != c2c2 || c3a != c3a2 || c3b != c3b2 || c3c != c3c2 || c4a != c4a2 || c4b != c4b2 || c4c != c4c2){
				 tresc(a,b,rotacja,c1a,c1b,c1c,c2a,c2b,c2c,c3a,c3b,c3c,c4a,c4b,c4c);
				 a2=a;
				 b2=b;
				 rotacja2=rotacja;
				 c1a2=c1a;
				 c1b2=c1b;
				 c1c2=c1c;
				 c2a2=c2a;
				 c2b2=c2b;
				 c2c2=c2c;
				 c3a2=c3a;
				 c3b2=c3b;
				 c3c2=c3c;
				 c4a2=c4a;
				 c4b2=c4b;
				 c4c2=c4c;
				 }
				 wiersze->Value = Codeview->Lines->Length;
				 znaki->Value = Codeview->Text->Length;
				 float dd = FPS();
				 fps2->Value =(System::Decimal)dd;

		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton1->Checked){
			 b=1;
			 color4a->Enabled = false;
			 color4b->Enabled = false;
			 color4c->Enabled = false;
			 }
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton2->Checked){
			 b=2;
			 color4a->Enabled= true;
			 color4b->Enabled = true;
			 color4c->Enabled = true;
			 }
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 a=1;
			 label7->Visible = false;
			 label8->Visible = false;
			 label9->Visible = false;
			 label10->Visible = false;
			 color2a->Visible = false;
			 color2b->Visible = false;
			 color2c->Visible = false;
			 color3a->Visible = false;
			 color3b->Visible = false;
			 color3c->Visible = false;
			 color4a->Visible = false;
			 color4b->Visible = false;
			 color4c->Visible = false;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 a=2;
			 label7->Visible = true;
			 label8->Visible = true;
			 label9->Visible = true;
			 label10->Visible = true;
			 color2a->Visible = true;
			 color2b->Visible = true;
			 color2c->Visible = true;
			 color3a->Visible = true;
			 color3b->Visible = true;
			 color3c->Visible = true;
			 color4a->Visible = true;
			 color4b->Visible = true;
			 color4c->Visible = true;
		 }

private: System::Void My2okno_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Application::Restart();
		 }
private: System::Void OpenGLPanel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}
