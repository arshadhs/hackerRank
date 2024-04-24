#include <stdio.h>
#include <stdlib.h>

typedef int File;
typedef int Rank;

class Piece {
public:
    Piece(File f, Rank r) :  file(f), rank(r) { }

    virtual bool is_legal_move(File f, Rank r) = 0;

    bool move(File f, Rank r) {
        if (!is_legal_move(f, r)) return false;
        file = f;
        rank = r;
        return true;
    }

protected:
    static bool is_on_board(File f, Rank r) {
        return f < 8 && r < 8 && f >= 0 && r >= 0;
    }

protected:
    File file;
    Rank rank;
};

// Implement class Rook here
class Rook : public Piece {
public:
    Rook(File f, Rank r) : Piece(f, r) { }
    
    bool is_legal_move(File f, Rank r) {
        bool ret = false;
        
        if (is_on_board(f,r) == false)  return false;
        
        if (this->file == f && this->rank != r) {
            ret = true;
        }
        
        if (this->file != f && this->rank == r) {
            ret = true;
        }   
  
        return ret;        
    }
};

// Implement class Bishop here
class Bishop : public Piece {
public:
    Bishop(File f, Rank r) : Piece(f, r) {  }
    // Implement virtual
    bool is_legal_move(File f, Rank r) {
        bool ret = false;
        
        if (is_on_board(f,r) == false)  return false;
        if (this->file == f && this->rank == r)  return false;

        int x = this->file - f;
        int y = this->rank - r;
        if (x == y)
            ret = true;    

        if (abs(x) == abs(y))
            ret = true;          
            
        return ret;        
    }
};


// Implement class King here
class King : public Piece {
public:
    King(File f, Rank r) : Piece(f, r) {  }
    // Implement virtual
    bool is_legal_move(File f, Rank r) {
        bool ret = false;
        
        if (is_on_board(f,r) == false)  return false;

        int x = this->file - f;
        int y = this->rank - r;
        if ((x == 1 && y == 0) || (x == 0 && y == 1) || (x == 1 && y == 1) || (x == -1 && y == 1) || (x == 1 && y == -1) || (x == -1 && y == -1))
            ret = true;    

        int p = f - this->file;
        int q = r - this->rank;
        if ((p == 1 && q == 0) || (p == 0 && q == 1)  || (x == -1 && y == -1))
            ret = true; 
            
        return ret;        
    }
};


int main()
{
    Rook* rook = nullptr;
    Bishop* bishop = nullptr;
    King* king = nullptr;

    char line[100];
    while (fgets(line, sizeof(line), stdin) != nullptr) {
        char* p = line;
        char ch = *p++;
        File f = strtol(p, &p, 10);
        Rank r = strtol(p, &p, 10);
        bool created = false;
        Piece* piece;
        switch (ch) {
        case 'R':
            if (!rook) {
                rook = new Rook(f, r);
                created = true;
            }
            piece = rook;
            break;
        case 'B':
            if (!bishop) {
                bishop = new Bishop(f, r);
                created = true;
            }
            piece = bishop;
            break;
        case 'K':
            if (!king) {
                king = new King(f, r);
                created = true;
            }
            piece = king;
            break;
        default:
            continue;
        }
        printf("%c %d %d ", ch, f, r);
        if (created)
            printf("created\n");
        else if (piece->move(f, r))
            printf("ok\n");
        else
            printf("illegal move\n");
    }
}

/*
R 0 0
R 0 4
R 7 4
R 7 4
R 6 3
R 7 1
R 8 1
R 0 1


R 7 0
K 5 0
B 2 0
R 7 3
K 4 0
K 4 1
K 3 2
B 4 2
B 7 5
B 6 4
B 6 5
K 2 2
K 1 1
R 0 3
K 1 3
B 5 5
B 4 6
B 2 7

K 1 0
K 2 1
K 2 1
K 3 0
K 3 -1
K 2 1
K 2 3
B 1 5
B 4 8
B 2 4
B -1 1
B 0 6

B 0 0
B 3 4
B 2 2
B 2 2
*/