#pragma once
#include <vector>
#include "Tile.h"
using std::vector;

class Board {
    unsigned int _columns, _rows, _mines;
    vector<vector<char>> _layoutPlan;
    vector<vector<Tile>> _board;

    bool _debugStatus = false;
    int _flagsAllowed;

    int _tilesEligible = 0;
    int _flagMineCount = 0;
    int _tilesRevealed = 0;

    bool _hasLost = false;
    bool _hasWon = false;
    // bool _newGame = true;



public:
    unsigned int _digitsX, _digitsY;
    sf::Sprite _tensDigit,  _onesDigit,  _hundredsDigit;

    Board(unsigned int columns,  unsigned int rows, unsigned int mines);

    void ResizeVectors();
    void ResizeTileVector();
    void ResetBoard();
    void SeedVectorDefaults();
    void PlantRandMines(unsigned int mineNumber);
    void PlantMines();

    bool IsMine(int x, int y);
    int CountNearMines(int x, int y);
    void SetNumbers();

    void RevealMines();
    void LeftMousePress(int x, int y);
    bool RightMousePress(int x, int y);
    bool CheckWinStat();

    void SetDebugStatus();
    void SetTileLayout(vector<vector<char>>& layoutSet);
    void SetDigits(float x, float y);
    void SetWin();

    vector<vector<char>>& GetLayout();
    vector<vector<Tile>>& GetTileLayout();
    vector<vector<Tile>>& GetTileBoard();
    unsigned int GetMines();
    unsigned int GetRows();
    unsigned int GetColumns();
    int GetFlagsAllowed();
    bool GetDebugStatus();
    bool HasLost();
    bool HasWon();
    int FlagMineCount();
    int TilesRevealed();
    int TilesEligible();

    void PrintLayoutPlan();
};

