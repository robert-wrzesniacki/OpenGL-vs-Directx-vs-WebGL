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
    public partial class _3okno : Form
    {
        private Device device;
        private Mesh sf;
        private Mesh szes;
        private Mesh sto;
        private Mesh tor;
        private Mesh czworo;
        private Mesh osmio;
        private Mesh dwunasto;
        private Mesh dwudziesto;
        private Mesh tapo;
        private CustomVertex.PositionColored[] vertex_lights;
        private Material material;
        private Material material2;
        private float angle = 0f;
        int wybor;
        int frameCount;
        float fps;
        long currentTime, previousTime;
        int c1a2, c1b2, c1c2;
        int rotacja2, wybor2, swiatlo2;


        public _3okno()
        {
            InitializeComponent();
            InitializeDevice();
            CameraPositioning();
            //VertexDeclaration();
            meshdeklaration();
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
        private void meshdeklaration() {

        sf = Mesh.Sphere(device,1f,15,15);
        szes = Mesh.Box(device,2,2,2);
        sto = Mesh.Cylinder(device, 1f, 0f,1.5f,12,12);
        tor = Mesh.Torus(device, 0.5f, 1.0f, 12, 12);
        czworo = Mesh.Sphere(device, 1f, 4, 2);     
        tapo = Mesh.Teapot(device);
        sf.ComputeNormals();
        szes.ComputeNormals();
        sto.ComputeNormals();
        tor.ComputeNormals();
        czworo.ComputeNormals();
        tapo.ComputeNormals();
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
        private void tresc(int r, int wyb, int sw, int c1a, int c1b, int c1c)
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
            if (sw == 1)
            {
                 Codeview.Text += "device.RenderState.Lighting = true;\r\n\r\n";
            }
            else if (sw == 2)
            {
                Codeview.Text += "device.RenderState.Lighting = false;\r\n\r\n";
            }

            Codeview.Text += "device.RenderState.AmbientColor = System.Drawing.Color.FromArgb( "+ c1a +", " + c1b +", "+ c1c +").ToArgb();\r\n\r\n";
            switch (wyb)
            {
                case 1:
                    Codeview.Text += "\tsfera.DrawSubset(0);\r\n\r\n";
                    break;
                case 2:
                    Codeview.Text += "\tszescian.DrawSubset(0);\r\n\r\n";
                    break;
                case 3:
                    Codeview.Text += "\tstozek.DrawSubset(0);\r\n\r\n";
                    break;
                case 4:
                    Codeview.Text += "\ttorus.DrawSubset(0);\r\n\r\n";
                    break;
                case 5:
                    Codeview.Text += "\tczworoscian.DrawSubset(0);\r\n\r\n";
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    Codeview.Text += "\ttapot.DrawSubset(0);\r\n\r\n";
                    break;
            }
            Codeview.Text += "device.EndScene();\r\ndevice.Present();\r\nthis.Invalidate();\r\nangle += 0.02f;";
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
        private void Render(int r, int wyb, int sw, int c1a, int c1b, int c1c)
        {
            device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.Black, 1.0f, 0);
            device.BeginScene();

            device.VertexFormat = CustomVertex.PositionNormalColored.Format;
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
            if (sw == 1)
            {
                device.RenderState.Lighting = true;
            }
            else if (sw == 2) 
            { 
                device.RenderState.Lighting = false; 
            }
            

            SetLight();
            device.RenderState.AmbientColor = System.Drawing.Color.FromArgb(c1a, c1b, c1c).ToArgb();
            switch (wyb)
            {
                case 1:
                    sf.DrawSubset(0);
                    break;
                case 2:
                    szes.DrawSubset(0);
                    break;
                case 3:
                    sto.DrawSubset(0);
                    break;
                case 4:
                    tor.DrawSubset(0);
                    break;
                case 5:
                    czworo.DrawSubset(0);
                    break;
                case 6:
                    break;
                case 7: 
                    break;
                case 8:
                    break;
                case 9:
                    tapo.DrawSubset(0);
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
            

            Render(rotacja, wybor, swiatlo, c1a, c1b, c1c);
            if (rotacja != rotacja2 || wybor != wybor2 || swiatlo != swiatlo2 || c1a != c1a2 || c1b != c1b2 || c1c != c1c2)
            {
                tresc(rotacja, wybor, swiatlo, c1a, c1b, c1c);
                rotacja2 = rotacja;
                wybor2 = wybor;
                swiatlo2 = swiatlo;
                c1a2 = c1a;
                c1b2 = c1b;
                c1c2 = c1c;
            }
            wiersze.Value = Codeview.Lines.Length;
            znaki.Value = Codeview.Text.Length;
            float dd = FPS();
            fps2.Value = (Decimal)dd;
        }

        private void DirectXPanel_Paint(object sender, PaintEventArgs e)
        {

        }

        private void _3okno_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 10;
            wybor = 1;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void sfera_Click(object sender, EventArgs e)
        {
            wybor = 1;
        }

        private void szescian_Click(object sender, EventArgs e)
        {
            wybor = 2;
        }

        private void stozek_Click(object sender, EventArgs e)
        {
            wybor = 3;
        }

        private void torus_Click(object sender, EventArgs e)
        {
            wybor = 4;
        }

        private void czworoscian_Click(object sender, EventArgs e)
        {
            wybor = 5;
        }

        private void smioscian_Click(object sender, EventArgs e)
        {
            wybor = 6;
        }

        private void dwunastoscian_Click(object sender, EventArgs e)
        {
            wybor = 7;
        }

        private void dwudziestoscian_Click(object sender, EventArgs e)
        {
            wybor = 8;
        }

        private void czajnik_Click(object sender, EventArgs e)
        {
            wybor = 9;
        }
    }
}
