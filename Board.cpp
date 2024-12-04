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

    _digitsX = 18;
    _digitsY = _rows * 32;

    _hundredsDigit.setTexture(TextureManager::GetTexture("digits"));
    _tensDigit.setTexture(TextureManager::GetTexture("digits"));
    _onesDigit.setTexture(TextureManager::GetTexture("digits"));

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
    _hasLost = false;
    _hasWon = false;
    _flagMineCount = 0;
    _tilesRevealed = 0;
    if (_debugStatus) SetDebugStatus();
    _mines = 0;
    _flagsAllowed = 0;
    _tilesEligible = _columns * _rows;
    SeedVectorDefaults();
}
void Board::SeedVectorDefaults() {
    for (unsigned int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _layoutPlan[i][j] = ' ';
            _board[i][j] = Tile();
        }
    }
}
void Board::PlantRandMines(unsigned int mineNumber) {
    int m = 0;
    _mines = mineNumber;
    _flagsAllowed = mineNumber;

    while(m < mineNumber) {
        int x = Random::Int(0,_rows -1);
        int y = Random::Int(0, _columns -1);

        if (_layoutPlan[x][y] == ' ') {
            _layoutPlan[x][y] = 'x';
            _board[x][y].SetMine();
            m++;
            _tilesEligible--;
        }
    }
    SetNumbers();

    SetNieghtbors(_board);
}
void Board::PlantMines() {
    for (unsigned int x = 0; x < _rows; x++) {
        for (int y = 0;y < _columns;y++) {
            if (_layoutPlan[x][y] == 'x') {
                _mines +=1;
                _board[x][y].SetMine();
                _tilesEligible--;
            }
        }
    }
    _flagsAllowed = _mines;
    SetNumbers();
    SetNieghtbors(_board);
}

bool Board::IsMine(int x, int y) {
    if (x<0) return false;
    if (y<0) return false;
    if (x >= _rows) return false;
    if (y >= _columns) return false;

    if (_layoutPlan[x][y] == 'x') return true;
    return false;
}
int Board::CountNearMines(int x, int y) {
    int mines = 0;

    //previous row
    if (IsMine(x-1,y-1)) mines++;
    if (IsMine(x-1,y)) mines++;
    if (IsMine(x-1,y+1)) mines++;

    //same row
    if (IsMine(x,y-1)) mines++;
    if (IsMine(x,y+1)) mines++;

    //next row
    if (IsMine(x+1,y-1)) mines++;
    if (IsMine(x+1,y)) mines++;
    if (IsMine(x+1,y+1)) mines++;

    return mines;
}
void Board::SetNumbers() {
    for (int x = 0; x < _rows; x++) {
        for (int y = 0; y < _columns; y++) {
            int nearMines = CountNearMines(x,y);
            if (nearMines>0 && _layoutPlan[x][y] == ' ') {
                _layoutPlan[x][y] = '0' + nearMines;
                _board[x][y].SetNumber(nearMines);
            }
        }
    }
}

void Board::RevealMines() {
    for (unsigned int x = 0; x < _rows; x++) {
        for (int y = 0; y < _columns; y++) {
            if (_board[x][y].HasMine()) {
                _board[x][y].Reveal();
            }
        }
    }
}
void Board::LeftMousePress(int x, int y) {
    for (unsigned int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++){
            if (_board[i][j].Contains(x, y)) {
                if (_hasLost) break;
                if (_hasWon) break;

                if (_board[i][j].HasMine()) {
                    _hasLost = true;
                    _board[i][j].Reveal();
                    SetDebugStatus();
                    for (unsigned int k = 0; k < _mines; k++) {
                        RevealMines();
                    }
                }
                if (!_board[i][j].isRevealed()) {
                    if (!_board[i][j].HasNumber()) {
                        _board[i][j].RevealEligibleNeighbors();
                    }

                    _board[i][j].Reveal();
                    _tilesRevealed = 0;
                    CheckWinStat();
                    cout<< "tiles revealed: "<< _tilesRevealed << endl;
                }
                // else if (!_board[i][j].HasNumber()) {
                //     _board[i][j].RevealEligibleNeighbors();
                // }
                //
                // _board[i][j].Reveal();

                // CheckWinStat();

                break;
            }
    }
    }
}
bool Board::RightMousePress(int x, int y) {
    for (unsigned int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++){
            if (_hasLost || _hasWon)break;
            if (_board[i][j].ContainsFlag(x, y)) {
                if (_board[i][j].isRevealed()) break;
                _board[i][j].Flag();
                _board[i][j].GetFlagSprite();

                if (_board[i][j].isFlagged()&& !_board[i][j].isRevealed()) {
                    _flagsAllowed -=1;
                }
                else if (!_board[i][j].isFlagged()&& !_board[i][j].isRevealed()) {
                    _flagsAllowed+=1;

                }
                if (_layoutPlan[i][j] == 'x') {
                    if (_board[i][j].isFlagged())_flagMineCount++;
                    else if (!_board[i][j].isFlagged()) _flagMineCount--;
                    cout << "FlagMineCount: "<<_flagMineCount << endl;
                    cout << "Mines: "<<_mines << endl;
                }
                return true;
                break;
            }
    }
}
}
bool Board::CheckWinStat() {
    // if (_flagsAllowed == _mines) {
        for (unsigned int i = 0; i < _rows; i++) {
            for (int j = 0; j < _columns; j++) {
                if (_board[i][j].isRevealed()) _tilesRevealed++;
            }
        }
    // }
}


void Board::SetDebugStatus() {
    _debugStatus = !_debugStatus;
}
void Board::SetTileLayout(vector<vector<char>>& layoutSet) {
    _mines = 0;
    _layoutPlan = layoutSet;
}
void Board::SetDigits(float x, float y) {
    int hundredsPlace = _flagsAllowed / 100;
    int tensPlace = _flagsAllowed / 10;
    int onesPlace = _flagsAllowed % 10;
    if (_flagsAllowed < 0 && _flagsAllowed > -10) {
        onesPlace = _flagsAllowed * -1;
    }else if (_flagsAllowed <=-10) {
        tensPlace = -_flagsAllowed / 10;
        onesPlace = -_flagsAllowed % 10;
    }

    if (hundredsPlace> 0) {
        _hundredsDigit.setTextureRect(sf::IntRect(hundredsPlace*21, 0, 21, 32));
        tensPlace = hundredsPlace / 10;
    }else if (_flagsAllowed < 0) {
        _hundredsDigit.setTextureRect(sf::IntRect(10*21, 0, 21, 32));
    }else {
        _hundredsDigit.setTextureRect(sf::IntRect(0*21, 0, 21, 32));
    }

    _hundredsDigit.setPosition(x,y);

    _tensDigit.setTextureRect(sf::IntRect(tensPlace*21, 0, 21, 32));
    _tensDigit.setPosition(x+21,y);

    _onesDigit.setTextureRect(sf::IntRect(onesPlace*21, 0, 21, 32));
    _onesDigit.setPosition(x+42,y);
}
void Board::SetWin() {
    _hasWon = true;
}

vector<vector<char>>& Board::GetLayout() {
    return _layoutPlan;
}
vector<vector<Tile>>& Board::GetTileLayout() {
    return _board;
}
vector<vector<Tile>> & Board::GetTileBoard() {
    return _board;
}
unsigned int Board::GetMines() {
    return _mines;
}
unsigned int Board::GetRows() {
    return _rows;
}
unsigned int Board::GetColumns() {
    return _columns;
}
int Board::GetFlagsAllowed() {
    return _flagsAllowed;
}
bool Board::GetDebugStatus() {
    return _debugStatus;
}

bool Board::HasLost() {
    return _hasLost;
}

bool Board::HasWon() {
    return _hasWon;
}

int Board::FlagMineCount() {
    return _flagMineCount;
}

int Board::TilesRevealed() {
    return _tilesRevealed;
}

int Board::TilesEligible() {
    return _tilesEligible;
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
