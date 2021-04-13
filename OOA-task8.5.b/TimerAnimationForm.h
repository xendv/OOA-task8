#pragma once

namespace OOAtask85b {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ TimerAnimationForm
	/// </summary>
	public ref class TimerAnimationForm : public System::Windows::Forms::Form
	{
	public:
		TimerAnimationForm(void)
		{
			InitializeComponent();
			try
			{
				sky = gcnew System::Drawing::Bitmap
				(Application::StartupPath + "\\sky.bmp");
				plane = gcnew System::Drawing::Bitmap
				(Application::StartupPath + "\\plane.bmp");
			}
			catch (System::Exception^ e)
			{
				MessageBox::Show(
					"ќшибка загрузки битового образа: "
					+ e->Message,
					"ѕолет",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				this->Close();// закрываем форму return;
			}
			// сделать прозрачным фон
			plane->MakeTransparent();
			// установить размер формы равный
			// размеру фонового рисунка
			this->ClientSize = sky->Size;
			// задать фоновый рисунок формы
			this->BackgroundImage = gcnew Bitmap(sky);
			// определ€ем графическую поверхность g
			g = this->CreateGraphics();
			// инициализаци€ генератора случ. чисел
			rnd = gcnew System::Random();
			// исходное положение самолета
			rct.X = -40;
			rct.Y = 20 + rnd->Next(20);
			rct.Width = plane->Width;
			rct.Height = plane->Height;
			/*
			скорость полета определ€етс€ периодом
			следовани€ сигналов от таймера и величиной
			приращени€ координаты X */
			dx = 2; // скорость полета Ч 2 пиксела/тик_таймера
			timer1->Interval = 20;
			timer1->Enabled = true;
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	private:
		Bitmap^ sky;

		Bitmap^ plane;
		// рабоча€ графическа€ поверхность
		Graphics^ g;
		// приращение координаты X, определ€ет скорость полета
		int dx;
		// область, в которой находитс€ объект
		Rectangle rct;
		// генератор случайных чисел
		System::Random^ rnd;
		/*
 private: System::Void InitializeComponent() {
	 this->components = (gcnew System::ComponentModel::Container());
	 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
	 this->SuspendLayout();
	 //
	 // timer1
	 //
	 this->timer1->Tick += gcnew System::EventHandler(this, &TimerAnimationForm::timer1_Tick);
	 //
	 // TimerAnimationForm
	 //
	 this->ClientSize = System::Drawing::Size(284, 261);
	 this->Name = L"TimerAnimationForm";
	 this->ResumeLayout(false);

 }*/

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~TimerAnimationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
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
			this->timer1->Tick += gcnew System::EventHandler(this, &TimerAnimationForm::timer1_Tick);
			// 
			// TimerAnimationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"TimerAnimationForm";
			this->Text = L"TimerAnimationForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		g->DrawImage(sky,
			Rectangle(rct.X, rct.Y, rct.Width, rct.Height),
			Rectangle(rct.X, rct.Y, rct.Width, rct.Height),
			GraphicsUnit::Pixel);
		// вычислить новое положение объекта
		if (rct.X < this->ClientRectangle.Width)
			rct.X += dx;
		else
		{
			// объект достиг правой границы,
			// перемещаем его к левой границе
			rct.X = -40;
			rct.Y = 20 + rnd->Next(40);
			// скорость полета от 2 до 5
			// пикселов/тик_таймера
			dx = 2 + rnd->Next(4);
		}
		g->DrawImage(plane, rct.X, rct.Y);
	}
	};
}