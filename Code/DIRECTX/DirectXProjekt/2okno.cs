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
    public partial class _2okno : Form
    {
        private Device device;
        private CustomVertex.PositionColored[] triangle;
        private CustomVertex.PositionColored[] triangles;
        private float angle = 0f;
        int wybor, ile;
        int frameCount;
        float fps;
        long currentTime, previousTime;
        int c1a2, c1b2, c1c2, c2a2, c2b2, c2c2, c3a2, c3b2, c3c2, c4a2, c4b2, c4c2;
        int rotacja2, wybor2, ile2;

        public _2okno()
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
            device.RenderState.Lighting = false;
            device.RenderState.CullMode = Cull.None;

        }
        private void VertexDeclaration()
        {
            triangle = new CustomVertex.PositionColored[3];
                triangle[0].Position = new Vector3(0f, 1.75f, 0f);
                triangle[1].Position = new Vector3(-1.75f, -1.75f, 0f);
                triangle[2].Position = new Vector3(1.75f, -1.75f, 0f);
            triangles = new CustomVertex.PositionColored[4];
                triangles[0].Position = new Vector3(-1.75f, 1.75f, 0f);
                triangles[1].Position = new Vector3(1.75f, 1.75f, 0f);
                triangles[2].Position = new Vector3(-1.75f, -1.75f, 0f);
                triangles[3].Position = new Vector3(1.75f, -1.75f, 0f);

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
        private void _2okno_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 10;
            wybor = 1;
            ile = 1;
            label7.Visible = false;
            label8.Visible = false;
            label9.Visible = false;
            label10.Visible = false;
            color2a.Visible = false;
            color2b.Visible = false;
            color2c.Visible = false;
            color3a.Visible = false;
            color3b.Visible = false;
            color3c.Visible = false;
            color4a.Visible = false;
            color4b.Visible = false;
            color4c.Visible = false;
            color4a.Enabled = false;
            color4b.Enabled = false;
            color4c.Enabled = false;
        }
        private void tresc(int r, int wyb, int il, int c1a, int c1b, int c1c, int c2a, int c2b, int c2c, int c3a, int c3b, int c3c, int c4a, int c4b, int c4c) 
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
                    if (il == 1)
                    {
                        Codeview.Text += "triangle[0].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangle[1].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangle[2].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n\r\n";
                    }
                    else if (il == 2)
                    {
                        Codeview.Text += "triangle[0].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangle[1].Color = Color.FromArgb( " + c2a + ", " + c2b + ", " + c2c + ").ToArgb();\r\n";
                        Codeview.Text += "triangle[2].Color = Color.FromArgb( " + c3a + ", " + c3b + ", " + c3c + ").ToArgb();\r\n\r\n";
                    }
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleList, 1, triangle);\r\n\r\n";
                    break;
                case 2:
                    if (il == 1)
                    {
                        Codeview.Text += "triangles[0].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangles[1].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangles[2].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangles[3].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n\r\n";
                    }
                    else if (il == 2)
                    {
                        Codeview.Text += "triangles[0].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangles[1].Color = Color.FromArgb( " + c2a + ", " + c2b + ", " + c2c + ").ToArgb();\r\n";
                        Codeview.Text += "triangles[2].Color = Color.FromArgb( " + c3a + ", " + c3b + ", " + c3c + ").ToArgb();\r\n";
                        Codeview.Text += "triangles[3].Color = Color.FromArgb( " + c4a + ", " + c4b + ", " + c4c + ").ToArgb();\r\n\r\n";
                    }
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, triangles);\r\n\r\n";
                    break;
            }
            Codeview.Text += "device.EndScene();\r\ndevice.Present();\r\nthis.Invalidate();\r\nangle += 0.02f;";
        }
        private void Render(int r, int wyb, int il, int c1a, int c1b, int c1c, int c2a, int c2b, int c2c, int c3a, int c3b, int c3c, int c4a, int c4b, int c4c)
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
                    if (il == 1)
                    {
                        triangle[0].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangle[1].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangle[2].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                    }
                    else if (il == 2)
                    {
                        triangle[0].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangle[1].Color = Color.FromArgb(c2a, c2b, c2c).ToArgb();
                        triangle[2].Color = Color.FromArgb(c3a, c3b, c3c).ToArgb();
                    }
                    device.DrawUserPrimitives(PrimitiveType.TriangleList, 1, triangle);
                    break;
                case 2:
                    if (il == 1)
                    {
                        triangles[0].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangles[1].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangles[2].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangles[3].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                    }
                    else if (il == 2)
                    {
                        triangles[0].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangles[1].Color = Color.FromArgb(c2a, c2b, c2c).ToArgb();
                        triangles[2].Color = Color.FromArgb(c3a, c3b, c3c).ToArgb();
                        triangles[3].Color = Color.FromArgb(c4a, c4b, c4c).ToArgb();
                    }
                    device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, triangles);
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

            int c1a = (int)color1a.Value;
            int c1b = (int)color1b.Value;
            int c1c = (int)color1c.Value;
            int c2a = (int)color2a.Value;
            int c2b = (int)color2b.Value;
            int c2c = (int)color2c.Value;
            int c3a = (int)color3a.Value;
            int c3b = (int)color3b.Value;
            int c3c = (int)color3c.Value;
            int c4a = (int)color4a.Value;
            int c4b = (int)color4b.Value;
            int c4c = (int)color4c.Value;

            Render(rotacja, wybor, ile, c1a, c1b, c1c, c2a, c2b, c2c, c3a, c3b, c3c, c4a, c4b, c4c);
            if (rotacja != rotacja2 || wybor != wybor2 || ile != ile2 || c1a != c1a2 || c1b != c1b2 || c1c != c1c2 || c2a != c2a2 || c2b != c2b2 || c2c != c2c2 || c3a != c3a2 || c3b != c3b2 || c3c != c3c2 || c4a != c4a2 || c4b != c4b2 || c4c != c4c2)
            {
                tresc(rotacja, wybor, ile, c1a, c1b, c1c, c2a, c2b, c2c, c3a, c3b, c3c, c4a, c4b, c4c);
                rotacja2 = rotacja;
                wybor2 = wybor;
                ile2 = ile;
                c1a2 = c1a;
                c1b2 = c1b;
                c1c2 = c1c;
                c2a2 = c2a;
                c2b2 = c2b;
                c2c2 = c2c;
                c3a2 = c3a;
                c3b2 = c3b;
                c3c2 = c3c;
                c4a2 = c4a;
                c4b2 = c4b;
                c4c2 = c4c;
            }
            wiersze.Value = Codeview.Lines.Length;
            znaki.Value = Codeview.Text.Length;
            float dd = FPS();
            fps2.Value = (Decimal)dd;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ile = 1;
            label7.Visible = false;
            label8.Visible = false;
            label9.Visible = false;
            label10.Visible = false;
            color2a.Visible = false;
            color2b.Visible = false;
            color2c.Visible = false;
            color3a.Visible = false;
            color3b.Visible = false;
            color3c.Visible = false;
            color4a.Visible = false;
            color4b.Visible = false;
            color4c.Visible = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ile = 2;
            label7.Visible = true;
            label8.Visible = true;
            label9.Visible = true;
            label10.Visible = true;
            color2a.Visible = true;
            color2b.Visible = true;
            color2c.Visible = true;
            color3a.Visible = true;
            color3b.Visible = true;
            color3c.Visible = true;
            color4a.Visible = true;
            color4b.Visible = true;
            color4c.Visible = true;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                wybor = 1;
                color4a.Enabled = false;
                color4b.Enabled = false;
                color4c.Enabled = false;
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked) 
            {
                wybor = 2;
                color4a.Enabled = true;
                color4b.Enabled = true;
                color4c.Enabled = true;
            }
        }
    }
}
