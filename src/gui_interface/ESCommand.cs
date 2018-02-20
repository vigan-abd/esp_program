using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EsGuiApp
{
	public class ESCommand
	{
		public const byte CMD_N0_WR_FAN = 0x24;
		public const byte CMD_N0_WR_LIGHT = 0x44;
		protected SerialPort adapter;
		public ESSerialPortResponse responseType { get; protected set; }

		public ESCommand(System.IO.Ports.SerialPort adapter)
		{
			this.adapter = adapter;
			this.adapter.Parity = Parity.None;
			this.adapter.StopBits = StopBits.Two;
			this.adapter.DataBits = 8;
		}

		public void SetPort(string value)
		{
			if (this.adapter.IsOpen)
				this.adapter.Close();
			this.adapter.PortName = value;
			this.adapter.Open();
		}

		public void SetBaudRate(int value)
		{
			if (this.adapter.IsOpen)
				this.adapter.Close();
			this.adapter.BaudRate = value;
			this.adapter.Open();
		}

		public void SendFanSpeed(byte data)
		{
			try
			{
				var payload = new byte[1];
				payload[0] = 0x0F & CMD_N0_WR_FAN;
				this.adapter.Write(payload, 0, 1);
				payload[0] = CMD_N0_WR_FAN >> 4;
				this.adapter.Write(payload, 0, 1);
				payload[0] = (byte)(0x0F & data);
				this.adapter.Write(payload, 0, 1);
				payload[0] = (byte)(data >> 4);
				this.adapter.Write(payload, 0, 1);
				this.responseType = ESSerialPortResponse.FanReceivedAck;
			}
			catch (Exception ex)
			{
				throw new Exception(ex.Message);
			}
		}

		public void SendLightIntensity(byte data)
		{
			try
			{
				var payload = new byte[1];
				payload[0] = 0x0F & CMD_N0_WR_LIGHT;
				this.adapter.Write(payload, 0, 1);
				payload[0] = CMD_N0_WR_LIGHT >> 4;
				this.adapter.Write(payload, 0, 1);
				payload[0] = (byte)(0x0F & data);
				this.adapter.Write(payload, 0, 1);
				payload[0] = (byte)(data >> 4);
				this.adapter.Write(payload, 0, 1);
				this.responseType = ESSerialPortResponse.LightReceivedAck;
			}
			catch (Exception ex)
			{
				throw new Exception(ex.Message);
			}
		}
	}
}
