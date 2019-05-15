using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

//第一步
using HalconDotNet;


namespace CSharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {   
            InitializeComponent();
        }

        
        //显示图片
        private void button1_Click(object sender, EventArgs e)
        {
            //第四步
            HDevelopExport HD = new HDevelopExport();
            HD.RunHalcon(hWindowControl1.HalconWindow);
        }
    }

    //第二步
    public partial class HDevelopExport
    {
        public HTuple hv_ExpDefaultWinHandle;

        // Main procedure 
        private void action()
        {
            // Local iconic variables 

            HObject ho_Image;

            // Local control variables 
            
            //第三步
            HTuple hv_Width = new HTuple(), hv_Height = new HTuple(), hv_WindowHandle = new HTuple();
            // Initialize local and output iconic variables 
            HOperatorSet.GenEmptyObj(out ho_Image);
            //dev_close_window(...);
            ho_Image.Dispose();
            HOperatorSet.ReadImage(out ho_Image, "D:/Visual studio 2017/Projects/Halcon-Config/res/IMG_20180618_172946_HDR.jpg");
            hv_Width.Dispose(); hv_Height.Dispose();
            HOperatorSet.GetImageSize(ho_Image, out hv_Width, out hv_Height);
            //dev_open_window(...);
            using (HDevDisposeHelper dh = new HDevDisposeHelper())
            {
                HOperatorSet.SetPart(hv_ExpDefaultWinHandle, 0, 0, hv_Height - 1, hv_Width - 1);
            }
            HOperatorSet.DispObj(ho_Image, hv_ExpDefaultWinHandle);
            ho_Image.Dispose();

            hv_Width.Dispose();
            hv_Height.Dispose();
            //如果第三步不做修改此处会报错
            hv_WindowHandle.Dispose();
        }

        public void InitHalcon()
        {
            // Default settings used in HDevelop
            HOperatorSet.SetSystem("width", 512);
            HOperatorSet.SetSystem("height", 512);
        }

        public void RunHalcon(HTuple Window)
        {
            hv_ExpDefaultWinHandle = Window;
            action();
        }

    }

}
