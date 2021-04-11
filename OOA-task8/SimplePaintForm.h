#pragma once

namespace OOAtask8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� SimplePaintForm
	/// </summary>
	public ref class SimplePaintForm : public System::Windows::Forms::Form
	{
	public:
		SimplePaintForm(void)
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
		~SimplePaintForm()
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
			this->pictureBox1->Size = System::Drawing::Size(311, 300);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SimplePaintForm::pictureBox1_Paint);
			// 
			// SimplePaintForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(311, 300);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"SimplePaintForm";
			this->Text = L"�����";
			this->SizeChanged += gcnew System::EventHandler(this, &SimplePaintForm::SimplePaintForm_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int w = 80, h = 60;	// ������ �����
		int ws = w / 3;	// ������ ������ (���� �� ���� ������������ �����)
		int x0, y0; // ���������� ������ �������� ���� ����� 
		int x, y; // ���������� ������ �������� ���� ������

		// ��������� ���� � ������ �����:
		x0 = (this->ClientSize.Width - w) / 2; // ������ ���������� ������� ����� 
		y0 = (this->ClientSize.Height - h) / 4;// ������ ���������� ������� ����� 
		// ������ ���� 
		// ������� ������ 
		x = x0;
		y = y0;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Green, x, y, ws, h);
		// ����� ������ 
		x = x + ws + 1;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::White, x, y, ws, h);
		// ��������� ������ 
		x = x + ws + 1;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Orange, x, y, ws, h);
		// ���������
		e->Graphics->DrawRectangle
		(System::Drawing::Pens::Black, x0, y0, w, h);
		// ������� (������� �����)
		e->Graphics->DrawString("��������", this->Font, Brushes::Black, x0 + 14, y0 + h + 10);

		//������ ���������� ����
		int hw = h / 3;
		x0 = x0;
		y0 = y0 + h * 3/2;
		x = x0;
		y = y0;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::White, x, y, w, hw);
		// ����� ������ 
		y = y + hw;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Blue, x, y, w, hw);
		// ��������� ������ 
		y = y + hw;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Red, x, y, w, hw);
		// ���������
		e->Graphics->DrawRectangle
		(System::Drawing::Pens::Black, x0, y0, w, h);
		// ������� (������� �����)
		e->Graphics->DrawString("������", this->Font, Brushes::Black, x0 + 20, y0 + h + 10);

	}
	private: System::Void SimplePaintForm_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Refresh(); //�������� �����
	}
	};
}
