#pragma once

namespace OOAtask84 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� DynamicGraphics
	/// </summary>
	public ref class DynamicGraphics : public System::Windows::Forms::Form
	{
	public:
		DynamicGraphics(void)
		{
			InitializeComponent();
			// g - ����������� ����������� 
			g = this->CreateGraphics();
			R = 70;
			// ��������� ������ �����
			// � ������������ � �������� ����������
			this->ClientSize =
				System::Drawing::Size((R + 30) * 2, (R + 30) * 2);
			x0 = R + 30;
			y0 = R + 30;
			// ���������� ��������� �������.
			// ���� ����� ������� �����(�������) � 30 ��������.
			// ���� ����� ������� ����� - 6 ��������.
			// ���� ����������� �� 12-�� �����
			ahr = 90 - DateTime::Now.Hour * 30 - (DateTime::Now.Minute / 12) * 6;
			amin = 90 - DateTime::Now.Minute * 6;
			asec = 90 - DateTime::Now.Second * 6;
			timer1->Interval = 1000; // ������ ������� �� ������� 1 � 
			timer1->Enabled = true; // ���� �������
		}

	private:
		// ����������� �����������
		Graphics^ g;
		int R; // ������ ����������
		int x0, y0;	// ����� ����������
		int ahr, amin, asec; // ��������� ������� (����)

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~DynamicGraphics()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &DynamicGraphics::timer1_Tick);
			// 
			// DynamicGraphics
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"DynamicGraphics";
			this->Text = L"����";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DynamicGraphics::DynamicGraphics_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

		//������ �� �������
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// ���������� �������
		DrawClock();
	}
	private: System::Void DynamicGraphics_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int x, y; // ���������� ������� �� ���������� 
		int a; // ���� ����� �� � ������ (�0,��) (�,�)
		int h; // ����� ������� �����
		a = 0; // ����� ������ �� 3 -� ����� ������ ������� �������
		h = 3; // ���� 0 �������� � ��� 3 ����
#define TORAD 0.0174532
			   // ���������
		while (a < 360)
		{
			x = x0 + R * Math::Cos(a * TORAD);
			y = x0 - R * Math::Sin(a * TORAD);
			// Forml->Canvas->MoveTo(x,y);
			if ((a % 30) == 0)
			{
				g->DrawEllipse(Pens::Black, x - 2, y - 2, 3, 3);
				// ����� �� �������� �������
				x = x0 + (R + 15) * Math::Cos(a * TORAD);
				y = x0 - (R + 15) * Math::Sin(a * TORAD);
				g->DrawString(h.ToString(),
					this->Font, Brushes::Black, x - 5, y - 7);
				h--;
				if (h == 0) h = 12;

			}
			else
				g->DrawEllipse(Pens::Black, x - 1, y - 1, 1, 1);
			a = a + 6; // 1 ������ - 6 ��������
		}
		// �������
		DrawClock();
	}

		   // ������ ������ �� ����� (�0,�0) ���
		   // ����� � ������������ ��� X
		   // L - ����� �������
		   void Vector(float �0, float �0, float a, float l, System::Drawing::Pen^ aPen)
		   {
			   // x0,y0 - ������ �������
			   //a - ���� ����� ���� � � ��������
			   // l - ����� �������
			   // �����. ��������� ���� �� �������� � �������
#define TORAD 0.0174532
			   float �, �; // ���������� ����� �������
			   � = �0 + l * Math::Cos(a * TORAD);
			   � = �0 - l * Math::Sin(a * TORAD);
			   g->DrawLine(aPen, �0, �0, �, �);
		   }

		   // ������ �������
		   void DrawClock(void)
		   {
			   // ��������� ��� ��������� �������
			   Pen^ hPen = gcnew Pen(Color::LightBlue, 3);
			   Pen^ mPen = gcnew Pen(Color::LightBlue, 3);
			   Pen^ sPen = gcnew Pen(Color::Black, 2);
			   // �������� ��� �������� �������
			   Pen^ cPen = gcnew Pen(SystemColors::Control, 4);
			   // ��� ��������� � �������� ������� � ��������,
			   // ������� � 30.
			   // ������� ����������� �������:
			   Vector(x0, y0, ahr, R - 20, cPen); // �������
			   Vector(x0, y0, amin, R - 15, cPen); // ��������
			   Vector(x0, y0, asec, R - 7, cPen); // ���������
				// ����� ��������� �������
			   ahr = 90 - DateTime::Now.Hour * 30 - (DateTime::Now.Minute / 12) * 6;
			   amin = 90 - DateTime::Now.Minute * 6; asec = 90 - DateTime::Now.Second * 6;
			   // ���������� �������:
			   // �������
			   Vector(x0, y0, ahr, R - 20, hPen);
			   // ��������
			   Vector(x0, y0, amin, R - 15, mPen);
			   // ���������
			   Vector(x0, y0, asec, R - 7, sPen);
			   //g->DrawEllipse(Pens::Black,x0-2,y0-2,4,4); 
			   g->FillEllipse(Brushes::Black, x0 - 3, y0 - 3, 6, 6);
		   }
	};
}
