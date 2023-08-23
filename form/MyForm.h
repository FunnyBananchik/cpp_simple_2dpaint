#pragma once

namespace form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			openFileDialog1->Filter = "Файлы изображения (*.bmp)|*.bmp";
			saveFileDialog1->Filter = "Файлы изображения (*.bmp)|*.bmp";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button_pen;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ ОткрытьКакToolStripMenuItem;
	private: System::Windows::Forms::Button^ button_rectangle;
	private: System::Windows::Forms::Button^ button_circle;
	private: System::Windows::Forms::Button^ button_eraser;
	private: System::Windows::Forms::Button^ button_color;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьКакToolStripMenuItem1;



	private: System::Windows::Forms::Button^ button_el;
	private: System::Windows::Forms::Button^ button_rec;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;






		  


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
			this->button_pen = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ОткрытьКакToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьКакToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_rectangle = (gcnew System::Windows::Forms::Button());
			this->button_circle = (gcnew System::Windows::Forms::Button());
			this->button_eraser = (gcnew System::Windows::Forms::Button());
			this->button_color = (gcnew System::Windows::Forms::Button());
			this->button_el = (gcnew System::Windows::Forms::Button());
			this->button_rec = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button_pen
			// 
			this->button_pen->Location = System::Drawing::Point(1263, 84);
			this->button_pen->Name = L"button_pen";
			this->button_pen->Size = System::Drawing::Size(102, 37);
			this->button_pen->TabIndex = 1;
			this->button_pen->Text = L"Карандаш";
			this->button_pen->UseVisualStyleBackColor = true;
			this->button_pen->Click += gcnew System::EventHandler(this, &MyForm::pen_click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-40, 127);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(2000, 800);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mouse_down);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mouse_move);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mouse_up);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1360, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ОткрытьКакToolStripMenuItem,
					this->сохранитьКакToolStripMenuItem1
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(59, 24);
			this->toolStripMenuItem1->Text = L"Файл";
			// 
			// ОткрытьКакToolStripMenuItem
			// 
			this->ОткрытьКакToolStripMenuItem->Name = L"ОткрытьКакToolStripMenuItem";
			this->ОткрытьКакToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			this->ОткрытьКакToolStripMenuItem->Text = L"Открыть";
			this->ОткрытьКакToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::open_file);
			// 
			// сохранитьКакToolStripMenuItem1
			// 
			this->сохранитьКакToolStripMenuItem1->Name = L"сохранитьКакToolStripMenuItem1";
			this->сохранитьКакToolStripMenuItem1->Size = System::Drawing::Size(192, 26);
			this->сохранитьКакToolStripMenuItem1->Text = L"Сохранить как";
			this->сохранитьКакToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::save_as);
			// 
			// button_rectangle
			// 
			this->button_rectangle->Location = System::Drawing::Point(1116, 41);
			this->button_rectangle->Name = L"button_rectangle";
			this->button_rectangle->Size = System::Drawing::Size(141, 37);
			this->button_rectangle->TabIndex = 5;
			this->button_rectangle->Text = L"Прямоугольник";
			this->button_rectangle->UseVisualStyleBackColor = true;
			this->button_rectangle->Click += gcnew System::EventHandler(this, &MyForm::rectangle_click);
			// 
			// button_circle
			// 
			this->button_circle->Location = System::Drawing::Point(1116, 84);
			this->button_circle->Name = L"button_circle";
			this->button_circle->Size = System::Drawing::Size(141, 37);
			this->button_circle->TabIndex = 6;
			this->button_circle->Text = L"Окружность";
			this->button_circle->UseVisualStyleBackColor = true;
			this->button_circle->Click += gcnew System::EventHandler(this, &MyForm::circle_click);
			// 
			// button_eraser
			// 
			this->button_eraser->Location = System::Drawing::Point(1263, 41);
			this->button_eraser->Name = L"button_eraser";
			this->button_eraser->Size = System::Drawing::Size(102, 36);
			this->button_eraser->TabIndex = 7;
			this->button_eraser->Text = L"Ластик";
			this->button_eraser->UseVisualStyleBackColor = true;
			this->button_eraser->Click += gcnew System::EventHandler(this, &MyForm::eraser_click);
			// 
			// button_color
			// 
			this->button_color->Location = System::Drawing::Point(0, 33);
			this->button_color->Name = L"button_color";
			this->button_color->Size = System::Drawing::Size(88, 37);
			this->button_color->TabIndex = 8;
			this->button_color->Text = L"Цвет";
			this->button_color->UseVisualStyleBackColor = true;
			this->button_color->Click += gcnew System::EventHandler(this, &MyForm::buttoncolor_Click);
			// 
			// button_el
			// 
			this->button_el->Location = System::Drawing::Point(888, 41);
			this->button_el->Name = L"button_el";
			this->button_el->Size = System::Drawing::Size(201, 23);
			this->button_el->TabIndex = 12;
			this->button_el->Text = L"Кисть окружности";
			this->button_el->UseVisualStyleBackColor = true;
			this->button_el->Click += gcnew System::EventHandler(this, &MyForm::BrushEl_Click);
			// 
			// button_rec
			// 
			this->button_rec->Location = System::Drawing::Point(888, 70);
			this->button_rec->Name = L"button_rec";
			this->button_rec->Size = System::Drawing::Size(201, 23);
			this->button_rec->TabIndex = 13;
			this->button_rec->Text = L"Кисть прямоугольниками";
			this->button_rec->UseVisualStyleBackColor = true;
			this->button_rec->Click += gcnew System::EventHandler(this, &MyForm::BrushRec_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(741, 41);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 24, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 15;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Click += gcnew System::EventHandler(this, &MyForm::size_click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(94, 33);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(35, 37);
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(888, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(201, 23);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Рисование окружн.";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::TBrush_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(676, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(201, 23);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Штриховка прямоугольника";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::ShtrBrush_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1360, 456);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button_rec);
			this->Controls->Add(this->button_el);
			this->Controls->Add(this->button_color);
			this->Controls->Add(this->button_eraser);
			this->Controls->Add(this->button_circle);
			this->Controls->Add(this->button_rectangle);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button_pen);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	Color color;
	Pen^ pen;
	Bitmap^ Img;
	Bitmap^ Img_dop;
	List <Point>^ points;
	Graphics^ canvas;
	Graphics^ dop;
	SolidBrush^ mySolidBrush;
	Bitmap^ background;
	HatchBrush^ myHatchBrush;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
}
private: System::Void domainUpDown1_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menuStrip2_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton_gr_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   System::Void buttoncolor_Click(System::Object^ sender, System::EventArgs^ e);

	   System::Void open_file(System::Object^ sender, System::EventArgs^ e);

	   System::Void save_as(System::Object^ sender, System::EventArgs^ e);

	   System::Void pen_click(System::Object^ sender, System::EventArgs^ e);

	   System::Void eraser_click(System::Object^ sender, System::EventArgs^ e);

	   System::Void rectangle_click(System::Object^ sender, System::EventArgs^ e);

	   System::Void circle_click(System::Object^ sender, System::EventArgs^ e);

	   System::Void BrushEl_Click(System::Object^ sender, System::EventArgs^ e);

	   System::Void BrushRec_Click(System::Object^ sender, System::EventArgs^ e);

	   System::Void ShtrBrush_Click(System::Object^ sender, System::EventArgs^ e);

	   System::Void TBrush_Click(System::Object^ sender, System::EventArgs^ e);

	   System::Void mouse_down(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	   System::Void mouse_move(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	   System::Void mouse_up(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	   System::Void Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

	   System::Void size_click(System::Object^ sender, System::EventArgs^ e);
	 private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	 
};
}
