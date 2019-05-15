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

namespace CSharp3
{
    public partial class Form1 : Form
    {
        //第二步           
        HDevelopExport HD = new HDevelopExport();
      
        public Form1()
        {
            InitializeComponent();        
        }
        private void button1_Click(object sender, EventArgs e)
        {   
            //第三步
            HD.RunHalcon(hWindowControl1.HalconWindow);
        }
    }
}
