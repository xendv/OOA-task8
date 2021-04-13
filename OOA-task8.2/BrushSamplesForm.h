#pragma once

namespace OOAtask82 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� BrushSamplesForm
	/// </summary>
	public ref class BrushSamplesForm : public System::Windows::Forms::Form
	{
	public:
		BrushSamplesForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~BrushSamplesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(644, 528);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->ClientSizeChanged += gcnew System::EventHandler(this, &BrushSamplesForm::pictureBox1_ClientSizeChanged);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BrushSamplesForm::pictureBox1_Paint);
			// 
			// BrushSamplesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 528);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"BrushSamplesForm";
			this->Text = L"BrushSamplesForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// ����������� �����������
		System::Drawing::Graphics^ g = e->Graphics;
		int w = 100, h = 200; //������ � ������ �����
		int x0 = (this->ClientSize.Width - w) / 4; // ������ ���������� ������� ����� 
		int y0 = (this->ClientSize.Height - h) / 10;

		//������ �������� �������� 4 ������� 
		System::Drawing::Pen^ aPen;
		aPen = gcnew Pen(Color::DarkViolet, 4);
		aPen->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDot; //�������
		g->DrawLine(aPen, x0, y0, x0, y0 + h);
		g->DrawLine(aPen, x0, y0 + h / 2, x0 + w, y0);
		g->DrawLine(aPen, x0, y0 + h / 2, x0 + w, y0 + h);
		int x, y;
		x = x0 + w + 10;
		y = y0 + h;
		aPen->DashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
		g->DrawEllipse(aPen, x, y - w / 20, w / 20, w / 20);
		x = x + 10;
		y = y0 - 40;

		//������ HatchBrush-�����
		System::Drawing::Drawing2D::HatchBrush^ myBrush;
		myBrush = gcnew System::Drawing::Drawing2D::HatchBrush
		(System::Drawing::Drawing2D::HatchStyle::DottedDiamond, //����� ������
			Color::White, //���� ������
			Color::DarkTurquoise); //���� ����
		System::Drawing::Font^ aFont = gcnew System::Drawing::Font("Arial", 190);
		g->DrawString("�.", aFont, myBrush, x, y);

		//��������
		x = x0;
		y = y0 + h * 4 / 3;

		System::Drawing::TextureBrush^ myBrush2;
		try {
			myBrush2 = gcnew System::Drawing::TextureBrush
			(Image::FromFile(Application::StartupPath + "\\11.png"));
			//������ ���������� ������
			g->FillRectangle(myBrush2, x * 4/3, y, 200, 200);
		}
		catch (System::IO::FileNotFoundException^ ex) {
			g->DrawRectangle(Pens::Black, x, y, w, h);
			g->DrawString("�������", this->Font, Brushes::Black, x + 5, y + 5);
			g->DrawString("He ������", this->Font, Brushes::Black, x + 5, y + 20);
		}

		//��������
		x = x0;
		y = y + 50;

		System::Drawing::Drawing2D::LinearGradientBrush^ linGrBrush = 
			gcnew System::Drawing::Drawing2D::LinearGradientBrush(
			Rectangle(10, 10, 100, 100),
			Color::BlueViolet,   // Opaque red
			Color::FromArgb(255, 0, 0, 255),   // Opaque blue
			0);  //angle

		g->FillRectangle(linGrBrush, x * 3 + 2, y , w, w);
		g->FillRectangle(linGrBrush, x * 3 + 2, y + w + 10, 200, 30);
	}
	private: System::Void pictureBox1_ClientSizeChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Refresh();
	}
	};
}
