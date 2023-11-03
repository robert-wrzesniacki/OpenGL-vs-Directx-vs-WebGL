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
    public partial class _4okno : Form
    {
        private Device device;
        private Mesh czworo;
        private Mesh tapo;
        private CustomVertex.PositionColored[] triangle;
        private CustomVertex.PositionColored[] vertex_lights;
        private Material material;
        float lr, ud, skal, skalx, skaly, skalz;
        int wybor;
        int frameCount;
        float fps;
        long currentTime, previousTime;
        int c1a2, c1b2, c1c2;
        int rotacja2, wybor2, swiatlo2;
        float katy22, katx22, katz22, lr2, ud2, skal2, skalx2, skaly2, skalz2;
        public _4okno()
        {
            InitializeComponent();
            InitializeDevice();
            CameraPositioning();
            VertexDeclaration();
            MeshDeclaration();
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

            device.RenderState.CullMode = Cull.None;

        }
        private void VertexDeclaration()
        {
            triangle = new CustomVertex.PositionColored[3];
            triangle[0].Position = new Vector3(0f, 1.75f, 0f);
            triangle[1].Position = new Vector3(-1.75f, -1.75f, 0f);
            triangle[2].Position = new Vector3(1.75f, -1.75f, 0f);

        }
        private void MeshDeclaration()
        {
            czworo = Mesh.Sphere(device, 1f, 4, 2);
            tapo = Mesh.Teapot(device);

            czworo.ComputeNormals();
            tapo.ComputeNormals();
        }
        private void SetLight()
        {
            //device.RenderState.Lighting = true;
            device.Lights[0].Enabled = true;
            device.Lights[0].Type = LightType.Point;
            device.Lights[0].Position = new Vector3(0.2f, 0f, -1.5f);
            device.Lights[0].Range = 5f;
            device.Lights[0].Ambient = Color.White;
            device.Lights[0].Attenuation1 = 3f;


            #region Światła
            vertex_lights = new CustomVertex.PositionColored[1];
            vertex_lights[0].Position = device.Lights[0].Position;
            //  vertex_lights[1].Position = device.Lights[1].Position;
            //vertex_lights[2].Position = device.Lights[2].Position;
            vertex_lights[0].Color = device.Lights[0].Ambient.ToArgb();
            // vertex_lights[1].Color = device.Lights[1].Ambient.ToArgb();
            //vertex_lights[2].Color = device.Lights[2].Ambient.ToArgb();
            #endregion

            material = new Material();
            material.Ambient = Color.LightGray;
            material.Specular = Color.White;
            device.Material = material;
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
        private void Render(int r, int wyb, int sw, int c1a, int c1b, int c1c, float katx2, float katy2, float katz2, float lr, float ud, float skal, float skalx, float skaly, float skalz)
        {
            device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.Black, 1.0f, 0);
            device.BeginScene();
            device.Transform.World = Matrix.Scaling(skalx, skaly, skalz);
            if (r > 0)
            {
                switch (r)
                {
                    case 1:
                        device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(katx2, 0, 0));
                        break;
                    case 2:
                        device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(0, katy2, 0));
                        break;
                    case 3:
                        device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(0, 0, katz2));
                        break;
                    case 4:
                        device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(katx2, katy2, 0));
                        break;
                    case 5:
                        device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(katx2, 0, katz2));
                        break;
                    case 6:
                        device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(0, katy2, katz2));
                        break;
                    case 7:
                        device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(katx2, katy2, katz2));
                        break;
                }
            }
            else
            {
                device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(0, 0, 0));
            };

            

            device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.Translation(lr, ud, skal));
            
            if (sw == 1)
            {
                device.RenderState.Lighting = true;
            }
            else if (sw == 2)
            {
                device.RenderState.Lighting = false;
            }

            SetLight();

            switch (wyb)
            {
                case 1:
                        device.RenderState.Lighting = false;
                        device.VertexFormat = CustomVertex.PositionColored.Format;
                        triangle[0].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangle[1].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                        triangle[2].Color = Color.FromArgb(c1a, c1b, c1c).ToArgb();
                    device.DrawUserPrimitives(PrimitiveType.TriangleList, 1, triangle);
                    break;
                case 2:
                    device.VertexFormat = CustomVertex.PositionNormalColored.Format;
                    device.RenderState.AmbientColor = System.Drawing.Color.FromArgb(c1a, c1b, c1c).ToArgb();
                    czworo.DrawSubset(0);
                    break;
                case 3:
                    device.VertexFormat = CustomVertex.PositionNormalColored.Format;
                    device.RenderState.AmbientColor = System.Drawing.Color.FromArgb(c1a, c1b, c1c).ToArgb();
                    tapo.DrawSubset(0);
                    break;
            }

            device.EndScene();
            device.Present();
            this.Invalidate();

        }
        private void _4okno_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 10;
            wybor = 1;
            radioButton2.Checked = true;
            radioButton1.Enabled = false;
            lr = 0.0f;
            ud = 0.0f;
            skal = 5.0f;
            skalx = 1.0f;
            skaly = 1.0f;
            skalz = 1.0f;
        }
        private void tresc(int r, int wyb, int sw, int c1a, int c1b, int c1c, float katx2, float katy2, float katz2, float lr, float ud, float skal, float skalx, float skaly, float skalz)
        {
            Codeview.Text = "device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.White, 1.0f, 0);\r\ndevice.BeginScene();\r\n";
            if (wyb != 1)
            {

                Codeview.Text += "device.VertexFormat = CustomVertex.PositionNormalColored.Format;\r\n";
            }
            else
            {
                Codeview.Text += "device.VertexFormat = CustomVertex.PositionColored.Format;\r\n";
            }
            Codeview.Text += "device.Transform.World = Matrix.Scaling(" + skalx + ", " + skaly + ", " + skalz + ");\r\n\r\n";
            switch (r)
            {
                case 1:
                    Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(" + katx2 + ", 0, 0));\r\n\r\n";
                    break;
                case 2:
                    Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(0, " + katy2 + ", 0));\r\n\r\n";
                    break;
                case 3:
                    Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(0, 0, " + katz2 + "));\r\n\r\n";
                    break;
                case 4:
                    Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(" + katx2 + ", " + katy2 + ", 0));\r\n\r\n";
                    break;
                case 5:
                    Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(" + katx2 + ", 0, " + katz2 + "));\r\n\r\n";
                    break;
                case 6:
                    Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(0, " + katy2 + ", " + katz2 + "));\r\n\r\n";
                    break;
                case 7:
                    Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.RotationYawPitchRoll(" + katx2 + ", " + katy2 + ", " + katz2 + "));\r\n\r\n";
                    break;
            }
            Codeview.Text += "device.Transform.World = Matrix.Multiply(device.Transform.World,Matrix.Translation(" + lr + ", " + ud + ", " + skal + "));\r\n\r\n";
            
           
            if (sw == 1)
            {
                Codeview.Text += "device.RenderState.Lighting = true;\r\n\r\n";
            }
            else if (sw == 2)
            {
                Codeview.Text += "device.RenderState.Lighting = false;\r\n\r\n";
            }

            
            switch (wyb)
            {
                case 1:
                        Codeview.Text += "triangle[0].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangle[1].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n";
                        Codeview.Text += "triangle[2].Color = Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n\r\n";
                    Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleList, 1, triangle);\r\n\r\n";
                    break;
                case 2:
                    if (sw == 1)
                    {
                        Codeview.Text += "device.RenderState.AmbientColor = System.Drawing.Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n\r\n";
                    }
                    Codeview.Text += "\tczworoscian.DrawSubset(0);\r\n\r\n";
                    break;
                case 3:
                    if (sw == 1)
                    {
                        Codeview.Text += "device.RenderState.AmbientColor = System.Drawing.Color.FromArgb( " + c1a + ", " + c1b + ", " + c1c + ").ToArgb();\r\n\r\n";
                    }
                    Codeview.Text += "\ttapot.DrawSubset(0);\r\n\r\n";
                    break;
            }
            Codeview.Text += "device.EndScene();\r\ndevice.Present();\r\nthis.Invalidate();\r\n";
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
            int swiatlo = 0;
            if (radioButton1.Checked)
            {
                swiatlo = 1;
            }
            else if (radioButton2.Checked)
            {
                swiatlo = 2;
            }
            int c1a = (int)color1a.Value;
            int c1b = (int)color1b.Value;
            int c1c = (int)color1c.Value;

            float katx2 = (float)katx.Value;
            float katy2 = (float)katy.Value;
            float katz2 = (float)katz.Value;

            katx2 = katx2 * (float)(Math.PI/180);
            katy2 = katy2 * (float)(Math.PI/180);
            katz2 = katz2 * (float)(Math.PI/180);

            Render(rotacja, wybor, swiatlo, c1a, c1b, c1c, katx2, katy2, katz2, lr, ud, skal, skalx, skaly, skalz);
            if (rotacja != rotacja2 || wybor != wybor2 || swiatlo != swiatlo2 || c1a != c1a2 || c1b != c1b2 || c1c != c1c2 || katx2 != katx22 || katy2 != katy22 || katz2 != katz22 || lr != lr2 || ud != ud2 || skal != skal2 || skalx != skalx2 || skaly != skaly2 || skalz != skalz2)
            {
                tresc(rotacja, wybor, swiatlo, c1a, c1b, c1c, katx2, katy2, katz2, lr, ud, skal, skalx, skaly, skalz);
                rotacja2 = rotacja;
                wybor2 = wybor;
                swiatlo2 = swiatlo;
                c1a2 = c1a;
                c1b2 = c1b;
                c1c2 = c1c;
                katx22 = katx2; 
                katy22 = katy2; 
                katz22 = katz2; 
                lr2 = lr; 
                ud2 = ud;
                skal2 = skal;
                skalx2 = skalx;
                skaly2 = skaly;
                skalz2 = skalz;
            }
            wiersze.Value = Codeview.Lines.Length;
            znaki.Value = Codeview.Text.Length;
            float dd = FPS();
            fps2.Value = (Decimal)dd;
        }

        private void sfera_Click(object sender, EventArgs e)
        {
            wybor = 1;
            radioButton2.Checked = true;
            radioButton1.Enabled = false;
           
        }

        private void szescian_Click(object sender, EventArgs e)
        {
            wybor = 2;
            radioButton1.Enabled = true;
        }

        private void czajnik_Click(object sender, EventArgs e)
        {
            wybor = 3;
            radioButton1.Enabled = true;
        }

        private void katz_ValueChanged(object sender, EventArgs e)
        {

        }

        private void plus_Click(object sender, EventArgs e)
        {
            skal -= 0.5f;
        }

        private void minus_Click(object sender, EventArgs e)
        {
            skal += 0.5f;
        }

        private void up_Click(object sender, EventArgs e)
        {
            ud += 0.5f;
        }

        private void right_Click(object sender, EventArgs e)
        {
            lr += 0.5f;
        }

        private void down_Click(object sender, EventArgs e)
        {
            ud -= 0.5f;
        }

        private void left_Click(object sender, EventArgs e)
        {
            lr -= 0.5f;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ud = 0.0f;
            lr = 0.0f;
            skal = 5.0f;
            skalx = 1.0f;
            skaly = 1.0f;
            skalz = 1.0f;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            skalx += 0.2f;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            skaly += 0.2f;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            skalz += 0.2f;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            skalx -= 0.2f;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            skaly -= 0.2f;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            skalz -= 0.2f;
        }
    }
}
