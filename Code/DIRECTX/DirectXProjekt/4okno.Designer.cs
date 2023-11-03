namespace DirectXProjekt
{
    partial class _4okno
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.fps2 = new System.Windows.Forms.NumericUpDown();
            this.znaki = new System.Windows.Forms.NumericUpDown();
            this.wiersze = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.Codeview = new System.Windows.Forms.TextBox();
            this.DirectXPanel = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.minus = new System.Windows.Forms.Button();
            this.plus = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.button1 = new System.Windows.Forms.Button();
            this.left = new System.Windows.Forms.Button();
            this.right = new System.Windows.Forms.Button();
            this.down = new System.Windows.Forms.Button();
            this.up = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.label7 = new System.Windows.Forms.Label();
            this.color1a = new System.Windows.Forms.NumericUpDown();
            this.color1c = new System.Windows.Forms.NumericUpDown();
            this.color1b = new System.Windows.Forms.NumericUpDown();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.Sterowanie = new System.Windows.Forms.GroupBox();
            this.label8 = new System.Windows.Forms.Label();
            this.katz = new System.Windows.Forms.NumericUpDown();
            this.checkBox3 = new System.Windows.Forms.CheckBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.katy = new System.Windows.Forms.NumericUpDown();
            this.katx = new System.Windows.Forms.NumericUpDown();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.czajnik = new System.Windows.Forms.Button();
            this.szescian = new System.Windows.Forms.Button();
            this.sfera = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.color1a)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1c)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1b)).BeginInit();
            this.Sterowanie.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.katz)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.katy)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.katx)).BeginInit();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.fps2);
            this.groupBox1.Controls.Add(this.znaki);
            this.groupBox1.Controls.Add(this.wiersze);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Location = new System.Drawing.Point(522, 366);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(450, 55);
            this.groupBox1.TabIndex = 21;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Informacje";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(18, 22);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(69, 13);
            this.label5.TabIndex = 6;
            this.label5.Text = "Ilość wierszy:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(171, 22);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(72, 13);
            this.label6.TabIndex = 6;
            this.label6.Text = "Ilość znaków:";
            // 
            // fps2
            // 
            this.fps2.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.fps2.DecimalPlaces = 4;
            this.fps2.Enabled = false;
            this.fps2.ForeColor = System.Drawing.Color.Black;
            this.fps2.InterceptArrowKeys = false;
            this.fps2.Location = new System.Drawing.Point(365, 20);
            this.fps2.Name = "fps2";
            this.fps2.ReadOnly = true;
            this.fps2.Size = new System.Drawing.Size(68, 20);
            this.fps2.TabIndex = 4;
            this.fps2.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // znaki
            // 
            this.znaki.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.znaki.Enabled = false;
            this.znaki.ForeColor = System.Drawing.Color.Black;
            this.znaki.InterceptArrowKeys = false;
            this.znaki.Location = new System.Drawing.Point(251, 20);
            this.znaki.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.znaki.Name = "znaki";
            this.znaki.ReadOnly = true;
            this.znaki.Size = new System.Drawing.Size(68, 20);
            this.znaki.TabIndex = 4;
            this.znaki.Value = new decimal(new int[] {
            96,
            0,
            0,
            0});
            // 
            // wiersze
            // 
            this.wiersze.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.wiersze.Enabled = false;
            this.wiersze.ForeColor = System.Drawing.Color.Black;
            this.wiersze.InterceptArrowKeys = false;
            this.wiersze.Location = new System.Drawing.Point(95, 20);
            this.wiersze.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.wiersze.Name = "wiersze";
            this.wiersze.ReadOnly = true;
            this.wiersze.Size = new System.Drawing.Size(68, 20);
            this.wiersze.TabIndex = 4;
            this.wiersze.Value = new decimal(new int[] {
            30,
            0,
            0,
            0});
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(327, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(30, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "FPS:";
            // 
            // Codeview
            // 
            this.Codeview.BackColor = System.Drawing.Color.Black;
            this.Codeview.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.Codeview.ForeColor = System.Drawing.Color.LimeGreen;
            this.Codeview.Location = new System.Drawing.Point(522, 10);
            this.Codeview.Multiline = true;
            this.Codeview.Name = "Codeview";
            this.Codeview.ReadOnly = true;
            this.Codeview.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.Codeview.Size = new System.Drawing.Size(450, 350);
            this.Codeview.TabIndex = 20;
            this.Codeview.WordWrap = false;
            // 
            // DirectXPanel
            // 
            this.DirectXPanel.Location = new System.Drawing.Point(10, 10);
            this.DirectXPanel.Name = "DirectXPanel";
            this.DirectXPanel.Size = new System.Drawing.Size(500, 500);
            this.DirectXPanel.TabIndex = 19;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Controls.Add(this.label10);
            this.groupBox3.Controls.Add(this.label9);
            this.groupBox3.Controls.Add(this.button7);
            this.groupBox3.Controls.Add(this.button3);
            this.groupBox3.Controls.Add(this.button6);
            this.groupBox3.Controls.Add(this.button5);
            this.groupBox3.Controls.Add(this.button4);
            this.groupBox3.Controls.Add(this.button2);
            this.groupBox3.Location = new System.Drawing.Point(852, 427);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(120, 119);
            this.groupBox3.TabIndex = 55;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Skalowanie";
            // 
            // minus
            // 
            this.minus.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.minus.Location = new System.Drawing.Point(78, 28);
            this.minus.Name = "minus";
            this.minus.Size = new System.Drawing.Size(25, 25);
            this.minus.TabIndex = 4;
            this.minus.Text = "-";
            this.minus.UseVisualStyleBackColor = true;
            this.minus.Click += new System.EventHandler(this.minus_Click);
            // 
            // plus
            // 
            this.plus.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.plus.Location = new System.Drawing.Point(16, 81);
            this.plus.Name = "plus";
            this.plus.Size = new System.Drawing.Size(25, 25);
            this.plus.TabIndex = 0;
            this.plus.Text = "+";
            this.plus.UseVisualStyleBackColor = true;
            this.plus.Click += new System.EventHandler(this.plus_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.plus);
            this.groupBox2.Controls.Add(this.minus);
            this.groupBox2.Controls.Add(this.button1);
            this.groupBox2.Controls.Add(this.left);
            this.groupBox2.Controls.Add(this.right);
            this.groupBox2.Controls.Add(this.down);
            this.groupBox2.Controls.Add(this.up);
            this.groupBox2.Location = new System.Drawing.Point(726, 427);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(119, 119);
            this.groupBox2.TabIndex = 54;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Translacja";
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button1.Location = new System.Drawing.Point(47, 54);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(25, 25);
            this.button1.TabIndex = 7;
            this.button1.Text = "X";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // left
            // 
            this.left.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.left.Location = new System.Drawing.Point(6, 54);
            this.left.Name = "left";
            this.left.Size = new System.Drawing.Size(35, 25);
            this.left.TabIndex = 6;
            this.left.Text = "←";
            this.left.UseVisualStyleBackColor = true;
            this.left.Click += new System.EventHandler(this.left_Click);
            // 
            // right
            // 
            this.right.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.right.Location = new System.Drawing.Point(77, 54);
            this.right.Name = "right";
            this.right.Size = new System.Drawing.Size(35, 25);
            this.right.TabIndex = 5;
            this.right.Text = "→";
            this.right.UseVisualStyleBackColor = true;
            this.right.Click += new System.EventHandler(this.right_Click);
            // 
            // down
            // 
            this.down.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.down.Location = new System.Drawing.Point(47, 80);
            this.down.Name = "down";
            this.down.Size = new System.Drawing.Size(25, 35);
            this.down.TabIndex = 4;
            this.down.Text = "↓";
            this.down.UseVisualStyleBackColor = true;
            this.down.Click += new System.EventHandler(this.down_Click);
            // 
            // up
            // 
            this.up.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.up.Location = new System.Drawing.Point(47, 18);
            this.up.Name = "up";
            this.up.Size = new System.Drawing.Size(25, 35);
            this.up.TabIndex = 0;
            this.up.Text = "↑";
            this.up.UseVisualStyleBackColor = true;
            this.up.Click += new System.EventHandler(this.up_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Controls.Add(this.color1a);
            this.groupBox4.Controls.Add(this.color1c);
            this.groupBox4.Controls.Add(this.color1b);
            this.groupBox4.Controls.Add(this.radioButton2);
            this.groupBox4.Controls.Add(this.radioButton1);
            this.groupBox4.Controls.Add(this.label1);
            this.groupBox4.Location = new System.Drawing.Point(522, 548);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(450, 47);
            this.groupBox4.TabIndex = 53;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Dodatki:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(22, 21);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(34, 13);
            this.label7.TabIndex = 52;
            this.label7.Text = "Kolor:";
            // 
            // color1a
            // 
            this.color1a.Location = new System.Drawing.Point(76, 18);
            this.color1a.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.color1a.Name = "color1a";
            this.color1a.Size = new System.Drawing.Size(50, 20);
            this.color1a.TabIndex = 51;
            this.color1a.Value = new decimal(new int[] {
            255,
            0,
            0,
            0});
            // 
            // color1c
            // 
            this.color1c.Location = new System.Drawing.Point(198, 18);
            this.color1c.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.color1c.Name = "color1c";
            this.color1c.Size = new System.Drawing.Size(50, 20);
            this.color1c.TabIndex = 49;
            this.color1c.Value = new decimal(new int[] {
            255,
            0,
            0,
            0});
            // 
            // color1b
            // 
            this.color1b.Location = new System.Drawing.Point(137, 18);
            this.color1b.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.color1b.Name = "color1b";
            this.color1b.Size = new System.Drawing.Size(50, 20);
            this.color1b.TabIndex = 50;
            this.color1b.Value = new decimal(new int[] {
            255,
            0,
            0,
            0});
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(384, 19);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(45, 17);
            this.radioButton2.TabIndex = 48;
            this.radioButton2.Text = "OFF";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(337, 20);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(41, 17);
            this.radioButton1.TabIndex = 47;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "ON";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(283, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 13);
            this.label1.TabIndex = 46;
            this.label1.Text = "Światło:";
            // 
            // Sterowanie
            // 
            this.Sterowanie.Controls.Add(this.label8);
            this.Sterowanie.Controls.Add(this.katz);
            this.Sterowanie.Controls.Add(this.checkBox3);
            this.Sterowanie.Controls.Add(this.label3);
            this.Sterowanie.Controls.Add(this.label2);
            this.Sterowanie.Controls.Add(this.katy);
            this.Sterowanie.Controls.Add(this.katx);
            this.Sterowanie.Controls.Add(this.checkBox2);
            this.Sterowanie.Controls.Add(this.checkBox1);
            this.Sterowanie.Location = new System.Drawing.Point(522, 427);
            this.Sterowanie.Name = "Sterowanie";
            this.Sterowanie.Size = new System.Drawing.Size(198, 119);
            this.Sterowanie.TabIndex = 52;
            this.Sterowanie.TabStop = false;
            this.Sterowanie.Text = "Rotacja";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(57, 90);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(75, 13);
            this.label8.TabIndex = 40;
            this.label8.Text = "Kąt obrotu (Z):";
            // 
            // katz
            // 
            this.katz.Location = new System.Drawing.Point(136, 88);
            this.katz.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.katz.Name = "katz";
            this.katz.Size = new System.Drawing.Size(51, 20);
            this.katz.TabIndex = 39;
            this.katz.ValueChanged += new System.EventHandler(this.katz_ValueChanged);
            // 
            // checkBox3
            // 
            this.checkBox3.AutoSize = true;
            this.checkBox3.Location = new System.Drawing.Point(7, 89);
            this.checkBox3.Name = "checkBox3";
            this.checkBox3.Size = new System.Drawing.Size(49, 17);
            this.checkBox3.TabIndex = 38;
            this.checkBox3.Text = "Oś Z";
            this.checkBox3.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(57, 21);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 13);
            this.label3.TabIndex = 37;
            this.label3.Text = "Kąt obrotu (X):";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(57, 54);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(75, 13);
            this.label2.TabIndex = 35;
            this.label2.Text = "Kąt obrotu (Y):";
            // 
            // katy
            // 
            this.katy.Location = new System.Drawing.Point(136, 19);
            this.katy.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.katy.Name = "katy";
            this.katy.Size = new System.Drawing.Size(51, 20);
            this.katy.TabIndex = 36;
            // 
            // katx
            // 
            this.katx.Location = new System.Drawing.Point(136, 52);
            this.katx.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.katx.Name = "katx";
            this.katx.Size = new System.Drawing.Size(51, 20);
            this.katx.TabIndex = 34;
            // 
            // checkBox2
            // 
            this.checkBox2.AutoSize = true;
            this.checkBox2.Location = new System.Drawing.Point(7, 54);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(49, 17);
            this.checkBox2.TabIndex = 33;
            this.checkBox2.Text = "Oś Y";
            this.checkBox2.UseVisualStyleBackColor = true;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(7, 19);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(49, 17);
            this.checkBox1.TabIndex = 14;
            this.checkBox1.Text = "Oś X";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // czajnik
            // 
            this.czajnik.Location = new System.Drawing.Point(349, 526);
            this.czajnik.Name = "czajnik";
            this.czajnik.Size = new System.Drawing.Size(80, 60);
            this.czajnik.TabIndex = 58;
            this.czajnik.Text = "CZAJNIK";
            this.czajnik.UseVisualStyleBackColor = true;
            this.czajnik.Click += new System.EventHandler(this.czajnik_Click);
            // 
            // szescian
            // 
            this.szescian.Location = new System.Drawing.Point(201, 526);
            this.szescian.Name = "szescian";
            this.szescian.Size = new System.Drawing.Size(124, 60);
            this.szescian.TabIndex = 57;
            this.szescian.Text = "SZEŚCIAN";
            this.szescian.UseVisualStyleBackColor = true;
            this.szescian.Click += new System.EventHandler(this.szescian_Click);
            // 
            // sfera
            // 
            this.sfera.Location = new System.Drawing.Point(92, 526);
            this.sfera.Name = "sfera";
            this.sfera.Size = new System.Drawing.Size(85, 60);
            this.sfera.TabIndex = 56;
            this.sfera.Text = "TRÓJKĄT";
            this.sfera.UseVisualStyleBackColor = true;
            this.sfera.Click += new System.EventHandler(this.sfera_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button2.Location = new System.Drawing.Point(79, 54);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(35, 25);
            this.button2.TabIndex = 0;
            this.button2.Text = "+";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button3.Location = new System.Drawing.Point(79, 23);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(35, 25);
            this.button3.TabIndex = 0;
            this.button3.Text = "+";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button4.Location = new System.Drawing.Point(79, 85);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(35, 25);
            this.button4.TabIndex = 0;
            this.button4.Text = "+";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button5.Location = new System.Drawing.Point(7, 54);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(35, 25);
            this.button5.TabIndex = 0;
            this.button5.Text = "-";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button6.Location = new System.Drawing.Point(7, 85);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(35, 25);
            this.button6.TabIndex = 0;
            this.button6.Text = "-";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button7
            // 
            this.button7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button7.Location = new System.Drawing.Point(7, 23);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(35, 25);
            this.button7.TabIndex = 0;
            this.button7.Text = "-";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(46, 29);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(30, 13);
            this.label9.TabIndex = 1;
            this.label9.Text = "Oś X";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(46, 60);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(30, 13);
            this.label10.TabIndex = 1;
            this.label10.Text = "Oś Y";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(46, 91);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(30, 13);
            this.label11.TabIndex = 1;
            this.label11.Text = "Oś Z";
            // 
            // _4okno
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 602);
            this.Controls.Add(this.czajnik);
            this.Controls.Add(this.szescian);
            this.Controls.Add(this.sfera);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.Sterowanie);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Codeview);
            this.Controls.Add(this.DirectXPanel);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(1000, 640);
            this.MinimumSize = new System.Drawing.Size(1000, 640);
            this.Name = "_4okno";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "C# & DirectX: Przekształcenia";
            this.Load += new System.EventHandler(this._4okno_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.color1a)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1c)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1b)).EndInit();
            this.Sterowanie.ResumeLayout(false);
            this.Sterowanie.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.katz)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.katy)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.katx)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown fps2;
        private System.Windows.Forms.NumericUpDown znaki;
        private System.Windows.Forms.NumericUpDown wiersze;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox Codeview;
        private System.Windows.Forms.Panel DirectXPanel;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button minus;
        private System.Windows.Forms.Button plus;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button left;
        private System.Windows.Forms.Button right;
        private System.Windows.Forms.Button down;
        private System.Windows.Forms.Button up;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown color1a;
        private System.Windows.Forms.NumericUpDown color1c;
        private System.Windows.Forms.NumericUpDown color1b;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox Sterowanie;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.NumericUpDown katz;
        private System.Windows.Forms.CheckBox checkBox3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown katy;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown katx;
        private System.Windows.Forms.CheckBox checkBox2;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.Button czajnik;
        private System.Windows.Forms.Button szescian;
        private System.Windows.Forms.Button sfera;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button2;
    }
}