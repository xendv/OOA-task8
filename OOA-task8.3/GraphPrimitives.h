#pragma once

namespace OOAtask83 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ GraphPrimitives
	/// </summary>
	public ref class GraphPrimitives : public System::Windows::Forms::Form
	{
	public:
		GraphPrimitives(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
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
			this->pictureBox1->Size = System::Drawing::Size(495, 484);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraphPrimitives::pictureBox1_Paint);
			// 
			// GraphPrimitives
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 484);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"GraphPrimitives";
			this->Text = L"GraphPrimitives";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// графическа€ поверхность
		System::Drawing::Graphics^ g = e->Graphics;
		double x0 = (this->ClientSize.Width) / 2; // ширина внутренней области формы 
		double y0 = (this->ClientSize.Height) / 6;

		//рисуем правильный п€тиугольник (8.3.а)
		int r = 50, a = 0; //длина стороны и начальный угол 
		double pi = 3.14;
		y0 += r;
		// массив точек 
		array<Point>^ p = { Point(x0, y0), Point(x0, y0), Point(x0, y0), Point(x0, y0),
		Point(x0, y0), Point(x0, y0) };
		// изменение координат точек кривой
		for (int i = 0; i < 5; i++)
		{
			p[i].X = x0 + r * Math::Cos(a * pi / 180);
			p[i].Y = y0 - r * Math::Sin(a * pi / 180);
			a = a + 180 - (5 - 2) * 180 / 5; //отклонение
		}
		p[5].X = p[0].X; p[5].Y = p[0].Y; // дл€ закольцевани€
		
		// рисование ломаной линии 
		g->DrawLines(Pens::DodgerBlue, p);

		double x = x0, y = y0 + r * 3 / 2;
		r = 7;
		//рисуем точку (8.3.б)
		g->FillEllipse(Brushes::ForestGreen, x-r/2, y, r, r);

		//рисуем круговую диаграмму (8.3.в)
		r =100;
		x = x0  *2 / 3 - r/4 + 5;
		//x -= r/2;
		y +=40;
		//рамка
		Pen^ aPen = gcnew Pen(Color::Black,1);
		g->DrawRectangle(aPen, x-10, y-20, 2*r+30, r+30);
		aPen->Width = 2;
		g->DrawEllipse(aPen, x, y, r, r);
		//сектора
		g->FillPie(Brushes::LightSteelBlue,
			System::Drawing::Rectangle(x, y, r, r), 0, 90);
		g->FillPie(Brushes::DarkBlue,
			System::Drawing::Rectangle(x, y, r, r), 90, 110);
		g->FillPie(Brushes::DarkViolet,
			System::Drawing::Rectangle(x, y, r, r), 200, 20);
		g->FillPie(Brushes::MediumPurple,
			System::Drawing::Rectangle(x, y, r, r), 220, 150);
		//подписи к диаграмме
		g->DrawString("∆анры книг в наличии", this->Font, Brushes::Black, x + 50, y - 15);
		x = x +  r + 20; y += 10;
		g->FillRectangle(Brushes::LightSteelBlue, x, y, 10, 5);
		g->DrawString("‘антастика", this->Font, Brushes::Black, x + 15, y-5);
		y += 15;
		g->FillRectangle(Brushes::DarkBlue, x, y, 10, 5);
		g->DrawString(" лассика", this->Font, Brushes::Black, x + 15, y - 5);
		y += 15;
		g->FillRectangle(Brushes::DarkViolet, x, y, 10, 5);
		g->DrawString("”чебна€", this->Font, Brushes::Black, x + 15, y - 5);
		y += 15;
		g->FillRectangle(Brushes::MediumPurple, x, y, 10, 5);
		g->DrawString("Ёнциклопедии", this->Font, Brushes::Black, x + 15, y - 5);

	}
	};
}
