using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;


namespace DirectXProjekt
{
    public partial class _1okno : Form
    {
        private Device device;
        private CustomVertex.PositionColored[] point;
        private CustomVertex.PositionColored[] line;
        private CustomVertex.PositionColored[] lines;
        private CustomVertex.PositionColored[] triangle;
        private CustomVertex.PositionColored[] triangles;
        private CustomVertex.PositionColored[] trianglef;
        private float angle = 0f;
        int wybor;
        int frameCount;
        float fps;
        long currentTime, previousTime;

        int rotacja2, wybor2, ilosc2;
        float wielkosc2;

        public _1okno()
        {
            InitializeComponent();
            InitializeDevice();
            CameraPositioning();
            VertexDeclaration();
        }
        public void InitializeDevice()
        {
            PresentParameters presentParams = new PresentParameters();
            presentParams.Windowed = true;
            presentParams.SwapEffect = SwapEffect.Discard;
            presentParams.AutoDepthStencilFormat = DepthFormat.D16;
            presentParams.EnableAutoDepthStencil = true;
            device = new Device(0, DeviceType.Hardware, DirectXPanel, CreateFlags.SoftwareVertexProcessing, presentParams);
            frameCount = 0;
            fps = 0;
            currentTime = 0;
            previousTime = 0;
        }
        private void CameraPositioning()
        {
            device.Transform.Projection = Matrix.PerspectiveFovLH(45.0f, this.Width / this.Height, 0.1f, 100f);
            // device.Transform.View = Matrix.LookAtLH(new Vector3(0, 0, -6), new Vector3(0, 0, 0), new Vector3(0, 1, 0));
            device.RenderState.Lighting = false;
            device.RenderState.CullMode = Cull.None;

        }
        private void VertexDeclaration()
        {
            point = new CustomVertex.PositionColored[17];
                point[0].Position = new Vector3(0f, 0f, 0f);
                point[1].Position = new Vector3(0f, 1f, 0f);
                point[2].Position = new Vector3(0.75f, 0.75f, 0f);
                point[3].Position = new Vector3(1f, 0f, 0f);
                point[4].Position = new Vector3(0.75f, -0.75f, 0f);
                point[5].Position = new Vector3(0f, -1f, 0f);
                point[6].Position = new Vector3(-0.75f, -0.75f, 0f);
                point[7].Position = new Vector3(-1f, 0f, 0f);
                point[8].Position = new Vector3(-0.75f, 0.75f, 0f);
                point[9].Position = new Vector3(0f, 2f, 0f);
                point[10].Position = new Vector3(1.75f, 1.75f, 0f);
                point[11].Position = new Vector3(2f, 0f, 0f);
                point[12].Position = new Vector3(1.75f, -1.75f, 0f);
                point[13].Position = new Vector3(0f, -2f, 0f);
                point[14].Position = new Vector3(-1.75f, -1.75f, 0f);
                point[15].Position = new Vector3(-2f, 0f, 0f);
                point[16].Position = new Vector3(-1.75f, 1.75f, 0f);

            line = new CustomVertex.PositionColored[34];
                line[0].Position = new Vector3(-1f, 0f, 0f);
                line[1].Position = new Vector3(1f, 0f, 0f);
                line[2].Position = new Vector3(0f, -1f, 0f);
                line[3].Position = new Vector3(0f, 1f, 0f);
                line[4].Position = new Vector3(0f, 1f, 0f);
                line[5].Position = new Vector3(1f, 0f, 0f);
                line[6].Position = new Vector3(1f, 0f, 0f);
                line[7].Position = new Vector3(0f, -1f, 0f);
                line[8].Position = new Vector3(0f, -1f, 0f);
                line[9].Position = new Vector3(-1f, 0f, 0f);
                line[10].Position = new Vector3(-1f, 0f, 0f);
                line[11].Position = new Vector3(0f, 1f, 0f);
                line[12].Position = new Vector3(-1f, 1f, 0f);
                line[13].Position = new Vector3(1f, 1f, 0f);
                line[14].Position = new Vector3(1f, 1f, 0f);
                line[15].Position = new Vector3(1f, -1f, 0f);
                line[16].Position = new Vector3(1f, -1f, 0f);
                line[17].Position = new Vector3(-1f, -1f, 0f);
                line[18].Position = new Vector3(-1f, -1f, 0f);
                line[19].Position = new Vector3(-1f, 1f, 0f);
                line[20].Position = new Vector3(-2f, 0f, 0f);
                line[21].Position = new Vector3(0f, 2f, 0f);
                line[22].Position = new Vector3(0f, 2f, 0f);
                line[23].Position = new Vector3(2f, 0f, 0f);
                line[24].Position = new Vector3(2f, 0f, 0f);
                line[25].Position = new Vector3(0f, -2f, 0f);
                line[26].Position = new Vector3(0f, -2f, 0f);
                line[27].Position = new Vector3(-2f, 0f, 0f);
                line[28].Position = new Vector3(-2f, -2f, 0f);
                line[29].Position = new Vector3(-2f, 2f, 0f);
                line[30].Position = new Vector3(-2f, 2f, 0f);
                line[31].Position = new Vector3(2f, 2f, 0f);
                line[32].Position = new Vector3(2f, 2f, 0f);
                line[33].Position = new Vector3(2f, -2f, 0f);

            lines = new CustomVertex.PositionColored[18];
                lines[0].Position = new Vector3(0f, 1f, 0f);
                lines[1].Position = new Vector3(0.75f, 0.75f, 0f);
                lines[2].Position = new Vector3(1f, 0f, 0f);
                lines[3].Position = new Vector3(0.75f, -0.75f, 0f);
                lines[4].Position = new Vector3(0f, -1f, 0f);
                lines[5].Position = new Vector3(-0.75f, -0.75f, 0f);
                lines[6].Position = new Vector3(-1, 0f, 0f);
                lines[7].Position = new Vector3(-0.75f, 0.75f, 0f);
                lines[8].Position = new Vector3(0f, 1f, 0f);
                lines[9].Position = new Vector3(0f, 2f, 0f);
                lines[10].Position = new Vector3(1.75f, 1.75f, 0f);
                lines[11].Position = new Vector3(2f, 0f, 0f);
                lines[12].Position = new Vector3(1.75f, -1.75f, 0f);
                lines[13].Position = new Vector3(0f, -2f, 0f);
                lines[14].Position = new Vector3(-1.75f, -1.75f, 0f);
                lines[15].Position = new Vector3(-2f, 0f, 0f);
                lines[16].Position = new Vector3(-1.75f, 1.75f, 0f);
                lines[17].Position = new Vector3(0f, 2f, 0f);

            triangle = new CustomVertex.PositionColored[27];
                triangle[0].Position = new Vector3(0f, 0.75f, 0f);
                triangle[1].Position = new Vector3(-0.75f, -0.75f, 0f);
                triangle[2].Position = new Vector3(0.75f, -0.75f, 0f);
                triangle[3].Position = new Vector3(-2f, 2f, 0f);
                triangle[4].Position = new Vector3(-1f, 2f, 0f);
                triangle[5].Position = new Vector3(-1.5f, 1f, 0f);
                triangle[6].Position = new Vector3(-0.5f, 2f, 0f);
                triangle[7].Position = new Vector3(0.5f, 2f, 0f);
                triangle[8].Position = new Vector3(0f, 1f, 0f);
                triangle[9].Position = new Vector3(2f, 2f, 0f);
                triangle[10].Position = new Vector3(1f, 2f, 0f);
                triangle[11].Position = new Vector3(1.5f, 1f, 0f);
                triangle[12].Position = new Vector3(2f, 0.5f, 0f);
                triangle[13].Position = new Vector3(2f, -0.5f, 0f);
                triangle[14].Position = new Vector3(1f, 0f, 0f);
                triangle[15].Position = new Vector3(2f, -2f, 0f);
                triangle[16].Position = new Vector3(1f, -2f, 0f);
                triangle[17].Position = new Vector3(1.5f, -1f, 0f);
                triangle[18].Position = new Vector3(-0.5f, -2f, 0f);
                triangle[19].Position = new Vector3(0.5f, -2f, 0f);
                triangle[20].Position = new Vector3(0f, -1f, 0f);
                triangle[21].Position = new Vector3(-2f, -2f, 0f);
                triangle[22].Position = new Vector3(-1f, -2f, 0f);
                triangle[23].Position = new Vector3(-1.5f, -1f, 0f);
                triangle[24].Position = new Vector3(-2f, 0.5f, 0f);
                triangle[25].Position = new Vector3(-2f, -0.5f, 0f);
                triangle[26].Position = new Vector3(-1f, 0f, 0f);

            triangles = new CustomVertex.PositionColored[10];
                triangles[0].Position = new Vector3(-1.5f, 2f, 0f);
                triangles[1].Position = new Vector3(-0.5f, 2f, 0f);
                triangles[2].Position = new Vector3(-1f, 1f, 0f);
                triangles[3].Position = new Vector3(0f, 1f, 0f);
                triangles[4].Position = new Vector3(-0.5f, 0f, 0f);
                triangles[5].Position = new Vector3(0.5f, 0f, 0f);
                triangles[6].Position = new Vector3(0f, -1f, 0f);
                triangles[7].Position = new Vector3(1f, -1f, 0f);
                triangles[8].Position = new Vector3(0.5f, -2f, 0f);
                triangles[9].Position = new Vector3(1.5f, -2f, 0f);

            trianglef = new CustomVertex.PositionColored[14];
                trianglef[0].Position = new Vector3(0f, 0f, 0f);
                trianglef[1].Position = new Vector3(0f, 2f, 0f);
                trianglef[2].Position = new Vector3(1f, 1.75f, 0f);
                trianglef[3].Position = new Vector3(1.75f, 1f, 0f);
                trianglef[4].Position = new Vector3(2f, 0f, 0f);
                trianglef[5].Position = new Vector3(1.75f, -1f, 0f);
                trianglef[6].Position = new Vector3(1f, -1.75f, 0f);
                trianglef[7].Position = new Vector3(0f, -2f, 0f);
                trianglef[8].Position = new Vector3(-1f, -1.75f, 0f);
                trianglef[9].Position = new Vector3(-1.75f, -1f, 0f);
                trianglef[10].Position = new Vector3(-2f, 0f, 0f);
                trianglef[11].Position = new Vector3(-1.75f, 1f, 0f);
                trianglef[12].Position = new Vector3(-1f, 1.75f, 0f);
                trianglef[13].Position = new Vector3(0f, 2f, 0f);

        }
        private void _1okno_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 10;
            wybor = 1;
            liczba2.Enabled = true;
            liczba2.Value = 1;
            liczba1.Value = 1;
            liczba1.Maximum = 17;
            label1.Text = "Ilość punktów: ";

        }
        float FPS()
        {
            frameCount++;
            currentTime = System.DateTime.UtcNow.Ticks;
            long timeInterval = currentTime - previousTime;

            if (timeInterval > 500000)
            {
                fps = frameCount / (timeInterval / 1000.0f) * 10000;
                previousTime = currentTime;
                frameCount = 0;
            }
            return fps;
        }
        private void tresc(int r, float w, int ile, int wyb) 
        {
            Codeview.Text = "device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.White, 1.0f, 0);\r\ndevice.BeginScene();\r\ndevice.VertexFormat = CustomVertex.PositionColored.Format;\r\ndevice.Transform.View = Matrix.Translation(0, 0, 5);\r\n\r\n";
            switch (r)
            {
                case 1:
                    Codeview.Text += "device.Transform.World = Matrix.RotationYawPitchRoll(angle, 0, 0);\r\n\r\n";
                    break;
                case 2:
                    Codeview.Text += "device.Transform.World = Matrix.RotationYawPitchRoll(0, angle, 0);\r\n\r\n";
                    break;
                case 3:
                    Codeview.Text += "device.Transform.World = Matrix.RotationYawPitchRoll(0, 0, angle);\r\n\r\n";
                    break;
                case 4:
                    Codeview.Text += "device.Transform.World = Matrix.RotationYawPitchRoll(angle, angle, 0);\r\n\r\n";
                    break;
                case 5:
                    Codeview.Text += "device.Transform.World = Matrix.RotationYawPitchRoll(angle, 0, angle);\r\n\r\n";
                    break;
                case 6:
                    Codeview.Text += "device.Transform.World = Matrix.RotationYawPitchRoll(0, angle, angle);\r\n\r\n";
                    break;
                case 7:
                    Codeview.Text += "device.Transform.World = Matrix.RotationYawPitchRoll(angle, angle, angle);\r\n\r\n";
                    break;
            }
            switch (wyb)
            {
                case 1:
                    Codeview.Text += "device.RenderState.PointSize = "+ w +";\r\n\r\n";
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.PointList, "+ ile +", point);\r\n\r\n";
                    break;
                case 2:
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.LineList, " + ile + ", line);\r\n\r\n";
                    break;
                case 3:
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.LineStrip, " + ile + ", lines);\r\n\r\n";
                    break;
                case 4:
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleList, " + ile + ", triangle);\r\n\r\n";
                    break;
                case 5:
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleFan, " + ile + ", trianglef);\r\n\r\n";
                    break;
                case 6:
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, " + ile + ", triangles);\r\n\r\n";
                    break;
            }
            Codeview.Text += "device.EndScene();\r\ndevice.Present();\r\nthis.Invalidate();\r\nangle += 0.02f;";
        }
        private void Render(int r, float w, int ile, int wyb)
        {
            device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.White, 1.0f, 0);
            device.BeginScene();

            device.VertexFormat = CustomVertex.PositionColored.Format;
           
            device.Transform.View = Matrix.Translation(0, 0, 5);
            if (r > 0)
            {
                switch (r)
                {
                    case 1:
                        device.Transform.World = Matrix.RotationYawPitchRoll(angle, 0, 0);
                        break;
                    case 2:
                        device.Transform.World = Matrix.RotationYawPitchRoll(0, angle, 0);
                        break;
                    case 3:
                        device.Transform.World = Matrix.RotationYawPitchRoll(0, 0, angle);
                        break;
                    case 4:
                        device.Transform.World = Matrix.RotationYawPitchRoll(angle, angle, 0);
                        break;
                    case 5:
                        device.Transform.World = Matrix.RotationYawPitchRoll(angle, 0, angle);
                        break;
                    case 6:
                        device.Transform.World = Matrix.RotationYawPitchRoll(0, angle, angle);
                        break;
                    case 7:
                        device.Transform.World = Matrix.RotationYawPitchRoll(angle, angle, angle);
                        break;
                }
            }
            else
            {
                device.Transform.World = Matrix.RotationYawPitchRoll(0, 0, 0);
                angle = 0f;
            };
            switch (wyb)
            { 
                case 1:
                    device.RenderState.PointSize = w;
                    device.DrawUserPrimitives(PrimitiveType.PointList, ile, point);
                    break;
                case 2:
                    device.DrawUserPrimitives(PrimitiveType.LineList, ile, line);
                    break;
                case 3:
                    device.DrawUserPrimitives(PrimitiveType.LineStrip, ile, lines);
                    break;
                case 4:
                    device.DrawUserPrimitives(PrimitiveType.TriangleList, ile, triangle);
                    break;
                case 5:
                    device.DrawUserPrimitives(PrimitiveType.TriangleFan, ile, trianglef);
                    break;
                case 6:
                    device.DrawUserPrimitives(PrimitiveType.TriangleStrip, ile, triangles);
                    break;
            }
              
            device.EndScene();
            device.Present();
            this.Invalidate();
            angle += 0.02f;
        
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            int rotacja = 0;
            if (checkBox1.Checked && checkBox2.Checked && checkBox3.Checked)
            {
                rotacja = 7;
            }
            else if (checkBox1.Checked && checkBox3.Checked)
            {
                rotacja = 6;
            }
            else if (checkBox2.Checked && checkBox3.Checked)
            {
                rotacja = 5;
            }
            else if (checkBox1.Checked && checkBox2.Checked)
            {
                rotacja = 4;
            }
            else if (checkBox3.Checked)
            {
                rotacja = 3;
            }
            else if (checkBox1.Checked)
            {
                rotacja = 2;
            }
            else if (checkBox2.Checked)
            {
                rotacja = 1;
            };
            int ilosc = (int)liczba1.Value;
            float wielkosc = (float)liczba2.Value;
            Render(rotacja,wielkosc,ilosc,wybor);
            if (rotacja != rotacja2 || wielkosc != wielkosc2|| ilosc != ilosc2|| wybor != wybor2)
            {
                tresc(rotacja, wielkosc, ilosc, wybor);
                rotacja2 = rotacja;
                wielkosc2 = wielkosc;
                ilosc2 = ilosc;
                wybor2 = wybor;
            }
            wiersze.Value = Codeview.Lines.Length;
            znaki.Value = Codeview.Text.Length;
            float dd = FPS();
            fps2.Value = (Decimal)dd;
        }

        private void punkty_Click(object sender, EventArgs e)
        {
            wybor = 1;
            liczba2.Enabled = true;
            liczba2.Value = 1;
            liczba1.Value = 1;
            liczba1.Maximum = 17;
            label1.Text = "Ilość punktów: ";
        }

        private void linie_Click(object sender, EventArgs e)
        {
            wybor = 2;
            liczba2.Enabled = false;
            liczba2.Value = 1;
            liczba1.Value = 1;
            liczba1.Maximum = 17;
            label1.Text = "Ilość linii: ";
        }

        private void linie2_Click(object sender, EventArgs e)
        {
            wybor = 3;
            liczba2.Enabled = false;
            liczba2.Value = 1;
            liczba1.Value = 1;
            liczba1.Maximum = 17;
            label1.Text = "Ilość linii: ";
        }

        private void trojkaty_Click(object sender, EventArgs e)
        {
            wybor = 4;
            liczba2.Enabled = false;
            liczba2.Value = 1;
            liczba1.Value = 1;
            liczba1.Maximum = 9;
            label1.Text = "Ilość trójkątów: ";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            wybor = 5;
            liczba2.Enabled = false;
            liczba2.Value = 1;
            liczba1.Value = 1;
            liczba1.Maximum = 12;
            label1.Text = "Ilość trójkątów: ";
        }

        private void trojkaty3_Click(object sender, EventArgs e)
        {
            wybor = 6;
            liczba2.Enabled = false;
            liczba2.Value = 1;
            liczba1.Value = 1;
            liczba1.Maximum = 8;
            label1.Text = "Ilość trójkątów: ";
        }
    }
}
