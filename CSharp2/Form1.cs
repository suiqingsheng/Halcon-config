using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CSharp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //第四步
        private void button1_Click(object sender, EventArgs e)
        {
            HDevelopExport HD = new HDevelopExport();
            HD.RunHalcon(hWindowControl1.HalconWindow);
        }
    }
}
