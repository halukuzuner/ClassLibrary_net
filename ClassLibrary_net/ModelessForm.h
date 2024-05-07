#pragma once

namespace ClassLibrarynet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class ModelessForm : public System::Windows::Forms::Form
	{
	public:
      ModelessForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModelessForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
      System::Windows::Forms::Button^ btnExit;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
         this->btnExit = (gcnew System::Windows::Forms::Button());

         // 
         // btnExit
         // 
         this->btnExit->Location = System::Drawing::Point(this->Location.X + this->Size.Width, this->Location.Y + this->Size.Height-25);
         this->btnExit->Name = L"btnExit";
         this->btnExit->Size = System::Drawing::Size(72, 22);
         this->btnExit->TabIndex = 1;
         this->btnExit->Text = L"&Exit";
         this->btnExit->UseVisualStyleBackColor = true;
         this->btnExit->Click += gcnew System::EventHandler(this, &ModelessForm::btnExit_Click);
         // 
         // ModelessForm
         //
         this->Location = System::Drawing::Point(200, 200);
         this->Size = System::Drawing::Size(600, 300);
         this->MaximizeBox = false;
         this->Text = L"ModelessForm" + "  Location: " + this->Location.ToString() + "   Size: " + this->Size.ToString();
         this->Padding = System::Windows::Forms::Padding(0);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         //this->ClientSize = System::Drawing::Size(734, 361);
         this->Controls->Add(this->btnExit);
		}
#pragma endregion
      private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
      {
         this->Close();
      }
	};
}
