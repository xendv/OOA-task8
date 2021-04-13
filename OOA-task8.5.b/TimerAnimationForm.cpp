#include "TimerAnimationForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	OOAtask85b::TimerAnimationForm form;
	Application::Run(% form);
	return 0;
}