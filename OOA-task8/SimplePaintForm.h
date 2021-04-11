#pragma once

namespace OOAtask8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SimplePaintForm
	/// </summary>
	public ref class SimplePaintForm : public System::Windows::Forms::Form
	{
	public:
		SimplePaintForm(void)
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->Text = L"Флаги";
			this->SizeChanged += gcnew System::EventHandler(this, &SimplePaintForm::SimplePaintForm_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int w = 80, h = 60;	// размер флага
		int ws = w / 3;	// ширина полосы (флаг из трех вертикальных полос)
		int x0, y0; // координаты левого верхнего угла флага 
		int x, y; // координаты левого верхнего угла полосы

		// разместим флаг в центре формы:
		x0 = (this->ClientSize.Width - w) / 2; // ширина внутренней области формы 
		y0 = (this->ClientSize.Height - h) / 4;// высота внутренней области формы 
		// рисуем флаг 
		// зеленая полоса 
		x = x0;
		y = y0;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Green, x, y, ws, h);
		// белая полоса 
		x = x + ws + 1;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::White, x, y, ws, h);
		// оранжевая полоса 
		x = x + ws + 1;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Orange, x, y, ws, h);
		// окантовка
		e->Graphics->DrawRectangle
		(System::Drawing::Pens::Black, x0, y0, w, h);
		// подпись (шрифтом формы)
		e->Graphics->DrawString("Ирландия", this->Font, Brushes::Black, x0 + 14, y0 + h + 10);

		//рисуем российский флаг
		int hw = h / 3;
		x0 = x0;
		y0 = y0 + h * 3/2;
		x = x0;
		y = y0;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::White, x, y, w, hw);
		// белая полоса 
		y = y + hw;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Blue, x, y, w, hw);
		// оранжевая полоса 
		y = y + hw;
		e->Graphics->FillRectangle
		(System::Drawing::Brushes::Red, x, y, w, hw);
		// окантовка
		e->Graphics->DrawRectangle
		(System::Drawing::Pens::Black, x0, y0, w, h);
		// подпись (шрифтом формы)
		e->Graphics->DrawString("Россия", this->Font, Brushes::Black, x0 + 20, y0 + h + 10);

	}
	private: System::Void SimplePaintForm_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Refresh(); //обновить форму
	}
	};
}
