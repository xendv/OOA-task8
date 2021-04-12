#pragma once

namespace OOAtask82 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для BrushSamplesForm
	/// </summary>
	public ref class BrushSamplesForm : public System::Windows::Forms::Form
	{
	public:
		BrushSamplesForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->pictureBox1->Size = System::Drawing::Size(562, 374);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->ClientSizeChanged += gcnew System::EventHandler(this, &BrushSamplesForm::pictureBox1_ClientSizeChanged);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BrushSamplesForm::pictureBox1_Paint);
			// 
			// BrushSamplesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 374);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"BrushSamplesForm";
			this->Text = L"BrushSamplesForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// графическая поверхность
		System::Drawing::Graphics^ g = e->Graphics;
		int w = 100, h = 200; //ширина и высота буквы
		int x0 = (this->ClientSize.Width - w) / 4; // ширина внутренней области формы 
		int y0 = (this->ClientSize.Height - h) / 4;

		//создаём карандаш толщиной 4 пиксела 
		System::Drawing::Pen^ aPen; 
		aPen = gcnew Pen(Color::DarkViolet,4);
		aPen->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDot; //пунктир
		g->DrawLine(aPen, x0, y0, x0, y0+h);
		g->DrawLine(aPen, x0, y0+h/2, x0+w, y0);
		g->DrawLine(aPen, x0, y0 + h / 2, x0 + w, y0+h);
		int x, y;
		x = x0 + w + 10;
		y = y0 + h;
		aPen->DashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
		g->DrawEllipse(aPen, x, y - w / 20, w / 20, w / 20);
		x = x + 10;
		y = y0 - 40;

		//создаём HatchBrush-кисть
		System::Drawing::Drawing2D::HatchBrush^ myBrush;
		myBrush = gcnew System::Drawing::Drawing2D::HatchBrush
		(System::Drawing::Drawing2D::HatchStyle::DottedDiamond, //стиль штриха
			Color::White, //цвет штриха
			Color::DarkTurquoise); //цвет фона
		System::Drawing::Font^ aFont = gcnew System::Drawing::Font("Arial", 190);
		g->DrawString("Д.", aFont, myBrush, x, y);
		//g->FillRectangle(myBrush, 10, 10, 250, 250);

		//System::Drawing::Brush^ aBrush;
		//aBrush = gcnew System::Drawing::TextureBrush ();
		//рисуем этим карандашом 
		//g->DrawRectangle(aPen,x0,y0,100,100);
		//System::Drawing::Font^ aFont;
			//aFont = gcnew Font("Arial", 16);
		//g->DrawString("K.", aFont,Brushes::AliceBlue,x0+10,y0+10);

		//изменяем толщину и цвет карандаша 
		/*aPen->Width = 4; 
		aPen->Color = Color::Green;
		//рисуем
		g->DrawRectangle(aPen, 20, 20, 100, 100);
		//снова меняем толщину, цвет, а также стиль 
		aPen->Width =1; 
		aPen->Color = Color::Purple;
		aPen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash; //пунктир 
		//рисуем пунктиром
		g->DrawRectangle(aPen, 30, 30, 100, 100);*/
	}
	private: System::Void pictureBox1_ClientSizeChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Refresh();
	}
	};
}
