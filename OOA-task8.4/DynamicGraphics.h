#pragma once

namespace OOAtask84 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ DynamicGraphics
	/// </summary>
	public ref class DynamicGraphics : public System::Windows::Forms::Form
	{
	public:
		DynamicGraphics(void)
		{
			InitializeComponent();
			// g - графическа€ поверхность 
			g = this->CreateGraphics();
			R = 70;
			// установим размер формы
			// в соответствии с размером циферблата
			this->ClientSize =
				System::Drawing::Size((R + 30) * 2, (R + 30) * 2);
			x0 = R + 30;
			y0 = R + 30;
			// ќпределить положение стрелок.
			// ”гол между метками часов(цифрами) Ч 30 градусов.
			// ”гол между метками минут - 6 градусов.
			// ”гол отсчитываем от 12-ти часов
			ahr = 90 - DateTime::Now.Hour * 30 - (DateTime::Now.Minute / 12) * 6;
			amin = 90 - DateTime::Now.Minute * 6;
			asec = 90 - DateTime::Now.Second * 6;
			timer1->Interval = 1000; // период сигнала от таймера 1 с 
			timer1->Enabled = true; // пуск таймера
		}

	private:
		// графическа€ поверхность
		Graphics^ g;
		int R; // радиус циферблата
		int x0, y0;	// центр циферблата
		int ahr, amin, asec; // положение стрелок (угол)

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->Text = L"„асы";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DynamicGraphics::DynamicGraphics_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

		//сигнал от таймера
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// нарисовать стрелки
		DrawClock();
	}
	private: System::Void DynamicGraphics_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int x, y; // координаты маркера на циферблате 
		int a; // угол между ќ’ и пр€мой (х0,уо) (х,у)
		int h; // метка часовой риски
		a = 0; // метки ставим от 3 -х часов против часовой стрелки
		h = 3; // угол 0 градусов Ч это 3 часа
#define TORAD 0.0174532
			   // циферблат
		while (a < 360)
		{
			x = x0 + R * Math::Cos(a * TORAD);
			y = x0 - R * Math::Sin(a * TORAD);
			// Forml->Canvas->MoveTo(x,y);
			if ((a % 30) == 0)
			{
				g->DrawEllipse(Pens::Black, x - 2, y - 2, 3, 3);
				// цифры по большему радиусу
				x = x0 + (R + 15) * Math::Cos(a * TORAD);
				y = x0 - (R + 15) * Math::Sin(a * TORAD);
				g->DrawString(h.ToString(),
					this->Font, Brushes::Black, x - 5, y - 7);
				h--;
				if (h == 0) h = 12;

			}
			else
				g->DrawEllipse(Pens::Black, x - 1, y - 1, 1, 1);
			a = a + 6; // 1 минута - 6 градусов
		}
		// стрелки
		DrawClock();
	}

		   // –исует вектор из точки (х0,у0) под
		   // углом а относительно оси X
		   // L - длина вектора
		   void Vector(float х0, float у0, float a, float l, System::Drawing::Pen^ aPen)
		   {
			   // x0,y0 - начало вектора
			   //a - угол между осью х и вектором
			   // l - длина вектора
			   // коэфф. пересчета угла из градусов в радианы
#define TORAD 0.0174532
			   float х, у; // координаты конца вектора
			   х = х0 + l * Math::Cos(a * TORAD);
			   у = у0 - l * Math::Sin(a * TORAD);
			   g->DrawLine(aPen, х0, у0, х, у);
		   }

		   // рисует стрелки
		   void DrawClock(void)
		   {
			   // карандаши дл€ рисовани€ стрелок
			   Pen^ hPen = gcnew Pen(Color::LightBlue, 3);
			   Pen^ mPen = gcnew Pen(Color::LightBlue, 3);
			   Pen^ sPen = gcnew Pen(Color::Black, 2);
			   // карандаш дл€ стирани€ стрелок
			   Pen^ cPen = gcnew Pen(SystemColors::Control, 4);
			   // шаг секундной и минутной стрелок б градусов,
			   // часовой Ч 30.
			   // стереть изображение стрелок:
			   Vector(x0, y0, ahr, R - 20, cPen); // часовую
			   Vector(x0, y0, amin, R - 15, cPen); // минутную
			   Vector(x0, y0, asec, R - 7, cPen); // секундную
				// новое положение стрелок
			   ahr = 90 - DateTime::Now.Hour * 30 - (DateTime::Now.Minute / 12) * 6;
			   amin = 90 - DateTime::Now.Minute * 6; asec = 90 - DateTime::Now.Second * 6;
			   // нарисовать стрелки:
			   // часовую
			   Vector(x0, y0, ahr, R - 20, hPen);
			   // минутную
			   Vector(x0, y0, amin, R - 15, mPen);
			   // секундную
			   Vector(x0, y0, asec, R - 7, sPen);
			   //g->DrawEllipse(Pens::Black,x0-2,y0-2,4,4); 
			   g->FillEllipse(Brushes::Black, x0 - 3, y0 - 3, 6, 6);
		   }
	};
}
