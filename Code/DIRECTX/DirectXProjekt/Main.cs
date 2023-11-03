
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DirectXProjekt
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void Main_Load(object sender, EventArgs e)
        {

        }

        private void zamknijToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            _1okno okno1 = new _1okno();
            okno1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            _2okno okno2 = new _2okno();
            okno2.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            _3okno okno3 = new _3okno();
            okno3.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            _4okno okno4 = new _4okno();
            okno4.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            _5okno okno5 = new _5okno();
            okno5.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            _6okno okno6 = new _6okno();
            okno6.ShowDialog();
        }

        private void oProgramieToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _7okno okno7 = new _7okno();
            okno7.ShowDialog();
        }

    }
}
