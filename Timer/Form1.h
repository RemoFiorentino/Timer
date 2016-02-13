#pragma once
#include <ctime>
#include<time.h>
#include <Windows.h>
#include<stdlib.h>

namespace Timer1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::Windows::Forms::Label^  label1;

	protected: 

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick_1);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(424, 106);
			this->label1->TabIndex = 0;
			this->label1->Text = L"00:00:00";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 159);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
		//global variable to initialize the clock
		clock_t t;


	private: System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
		/*int h = 0, m = 0, s = 0;
		array<String^>^ time = label1->Text->Split(':');
		h = Int32::Parse(time[0]);
		m = Int32::Parse(time[1]);
		s = Int32::Parse(time[2]);
		s = s++;
		if (s == 60) {
			s = 0;
			m = m++;
			if (m == 60) {
				m = 0;
				h = h++;
			}
		}
		if (h < 10) {
			time[0] = "0" + h;
		}
		else {
			time[0] = "" + h;
		}
		if (m < 10) {
			time[1] = "0" + m;
		}
		else {
			time[1] = "" + m;
		}
		if (s < 10) {
			time[2] = "0" + s;
		}
		else {
			time[2] = "" + s;
		}
		label1->Text = time[0] + ":" + time[1] + ":" + time[2];
		Solution works great on seconds, but when comming to miliseconds it is very imprecise.
		As a solution i think a second timer that actually gets the correct count of miliseconds
		and the same timer used here to print the time that the other timer has at the moment.
		*/
		int ms = 0, m = 0, s = 0;
		String^ MS, ^M, ^S;
		clock_t tempClock;
		tempClock = clock() - t;
		if (tempClock < 1000) {
			ms = tempClock / 10;
		}
		else {
			ms = (tempClock % 1000) / 10;
		}

		m = Convert::ToInt32(label1->Text->Substring(0, 2));

		if (ms < 10) MS = "0" + ms;
		else MS = "" + ms;

		s = tempClock / 1000;
		if (s < 10) S = "0" + s;
		else S = "" + s;

		if (s >= 60) {
			m++;
			t = clock();
		}
		if (m < 10) M = "0" + m;
		else M = "" + m;
		label1->Text = M + ":" + S + ":" + MS;


	}
};
}

