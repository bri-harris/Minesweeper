#pragma once
#include <fstream>
#include "Window.h"
#include "Board.h"
using namespace std;

namespace Worker {
    Board CreateBoardFromFile(string cfgFile);
    Window CreateWindowFromBoard(Board& board);
    unsigned int GetMineNumFromConfig(string cfgFile);

    void SetNieghtbors(vector<vector<Tile>>& tileBoard);

    vector<vector<char>> ReadInTestLayout(string testFile);
    void SetupTestBoard(Board& board, string testPath);

    void BuildBoard(Board& board,sf::RenderWindow& rWindow);

    void DrawMenu(Window& window, sf::RenderWindow& rWindow);
    void DrawWon(Window& window, sf::RenderWindow& rWindow);
    void DrawLost(Window& window, sf::RenderWindow& rWindow);
    void DrawSmile(Window& window, sf::RenderWindow& rWindow);
    void DrawDigits(Board& board, sf::RenderWindow& rWindow);

    void DebugToggle(vector<vector<Tile>>& tileLayout , sf::RenderWindow& rWindow);

    void BuildBoard(Window& gWindow,sf::RenderWindow& rWindow);

    bool CheckWin(Board& board);

}
