namespace EsGuiApp
{
	partial class MainForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.serialPort = new System.IO.Ports.SerialPort(this.components);
			this.nmrFanSpeed = new System.Windows.Forms.NumericUpDown();
			this.btnFanSpeed = new System.Windows.Forms.Button();
			this.grbFanSpeed = new System.Windows.Forms.GroupBox();
			this.grbLightIntensity = new System.Windows.Forms.GroupBox();
			this.nmrLightIntensity = new System.Windows.Forms.NumericUpDown();
			this.btnLightIntensity = new System.Windows.Forms.Button();
			this.grbComPort = new System.Windows.Forms.GroupBox();
			this.cboComPorts = new System.Windows.Forms.ComboBox();
			this.btnComPort = new System.Windows.Forms.Button();
			this.grbBaudRate = new System.Windows.Forms.GroupBox();
			this.cboBaudRate = new System.Windows.Forms.ComboBox();
			this.btnBaudRate = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.nmrFanSpeed)).BeginInit();
			this.grbFanSpeed.SuspendLayout();
			this.grbLightIntensity.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.nmrLightIntensity)).BeginInit();
			this.grbComPort.SuspendLayout();
			this.grbBaudRate.SuspendLayout();
			this.SuspendLayout();
			// 
			// serialPort
			// 
			this.serialPort.BaudRate = 1200;
			this.serialPort.PortName = "COM5";
			this.serialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort_DataReceived);
			// 
			// nmrFanSpeed
			// 
			this.nmrFanSpeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.nmrFanSpeed.Location = new System.Drawing.Point(14, 36);
			this.nmrFanSpeed.Maximum = new decimal(new int[] {
            4,
            0,
            0,
            0});
			this.nmrFanSpeed.Name = "nmrFanSpeed";
			this.nmrFanSpeed.Size = new System.Drawing.Size(211, 30);
			this.nmrFanSpeed.TabIndex = 1;
			// 
			// btnFanSpeed
			// 
			this.btnFanSpeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnFanSpeed.Location = new System.Drawing.Point(14, 86);
			this.btnFanSpeed.Name = "btnFanSpeed";
			this.btnFanSpeed.Size = new System.Drawing.Size(210, 43);
			this.btnFanSpeed.TabIndex = 2;
			this.btnFanSpeed.Text = "Send";
			this.btnFanSpeed.UseVisualStyleBackColor = true;
			this.btnFanSpeed.Click += new System.EventHandler(this.btnFanSpeed_Click);
			// 
			// grbFanSpeed
			// 
			this.grbFanSpeed.Controls.Add(this.nmrFanSpeed);
			this.grbFanSpeed.Controls.Add(this.btnFanSpeed);
			this.grbFanSpeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.grbFanSpeed.Location = new System.Drawing.Point(22, 245);
			this.grbFanSpeed.Name = "grbFanSpeed";
			this.grbFanSpeed.Size = new System.Drawing.Size(242, 149);
			this.grbFanSpeed.TabIndex = 3;
			this.grbFanSpeed.TabStop = false;
			this.grbFanSpeed.Text = "Fan Speed";
			// 
			// grbLightIntensity
			// 
			this.grbLightIntensity.Controls.Add(this.nmrLightIntensity);
			this.grbLightIntensity.Controls.Add(this.btnLightIntensity);
			this.grbLightIntensity.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.grbLightIntensity.Location = new System.Drawing.Point(287, 245);
			this.grbLightIntensity.Name = "grbLightIntensity";
			this.grbLightIntensity.Size = new System.Drawing.Size(242, 149);
			this.grbLightIntensity.TabIndex = 4;
			this.grbLightIntensity.TabStop = false;
			this.grbLightIntensity.Text = "Light Intensity";
			// 
			// nmrLightIntensity
			// 
			this.nmrLightIntensity.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.nmrLightIntensity.Location = new System.Drawing.Point(14, 36);
			this.nmrLightIntensity.Maximum = new decimal(new int[] {
            4,
            0,
            0,
            0});
			this.nmrLightIntensity.Name = "nmrLightIntensity";
			this.nmrLightIntensity.Size = new System.Drawing.Size(211, 30);
			this.nmrLightIntensity.TabIndex = 1;
			// 
			// btnLightIntensity
			// 
			this.btnLightIntensity.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnLightIntensity.Location = new System.Drawing.Point(14, 86);
			this.btnLightIntensity.Name = "btnLightIntensity";
			this.btnLightIntensity.Size = new System.Drawing.Size(210, 43);
			this.btnLightIntensity.TabIndex = 2;
			this.btnLightIntensity.Text = "Send";
			this.btnLightIntensity.UseVisualStyleBackColor = true;
			this.btnLightIntensity.Click += new System.EventHandler(this.btnLightIntensity_Click);
			// 
			// grbComPort
			// 
			this.grbComPort.Controls.Add(this.cboComPorts);
			this.grbComPort.Controls.Add(this.btnComPort);
			this.grbComPort.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.grbComPort.Location = new System.Drawing.Point(22, 22);
			this.grbComPort.Name = "grbComPort";
			this.grbComPort.Size = new System.Drawing.Size(507, 94);
			this.grbComPort.TabIndex = 4;
			this.grbComPort.TabStop = false;
			this.grbComPort.Text = "COM Port";
			// 
			// cboComPorts
			// 
			this.cboComPorts.FormattingEnabled = true;
			this.cboComPorts.Location = new System.Drawing.Point(14, 39);
			this.cboComPorts.Name = "cboComPorts";
			this.cboComPorts.Size = new System.Drawing.Size(210, 33);
			this.cboComPorts.TabIndex = 3;
			// 
			// btnComPort
			// 
			this.btnComPort.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnComPort.Location = new System.Drawing.Point(279, 33);
			this.btnComPort.Name = "btnComPort";
			this.btnComPort.Size = new System.Drawing.Size(210, 43);
			this.btnComPort.TabIndex = 2;
			this.btnComPort.Text = "Set";
			this.btnComPort.UseVisualStyleBackColor = true;
			this.btnComPort.Click += new System.EventHandler(this.btnComPort_Click);
			// 
			// grbBaudRate
			// 
			this.grbBaudRate.Controls.Add(this.cboBaudRate);
			this.grbBaudRate.Controls.Add(this.btnBaudRate);
			this.grbBaudRate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.grbBaudRate.Location = new System.Drawing.Point(22, 131);
			this.grbBaudRate.Name = "grbBaudRate";
			this.grbBaudRate.Size = new System.Drawing.Size(507, 94);
			this.grbBaudRate.TabIndex = 5;
			this.grbBaudRate.TabStop = false;
			this.grbBaudRate.Text = "BAUD Rate";
			// 
			// cboBaudRate
			// 
			this.cboBaudRate.FormattingEnabled = true;
			this.cboBaudRate.Items.AddRange(new object[] {
            "110",
            "300",
            "600",
            "1200",
            "2400",
            "4800",
            "9600",
            "14400",
            "19200"});
			this.cboBaudRate.Location = new System.Drawing.Point(14, 39);
			this.cboBaudRate.Name = "cboBaudRate";
			this.cboBaudRate.Size = new System.Drawing.Size(210, 33);
			this.cboBaudRate.TabIndex = 3;
			// 
			// btnBaudRate
			// 
			this.btnBaudRate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnBaudRate.Location = new System.Drawing.Point(279, 33);
			this.btnBaudRate.Name = "btnBaudRate";
			this.btnBaudRate.Size = new System.Drawing.Size(210, 43);
			this.btnBaudRate.TabIndex = 2;
			this.btnBaudRate.Text = "Set";
			this.btnBaudRate.UseVisualStyleBackColor = true;
			this.btnBaudRate.Click += new System.EventHandler(this.btnBaudRate_Click);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(548, 410);
			this.Controls.Add(this.grbBaudRate);
			this.Controls.Add(this.grbComPort);
			this.Controls.Add(this.grbLightIntensity);
			this.Controls.Add(this.grbFanSpeed);
			this.Name = "MainForm";
			this.Text = "ES GUI";
			((System.ComponentModel.ISupportInitialize)(this.nmrFanSpeed)).EndInit();
			this.grbFanSpeed.ResumeLayout(false);
			this.grbLightIntensity.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.nmrLightIntensity)).EndInit();
			this.grbComPort.ResumeLayout(false);
			this.grbBaudRate.ResumeLayout(false);
			this.ResumeLayout(false);

		}

		#endregion

		private System.IO.Ports.SerialPort serialPort;
		private System.Windows.Forms.NumericUpDown nmrFanSpeed;
		private System.Windows.Forms.Button btnFanSpeed;
		private System.Windows.Forms.GroupBox grbFanSpeed;
		private System.Windows.Forms.GroupBox grbLightIntensity;
		private System.Windows.Forms.NumericUpDown nmrLightIntensity;
		private System.Windows.Forms.Button btnLightIntensity;
		private System.Windows.Forms.GroupBox grbComPort;
		private System.Windows.Forms.Button btnComPort;
		private System.Windows.Forms.ComboBox cboComPorts;
		private System.Windows.Forms.GroupBox grbBaudRate;
		private System.Windows.Forms.ComboBox cboBaudRate;
		private System.Windows.Forms.Button btnBaudRate;
	}
}

