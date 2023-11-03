namespace DirectXProjekt
{
    partial class _6okno
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
            this.Codeview = new System.Windows.Forms.TextBox();
            this.DirectXPanel = new System.Windows.Forms.Panel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.fps2 = new System.Windows.Forms.NumericUpDown();
            this.znaki = new System.Windows.Forms.NumericUpDown();
            this.wiersze = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.Sterowanie = new System.Windows.Forms.GroupBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton4 = new System.Windows.Forms.RadioButton();
            this.panel2 = new System.Windows.Forms.Panel();
            this.radioButton5 = new System.Windows.Forms.RadioButton();
            this.radioButton6 = new System.Windows.Forms.RadioButton();
            this.label3 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).BeginInit();
            this.Sterowanie.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
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
            this.Codeview.Size = new System.Drawing.Size(450, 390);
            this.Codeview.TabIndex = 25;
            this.Codeview.WordWrap = false;
            this.Codeview.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Codeview_KeyDown);
            this.Codeview.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Codeview_KeyUp);
            // 
            // DirectXPanel
            // 
            this.DirectXPanel.Location = new System.Drawing.Point(10, 10);
            this.DirectXPanel.Name = "DirectXPanel";
            this.DirectXPanel.Size = new System.Drawing.Size(500, 500);
            this.DirectXPanel.TabIndex = 24;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.fps2);
            this.groupBox1.Controls.Add(this.znaki);
            this.groupBox1.Controls.Add(this.wiersze);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Location = new System.Drawing.Point(771, 406);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(201, 104);
            this.groupBox1.TabIndex = 54;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Informacje";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(20, 20);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(69, 13);
            this.label5.TabIndex = 6;
            this.label5.Text = "Ilość wierszy:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(20, 47);
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
            this.fps2.Location = new System.Drawing.Point(102, 72);
            this.fps2.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
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
            this.znaki.Location = new System.Drawing.Point(102, 47);
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
            this.wiersze.Location = new System.Drawing.Point(102, 18);
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
            3,
            0,
            0,
            0});
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(20, 76);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(30, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "FPS:";
            // 
            // Sterowanie
            // 
            this.Sterowanie.CausesValidation = false;
            this.Sterowanie.Controls.Add(this.panel3);
            this.Sterowanie.Controls.Add(this.panel2);
            this.Sterowanie.Controls.Add(this.panel1);
            this.Sterowanie.Location = new System.Drawing.Point(522, 406);
            this.Sterowanie.Name = "Sterowanie";
            this.Sterowanie.Size = new System.Drawing.Size(243, 104);
            this.Sterowanie.TabIndex = 55;
            this.Sterowanie.TabStop = false;
            this.Sterowanie.Text = "Sterowanie";
            // 
            // panel3
            // 
            this.panel3.CausesValidation = false;
            this.panel3.Controls.Add(this.label2);
            this.panel3.Controls.Add(this.radioButton3);
            this.panel3.Controls.Add(this.radioButton4);
            this.panel3.Location = new System.Drawing.Point(149, 21);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(88, 70);
            this.panel3.TabIndex = 55;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1, 4);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(86, 13);
            this.label2.TabIndex = 42;
            this.label2.Text = "Przezroczystość:";
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.CausesValidation = false;
            this.radioButton3.Location = new System.Drawing.Point(24, 25);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(41, 17);
            this.radioButton3.TabIndex = 43;
            this.radioButton3.Text = "ON";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radioButton3_KeyDown);
            this.radioButton3.KeyUp += new System.Windows.Forms.KeyEventHandler(this.radioButton3_KeyUp);
            // 
            // radioButton4
            // 
            this.radioButton4.AutoSize = true;
            this.radioButton4.CausesValidation = false;
            this.radioButton4.Checked = true;
            this.radioButton4.Location = new System.Drawing.Point(24, 50);
            this.radioButton4.Name = "radioButton4";
            this.radioButton4.Size = new System.Drawing.Size(45, 17);
            this.radioButton4.TabIndex = 44;
            this.radioButton4.TabStop = true;
            this.radioButton4.Text = "OFF";
            this.radioButton4.UseVisualStyleBackColor = true;
            this.radioButton4.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radioButton4_KeyDown);
            this.radioButton4.KeyUp += new System.Windows.Forms.KeyEventHandler(this.radioButton4_KeyUp);
            // 
            // panel2
            // 
            this.panel2.CausesValidation = false;
            this.panel2.Controls.Add(this.radioButton5);
            this.panel2.Controls.Add(this.radioButton6);
            this.panel2.Controls.Add(this.label3);
            this.panel2.Location = new System.Drawing.Point(4, 21);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(65, 70);
            this.panel2.TabIndex = 54;
            // 
            // radioButton5
            // 
            this.radioButton5.AutoSize = true;
            this.radioButton5.CausesValidation = false;
            this.radioButton5.Checked = true;
            this.radioButton5.Location = new System.Drawing.Point(15, 25);
            this.radioButton5.Name = "radioButton5";
            this.radioButton5.Size = new System.Drawing.Size(41, 17);
            this.radioButton5.TabIndex = 40;
            this.radioButton5.TabStop = true;
            this.radioButton5.Text = "ON";
            this.radioButton5.UseVisualStyleBackColor = true;
            this.radioButton5.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radioButton5_KeyDown);
            this.radioButton5.KeyUp += new System.Windows.Forms.KeyEventHandler(this.radioButton5_KeyUp);
            // 
            // radioButton6
            // 
            this.radioButton6.AutoSize = true;
            this.radioButton6.CausesValidation = false;
            this.radioButton6.Location = new System.Drawing.Point(15, 50);
            this.radioButton6.Name = "radioButton6";
            this.radioButton6.Size = new System.Drawing.Size(45, 17);
            this.radioButton6.TabIndex = 41;
            this.radioButton6.Text = "OFF";
            this.radioButton6.UseVisualStyleBackColor = true;
            this.radioButton6.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radioButton6_KeyDown);
            this.radioButton6.KeyUp += new System.Windows.Forms.KeyEventHandler(this.radioButton6_KeyUp);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 4);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 13);
            this.label3.TabIndex = 39;
            this.label3.Text = "Kolizje:";
            // 
            // panel1
            // 
            this.panel1.CausesValidation = false;
            this.panel1.Controls.Add(this.radioButton1);
            this.panel1.Controls.Add(this.radioButton2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(77, 21);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(65, 70);
            this.panel1.TabIndex = 53;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.CausesValidation = false;
            this.radioButton1.Location = new System.Drawing.Point(12, 25);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(41, 17);
            this.radioButton1.TabIndex = 40;
            this.radioButton1.Text = "ON";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radioButton1_KeyDown);
            this.radioButton1.KeyUp += new System.Windows.Forms.KeyEventHandler(this.radioButton1_KeyUp);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.CausesValidation = false;
            this.radioButton2.Checked = true;
            this.radioButton2.Location = new System.Drawing.Point(12, 50);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(45, 17);
            this.radioButton2.TabIndex = 41;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "OFF";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.KeyDown += new System.Windows.Forms.KeyEventHandler(this.radioButton2_KeyDown);
            this.radioButton2.KeyUp += new System.Windows.Forms.KeyEventHandler(this.radioButton2_KeyUp);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 4);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 13);
            this.label1.TabIndex = 39;
            this.label1.Text = "Światło:";
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.groupBox2.Controls.Add(this.label12);
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.ForeColor = System.Drawing.Color.Black;
            this.groupBox2.Location = new System.Drawing.Point(10, 516);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(962, 74);
            this.groupBox2.TabIndex = 56;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Poruszanie się";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label12.Location = new System.Drawing.Point(701, 29);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(250, 25);
            this.label12.TabIndex = 5;
            this.label12.Text = "E - obrót przez prawe ramię";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label11.Location = new System.Drawing.Point(461, 29);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(250, 25);
            this.label11.TabIndex = 4;
            this.label11.Text = "Q - obrót przez lewe ramię |";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label10.Location = new System.Drawing.Point(346, 29);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(125, 25);
            this.label10.TabIndex = 3;
            this.label10.Text = "S - w prawo |";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label9.Location = new System.Drawing.Point(244, 29);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(112, 25);
            this.label9.TabIndex = 2;
            this.label9.Text = "A - w lewo |";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label8.Location = new System.Drawing.Point(144, 29);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(110, 25);
            this.label8.TabIndex = 1;
            this.label8.Text = "S - do tyłu |";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label7.Location = new System.Drawing.Point(8, 29);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(146, 25);
            this.label7.TabIndex = 0;
            this.label7.Text = "W - do przodu |";
            // 
            // _6okno
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 602);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.Sterowanie);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Codeview);
            this.Controls.Add(this.DirectXPanel);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(1000, 640);
            this.MinimumSize = new System.Drawing.Size(1000, 640);
            this.Name = "_6okno";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "C# & DirectX: Kamera i poruszanie się po scenie 3D";
            this.Load += new System.EventHandler(this._6okno_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this._6okno_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this._6okno_KeyUp);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).EndInit();
            this.Sterowanie.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TextBox Codeview;
        private System.Windows.Forms.Panel DirectXPanel;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown fps2;
        private System.Windows.Forms.NumericUpDown znaki;
        private System.Windows.Forms.NumericUpDown wiersze;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox Sterowanie;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton4;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.RadioButton radioButton5;
        private System.Windows.Forms.RadioButton radioButton6;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
    }
}