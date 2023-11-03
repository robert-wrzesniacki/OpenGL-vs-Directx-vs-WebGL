namespace DirectXProjekt
{
    partial class _1okno
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
            this.DirectXPanel = new System.Windows.Forms.Panel();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.Codeview = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.fps2 = new System.Windows.Forms.NumericUpDown();
            this.znaki = new System.Windows.Forms.NumericUpDown();
            this.wiersze = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.Sterowanie = new System.Windows.Forms.GroupBox();
            this.checkBox3 = new System.Windows.Forms.CheckBox();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.liczba2 = new System.Windows.Forms.NumericUpDown();
            this.liczba1 = new System.Windows.Forms.NumericUpDown();
            this.punkty = new System.Windows.Forms.Button();
            this.linie = new System.Windows.Forms.Button();
            this.linie2 = new System.Windows.Forms.Button();
            this.trojkaty = new System.Windows.Forms.Button();
            this.trojkaty3 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).BeginInit();
            this.Sterowanie.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.liczba2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.liczba1)).BeginInit();
            this.SuspendLayout();
            // 
            // DirectXPanel
            // 
            this.DirectXPanel.Location = new System.Drawing.Point(10, 10);
            this.DirectXPanel.Name = "DirectXPanel";
            this.DirectXPanel.Size = new System.Drawing.Size(500, 500);
            this.DirectXPanel.TabIndex = 0;
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
            this.Codeview.Size = new System.Drawing.Size(450, 350);
            this.Codeview.TabIndex = 9;
            this.Codeview.WordWrap = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.fps2);
            this.groupBox1.Controls.Add(this.znaki);
            this.groupBox1.Controls.Add(this.wiersze);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Location = new System.Drawing.Point(777, 370);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(195, 140);
            this.groupBox1.TabIndex = 22;
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
            this.label6.Location = new System.Drawing.Point(20, 55);
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
            this.fps2.Location = new System.Drawing.Point(102, 88);
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
            this.znaki.Location = new System.Drawing.Point(102, 55);
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
            this.label4.Location = new System.Drawing.Point(20, 92);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(30, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "FPS:";
            // 
            // Sterowanie
            // 
            this.Sterowanie.Controls.Add(this.checkBox3);
            this.Sterowanie.Controls.Add(this.checkBox2);
            this.Sterowanie.Controls.Add(this.checkBox1);
            this.Sterowanie.Controls.Add(this.label3);
            this.Sterowanie.Controls.Add(this.label2);
            this.Sterowanie.Controls.Add(this.label1);
            this.Sterowanie.Controls.Add(this.liczba2);
            this.Sterowanie.Controls.Add(this.liczba1);
            this.Sterowanie.Location = new System.Drawing.Point(522, 370);
            this.Sterowanie.Name = "Sterowanie";
            this.Sterowanie.Size = new System.Drawing.Size(251, 140);
            this.Sterowanie.TabIndex = 21;
            this.Sterowanie.TabStop = false;
            this.Sterowanie.Text = "Sterowanie";
            // 
            // checkBox3
            // 
            this.checkBox3.AutoSize = true;
            this.checkBox3.Location = new System.Drawing.Point(178, 90);
            this.checkBox3.Name = "checkBox3";
            this.checkBox3.Size = new System.Drawing.Size(49, 17);
            this.checkBox3.TabIndex = 4;
            this.checkBox3.Text = "Oś Z";
            this.checkBox3.UseVisualStyleBackColor = true;
            // 
            // checkBox2
            // 
            this.checkBox2.AutoSize = true;
            this.checkBox2.Location = new System.Drawing.Point(123, 90);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(49, 17);
            this.checkBox2.TabIndex = 3;
            this.checkBox2.Text = "Oś Y";
            this.checkBox2.UseVisualStyleBackColor = true;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(68, 90);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(49, 17);
            this.checkBox1.TabIndex = 3;
            this.checkBox1.Text = "Oś X";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(5, 90);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Rotacja:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(5, 55);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Wielkość punktów:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(5, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(76, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Ilość punktów:";
            // 
            // liczba2
            // 
            this.liczba2.DecimalPlaces = 1;
            this.liczba2.Location = new System.Drawing.Point(110, 53);
            this.liczba2.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.liczba2.Name = "liczba2";
            this.liczba2.Size = new System.Drawing.Size(120, 20);
            this.liczba2.TabIndex = 0;
            this.liczba2.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // liczba1
            // 
            this.liczba1.Location = new System.Drawing.Point(110, 18);
            this.liczba1.Maximum = new decimal(new int[] {
            17,
            0,
            0,
            0});
            this.liczba1.Name = "liczba1";
            this.liczba1.Size = new System.Drawing.Size(120, 20);
            this.liczba1.TabIndex = 0;
            this.liczba1.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // punkty
            // 
            this.punkty.Location = new System.Drawing.Point(23, 525);
            this.punkty.Name = "punkty";
            this.punkty.Size = new System.Drawing.Size(92, 65);
            this.punkty.TabIndex = 23;
            this.punkty.Text = "POINT LIST";
            this.punkty.UseVisualStyleBackColor = true;
            this.punkty.Click += new System.EventHandler(this.punkty_Click);
            // 
            // linie
            // 
            this.linie.Location = new System.Drawing.Point(179, 525);
            this.linie.Name = "linie";
            this.linie.Size = new System.Drawing.Size(92, 65);
            this.linie.TabIndex = 24;
            this.linie.Text = "LINE LIST";
            this.linie.UseVisualStyleBackColor = true;
            this.linie.Click += new System.EventHandler(this.linie_Click);
            // 
            // linie2
            // 
            this.linie2.Location = new System.Drawing.Point(335, 525);
            this.linie2.Name = "linie2";
            this.linie2.Size = new System.Drawing.Size(92, 65);
            this.linie2.TabIndex = 25;
            this.linie2.Text = "LINE STRIP";
            this.linie2.UseVisualStyleBackColor = true;
            this.linie2.Click += new System.EventHandler(this.linie2_Click);
            // 
            // trojkaty
            // 
            this.trojkaty.Location = new System.Drawing.Point(491, 525);
            this.trojkaty.Name = "trojkaty";
            this.trojkaty.Size = new System.Drawing.Size(104, 65);
            this.trojkaty.TabIndex = 26;
            this.trojkaty.Text = "TRIANGLE LIST";
            this.trojkaty.UseVisualStyleBackColor = true;
            this.trojkaty.Click += new System.EventHandler(this.trojkaty_Click);
            // 
            // trojkaty3
            // 
            this.trojkaty3.Location = new System.Drawing.Point(841, 525);
            this.trojkaty3.Name = "trojkaty3";
            this.trojkaty3.Size = new System.Drawing.Size(118, 65);
            this.trojkaty3.TabIndex = 27;
            this.trojkaty3.Text = "TRIANGLE STRIP";
            this.trojkaty3.UseVisualStyleBackColor = true;
            this.trojkaty3.Click += new System.EventHandler(this.trojkaty3_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(659, 525);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(118, 65);
            this.button1.TabIndex = 28;
            this.button1.Text = "TRIANGLE FUN";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // _1okno
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 602);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.trojkaty3);
            this.Controls.Add(this.trojkaty);
            this.Controls.Add(this.linie2);
            this.Controls.Add(this.linie);
            this.Controls.Add(this.punkty);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Sterowanie);
            this.Controls.Add(this.Codeview);
            this.Controls.Add(this.DirectXPanel);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(1000, 640);
            this.MinimumSize = new System.Drawing.Size(1000, 640);
            this.Name = "_1okno";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "C# & DirectX: Podstawowe elementy grafiki";
            this.Load += new System.EventHandler(this._1okno_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fps2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.znaki)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.wiersze)).EndInit();
            this.Sterowanie.ResumeLayout(false);
            this.Sterowanie.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.liczba2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.liczba1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel DirectXPanel;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TextBox Codeview;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown fps2;
        private System.Windows.Forms.NumericUpDown znaki;
        private System.Windows.Forms.NumericUpDown wiersze;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox Sterowanie;
        private System.Windows.Forms.CheckBox checkBox2;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown liczba2;
        private System.Windows.Forms.NumericUpDown liczba1;
        private System.Windows.Forms.CheckBox checkBox3;
        private System.Windows.Forms.Button punkty;
        private System.Windows.Forms.Button linie;
        private System.Windows.Forms.Button linie2;
        private System.Windows.Forms.Button trojkaty;
        private System.Windows.Forms.Button trojkaty3;
        private System.Windows.Forms.Button button1;
    }
}