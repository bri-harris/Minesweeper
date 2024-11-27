#pragma once
#include <vector>
#include "Tile.h"
using std::vector;

class Board {
    unsigned int _columns, _rows, _mines;
    vector<vector<int>> _layoutPlan;
    vector<vector<Tile>> _board;
    bool _debugStatus = false;
    int _flagsAllowed;
    unsigned int _flagsLaid = 0;


public:
    Board(unsigned int columns,  unsigned int rows, unsigned int mines);
    void ResizeVectors();
    void ResizeTileVector();
    void ResetBoard();
    void SeedVectorDefaults();

    void PlantRandMines(unsigned int mineNumber);
    void PlantMines();
    void LeftMousePress(int x, int y);
    bool RightMousePress(int x, int y);

    vector<vector<int>>& GetLayout();
    vector<vector<Tile>>& GetTileLayout();

    void SetDebugStatus();
    bool IsDebugOn();

    void SetTileLayout(vector<vector<int>>& layoutSet);
    void PrintLayoutPlan();
    unsigned int GetRows();
    unsigned int GetColumns();
    unsigned int GetFlagsLaid();
    int GetFlagsAllowed();


};

