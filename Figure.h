#pragma once
ref class Coords {
public:
	int x;
	int y;
	Coords() {
		x = 0;
		y = 0;
	}
	Coords(int _x, int _y) {
		if (x < 0 || y < 0 || x>7 || y>7) {
			throw gcnew System::Exception(L"Invalid coords: x=" + _x + L"; y=" + _y);
		}
		x = _x;
		y = _y;
	}
};

ref class Figure
{
public:
	int x;
	int y;
	int type;
	int color;
	static const int WHITE = 0;
	static const int BLACK = 1;
	static const int PAWN = 0;
	static const int KNIGHT = 2;
	static const int QUEEN = 4;
	static const int ROOK = 3;
	static const int BISHOP = 1;
	static const int KING = 5;
	Figure(int _x, int _y, int _type, int _color);
	System::Collections::Generic::List<Coords^>^ getAllMoves(array<Figure^,2>^ field) {
		switch (this->type)
		{
		case PAWN:
			return this->getAllPawnMoves(field);
			break;
		case KNIGHT:
			return this->getAllKnightMoves(field);
			break;
		case BISHOP:
			return this->getAllBishopMoves(field);
			break;
		case ROOK:
			return this->getAllRookMoves(field);
			break;
		case QUEEN:
			return this->getAllQueenMoves(field);
			break;
		case KING:
			return this->getAllKingMoves(field);
			break;
		default:
			throw gcnew System::Exception("Unknown figure type");
			break;
		}
	}
	System::Collections::Generic::List<Coords^>^ getAllPawnMoves(array<Figure^, 2>^ field) {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		switch (this->color)
		{
		case WHITE:
			if (this->y > 0) {
				if (nullptr == field[this->y - 1, this->x]) {
					res->Add(gcnew Coords(this->x, this->y - 1));
					if (this->y == 6 && 
						nullptr == field[this->y - 2, this->x]) 
					{
						res->Add(gcnew Coords(this->x, this->y - 2));
					}
				}
				if (this->x > 0 &&
					nullptr != field[this->y - 1, this->x - 1] && 
					field[this->y - 1, this->x - 1]->color == BLACK ) 
				{
					res->Add(gcnew Coords(this->x - 1, this->y - 1));
				}

				if (this->x < 7 &&
					nullptr != field[this->y - 1, this->x + 1] &&
					field[this->y - 1, this->x + 1]->color == BLACK) 
				{
					res->Add(gcnew Coords(this->x + 1, this->y - 1));
				}

			}
			break;
		case BLACK:
			if (this->y < 7) {
				if (nullptr == field[this->y + 1, this->x]) {
					res->Add(gcnew Coords(this->x, this->y + 1));
					if (this->y == 1 && 
						nullptr == field[this->y + 2, this->x]) 
					{
						res->Add(gcnew Coords(this->x, this->y + 2));
					}
				}
				if (this->x > 0 &&
					nullptr != field[this->y + 1, this->x - 1] &&
					field[this->y + 1, this->x - 1]->color == WHITE) 
				{
					res->Add(gcnew Coords(this->x - 1, this->y + 1));
				}
				if (this->x < 7 &&
					nullptr != field[this->y + 1, this->x + 1] &&
					field[this->y + 1, this->x + 1]->color == WHITE)
				{
					res->Add(gcnew Coords(this->x + 1, this->y + 1));
				}
			}
			break;
		default:
			throw gcnew System::Exception("Unknown figure color");
			break;
		}
		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllKnightMoves(array<Figure^, 2>^ field) {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		if (this->y > 0) {
			if (this->x > 1) {
				if (nullptr == field[this->y - 1, this->x - 2] || field[this->y - 1, this->x - 2]->color != this->color) {
					res->Add(gcnew Coords(this->x - 2, this->y - 1));
				}
			}
			if (this->x < 6) {
				if (nullptr == field[this->y - 1, this->x + 2] || field[this->y - 1, this->x + 2]->color != this->color) {
					res->Add(gcnew Coords(this->x + 2, this->y - 1));
				}
			}
			if (this->y > 1) {
				if (this->x > 0) {
					if (nullptr == field[this->y - 2, this->x - 1] || field[this->y - 2, this->x - 1]->color != this->color) {
						res->Add(gcnew Coords(this->x - 1, this->y - 2));
					}
				}
				if (this->x < 7) {
					if (nullptr == field[this->y - 2, this->x + 1] || field[this->y - 2, this->x + 1]->color != this->color) {
						res->Add(gcnew Coords(this->x + 1, this->y - 2));
					}
				}
			}
		}

		if (this->y < 7) {
			if (this->x > 1) {
				if (nullptr == field[this->y + 1, this->x - 2] || field[this->y + 1, this->x - 2]->color != this->color) {
					res->Add(gcnew Coords(this->x - 2, this->y + 1));
				}
			}
			if (this->x < 6) {
				if (nullptr == field[this->y + 1, this->x + 2] || field[this->y + 1, this->x + 2]->color != this->color) {
					res->Add(gcnew Coords(this->x + 2, this->y + 1));
				}
			}
			if (this->y < 6) {
				if (this->x > 0) {
					if (nullptr == field[this->y + 2, this->x - 1] || field[this->y + 2, this->x - 1]->color != this->color) {
						res->Add(gcnew Coords(this->x - 1, this->y + 2));
					}
				}
				if (this->x < 7) {
					if (nullptr == field[this->y + 2, this->x + 1] || field[this->y + 2, this->x + 1]->color != this->color) {
						res->Add(gcnew Coords(this->x + 1, this->y + 2));
					}
				}
			}
		}

		return res;

	}

	System::Collections::Generic::List<Coords^>^ getAllBishopMoves(array<Figure^, 2>^ field) {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		int cx, cy;

		for (int d = 1; d < 8; d++) {
			cx = this->x + d;
			cy = this->y + d;
			if (cx >= 8 || cy >= 8) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}

		for (int d = 1; d < 8; d++) {
			cx = this->x + d;
			cy = this->y - d;
			if (cx >= 8 || cy < 0) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}

		for (int d = 1; d < 8; d++) {
			cx = this->x - d;
			cy = this->y + d;
			if (cx < 0 || cy > 7) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}

		for (int d = 1; d < 8; d++) {
			cx = this->x - d;
			cy = this->y - d;
			if (cx < 0 || cy < 0) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}

		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllRookMoves(array<Figure^, 2>^ field) {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		int cx, cy;

		cy = this->y;
		for (int d = 1; d < 8; d++) {
			cx = this->x + d;
			if (cx > 7) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}

		for (int d = 1; d < 8; d++) {
			cx = this->x - d;
			if (cx <  0) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}

		cx = this->x;
		for (int d = 1; d < 8; d++) {
			cy = this->y + d;
			if (cy > 7) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}

		for (int d = 1; d < 8; d++) {
			cy = this->y - d;
			if (cy < 0) {
				break;
			}
			if (nullptr != field[cy, cx]) {
				if (field[cy, cx]->color != this->color) {
					res->Add(gcnew Coords(cx, cy));
				}
				break;
			}
			res->Add(gcnew Coords(cx, cy));
		}
		
		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllQueenMoves(array<Figure^, 2>^ field) {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		res = this->getAllBishopMoves(field);
		res->AddRange(this->getAllRookMoves(field));
		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllKingMoves(array<Figure^, 2>^ field) {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		int cx, cy;
		for (int dx = -1; dx < 2; dx++) {
			for (int dy = -1; dy < 2; dy++) {
				if (dx == 0 && dy == 0) {
					continue;
				}
				cx = this->x + dx;
				cy = this->y + dy;
				if (cx > -1 && cx <8 && cy > -1 && cy < 8) {
					if (nullptr != field[cy, cx]) {
						if (field[cy, cx]->color != this->color) {
							res->Add(gcnew Coords(cx, cy));
						}
					}
					else {
						res->Add(gcnew Coords(cx, cy));
					}
				}
			}
		}
		if (this->y % 7 == 0 && this->x == 4) {
			if (nullptr == field[this->y, 3] && nullptr == field[this->y, 2] && nullptr == field[this->y, 1]) {
				res->Add(gcnew Coords(2, this->y));
			}
			if (nullptr == field[this->y, 5] && nullptr == field[this->y, 6]) {
				res->Add(gcnew Coords(6, this->y));
			}
		}
		return res;
	}

	System::String^ getTypeString() {
		switch (this->type)
		{
		case PAWN:
			return L"pawn";
		case KNIGHT:
			return L"knight";
		case BISHOP:
			return L"bishop";
		case ROOK:
			return L"rook";
		case QUEEN:
			return L"queen";
		case KING:
			return L"king";
		default:
			return L"unknown";
		}
	}
	
};
