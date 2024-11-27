#include "Board.h"
#include "Random.h"
#include "Worker.h"
#include <iostream>
using namespace std;
using namespace Worker;

Board::Board(unsigned int columns, unsigned int rows, unsigned int mines) {
    _columns = columns;
    _rows = rows;
    _mines = mines;
    _flagsAllowed = mines;

    ResizeVectors();
    ResetBoard();
    PlantRandMines(mines);
}
void Board::ResizeVectors() {
    _layoutPlan.resize(_rows);
    _board.resize(_rows);
    for (unsigned int i = 0; i < _rows; i++) {
        _layoutPlan[i].resize(_columns);
        _board[i].resize(_columns);
    }
}
void Board::ResizeTileVector() {
    _board.resize(_rows);
    for (unsigned int i = 0; i < _rows; i++) {
        _board[i].resize(_columns);
    }
}
void Board::ResetBoard() {
    if (_debugStatus) SetDebugStatus();
    _mines = 0;
    SeedVectorDefaults();
}
void Board::SeedVectorDefaults() {
    for (unsigned int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _layoutPlan[i][j] = 0;
            _board[i][j] = Tile();
        }
    }
}


void Board::PlantRandMines(unsigned int mineNumber) {
    int m = 0;
    _mines = mineNumber;

    while(m < mineNumber) {
        int x = Random::Int(0,_rows -1);
        int y = Random::Int(0, _columns -1);

        if (_layoutPlan[x][y] == 0) {
            _layoutPlan[x][y] = 1;
            _board[x][y].SetMine();
            m++;
        }
    }
}
void Board::PlantMines() {
    for (unsigned int x = 0; x < _rows; x++) {
        for (int y = 0;y < _columns;y++) {
            if (_layoutPlan[x][y] == 1) {
                _mines +=1;
                _board[x][y].SetMine();
            }
        }
    }
}

void Board::LeftMousePress(int x, int y) {
    for (unsigned int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++)
            if (_board[i][j].Contains(x, y)) {
                _board[i][j].Reveal();
                break;
            }
    }
}
bool Board::RightMousePress(int x, int y) {
    for (unsigned int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++)
            if (_board[i][j].ContainsFlag(x, y)) {
                _board[i][j].Flag();
                _board[i][j].GetFlagSprite();

                if (_board[i][j].isFlagged()) {
                    _flagsLaid+=1;
                    _flagsAllowed -=1;
                }
                else if (!_board[i][j].isFlagged()) {
                    _flagsLaid-=1;
                    _flagsAllowed+=1;
                }
                // cout<<"Flags Laid: " << _flagsLaid << endl;
                // cout<<"Flags Allowed: " << _flagsAllowed << endl;
                return true;
                break;
            }
    }
}


vector<vector<int>>& Board::GetLayout() {
    return _layoutPlan;
}
vector<vector<Tile>>& Board::GetTileLayout() {
    return _board;
}

void Board::SetDebugStatus() {
    _debugStatus = !_debugStatus;
}
bool Board::IsDebugOn() {
    return _debugStatus;
}

void Board::SetTileLayout(vector<vector<int>>& layoutSet) {
    _mines = 0;
    _layoutPlan = layoutSet;
}
void Board::PrintLayoutPlan() {
    for (int i = 0; i < _rows; i++) {
        cout << "[ ";
        for (int j = 0; j < _columns; j++) {
            cout << " "<< _layoutPlan[i][j] <<" ";
        }
        cout << " ]\n";
    }
}
unsigned int Board::GetRows() {
    return _rows;
}
unsigned int Board::GetColumns() {
    return _columns;
}
unsigned int Board::GetFlagsLaid() {
    return _flagsLaid;
}
int Board::GetFlagsAllowed() {
    return _flagsAllowed;
}

