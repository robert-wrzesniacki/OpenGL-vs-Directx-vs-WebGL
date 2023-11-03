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
    public partial class _5okno : Form
    {
        private Device device;
        private CustomVertex.PositionTextured[] top;
        private CustomVertex.PositionTextured[] down;
        private CustomVertex.PositionTextured[] face;
        private CustomVertex.PositionTextured[] beck;
        private CustomVertex.PositionTextured[] left;
        private CustomVertex.PositionTextured[] right;
        private CustomVertex.PositionColored[] vertex_lights;
        private Texture texture;
        private Texture texture2;
        private Texture texture3;
        private Texture texture4;
        private Texture texture5;
        private Material material;
        private float angle = 0f;
        int wybor;
        int frameCount;
        float fps;
        long currentTime, previousTime;

        int rotacja2, wybor2, swiatlo2, blend2;

        public _5okno()
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
            device.RenderState.SourceBlend = Blend.SourceAlpha;
            device.RenderState.DestinationBlend = Blend.One;
        }
        private void CameraPositioning()
        {
            device.Transform.Projection = Matrix.PerspectiveFovLH(45.0f, this.Width / this.Height, 0.1f, 100f);
            // device.Transform.View = Matrix.LookAtLH(new Vector3(0, 0, -6), new Vector3(0, 0, 0), new Vector3(0, 1, 0));

            device.RenderState.CullMode = Cull.None;

        }
        private void VertexDeclaration()
        {

            face = new CustomVertex.PositionTextured[4];
            beck = new CustomVertex.PositionTextured[4];
            top = new CustomVertex.PositionTextured[4];
            down = new CustomVertex.PositionTextured[4];
            left = new CustomVertex.PositionTextured[4];
            right = new CustomVertex.PositionTextured[4];

            face[0].Position = new Vector3(-1f, 1f, -1f);
            face[0].Tu = 0;
            face[0].Tv = 0;

            face[1].Position = new Vector3(1f, 1f, -1f);
            face[1].Tu = 1;
            face[1].Tv = 0;

            face[2].Position = new Vector3(-1f, -1f, -1f);
            face[2].Tu = 0;
            face[2].Tv = 1;

            face[3].Position = new Vector3(1f, -1f, -1f);
            face[3].Tu = 1;
            face[3].Tv = 1;

            beck[0].Position = new Vector3(-1f, 1f, 1f);
            beck[0].Tu = 1;
            beck[0].Tv = 0;

            beck[1].Position = new Vector3(1f, 1f, 1f);
            beck[1].Tu = 0;
            beck[1].Tv = 0;

            beck[2].Position = new Vector3(-1f, -1f, 1f);
            beck[2].Tu = 1;
            beck[2].Tv = 1;

            beck[3].Position = new Vector3(1f, -1f, 1f);
            beck[3].Tu = 0;
            beck[3].Tv = 1;

            top[0].Position = new Vector3(-1f, 1f, 1f);
            top[0].Tu = 0;
            top[0].Tv = 0;

            top[1].Position = new Vector3(1f, 1f, 1f);
            top[1].Tu = 1;
            top[1].Tv = 0;

            top[2].Position = new Vector3(-1f, 1f, -1f);
            top[2].Tu = 0;
            top[2].Tv = 1;

            top[3].Position = new Vector3(1f, 1f, -1f);
            top[3].Tu = 1;
            top[3].Tv = 1;

            down[0].Position = new Vector3(-1f, -1f, 1f);
            down[0].Tu = 1;
            down[0].Tv = 0;

            down[1].Position = new Vector3(1f, -1f, 1f);
            down[1].Tu = 0;
            down[1].Tv = 0;

            down[2].Position = new Vector3(-1f, -1f, -1f);
            down[2].Tu = 1;
            down[2].Tv = 1;

            down[3].Position = new Vector3(1f, -1f, -1f);
            down[3].Tu = 0;
            down[3].Tv = 1;

            left[0].Position = new Vector3(1f, 1f, 1f);
            left[0].Tu = 1;
            left[0].Tv = 0;

            left[1].Position = new Vector3(1f, 1f, -1f);
            left[1].Tu = 0;
            left[1].Tv = 0;

            left[2].Position = new Vector3(1f, -1f, 1f);
            left[2].Tu = 1;
            left[2].Tv = 1;

            left[3].Position = new Vector3(1f, -1f, -1f);
            left[3].Tu = 0;
            left[3].Tv = 1;
 
            right[0].Position = new Vector3(-1f, 1f, 1f);
            right[0].Tu = 1;
            right[0].Tv = 0;

            right[1].Position = new Vector3(-1f, 1f, -1f);
            right[1].Tu = 0;
            right[1].Tv = 0;

            right[2].Position = new Vector3(-1f, -1f, 1f);
            right[2].Tu = 1;
            right[2].Tv = 1;

            right[3].Position = new Vector3(-1f, -1f, -1f);
            right[3].Tu = 0;
            right[3].Tv = 1;


        }
        private void Texture()
        {

            texture = TextureLoader.FromFile(device, "Data/Tekstura1.bmp");
            texture2 = TextureLoader.FromFile(device, "Data/Tekstura2.bmp");
            texture3 = TextureLoader.FromFile(device, "Data/Tekstura3.png");
            texture4 = TextureLoader.FromFile(device, "Data/Tekstura4.jpg");
            texture5 = TextureLoader.FromFile(device, "Data/Tekstura5.png");

        }
        private void SetLight()
        {
            //device.RenderState.Lighting = true;
            device.Lights[0].Enabled = true;
            device.Lights[0].Type = LightType.Point;
            device.Lights[0].Position = new Vector3(0.2f, 0f, -1f);
            device.Lights[0].Range = 10f;
            device.Lights[0].Ambient = Color.White;
            device.Lights[0].Attenuation1 = 3f;
           
            device.Lights[1].Enabled = true;
            device.Lights[1].Type = LightType.Point;
            device.Lights[1].Position = new Vector3(-0.2f, 0f, -1f);
            device.Lights[1].Range = 10f;
            device.Lights[1].Ambient = Color.White;
            device.Lights[1].Attenuation1 = 3f;
          
            device.Lights[2].Enabled = true;
            device.Lights[2].Type = LightType.Point;
            device.Lights[2].Position = new Vector3(0f, 0.2f, -1.4f);
            device.Lights[2].Range = 10f;
            device.Lights[2].Ambient = Color.White;
            device.Lights[2].Attenuation1 = 3f;
            #region Światła
            vertex_lights = new CustomVertex.PositionColored[3];
            vertex_lights[0].Position = device.Lights[0].Position;
            vertex_lights[1].Position = device.Lights[1].Position;
            vertex_lights[2].Position = device.Lights[2].Position;
            vertex_lights[0].Color = device.Lights[0].Ambient.ToArgb();
            vertex_lights[1].Color = device.Lights[1].Ambient.ToArgb();
            vertex_lights[2].Color = device.Lights[2].Ambient.ToArgb();
            #endregion

            material = new Material();
            material.Ambient = Color.White;
            material.Specular = Color.White;
            material.SpecularSharpness = 1.0f;
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
        private void tresc(int r, int wyb, int sw, int blen)
        {
            Codeview.Text = "device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.White, 1.0f, 0);\r\ndevice.BeginScene();\r\ndevice.VertexFormat = CustomVertex.PositionTextured.Format;\r\ndevice.Transform.View = Matrix.Translation(0, 0, 5);\r\n\r\n";
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
            if (blen == 1)
            {
                Codeview.Text += "device.RenderState.AlphaBlendEnable = true;\r\n\r\n";
            }
            else
            {
                Codeview.Text += "device.RenderState.AlphaBlendEnable = false;\r\n\r\n";
            }

            
            switch (wyb)
            {
                case 1:
                    Codeview.Text += "device.SetTexture(0, texture);\r\n\r\n";
                    break;
                case 2:
                    Codeview.Text += "device.SetTexture(0, texture2);\r\n\r\n";
                    break;
                case 3:
                    Codeview.Text += "device.SetTexture(0, texture3);\r\n\r\n";
                    break;
                case 4:
                    Codeview.Text += "device.SetTexture(0, texture4);\r\n\r\n";
                    break;
                case 5:
                    Codeview.Text += "device.SetTexture(0, texture5);\r\n\r\n";
                    break;

            }
            Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, face);\r\n";
            Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, beck);\r\n";
            Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, top);\r\n";
            Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, down);\r\n";
            Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, left);\r\n";
            Codeview.Text += "\tdevice.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, right);\r\n\r\n";
            Codeview.Text += "device.EndScene();\r\ndevice.Present();\r\nthis.Invalidate();\r\nangle += 0.02f;";
        }
        private void Render(int r, int wyb, int sw, int blen)
        {
            device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.Black, 1.0f, 0);
            device.BeginScene();

            device.VertexFormat = CustomVertex.PositionTextured.Format;
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
            if (blen == 1)
            {
                device.RenderState.AlphaBlendEnable = true;
            }
            else
            {
                device.RenderState.AlphaBlendEnable = false;
            }
            SetLight();
            switch (wyb)
            {
                case 1:
                    device.SetTexture(0, texture);
                    break;
                case 2:
                    device.SetTexture(0, texture2);
                    break;
                case 3:
                    device.SetTexture(0, texture3);
                    break;
                case 4:
                    device.SetTexture(0, texture4);
                    break;
                case 5:
                    device.SetTexture(0, texture5);
                    break;
            }
            
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, beck);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, face);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, right);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, left);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, top);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, down);
      
            device.EndScene();
            device.Present();
            this.Invalidate();
            angle += 0.02f;

        }
        private void _5okno_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 10;
            Texture();
            wybor = 1;
            this.textBox1.Text = "texture = TextureLoader.FromFile(\r\ndevice, \r\n\"Data/Tekstura1.bmp\"\r\n);";
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
            int blend = 0;
            if (radioButton3.Checked)
            {
                blend = 1;
            }
            else if (radioButton4.Checked)
            {
                blend = 2;
            }

            Render(rotacja, wybor, swiatlo, blend);
            if (rotacja != rotacja2 || wybor != wybor2 || swiatlo != swiatlo2 || blend != blend2)
            {
            tresc(rotacja, wybor, swiatlo, blend);
            rotacja2 = rotacja;
            wybor2 = wybor;
            swiatlo2 = swiatlo;
            blend2 = blend;
            }
            wiersze.Value = Codeview.Lines.Length;
            znaki.Value = Codeview.Text.Length;
            float dd = FPS();
            fps2.Value = (Decimal)dd;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            wybor = 1;
            this.textBox1.Text = "texture = TextureLoader.FromFile(\r\ndevice, \r\n\"Data/Tekstura1.bmp\"\r\n);";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            wybor = 2;
            this.textBox1.Text = "texture2 = TextureLoader.FromFile(\r\ndevice, \r\n\"Data/Tekstura2.bmp\"\r\n);";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            wybor = 3;
            this.textBox1.Text = "texture3 = TextureLoader.FromFile(\r\ndevice, \r\n\"Data/Tekstura3.png\"\r\n);";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            wybor = 4;
            this.textBox1.Text = "texture4 = TextureLoader.FromFile(\r\ndevice, \r\n\"Data/Tekstura4.jpg\"\r\n);";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            wybor = 5;
            this.textBox1.Text = "texture5 = TextureLoader.FromFile(\r\ndevice, \r\n\"Data/Tekstura5.png\"\r\n);";
        }

    }
}