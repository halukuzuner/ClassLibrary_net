#include "pch.h"
#include "ModelessForm.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(array<String^>^ args)

{

   Application::EnableVisualStyles(); Application::SetCompatibleTextRenderingDefault(false); ClassLibrarynet::ModelessForm form; Application::Run(% form);

}