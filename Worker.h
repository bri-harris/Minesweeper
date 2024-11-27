#pragma once
#include <fstream>
#include "Window.h"
#include "Board.h"
using namespace std;

namespace Worker {
    Board CreateBoardFromFile(string cfgFile);
    Window CreateWindowFromBoard(Board& board);
    unsigned int GetMineNumFromConfig(string cfgFile);

    vector<vector<int>> ReadInTestLayout(string testFile);
    void SetupTestBoard(Board& board, string testPath);

    void BuildBoard(Board& board,sf::RenderWindow& rWindow);
    void DrawMenu(Window& window, sf::RenderWindow& rWindow);
    void DrawDigits(Window& window, sf::RenderWindow& rWindow);
    void DebugToggle(vector<vector<Tile>>& tileLayout , sf::RenderWindow& rWindow);

}
