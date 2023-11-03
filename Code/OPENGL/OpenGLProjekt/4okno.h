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
	/// Summary for My4okno
	/// </summary>
	public ref class My4okno : public System::Windows::Forms::Form
	{
	public:
		My4okno(void)
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
	//		rtri = 0.0f;
			timer1->Interval = 10;
			timer1->Enabled = true;
		}
		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
		
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Ustawienia Blendingu
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Kolor tła
			glClearDepth(1.0);									// Czyści bufor głębi
			glFlush();
			glDepthFunc(GL_LESS);								// test głębi
			glShadeModel(GL_SMOOTH);							// wygładzenie on
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// perspektywa
			   GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 0.5 };
			   GLfloat mat_shininess[] = { 10.0 };
			   GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
			   GLfloat light_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
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
		~My4okno()
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
	//	GLfloat	rtri;				// Angle for the triangle
		int frameCount;
		float fps;
		int currentTime, previousTime;

		int f;
		float lr, ud, skal, skalx, skaly, skalz;
		int f2, rotacja2;
		float swiatlo2, kolor12, kolor22, kolor32, katy22, katx22, katz22, lr2, ud2, skal2, skalx2, skaly2, skalz2;
private: System::Windows::Forms::Button^  czajnik;
private: System::Windows::Forms::Button^  dwudziestoscian;
private: System::Windows::Forms::Button^  sfera;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::NumericUpDown^  color1a;
private: System::Windows::Forms::NumericUpDown^  color1c;
private: System::Windows::Forms::NumericUpDown^  color1b;
private: System::Windows::Forms::RadioButton^  radioButton2;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  Codeview;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::NumericUpDown^  fps2;
private: System::Windows::Forms::NumericUpDown^  znaki;
private: System::Windows::Forms::NumericUpDown^  wiersze;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::GroupBox^  Sterowanie;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::NumericUpDown^  katy;

private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::NumericUpDown^  katx;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Button^  minus;
private: System::Windows::Forms::Button^  plus;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  left;
private: System::Windows::Forms::Button^  right;
private: System::Windows::Forms::Button^  down;
private: System::Windows::Forms::CheckBox^  checkBox3;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::NumericUpDown^  katz;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button2;

private: System::Windows::Forms::Button^  up;

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
			this->sfera = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->color1a = (gcnew System::Windows::Forms::NumericUpDown());
			this->color1c = (gcnew System::Windows::Forms::NumericUpDown());
			this->color1b = (gcnew System::Windows::Forms::NumericUpDown());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Codeview = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fps2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->znaki = (gcnew System::Windows::Forms::NumericUpDown());
			this->wiersze = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Sterowanie = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->katz = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->katy = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->katx = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->left = (gcnew System::Windows::Forms::Button());
			this->right = (gcnew System::Windows::Forms::Button());
			this->down = (gcnew System::Windows::Forms::Button());
			this->up = (gcnew System::Windows::Forms::Button());
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1a))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1c))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1b))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->BeginInit();
			this->Sterowanie->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->katz))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->katy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->katx))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &My4okno::timer1_Tick);
			// 
			// OpenGLPanel
			// 
			this->OpenGLPanel->Location = System::Drawing::Point(10, 10);
			this->OpenGLPanel->Name = L"OpenGLPanel";
			this->OpenGLPanel->Size = System::Drawing::Size(500, 500);
			this->OpenGLPanel->TabIndex = 0;
			// 
			// czajnik
			// 
			this->czajnik->Location = System::Drawing::Point(338, 527);
			this->czajnik->Name = L"czajnik";
			this->czajnik->Size = System::Drawing::Size(80, 60);
			this->czajnik->TabIndex = 49;
			this->czajnik->Text = L"CZAJNIK";
			this->czajnik->UseVisualStyleBackColor = true;
			this->czajnik->Click += gcnew System::EventHandler(this, &My4okno::czajnik_Click);
			// 
			// dwudziestoscian
			// 
			this->dwudziestoscian->Location = System::Drawing::Point(190, 527);
			this->dwudziestoscian->Name = L"dwudziestoscian";
			this->dwudziestoscian->Size = System::Drawing::Size(124, 60);
			this->dwudziestoscian->TabIndex = 48;
			this->dwudziestoscian->Text = L"DWUDZIESTOŚCIAN";
			this->dwudziestoscian->UseVisualStyleBackColor = true;
			this->dwudziestoscian->Click += gcnew System::EventHandler(this, &My4okno::dwudziestoscian_Click);
			// 
			// sfera
			// 
			this->sfera->Location = System::Drawing::Point(81, 527);
			this->sfera->Name = L"sfera";
			this->sfera->Size = System::Drawing::Size(85, 60);
			this->sfera->TabIndex = 47;
			this->sfera->Text = L"TRÓJKĄT";
			this->sfera->UseVisualStyleBackColor = true;
			this->sfera->Click += gcnew System::EventHandler(this, &My4okno::sfera_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->color1a);
			this->groupBox4->Controls->Add(this->color1c);
			this->groupBox4->Controls->Add(this->color1b);
			this->groupBox4->Controls->Add(this->radioButton2);
			this->groupBox4->Controls->Add(this->radioButton1);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Location = System::Drawing::Point(520, 547);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(450, 47);
			this->groupBox4->TabIndex = 46;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Dodatki:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 21);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 13);
			this->label7->TabIndex = 52;
			this->label7->Text = L"Kolor:";
			// 
			// color1a
			// 
			this->color1a->DecimalPlaces = 2;
			this->color1a->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1a->Location = System::Drawing::Point(76, 18);
			this->color1a->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1a->Name = L"color1a";
			this->color1a->Size = System::Drawing::Size(50, 20);
			this->color1a->TabIndex = 51;
			this->color1a->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color1c
			// 
			this->color1c->DecimalPlaces = 2;
			this->color1c->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1c->Location = System::Drawing::Point(198, 18);
			this->color1c->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1c->Name = L"color1c";
			this->color1c->Size = System::Drawing::Size(50, 20);
			this->color1c->TabIndex = 49;
			this->color1c->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// color1b
			// 
			this->color1b->DecimalPlaces = 2;
			this->color1b->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 131072});
			this->color1b->Location = System::Drawing::Point(137, 18);
			this->color1b->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->color1b->Name = L"color1b";
			this->color1b->Size = System::Drawing::Size(50, 20);
			this->color1b->TabIndex = 50;
			this->color1b->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(384, 19);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(45, 17);
			this->radioButton2->TabIndex = 48;
			this->radioButton2->Text = L"OFF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(337, 20);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(41, 17);
			this->radioButton1->TabIndex = 47;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ON";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(283, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 46;
			this->label1->Text = L"Światło:";
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
			this->Codeview->TabIndex = 43;
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
			this->groupBox1->TabIndex = 44;
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
			this->label5->Text = L"Ilość wierszy:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(171, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Ilość znaków:";
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
			this->Sterowanie->Controls->Add(this->checkBox2);
			this->Sterowanie->Controls->Add(this->checkBox3);
			this->Sterowanie->Controls->Add(this->label8);
			this->Sterowanie->Controls->Add(this->katz);
			this->Sterowanie->Controls->Add(this->label3);
			this->Sterowanie->Controls->Add(this->katy);
			this->Sterowanie->Controls->Add(this->label2);
			this->Sterowanie->Controls->Add(this->katx);
			this->Sterowanie->Controls->Add(this->checkBox1);
			this->Sterowanie->Location = System::Drawing::Point(520, 426);
			this->Sterowanie->Name = L"Sterowanie";
			this->Sterowanie->Size = System::Drawing::Size(187, 119);
			this->Sterowanie->TabIndex = 45;
			this->Sterowanie->TabStop = false;
			this->Sterowanie->Text = L"Rotacja";
			this->Sterowanie->Enter += gcnew System::EventHandler(this, &My4okno::Sterowanie_Enter);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(14, 20);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 17);
			this->checkBox2->TabIndex = 33;
			this->checkBox2->Text = L"Oś X";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(129, 20);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(49, 17);
			this->checkBox3->TabIndex = 52;
			this->checkBox3->Text = L"Oś Z";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &My4okno::checkBox3_CheckedChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(11, 96);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 13);
			this->label8->TabIndex = 37;
			this->label8->Text = L"Kąt obrotu (Z):";
			// 
			// katz
			// 
			this->katz->Location = System::Drawing::Point(90, 94);
			this->katz->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {360, 0, 0, 0});
			this->katz->Name = L"katz";
			this->katz->Size = System::Drawing::Size(88, 20);
			this->katz->TabIndex = 36;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 13);
			this->label3->TabIndex = 37;
			this->label3->Text = L"Kąt obrotu (Y):";
			// 
			// katy
			// 
			this->katy->Location = System::Drawing::Point(90, 69);
			this->katy->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {360, 0, 0, 0});
			this->katy->Name = L"katy";
			this->katy->Size = System::Drawing::Size(88, 20);
			this->katy->TabIndex = 36;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 35;
			this->label2->Text = L"Kąt obrotu (X):";
			// 
			// katx
			// 
			this->katx->Location = System::Drawing::Point(90, 44);
			this->katx->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {360, 0, 0, 0});
			this->katx->Name = L"katx";
			this->katx->Size = System::Drawing::Size(88, 20);
			this->katx->TabIndex = 34;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(75, 20);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(49, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"Oś Y";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Location = System::Drawing::Point(835, 426);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(135, 119);
			this->groupBox3->TabIndex = 51;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Skalowanie";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(53, 90);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(30, 13);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Oś Z";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(53, 60);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Oś Y";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(53, 29);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(30, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Oś X";
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button7->Location = System::Drawing::Point(7, 84);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(35, 25);
			this->button7->TabIndex = 0;
			this->button7->Text = L"-";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &My4okno::button7_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(93, 84);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(35, 25);
			this->button4->TabIndex = 0;
			this->button4->Text = L"+";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &My4okno::button4_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button6->Location = System::Drawing::Point(7, 54);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(35, 25);
			this->button6->TabIndex = 0;
			this->button6->Text = L"-";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &My4okno::button6_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(7, 23);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(35, 25);
			this->button5->TabIndex = 0;
			this->button5->Text = L"-";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &My4okno::button5_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(93, 54);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(35, 25);
			this->button3->TabIndex = 0;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &My4okno::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(93, 23);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(35, 25);
			this->button2->TabIndex = 0;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &My4okno::button2_Click);
			// 
			// minus
			// 
			this->minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->minus->Location = System::Drawing::Point(78, 23);
			this->minus->Name = L"minus";
			this->minus->Size = System::Drawing::Size(25, 25);
			this->minus->TabIndex = 4;
			this->minus->Text = L"-";
			this->minus->UseVisualStyleBackColor = true;
			this->minus->Click += gcnew System::EventHandler(this, &My4okno::minus_Click);
			// 
			// plus
			// 
			this->plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->plus->Location = System::Drawing::Point(15, 84);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(25, 25);
			this->plus->TabIndex = 0;
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = true;
			this->plus->Click += gcnew System::EventHandler(this, &My4okno::plus_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->minus);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->plus);
			this->groupBox2->Controls->Add(this->left);
			this->groupBox2->Controls->Add(this->right);
			this->groupBox2->Controls->Add(this->down);
			this->groupBox2->Controls->Add(this->up);
			this->groupBox2->Location = System::Drawing::Point(710, 426);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(119, 119);
			this->groupBox2->TabIndex = 50;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Translacja";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(47, 54);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(25, 25);
			this->button1->TabIndex = 7;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &My4okno::button1_Click);
			// 
			// left
			// 
			this->left->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->left->Location = System::Drawing::Point(6, 54);
			this->left->Name = L"left";
			this->left->Size = System::Drawing::Size(35, 25);
			this->left->TabIndex = 6;
			this->left->Text = L"←";
			this->left->UseVisualStyleBackColor = true;
			this->left->Click += gcnew System::EventHandler(this, &My4okno::left_Click);
			// 
			// right
			// 
			this->right->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->right->Location = System::Drawing::Point(77, 54);
			this->right->Name = L"right";
			this->right->Size = System::Drawing::Size(35, 25);
			this->right->TabIndex = 5;
			this->right->Text = L"→";
			this->right->UseVisualStyleBackColor = true;
			this->right->Click += gcnew System::EventHandler(this, &My4okno::right_Click);
			// 
			// down
			// 
			this->down->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->down->Location = System::Drawing::Point(47, 80);
			this->down->Name = L"down";
			this->down->Size = System::Drawing::Size(25, 35);
			this->down->TabIndex = 4;
			this->down->Text = L"↓";
			this->down->UseVisualStyleBackColor = true;
			this->down->Click += gcnew System::EventHandler(this, &My4okno::down_Click);
			// 
			// up
			// 
			this->up->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->up->Location = System::Drawing::Point(47, 18);
			this->up->Name = L"up";
			this->up->Size = System::Drawing::Size(25, 35);
			this->up->TabIndex = 0;
			this->up->Text = L"↑";
			this->up->UseVisualStyleBackColor = true;
			this->up->Click += gcnew System::EventHandler(this, &My4okno::up_Click);
			// 
			// My4okno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->czajnik);
			this->Controls->Add(this->dwudziestoscian);
			this->Controls->Add(this->sfera);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->Codeview);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Sterowanie);
			this->Controls->Add(this->OpenGLPanel);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 640);
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->Name = L"My4okno";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"C++ & OpenGL: Przekształcenia";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &My4okno::My4okno_FormClosed);
			this->Load += gcnew System::EventHandler(this, &My4okno::My4okno_Load);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1a))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1c))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->color1b))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->EndInit();
			this->Sterowanie->ResumeLayout(false);
			this->Sterowanie->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->katz))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->katy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->katx))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
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
	System::Void Render(int f2, int r, int s2, float c1a3, float c1b3, float c1c3, float katy2, float katx2, float katz2, float lr, float ud, float skal, float skalx, float skaly, float skalz)
			{
			wglMakeCurrent(m_hDC, m_hRC);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			glTranslatef(lr,ud,skal);
			
			if (s2==1){
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
			};
			if (r > 0)
				{
					switch (r)
					{
						case 1:
							glRotatef(katx2,1.0f,0.0f,0.0f);
							break;
						case 2:
							glRotatef(katy2,0.0f,1.0f,0.0f);
							break;
						case 3:
							glRotatef(katz2,0.0f,0.0f,1.0f);
							break;
						case 4:
							glRotatef(katx2,1.0f,0.0f,0.0f);
							glRotatef(katy2,0.0f,1.0f,0.0f);
							break;
						case 5:
							glRotatef(katx2,1.0f,0.0f,0.0f);
							glRotatef(katz2,0.0f,0.0f,1.0f);
							break;
						case 6:
							glRotatef(katy2,0.0f,1.0f,0.0f);
							glRotatef(katz2,0.0f,0.0f,1.0f);
							break;
						case 7:
							glRotatef(katx2,1.0f,0.0f,0.0f);
							glRotatef(katy2,0.0f,1.0f,0.0f);
							glRotatef(katz2,0.0f,0.0f,1.0f);
							break;
					}
				}
			glScalef(skalx, skaly, skalz);
			glColor3f(c1a3,c1b3,c1c3);
			switch(f2){
			case 1:
				glBegin(GL_TRIANGLES);
					glVertex3f( 0.0f, 0.75f, 0.0f); 
					glVertex3f(-0.75f,-0.75f, 0.0f); 
					glVertex3f( 0.75f,-0.75f, 0.0f); 
				glEnd();
				break;
			case 2:
				glutSolidIcosahedron();
				break;
			case 3:
				glutSolidTeapot(1.5f);
				break;
			}



			if (s2==1)
			{
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
			};

			glFlush();
			SwapBuffers( m_hDC );
		}
	System::Void tresc(int f2, int r, int s2, float c1a3, float c1b3, float c1c3, float katy2, float katx2, float katz2, float lr, float ud, float skal, float skalx, float skaly, float skalz)
	{
		Codeview->Text = L"glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);\r\nglLoadIdentity();\r\nglTranslatef("+ lr +"f,"+ ud +"f,"+ skal +"f);\r\n\r\n";
		
					if (r > 0)
				{
					switch (r)
					{
						case 1:
							Codeview->Text += "glRotatef("+katx2+",1.0f,0.0f,0.0f);\r\n\r\n";
							break;
						case 2:
							Codeview->Text += "glRotatef("+katy2+",0.0f,1.0f,0.0f);\r\n\r\n";
							break;
						case 3:
							Codeview->Text += "glRotatef("+katz2+",0.0f,0.0f,1.0f);\r\n\r\n";
							break;
						case 4:
							Codeview->Text += "glRotatef("+katx2+",1.0f,0.0f,0.0f);\r\n\r\n";
							Codeview->Text += "glRotatef("+katy2+",0.0f,1.0f,0.0f);\r\n\r\n";
							break;
						case 5:
							Codeview->Text += "glRotatef("+katx2+",1.0f,0.0f,0.0f);\r\n\r\n";
							Codeview->Text += "glRotatef("+katz2+",0.0f,0.0f,1.0f);\r\n\r\n";
							break;
						case 6:
							Codeview->Text += "glRotatef("+katy2+",0.0f,1.0f,0.0f);\r\n\r\n";
							Codeview->Text += "glRotatef("+katz2+",0.0f,0.0f,1.0f);\r\n\r\n";
							break;
						case 7:
							Codeview->Text += "glRotatef("+katx2+",1.0f,0.0f,0.0f);\r\n\r\n";
							Codeview->Text += "glRotatef("+katy2+",0.0f,1.0f,0.0f);\r\n\r\n";
							Codeview->Text += "glRotatef("+katz2+",0.0f,0.0f,1.0f);\r\n\r\n";
							break;
					}
				}
		Codeview->Text += "glScalef("+ skalx +"f,"+ skaly +"f,"+ skalz +"f);\r\n\r\n";
		if (s2==1)
			{
				Codeview->Text += "glEnable(GL_LIGHTING)\r\nglEnable(GL_LIGHT0);\r\n\r\n";
			}
		Codeview->Text += "glColor3f(" + c1a3  + "f," + c1b3 + "f," + c1c3 + "f);\r\n\r\n";
			
		switch(f2){
			case 1:
				Codeview->Text += "   glBegin(GL_TRIANGLES);\r\n\tglVertex3f( 0.0f, 0.75f, 0.0f);\r\n\tglVertex3f(-0.75f,-0.75f, 0.0f);\r\n\tglVertex3f( 0.75f,-0.75f, 0.0f);\r\n   glEnd();\r\n";
				break;
			case 2:
				Codeview->Text += "\tglutSolidIcosahedron();\r\n";
				break;
			case 3:
				Codeview->Text += "\tglutSolidTeapot(1.5f);\r\n";
				break;
			}

		if (s2==1)
			{
				Codeview->Text += "\r\nglDisable(GL_LIGHTING)\r\nglDisable(GL_LIGHT0);\r\n\r\n";
			}

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
				 float katy2 = (float)katy->Value;
				 float katx2 = (float)katx->Value;
				 float katz2 = (float)katz->Value;
				 Render(f, rotacja, swiatlo, kolor1, kolor2, kolor3, katy2, katx2, katz2, lr, ud, skal, skalx, skaly, skalz);
				 if (rotacja!=rotacja2 || f!=f2 || swiatlo!=swiatlo2 || kolor1!=kolor12 || kolor2!=kolor22 || kolor3!=kolor32 || katy2!=katy22 || katx2!=katx22 || katz2!=katz22 || lr!=lr2 || ud!=ud2 || skal!=skal2 || skalx!=skalx2 || skaly!=skaly2 || skalz!=skalz2)
				 {
					 tresc(f, rotacja, swiatlo, kolor1, kolor2, kolor3, katy2, katx2, katz2, lr, ud, skal, skalx, skaly, skalz);
					 f2=f; 
					 rotacja2=rotacja;
					 swiatlo2=swiatlo; 
					 kolor12=kolor1; 
					 kolor22=kolor2; 
					 kolor32=kolor3; 
					 katy22=katy2; 
					 katx22=katx2; 
					 katz22=katz2;
					 lr2=lr; 
					 ud2=ud; 
					 skal2=skal;
					 skalx2=skalx;
					 skaly2=skaly;
					 skalz2=skalz;
				 }
				 wiersze->Value = Codeview->Lines->Length;
				 znaki->Value = Codeview->Text->Length;
			 	 float dd = FPS();
				 fps2->Value =(System::Decimal)dd;
			 }
private: System::Void sfera_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=1;
			 }
private: System::Void dwudziestoscian_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=2;
			 }
private: System::Void czajnik_Click(System::Object^  sender, System::EventArgs^  e) {
			 f=3;
			 }
private: System::Void My4okno_Load(System::Object^  sender, System::EventArgs^  e) {
				  f=1;
				  katx->Value = 0;
				  katy->Value = 0;
				  lr = 0.0;
				  ud = 0.0;
				  skal= -6.0;
				  skalx = 1.00;
				  skaly = 1.00;
				  skalz = 1.00;
		 }
private: System::Void My4okno_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Application::Restart();
		 }
private: System::Void up_Click(System::Object^  sender, System::EventArgs^  e) {
			 ud+= 0.5;
		 }
private: System::Void right_Click(System::Object^  sender, System::EventArgs^  e) {
			 lr= lr + 0.5;
		 }
private: System::Void down_Click(System::Object^  sender, System::EventArgs^  e) {
			 ud-= 0.5;
		 }
private: System::Void left_Click(System::Object^  sender, System::EventArgs^  e) {
			 lr= lr - 0.5;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 ud = 0.0;
			 lr = 0.0;
			 skal = -6.0;
			 skalx = 1.0;
			 skaly = 1.0;
			 skalz = 1.0;
		 }
private: System::Void plus_Click(System::Object^  sender, System::EventArgs^  e) {
			 skal = skal + 0.5;
		 }
private: System::Void minus_Click(System::Object^  sender, System::EventArgs^  e) {
			 skal = skal - 0.5;
		 }
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Sterowanie_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 skalx += 0.2;
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 skaly += 0.2;
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 skalz += 0.2;
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 skalz -= 0.2;
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 skaly -= 0.2;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 skalx -= 0.2;
		 }
};
}
