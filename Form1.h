#pragma once
#include "Figure.h"
namespace form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::Collections::Generic;

	//global counters to count destroyed ships and number of shots
	int ShipsDestroyed = 0;
	int Shots = 0;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column1;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column2;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column3;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column4;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column5;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column6;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column7;
	private: System::Windows::Forms::DataGridViewImageColumn^  Column8;
	private: System::Windows::Forms::RadioButton^  rb_black;
	private: System::Windows::Forms::RadioButton^  rb_white;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RadioButton^  rb_pawn;
	private: System::Windows::Forms::RadioButton^  rb_king;
	private: System::Windows::Forms::RadioButton^  rb_queen;
	private: System::Windows::Forms::RadioButton^  rb_rook;
	private: System::Windows::Forms::RadioButton^  rb_bishop;
	private: System::Windows::Forms::RadioButton^  rb_knight;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  b_standard;
	private: System::Windows::Forms::Button^  b_place;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  b_remove;
	private: System::Windows::Forms::Button^  b_checkmate;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  nudMoves;




	private:
		/// <summary>
		/// Required designer variable.
		Figure^ selectedFigure;
		Figure^ lastMovedFigure;
		array<Figure^, 2>^ field;
		Coords^ lastMovePreviousCoords;
		bool rookingWhiteLeft,		
			rookingWhiteRight,
			rookingBlackLeft ,
			rookingBlackRight;
	private: System::Windows::Forms::Button^  b_remall;
					 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->b_checkmate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nudMoves = (gcnew System::Windows::Forms::NumericUpDown());
			this->b_remall = (gcnew System::Windows::Forms::Button());
			this->b_remove = (gcnew System::Windows::Forms::Button());
			this->b_standard = (gcnew System::Windows::Forms::Button());
			this->b_place = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->rb_pawn = (gcnew System::Windows::Forms::RadioButton());
			this->rb_king = (gcnew System::Windows::Forms::RadioButton());
			this->rb_queen = (gcnew System::Windows::Forms::RadioButton());
			this->rb_rook = (gcnew System::Windows::Forms::RadioButton());
			this->rb_bishop = (gcnew System::Windows::Forms::RadioButton());
			this->rb_knight = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->rb_white = (gcnew System::Windows::Forms::RadioButton());
			this->rb_black = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudMoves))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->b_checkmate);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->nudMoves);
			this->groupBox1->Controls->Add(this->b_remall);
			this->groupBox1->Controls->Add(this->b_remove);
			this->groupBox1->Controls->Add(this->b_standard);
			this->groupBox1->Controls->Add(this->b_place);
			this->groupBox1->Controls->Add(this->panel2);
			this->groupBox1->Controls->Add(this->panel1);
			this->groupBox1->Location = System::Drawing::Point(16, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(162, 466);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// b_checkmate
			// 
			this->b_checkmate->Location = System::Drawing::Point(10, 397);
			this->b_checkmate->Name = L"b_checkmate";
			this->b_checkmate->Size = System::Drawing::Size(146, 23);
			this->b_checkmate->TabIndex = 8;
			this->b_checkmate->Text = L"Find checkmate";
			this->b_checkmate->UseVisualStyleBackColor = true;
			this->b_checkmate->Click += gcnew System::EventHandler(this, &Form1::b_checkmate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 371);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Moves to checkmate";
			// 
			// nudMoves
			// 
			this->nudMoves->Location = System::Drawing::Point(120, 369);
			this->nudMoves->Name = L"nudMoves";
			this->nudMoves->Size = System::Drawing::Size(36, 20);
			this->nudMoves->TabIndex = 6;
			this->nudMoves->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// b_remall
			// 
			this->b_remall->Location = System::Drawing::Point(10, 335);
			this->b_remall->Name = L"b_remall";
			this->b_remall->Size = System::Drawing::Size(146, 23);
			this->b_remall->TabIndex = 5;
			this->b_remall->Text = L"Remove All";
			this->b_remall->UseVisualStyleBackColor = true;
			this->b_remall->Click += gcnew System::EventHandler(this, &Form1::b_remall_Click);
			// 
			// b_remove
			// 
			this->b_remove->Location = System::Drawing::Point(10, 306);
			this->b_remove->Name = L"b_remove";
			this->b_remove->Size = System::Drawing::Size(146, 23);
			this->b_remove->TabIndex = 5;
			this->b_remove->Text = L"Remove";
			this->b_remove->UseVisualStyleBackColor = true;
			this->b_remove->Click += gcnew System::EventHandler(this, &Form1::b_remove_Click);
			// 
			// b_standard
			// 
			this->b_standard->Location = System::Drawing::Point(10, 277);
			this->b_standard->Name = L"b_standard";
			this->b_standard->Size = System::Drawing::Size(146, 23);
			this->b_standard->TabIndex = 4;
			this->b_standard->Text = L"Standard setting";
			this->b_standard->UseVisualStyleBackColor = true;
			this->b_standard->Click += gcnew System::EventHandler(this, &Form1::b_standard_Click);
			// 
			// b_place
			// 
			this->b_place->Location = System::Drawing::Point(10, 247);
			this->b_place->Name = L"b_place";
			this->b_place->Size = System::Drawing::Size(146, 23);
			this->b_place->TabIndex = 3;
			this->b_place->Text = L"Place";
			this->b_place->UseVisualStyleBackColor = true;
			this->b_place->Click += gcnew System::EventHandler(this, &Form1::b_place_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->rb_pawn);
			this->panel2->Controls->Add(this->rb_king);
			this->panel2->Controls->Add(this->rb_queen);
			this->panel2->Controls->Add(this->rb_rook);
			this->panel2->Controls->Add(this->rb_bishop);
			this->panel2->Controls->Add(this->rb_knight);
			this->panel2->Location = System::Drawing::Point(7, 93);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(149, 139);
			this->panel2->TabIndex = 2;
			// 
			// rb_pawn
			// 
			this->rb_pawn->AutoSize = true;
			this->rb_pawn->Location = System::Drawing::Point(3, 3);
			this->rb_pawn->Name = L"rb_pawn";
			this->rb_pawn->Size = System::Drawing::Size(51, 17);
			this->rb_pawn->TabIndex = 0;
			this->rb_pawn->TabStop = true;
			this->rb_pawn->Text = L"pawn";
			this->rb_pawn->UseVisualStyleBackColor = true;
			// 
			// rb_king
			// 
			this->rb_king->AutoSize = true;
			this->rb_king->Location = System::Drawing::Point(3, 118);
			this->rb_king->Name = L"rb_king";
			this->rb_king->Size = System::Drawing::Size(45, 17);
			this->rb_king->TabIndex = 1;
			this->rb_king->TabStop = true;
			this->rb_king->Text = L"king";
			this->rb_king->UseVisualStyleBackColor = true;
			// 
			// rb_queen
			// 
			this->rb_queen->AutoSize = true;
			this->rb_queen->Location = System::Drawing::Point(3, 95);
			this->rb_queen->Name = L"rb_queen";
			this->rb_queen->Size = System::Drawing::Size(55, 17);
			this->rb_queen->TabIndex = 1;
			this->rb_queen->TabStop = true;
			this->rb_queen->Text = L"queen";
			this->rb_queen->UseVisualStyleBackColor = true;
			// 
			// rb_rook
			// 
			this->rb_rook->AutoSize = true;
			this->rb_rook->Location = System::Drawing::Point(3, 72);
			this->rb_rook->Name = L"rb_rook";
			this->rb_rook->Size = System::Drawing::Size(46, 17);
			this->rb_rook->TabIndex = 1;
			this->rb_rook->TabStop = true;
			this->rb_rook->Text = L"rook";
			this->rb_rook->UseVisualStyleBackColor = true;
			// 
			// rb_bishop
			// 
			this->rb_bishop->AutoSize = true;
			this->rb_bishop->Location = System::Drawing::Point(3, 49);
			this->rb_bishop->Name = L"rb_bishop";
			this->rb_bishop->Size = System::Drawing::Size(56, 17);
			this->rb_bishop->TabIndex = 1;
			this->rb_bishop->TabStop = true;
			this->rb_bishop->Text = L"bishop";
			this->rb_bishop->UseVisualStyleBackColor = true;
			// 
			// rb_knight
			// 
			this->rb_knight->AutoSize = true;
			this->rb_knight->Location = System::Drawing::Point(3, 26);
			this->rb_knight->Name = L"rb_knight";
			this->rb_knight->Size = System::Drawing::Size(54, 17);
			this->rb_knight->TabIndex = 1;
			this->rb_knight->TabStop = true;
			this->rb_knight->Text = L"knight";
			this->rb_knight->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->rb_white);
			this->panel1->Controls->Add(this->rb_black);
			this->panel1->Location = System::Drawing::Point(7, 29);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(149, 48);
			this->panel1->TabIndex = 2;
			// 
			// rb_white
			// 
			this->rb_white->AutoSize = true;
			this->rb_white->Location = System::Drawing::Point(3, 3);
			this->rb_white->Name = L"rb_white";
			this->rb_white->Size = System::Drawing::Size(50, 17);
			this->rb_white->TabIndex = 0;
			this->rb_white->TabStop = true;
			this->rb_white->Text = L"white";
			this->rb_white->UseVisualStyleBackColor = true;
			// 
			// rb_black
			// 
			this->rb_black->AutoSize = true;
			this->rb_black->Location = System::Drawing::Point(3, 26);
			this->rb_black->Name = L"rb_black";
			this->rb_black->Size = System::Drawing::Size(51, 17);
			this->rb_black->TabIndex = 1;
			this->rb_black->TabStop = true;
			this->rb_black->Text = L"black";
			this->rb_black->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Location = System::Drawing::Point(184, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(461, 474);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Snow;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeight = 50;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::Tan;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 16);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridView1->RowTemplate->Height = 50;
			this->dataGridView1->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->ShowCellErrors = false;
			this->dataGridView1->Size = System::Drawing::Size(455, 455);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			this->dataGridView1->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form1::dataGridView1_CellMouseClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"A";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"B";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"C";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 50;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"D";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 50;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"E";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 50;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"F";
			this->Column6->Name = L"Column6";
			this->Column6->Width = 50;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"G";
			this->Column7->Name = L"Column7";
			this->Column7->Width = 50;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"H";
			this->Column8->Name = L"Column8";
			this->Column8->Width = 50;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 490);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudMoves))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
						 System::Collections::Generic::List<Coords^>^ moves;
						 Figure^ f = field[e->RowIndex, e->ColumnIndex];
						 this->selectedFigure = f;
						 if (nullptr != f) {
							 moves = f->getAllMoves(field);
							 for (int i = 0; i < moves->Count; i++) {
								 Coords^ c = moves[i];
								 this->dataGridView1->Rows[c->y]->Cells[c->x]->Selected = true;
							 }
						 }	
					 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
						 this->field = gcnew array<Figure^, 2>(8, 8);
						 this->initTable();
						 placeFigure(gcnew Figure(4, 6, Figure::KING, Figure::WHITE), field);
						 						 placeFigure(gcnew Figure(4, 0, Figure::KING, Figure::BLACK), field);
												 						 placeFigure(gcnew Figure(0, 1, Figure::PAWN, Figure::BLACK), field);
																		 						 placeFigure(gcnew Figure(5, 1, Figure::ROOK, Figure::WHITE), field);
																								 						 placeFigure(gcnew Figure(3, 3, Figure::QUEEN, Figure::WHITE), field);
					 }

					 System::Void initTable() {
						 rookingBlackLeft = rookingBlackRight = rookingWhiteLeft = rookingWhiteRight = false;
						 this->dataGridView1->Rows->Clear();
						 this->dataGridView1->Rows->Add(8);
						 for(int row=0; row<8; row++) {
							 this->dataGridView1->Rows[row]->HeaderCell->Value = L""+(8-row);
						 }
						 int ccolor = Figure::WHITE;
						 for (int i = 0; i < 64; i++) {
							 if (i % 8) {
								 ccolor = (ccolor == Figure::WHITE) ? Figure::BLACK: Figure::WHITE;
							 }
							 this->dataGridView1->Rows[Math::Ceiling(i / 8)]->Cells[i % 8]->Style->BackColor = 
								 (ccolor == Figure::BLACK) ? System::Drawing::Color::DimGray : System::Drawing::Color::WhiteSmoke;
							 this->dataGridView1->Rows[Math::Ceiling(i / 8)]->Cells[i % 8]->Value = Image::FromFile(L"figures/empty.png");
						 }
						 selectedFigure = nullptr;
						 lastMovedFigure = nullptr;
						 lastMovePreviousCoords = nullptr;
					 }

					 System::Void placeFigure(Figure^ f, array<Figure^, 2>^ field) {
						 field[f->y, f->x] = f;
					 }

					 System::Void drawFigure(Figure^ f) {
						 String^ colorDir = (f->color == Figure::WHITE) ? L"white/" : L"black/";
						 String^ figureName = f->getTypeString() + L".png";
						 this->dataGridView1->Rows[f->y]->Cells[f->x]->Value = Image::FromFile(L"figures/" + colorDir + figureName);
					 }

					 System::Void eraseFigure(int x, int y) {
						 this->dataGridView1->Rows[y]->Cells[x]->Value = Image::FromFile(L"figures/empty.png" );
					 }

					 System::Void removeFigure(int x, int y, array<Figure^, 2>^ field) {
						 field[y, x] = nullptr;
					 }
/*

					 bool moveFigure(Figure^ f, int x, int y) {
						 return moveFigure(f, x, y, this->field);
					 }*/
					 void drawField(array<Figure^,2>^ _field) {
						 initTable();
						 Figure^ f = nullptr;
						 for(int x = 0; x <8; x++) {
							 for (int y = 0; y < 8; y++ ) {
								 f = _field[y,x];
								 
								 if (nullptr != f) {
									 if (f->x != x || f->y != y) {
										 throw gcnew Exception(L"Координаты фигуры и её расположение на поле не совпадают");
									 }
									 placeFigure(f, _field);
									 drawFigure(f);
								 }
							 }
						 }
					 }

					 bool moveFigure(Figure^ f, int x, int y, array<Figure^, 2>^ field) {
						 if (nullptr == field) {
							 field = this->field;
						 }
						 Figure^ target = field[y,x];
						 if (nullptr != target && target->color == f->color) {
							 return false;
						 }
						 int prevX = f->x, prevY = f->y;
						 bool isChecked = this->isCheck(f->color, field);
						 bool origRookingsWhiteLeft = rookingWhiteLeft;
						 bool origRookingsWhiteRight = rookingWhiteRight;
						 bool origRookingsBlackLeft = rookingBlackLeft;
						 bool origRookingsBlackRight = rookingBlackRight;
						 if (isChecked) {
							 rookingBlackLeft = rookingBlackRight = rookingWhiteLeft = rookingWhiteRight = false;
						 }
						 bool isLegal = isLegalMove(f, x, y, field);
						 if (isLegal) {
							 if (f->type == Figure::KING && Math::Abs(x - prevX) > 1) {
								 if (x == 6 ) {
									 Figure^ rook = field[f->y, 7];
									 removeFigure(7, f->y, field);
									 rook->x = 5;
									 placeFigure(rook, field);
								 } else {
									 Figure^ rook = field[f->y, 0];
									 removeFigure(0, f->y, field);
 									 rook->x = 3;
									 placeFigure(rook, field);
								 }
							 }
							 removeFigure(f->x, f->y, field);
							 f->x = x;
							 f->y = y;
							 placeFigure(f, field);
							 if (isCheck(f->color)) {
								 if (nullptr == target) {
									 removeFigure(x,y, field);
								 } else {
										placeFigure(target, field);
								 }
								
								 rookingWhiteLeft = origRookingsWhiteLeft;
								 rookingWhiteRight = origRookingsWhiteRight;
								 rookingBlackLeft = origRookingsBlackLeft;
								 rookingBlackRight = origRookingsBlackRight;
								 f->x = prevX;
								 f->y = prevY;
								 placeFigure(f, field);
								 return false;
							 }
							 if(f->type == Figure::ROOK) {
								 if (f->color == Figure::WHITE) {
									 if (prevX == 0) {
										 origRookingsWhiteLeft = false;
									 }
									 if (prevX == 7) {
										 origRookingsWhiteRight = false;
									 }
								 } else {
									 if (prevX == 0) {
										 origRookingsBlackLeft = false;
									 }
									 if (prevX == 7) {
										 origRookingsBlackRight = false;
									 }
								 }
							 }
							 if (f->type == f->KING) {
								 if (f->color == f->BLACK) {
									 origRookingsBlackLeft = false;
									 origRookingsBlackRight = false;
								 } else {
									 origRookingsWhiteLeft = false;
									 origRookingsWhiteRight = false;
								 }
							 }
							 this->lastMovePreviousCoords = gcnew Coords(prevX, prevY);
							 this->lastMovedFigure = f;
							 dataGridView1->ClearSelection();
							 this->selectedFigure = nullptr;
							 rookingWhiteLeft = origRookingsWhiteLeft;
							 rookingWhiteRight = origRookingsWhiteRight;
							 rookingBlackLeft = origRookingsBlackLeft;
							 rookingBlackRight = origRookingsBlackRight;
							 return true;
						 }
						 rookingWhiteLeft = origRookingsWhiteLeft;
						 rookingWhiteRight = origRookingsWhiteRight;
						 rookingBlackLeft = origRookingsBlackLeft;
						 rookingBlackRight = origRookingsBlackRight;
						 return false;
					 }

					 bool isLegalMove(Figure^ orig_offence, int x, int y, array<Figure^, 2>^ field) {
						 //todo check for check
						 Figure^ offence = gcnew Figure(orig_offence);
						 List<Coords^>^ moves = offence->getAllMoves(field);
						 for (int i = 0; i < moves->Count; i++) {
							 if (moves[i]->x == x && moves[i]->y == y) {
								 if (offence->type == Figure::KING && Math::Abs(offence->x - x) > 1) {
									 bool rookingAllowed = true;
									 if (offence->color == Figure::BLACK)
									 {
										 if (offence->x > x) {
											 for (int cx = 0; cx < offence->x; cx++) {
												 if (isTileUnderAttack(cx, offence->y, Figure::WHITE, field)) {
													 return false;
												 }
											 }
											 return rookingBlackLeft;
										 } else {
											 for (int cx = offence->x+1; cx < 8; cx++) {
												 if (isTileUnderAttack(cx, offence->y, Figure::WHITE, field)) {
													 return false;
												 }
											 }
											 return  rookingBlackRight;
										 }											 
									 } else {
										 if (offence->x > x) {
											 for (int cx = 0; cx < offence->x; cx++) {
												 if (isTileUnderAttack(cx, offence->y, Figure::BLACK, field)) {
													 return false;
												 }
											 }
											 return rookingWhiteLeft;
										 } else {
											 for (int cx = offence->x+1; cx < 8; cx++) {
												 if (isTileUnderAttack(cx, offence->y, Figure::BLACK, field)) {
													 return false;
												 }
											 }
											 return  rookingWhiteRight;
										 }
									 }
								 }
								 array<Figure^, 2>^ fieldCpy = (array<Figure^, 2>^)field->Clone();
								 removeFigure(offence->x, offence->y, fieldCpy);
								 offence->x = x; 
								 offence->y=y;
								 placeFigure(offence,fieldCpy);
								 return !isCheck(offence->color, fieldCpy);
							 }
						 }
						 return false;
					 };

					 bool isCheck(int forWhatColor) {
						 return isCheck(forWhatColor, this->field);
					 }

					 bool isCheck(int forWhatColor, array<Figure^, 2>^ field) {
						 Figure^ king = nullptr;
						 Figure^ offence = nullptr;
						 for (int x = 0; x < 8; x++) {
							 for (int y = 0; y < 8; y++) {
								 if (nullptr != field[y, x] && field[y, x]->type == Figure::KING && field[y, x]->color == forWhatColor) {
									 king = field[y, x];
									 break;
								 }
							 }
						 }
						 if (nullptr == king) {
							 MessageBox::Show(L"No king on a desk");
							 return false;
						 }
						 int offenceColor = (forWhatColor == Figure::WHITE) ? Figure::BLACK : Figure::WHITE;
						 for (int x = 0; x < 8; x++) {
							 for (int y = 0; y < 8; y++) {
								 if (nullptr != field[y, x] && field[y, x]->color == offenceColor) {
									 offence = field[y, x];
									 if (this->isLegalMove(offence, king->x, king->y, field)) {
										 return true;
									 }
								 }
							 }
						 }

						 return false;
					 }

					 bool isCheckmate(int forWhatColor, array<Figure^, 2>^ field) {
						 Figure^ king = nullptr;
						 Figure^ defence = nullptr;
						 if (!isCheck(forWhatColor, field)) {
							 return false;
						 }
						 for (int x = 0; x < 8; x++) {
							 for (int y = 0; y < 8; y++) {
								 if (nullptr != field[y, x] && field[y, x]->type == Figure::KING && field[y, x]->color == forWhatColor) {
									 king = field[y, x];
									 break;
								 }
							 }
						 }
						 if (nullptr == king) {
							 MessageBox::Show(L"No king on a desk");
							 return false;
						 }
						 List<Coords^>^ moves = king->getAllMoves(field);
						 for (int m = 0; m < moves->Count; m++) {
							 if (isLegalMove(king, moves[m]->x, moves[m]->y, field)) {
								 return false;
							 }
						 }
						 int defenceColor = forWhatColor; //(forWhatColor == Figure::WHITE) ? Figure::BLACK : Figure::WHITE;
						 for (int x = 0; x < 8; x++) {
							 for (int y = 0; y < 8; y++) {
								 if (nullptr != field[y, x] && field[y, x]->color == defenceColor) {
									 defence = field[y, x];
									 moves = field[y,x]->getAllMoves(field);
									 for (int m = 0; m < moves->Count; m++ ) {
										 if (this->isLegalMove(defence, moves[m]->x, moves[m]->y, field)) {
											 return false;
										 }
									 }
								 }
							 }
							}
						 return true;
					 }

					 bool isTileUnderAttack(int x, int y, int offenceColor, array<Figure^, 2>^ field) {
						 Figure^ target = nullptr;
						 Figure^ offence = nullptr;
						 for (int cx = 0; cx < 8; cx++) {
							 for (int cy = 0; cy < 8; cy++) {
								 if (nullptr != field[cy, cx] && field[cy, cx]->color == offenceColor) {
									 offence = field[cy, cx];
									 if (this->isLegalMove(offence, x, y, field)) {
										 return true;
									 }
								 }
							 }
						 }
						 return false;
					 }


	private: System::Void b_place_Click(System::Object^  sender, System::EventArgs^  e) {
						 int type = Figure::PAWN, color = Figure::WHITE, y = 0, x = 0;
						 if (rb_black->Checked) {
							 color = Figure::BLACK;
						 }
						 if (rb_bishop->Checked) {
							 type = Figure::BISHOP;
						 }
						 if (rb_king->Checked) {
							 type = Figure::KING;
						 }
						 if (rb_knight->Checked) {
							 type = Figure::KNIGHT;
						 }
						 if (rb_queen->Checked) {
							 type = Figure::QUEEN;
						 }
						 if (rb_rook->Checked) {
							 type = Figure::ROOK;
						 }
						 y = dataGridView1->CurrentCellAddress.Y;
						 x = dataGridView1->CurrentCellAddress.X;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 drawField(field);
					 }
	private: System::Void b_remove_Click(System::Object^  sender, System::EventArgs^  e) {
						 int y = dataGridView1->CurrentCellAddress.Y;
						 int x = dataGridView1->CurrentCellAddress.X;
						 removeFigure(x, y, field);
						 drawField(field);
					 }
	private: System::Void b_standard_Click(System::Object^  sender, System::EventArgs^  e) {
						 int color, type, x, y;
						 for (x = 0; x < 8; x++) {
							 for (y = 0; y < 8; y++) {
								 removeFigure(x, y, field);
							 }
						 }
						 rookingBlackLeft = rookingBlackRight = rookingWhiteLeft = rookingWhiteRight = true;

						 /////////////////////////////////////////////////WHITE
						 color = Figure::WHITE;

						 //PAWNS
						 type = Figure::PAWN;
						 y = 6;
						 for (x = 0; x < 8; x++) {
							 placeFigure(gcnew Figure(x, y, type, color), field);
						 }

						 //ROOKS
						 y = 7;
						 type = Figure::ROOK;
						 x = 0;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 x = 7;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 //KNIGHTS
						 type = Figure::KNIGHT;
						 x = 1;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 x = 6;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 //BISHOPS
						 type = Figure::BISHOP;
						 x = 2;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 x = 5;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 //QUEEN
						 type = Figure::QUEEN;
						 x = 3;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 //KING
						 type = Figure::KING;
						 x = 4;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 ///////////////////////////////////////////////BLACK
						 color = Figure::BLACK;

						 //PAWNS
						 type = Figure::PAWN;
						 y = 1;
						 for (x = 0; x < 8; x++) {
							 placeFigure(gcnew Figure(x, y, type, color), field);
						 }

						 //ROOKS
						 y = 0;
						 type = Figure::ROOK;
						 x = 0;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 x = 7;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 //KNIGHTS
						 type = Figure::KNIGHT;
						 x = 1;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 x = 6;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 //BISHOPS
						 type = Figure::BISHOP;
						 x = 2;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 x = 5;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 //QUEEN
						 type = Figure::QUEEN;
						 x = 3;
						 placeFigure(gcnew Figure(x, y, type, color), field);

						 //KING
						 type = Figure::KING;
						 x = 4;
						 placeFigure(gcnew Figure(x, y, type, color), field);
						 drawField(field);
					 }
	private: System::Void b_checkmate_Click(System::Object^  sender, System::EventArgs^  e) {
						 DateTime beginDate =DateTime::Now;
						 int movesToCheckmate = Convert::ToInt32(nudMoves->Value);
						 List<Coords^> ^ resultMoves = gcnew List<Coords^>(0);
						 resultMoves = findCheckmate(movesToCheckmate, Figure::WHITE, Figure::WHITE, this->field);
						 drawField(this->field);
						 String^ checkmateMoves = L"Ходы для белых, чтобы поставить мат за указанное количество ходов:\n";
						 for (int rm= resultMoves->Count-2; rm >= 0; rm-=2)
						 {
							 Coords^ cm = resultMoves[rm];
							 Coords^ cm2 = resultMoves[rm+1];
							 checkmateMoves+= Convert::ToChar('a'+ cm->x) + L"" + (8 - cm->y) + " => " + Convert::ToChar('a'+ cm2->x) + L"" + (8 - cm2->y) + "\n";
						 }
						 DateTime endDate = DateTime::Now;
						 checkmateMoves += L"Врем просчётов: " + beginDate.TimeOfDay + L" - " + endDate.TimeOfDay + L" ("+(endDate-beginDate) + ")";
						 
						 MessageBox::Show(checkmateMoves);
					 }

					 List<Coords^>^ findCheckmate(int movesToCheckmate, int offenceColor, int currentColor, array<Figure^, 2>^ field) {
						 List<Coords^>^ res = gcnew List<Coords^>(0);
						 //array<Figure^, 2>^ fieldCpy = (array<Figure^, 2>^)field->Clone();
						 int defenceColor = (offenceColor == Figure::BLACK ) ? Figure::WHITE : Figure::BLACK;

						 //Условие выхода: последний ход защиты - либо мат(пустой список ходов), либо nullptr
						 if (movesToCheckmate == 1 && currentColor == defenceColor) {
							 if (isCheckmate(defenceColor, field)) {
								 return gcnew List<Coords^>(0);
							 } else {
								 return nullptr;
							 }
						 }

						 Figure^ currentFigure = nullptr;
						 Figure^ f = nullptr;
						 List<Coords^>^ cFigMoves = gcnew List<Coords^>;
						 Coords^ pos;
						 for(int cx = 0;  cx<8; cx++){
							 for (int cy =0 ; cy<8; cy++)
							 {
								 currentFigure = field[cy, cx];
								 if (nullptr != currentFigure && currentColor == currentFigure->color ) {
									 pos = gcnew Coords(currentFigure->x, currentFigure->y);
									 cFigMoves = currentFigure->getAllMoves(field);
									 for (int m = 0; m<cFigMoves->Count; m++) {
										 f = gcnew Figure(currentFigure);
										 int dstX, dstY;
										 dstX = cFigMoves[m]->x;
										 dstY = cFigMoves[m]->y;
										 if (isLegalMove(f, dstX, dstY, field)) {
											 array<Figure^, 2>^ fieldCpy = (array<Figure^, 2>^)field->Clone();
											 if (!moveFigure(f, dstX, dstY, fieldCpy)) {
												 continue;
											 }
											 drawField(fieldCpy);
//											MessageBox::Show(Convert::ToChar('a'+pos->x) + L"" + pos->y + " " + Convert::ToChar('a' + f->x) + f->y );
											 if (movesToCheckmate < 2) {
												 if (f->color == offenceColor) {
													 //последний ход нападающего, должен быть поставлен шах
													 if (!isCheck(defenceColor, fieldCpy)) {
														 continue;
													 } else {
														 res = findCheckmate(movesToCheckmate, offenceColor, defenceColor, fieldCpy);
														 if (nullptr == res) {
															 continue;
														 } else {
															 res->Add(pos);
															 res->Add(gcnew Coords(f->x, f->y));
															 return res;
														 }
													 }
													 //последний ход нападения
												 }
											
												 /*
												 //TODO разобраться, нужен ли этот код
												 else {
													 //последний ход защищающегося, либо мат (пустой список) либо nullptr
													 if (!isCheckmate(defenceColor, fieldCpy) ) {
														 return nullptr;
													 } else {
														 continue;
													 }
													 //последний ход защиты
												 }
												 if (currentColor != offenceColor) {
													 return gcnew List<Coords^>();
												 } else {
													 return nullptr;
												 }
											 */

												 //ходов до мата < 2
											 }
												 else {
												 //ходов до мата > 2
												 if (currentColor == offenceColor) {
													 //обычный ход нападения
													 res = findCheckmate(movesToCheckmate, offenceColor, defenceColor,fieldCpy);
													 if (nullptr == res) {
														  continue;
													 } else {
														 res->Add(pos);
														 res->Add(gcnew Coords(f->x, f->y));
														 return res;
													 }
													 //обычный ход нападения
												 } else {
													 //обычный ход защиты
													 res = findCheckmate(movesToCheckmate-1, offenceColor, offenceColor,fieldCpy);
													 if (nullptr == res) {
														 return nullptr;
													 } else {
														 res->Add(pos);
														 res->Add(gcnew Coords(f->x, f->y));
													 }
													 //обычный ход защиты
												 }
												 //ходов до мата > 2
											 }
										 } 
									 }
								 } 
							 }
						 }

						 return res;
					 }

	private: System::Void dataGridView1_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
						 if (e->RowIndex >= 0 && e->ColumnIndex >= 0 && e->Button == System::Windows::Forms::MouseButtons::Right) {
							 if (nullptr != this->selectedFigure) {
								 int x = e->ColumnIndex;
								 int y = e->RowIndex;
								 bool isLegal = isLegalMove(this->selectedFigure, x, y, this->field);
								 if (isLegal) {
									 this->moveFigure(this->selectedFigure, x, y, field);
									/*									
									 removeFigure(this->selectedFigure->x, this->selectedFigure->y);
									 this->selectedFigure->x = x;
									 this->selectedFigure->y = y;
									 placeFigure(this->selectedFigure);
									 */
									 dataGridView1->ClearSelection();
								 }
							 }
						 }
					 }


	private: System::Void b_remall_Click(System::Object^  sender, System::EventArgs^  e) {
						 initTable();
						 drawField(field);
					 }
};
}

