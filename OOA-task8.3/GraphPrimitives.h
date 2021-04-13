#pragma once

namespace OOAtask83 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� GraphPrimitives
	/// </summary>
	public ref class GraphPrimitives : public System::Windows::Forms::Form
	{
	public:
		GraphPrimitives(void)
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
		~GraphPrimitives()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->pictureBox1->Size = System::Drawing::Size(284, 261);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraphPrimitives::pictureBox1_Paint);
			// 
			// GraphPrimitives
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"GraphPrimitives";
			this->Text = L"GraphPrimitives";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// ����������� �����������
		System::Drawing::Graphics^ g = e->Graphics;
		int x0 = (this->ClientSize.Width) / 2; // ������ ���������� ������� ����� 
		int y0 = (this->ClientSize.Height) / 6;

		//������ ���������� ������������ (8.3.�)
		int r = 50, a = 0; //����� ������� � ��������� ���� 
		double pi = 3.14;
		y0 += r;
		// ������ ����� 
		array<Point>^ p = { Point(x0, y0), Point(x0, y0), Point(x0, y0), Point(x0, y0),
		Point(x0, y0), Point(x0, y0) };
		// ��������� ��������� ����� ������
		for (int i = 0; i < 5; i++)
		{
			p[i].X = x0 + r * Math::Cos(a * pi / 180);
			p[i].Y = y0 - r * Math::Sin(a * pi / 180);
			a = a + 180 - (5 - 2) * 180 / 5; //����������
		}
		p[5].X = p[0].X; p[5].Y = p[0].Y; // ��� �������������
		
		// ��������� ������� ����� 
		g->DrawLines(Pens::DodgerBlue, p);

		int x = x0, y = y0 + r * 3 / 2;

		//������ ����� (8.3.�)
		g->FillEllipse(Brushes::ForestGreen, x, y, 7, 7);

		//������ �������� ��������� (8.3.�)


	}
	};
}
