using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EsGuiApp
{
	public partial class MainForm : Form
	{
		private ESCommand cmd;

		public MainForm()
		{
			InitializeComponent();
			foreach(var item in System.IO.Ports.SerialPort.GetPortNames())
			{
				cboComPorts.Items.Add(item);
			}
			this.cboBaudRate.SelectedIndex = 3;
			this.cmd = new ESCommand(this.serialPort);
		}

		private void serialPort_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
		{
			//Do nothing
		}

		private void btnBaudRate_Click(object sender, EventArgs e)
		{
			try
			{
				this.cmd.SetBaudRate(int.Parse(this.cboBaudRate.SelectedValue.ToString()));
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		private void btnComPort_Click(object sender, EventArgs e)
		{
			try
			{
				this.cmd.SetPort(this.cboComPorts.SelectedItem.ToString());
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		private void btnLightIntensity_Click(object sender, EventArgs e)
		{
			try
			{
				byte data = (byte)(int.Parse(nmrLightIntensity.Value.ToString()));
				this.cmd.SendLightIntensity(data);
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}

		private void btnFanSpeed_Click(object sender, EventArgs e)
		{
			try
			{
				byte data = (byte)(int.Parse(nmrFanSpeed.Value.ToString()));
				this.cmd.SendFanSpeed(data);
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}
		}
	}

}
