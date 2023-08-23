#include "MyForm.h"
#include <stdio.h>
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;



float size;
int flag;
bool prov;


struct koordinati {
    int x, y;
};

koordinati mouse, k_phigur, dop1;

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    form::MyForm form; 
    Application::Run(% form);
}

System::Void form::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    points = gcnew List<Point>();
    Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
    Img_dop = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
    canvas = Graphics::FromImage(Img);
    dop=Graphics::FromImage(Img_dop);
    pictureBox1->Image = Img;
    pictureBox1->BackColor = Color::White;
}




// Кнопка цвета
System::Void form::MyForm::buttoncolor_Click(System::Object^ sender, System::EventArgs^ e)
{  
    colorDialog1->ShowDialog();
    color = colorDialog1->Color;
    pictureBox2->BackColor = color;
    if (flag == 1 || flag == 4 || flag == 5 || flag == 6 || flag == 3 || flag==7 || flag==8) {
        mySolidBrush = gcnew SolidBrush(color);
        pen = gcnew Pen(color, size);
        myHatchBrush = gcnew HatchBrush(Drawing2D::HatchStyle::Horizontal, color);
    }
    else if (flag == 2) {
        pen = gcnew Pen(pictureBox1->BackColor, size);
    }
}

//Открыть файл

System::Void form::MyForm::open_file(System::Object^ sender, System::EventArgs^ e) {
    String^ FileName;
    openFileDialog1->ShowDialog();
    FileName = openFileDialog1->FileName;

    if (FileName == "openFileDialog1") 
        return;
    background = gcnew Bitmap(FileName);
    this->Width = background->Width;
    this->Height = background->Height;
    canvas = Graphics::FromImage(background);
    pictureBox1->Image = background;
}

// Сохранить как
System::Void form::MyForm::save_as(System::Object^ sender, System::EventArgs^ e) {
    String^ filename;
    saveFileDialog1->ShowDialog();
    if (filename == "")
    {
        return;
    }
    else {
        filename = saveFileDialog1->FileName;
        Bitmap^ Img = gcnew Bitmap(pictureBox1->Image);
        Img->Save(filename);
    }
}

//Толщина
System::Void form::MyForm::size_click(System::Object^ sender, System::EventArgs^ e) {
    size = Convert::ToSingle(numericUpDown1->Value);
    if (flag == 1 || flag == 4 || flag == 5 || flag==6 || flag==3)
        pen = gcnew Pen(color, size);
    else if (flag == 2 ) {
        pen = gcnew Pen(pictureBox1->BackColor, size);
    }
}

//Карандаш

System::Void form::MyForm::pen_click(System::Object^ sender, System::EventArgs^ e) {
    pen= gcnew Pen(color, size);
    flag = 1;
}
// Ластик
System::Void form::MyForm::eraser_click(System::Object^ sender, System::EventArgs^ e) {
    pen = gcnew Pen(pictureBox1->BackColor, size);
    flag = 2;
}
//Прямоугольник
System::Void form::MyForm::rectangle_click(System::Object^ sender, System::EventArgs^ e) {
    pen = gcnew Pen(color, size);
    flag = 4;
}
//Окружность
System::Void form::MyForm::circle_click(System::Object^ sender, System::EventArgs^ e) {
    pen = gcnew Pen(color, size);
    flag = 5;
}

//Кисть заливки окружности
System::Void form::MyForm::BrushEl_Click(System::Object^ sender, System::EventArgs^ e) {
    mySolidBrush = gcnew SolidBrush(color);
    flag = 3;
}

//Кисть прямоугольниками
System::Void form::MyForm::BrushRec_Click(System::Object^ sender, System::EventArgs^ e) {
    mySolidBrush = gcnew SolidBrush(color);
    flag = 6;
}
//Кисть штриховка прямоугольника
System::Void form::MyForm::ShtrBrush_Click(System::Object^ sender, System::EventArgs^ e) {
    myHatchBrush = gcnew HatchBrush(Drawing2D::HatchStyle::Horizontal, color);
    flag = 8;
}

//Кисть окружностями
System::Void form::MyForm::TBrush_Click(System::Object^ sender, System::EventArgs^ e) {
    mySolidBrush = gcnew SolidBrush(color);
    flag = 7;
}

//Нажатие мышки
System::Void form::MyForm:: mouse_down(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    Img_dop = gcnew Bitmap(pictureBox1->Image);
    if (flag == 1 || flag == 2) {
        points->Clear();
        points->Add(e->Location);
        prov = true;
    }
    else if (flag == 4 || flag == 5 || flag==3 || flag == 6 || flag==7 || flag==8) {
        mouse.x = e->Location.X;
        mouse.y = e->Location.Y;
        prov = true;
        dop1.x = mouse.x;
        dop1.y = mouse.y;
    }
    else prov = false;
        pictureBox1->Invalidate();
}


//Движение мышкой
System::Void form::MyForm::mouse_move(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    if (prov && points->Contains(Point(e->X, e->Y)) == false) {
        points->Add(e->Location);
        pictureBox1->Invalidate();
    }
    k_phigur.x = e->Location.X;
    k_phigur.y = e->Location.Y;
    if (flag == 7 && prov) {
        canvas->FillEllipse(mySolidBrush, dop1.x, dop1.y, k_phigur.x - dop1.x, k_phigur.y - dop1.y);
        pictureBox1->Invalidate();
        dop1.x = k_phigur.x;
        dop1.y = k_phigur.y;
   }    
}

//Отжатие мышки
System::Void form::MyForm::mouse_up(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    if (flag == 4) {
    
        canvas->DrawRectangle(pen, mouse.x, mouse.y, k_phigur.x - mouse.x, k_phigur.y - mouse.y);

        pictureBox1->Invalidate();
    }
    else 
    if (flag == 5) {
        canvas->DrawEllipse(pen, mouse.x, mouse.y, k_phigur.x - mouse.x, k_phigur.y - mouse.y);
        pictureBox1->Invalidate();
    }
    else if (flag ==3 ) {
        canvas->FillEllipse(mySolidBrush, mouse.x, mouse.y, k_phigur.x - mouse.x, k_phigur.y - mouse.y);
        pictureBox1->Invalidate();
    }
    else if (flag == 6) {
        canvas->FillRectangle(mySolidBrush, mouse.x, mouse.y, k_phigur.x - mouse.x, k_phigur.y - mouse.y);
        pictureBox1->Invalidate();
    }
    else if (flag == 8) {
        canvas->FillRectangle(myHatchBrush, mouse.x, mouse.y, k_phigur.x - mouse.x, k_phigur.y - mouse.y);
        pictureBox1->Invalidate();
    }
   // pictureBox1->Image = Img;
    prov = false;
}

//Рисование
System::Void form::MyForm:: Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
   // Bitmap^ Img_dop = gcnew Bitmap(pictureBox1->Image);
    if ((flag == 1 || flag == 2) && points->Count > 1) {
            canvas->DrawCurve(pen, points->ToArray());
    }
    //pictureBox1->Image = Img;
}


