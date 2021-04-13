#pragma once

namespace OOAtask85 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� BitmapsAnimationForm
	/// </summary>
	public ref class BitmapsAnimationForm : public System::Windows::Forms::Form
	{
	public:
		Bitmap^ sky; //������ "����"
		Bitmap^ plane; //������ "������"

		BitmapsAnimationForm(void)
		{
			InitializeComponent();
			//�������� ����������� �� ������:
			try {
				sky = gcnew System::Drawing::Bitmap
				(Application::StartupPath + "\\sky.bmp");
				plane = gcnew System::Drawing::Bitmap
				(Application::StartupPath + "\\plane.bmp");
			}
			catch (System::Exception^ e)
			{
				MessageBox::Show("������ �������� �������� ������" + e->Message, "�����",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close();// ��������� �����
				return;
			}
			// ������ ����� = ������� �������� �������
			this->ClientSize = sky->Size;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~BitmapsAnimationForm()
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
		System::ComponentModel::Container ^components;

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
			this->pictureBox1->Size = System::Drawing::Size(540, 400);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SizeChanged += gcnew System::EventHandler(this, &BitmapsAnimationForm::pictureBox1_SizeChanged);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BitmapsAnimationForm::pictureBox1_Paint);
			// 
			// BitmapsAnimationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 400);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"BitmapsAnimationForm";
			this->Text = L"BitmapsAnimationForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (sky != nullptr)
		{
			//������� ������� �������
			e->Graphics->DrawImage(sky,0,0);
		}
		if (plane != nullptr)
		{
			//����� ������
			plane->MakeTransparent(); // ������� ���������� ���

			e->Graphics->DrawImage(plane, 70, 50);
			//������ ������
			plane->MakeTransparent(); // ������� ���������� ���
			e->Graphics->DrawImage(plane, 300, 80);
		}
	}
	private: System::Void pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	};
}
