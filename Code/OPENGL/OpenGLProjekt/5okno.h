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
	/// Summary for My5okno
	/// </summary>
	public ref class My5okno : public System::Windows::Forms::Form
	{
	public:
		My5okno(void)
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
		int LoadGLTextures(){
			Tekstura1 = SOIL_load_OGL_texture
				(
				"Data/Tekstura1.bmp",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);
			Tekstura2 = SOIL_load_OGL_texture
				(
				"Data/Tekstura2.bmp",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);
			Tekstura3 = SOIL_load_OGL_texture
				(
				"Data/Tekstura3.png",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);
			Tekstura4 = SOIL_load_OGL_texture
				(
				"Data/Tekstura4.jpg",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);
			Tekstura5 = SOIL_load_OGL_texture
				(
				"Data/Tekstura5.tga",
				SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_INVERT_Y
				);

			if(Tekstura1 == 0 || Tekstura2 == 0 || Tekstura3 == 0 || Tekstura4 == 0 || Tekstura5 == 0)
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
		~My5okno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  OpenGLPanel;
	protected: 
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
		GLuint Tekstura4;
		GLuint Tekstura5;

		int t;
		int t2t, rotacja2, swiatlo2, blend2;
private: System::Windows::Forms::RadioButton^  radioButton2;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  Codeview;
private: System::Windows::Forms::RadioButton^  radioButton4;

private: System::Windows::Forms::RadioButton^  radioButton3;








private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::NumericUpDown^  fps2;
private: System::Windows::Forms::NumericUpDown^  znaki;
private: System::Windows::Forms::NumericUpDown^  wiersze;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::CheckBox^  checkBox3;
private: System::Windows::Forms::GroupBox^  Sterowanie;



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
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Codeview = (gcnew System::Windows::Forms::TextBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->Sterowanie = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fps2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->znaki = (gcnew System::Windows::Forms::NumericUpDown());
			this->wiersze = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Sterowanie->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// OpenGLPanel
			// 
			this->OpenGLPanel->Location = System::Drawing::Point(10, 10);
			this->OpenGLPanel->Name = L"OpenGLPanel";
			this->OpenGLPanel->Size = System::Drawing::Size(500, 500);
			this->OpenGLPanel->TabIndex = 1;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &My5okno::timer1_Tick);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(16, 50);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(45, 17);
			this->radioButton2->TabIndex = 41;
			this->radioButton2->Text = L"OFF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(16, 25);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(41, 17);
			this->radioButton1->TabIndex = 40;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ON";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Œwiat³o:";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(9, 41);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 17);
			this->checkBox2->TabIndex = 38;
			this->checkBox2->Text = L"Oœ X";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(9, 62);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(49, 17);
			this->checkBox1->TabIndex = 37;
			this->checkBox1->Text = L"Oœ Y";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 36;
			this->label3->Text = L"Rotacja:";
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
			this->Codeview->TabIndex = 34;
			this->Codeview->WordWrap = false;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->Location = System::Drawing::Point(168, 71);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(45, 17);
			this->radioButton4->TabIndex = 44;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"OFF";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(168, 46);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(41, 17);
			this->radioButton3->TabIndex = 43;
			this->radioButton3->Text = L"ON";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(145, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 42;
			this->label2->Text = L"Przezroczystoœæ:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 525);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 60);
			this->button1->TabIndex = 46;
			this->button1->Text = L"TEKSTURA 1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &My5okno::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(114, 525);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 60);
			this->button2->TabIndex = 47;
			this->button2->Text = L"TEKSTURA 2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &My5okno::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(213, 525);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 60);
			this->button3->TabIndex = 48;
			this->button3->Text = L"TEKSTURA 3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &My5okno::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(312, 525);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(91, 60);
			this->button4->TabIndex = 49;
			this->button4->Text = L"TEKSTURA 4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &My5okno::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(411, 525);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(91, 60);
			this->button5->TabIndex = 50;
			this->button5->Text = L"TEKSTURA 5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &My5okno::button5_Click);
			// 
			// Sterowanie
			// 
			this->Sterowanie->Controls->Add(this->checkBox3);
			this->Sterowanie->Controls->Add(this->panel1);
			this->Sterowanie->Controls->Add(this->label2);
			this->Sterowanie->Controls->Add(this->label3);
			this->Sterowanie->Controls->Add(this->checkBox1);
			this->Sterowanie->Controls->Add(this->checkBox2);
			this->Sterowanie->Controls->Add(this->radioButton4);
			this->Sterowanie->Controls->Add(this->radioButton3);
			this->Sterowanie->Location = System::Drawing::Point(520, 481);
			this->Sterowanie->Name = L"Sterowanie";
			this->Sterowanie->Size = System::Drawing::Size(243, 104);
			this->Sterowanie->TabIndex = 51;
			this->Sterowanie->TabStop = false;
			this->Sterowanie->Text = L"Sterowanie";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(9, 83);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(49, 17);
			this->checkBox3->TabIndex = 54;
			this->checkBox3->Text = L"Oœ Z";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(72, 21);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(65, 70);
			this->panel1->TabIndex = 53;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->fps2);
			this->groupBox1->Controls->Add(this->znaki);
			this->groupBox1->Controls->Add(this->wiersze);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(769, 481);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(201, 104);
			this->groupBox1->TabIndex = 45;
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
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox1->ForeColor = System::Drawing::Color::LimeGreen;
			this->textBox1->Location = System::Drawing::Point(9, 20);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(435, 83);
			this->textBox1->TabIndex = 52;
			this->textBox1->Text = L"Textura1 = SOIL_load_OGL_texture(\r\n\"Textura1.bmp\",\r\nSOIL_LOAD_AUTO,\r\nSOIL_CREATE_" 
				L"NEW_ID,\r\nSOIL_FLAG_INVERT_Y);\r\n";
			this->textBox1->WordWrap = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &My5okno::textBox1_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Location = System::Drawing::Point(520, 361);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(450, 114);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Funkcja ³aduj¹ca teksturê:";
			// 
			// My5okno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 602);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Sterowanie);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Codeview);
			this->Controls->Add(this->OpenGLPanel);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 640);
			this->MinimumSize = System::Drawing::Size(1000, 640);
			this->Name = L"My5okno";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"C++ & OpenGL: Nak³adanie tekstur + Przezroczystoœæ";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &My5okno::My5okno_FormClosed);
			this->Load += gcnew System::EventHandler(this, &My5okno::My5okno_Load);
			this->Sterowanie->ResumeLayout(false);
			this->Sterowanie->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fps2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->znaki))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wiersze))->EndInit();
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
		System::Void Render(int t2, int r, int s, int b)
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
			if (b==1)
			{
				glEnable(GL_BLEND);
				glDisable(GL_DEPTH_TEST);
			};			
			glEnable(GL_TEXTURE_2D);
			switch(t2)
			{
			case 1:
				glBindTexture(GL_TEXTURE_2D, Tekstura1);
				break;
			case 2:
				glBindTexture(GL_TEXTURE_2D, Tekstura2);
				break;
			case 3:
				glBindTexture(GL_TEXTURE_2D, Tekstura3);
				break;
			case 4:
				glBindTexture(GL_TEXTURE_2D, Tekstura4);
				break;
			case 5:
				glBindTexture(GL_TEXTURE_2D, Tekstura5);
				break;
			}
			
			glBegin(GL_QUADS);
				// Front Face
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
				// Back Face
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
				// Top Face
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
				// Bottom Face
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
				// Right face
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
				// Left Face
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
			glEnd();

			rtri+=0.2f;
			if (s==1)
			{
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
			};
			glDisable(GL_TEXTURE_2D);
			if (b==1)
			{
						glDisable(GL_BLEND);
						glEnable(GL_DEPTH_TEST);
			};
			glFlush();
			SwapBuffers( m_hDC );
		}
		System::Void tresc(int t2, int r, int s, int b)
		{
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
				Codeview->Text += "glEnable(GL_LIGHTING)\r\nglEnable(GL_LIGHT0);\r\n\r\n";
			}
			if (b==1){
				Codeview->Text += "glEnable(GL_BLEND);\r\nglDisable(GL_DEPTH_TEST);\r\n\r\n";
			}
			Codeview->Text += "glEnable(GL_TEXTURE_2D);\r\n\r\n";
			switch(t2)
			{
				case 1:
					Codeview->Text += "glBindTexture(GL_TEXTURE_2D, Tekstura1);\r\n\r\n";
					break;
				case 2:
					Codeview->Text += "glBindTexture(GL_TEXTURE_2D, Tekstura2);\r\n\r\n";
					break;
				case 3:
					Codeview->Text += "glBindTexture(GL_TEXTURE_2D, Tekstura3);\r\n\r\n";
					break;
				case 4:
					Codeview->Text += "glBindTexture(GL_TEXTURE_2D, Tekstura4);\r\n\r\n";
					break;
				case 5:
					Codeview->Text += "glBindTexture(GL_TEXTURE_2D, Tekstura5);\r\n\r\n";
					break;
			}
			
			Codeview->Text += " glBegin(GL_QUADS);\r\n  glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);\r\n  glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);\r\n  glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);\r\n  glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);\r\n\r\n  glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);\r\n  glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);\r\n  glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);\r\n  glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);\r\n\r\n  glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);\r\n  glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);\r\n  glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);\r\n  glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);\r\n\r\n  glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);\r\n  glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);\r\n  glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);\r\n  glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);\r\n\r\n  glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);\r\n  glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);\r\n  glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);\r\n  glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);\r\n\r\n  glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);\r\n  glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);\r\n  glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);\r\n  glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);\r\n glEnd();\r\n\r\n";
			Codeview->Text += "glDisable(GL_TEXTURE_2D);\r\n\r\n";
			if (b==1){
				Codeview->Text += "glDisable(GL_BLEND);\r\nglEnable(GL_DEPTH_TEST);;\r\n\r\n";
			}
			if (s==1){
				Codeview->Text += "\r\nglDisable(GL_LIGHTING)\r\nglDisable(GL_LIGHT0);\r\n\r\n";
			}
			if (r>0 && r<8){
				Codeview->Text += "\t\r\nrtri+=0.2f;";
			};
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
				int blend = 0;
				if (radioButton3->Checked){
					 blend =1;
				 }else if (radioButton4->Checked){
					blend =2;
				 }
				 // char path = openFileDialog1->FileName;
				Render(t, rotacja, swiatlo, blend);
				if ( t!=t2t || rotacja != rotacja2 || swiatlo != swiatlo2 || blend != blend2)
				{
				tresc(t, rotacja, swiatlo, blend);
				t2t=t; 
				rotacja2=rotacja; 
				swiatlo2=swiatlo; 
				blend2=blend;
				}
				wiersze->Value = Codeview->Lines->Length;
				znaki->Value = Codeview->Text->Length;
			 	float dd = FPS();
				fps2->Value =(System::Decimal)dd;
		
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 t=1;
			 textBox1->Text = L"Textura1 = SOIL_load_OGL_texture(\r\n\"Data/Textura1.bmp\",\r\nSOIL_LOAD_AUTO,\r\nSOIL_CREATE_" 
				L"NEW_ID,\r\nSOIL_FLAG_INVERT_Y);\r\n";
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			  t=2;
			  textBox1->Text = L"Textura2 = SOIL_load_OGL_texture(\r\n\"Data/Textura2.bmp\",\r\nSOIL_LOAD_AUTO,\r\nSOIL_CREATE_" 
				L"NEW_ID,\r\nSOIL_FLAG_INVERT_Y);\r\n";
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			  t=3;
			  textBox1->Text = L"Textura3 = SOIL_load_OGL_texture(\r\n\"Data/Textura3.png\",\r\nSOIL_LOAD_AUTO,\r\nSOIL_CREATE_" 
				L"NEW_ID,\r\nSOIL_FLAG_INVERT_Y);\r\n";
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			  t=4;
			  textBox1->Text = L"Textura4 = SOIL_load_OGL_texture(\r\n\"Data/Textura4.jpg\",\r\nSOIL_LOAD_AUTO,\r\nSOIL_CREATE_" 
				L"NEW_ID,\r\nSOIL_FLAG_INVERT_Y);\r\n";
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			  t=5;
			  textBox1->Text = L"Textura5 = SOIL_load_OGL_texture(\r\n\"Data/Textura5.tga\",\r\nSOIL_LOAD_AUTO,\r\nSOIL_CREATE_" 
				L"NEW_ID,\r\nSOIL_FLAG_INVERT_Y);\r\n";
		 }
private: System::Void My5okno_Load(System::Object^  sender, System::EventArgs^  e) {
			  t=1;
			 textBox1->Text = L"Textura1 = SOIL_load_OGL_texture(\r\n\"Data/Textura1.bmp\",\r\nSOIL_LOAD_AUTO,\r\nSOIL_CREATE_" 
				L"NEW_ID,\r\nSOIL_FLAG_INVERT_Y);\r\n";
		 }
private: System::Void My5okno_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Application::Restart();
		 }
};
}
