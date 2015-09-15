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
	System::Collections::Generic::List<Coords^>^ getAllMoves() {
		switch (this->type)
		{
		case PAWN:
			return this->getAllPawnMoves();
			break;
		case KNIGHT:
			return this->getAllKnightMoves();
			break;
		case BISHOP:
			return this->getAllBishopMoves();
			break;
		case ROOK:
			return this->getAllRookMoves();
			break;
		case QUEEN:
			return this->getAllQueenMoves();
			break;
		case KING:
			return this->getAllKingMoves();
			break;
		default:
			throw gcnew System::Exception("Unknown figure type");
			break;
		}
	}
	System::Collections::Generic::List<Coords^>^ getAllPawnMoves() {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		switch (this->color)
		{
		case WHITE:
			if (this->y > 0) {
				res->Add(gcnew Coords(this->x, this->y - 1));
				if (this->x > 0) {
					res->Add(gcnew Coords(this->x - 1, this->y - 1));
				}
				if (this->x < 7) {
					res->Add(gcnew Coords(this->x + 1, this->y - 1));
				}
				if (this->y == 6) {
					res->Add(gcnew Coords(this->x, this->y - 2));
				}
			}
			break;
		case BLACK:
			if (this->y < 7) {
				res->Add(gcnew Coords(this->x, this->y + 1));
				if (this->x > 0) {
					res->Add(gcnew Coords(this->x - 1, this->y + 1));
				}
				if (this->x < 7) {
					res->Add(gcnew Coords(this->x + 1, this->y + 1));
				}
				if (this->y == 1) {
					res->Add(gcnew Coords(this->x, this->y + 2));
				}
			}
			break;
		default:
			throw gcnew System::Exception("Unknown figure color");
			break;
		}
		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllKnightMoves() {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		if (this->y > 0) {
			if (this->x > 1) {
				res->Add(gcnew Coords(this->x - 2, this->y - 1));
			}
			if (this->x < 6) {
				res->Add(gcnew Coords(this->x + 2, this->y - 1));
			}
			if (this->y > 1) {
				if (this->x > 0) {
					res->Add(gcnew Coords(this->x - 1, this->y - 2));
				}
				if (this->x < 7) {
					res->Add(gcnew Coords(this->x + 1, this->y - 2));
				}
			}
		}

		if (this->y < 7) {
			if (this->x > 1) {
				res->Add(gcnew Coords(this->x - 2, this->y + 1));
			}
			if (this->x < 6) {
				res->Add(gcnew Coords(this->x + 2, this->y + 1));
			}
			if (this->y < 6) {
				if (this->x > 0) {
					res->Add(gcnew Coords(this->x - 1, this->y + 2));
				}
				if (this->x < 7) {
					res->Add(gcnew Coords(this->x + 1, this->y + 2));
				}
			}
		}

		return res;

	}

	System::Collections::Generic::List<Coords^>^ getAllBishopMoves() {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		int cx, cy;
		for (int d = 1; d < 8; d++) {
			cx = this->x + d;
			cy = this->y + d;
			if (cx < 8 && cy < 8) {
				res->Add(gcnew Coords(cx, cy));
			}
			cx = this->x + d;
			cy = this->y - d;
			if (cx < 8 && cy > -1) {
				res->Add(gcnew Coords(cx, cy));
			}
			cx = this->x - d;
			cy = this->y + d;
			if (cx > -1 && cy < 8) {
				res->Add(gcnew Coords(cx, cy));
			}
			cx = this->x - d;
			cy = this->y - d;
			if (cx > -1 && cy > -1) {
				res->Add(gcnew Coords(cx, cy));
			}
		}
		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllRookMoves() {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		int cx, cy;
		for (int d = 1; d < 8; d++) {
			cx = this->x + d;
			cy = this->y;
			if (cx < 8) {
				res->Add(gcnew Coords(cx, cy));
			}
			cx = this->x - d;
			if (cx > -1) {
				res->Add(gcnew Coords(cx, cy));
			}
			cx = this->x;
			cy = this->y + d;
			if (cy < 8) {
				res->Add(gcnew Coords(cx, cy));
			}
			cy = this->y - d;
			if (cy > -1) {
				res->Add(gcnew Coords(cx, cy));
			}
		}
		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllQueenMoves() {
		System::Collections::Generic::List<Coords^>^ res = gcnew System::Collections::Generic::List<Coords^>(0);
		res = this->getAllBishopMoves();
		res->AddRange(this->getAllRookMoves());
		return res;
	}

	System::Collections::Generic::List<Coords^>^ getAllKingMoves() {
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
					res->Add(gcnew Coords(cx, cy));
				}
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

