namespace DirectXProjekt
{
    partial class _3okno
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
            this.Sterowanie = new System.Windows.Forms.GroupBox();
            this.checkBox3 = new System.Windows.Forms.CheckBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.color1a = new System.Windows.Forms.NumericUpDown();
            this.color1c = new System.Windows.Forms.NumericUpDown();
            this.color1b = new System.Windows.Forms.NumericUpDown();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.label3 = new System.Windows.Forms.Label();
            this.czajnik = new System.Windows.Forms.Button();
            this.czworoscian = new System.Windows.Forms.Button();
            this.torus = new System.Windows.Forms.Button();
            this.stozek = new System.Windows.Forms.Button();
            this.szescian = new System.Windows.Forms.Button();
            this.sfera = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).BeginInit();
            this.Sterowanie.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.color1a)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1c)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1b)).BeginInit();
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
            this.groupBox1.TabIndex = 18;
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
            this.Codeview.TabIndex = 17;
            this.Codeview.WordWrap = false;
            // 
            // DirectXPanel
            // 
            this.DirectXPanel.Location = new System.Drawing.Point(10, 10);
            this.DirectXPanel.Name = "DirectXPanel";
            this.DirectXPanel.Size = new System.Drawing.Size(500, 500);
            this.DirectXPanel.TabIndex = 16;
            this.DirectXPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.DirectXPanel_Paint);
            // 
            // Sterowanie
            // 
            this.Sterowanie.Controls.Add(this.checkBox3);
            this.Sterowanie.Controls.Add(this.radioButton2);
            this.Sterowanie.Controls.Add(this.radioButton1);
            this.Sterowanie.Controls.Add(this.label1);
            this.Sterowanie.Controls.Add(this.label7);
            this.Sterowanie.Controls.Add(this.color1a);
            this.Sterowanie.Controls.Add(this.color1c);
            this.Sterowanie.Controls.Add(this.color1b);
            this.Sterowanie.Controls.Add(this.checkBox2);
            this.Sterowanie.Controls.Add(this.checkBox1);
            this.Sterowanie.Controls.Add(this.label3);
            this.Sterowanie.Location = new System.Drawing.Point(522, 427);
            this.Sterowanie.Name = "Sterowanie";
            this.Sterowanie.Size = new System.Drawing.Size(450, 94);
            this.Sterowanie.TabIndex = 26;
            this.Sterowanie.TabStop = false;
            this.Sterowanie.Text = "Sterowanie";
            // 
            // checkBox3
            // 
            this.checkBox3.AutoSize = true;
            this.checkBox3.Location = new System.Drawing.Point(194, 23);
            this.checkBox3.Name = "checkBox3";
            this.checkBox3.Size = new System.Drawing.Size(49, 17);
            this.checkBox3.TabIndex = 28;
            this.checkBox3.Text = "Oś Z";
            this.checkBox3.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(353, 50);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(45, 17);
            this.radioButton2.TabIndex = 27;
            this.radioButton2.Text = "OFF";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(353, 22);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(41, 17);
            this.radioButton1.TabIndex = 26;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "ON";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(299, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 13);
            this.label1.TabIndex = 25;
            this.label1.Text = "Światło:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(18, 60);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(34, 13);
            this.label7.TabIndex = 24;
            this.label7.Text = "Kolor:";
            // 
            // color1a
            // 
            this.color1a.Location = new System.Drawing.Point(72, 58);
            this.color1a.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.color1a.Name = "color1a";
            this.color1a.Size = new System.Drawing.Size(50, 20);
            this.color1a.TabIndex = 23;
            // 
            // color1c
            // 
            this.color1c.Location = new System.Drawing.Point(194, 58);
            this.color1c.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.color1c.Name = "color1c";
            this.color1c.Size = new System.Drawing.Size(50, 20);
            this.color1c.TabIndex = 21;
            // 
            // color1b
            // 
            this.color1b.Location = new System.Drawing.Point(133, 58);
            this.color1b.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.color1b.Name = "color1b";
            this.color1b.Size = new System.Drawing.Size(50, 20);
            this.color1b.TabIndex = 22;
            // 
            // checkBox2
            // 
            this.checkBox2.AutoSize = true;
            this.checkBox2.Location = new System.Drawing.Point(133, 22);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(49, 17);
            this.checkBox2.TabIndex = 15;
            this.checkBox2.Text = "Oś Y";
            this.checkBox2.UseVisualStyleBackColor = true;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(72, 22);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(49, 17);
            this.checkBox1.TabIndex = 14;
            this.checkBox1.Text = "Oś X";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(10, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 13;
            this.label3.Text = "Rotacja:";
            // 
            // czajnik
            // 
            this.czajnik.Location = new System.Drawing.Point(499, 531);
            this.czajnik.Name = "czajnik";
            this.czajnik.Size = new System.Drawing.Size(80, 60);
            this.czajnik.TabIndex = 41;
            this.czajnik.Text = "CZAJNIK";
            this.czajnik.UseVisualStyleBackColor = true;
            this.czajnik.Click += new System.EventHandler(this.czajnik_Click);
            // 
            // czworoscian
            // 
            this.czworoscian.AllowDrop = true;
            this.czworoscian.Location = new System.Drawing.Point(379, 531);
            this.czworoscian.Name = "czworoscian";
            this.czworoscian.Size = new System.Drawing.Size(104, 60);
            this.czworoscian.TabIndex = 39;
            this.czworoscian.Text = "CZWOROŚCIAN";
            this.czworoscian.UseVisualStyleBackColor = true;
            this.czworoscian.Click += new System.EventHandler(this.czworoscian_Click);
            // 
            // torus
            // 
            this.torus.Location = new System.Drawing.Point(289, 531);
            this.torus.Name = "torus";
            this.torus.Size = new System.Drawing.Size(74, 60);
            this.torus.TabIndex = 36;
            this.torus.Text = "TORUS";
            this.torus.UseVisualStyleBackColor = true;
            this.torus.Click += new System.EventHandler(this.torus_Click);
            // 
            // stozek
            // 
            this.stozek.Location = new System.Drawing.Point(201, 531);
            this.stozek.Name = "stozek";
            this.stozek.Size = new System.Drawing.Size(72, 60);
            this.stozek.TabIndex = 35;
            this.stozek.Text = "STOŻEK";
            this.stozek.UseVisualStyleBackColor = true;
            this.stozek.Click += new System.EventHandler(this.stozek_Click);
            // 
            // szescian
            // 
            this.szescian.Location = new System.Drawing.Point(107, 531);
            this.szescian.Name = "szescian";
            this.szescian.Size = new System.Drawing.Size(78, 60);
            this.szescian.TabIndex = 38;
            this.szescian.Text = "SZEŚCIAN";
            this.szescian.UseVisualStyleBackColor = true;
            this.szescian.Click += new System.EventHandler(this.szescian_Click);
            // 
            // sfera
            // 
            this.sfera.Location = new System.Drawing.Point(15, 531);
            this.sfera.Name = "sfera";
            this.sfera.Size = new System.Drawing.Size(76, 60);
            this.sfera.TabIndex = 37;
            this.sfera.Text = "SFERA";
            this.sfera.UseVisualStyleBackColor = true;
            this.sfera.Click += new System.EventHandler(this.sfera_Click);
            // 
            // _3okno
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 602);
            this.Controls.Add(this.czajnik);
            this.Controls.Add(this.czworoscian);
            this.Controls.Add(this.torus);
            this.Controls.Add(this.stozek);
            this.Controls.Add(this.szescian);
            this.Controls.Add(this.sfera);
            this.Controls.Add(this.Sterowanie);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Codeview);
            this.Controls.Add(this.DirectXPanel);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(1000, 640);
            this.MinimumSize = new System.Drawing.Size(1000, 640);
            this.Name = "_3okno";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "C# & DirectX: Obiekty 3D (MESH) + Światło";
            this.Load += new System.EventHandler(this._3okno_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).EndInit();
            this.Sterowanie.ResumeLayout(false);
            this.Sterowanie.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.color1a)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1c)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.color1b)).EndInit();
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
        private System.Windows.Forms.GroupBox Sterowanie;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown color1a;
        private System.Windows.Forms.NumericUpDown color1c;
        private System.Windows.Forms.NumericUpDown color1b;
        private System.Windows.Forms.CheckBox checkBox2;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox checkBox3;
        private System.Windows.Forms.Button czajnik;
        private System.Windows.Forms.Button czworoscian;
        private System.Windows.Forms.Button torus;
        private System.Windows.Forms.Button stozek;
        private System.Windows.Forms.Button szescian;
        private System.Windows.Forms.Button sfera;
    }
}