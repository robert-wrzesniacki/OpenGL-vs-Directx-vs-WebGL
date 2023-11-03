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
using System.IO;
using System.Runtime.InteropServices;


namespace DirectXProjekt
{
    public partial class _6okno : Form
    {
        private Device device;
        private CustomVertex.PositionTextured[] top;
        private CustomVertex.PositionTextured[] down;
        private CustomVertex.PositionTextured[] sc;
        private CustomVertex.PositionTextured[] sc1;
        private CustomVertex.PositionTextured[] sc2;
        private CustomVertex.PositionTextured[] sc3;
        private CustomVertex.PositionTextured[] sc4;
        private CustomVertex.PositionTextured[] sc5;
        private CustomVertex.PositionTextured[] sc6;
        private CustomVertex.PositionTextured[] sc7;
        private CustomVertex.PositionTextured[] sc8;
        private CustomVertex.PositionTextured[] sc9;
        private CustomVertex.PositionTextured[] sc10;
        private CustomVertex.PositionTextured[] sc11;
        private CustomVertex.PositionTextured[] scp;
        private CustomVertex.PositionTextured[] scp1;
        private CustomVertex.PositionTextured[] scp2;
        private CustomVertex.PositionTextured[] scp3;
        private CustomVertex.PositionTextured[] scp4;
        private CustomVertex.PositionTextured[] scp5;
        private CustomVertex.PositionTextured[] scp6;
        private CustomVertex.PositionTextured[] scp7;
        private CustomVertex.PositionTextured[] scp8;
        private CustomVertex.PositionTextured[] scp9;
        private CustomVertex.PositionTextured[] scp10;
        private CustomVertex.PositionColored[] vertex_lights;
        private Texture texture;
        private Texture texture2;
        private Texture texture3;
        private Material material;
        int frameCount;
        float fps;
        long currentTime, previousTime;
        float X, Z;
        float HeadMovement, HeadMovAngle;
        float Heading;
        bool kw, ks, ka, kd, kl, kp;
        float g;
        #region dane ścian

        int[,] s = {
{0,9,0,0},
{1,6,1,1},
{0,1,2,2},
{2,7,2,2},
{2,8,3,3},
{1,7,4,4},
{1,2,5,5},
{3,7,5,5},
{3,8,6,6},
{0,2,7,7},
{3,9,7,7},
{1,4,9,9},
//pion,
{0,0,0,7},
{1,1,1,4},
{1,1,5,6},
{1,1,7,9},
{2,2,5,7},
{3,3,6,7},
{4,4,7,9},
{7,7,0,2},
{7,7,4,5},
{8,8,1,6},
{9,9,0,7},
						  {-1 , -1, -1, -1}
					  };

        # endregion

        float X2, Z2, Heading2, HeadMovement2;
        int swiatlo2, blend2, kolizje2;
        public _6okno()
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
            top = new CustomVertex.PositionTextured[4];
            down = new CustomVertex.PositionTextured[4];
            top[0].Position = new Vector3(0f, 0.5f, 9f);
            top[0].Tu = 0;
            top[0].Tv = 0;

            top[1].Position = new Vector3(9f, 0.5f, 9f);
            top[1].Tu = 18;
            top[1].Tv = 0;

            top[2].Position = new Vector3(0f, 0.5f, 0f);
            top[2].Tu = 0;
            top[2].Tv = 18;

            top[3].Position = new Vector3(9f, 0.5f, 0f);
            top[3].Tu = 18;
            top[3].Tv = 18;

            down[0].Position = new Vector3(0f, -0.5f, 9f);
            down[0].Tu = 0;
            down[0].Tv = 0;

            down[1].Position = new Vector3(9f, -0.5f, 9f);
            down[1].Tu = 9;
            down[1].Tv = 0;

            down[2].Position = new Vector3(0f, -0.5f, 0f);
            down[2].Tu = 0;
            down[2].Tv = 9;

            down[3].Position = new Vector3(9f, -0.5f, 0f);
            down[3].Tu = 9;
            down[3].Tv = 9;

            sc = new CustomVertex.PositionTextured[4];
            sc[0].Position = new Vector3(0f, 0.5f, 0f);
            sc[0].Tu = 0;
            sc[0].Tv = 0;

            sc[1].Position = new Vector3(9f, 0.5f, 0f);
            sc[1].Tu = 9;
            sc[1].Tv = 0;

            sc[2].Position = new Vector3(0f, -0.5f, 0f);
            sc[2].Tu = 0;
            sc[2].Tv = 3;

            sc[3].Position = new Vector3(9f, -0.5f, 0f);
            sc[3].Tu = 9;
            sc[3].Tv = 3;

            sc1 = new CustomVertex.PositionTextured[4];
            sc1[0].Position = new Vector3(1f, 0.5f, 1f);
            sc1[0].Tu = 0;
            sc1[0].Tv = 0;

            sc1[1].Position = new Vector3(6f, 0.5f, 1f);
            sc1[1].Tu = 5;
            sc1[1].Tv = 0;

            sc1[2].Position = new Vector3(1f, -0.5f, 1f);
            sc1[2].Tu = 0;
            sc1[2].Tv = 3;

            sc1[3].Position = new Vector3(6f, -0.5f, 1f);
            sc1[3].Tu = 5;
            sc1[3].Tv = 3;

            sc2 = new CustomVertex.PositionTextured[4];
            sc2[0].Position = new Vector3(0f, 0.5f, 2f);
            sc2[0].Tu = 0;
            sc2[0].Tv = 0;

            sc2[1].Position = new Vector3(1f, 0.5f, 2f);
            sc2[1].Tu = 1;
            sc2[1].Tv = 0;

            sc2[2].Position = new Vector3(0f, -0.5f, 2f);
            sc2[2].Tu = 0;
            sc2[2].Tv = 3;

            sc2[3].Position = new Vector3(1f, -0.5f, 2f);
            sc2[3].Tu = 1;
            sc2[3].Tv = 3;

            sc3 = new CustomVertex.PositionTextured[4];
            sc3[0].Position = new Vector3(2f, 0.5f, 2f);
            sc3[0].Tu = 0;
            sc3[0].Tv = 0;

            sc3[1].Position = new Vector3(7f, 0.5f, 2f);
            sc3[1].Tu = 5;
            sc3[1].Tv = 0;

            sc3[2].Position = new Vector3(2f, -0.5f, 2f);
            sc3[2].Tu = 0;
            sc3[2].Tv = 3;

            sc3[3].Position = new Vector3(7f, -0.5f, 2f);
            sc3[3].Tu = 5;
            sc3[3].Tv = 3;

            sc4 = new CustomVertex.PositionTextured[4];
            sc4[0].Position = new Vector3(2f, 0.5f, 3f);
            sc4[0].Tu = 0;
            sc4[0].Tv = 0;

            sc4[1].Position = new Vector3(8f, 0.5f, 3f);
            sc4[1].Tu = 6;
            sc4[1].Tv = 0;

            sc4[2].Position = new Vector3(2f, -0.5f, 3f);
            sc4[2].Tu = 0;
            sc4[2].Tv = 3;

            sc4[3].Position = new Vector3(8f, -0.5f, 3f);
            sc4[3].Tu = 6;
            sc4[3].Tv = 3;

            sc5 = new CustomVertex.PositionTextured[4];
            sc5[0].Position = new Vector3(1f, 0.5f, 4f);
            sc5[0].Tu = 0;
            sc5[0].Tv = 0;

            sc5[1].Position = new Vector3(7f, 0.5f, 4f);
            sc5[1].Tu = 6;
            sc5[1].Tv = 0;

            sc5[2].Position = new Vector3(1f, -0.5f, 4f);
            sc5[2].Tu = 0;
            sc5[2].Tv = 3;

            sc5[3].Position = new Vector3(7f, -0.5f, 4f);
            sc5[3].Tu = 6;
            sc5[3].Tv = 3;

            sc6 = new CustomVertex.PositionTextured[4];
            sc6[0].Position = new Vector3(1f, 0.5f, 5f);
            sc6[0].Tu = 0;
            sc6[0].Tv = 0;

            sc6[1].Position = new Vector3(2f, 0.5f, 5f);
            sc6[1].Tu = 1;
            sc6[1].Tv = 0;

            sc6[2].Position = new Vector3(1f, -0.5f, 5f);
            sc6[2].Tu = 0;
            sc6[2].Tv = 3;

            sc6[3].Position = new Vector3(2f, -0.5f, 5f);
            sc6[3].Tu = 1;
            sc6[3].Tv = 3;

            sc7 = new CustomVertex.PositionTextured[4];
            sc7[0].Position = new Vector3(3f, 0.5f, 5f);
            sc7[0].Tu = 0;
            sc7[0].Tv = 0;

            sc7[1].Position = new Vector3(7f, 0.5f, 5f);
            sc7[1].Tu = 4;
            sc7[1].Tv = 0;

            sc7[2].Position = new Vector3(3f, -0.5f, 5f);
            sc7[2].Tu = 0;
            sc7[2].Tv = 3;

            sc7[3].Position = new Vector3(7f, -0.5f, 5f);
            sc7[3].Tu = 4;
            sc7[3].Tv = 3;

            sc8 = new CustomVertex.PositionTextured[4];
            sc8[0].Position = new Vector3(3f, 0.5f, 6f);
            sc8[0].Tu = 0;
            sc8[0].Tv = 0;

            sc8[1].Position = new Vector3(8f, 0.5f, 6f);
            sc8[1].Tu = 5;
            sc8[1].Tv = 0;

            sc8[2].Position = new Vector3(3f, -0.5f, 6f);
            sc8[2].Tu = 0;
            sc8[2].Tv = 3;

            sc8[3].Position = new Vector3(8f, -0.5f, 6f);
            sc8[3].Tu = 5;
            sc8[3].Tv = 3;

            sc9 = new CustomVertex.PositionTextured[4];
            sc9[0].Position = new Vector3(0f, 0.5f, 7f);
            sc9[0].Tu = 0;
            sc9[0].Tv = 0;

            sc9[1].Position = new Vector3(2f, 0.5f, 7f);
            sc9[1].Tu = 2;
            sc9[1].Tv = 0;

            sc9[2].Position = new Vector3(0f, -0.5f, 7f);
            sc9[2].Tu = 0;
            sc9[2].Tv = 3;

            sc9[3].Position = new Vector3(2f, -0.5f, 7f);
            sc9[3].Tu = 2;
            sc9[3].Tv = 3;

            sc10 = new CustomVertex.PositionTextured[4];
            sc10[0].Position = new Vector3(3f, 0.5f, 7f);
            sc10[0].Tu = 0;
            sc10[0].Tv = 0;

            sc10[1].Position = new Vector3(9f, 0.5f, 7f);
            sc10[1].Tu = 6;
            sc10[1].Tv = 0;

            sc10[2].Position = new Vector3(3f, -0.5f, 7f);
            sc10[2].Tu = 0;
            sc10[2].Tv = 3;

            sc10[3].Position = new Vector3(9f, -0.5f, 7f);
            sc10[3].Tu = 6;
            sc10[3].Tv = 3;

            sc11 = new CustomVertex.PositionTextured[4];
            sc11[0].Position = new Vector3(1f, 0.5f, 9f);
            sc11[0].Tu = 0;
            sc11[0].Tv = 0;

            sc11[1].Position = new Vector3(4f, 0.5f, 9f);
            sc11[1].Tu = 3;
            sc11[1].Tv = 0;

            sc11[2].Position = new Vector3(1f, -0.5f, 9f);
            sc11[2].Tu = 0;
            sc11[2].Tv = 3;

            sc11[3].Position = new Vector3(4f, -0.5f, 9f);
            sc11[3].Tu = 3;
            sc11[3].Tv = 3;

//pionowe
            scp = new CustomVertex.PositionTextured[4];
            scp[0].Position = new Vector3(0f, 0.5f, 0f);
            scp[0].Tu = 0;
            scp[0].Tv = 0;

            scp[1].Position = new Vector3(0f, 0.5f, 7f);
            scp[1].Tu = 7;
            scp[1].Tv = 0;

            scp[2].Position = new Vector3(0f, -0.5f, 0f);
            scp[2].Tu = 0;
            scp[2].Tv = 3;

            scp[3].Position = new Vector3(0f, -0.5f, 7f);
            scp[3].Tu = 7;
            scp[3].Tv = 3;

            scp1 = new CustomVertex.PositionTextured[4];
            scp1[0].Position = new Vector3(1f, 0.5f, 1f);
            scp1[0].Tu = 0;
            scp1[0].Tv = 0;

            scp1[1].Position = new Vector3(1f, 0.5f, 4f);
            scp1[1].Tu = 3;
            scp1[1].Tv = 0;

            scp1[2].Position = new Vector3(1f, -0.5f, 1f);
            scp1[2].Tu = 0;
            scp1[2].Tv = 3;

            scp1[3].Position = new Vector3(1f, -0.5f, 4f);
            scp1[3].Tu = 3;
            scp1[3].Tv = 3;

            scp2 = new CustomVertex.PositionTextured[4];
            scp2[0].Position = new Vector3(1f, 0.5f, 5f);
            scp2[0].Tu = 0;
            scp2[0].Tv = 0;

            scp2[1].Position = new Vector3(1f, 0.5f, 6f);
            scp2[1].Tu = 1;
            scp2[1].Tv = 0;

            scp2[2].Position = new Vector3(1f, -0.5f, 5f);
            scp2[2].Tu = 0;
            scp2[2].Tv = 3;

            scp2[3].Position = new Vector3(1f, -0.5f, 6f);
            scp2[3].Tu = 1;
            scp2[3].Tv = 3;

            scp3 = new CustomVertex.PositionTextured[4];
            scp3[0].Position = new Vector3(1f, 0.5f, 7f);
            scp3[0].Tu = 0;
            scp3[0].Tv = 0;

            scp3[1].Position = new Vector3(1f, 0.5f, 9f);
            scp3[1].Tu = 1;
            scp3[1].Tv = 0;

            scp3[2].Position = new Vector3(1f, -0.5f, 7f);
            scp3[2].Tu = 0;
            scp3[2].Tv = 3;

            scp3[3].Position = new Vector3(1f, -0.5f, 9f);
            scp3[3].Tu = 1;
            scp3[3].Tv = 3;

            scp4 = new CustomVertex.PositionTextured[4];
            scp4[0].Position = new Vector3(2f, 0.5f, 5f);
            scp4[0].Tu = 0;
            scp4[0].Tv = 0;

            scp4[1].Position = new Vector3(2f, 0.5f, 7f);
            scp4[1].Tu = 2;
            scp4[1].Tv = 0;

            scp4[2].Position = new Vector3(2f, -0.5f, 5f);
            scp4[2].Tu = 0;
            scp4[2].Tv = 3;

            scp4[3].Position = new Vector3(2f, -0.5f, 7f);
            scp4[3].Tu = 2;
            scp4[3].Tv = 3;

            scp5 = new CustomVertex.PositionTextured[4];
            scp5[0].Position = new Vector3(3f, 0.5f, 6f);
            scp5[0].Tu = 0;
            scp5[0].Tv = 0;

            scp5[1].Position = new Vector3(3f, 0.5f, 7f);
            scp5[1].Tu = 1;
            scp5[1].Tv = 0;

            scp5[2].Position = new Vector3(3f, -0.5f, 6f);
            scp5[2].Tu = 0;
            scp5[2].Tv = 3;

            scp5[3].Position = new Vector3(3f, -0.5f, 7f);
            scp5[3].Tu = 1;
            scp5[3].Tv = 3;

            scp6 = new CustomVertex.PositionTextured[4];
            scp6[0].Position = new Vector3(4f, 0.5f, 7f);
            scp6[0].Tu = 0;
            scp6[0].Tv = 0;

            scp6[1].Position = new Vector3(4f, 0.5f, 9f);
            scp6[1].Tu = 2;
            scp6[1].Tv = 0;

            scp6[2].Position = new Vector3(4f, -0.5f, 7f);
            scp6[2].Tu = 0;
            scp6[2].Tv = 3;

            scp6[3].Position = new Vector3(4f, -0.5f, 9f);
            scp6[3].Tu = 2;
            scp6[3].Tv = 3;

            scp7 = new CustomVertex.PositionTextured[4];
            scp7[0].Position = new Vector3(7f, 0.5f, 0f);
            scp7[0].Tu = 0;
            scp7[0].Tv = 0;

            scp7[1].Position = new Vector3(7f, 0.5f, 2f);
            scp7[1].Tu = 2;
            scp7[1].Tv = 0;

            scp7[2].Position = new Vector3(7f, -0.5f, 0f);
            scp7[2].Tu = 0;
            scp7[2].Tv = 3;

            scp7[3].Position = new Vector3(7f, -0.5f, 2f);
            scp7[3].Tu = 2;
            scp7[3].Tv = 3;

            scp8 = new CustomVertex.PositionTextured[4];
            scp8[0].Position = new Vector3(7f, 0.5f, 4f);
            scp8[0].Tu = 0;
            scp8[0].Tv = 0;

            scp8[1].Position = new Vector3(7f, 0.5f, 5f);
            scp8[1].Tu = 1;
            scp8[1].Tv = 0;

            scp8[2].Position = new Vector3(7f, -0.5f, 4f);
            scp8[2].Tu = 0;
            scp8[2].Tv = 3;

            scp8[3].Position = new Vector3(7f, -0.5f, 5f);
            scp8[3].Tu = 1;
            scp8[3].Tv = 3;

            scp9 = new CustomVertex.PositionTextured[4];
            scp9[0].Position = new Vector3(8f, 0.5f, 1f);
            scp9[0].Tu = 0;
            scp9[0].Tv = 0;

            scp9[1].Position = new Vector3(8f, 0.5f, 6f);
            scp9[1].Tu = 5;
            scp9[1].Tv = 0;

            scp9[2].Position = new Vector3(8f, -0.5f, 1f);
            scp9[2].Tu = 0;
            scp9[2].Tv = 3;

            scp9[3].Position = new Vector3(8f, -0.5f, 6f);
            scp9[3].Tu = 5;
            scp9[3].Tv = 3;

            scp10 = new CustomVertex.PositionTextured[4];
            scp10[0].Position = new Vector3(9f, 0.5f, 0f);
            scp10[0].Tu = 0;
            scp10[0].Tv = 0;

            scp10[1].Position = new Vector3(9f, 0.5f, 7f);
            scp10[1].Tu = 7;
            scp10[1].Tv = 0;

            scp10[2].Position = new Vector3(9f, -0.5f, 0f);
            scp10[2].Tu = 0;
            scp10[2].Tv = 3;

            scp10[3].Position = new Vector3(9f, -0.5f, 7f);
            scp10[3].Tu = 7;
            scp10[3].Tv = 3;
        }
        private void Texture()
        {

            texture = TextureLoader.FromFile(device, "Data/sciany.jpg");
            texture2 = TextureLoader.FromFile(device, "Data/sufit.jpg");
            texture3 = TextureLoader.FromFile(device, "Data/podloga.jpg");

        }
        private void SetLight()
        {
            //device.RenderState.Lighting = true;
            device.Lights[0].Enabled = true;
            device.Lights[0].Type = LightType.Point;
            device.Lights[0].Position = new Vector3(0.2f, -0.4f, -1f);
            device.Lights[0].Range = 10f;
            device.Lights[0].Ambient = Color.White;
            device.Lights[0].Attenuation1 = 2f;

            device.Lights[1].Enabled = true;
            device.Lights[1].Type = LightType.Point;
            device.Lights[1].Position = new Vector3(-0.2f, 0f, -1f);
            device.Lights[1].Range = 10f;
            device.Lights[1].Ambient = Color.White;
            device.Lights[1].Attenuation1 = 1f;

            device.Lights[2].Enabled = true;
            device.Lights[2].Type = LightType.Point;
            device.Lights[2].Position = new Vector3(0f, 0.4f, -1.4f);
            device.Lights[2].Range = 10f;
            device.Lights[2].Ambient = Color.White;
            device.Lights[2].Attenuation1 = 2f;

            device.Lights[3].Enabled = true;
            device.Lights[3].Type = LightType.Point;
            device.Lights[3].Position = new Vector3(-3f, 0f, -8f);
            device.Lights[3].Range = 10f;
            device.Lights[3].Ambient = Color.White;
            device.Lights[3].Attenuation1 = 1f;
            #region Światła
            vertex_lights = new CustomVertex.PositionColored[4];
            vertex_lights[0].Position = device.Lights[0].Position;
            vertex_lights[1].Position = device.Lights[1].Position;
            vertex_lights[2].Position = device.Lights[2].Position;
            vertex_lights[3].Position = device.Lights[3].Position;
            vertex_lights[0].Color = device.Lights[0].Ambient.ToArgb();
            vertex_lights[1].Color = device.Lights[1].Ambient.ToArgb();
            vertex_lights[2].Color = device.Lights[2].Ambient.ToArgb();
            vertex_lights[3].Color = device.Lights[3].Ambient.ToArgb();

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
        private void _6okno_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 10;
           
            Texture();

            Heading = 1.57f;
            X = -2.5f;												//Pozycja startowa gracza
            Z = -0.5f;

        }
        private void testkolizji(int koli)
{
		float SX = X;
		float SZ = Z;
		
		if(kw == true){			//W
                    X += (float) (Math.Sin(Heading) * 0.025);
					Z -= (float) (Math.Cos(Heading) * 0.025); 
                    HeadMovAngle = HeadMovAngle + 2;
                    HeadMovement = (float) (0.025 * Math.Sin( HeadMovAngle *0.1));
			}
		if(ks == true){			//S
            X -= (float)(Math.Sin(Heading) * 0.025);
            Z += (float)(Math.Cos(Heading) * 0.025);
                  HeadMovAngle = HeadMovAngle - 2;
                   HeadMovement = (float)(0.025 * Math.Sin( HeadMovAngle  * 0.1 ));
			}
        if (ka == true)
        {				//A
            X += (float)(Math.Sin(Heading + 1.57) * 0.02f);   
            Z -= (float)(Math.Cos(Heading + 1.57) * 0.02f); 
        }
        if (kd == true)
        {			//D
            X -= (float)(Math.Sin(Heading + 1.57) * 0.02f);
            Z += (float)(Math.Cos(Heading + 1.57) * 0.02f); 
        }
		if(kl == true){
		Heading += 0.02f;
		}
		if(kp == true){
		Heading -= 0.02f;
		}
        g = 0.2f;
        if (koli == 1)
        {
            for (int a = 0; s[a, 0] != -1; a++)
            {
                if (s[a, 0] != s[a, 1])
                {
                    if (X < -s[a, 0] + g && X > -s[a, 1] - g)
                    {
                        if (Z > (-s[a, 2] - g) && Z < (-s[a, 3] + g))
                        {
                            X = SX;
                            Z = SZ;
                        }
                    }
                }
                else
                {
                    if (Z < -s[a, 2] + g && Z > -s[a, 3] - g)
                    {
                        if (X > (-s[a, 0] - g) && X < (-s[a, 1] + g))
                        {
                            X = SX;
                            Z = SZ;
                        }
                    }
                }
            }
        }
 }
        private void rysowanieswiata() 
        {
            device.SetTexture(0, texture2);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, top);
            device.SetTexture(0, texture3);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, down);
            device.SetTexture(0, texture);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc1);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc2);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc3);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc4);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc5);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc6);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc7);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc8);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc9);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc10);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, sc11);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp1);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp2);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp3);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp4);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp5);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp6);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp7);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp8);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp9);
            device.DrawUserPrimitives(PrimitiveType.TriangleStrip, 2, scp10);
        }
        private void Render(int sw, int blen, int kol)
        {
            device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.Black, 1.0f, 0);
            device.BeginScene();

            device.VertexFormat = CustomVertex.PositionTextured.Format;
            SetLight();
            testkolizji(kol);
            device.Transform.World = Matrix.Translation(X, HeadMovement, Z);
 
            device.Transform.View = Matrix.RotationAxis(new Vector3(0f, 1f, 0f), Heading);
            
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

            rysowanieswiata();
          
            device.EndScene();
            device.Present();
            this.Invalidate();


        }
        private void tresc(int sw, int blen, int kol)
        {
            Codeview.Text = "device.Clear(ClearFlags.Target | ClearFlags.ZBuffer, System.Drawing.Color.White, 1.0f, 0);\r\ndevice.BeginScene();\r\ndevice.VertexFormat = CustomVertex.PositionTextured.Format;\r\n\r\n";

            if (kol == 1)
            {
                Codeview.Text += "DetekcjaKolizji();\r\n\r\n";
            }

            Codeview.Text += "device.Transform.World = Matrix.Translation(" + X + ", "+ HeadMovement + ", " + Z + ");\r\n\r\n";
            Codeview.Text += "device.Transform.View = Matrix.RotationAxis(new Vector3(0f, 1f, 0f), " + Heading + ");\r\n\r\n";

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

            Codeview.Text += "\tRysowanieSwiata();\r\n\r\n";
            Codeview.Text += "device.EndScene();\r\ndevice.Present();\r\nthis.Invalidate();\r\nangle += 0.02f;";
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
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
            int kolizje = 0;
            if (radioButton5.Checked)
            {
                kolizje = 1;
            }
            else if (radioButton6.Checked)
            {
                kolizje = 2;
            }
            Render(swiatlo, blend, kolizje);

            if (X != X2 || Z != Z2 || Heading != Heading2 || HeadMovement != HeadMovement2 || swiatlo != swiatlo2 || blend != blend2 || kolizje != kolizje2)
            {
                tresc(swiatlo, blend, kolizje);
                X2 = X;
                Z2 = Z;
                Heading2 = Heading;
                HeadMovement2 = HeadMovement;
                swiatlo2 = swiatlo;
                blend2 = blend;
                kolizje2 = kolizje;
            }
            wiersze.Value = Codeview.Lines.Length;
            znaki.Value = Codeview.Text.Length;
            float dd = FPS();
            fps2.Value = (Decimal)dd;
        }

        private void _6okno_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }
        }

        private void _6okno_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }


        private void radioButton5_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }

        }

        private void radioButton6_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }
        }

        private void radioButton1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }
        }

        private void radioButton2_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }
        }

        private void radioButton3_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }
        }

        private void radioButton4_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }
        }

        private void radioButton5_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }

        private void radioButton6_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }

        private void radioButton1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }

        private void radioButton2_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }

        private void radioButton3_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }

        private void radioButton4_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }

        private void Codeview_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = true;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = true;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = true;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = true;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = true;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = true;
            }
        }

        private void Codeview_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W)
            {
                kw = false;
            }
            if (e.KeyCode == Keys.S)
            {
                ks = false;
            }
            if (e.KeyCode == Keys.A)
            {
                ka = false;
            }
            if (e.KeyCode == Keys.D)
            {
                kd = false;
            }
            if (e.KeyCode == Keys.Q)
            {
                kl = false;
            }
            if (e.KeyCode == Keys.E)
            {
                kp = false;
            }
        }
    }
}
